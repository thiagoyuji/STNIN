#ifndef INSTALL_H_INCLUDED
#define INSTALL_H_INCLUDED

// INCLUDES::start

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>

// INCLUDES::end

// INTERFACES::start

void installDatabase(   );
enum Boolean verificateDatabaseInstallation(   );
void showLoadingPorcent(   );
void uninstallDatabase(   );

// INTERFACES::end

#endif
