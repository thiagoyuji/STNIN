// << Main :: Implementation >>
// << Author :: STNIN >>

// << Implementation :: Start >>

// Includes :: Start

#include "NpdbTypes.h"
#include "DirFileTreatment/dirFile.h"

// Includes :: End

// MAIN :: START

void main(  ){
        
    DirFile.NewDirectory( CONST_DIRECTORY_DATABASE );
    DirFile.NewFile( "COMO" );
    DirFile.RemoveDirectory( "VAI" );
    DirFile.RemoveFile( "VOCE" );
    DirFile.CheckDirectory( CONST_DIRECTORY_DATABASE );
    DirFile.CheckFile( "DNOVO" );
    
    mkdir( "~/ola", S_IRUSR | S_IWUSR | S_IXUSR );
    getchar();
    system( "rm -rf /tmp/ola" );
    
}

// MAIN :: END

// << Implementation :: End >> 
