#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

// INCLUDES, DEFINES :: Start

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 11
#define SINAL -1

#define ZERO 0

#define GHOST -2

// INCLUDES, DEFINES :: End

// TYPEDEFS, STRUCTS, ENUMS :: Start

typedef int Integer;

struct Stack{

	Integer topper;

	Integer Stack_s[ MAX_SIZE ];

};

enum Boolean{ FALSE, TRUE };

// TYPEDEFS, STRUCTS, ENUMS :: End

// INTERFACES :: Start

void newStack( struct Stack * );		// Create new Stack

void emptyStack( struct Stack * );		// Clean Stack

Integer getMaxSizeStack(  );			// Get Max Size of Stack

Integer accessTopper( struct Stack );		// Get topper value

void push( struct Stack *, Integer );		// Insert in stack

void pop( struct Stack * );		// Remove of Stack

void showTopper( struct Stack );		// Print in Video topper

// INTERFACES :: End

#endif
