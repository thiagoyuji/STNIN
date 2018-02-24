#ifndef MENUINTERFACES_H_INCLUDED
#define MENUINTERFACES_H_INCLUDED

// INCLUDES::start

#include <stdio.h>
#include <stdlib.h>

// INCLUDES::end

// INTERFACES::start

void showStringFirstAccess(   );

void showStringUserAccess( char * userName, char * codeAccess );

void showInfoGetString( char * string );

void showLoadingInstall(   );

void showLoadingUninstall(   );

void showLoadingVerification(   );

// INTERFACES::end

#endif
