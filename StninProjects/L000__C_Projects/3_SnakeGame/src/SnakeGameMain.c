// INCLUDES :: Start

#include "SnakeMenu.h"
#include "Snake.h"
#include "SnakeMap.h"
#include "SnakeScore.h"

// INCLUDES :: End

// MAIN :: Start

void main(  ){

    struct Snake _snake_;
    struct Map _map_;
    struct Score _score_;

    Integer operation;
    Integer h = 0;

    enum Boolean checkGameAlreadyPlayed;

    checkGameAlreadyPlayed = checkSnakeHighestScoreFile();

    if( checkGameAlreadyPlayed == FALSE ){

        createScore( &_score_ );
    
    }

    refreshScore( &_score_ );

    do{
        
        operation = showMenu(  );

        if( operation == START ){

            refreshScore( &_score_ );

            // Start the Game
            createMap( &_map_ );
            createSnake( &_snake_ );

            defineSnakePosition( &_map_ );

            moveSnake( &_snake_, &_map_, &_score_ );            

            getchar();

        }else if( operation == SCORE ){

            Integer highest;
            Integer last;

            // Show Score of Last Game
            highest = checkHighestScore( _score_ );
            last = saveLastScore( _score_ );

            printf("\n\nCongratulations :: Your Highest Score is %d\n", highest);
            printf("Congratulations :: Your Last Score is %d\n\n", last);

            getchar();

        }else if( operation == RESET ){

            createScore( &_score_ );

            printf("\n\n==== >>>> GAME RESTARTED <<<< ====\n\n");

            getchar();

        }

    }while( operation != EXIT );

}

// MAIN :: End