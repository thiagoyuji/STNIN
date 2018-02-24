#ifndef SNAKE_CURSOR_H_INCLUDED
#define SNAKE_CURSOR_H_INCLUDED

// INCLUDES, DEFINES :: Start

#include "Defines.h"

#ifdef _WIN32

    #include <conio.h>

#else

    #include <termios.h>
    #include <unistd.h>
    #include <fcntl.h>

#endif

#define UP_UPPERCASE 87
#define UP_DOWNCASE 119

#define DOWN_UPPERCASE 83
#define DOWN_DOWNCASE 115

#define RIGHT_UPPERCASE 68
#define RIGHT_DOWNCASE 100

#define LEFT_UPPERCASE 65
#define LEFT_DOWNCASE 97

// INCLUDES, DEFINES :: End

// TYPEDEFS, STRUCTS, ENUMS :: Start

struct Cursor{

    Integer up_down_Value;

    Integer right_left_Value;

};

// TYPEDEFS, STRUCTS, ENUMS :: End

// INTERFACES :: Start

void newCursor( struct Cursor *, Integer );

void pressUP( struct Cursor * );

void pressDOWN( struct Cursor *, Integer );

void pressRIGHT( struct Cursor *, Integer );

void pressLEFT( struct Cursor * );

char getStdinKey(  );

int kbhitLinux( void );

// INTERFACES :: End

#endif