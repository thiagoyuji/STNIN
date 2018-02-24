#include "libc.h"
#include <errno.h>
#include <grp.h>
#include <limits.h>
#include <pwd.h>
#include <shadow.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

int __getpwent_a(FILE* f, struct passwd* pw, char** line, size_t* size, struct passwd** res);
int __getpw_a(const char* name, uid_t uid, struct passwd* pw, char** buf, size_t* size,
              struct passwd** res);
int __getgrent_a(FILE* f, struct group* gr, char** line, size_t* size, char*** mem, size_t* nmem,
                 struct group** res);
int __getgr_a(const char* name, gid_t gid, struct group* gr, char** buf, size_t* size, char*** mem,
              size_t* nmem, struct group** res);
int __parsespent(char* s, struct spwd* sp);
