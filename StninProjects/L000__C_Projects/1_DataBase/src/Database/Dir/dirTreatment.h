#ifndef DIR_TREATMENT_H_INCLUDED
#define DIR_TREATMENT_H_INCLUDED

// INCLUDES :: Start

#include <sys/types.h>
#include <sys/stat.h>

#include "../Npdb_Db_Types.h"

// INCLUDES :: End

// STRUCTS, ENUMS :: Start

struct Directory{
    
    C_Dir NewDir;
    
    R_Dir RemDir;
    
};

extern const struct Directory Dir;

// STRUCTS, ENUMS :: End

// INTERFACES :: Start

void createDirectory( String directoryName );
void removeDirectory( String directoryName );

// INTERFACES :: End

#endif
