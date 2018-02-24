#ifndef SNAKE_SCORE_H_INCLUDED
#define SNAKE_SCORE_H_INCLUDED

// INCLUDES, DEFINES :: Start

#include "Defines.h"

#define MAX_SCORE ( (HEIGHT_MAP - 2) * (WIDTH_MAP - 2) )

// INCLUDES, DEFINES :: End

// TYPEDEFS, STRUCTS, ENUMS :: Start

struct Score{

    Integer SnakeScore;

};

// TYPEDEFS, STRUCTS, ENUMS :: End

// INTERFACES :: Start

void createScore( struct Score * );

void refreshScore( struct Score * );

Integer checkHighestScore( struct Score );

enum Boolean checkSnakeHighestScoreFile( );

Integer saveLastScore( struct Score );

void updateScore( struct Score * );

// INTERFACES :: End

#endif