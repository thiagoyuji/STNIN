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

#ifndef CHAR_INT_QUEST_H
#define CHAR_INT_QUEST_H

#include "common/cronus.h"

/**
 * inter_quest interface
 **/
struct inter_quest_interface {
	int (*parse_frommap) (int fd);
};

#ifdef CRONUS_CORE
void inter_quest_defaults(void);
#endif // CRONUS_CORE

HPShared struct inter_quest_interface *inter_quest;

#endif /* CHAR_INT_QUEST_H */
