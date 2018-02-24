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

#ifndef MAP_MAIL_H
#define MAP_MAIL_H

#include "common/cronus.h"

struct item;
struct mail_message;
struct map_session_data;

struct mail_interface {
	void (*clear) (struct map_session_data *sd);
	int (*removeitem) (struct map_session_data *sd, short flag);
	int (*removezeny) (struct map_session_data *sd, short flag);
	unsigned char (*setitem) (struct map_session_data *sd, int idx, int amount);
	bool (*setattachment) (struct map_session_data *sd, struct mail_message *msg);
	void (*getattachment) (struct map_session_data* sd, int zeny, struct item* item);
	int (*openmail) (struct map_session_data *sd);
	void (*deliveryfail) (struct map_session_data *sd, struct mail_message *msg);
	bool (*invalid_operation) (struct map_session_data *sd);
};

#ifdef CRONUS_CORE
void mail_defaults(void);
#endif // CRONUS_CORE

HPShared struct mail_interface *mail;

#endif /* MAP_MAIL_H */
