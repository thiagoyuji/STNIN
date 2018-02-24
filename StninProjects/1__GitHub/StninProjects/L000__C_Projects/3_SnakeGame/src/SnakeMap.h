#ifndef SNAKE_MAP_H_INCLUDED
#define SNAKE_MAP_H_INCLUDED

// INCLUDES, DEFINES :: Start

#include "Defines.h"

#define HEIGHT_MAP 20
#define WIDTH_MAP 70

#ifdef _WIN32

    #define TOP_BOT_WALLS 205
    #define RIGHT_LEFT_WALLS 186

    #define TOP_LEFT_CORNER 201
    #define TOP_RIGHT_CORNER 187

    #define BOT_LEFT_CORNER 200
    #define BOT_RIGHT_CORNER 188

#else

    #define WALLS 35

#endif

#define FOOD 64
#define FREE_SPACE ' '

// INCLUDES, DEFINES :: End

// TYPEDEFS, STRUCTS, ENUMS :: Start

struct Map{

    char Map_m[ HEIGHT_MAP ][WIDTH_MAP ];

};

// TYPEDEFS, STRUCTS, ENUMS :: End

// INTERFACES :: Start

void createMap( struct Map * );

void generateFood( struct Map * );

void showMap( struct Map * );

// INTERFACES :: End

#endif