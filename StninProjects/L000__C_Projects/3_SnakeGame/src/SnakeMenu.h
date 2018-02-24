#ifndef SNAKE_MENU_H_INCLUDED
#define SNAKE_MENU_H_INCLUDED

// INCLUDES, DEFINES :: Start

#include "Defines.h"

#include "SnakeCursor.h"

#define LAST_POSITION_CURSOR 4

#define ENTER 13

// INCLUDES, DEFINES :: End

// TYPEDEFS, STRUCTS, ENUMS :: Start
// TYPEDEFS, STRUCTS, ENUMS :: End

// INTERFACES :: Start

Integer showMenu(  );

void cleanVideo(  );

void showInit(  );
void showLastScore(  );
void showReset(  );
void showExit(  );

void showOptionStart();
void showOptionScore();
void showOptionReset();
void showOptionExit();


// INTERFACES :: End

#endif