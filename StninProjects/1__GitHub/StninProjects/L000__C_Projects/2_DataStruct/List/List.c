/*

	Implementation of ArrayList ( List.c -> Functions ) in C, Objective :: Learn Data Struct

*/

// INCLUDES :: Start

#include "List.h"

// INCLUDES :: End

// IMPLEMENTATION :: Start

void newList( struct List * list_ ){

	Integer count;

	list_->Size = ZERO;

	for( count = 0; count <= MAX_SIZE; count++ ){
		list_->ArrayList[ count ] = ZERO;
	}

}// Create a empty list------------------------------------------

void newRandomList( struct List * list_, Integer A, Integer B ){

	Integer count;

	srand( ( unsigned ) time ( NULL ) );

	list_->Size = MAX_SIZE - 1;

	for( count = 1; count <= MAX_SIZE; count++ ){
		list_->ArrayList[ count ] = A + ( rand() % B );
	}

}// Create full random list-----------

void emptyList( struct List * list_ ){

	Integer count;

	list_->Size = ZERO;

}// Clean list----------

Integer maxSizeList(  ){

	return MAX_SIZE - 1;

}// Return Max size list-----------------------------------

Integer getItemList( struct List list_, Integer position ){

	Integer sizeTemp = list_.Size;
	Integer Item = GHOST;

	if( sizeTemp > ZERO ){
		if( ( position >= 1 ) && ( position <= sizeTemp ) ){
			
			Item = list_.ArrayList[ position ];

		} 
	}

	return Item;

}// Get item by Position--------------------------------

Integer seekItemList( struct List list_, Integer Item ){

	Integer sizeTemp = list_.Size;
	Integer position = ZERO;
	Integer count = 1;

	if( sizeTemp > ZERO ){
		
		while( ( count <= sizeTemp ) && ( list_.ArrayList[ count ] != Item ) ){
		
			count++;

		}

		if( list_.ArrayList[ count ] == Item ){
			position = count;
		}
	
	}

	return position;

}// Get position by Item ( First ocurrency ot item )

enum Boolean checkEmptyList( struct List list_ ){

	enum Boolean check = FALSE;

	if( list_.Size == ZERO ){

		check = TRUE;

	}

	return check;

}// Check if list is empty--------------------------

void insertInit( struct List * list_, Integer Item){

	Integer sizeTemp = list_->Size;
	Integer count;

	if( sizeTemp < ( MAX_SIZE - 1 ) ){

		for( count = sizeTemp; count >= 1; count-- ){

			list_->ArrayList[ count + 1 ] = list_->ArrayList[ count ]; 

		}

		list_->ArrayList[ INIT ] = Item;
		list_->Size = sizeTemp + 1;

	}

}// Insert in init of list----------------------------

void insertFinal( struct List * list_, Integer Item ){

	Integer sizeTemp = list_->Size;

	if( sizeTemp < ( MAX_SIZE - 1 ) ){

		list_->ArrayList[ sizeTemp + 1 ] = Item;
		list_->Size = sizeTemp + 1;

	}

}// Insert in the final of list-----------------------------------------

void insertLocal( struct List * list_, Integer position, Integer Item ){

	Integer sizeTemp = list_->Size;
	Integer count;

	if( sizeTemp < ( MAX_SIZE - 1 ) ){

		if( position >= 1 && position <= sizeTemp ){

			for( count = sizeTemp; count >= position; count-- ){

				list_->ArrayList[ count + 1 ] = list_->ArrayList[ count ];

			}

			list_->ArrayList[ position ] = Item;
			list_->Size = sizeTemp + 1;

		}

	}

}// Insert in local of list------------

void removeInit( struct List * list_ ){

	Integer sizeTemp = list_->Size;
	Integer count;

	if( sizeTemp > ZERO ){

		for( count = 1; count <= sizeTemp; count++ ){

			list_->ArrayList[ count ] = list_->ArrayList[ count + 1 ];

		}

		list_->Size = sizeTemp - 1;

	}

}// Remove in init of list--------------

void removeFinal( struct List * list_ ){

	Integer sizeTemp = list_->Size;

	if( sizeTemp > ZERO ){

		list_->Size = sizeTemp - 1;

	}

}// Remove in the final of list---------------------------

void removeLocal( struct List * list_, Integer position ){

	Integer sizeTemp = list_->Size;
	Integer count;

	if( position >= 1 && position <= sizeTemp ){

		for( count = position; count <= sizeTemp; count++ ){

			list_->ArrayList[ count ] = list_->ArrayList[ count + 1 ];

		}

		list_->Size = sizeTemp - 1;

	}

}// Remove in local of list

void swapItemsPositions( struct List * list_, Integer positionA, Integer positionB ){

	Integer sizeTemp = list_->Size;
	Integer temp;

	if( (positionA >= 1 && positionA <= sizeTemp) && (positionB >= 1 && positionB <= sizeTemp) ){

		temp = list_->ArrayList[ positionA ];
		list_->ArrayList[ positionA ] = list_->ArrayList[ positionB ];
		list_->ArrayList[ positionB ] = temp;

	}

}// Change items by position----------------------------------------

void showList( struct List list_ ){

	Integer count;
	Integer size_temp = list_.Size;

	printf("Size :: %d\n", size_temp);

	printf("List :: ");
	for( count = 1; count <= size_temp; count++ ){

		printf("| %d | ", list_.ArrayList[ count ]);

	}
	printf("\n\n");

}// Show List

// IMPLEMENTATION :: End
