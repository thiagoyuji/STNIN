// INCLUDES :: Start

#include "Row.h"

// INCLUDES :: End

// MAIN :: Start

void main(  ){

	struct Row row_;
	struct Row row__;

	// Testing NewRow ...
	printf("= = = = = = = = = =Testing NewRow\n\n");

		newRow( &row_ );
		printf("Name :: row_\t -> ");	showInit( row_ );

		newRow( &row__ );
		printf("Name :: row__\t -> ");	showInit( row__ );

	printf("= = = = = = = = = =Status :: Successful\n\n");
	// Status :: Successful

	// Testing MaxSizeRow ...
	printf("= = = = = = = = = =Testing MaxSizeRow\n\n");

		Integer size = maxSizeRow( );
		printf("Max Size Row :: %d\n\n", size);

	printf("= = = = = = = = = =Status :: Successful\n\n");
	// Status :: Successful

	// Testing Push ...
	printf("= = = = = = = = = =Testing Push\n\n");

		push( &row_, 1 );
		push( &row_, 3 );
		push( &row_, 2 );
		push( &row_, 4 );

		push( &row__, 1 );
		push( &row__, 3 );
		push( &row__, 2 );
		push( &row__, 4 );

		showInit( row_ );

	printf("= = = = = = = = = =Status :: Successful\n\n");
	// Status :: Successful

	// Testing AccessInit ...
	printf("= = = = = = = = = =Testing AccessInit\n\n");

		Integer init = accessInit( row_ );
		printf("Init :: %d\n\n", init);

	printf("= = = = = = = = = =Status :: Successful\n\n");
	// Status :: Successful

	// Testing Pop ...
	printf("= = = = = = = = = =Testing Pop\n\n");

		showInit( row_ );

		pop( &row_ );
		showInit( row_ );

		pop( &row_ );
		showInit( row_ );

		pop( &row_ );
		showInit( row_ );

		pop( &row_ );
		showInit( row_ );

	printf("= = = = = = = = = =Status :: Successful\n\n");
	// Status :: Successful

	// Testing EmptyRow ...
	printf("= = = = = = = = = =Testing EmptyRow\n\n");

		showInit( row__ );
		emptyRow( &row__ );
		showInit( row__ );

	printf("= = = = = = = = = =Status :: Successful\n\n");
	// Status :: Successful

}

// MAIN :: End
