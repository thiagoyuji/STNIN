#ifndef ROW_H_INCLUDED
#define ROW_H_INCLUDED

// INCLUDES, DEFINES :: Start

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 11

#define SINAL -1

#define ZERO 0

// INCLUDES, DEFINES :: End

// TYPEDEFS, STRUCTS, ENUMS :: Start

typedef int Integer;

struct Row {

	Integer init_;

	Integer final_;

	Integer Row_r[ MAX_SIZE ];

};

// TYPEDEFS, STRUCTS, ENUMS :: End

// INTERFACES :: Start

void newRow( struct Row * );		// Create Row

Integer maxSizeRow( );			// Return max size of Row

Integer accessInit( struct Row );	// Access Init of Row

void push( struct Row *, Integer );	// Enter in Row

void pop( struct Row * );		// Get out Row

void emptyRow( struct Row * );		// Clean Row

void showInit( struct Row );		// Print in video Init of Row

// INTERFACES :: End

#endif
