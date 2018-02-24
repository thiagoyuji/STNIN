// INCLUDE::start

#include "get.h"

// INCLUDE::end

// IMPLEMENTATION::start

void getString( char ** string ){

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


void getChar( char * caracter ){

	*caracter = getchar();

}


void getInt( int * integer ){

	scanf("%d", &( *integer ));

}


void getFloat( float * real ){

	scanf("%f", &( *real ));

}

void getDouble( double * bigReal ){

	scanf("%lf", &( *bigReal ));

}

void getLongLongInt( long long int * integer ){

	scanf ("%lld", &( *integer ));

}

// IMPLEMENTATION::end
