// INCLUDES :: Start

#include "SnakeScore.h"

// INCLUDES :: End

// IMPLEMENTATION :: Start

void createScore( struct Score * score_ ){

    // Put ZERO in Snake Score
    score_->SnakeScore = ZERO;


    // put ZERO in file SnakeHighestScore
    FILE * highestScore;

    #ifdef _WIN32
        highestScore = fopen( "SnakeHighestScore.txt", "w+" );
    #else
        highestScore = fopen( "../SnakeHighestScore.txt", "w+" );
    #endif

    if( highestScore == NULL ){
        fprintf( stderr, "ERROR :: File Dont Find\n");
        exit( -1 );
    }

    fseek( highestScore, ZERO, SEEK_END );
    if( (ftell( highestScore ) - 1) <= ZERO ){

        fprintf( highestScore, "%d", ZERO );

    }
    fclose( highestScore );

}

void refreshScore( struct Score * score_ ){

    score_->SnakeScore = ZERO;

}

Integer checkHighestScore( struct Score score_ ){

    Integer highest;

    FILE * highestScoreRead;


    #ifdef _WIN32
        highestScoreRead = fopen( "SnakeHighestScore.txt", "r" );
    #else
        highestScoreRead = fopen( "../SnakeHighestScore.txt", "r" );
    #endif

    if( highestScoreRead == NULL ){
        fprintf( stderr, "ERROR :: File Dont Find\n");
        exit( -1 );
    }

    rewind( highestScoreRead );

    fscanf( highestScoreRead,"%d", &highest );

    fclose( highestScoreRead );

    if( score_.SnakeScore > highest ){

        highest = score_.SnakeScore;

        FILE * highestScoreWrite;

        #ifdef _WIN32
            highestScoreWrite = fopen( "SnakeHighestScore.txt", "w" );
        #else
            highestScoreWrite = fopen( "../SnakeHighestScore.txt", "w" );
        #endif

        if( highestScoreWrite == NULL ){
            fprintf( stderr, "ERROR :: File Dont Find\n");
            exit( -1 );
        }

        rewind( highestScoreWrite );

        fprintf( highestScoreWrite,"%d", highest );

        fclose( highestScoreWrite );

    }

    return highest;

}

enum Boolean checkSnakeHighestScoreFile( ){

    enum Boolean checkFile = FALSE;

    Integer value;

    FILE * score;

    #ifdef _WIN32
        score = fopen( "SnakeHighestScore.txt", "r" );
    #else
        score = fopen( "../SnakeHighestScore.txt", "r" );
    #endif

    fseek( score, ZERO, SEEK_END );
    if( (ftell( score ) - 1) < ZERO ){

    }else{

        rewind( score );
        fscanf( score,"%d", &value );

        if( value != ZERO ){
            checkFile = TRUE;
        }

    }

    return checkFile;

}

Integer saveLastScore( struct Score score_ ){

    FILE * lastScore;

    #ifdef _WIN32
        lastScore = fopen( "SnakeLastScore.txt", "w" );
    #else
        lastScore = fopen( "../SnakeLastScore.txt", "w" );
    #endif

    if( lastScore == NULL ){
        fprintf( stderr, "ERROR :: File Dont Find\n");
        exit( -1 );
    }

    fprintf( lastScore, "%d", score_.SnakeScore);

    fclose( lastScore );

    return score_.SnakeScore;

}

void updateScore( struct Score * score_ ){

    score_->SnakeScore += 1;

}

// IMPLEMENTATION :: End