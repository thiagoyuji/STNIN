#include "pthread_impl.h"
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <wordexp.h>

static void reap(pid_t pid) {
    int status;
    for (;;) {
        if (waitpid(pid, &status, 0) < 0) {
            if (errno != EINTR)
                return;
        } else {
            if (WIFEXITED(status))
                return;
        }
    }
}

static char* getword(FILE* f) {
    char* s = 0;
    return getdelim(&s, (size_t[1]){0}, 0, f) < 0 ? 0 : s;
}

int wordexp(const char* s, wordexp_t* we, int flags) {
    size_t i, l;
    int sq = 0, dq = 0;
    size_t np = 0;
    char *w, **tmp;
    const char* redir = (flags & WRDE_SHOWERR) ? "" : "2>/dev/null";
    int err = 0;
    FILE* f;
    size_t wc = 0;
    char** wv = 0;
    int p[2];
    pid_t pid;

    if (flags & WRDE_REUSE)
        wordfree(we);

    if (flags & WRDE_NOCMD)
        for (i = 0; s[i]; i++)
            switch (s[i]) {
            case '\\':
                if (!sq)
                    i++;
                break;
            case '\'':
                if (!dq)
                    sq ^= 1;
                break;
            case '"':
                if (!sq)
                    dq ^= 1;
                break;
            case '(':
                if (np) {
                    np++;
                    break;
                }
            case ')':
                if (np) {
                    np--;
                    break;
                }
            case '\n':
            case '|':
            case '&':
            case ';':
            case '<':
            case '>':
            case '{':
            case '}':
                if (!(sq | dq | np))
                    return WRDE_BADCHAR;
                break;
            case '$':
                if (sq)
                    break;
                if (s[i + 1] == '(' && s[i + 2] == '(') {
                    i += 2;
                    np += 2;
                    break;
                } else if (s[i + 1] != '(')
                    break;
            case '`':
                if (sq)
                    break;
                return WRDE_CMDSUB;
            }

    if (flags & WRDE_APPEND) {
        wc = we->we_wordc;
        wv = we->we_wordv;
    }

    i = wc;
    if (flags & WRDE_DOOFFS) {
        if (we->we_offs > SIZE_MAX / sizeof(void*) / 4)
            goto nospace;
        i += we->we_offs;
    } else {
        we->we_offs = 0;
    }

    if (pipe2(p, O_CLOEXEC) < 0)
        goto nospace;
    pid = fork();
    if (pid < 0) {
        close(p[0]);
        close(p[1]);
        goto nospace;
    }
    if (!pid) {
        if (p[1] == 1)
            fcntl(1, F_SETFD, 0);
        else
            dup2(p[1], 1);
        execl("/bin/sh", "sh", "-c", "eval \"printf %s\\\\\\\\0 x $1 $2\"", "sh", s, redir,
              (char*)0);
        _exit(1);
    }
    close(p[1]);

    f = fdopen(p[0], "r");
    if (!f) {
        close(p[0]);
        kill(pid, SIGKILL);
        reap(pid);
        goto nospace;
    }

    l = wv ? i + 1 : 0;

    free(getword(f));
    if (feof(f)) {
        fclose(f);
        reap(pid);
        return WRDE_SYNTAX;
    }

    while ((w = getword(f))) {
        if (i + 1 >= l) {
            l += l / 2 + 10;
            tmp = realloc(wv, l * sizeof(char*));
            if (!tmp)
                break;
            wv = tmp;
        }
        wv[i++] = w;
        wv[i] = 0;
    }
    if (!feof(f))
        err = WRDE_NOSPACE;

    fclose(f);
    reap(pid);

    if (!wv)
        wv = calloc(i + 1, sizeof *wv);

    we->we_wordv = wv;
    we->we_wordc = i;

    if (flags & WRDE_DOOFFS) {
        if (wv)
            for (i = we->we_offs; i; i--)
                we->we_wordv[i - 1] = 0;
        we->we_wordc -= we->we_offs;
    }
    return err;

nospace:
    if (!(flags & WRDE_APPEND)) {
        we->we_wordc = 0;
        we->we_wordv = 0;
    }
    return WRDE_NOSPACE;
}

void wordfree(wordexp_t* we) {
    size_t i;
    if (!we->we_wordv)
        return;
    for (i = 0; i < we->we_wordc; i++)
        free(we->we_wordv[we->we_offs + i]);
    free(we->we_wordv);
    we->we_wordv = 0;
    we->we_wordc = 0;
}
