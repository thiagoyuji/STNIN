// INCLUDES :: Start

#include "Hash.h"

// INCLUDES :: End

// INTERFACES :: Start

void getString( char String[] );
struct Student getInfoRegister( );
void printfStruct( struct Student );

// INTERFACES :: End

// MAIN :: Start

void main( ){

    struct Student newStudent;

    struct Student studentRegister;

    Integer count;

    printf("========================================create hash\n");

    newHash(  );
    showHash(  );

    printf("========================================create hash\n\n");

    printf("========================================insert hash\n");

    for( count = 0; count < 7; count++ ){

        printf("Register Number :: %d\n", count + 1);
        newStudent = getInfoRegister( );
        insertRegisterHash( &newStudent );

    }
    
    showHash(  );

    printf("========================================insert hash\n\n");

    printf("========================================key and remove\n");

    showHashKey( 1 );

    removeRegisterHash( 5 );

    showHashKey( 0 );

    printf("========================================key and remove\n\n");

    printf("========================================search student\n");

    studentRegister = searchRegister( 0 );
    printfStruct( studentRegister );

    printf("========================================search student\n\n");

    printf("========================================empty Hash\n");

    emptyHash(  );
    showHash(  );

    printf("========================================empty Hash\n\n");

}

// MAIN :: End

// IMPLEMENTATION :: Start

void getString( char String[] ){

    char caracter;
    Integer count = 0;

    do{

        caracter = getchar();
        String[ count ] = caracter;
        count++;

    }while( caracter != '\n' );

    String[ count - 1 ] = '\0';

}

struct Student getInfoRegister( ){

    struct Student cell;

    char name[100];
    char profession[100];

    cell.next = NULL;
    
    setbuf( stdin, NULL );
    printf("Insert Name: ");
    getString( name );
    strcpy( cell.name, name);

    printf("Insert Age: ");
    scanf("%d", &cell.age);

    return cell;

}

void printfStruct( struct Student student ){

    printf("\nRegister :: %d | Name :: %s | Age :: %d\n\n", 
    student.studentKey, student.name, student.age);

}

// IMPLEMENTATION :: End