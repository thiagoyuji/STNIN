// INCLUDES :: Start

#include "DoubleChainedList.h"

// INCLUDES :: End

// IMPLEMENTATION :: Start

void newList( struct List * list_ ){

    list_->size = ZERO;
    list_->init = NULL;

}// Create List-----------------------

void emptyList( struct List * list_ ){

    struct Node * cell;

    Integer sizeTemp = list_->size;

    while( sizeTemp != ZERO ){

        cell = list_->init;

        list_->init = cell->next;
        
        free( cell );

        sizeTemp = sizeTemp - 1;
    }

    free( list_->init );

    list_->size = ZERO;

}// Clean List-----------------------

Integer getSize( struct List list_ ){

    Integer sizeList;

    sizeList = list_.size;

    return sizeList;

}// Get List Size--------------------------------

enum Boolean checkEmptyList( struct List list_ ){

    enum Boolean checkList = FALSE;

    if( list_.size == ZERO )    checkList = TRUE;

    return checkList;

}// Check if List is Empty----------------------------

Integer searchItem( struct List list_, Integer Item ){

    struct Node * cell = list_.init;

    Integer position = GHOST;
    Integer count = 1;

    Integer sizeTemp = list_.size;

    if( sizeTemp >= 1 ){

        while( (cell->next != NULL) && (cell->Item != Item) ){

            cell = cell->next;
            count++;

        }

        if( cell->Item == Item )    position = count;
    
    }

    return position; 

}// Search Item and return position------------------

void insertInit( struct List * list_, Integer Item ){

    struct Node * new;

    new = (struct Node * ) malloc ( sizeof( struct Node ) );
    new->Item = Item;
    
    new->next = list_->init;
    new->previous = NULL;
    list_->init = new;

    list_->size += 1;

}// Insert in the init of list------------------------

void insertFinal( struct List * list_, Integer Item ){

    struct Node * new;

    struct Node * cell = list_->init;

    struct Node * previous;

    Integer sizeTemp = list_->size;

    new = ( struct Node *) malloc ( sizeof( struct Node ) );
    new->Item = Item;

    if( sizeTemp == ZERO ){

        new->next = list_->init;
        new->previous = NULL;

        list_->init = new;

        list_->size = sizeTemp + 1;

    }else{

        while( cell != NULL ){

            previous = cell;
            cell = cell->next;

        }

        if( cell == NULL ){

            new->next = previous->next;
            new->previous = previous;

            previous->next = new;

            list_->size = sizeTemp + 1;

        }

    }

}// Insert in final of List---------------------------------------------

void insertLocal( struct List * list_, Integer Item, Integer position ){

    struct Node * new;
    struct Node * cell = list_->init;
    struct Node * previous;

    Integer sizeTemp = list_->size;
    Integer count = 1;

    if( position >= 1 && position <= ( sizeTemp + 1) ){

        new = ( struct Node * ) malloc ( sizeof( struct Node ) );
        new->Item = Item;

        if( position == 1 ){

            new->next = list_->init;
            new->previous = NULL;

            list_->init = new;

        }else{

            while( count != position ){

                previous = cell;
                cell = cell->next;
                count++;

            }
            new->next = cell;
            new->previous = previous;

            previous->next = new;

        }

        list_->size = sizeTemp + 1;

    }

}// Insert in local of list------------

void removeInit( struct List * list_ ){

    struct Node * cell = list_->init;

    Integer sizeTemp = list_->size;

    if( sizeTemp >= 1 ){

        list_->init = cell->next;

        list_->size = sizeTemp - 1;

        free( cell );

    }

}// Remove in init of list--------------

void removeFinal( struct List * list_ ){

    struct Node * cell = list_->init;
    struct Node * previous;

    Integer sizeTemp = list_->size;

    if( sizeTemp == 1 ){

        list_->init = cell->next;

        list_->size = sizeTemp - 1;

        free( cell );

    }else{

        while( cell->next != NULL ){

            previous = cell;
            cell = cell->next;

        }

        if( cell->next == NULL ){

            previous->next = cell->next;

            list_->size = sizeTemp - 1;

            free( cell );

        }

    }

}// Remove in final of list-------------------------------

void removeLocal( struct List * list_, Integer position ){

    struct Node * cell = list_->init;
    struct Node * previous;

    Integer sizeTemp = list_->size;
    Integer count = 1;

    if( sizeTemp >= 1 ){

        if( position >= 1 && position <= sizeTemp ){

            if( position == 1 ){

                list_->init = cell->next;

            }else{

                while( count != position ){

                    previous = cell;
                    cell = cell->next;
                    count++;

                }

                previous->next = cell->next;

                cell->next->previous = previous;

            }

            list_->size = sizeTemp - 1;
            free( cell );

        }

    }

}// Remove in local of List--------

void showList( struct List list_ ){

    struct Node * cell = list_.init;

    printf("SizeList :: %ld\n", list_.size );
    
    printf("List :: ");
    while( cell != NULL ){

        printf("| %d | ", cell->Item);
        cell = cell->next;

    }
    printf("\n\n");

}// Print List int Video

// IMPLEMENTATION :: End
