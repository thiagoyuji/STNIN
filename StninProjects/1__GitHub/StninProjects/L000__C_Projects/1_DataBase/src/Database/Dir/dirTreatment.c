// INCLUDES :: Start

#include "dirTreatment.h"

// INCLUDES :: End

// STRUCTS, ENUMS :: Start

const struct Directory Dir = {
    
    createDirectory,
    removeDirectory
    
};

extern const struct Directory Dir;

// STRUCTS, ENUMS :: End

// IMPLEMENTATION :: Start

void createDirectory( String directoryName ){
    
    printf("CREATE DIRECTORY %s\n\n", directoryName);
    
}

void removeDirectory( String directoryName ){
    
    printf("REMOVE DIRECTORY %s \n\n", directoryName);
    
}

// IMPLEMENTATION :: End 
