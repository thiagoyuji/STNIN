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

#ifndef CONFIG_RENEWAL_H
#define CONFIG_RENEWAL_H

/**
 * Renova��o: Defini��o Mestre.
 * Remova o coment�rio para ativar o modo pr�-renova��o (Tamb�m conhecido como gold times)
 * PS: Ativando essa defini��o, automaticamente, todas as defini��es abaixo ser�o removidas.
 */
//#define DISABLE_RENEWAL


#ifndef DISABLE_RENEWAL // N�o altere esta linha.

/// Modo renova��o
/// Deixe esta linha ativada para uso de mudan�as espec�ficas da renova��o (e.g F�rmulas das Habilidades, status e etc)
#define RENEWAL

/// Modo renova��o - Conjura��o
/// Tempo de conjura��o: Reduzido por (DEX * 2 + INT) enquanto 20% do cast n�o � removido pelos status (Apenas por itens)
#define RENEWAL_CAST

/// Modo renova��o - Taxa de Drops
/// Quando ativado, as taxas de drop sofrem uma modifica��o de acordo com a diferen�a entre o n�vel do personagem ~ n�vel do monstro
/// Informa��es em http://browiki.org/wiki/Drop
#define RENEWAL_DROP

/// Modo renova��o - Taxa de experi�ncia
/// Quando ativado, as taxas de experi�ncia sofrem uma modifica��o de acordo com a diferen�a entre o n�vel do personagem ~ n�vel do monstro
///Informa��es em http://browiki.org/wiki/Experi%C3%AAncia
#define RENEWAL_EXP

/// Modo renova��o - Modificadores de dano
/// Quando ativado, o n�vel base afeta o dano de algumas habilidades
#define RENEWAL_LVDMG

/// Modo renova��o - EDP
/// Quando ativado:
///  - O dano n�o � aumentado em 400%
///  - N�o afeta a adaga sinistra
///  - O ataque da arma e o status relacionado aumentam
#define RENEWAL_EDP

/// Modo renova��o - ASPD
/// Quando ativado:
/// - Penalidade na ASPD � aplicada quando usa-se escudo
/// - Agilidade tem uma influ�ncia maior no aumento da ASPD
/// - Mudan�as em como habilidades/itens modificam esta op��o
#define RENEWAL_ASPD

#endif // DISABLE_RENEWAL
#undef DISABLE_RENEWAL

#endif // CONFIG_RENEWAL_H
