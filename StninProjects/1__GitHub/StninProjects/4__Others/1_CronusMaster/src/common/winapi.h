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

#pragma once


#define STRICT
#define NTDDI_VERSION NTDDI_WIN2K
#define _WIN32_WINNT  0x0500
#define WINVER        0x0500
#define _WIN32_IE     0x0600
#define WIN32_LEAN_AND_MEAN
#define NOCOMM
#define NOKANJI
#define NOHELP
#define NOMCX
#define NOCLIPBOARD
#define NOCOLOR
#define NONLS
#define NOMEMMGR
#define NOMETAFILE
#define NOOPENFILE
#define NOSERVICE
#define NOSOUND
#define NOTEXTMETRIC


#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <io.h>
#include <Windows.h>
#include <WinSock2.h>
#include <In6addr.h>
#include <Ws2tcpip.h>
#include <Mswsock.h>
#include <MMSystem.h>
