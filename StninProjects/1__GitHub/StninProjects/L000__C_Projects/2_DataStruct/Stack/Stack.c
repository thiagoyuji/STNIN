// INCLUDES :: Start

#include "Stack.h"

// INCLUDES :: End

// IMPLEMENTATION :: Start

void newStack( struct Stack * stack_ ){

	stack_->topper = SINAL;

}// Create new Stack---------------------

void emptyStack( struct Stack * stack_ ){

	stack_->topper = SINAL;

	stack_->Stack_s[ SINAL + 1 ] = ZERO;

}// Clean Stack-------------

Integer getMaxSizeStack(  ){

	return ( MAX_SIZE - 1 );

}// Get Max Size of Stack-------------------

Integer accessTopper( struct Stack stack_ ){

	Integer topperTemp = stack_.topper;
	Integer ItemTopper = GHOST;

	if( topperTemp > SINAL ){

		ItemTopper = stack_.Stack_s[ topperTemp ];

	}

	return ItemTopper;

}// Get topper value-----------------------------

void push( struct Stack * stack_, Integer Item ){

	Integer topperTemp = stack_->topper + 1;

	if( topperTemp < ( MAX_SIZE - 1 ) ){

		stack_->Stack_s[ topperTemp ] = Item;
		stack_->topper = topperTemp;

	}

}// Insert in stack---------------

void pop( struct Stack * stack_ ){

	Integer topperTemp = stack_->topper;

	if( topperTemp > SINAL ){

		stack_->topper = topperTemp - 1;

	}

}// Remove of Stack--------------------

void showTopper( struct Stack stack_ ){

	Integer positionTopper = stack_.topper;

	printf("Position Topper :: %d\n",positionTopper);

	Integer topper = stack_.Stack_s[ positionTopper ];

	printf("Topper :: %d\n\n", topper);

}// Print in Video topper

// IMPLEMENTATION :: End
