#ifndef NEWDB_H_INCLUDED
#define NEWDB_H_INCLUDED

// INCLUDES::start

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// INCLUDES::end

// INTERFACES::start

void createDatabase(   );
void createUser( char ** dbName );
void openFilePutUser( char ** dbName );
void defineAccess(   );

// INTERFACES::end

#endif
