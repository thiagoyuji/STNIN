// INCLUDES :: Start

#include "SnakeCursor.h"

// INCLUDES :: End

// IMPLEMENTATION :: Start

void newCursor( struct Cursor * cursor_, Integer Init ){

    cursor_->up_down_Value = Init;
    cursor_->right_left_Value = Init;

}

void pressUP( struct Cursor * cursor_ ){

    if( cursor_->right_left_Value > START ){

        cursor_->right_left_Value -= 1;

    }

}

void pressDOWN( struct Cursor * cursor_, Integer lastPositionCursor ){

    if( cursor_->right_left_Value < lastPositionCursor ){

        cursor_->right_left_Value += 1;

    }

}

void pressRIGHT( struct Cursor * cursor_, Integer lastPositionCursor ){

    if( cursor_->up_down_Value < lastPositionCursor ){

        cursor_->up_down_Value += 1;

    }

}

void pressLEFT( struct Cursor * cursor_ ){

    if( cursor_->up_down_Value > START ){

        cursor_->up_down_Value -= 1;

    }

}

char getStdinKey(  ){

    char key = ' ';

    #if defined( _WINDOWS_ )

        key = getch();

    #else

        system( "stty echo raw" );

        key = getchar();

        system( "stty echo -raw" );

    #endif

    return key;

}

int kbhitLinux( void ){

    struct termios oldt, newt;
    int ch;
    int oldf;
    
    tcgetattr(STDIN_FILENO, &oldt);

    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    
    ch = getchar();
    
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    
    if( ch != EOF ){
        
        ungetc(ch, stdin);
        
        return 1;
    
    }
    
    return 0;

}

// IMPLEMENTATION :: End