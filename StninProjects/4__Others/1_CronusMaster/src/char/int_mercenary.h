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

#ifndef CHAR_INT_MERCENARY_H
#define CHAR_INT_MERCENARY_H

#include "common/cronus.h"

struct mmo_charstatus;

/**
 * inter_mercenary interface
 **/
struct inter_mercenary_interface {
	bool (*owner_fromsql) (int char_id, struct mmo_charstatus *status);
	bool (*owner_tosql) (int char_id, struct mmo_charstatus *status);
	bool (*owner_delete) (int char_id);
	int (*sql_init) (void);
	void (*sql_final) (void);
	int (*parse_frommap) (int fd);
};

#ifdef CRONUS_CORE
void inter_mercenary_defaults(void);
#endif // CRONUS_CORE

HPShared struct inter_mercenary_interface *inter_mercenary;

#endif /* CHAR_INT_MERCENARY_H */
