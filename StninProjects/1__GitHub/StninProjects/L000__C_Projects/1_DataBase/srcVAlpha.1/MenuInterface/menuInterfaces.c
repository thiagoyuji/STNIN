// INCLUDE::start

#include "menuInterfaces.h"

// INCLUDE::end

// IMPLEMENTATION::start

void showStringFirstAccess(   ){

	printf ("[][ BasicDB ] ~ [][ * ] # ");

}

void showStringUserAccess( char * userName, char * codeAccess ){

	printf ("[ %s ][ BasicDB ] ~ [ %s ][ AccessingDB ] # ",userName, codeAccess);

}

void showInfoGetString( char * string ){

	printf ("[][ BasicDB ] ~ [][ Insert %s ] # ", string);

}

void showLoadingInstall(   ){

	printf ("Database Installing ... [ 0% == 25% == 50% == 75% == 100% ]\n");

}

void showLoadingUninstall(   ){

	printf ("Database Uninstalling ... [ 0% == 25% == 50% == 75% == 100% ]\n");

}

void showLoadingVerification(   ){

	printf ("\nDatabase Verificating ... [ 0% == 25% == 50% == 75% == 100% ]\n");

}


// IMPLEMENTATION::end
