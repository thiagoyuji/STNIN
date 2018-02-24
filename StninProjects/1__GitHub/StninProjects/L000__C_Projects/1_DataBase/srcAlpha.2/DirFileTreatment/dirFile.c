// << Directory and File Treatment :: Implementation >>
// << Author :: STNIN >>

// << Implementation :: Start >>

// INCLUDES :: Start

#include "dirFile.h"

// INCLUDES :: End

// Struct Namespace :: start

const struct NewFunction DirFile = { 
    
    CreateDirectory, 
    CreateFile, 
    
    DeleteDirectory,
    DeleteFile,
    
    VerificationDirectory,
    VerificationFile
        
};


// Struct Namespace :: End


void CreateDirectory( String directoryName ){
    
    int newDir = mkdir( directoryName, S_IRWXU );
    
    if( !newDir )    printf ("ERRRRRRROOOOOOORRRR");
    
    printf ("%s1\n\n", directoryName );
    
}

void CreateFile( String fileName ){
    
    printf ("%s2\n\n", fileName );
    
}


void DeleteDirectory( String directoryName ){
    
    printf ("%s3\n\n", directoryName );
    
}

void DeleteFile( String fileName ){
    
    printf ("%s4\n\n", fileName );
    
}


enum Boolean VerificationDirectory( String directoryName ){
    
    enum Boolean verification = TRUE;

    DIR * DBdir = opendir( directoryName );

    if( !DBdir )    verification = FALSE;

    closedir( DBdir );

    printf ("%s5 - %d\n\n", directoryName, verification );

    return verification;
    
}

enum Boolean VerificationFile( String fileName ){
    
    printf ("%s6\n\n", fileName );
    
}

// << Implementation :: End >>
