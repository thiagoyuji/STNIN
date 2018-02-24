/*

	Implementation of ArrayList ( List.h -> Library ) in C, Objective :: Learn Data Struct

*/

#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

// INCLUDES, DEFINES :: Start

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 11

#define ZERO 0
#define GHOST -999

#define INIT 1

// INCLUDES, DEFINES :: End

// STRUCTS, ENUMS, TYPEDEFS :: Start

typedef int Integer;

struct List{

	size_t Size;

	Integer ArrayList[ MAX_SIZE ];

};

enum Boolean{ FALSE, TRUE };

// STRUCTS, ENUMS, TYPEDEFS :: End

// INTERFACES :: Start

void newList( struct List * );					// Create a empty list
void newRandomList( struct List *, Integer, Integer );		// Create full random list

void emptyList( struct List * );				// Clean list

Integer maxSizeList(  );					// Return Max size list

Integer getItemList( struct List, Integer );			// Get item by Position

Integer seekItemList( struct List, Integer );			// Get position by Item ( First ocurrency ot item )

enum Boolean checkEmptyList( struct List );			// Check if list is empty

void insertInit( struct List *, Integer );			// Insert in init of list
void insertFinal( struct List *, Integer );			// Insert in the final of list
void insertLocal( struct List *, Integer, Integer );		// Insert in local of list

void removeInit( struct List * );				// Remove in init of list
void removeFinal( struct List* );				// Remove in the final of list
void removeLocal( struct List *, Integer );			// Remove in local of list

void swapItemsPositions( struct List *, Integer, Integer );	// Change items by position

void showList( struct List );					// Show list

// INTERFACES :: End

#endif
