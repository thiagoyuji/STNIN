// << Directory and File Treatment :: Library >>
// << Author :: STNIN >>

// << Library :: Start >>

#ifndef DIRFILE_H_INCLUDED
#define DIRFILE_H_INCLUDED

// Includes :: Start

#include <dirent.h>
//#include <sys/dir.h>
#include <sys/types.h>
#include <sys/stat.h>
//#include <unistd.h>

#include "../NpdbTypes.h"

// Includes :: End

// Defines :: Start

#define CONST_DIRECTORY "~/"

#define CONST_DIRECTORY_DATABASE "~/Npdb"
#define CONST_DIRECTORY_STORAGE_DATABASES "~/Npdb/Databases"

#define CONST_FILE_USERS "~/Npdb/.allUsers.txt"

// Defines :: End

// Interfaces :: Start

void CreateDirectory( String );
void CreateFile( String );

void DeleteDirectory( String );
void DeleteFile( String );

enum Boolean VerificationDirectory( String );
enum Boolean VerificationFile( String );

// Interfaces :: End

// Structs :: Start

struct NewFunction {

        Directory NewDirectory;
        File NewFile;
        
        RmDirectory RemoveDirectory;
        RmFile RemoveFile;
        
        CkDirectory CheckDirectory;
        CkFile CheckFile;
    
};

extern const struct NewFunction DirFile;

// Structs :: End

#endif

// << Library :: End >>
