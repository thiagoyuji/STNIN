#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

// INCLUDES, DEFINES :: Start

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_FUNCTION(studentKey, hashKey) studentKey % hashKey

#define HASH_KEY 5

#define ZERO 0

#define GHOST -999

// INCLUDES, DEFINES :: End

// TYPEDEFS, STRUCTS, ENUMS :: Start

typedef int Integer;

struct Student{

    struct Student * next;

    Integer studentKey;
    char name[ 100 ];
    Integer age;

};

struct Hash{

    struct Student * registersInit;

    size_t size;

};

struct Hash HashTable[ HASH_KEY ];

// TYPEDEFS, STRUCTS, ENUMS :: End

// INTERFACES :: Start

void newHash(  );                  // Create Hash

void emptyHash(  );                // Clean Hash

struct Student searchRegister( Integer );      // Get Insformation of some Node 

void insertRegisterHash( struct Student * );       // Insert in Hash

void removeRegisterHash( Integer );       // Remove of Hash

void showHash(  );                   // Show full Data Hash

void showHashKey( Integer );       // Show Data Hash Key 

// INTERFACES :: End

#endif