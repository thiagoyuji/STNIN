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

#ifndef MAP_MAPREG_H
#define MAP_MAPREG_H

#include "map/script.h" // struct reg_db
#include "common/cronus.h"
#include "common/db.h"

struct eri;

/** Container for a mapreg value */
struct mapreg_save {
	int64 uid;         ///< Unique ID
	union {
		int i;     ///< Numeric value
		char *str; ///< String value
	} u;
	bool is_string;    ///< true if it's a string, false if it's a number
	bool save;         ///< Whether a save operation is pending
};

struct mapreg_interface {
	struct reg_db regs;
	/* */
	bool skip_insert;
	/* */
	struct eri *ers; //[Ind/Hercules]
	/* */
	char table[32];
	/* */
	bool dirty; ///< Whether there are modified regs to be saved
	/* */
	void (*init) (void);
	void (*final) (void);
	/* */
	int (*readreg) (int64 uid);
	char* (*readregstr) (int64 uid);
	bool (*setreg) (int64 uid, int val);
	bool (*setregstr) (int64 uid, const char *str);
	void (*load) (void);
	void (*save) (void);
	int (*save_timer) (int tid, int64 tick, int id, intptr_t data);
	int (*destroyreg) (DBKey key, DBData *data, va_list ap);
	void (*reload) (void);
	bool (*config_read) (const char *w1, const char *w2);
};

#ifdef CRONUS_CORE
void mapreg_defaults(void);
#endif // CRONUS_CORE

HPShared struct mapreg_interface *mapreg;

#endif /* MAP_MAPREG_H */
