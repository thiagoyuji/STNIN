#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

// INCLUDES, DEFINES :: Start

#include "Defines.h"

#include "SnakeCursor.h"

#include "SnakeMap.h"

#include "SnakeScore.h"

#include "SnakeMenu.h"

#define NAME_SIZE 25

#define SNAKE 43

#define TEMP 't'

#define LIMIT_COLLUN_SNAKE ( HEIGHT_MAP - 1 )
#define LIMIT_LINE_SNAKE ( WIDTH_MAP - 1 )

// INCLUDES, DEFINES :: End

// TYPEDEFS, STRUCTS, ENUMS :: Start

struct Snake{

    Integer head_Line;
    Integer head_Collun;

    enum Boolean death;

    Integer snakeSize;

};

// TYPEDEFS, STRUCTS, ENUMS :: End

// INTERFACES :: Start

void createSnake( struct Snake * );

void defineSnakePosition( struct Map * );

void moveSnake( struct Snake *, struct Map *, struct Score * );

enum Boolean checkFoodAroundRight( struct Snake *, struct Score *, struct Map * , struct Cursor );
enum Boolean checkFoodAroundLeft( struct Snake *, struct Score *, struct Map * , struct Cursor );

enum Boolean checkFoodAroundUp( struct Snake *, struct Score *, struct Map * , struct Cursor );
enum Boolean checkFoodAroundDown( struct Snake *, struct Score *, struct Map * , struct Cursor );

enum Boolean checkWallAroundRight( struct Snake *, struct Map * , struct Cursor );
enum Boolean checkWallAroundLeft( struct Snake *, struct Map * , struct Cursor );

enum Boolean checkWallAroundUp( struct Snake *, struct Map * , struct Cursor );
enum Boolean checkWallAroundDown( struct Snake *, struct Map * , struct Cursor );

enum Boolean checkDirection( char, char );

void growUpdateSnake( struct Snake *, struct Map *,struct Cursor *,  char, enum Boolean );

// INTERFACES :: End

#endif