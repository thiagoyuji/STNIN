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

#ifndef MAP_STORAGE_H
#define MAP_STORAGE_H

#include "common/cronus.h"
#include "common/db.h"

struct guild_storage;
struct item;
struct map_session_data;

/**
 * Acceptable values for map_session_data.state.storage_flag
 */
enum storage_flag {
	STORAGE_FLAG_CLOSED = 0, // Closed
	STORAGE_FLAG_NORMAL = 1, // Normal Storage open
	STORAGE_FLAG_GUILD  = 2, // Guild Storage open
};

struct storage_interface {
	/* */
	void (*reconnect) (void);
	/* */
	int (*delitem) (struct map_session_data* sd, int n, int amount);
	int (*open) (struct map_session_data *sd);
	int (*add) (struct map_session_data *sd,int index,int amount);
	int (*get) (struct map_session_data *sd,int index,int amount);
	int (*additem) (struct map_session_data* sd, struct item* item_data, int amount);
	int (*addfromcart) (struct map_session_data *sd,int index,int amount);
	int (*gettocart) (struct map_session_data *sd,int index,int amount);
	void (*close) (struct map_session_data *sd);
	void (*pc_quit) (struct map_session_data *sd, int flag);
	int (*comp_item) (const void *i1_, const void *i2_);
	void (*sortitem) (struct item* items, unsigned int size);
	int (*reconnect_sub) (DBKey key, DBData *data, va_list ap);
};

struct guild_storage_interface {
	struct DBMap* db; // int guild_id -> struct guild_storage*
	/* */
	struct guild_storage *(*ensure) (int guild_id);
	/* */
	void (*init) (bool minimal);
	void (*final) (void);
	/* */
	int (*delete) (int guild_id);
	int (*open) (struct map_session_data *sd);
	int (*additem) (struct map_session_data *sd,struct guild_storage *stor,struct item *item_data,int amount);
	int (*delitem) (struct map_session_data *sd,struct guild_storage *stor,int n,int amount);
	int (*add) (struct map_session_data *sd,int index,int amount);
	int (*get) (struct map_session_data *sd,int index,int amount);
	int (*addfromcart) (struct map_session_data *sd,int index,int amount);
	int (*gettocart) (struct map_session_data *sd,int index,int amount);
	int (*close) (struct map_session_data *sd);
	int (*pc_quit) (struct map_session_data *sd,int flag);
	int (*save) (int account_id, int guild_id, int flag);
	int (*saved) (int guild_id); //Ack from char server that guild store was saved.
	DBData (*create) (DBKey key, va_list args);
};

#ifdef CRONUS_CORE
void storage_defaults(void);
void gstorage_defaults(void);
#endif // CRONUS_CORE

HPShared struct storage_interface *storage;
HPShared struct guild_storage_interface *gstorage;

#endif /* MAP_STORAGE_H */
