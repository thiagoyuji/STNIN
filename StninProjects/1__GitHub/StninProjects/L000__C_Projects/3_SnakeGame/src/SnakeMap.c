// INCLUDES :: Start

#include "SnakeMap.h"

// INCLUDES :: End

// IMPLEMENTATION :: Start

#ifdef _WIN32

    void createMap( struct Map * map_ ){

        Integer line, collun;

        for( line = ZERO; line < HEIGHT_MAP; line++ ){

            for( collun = ZERO; collun < WIDTH_MAP; collun++ ){

                if( line == ZERO && collun == ZERO )    map_->Map_m[ line ][ collun ] = TOP_LEFT_CORNER;
                else if( line == ZERO && collun == (WIDTH_MAP - 1) )  map_->Map_m[ line ][ collun ] = TOP_RIGHT_CORNER;
                else if( line == (HEIGHT_MAP - 1) && collun == ZERO ) map_->Map_m[ line ][ collun ] = BOT_LEFT_CORNER;
                else if( line == (HEIGHT_MAP - 1) && collun == (WIDTH_MAP - 1) )    map_->Map_m[ line ][ collun ] = BOT_RIGHT_CORNER;
                else if( collun == ZERO || collun == (WIDTH_MAP - 1) )    map_->Map_m[ line ][ collun ] = RIGHT_LEFT_WALLS;
                else if( line == ZERO || line == (HEIGHT_MAP - 1) ) map_->Map_m[ line ][ collun ] = TOP_BOT_WALLS;
                else    map_->Map_m[ line ][ collun ] = FREE_SPACE;

            }

        }

    }

#else

    void createMap( struct Map * map_ ){

        Integer line, collun;

        for( line = ZERO; line < HEIGHT_MAP; line++ ){

            for( collun = ZERO; collun < WIDTH_MAP; collun++ ){

                if( collun == ZERO || collun == (WIDTH_MAP - 1) )    map_->Map_m[ line ][ collun ] = WALLS;
                else if( line == ZERO || line == (HEIGHT_MAP - 1) )   map_->Map_m[ line ][ collun ] = WALLS;
                else    map_->Map_m[ line ][ collun ] = FREE_SPACE;

            }

        }

    }

#endif

void generateFood( struct Map * map_ ){

    srand( ( unsigned ) time ( NULL ) );

    Integer line;
    Integer collun;

    do{

        line = START + ( rand() % ( HEIGHT_MAP - 2 ) );
        collun = START + ( rand() % ( WIDTH_MAP - 2 ) );

    }while( map_->Map_m[ line ][ collun ] != ' ' );

    if( map_->Map_m[ line ][ collun ] == ' ' ){

        map_->Map_m[ line ][ collun ] = FOOD;

    }

}

void showMap( struct Map * map_ ){

    Integer line, collun;

    for( line = ZERO; line < HEIGHT_MAP; line++ ){

        for( collun = ZERO; collun < WIDTH_MAP; collun++ ){

            printf("%c", map_->Map_m[ line ][ collun ]);

        }

        printf("\n");

    }


}

// IMPLEMENTATION :: End