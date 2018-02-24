// INCLUDES :: Start

#include "Snake.h"

// INCLUDES :: End

// IMPLEMENTATION :: Start

void createSnake( struct Snake * snake_ ){

    snake_->head_Line = START + 1;
    snake_->head_Collun = START + 1;

    snake_->death = FALSE;
    snake_->snakeSize = START;

}

void defineSnakePosition( struct Map * map_ ){

    map_->Map_m[ START + 1 ][ START + 1 ] = SNAKE;

}

void moveSnake( struct Snake * snake_, struct Map * map_, struct Score * score_ ){

    struct Cursor cursor_;

    char key;
    char backup;

    enum Boolean Food;

    newCursor( &cursor_, 2 );

    generateFood( map_ );

    do{

        showMap( map_ );

        backup = key;
        
        key = getStdinKey();

        if( checkDirection( key, backup ) == TRUE )    key = backup;

        switch( key ){

            case UP_UPPERCASE:
            case UP_DOWNCASE:

                #ifdef _WIN32
                #else

                    while( !kbhitLinux() ){

                        Food = checkFoodAroundUp( snake_, score_, map_, cursor_ );

                        if( checkWallAroundUp( snake_, map_, cursor_ ) == TRUE )   break;
                        
                        growUpdateSnake( snake_, map_, &cursor_, key, Food );

                        snake_->head_Line -= 1;                        

                        usleep( 200000 );
                        cleanVideo();
                        showMap( map_ );

                    }
                
                #endif

                break;

            case DOWN_UPPERCASE:
            case DOWN_DOWNCASE:

                #ifdef _WIN32
                #else

                    while( !kbhitLinux() ){

                        Food = checkFoodAroundDown( snake_, score_, map_, cursor_ );

                        if( checkWallAroundDown( snake_, map_, cursor_ ) == TRUE )   break;
                        
                        growUpdateSnake( snake_, map_, &cursor_, key, Food );

                        snake_->head_Line += 1;

                        usleep( 200000 );
                        cleanVideo();
                        showMap( map_ );

                    }

                #endif

                break;

            case RIGHT_UPPERCASE:
            case RIGHT_DOWNCASE:

                #ifdef _WIN32
                #else

                    while( !kbhitLinux() ){

                        Food = checkFoodAroundRight( snake_, score_, map_, cursor_ );
                        
                        if( checkWallAroundRight( snake_, map_, cursor_ ) == TRUE )   break;
                        
                        growUpdateSnake( snake_, map_, &cursor_, key, Food );

                        snake_->head_Collun += 1;

                        usleep( 200000 );
                        cleanVideo();
                        showMap( map_ );

                    }

                #endif

                break;

            case LEFT_UPPERCASE:
            case LEFT_DOWNCASE:

                #ifdef _WIN32
                #else

                    while( !kbhitLinux() ){

                        Food = checkFoodAroundLeft( snake_, score_, map_, cursor_ );
                        
                        if( checkWallAroundLeft( snake_, map_, cursor_ ) == TRUE )   break;
                        
                        growUpdateSnake( snake_, map_, &cursor_, key, Food );

                        snake_->head_Collun -= 1;

                        usleep( 200000 );
                        cleanVideo();
                        showMap( map_ );

                    }

                #endif
                
                break;

            default:

                key = backup;

                break;

        }

        cleanVideo();

    }while( snake_->death == FALSE );

    if( snake_->death == TRUE ){

        printf("\n\n==== >>>> GAME OVER <<<< ====\n\n");

    }

}

enum Boolean checkFoodAroundUp( struct Snake * snake_, struct Score * score_, struct Map * map_, struct Cursor cursor_ ){

    enum Boolean check = FALSE;

    if( map_->Map_m[ cursor_.right_left_Value - 1 ][ cursor_.up_down_Value ]  == FOOD ){

        map_->Map_m[ cursor_.right_left_Value - 1 ][ cursor_.up_down_Value ] = FREE_SPACE;

        updateScore( score_ );

        generateFood( map_ );

        check = TRUE;

        snake_->snakeSize += 1;

    }  

    return check;

}

enum Boolean checkFoodAroundDown( struct Snake * snake_, struct Score * score_, struct Map * map_, struct Cursor cursor_ ){

    enum Boolean check = FALSE;

    if( map_->Map_m[ cursor_.right_left_Value + 1 ][ cursor_.up_down_Value ]  == FOOD ){

        map_->Map_m[ cursor_.right_left_Value + 1 ][ cursor_.up_down_Value ] = FREE_SPACE;

        updateScore( score_ );

        generateFood( map_ );

        check = TRUE;

        snake_->snakeSize += 1;

    }

