// INCLUDES::start

#include "installUninstall.h"
#include "../Boolean/bool.h"
#include "../MenuInterface/menuInterfaces.h"

// INCLUDES::end

// IMPLEMENTATION::start

void installDatabase(   ){

	system("mkdir ~/npdb");

	system("mkdir ~/npdb/Databases");

	system("mkdir ~/npdb/UsersProjects");

	showLoadingInstall(   );
	printf ("Information: Database Installed -- Status: Success\n\n");


}

enum Boolean verificateDatabaseInstallation(   ){

	enum Boolean verification = TRUE;

	DIR * DBdir = opendir("~/npdb");

	if( !DBdir )	verification = FALSE;

	closedir( DBdir );

	showLoadingVerification(   );
	printf ("Information: Database Verification Completed -- Status: Success\n\n");

	return verification;

}

void uninstallDatabase(   ){

	system("rm -rf ~/npdb");

	showLoadingUninstall(   );
	printf ("Information: Database Uninstalled -- Status: Success\n\n");


}

// IMPLEMENTATION::end
