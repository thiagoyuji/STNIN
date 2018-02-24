// INCLUDES :: Start

#include "Stack.h"

// INCLUDES :: End

// MAIN :: Start

void main(  ){

	struct Stack stack_;

	// Testing NewStack ...
	printf("= = = = = = = = = =Testing NewStack\n\n");

		newStack( &stack_ );
		showTopper( stack_ );

	printf("= = = = = = = = = =Status :: Successful\n\n");
	// Status :: Successful

	// Testing GetMaxSizeStack ...
	printf("= = = = = = = = = =Testing GetMaxSizeStack\n\n");

		Integer maxSize = getMaxSizeStack(  );
		printf("Max Size :: %d\n\n", maxSize);

	printf("= = = = = = = = = =Status :: Successful\n\n");
	// Status :: Successful

	// Testing Push ...
	printf("= = = = = = = = = =Testing Push\n\n");

		push( &stack_, 1 );
		showTopper( stack_ );

		push( &stack_, 2 );
		showTopper( stack_ );

		push( &stack_, 3 );
		showTopper( stack_ );

		push( &stack_, 4 );
		showTopper( stack_ );

	printf("= = = = = = = = = =Status :: Successful\n\n");
	// Status :: Successful

	// Testing AccessTopper ...
	printf("= = = = = = = = = =Testing AccessTopper\n\n");

		Integer ItemTopper = accessTopper( stack_ );
		printf("Topper :: %d\n\n", ItemTopper);

	printf("= = = = = = = = = =Status :: Successful\n\n");
	// Status :: Successful

	// Testing Pop ...
	printf("= = = = = = = = = =Testing Pop and emptyStack\n\n");

		pop( &stack_ );
		showTopper( stack_ );

		pop( &stack_ );
		showTopper( stack_ );

		emptyStack( &stack_ );
		showTopper( stack_ );

	printf("= = = = = = = = = =Status :: Successful\n\n");
	// Status :: Successful

}

// MAIN :: End
