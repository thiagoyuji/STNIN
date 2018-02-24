#ifndef GETSET_H_INCLUDED
#define GETSET_H_INCLUDED

// INCLUDES::start

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// INCLUDES::end

// INTERFACES::start

void getString( char ** string );

void getChar( char * caracter );

void getInt( int * integer );

void getFloat( float * real );

void getDouble( double * bigReal );

void getLongLongInt( long long int * integer );

// INTERFACES::end

#endif
