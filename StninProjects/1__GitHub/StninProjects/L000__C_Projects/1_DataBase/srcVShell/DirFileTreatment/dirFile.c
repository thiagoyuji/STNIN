// INCLUDES::start

#include "dirFile.h"

// INCLUDES::end

// IMPLEMENTATION::start

void createNewDirectory( String directory ){
    
    char dir[100];

    strcpy( dir, COMMAND_CREATE_DIR );
    strcat( dir, directory );
    
    treatmentDirectoryFile( dir );
        
}

void createNewFile( String file ){
    
    char tmpFile[100];

    strcpy( tmpFile, COMMAND_CREATE_FILE );
    strcat( tmpFile, file );
    
    treatmentDirectoryFile( tmpFile );
    
}

void removeDirectory( String directory ){
    
    char dir[100];
    
    strcpy( dir, COMMAND_REMOVE_DIR );
    strcat( dir, directory );
    
    treatmentDirectoryFile( dir );
        
}

// IMPLEMENTATION::end
