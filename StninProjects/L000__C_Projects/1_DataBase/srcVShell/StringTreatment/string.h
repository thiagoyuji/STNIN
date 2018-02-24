#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

// INCLUDES::start

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// INCLUDES::end

// TYPEDEF::start

typedef char * String;
typedef char ** RefString;

// TYPEDEF::end

// INTERFACES::start

void getArrayString( String );
void getDinamicString( RefString );

// INTERFACES::end

#endif
