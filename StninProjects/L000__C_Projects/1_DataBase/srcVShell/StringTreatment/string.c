// INCLUDES::start

#include "string.h"

// INCLUDES::end

// IMPLEMENTATION::start

void getArrayString( String string ){
    
    int count = 0;
    
    char caracterTemporary;
    
    do{
        
        caracterTemporary = getchar();
        string[count] = caracterTemporary;
        count++;        
        
    }while( caracterTemporary != '\n' );
    
    string[ count - 1 ] = '\0';
    
}

void getDinamicString( RefString string ){

	int count = 0;

	size_t size = 1;

	char caracterTemporary;

	(*string) = ( char * )malloc( 1 * sizeof( char ) );

	do{

		caracterTemporary = getchar();

		*( *string + count )  = caracterTemporary;
		size += strlen( (*string) );
		(*string) = ( char * )realloc( (*string),( size + 1 ) * sizeof( char ) );

		count++;

	}while( caracterTemporary != '\n' );

	*( *string + (count - 1) ) = '\0';

}

// IMPLEMENTATION::end
