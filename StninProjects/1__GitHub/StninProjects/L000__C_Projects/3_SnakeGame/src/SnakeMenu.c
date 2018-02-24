// INCLUDES :: Start

#include "SnakeMenu.h"

// INCLUDES :: End

// IMPLEMENTATION :: Start

Integer showMenu(  ){

    struct Cursor cursor_;

    char key;
    
    Integer operation;

    newCursor( &cursor_, 1 );

    showOptionStart();

    do{

        key = getStdinKey();

        switch( key ){

            case UP_UPPERCASE:
            case UP_DOWNCASE:

                pressUP( &cursor_ );
                break;

            case DOWN_UPPERCASE:
            case DOWN_DOWNCASE:

                pressDOWN( &cursor_, LAST_POSITION_CURSOR );
                showOptionExit();
                break;

            default:

                break;
        }

        operation = cursor_.right_left_Value;

        switch( operation ){

            case START:

                showOptionStart();
                break;
            
            case SCORE:

                showOptionScore();
                break;

            case RESET:

                showOptionReset();
                break;

            case EXIT:

                showOptionExit();
                break;

            default:

                break;

        }

    }while( key != ENTER );

    cleanVideo(  );

    return operation; 

}

void cleanVideo(  ){

    #ifdef _WIN32
        system( "cls" );
    #else
        system("clear");
    #endif

}

void showInit(  ){

    printf("Start Game :: SnakeGame\n\n");

}

void showLastScore(  ){

    printf("Last Score :: SnakeGame\n\n");

}

void showReset(  ){

    printf("Reset Game :: SnakeGame\n\n");

}

void showExit(  ){

    printf("Exit :: SnakeGame\n\n");

}

void showOptionStart(){

    cleanVideo(  );
    printf("\n\n>>> ");     showInit();
    printf("    ");         showLastScore();
    printf("    ");         showReset();
    printf("    ");         showExit();

}

void showOptionScore(){

    cleanVideo(  );
    printf("\n\n    ");     showInit();
    printf(">>> ");         showLastScore();
    printf("    ");         showReset();
    printf("    ");         showExit();

}

void showOptionReset(){

    cleanVideo(  );
    printf("\n\n    ");     showInit();
    printf("    ");         showLastScore();
    printf(">>> ");         showReset();
    printf("    ");         showExit();

}

void showOptionExit(){

    cleanVideo(  );
    printf("\n\n    ");     showInit();
    printf("    ");         showLastScore();
    printf("    ");         showReset();
    printf(">>> ");         showExit();

}

// IMPLEMENTATION :: End