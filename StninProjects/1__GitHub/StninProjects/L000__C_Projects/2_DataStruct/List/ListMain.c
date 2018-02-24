/*

	Implementation of ArrayList ( ListMain.c -> Main File ) in C, Objective :: Learn Data Struct

*/

// INCLUDES :: Start

#include "List.h"

// INCLUDES :: End

// MAIN :: Start

void main(  ) {

	struct List list_;
	struct List list_random;

	// Testing NewList and NewRandomList ...
	printf("= = = = = = = = = =Testing :: NewList and NewRandomList\n\n");

		newList( &list_ );
		showList( list_ );

		newRandomList( &list_random, 1, 10 );
		showList( list_random );

	printf("= = = = = = = = = =Status :: Successful\n\n");
	// Status :: Successful

	// Testing EmptyList and MaxSizeList ...
	printf("= = = = = = = = = =Testing :: EmptyList and MaxSizeList\n\n");

		emptyList( &list_ );
		showList( list_ );

		Integer maxSize = maxSizeList(  );
		printf("Max Size :: %d\n\n", maxSize);

	printf("= = = = = = = = = =Status :: Successful\n\n");
	// Status :: Successful

	//Testing getItemList and seekItemList ...
	printf("= = = = = = = = = =Testing :: GetItemList and SeekItemList\n\n");

		Integer item = getItemList( list_random, 4 );
		printf("Item Random List position 4 :: %d\n\n", item);

		Integer position = seekItemList( list_random, 9 );
		printf("Position Random List Item 9 :: %d\n\n", position);

	printf("= = = = = = = = = =Status :: Successful\n\n");
	// Status :: Successful

	// Testing checkEmptyList ...
	printf("= = = = = = = = = =Testing :: CheckEmptyList\n\n");

		enum Boolean emptyList = checkEmptyList( list_ );
		printf("Empty List :: %d\n\n", emptyList);

	printf("= = = = = = = = = =Status :: Successful\n\n");
	// Status :: Successful

	// Testing Insert's ...
	printf("= = = = = = = = = =Testing :: Insert's\n\n");

		insertInit( &list_, 2 );
		insertInit( &list_, 1 );
		showList( list_ );

		insertFinal( &list_, 4 );
		showList( list_ );

		insertLocal( &list_, 3, 3 );
		showList( list_ );

	printf("= = = = = = = = = =Status :: Successful\n\n");
	// Status :: Successful

	// Testing Swap ...
	printf("= = = = = = = = = =Testing :: Swap\n\n");

		swapItemsPositions( &list_, 1, 4 );
		showList( list_ );

	printf("= = = = = = = = = =Status :: Successful\n\n");
	// Status :: Successful

	// Testing Remove's ...
	printf("= = = = = = = = = =Testing :: Remove's\n\n");

		removeLocal( &list_, 3 );
		showList( list_ );

		removeInit( &list_ );
		removeInit( &list_ );
		showList( list_ );

		removeFinal( &list_ );
		showList( list_ );

	printf("= = = = = = = = = =Status :: Successful\n\n");
	// Status :: Successful

}

// MAIN :: End
