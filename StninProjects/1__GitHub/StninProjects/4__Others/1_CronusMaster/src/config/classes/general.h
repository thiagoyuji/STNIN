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

#ifndef CONFIG_GENERAL_H
#define CONFIG_GENERAL_H

/**
 * Comportamento para reflex�o de habilidade m�gicas
 * - Quando refletido, o dano da reflex�o depende dos equipamentos do conjurador, ao inv�s do alvo. (Oficial)
 * - Quando esta configura��o � desativada, o dano da reflex�o depende dos equipamentos do alvo, ao inv�s do conjurador. (eAthena)
 * @values 1 (ativado) ou 0 (desativado)
 **/
#define MAGIC_REFLECTION_TYPE 1

/**
 * Limite de esferas espirituais
 **/
#define MAX_SPIRITBALL 15

/**
* Limite de amuletos espirituais
**/
#define MAX_SPIRITCHARM 10

/**
 * Quando ativado, o dano refletido n�o � suprimido pela reden��o (O templ�rio tamb�m sofre o dano)
 * Remova // para ativar
 **/
//#define DEVOTION_REFLECT_DAMAGE


#endif // CONFIG_GENERAL_H
