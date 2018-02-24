#ifndef THREADED_LIST_H_INCLUDED
#define THREADED_LIST_H_INCLUDED

// This Threaded List is not commum, this list has a HEAD.
// when you insert some Item the HEAD of List add 1 in size saving the size of list
// and (Node * init) has reference the first Node( but he isn't the First)

// INCLUDES, DEFINES :: Start

#include <stdio.h>
#include <stdlib.h>

#define ZERO 0

#define GHOST -999

// INCLUDES, DEFINES :: End

// TYPEDEFS, STRUCTS, ENUMS :: Start

typedef int Integer;

struct Node{

	struct Node * next;

	struct Node * previous;

	Integer Item;

};

struct List{

	struct Node * init;

	size_t size;

};

enum Boolean{ FALSE, TRUE };

// TYPEDEFS, STRUCTS, ENUMS :: End

// INTERFACES :: Start

void newList( struct List * );				// Create List

void emptyList( struct List * );			// Clean List

Integer getSize( struct List );				// Get List Size

enum Boolean checkEmptyList( struct List );		// Check if List is Empty

Integer searchItem( struct List, Integer );		// Search Item and return position

void insertInit( struct List *, Integer );		// Insert in the init of list
void insertFinal( struct List *, Integer );		// Insert in final of List
void insertLocal( struct List *, Integer, Integer );	// Insert in local of list

void removeInit( struct List * );			// Remove in init of list
void removeFinal( struct List * );			// Remove in final of list
void removeLocal( struct List *, Integer );		// Remove in local of List

void showList( struct List );				// Print List int Video

// INTEFACESS :: End

#endif
