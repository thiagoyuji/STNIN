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

#ifndef CONFIG_CORE_H
#define CONFIG_CORE_H

/// M�ximo de itens permitidos na lista do comando @autolootid
#define AUTOLOOTITEM_SIZE 10

/// M�ximo de sugest�es para comandos (Caso digite algum errado, o servidor envia uma lista com os mais parecidos)
#define MAX_SUGGESTIONS 10

/// Comente para desativar as configura��es oficiais das poss�veis c�lulas and�veis.
/// O oficial bloqueia a possibilidade de transpor obst�culos vis�veis (Realiza sempre um caminho linear)
/// EX: Desativando essa defini��o, clicar de um outro lado do muro far� o personagem realizar a trajet�ria automaticamente.
#define OFFICIAL_WALKPATH

/// Deixe esta linha ativa para ativar a funcionalidade para chamada automatizada de fun��es no processamento de scripts
/// Enquanto ativada, a engine ir� tentar procurar as fun��es definidas pelo usu�rio sem o uso da keyword callfunc
/// Isso IR� atingir a performance, ent�o se voc� achar que os scripts est�o mais lentos ou achar que o servidor de mapas
/// est� usando mais recursos que normalmente, comente esta linha.
#define SCRIPT_CALLFUNC_CHECK

/// Comente para remover a funcionalidade de entrada de dados no console
/// Ativo, voc� pode digitar comandos no console para manobrar certos elementos
#define CONSOLE_INPUT

/// M�ximo de caracteres suportados para entrada no console.
#define MAX_CONSOLE_INPUT 150

//#define STATS_OPT_OUT

/// Remova o coment�rio para ativar o limite para empilhamento de c�lulas.
/// (Remove a possibilidade de dois objetos do tipo BL_CHAR (Monstros e personagens) de ocuparem a mesma c�lula)
//#define CELL_NOSTACK

/// Remova o coment�rio para habilitar checagem circular de �rea
/// Por padr�o, todas as checagens no aegis s�o quadr�ticas, ent�o uma arma 10x10 atinge uma �rea 21x21 (C�lculo geom�trico)
/// Ativar esta defini��o far� o jogo ser mais real�stico, por�m n�o � o comportamento oficial
//#define CIRCULAR_AREA

/// Dist�ncia aplicada para funcionalidade do autoloot.
/// Comentado: Infinito.
/// Sem coment�rio: �rea de vis�o.
//#define AUTOLOOT_DISTANCE AREA_SIZE

/// Remova o coment�rio para alterar a funcionalidade do limite de dano aplicado por mapas.
/// Quando comentado, o limite � processado ANTES dos modificadores de dano (Buff/Nerf)
/// Quando sem o coment�rio, o limite � processado DEPOIS dos modificadores de dano (Buff/Nerf)
//#define HMAP_ZONE_DAMAGE_CAP_TYPE

/// Comente para remover o sistema de itens vinculados em grupo/cl�.
#define GP_BOUND_ITEMS

/// Remova o coment�rio para visualizar o consumo de recursos do emulador (Mem�ria, processamento e etc)
//#define SHOW_SERVER_STATS

/// Comente essa configura��o caso queira remover o salvamento de informa��es sobre os @AT (O Servidor armazena as lojinhas caso ele sofra uma queda)
#define AUTOTRADE_PERSISTENCY

#include "./renewal.h"
#include "./secure.h"
#include "./classes/general.h"
#include "./const.h"

#endif // CONFIG_CORE_H
