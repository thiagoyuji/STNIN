// INCLUDES :: Start

#include "Row.h"

// INCLUDES :: End

// IMPLEMENTATION :: Start

void newRow( struct Row * row_ ){

	row_->init_ = SINAL;

	row_->final_ = SINAL;

}// Create Row--------

Integer maxSizeRow( ){

	Integer max = MAX_SIZE - 1;

	return max;

}// Return max size of Row------------

Integer accessInit( struct Row row_ ){

	Integer init = row_.init_;
	Integer initValue;

	initValue = row_.Row_r[ init ];

	return initValue;

}// Access Init of Row-----------------------

void push( struct Row * row_, Integer Item ){

	Integer nextFinal = ( row_->final_ + 1 ) % MAX_SIZE;
	Integer init = row_->init_;

	if( nextFinal != init ){

		row_->Row_r[ nextFinal ] = Item;
		row_->final_ = nextFinal;

		if( init == SINAL ) row_->init_ = nextFinal;

	}
	

}// Enter in Row--------------

void pop( struct Row * row_ ){

	Integer init = row_->init_;
	Integer final = row_->final_;

	if( init != SINAL ){

		if( init == final ){

			row_->init_ = SINAL;
			row_->final_ = SINAL;

		}else{

			row_->init_ = ( init + 1 ) % MAX_SIZE;

		}

	}

}// Get out Row--------------------

void emptyRow( struct Row * row_ ){

	row_->init_ = SINAL;

	row_->final_ = SINAL;

}// Clean Row--------------------

void showInit( struct Row row_ ){

	Integer Init = row_.init_;

	printf("Init Row :: %d\n\n", row_.Row_r[ Init ]);

}// Print in video Init of Row

// IMPLEMENTATION :: End
