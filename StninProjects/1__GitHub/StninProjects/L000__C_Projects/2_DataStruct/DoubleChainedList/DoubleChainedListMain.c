// INCLUDES :: Start

#include "DoubleChainedList.h"

// INCLUDES :: End

// MAIN :: Start

void main(){

    struct List list_;

    // Testing NewList
	printf("= = = = = = = = = =Testing :: NewList\n\n");

		newList( &list_ );
		showList( list_ );

	printf("= = = = = = = = = =Status :: Successful\n\n");
	// Status :: Successful

	// Testing Insert ...
	printf("= = = = = = = = = =Testing :: Insert\n\n");

		insertInit( &list_, 4 );
		showList( list_ );

		insertInit( &list_, 2 );
		showList( list_ );

		insertFinal( &list_, 5 );
		showList( list_ );

		insertFinal( &list_, 6 );
		showList( list_ );

		insertLocal( &list_, 3, 3 );
		showList( list_ );

		insertLocal( &list_, 1, 1 );
		showList( list_ );

	printf("= = = = = = = = = =Status :: Successful\n\n");
	// Status :: Successful

	// Testing Remove ...
	printf("= = = = = = = = = =Testing :: Remove\n\n");

		removeInit( &list_ );
		showList( list_ );

		removeFinal( &list_ );
		showList( list_ );

		removeLocal( &list_, 2 );
		showList( list_ );

	printf("= = = = = = = = = =Status :: Successful\n\n");
	// Status :: Successful

	// Testing SearchItem ...
	printf("= = = = = = = = = =Testing :: SearchItem\n\n");

		Integer position = searchItem( list_, 4 );
        printf("Position :: %d\n\n", position);

	printf("= = = = = = = = = =Status :: Successful\n\n");
	// Status :: Successful

    // Testing SizeList ...
	printf("= = = = = = = = = =Testing :: SizeList\n\n");

		Integer maxSize = getSize( list_ );
        printf("SizeList :: %d\n\n", maxSize);

	printf("= = = = = = = = = =Status :: Successful\n\n");
	// Status :: Successful

    // Testing EmptyList ...
	printf("= = = = = = = = = =Testing :: EmptyList\n\n");

		emptyList( &list_ );
		showList( list_ );

	printf("= = = = = = = = = =Status :: Successful\n\n");
	// Status :: Successful

}

// MAIN :: End