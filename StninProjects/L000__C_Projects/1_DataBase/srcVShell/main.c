// INCLUDES::start

#include "StringTreatment/string.h"
#include "DirFileTreatment/dirFile.h"

// INCLUDES::end

// MAIN::start

void main(){
    
    /*      First Test :: SUCCESSFULL
    
    char nome[100];
    char * nome2;
    
    getArrayString( nome );
    getDinamicString( &nome2 );
    
    printf ("%s", nome);
    printf ("%s", nome2);
    
    */
    
    /*      Second Test :: SUCCESSFULL
     
    char dir[30];
    char dir2[30] = "~/test2";
    
    getArrayString( dir );
    
    createNewDirectory( dir );
    createNewDirectory( dir2 );
    
    getchar();
    
    removeDirectory( dir );
    removeDirectory( dir2 );
    
    */
    
    /*      Thrird Test :: SUCCESSFULL
    
    char file[30];
    char file2[30] = "~/.test.txt";
    
    getArrayString( file );
    
    createNewFile( file );
    createNewFile( file2 );
    
    getchar();
    
    removeDirectory( file );
    removeDirectory( file2 );
    
    */
    
    printf ("\n\n>>> Start Database <<<\n\n");
    
}

// MAIN::end

// IMPLEMENTATION::start



// IMPLEMENTATION::end
