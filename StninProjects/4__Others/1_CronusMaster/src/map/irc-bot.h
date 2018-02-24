/*==================================================================\\
//                   _____                                          ||
//                  /  __ \                                         ||
//                  | /  \/_ __ ___  _ __  _   _ ___                ||
//                  | |   | '__/ _ \| '_ \| | | / __|               ||
//                  | \__/\ | | (_) | | | | |_| \__ \               ||
//                   \____/_|  \___/|_| |_|\__,_|___/               ||
//                        Source - 2016                             ||
//==================================================================||
// = C�digo Base:                                                   ||
// - eAthena/Hercules/Cronus                                        ||
//==================================================================||
// = Sobre:                                                         ||
// Este software � livre: voc� pode redistribu�-lo e/ou modific�-lo ||
// sob os termos da GNU General Public License conforme publicada   ||
// pela Free Software Foundation, tanto a vers�o 3 da licen�a, ou   ||
// (a seu crit�rio) qualquer vers�o posterior.                      ||
//                                                                  ||
// Este programa � distribu�do na esperan�a de que possa ser �til,  ||
//�mas SEM QUALQUER GARANTIA; mesmo sem a garantia impl�cita de     ||
//�COMERCIALIZA��O ou ADEQUA��O A UM DETERMINADO FIM. Veja a        ||
//�GNU General Public License para mais detalhes.                   ||
//                                                                  ||
// Voc� deve ter recebido uma c�pia da Licen�a P�blica Geral GNU    ||
// juntamente com este programa. Se n�o, veja:                      ||
// <http://www.gnu.org/licenses/>.                                  ||
//==================================================================*/
// Base Author: shennetsind @ http://herc.ws


#ifndef MAP_IRC_BOT_H
#define MAP_IRC_BOT_H

#include "common/cronus.h"

#define IRC_NICK_LENGTH 40
#define IRC_IDENT_LENGTH 40
#define IRC_HOST_LENGTH 63
#define IRC_FUNC_LENGTH 30
#define IRC_MESSAGE_LENGTH 500

struct channel_data;

struct irc_func {
	char name[IRC_FUNC_LENGTH];
	void (*func)(int, char*, char*, char*, char*);
};

struct irc_bot_interface {
	int fd;
	bool isIn, isOn;
	int64 last_try;
	unsigned char fails;
	uint32 ip;
	unsigned short port;
	/* */
	struct channel_data *channel;
	/* */
	struct {
		struct irc_func **list;
		unsigned int size;
	} funcs;
	/* */
	void (*init) (bool minimal);
	void (*final) (void);
	/* */
	int (*parse) (int fd);
	void (*parse_sub) (int fd, char *str);
	void (*parse_source) (char *source, char *nick, char *ident, char *host);
	/* */
	struct irc_func* (*func_search) (char* function_name);
	/* */
	int (*connect_timer) (int tid, int64 tick, int id, intptr_t data);
	int (*identify_timer) (int tid, int64 tick, int id, intptr_t data);
	int (*join_timer) (int tid, int64 tick, int id, intptr_t data);
	/* */
	void (*send)(char *str);
	void (*relay) (const char *name, const char *msg);
	/* */
	void (*pong) (int fd, char *cmd, char *source, char *target, char *msg);
	void (*privmsg) (int fd, char *cmd, char *source, char *target, char *msg);
	void (*userjoin) (int fd, char *cmd, char *source, char *target, char *msg);
	void (*userleave) (int fd, char *cmd, char *source, char *target, char *msg);
	void (*usernick) (int fd, char *cmd, char *source, char *target, char *msg);
};

#ifdef CRONUS_CORE
void ircbot_defaults(void);
#endif // CRONUS_CORE

HPShared struct irc_bot_interface *ircbot;

#endif /* MAP_IRC_BOT_H */
