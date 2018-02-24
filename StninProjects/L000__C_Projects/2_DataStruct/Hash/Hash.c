// INCLUDES :: Start

#include "Hash.h"

// INCLUDES :: End

// IMPLEMENTATION :: Start

void newHash(  ){

    Integer count;

    for( count = 0; count <= ( HASH_KEY - 1 ); count++ ){
    
        HashTable[ count ].registersInit = NULL;
        HashTable[ count ].size = ZERO;

    }

}// Create Hash----

void emptyHash(  ){

    Integer count;

    struct Student * cell;

    for( count = 0; count <= (HASH_KEY - 1); count++ ){

        cell = HashTable[ count ].registersInit;

        while( cell != NULL ){

            HashTable[ count ].registersInit = cell->next;
            
            free( cell );
            
            cell = HashTable[ count ].registersInit;

        }

    }

}// Clean Hash--------------------------------------

struct Student searchRegister( Integer studentKey ){

    Integer key = HASH_FUNCTION( studentKey, HASH_KEY );
    Integer sizeTemp;

    struct Student studentRegister;
    struct Student * cell;

    if( key >= ZERO && key <= ( HASH_KEY - 1 ) ){

        cell = HashTable[ key ].registersInit;
        sizeTemp = HashTable[ key ].size;

        if( sizeTemp > 0 ){

            while( (cell != NULL) && (cell->studentKey != studentKey) ){

                cell->next;

            }

            if( cell->studentKey == studentKey ){

                studentRegister.studentKey = cell->studentKey;
                strcpy( studentRegister.name, cell->name );
                studentRegister.age = cell->age;

            }

        }

    }

    return studentRegister;

}// Get Insformation of some Node---------------------- 

void insertRegisterHash( struct Student * newStudent ){

    static int lastRegisterKey;

    Integer key = HASH_FUNCTION( lastRegisterKey, HASH_KEY );
    Integer sizeTemp;

    struct Student * new;
    struct Student * cell;

    if( key >= ZERO && key <= ( HASH_KEY - 1 ) ){

        cell = HashTable[ key ].registersInit;
        sizeTemp = HashTable[ key ].size;

        new = ( struct Student * ) malloc ( sizeof( struct Student ) );

        new->studentKey = lastRegisterKey;
        strcpy( new->name, newStudent->name );
        new->age = newStudent->age;

        if( sizeTemp == ZERO ){

            new->next = HashTable[ key ].registersInit;
            HashTable[ key ].registersInit = new;

        }else{

            while( cell->next != NULL ){

                cell = cell->next;    

            }

            new->next = cell->next;
            cell->next = new;

        }

        HashTable[ key ].size += 1;
        lastRegisterKey += 1;

    }

}// Insert in Hash----------------------------

void removeRegisterHash( Integer studentKey ){

    Integer key = HASH_FUNCTION( studentKey, HASH_KEY );
    Integer sizeTemp;

    struct Student * cell;
    struct Student * previous;

    if( key >= ZERO && key <= ( HASH_KEY - 1 ) ){

        cell = HashTable[ key ].registersInit;
        sizeTemp = HashTable[ key ].size;


        if( (sizeTemp == 1) && (cell->studentKey == studentKey) ){

            HashTable[ key ].registersInit = cell->next;
            free( cell );

        }else{

            while( (cell->next != NULL ) && (cell->studentKey != studentKey) ){

                previous = cell;
                cell = cell->next;

            }

            if( cell->studentKey == studentKey ){

                previous->next = cell->next;
                free( cell );

            }

        }


    }

}// Remove of Hash

void showHash(  ){

    printf("\n");

    Integer count;
    Integer size;

    struct Student * cell;

    for( count = 0; count <= ( HASH_KEY - 1 ); count++ ){
        
        size = HashTable[ count ].size;

        printf("-----------------------------------------------------------------------------\n");
        printf("-> Hash Key :: %d | Size :: %d-> \n\n", count, size );

        cell = HashTable[ count ].registersInit;

        // Print Registers of Key Hash
        while( cell != NULL ){

            printf("Student Key :: %d | ", cell->studentKey);
            printf("Student Name :: %s | ", cell->name);
            printf("Student Age :: %d\n", cell->age);

            cell = cell->next;

        }
        // Print Registers of Key Hash
    }

    printf("\n\n");

}// Show full Data Hash----------------

void showHashKey( Integer key ){

    struct Student * cell;

    Integer size;

    if( key >= ZERO && key <= (HASH_KEY - 1) ){

        size = HashTable[ key ].size;
        printf("-----------------------------------------------------------------------------\n");
        printf("-> Hash Key :: %d | Size :: %d-> \n\n", key, size );

        cell = HashTable[ key ].registersInit;

        // Print Registers of Key Hash
        while( cell != NULL ){

            printf("Student Key :: %d | ", cell->studentKey);
            printf("Student Name :: %s | ", cell->name);
            printf("Student Age :: %d\n", cell->age);

            cell = cell->next;

        }
        // Print Registers of Key Hash

    }
    printf("\n\n");

}// Show Data Hash Key 

// IMPLEMENTATION :: End