    return check;

}

enum Boolean checkFoodAroundRight( struct Snake * snake_, struct Score * score_, struct Map * map_, struct Cursor cursor_ ){

    enum Boolean check = FALSE;

    if( map_->Map_m[ cursor_.right_left_Value ][ cursor_.up_down_Value + 1 ]  == FOOD ){

        map_->Map_m[ cursor_.right_left_Value ][ cursor_.up_down_Value + 1 ] = FREE_SPACE;

        updateScore( score_ );

        generateFood( map_ );

        check = TRUE;

        snake_->snakeSize += 1;

    }

    return check;

}

enum Boolean checkFoodAroundLeft( struct Snake * snake_, struct Score * score_, struct Map * map_, struct Cursor cursor_ ){

    enum Boolean check = FALSE;

    if( map_->Map_m[ cursor_.right_left_Value ][ cursor_.up_down_Value - 1 ]  == FOOD ){

        map_->Map_m[ cursor_.right_left_Value ][ cursor_.up_down_Value - 1 ] = FREE_SPACE;

        updateScore( score_ );

        generateFood( map_ );

        check = TRUE;

        snake_->snakeSize += 1;

    }

    return check;

}

enum Boolean checkWallAroundUp( struct Snake * snake_, struct Map * map_, struct Cursor cursor_ ){

    enum Boolean check = FALSE;

    #ifdef _WIN32

        if( map_->Map_m[ cursor_.right_left_Value - 1 ][ cursor_.up_down_Value ]  == RIGHT_LEFT_WALLS ){

            snake_->death = TRUE;
            check = TRUE;

        }


    #else

        if( map_->Map_m[ cursor_.right_left_Value - 1 ][ cursor_.up_down_Value ]  == WALLS ){

            snake_->death = TRUE;
            check = TRUE;

        } 
        
    #endif

    return check;

}

enum Boolean checkWallAroundDown( struct Snake * snake_, struct Map * map_, struct Cursor cursor_ ){

    enum Boolean check = FALSE;

    #ifdef _WIN32

        if( map_->Map_m[ cursor_.right_left_Value + 1 ][ cursor_.up_down_Value ]  == RIGHT_LEFT_WALLS ){

            snake_->death = TRUE;
            check = TRUE;

        }

    #else

        if( map_->Map_m[ cursor_.right_left_Value + 1 ][ cursor_.up_down_Value ]  == WALLS ){

            snake_->death = TRUE;
            check = TRUE;

        }

    #endif

    return check;

}

enum Boolean checkWallAroundRight( struct Snake * snake_, struct Map * map_, struct Cursor cursor_ ){

    enum Boolean check = FALSE;

    #ifdef _WIN32

        if( map_->Map_m[ cursor_.right_left_Value ][ cursor_.up_down_Value + 1 ]  == TOP_BOT_WALLS ){

            snake_->death = TRUE;
            check = TRUE;

        }

    #else

        if( map_->Map_m[ cursor_.right_left_Value ][ cursor_.up_down_Value + 1 ]  == WALLS ){

            snake_->death = TRUE;
            check = TRUE;

        }

    #endif

    return check;

}

enum Boolean checkWallAroundLeft( struct Snake * snake_, struct Map * map_, struct Cursor cursor_ ){

    enum Boolean check = FALSE;

    #ifdef _WIN32

        if( map_->Map_m[ cursor_.right_left_Value ][ cursor_.up_down_Value - 1 ]  == TOP_BOT_WALLS ){

            snake_->death = TRUE;
            check = TRUE;

        }

    #else

        if( map_->Map_m[ cursor_.right_left_Value ][ cursor_.up_down_Value - 1 ]  == WALLS ){

            snake_->death = TRUE;
            check = TRUE;

        }

    #endif

    return check;

}

enum Boolean checkDirection( char key, char backup ){

    enum Boolean check = FALSE;

    if( (backup == UP_UPPERCASE || backup == UP_DOWNCASE) && (key == DOWN_UPPERCASE || key == DOWN_DOWNCASE) ){

        check = TRUE;

    }else if((backup == RIGHT_UPPERCASE || backup == RIGHT_DOWNCASE) && (key == LEFT_UPPERCASE || key == LEFT_DOWNCASE) ){

        check = TRUE;

    }else if( (backup == DOWN_UPPERCASE || backup == DOWN_DOWNCASE) && (key == UP_UPPERCASE || key == UP_DOWNCASE) ){

        check = TRUE;

    }else if( (backup == LEFT_UPPERCASE || backup == LEFT_DOWNCASE) && (key == RIGHT_UPPERCASE || key == RIGHT_DOWNCASE) ){

        check = TRUE;

    }

