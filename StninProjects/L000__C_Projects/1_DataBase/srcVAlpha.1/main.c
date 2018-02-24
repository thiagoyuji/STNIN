
/*
	This is the inictialization and execution code of database.

	author: STNIN

*/

// INCLUDES::start

#include "InstallUninstall/installUninstall.h"
#include "MenuInterface/menuInterfaces.h"
#include "Get/get.h"
#include "Syscall/syscall.h"
#include "Boolean/bool.h"
#include "NewDatabase/newdb.h"

// INCLUDES::end

// MAIN::start

void main (   ){

	uninstallDatabase(   );
	installDatabase(   );
	createDatabase(   );

}

// MAIN::end

//
//
