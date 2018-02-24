#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

// INCLUDES::start

#include "../StringTreatment/string.h"
#include "../Syscall/syscall.h"

// INCLUDES::end

// DEFINES::start

#define COMMAND_CREATE_DIR "../src/DirFileTreatment/./createDir.sh "
#define COMMAND_CREATE_FILE "../src/DirFileTreatment/./createFile.sh "

#define COMMAND_REMOVE_DIR "../src/DirFileTreatment/./removeDirFile.sh "

// DEFINES::end

// INTERFACES::start

void createNewDirectory( String );
void createNewFile( String );

void removeDirectory( String );

// INTERFACES::end

#endif