    return check;

}

void growUpdateSnake( struct Snake * snake_, struct Map * map_, struct Cursor * cursor_, char key, enum Boolean checkFood ){

    Integer line, collun;
    Integer countLine, countCollun;

    Integer count;

    enum Boolean walk;

    switch( key ){

        case UP_UPPERCASE:
        case UP_DOWNCASE:

            walk = FALSE;

            if( snake_->snakeSize == 2 && checkFood == TRUE ){

                    //grow snake
                map_->Map_m[cursor_->right_left_Value + 1][cursor_->up_down_Value] = SNAKE;

                pressUP( cursor_ );

                line = cursor_->right_left_Value;
                collun = cursor_->up_down_Value;

                do{

                    if( map_->Map_m[line + 1][collun] == SNAKE ){

                        map_->Map_m[line][collun] = TEMP;
                        line += 1;
                        map_->Map_m[line][collun] = FREE_SPACE;

                    }else if( map_->Map_m[line][collun + 1] == SNAKE ){

                        map_->Map_m[line][collun] = TEMP;
                        collun += 1;
                        map_->Map_m[line][collun] = FREE_SPACE;

                    }else if( map_->Map_m[line][collun - 1] == SNAKE ){

                        map_->Map_m[line][collun] = TEMP;
                        collun -= 1;
                        map_->Map_m[line][collun] = FREE_SPACE;

                    }else if( map_->Map_m[ line - 1][collun] == SNAKE ){

                        map_->Map_m[line][collun] = TEMP;
                        line -= 1;
                        map_->Map_m[line][collun] = FREE_SPACE;

                    }else{

                        walk = TRUE;

                        map_->Map_m[line][collun] = FREE_SPACE;

                    }


                }while( walk != TRUE );

            }else if( snake_->snakeSize == 1 && checkFood == FALSE ){

                map_->Map_m[cursor_->right_left_Value][cursor_->up_down_Value] = FREE_SPACE;

                pressUP( cursor_ );

                map_->Map_m[cursor_->right_left_Value][cursor_->up_down_Value] = SNAKE;

            }else{

                pressUP( cursor_ );

                line = cursor_->right_left_Value;
                collun = cursor_->up_down_Value;

                count = 1;

                do{

                    if( map_->Map_m[line + 1][collun] == SNAKE ){

                        map_->Map_m[line][collun] = TEMP;
                        line += 1;
                        map_->Map_m[line][collun] = FREE_SPACE;

                    }else if( map_->Map_m[line][collun + 1] == SNAKE ){

                        map_->Map_m[line][collun] = TEMP;
                        collun += 1;
                        map_->Map_m[line][collun] = FREE_SPACE;

                    }else if( map_->Map_m[line][collun - 1] == SNAKE ){

                        map_->Map_m[line][collun] = TEMP;
                        collun -= 1;
                        map_->Map_m[line][collun] = FREE_SPACE;

                    }else if( map_->Map_m[ line - 1][collun] == SNAKE ){

                        map_->Map_m[line][collun] = TEMP;
                        line -= 1;
                        map_->Map_m[line][collun] = FREE_SPACE;

                    }
                    
                    if( count == snake_->snakeSize && checkFood == TRUE ){

                        map_->Map_m[line][collun] = TEMP;

                    }

                    count++;

                }while( count <= snake_->snakeSize );

            }                

            break;

        case DOWN_UPPERCASE:
        case DOWN_DOWNCASE:

            walk = FALSE;


            if( snake_->snakeSize == 2 && checkFood == TRUE ){

                //grow snake
                map_->Map_m[cursor_->right_left_Value - 1][cursor_->up_down_Value] = SNAKE;

                pressDOWN( cursor_, LIMIT_COLLUN_SNAKE );

                line = cursor_->right_left_Value;
                collun = cursor_->up_down_Value;

                do{

                    if( map_->Map_m[line - 1][collun] == SNAKE ){

                        map_->Map_m[line][collun] = TEMP;
                        line -= 1;
                        map_->Map_m[line][collun] = FREE_SPACE;

                    }else if( map_->Map_m[line][collun + 1] == SNAKE ){

                        map_->Map_m[line][collun] = TEMP;
                        collun += 1;
                        map_->Map_m[line][collun] = FREE_SPACE;

                    }else if( map_->Map_m[line][collun - 1] == SNAKE ){

                        map_->Map_m[line][collun] = TEMP;
                        collun -= 1;
                        map_->Map_m[line][collun] = FREE_SPACE;

                    }else if( map_->Map_m[ line + 1][collun] == SNAKE ){

                        map_->Map_m[line][collun] = TEMP;
                        line += 1;
                        map_->Map_m[line][collun] = FREE_SPACE;

                    }else{

                        walk = TRUE;

                        map_->Map_m[line][collun] = FREE_SPACE;

                    }


                }while( walk != TRUE );

            }else if( snake_->snakeSize == 1 && checkFood == FALSE ){

                map_->Map_m[cursor_->right_left_Value][cursor_->up_down_Value] = FREE_SPACE;

                pressDOWN( cursor_, LIMIT_COLLUN_SNAKE );

                map_->Map_m[cursor_->right_left_Value][cursor_->up_down_Value] = SNAKE;

            }else{

                pressDOWN( cursor_, LIMIT_COLLUN_SNAKE );

                line = cursor_->right_left_Value;
                collun = cursor_->up_down_Value;

                count = 1;

                do{

                    if( map_->Map_m[line - 1][collun] == SNAKE ){

                        map_->Map_m[line][collun] = TEMP;
                        line -= 1;
                        map_->Map_m[line][collun] = FREE_SPACE;

                    }else if( map_->Map_m[line][collun + 1] == SNAKE ){

                        map_->Map_m[line][collun] = TEMP;
                        collun += 1;
                        map_->Map_m[line][collun] = FREE_SPACE;

                    }else if( map_->Map_m[line][collun - 1] == SNAKE ){

                        map_->Map_m[line][collun] = TEMP;
                        collun -= 1;
                        map_->Map_m[line][collun] = FREE_SPACE;

                    }else if( map_->Map_m[ line + 1][collun] == SNAKE ){

                        map_->Map_m[line][collun] = TEMP;
                        line += 1;
                        map_->Map_m[line][collun] = FREE_SPACE;

                    }
                    
                    if( count == snake_->snakeSize && checkFood == TRUE ){

                        map_->Map_m[line][collun] = TEMP;

                    }

                    count++;

                }while( count <= snake_->snakeSize );

            }                

            break;

        case RIGHT_UPPERCASE:
        case RIGHT_DOWNCASE:

            walk = FALSE;

            if( snake_->snakeSize == 2 && checkFood == TRUE ){
            
                    //grow snake
                map_->Map_m[cursor_->right_left_Value][cursor_->up_down_Value - 1] = SNAKE;

                pressRIGHT( cursor_, LIMIT_LINE_SNAKE );

                line = cursor_->right_left_Value;
                collun = cursor_->up_down_Value;

                do{

                    if( map_->Map_m[line][collun - 1] == SNAKE ){

                        map_->Map_m[line][collun] = TEMP;
                        collun -= 1;
                        map_->Map_m[line][collun] = FREE_SPACE;

                    }else if( map_->Map_m[line + 1][collun] == SNAKE ){

                        map_->Map_m[line][collun] = TEMP;
                        line += 1;
                        map_->Map_m[line][collun] = FREE_SPACE;

                    }else if( map_->Map_m[line - 1][collun] == SNAKE ){

                        map_->Map_m[line][collun] = TEMP;
                        line -= 1;
                        map_->Map_m[line][collun] = FREE_SPACE;

                    }else if( map_->Map_m[line][collun + 1] == SNAKE ){

                        map_->Map_m[line][collun] = TEMP;
                        collun += 1;
                        map_->Map_m[line][collun] = FREE_SPACE;

                    }else{

                        walk = TRUE;

                        map_->Map_m[line][collun] = FREE_SPACE;

                    }

                }while( walk != TRUE );

            }else if( snake_->snakeSize == 1 && checkFood == FALSE ){

                map_->Map_m[cursor_->right_left_Value][cursor_->up_down_Value] = FREE_SPACE;

                pressRIGHT( cursor_, LIMIT_LINE_SNAKE );

                map_->Map_m[cursor_->right_left_Value][cursor_->up_down_Value] = SNAKE;

            }else{    

                pressRIGHT( cursor_, LIMIT_LINE_SNAKE );

                line = cursor_->right_left_Value;
                collun = cursor_->up_down_Value;

                count = 1;

                do{

                    if( map_->Map_m[line][collun - 1] == SNAKE ){

                        map_->Map_m[line][collun] = TEMP;
                        collun -= 1;
                        map_->Map_m[line][collun] = FREE_SPACE;

                    }else if( map_->Map_m[line + 1][collun] == SNAKE ){

                        map_->Map_m[line][collun] = TEMP;
                        line += 1;
                        map_->Map_m[line][collun] = FREE_SPACE;

                    }else if( map_->Map_m[line - 1][collun] == SNAKE ){

                        map_->Map_m[line][collun] = TEMP;
                        line -= 1;
                        map_->Map_m[line][collun] = FREE_SPACE;

                    }else if( map_->Map_m[line][collun + 1] == SNAKE ){

                        map_->Map_m[line][collun] = TEMP;
                        collun += 1;
                        map_->Map_m[line][collun] = FREE_SPACE;

                    }
                    
                    if( count == snake_->snakeSize && checkFood == TRUE ){

                        map_->Map_m[line][collun] = TEMP;

                    }

                    count++;

                }while( count <= snake_->snakeSize );

            }                

            break;

        case LEFT_UPPERCASE:
        case LEFT_DOWNCASE:            

            walk = FALSE;

            if( snake_->snakeSize == 2 && checkFood == TRUE ){

                    //grow snake
                map_->Map_m[cursor_->right_left_Value][cursor_->up_down_Value + 1] = SNAKE;

                pressLEFT( cursor_ );

                line = cursor_->right_left_Value;
                collun = cursor_->up_down_Value;

                do{

                    if( map_->Map_m[line][collun + 1] == SNAKE ){

                        map_->Map_m[line][collun] = TEMP;
                        collun += 1;
                        map_->Map_m[line][collun] = FREE_SPACE;

                    }else if( map_->Map_m[line + 1][collun] == SNAKE ){

                        map_->Map_m[line][collun] = TEMP;
                        line += 1;
                        map_->Map_m[line][collun] = FREE_SPACE;

                    }else if( map_->Map_m[line - 1][collun] == SNAKE ){

                        map_->Map_m[line][collun] = TEMP;
                        line -= 1;
                        map_->Map_m[line][collun] = FREE_SPACE;

                    }else if( map_->Map_m[line][collun - 1] == SNAKE ){

                        map_->Map_m[line][collun] = TEMP;
                        collun -= 1;
                        map_->Map_m[line][collun] = FREE_SPACE;

                    }else{

                        walk = TRUE;

                        map_->Map_m[line][collun] = FREE_SPACE;

                    }


                }while( walk != TRUE );

            }else if( snake_->snakeSize == 1 && checkFood == FALSE ){

                map_->Map_m[cursor_->right_left_Value][cursor_->up_down_Value] = FREE_SPACE;

                pressLEFT( cursor_ );

                map_->Map_m[cursor_->right_left_Value][cursor_->up_down_Value] = SNAKE;

            }else{

                pressLEFT( cursor_ );

                line = cursor_->right_left_Value;
                collun = cursor_->up_down_Value;

                count = 1;

                do{

                    if( map_->Map_m[line][collun + 1] == SNAKE ){

                        map_->Map_m[line][collun] = TEMP;
                        collun += 1;
                        map_->Map_m[line][collun] = FREE_SPACE;

                    }else if( map_->Map_m[line + 1][collun] == SNAKE ){

                        map_->Map_m[line][collun] = TEMP;
                        line += 1;
                        map_->Map_m[line][collun] = FREE_SPACE;

                    }else if( map_->Map_m[line - 1][collun] == SNAKE ){

                        map_->Map_m[line][collun] = TEMP;
                        line -= 1;
                        map_->Map_m[line][collun] = FREE_SPACE;

                    }else if( map_->Map_m[line][collun - 1] == SNAKE ){

                        map_->Map_m[line][collun] = TEMP;
                        collun -= 1;
                        map_->Map_m[line][collun] = FREE_SPACE;

                    }
                    
                    if( count == snake_->snakeSize && checkFood == TRUE ){

                        map_->Map_m[line][collun] = TEMP;

                    }

                    count++;

                }while( count <= snake_->snakeSize );

            }                

            break;

    }

    for( countLine = 1; countLine < HEIGHT_MAP; countLine++ ){

        for( countCollun = 1; countCollun < WIDTH_MAP; countCollun++ ){

            if( map_->Map_m[countLine][countCollun] == TEMP ){

                map_->Map_m[countLine][countCollun] = SNAKE;

            }

        }

    }

}

// IMPLEMENTATION :: End