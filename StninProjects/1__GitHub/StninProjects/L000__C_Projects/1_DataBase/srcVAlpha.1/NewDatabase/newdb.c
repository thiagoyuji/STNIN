// INCLUDES::start

#include "newdb.h"
#include "../MenuInterface/menuInterfaces.h"
#include "../Get/get.h"

// INCLUDES::end

// IMPLEMENTATION::start

void createDatabase(   ){

	char * directory = "mkdir ~/npdb/Databases/";
	char * dbName;

	showInfoGetString( "Database Name" );
	getString( &dbName );

	char * buffer = ( char * ) malloc ( strlen( directory ) + strlen( dbName ) + 1);

	strcpy( buffer, directory );
	strcat( buffer, dbName );

	system( buffer );

	free( buffer );

	createUser( &dbName  );
	openFilePutUser( &dbName );
//	defineAccess(   );

	free( dbName );

}

void createUser( char ** dbName ){

	char * directory = "touch ~/npdb/Databases/";
	char * file = "/.users.txt";

	char * buffer = ( char * ) malloc ( strlen( directory ) + strlen( (*dbName) ) + strlen( file ) );

	strcpy( buffer, directory );
	strcat( buffer, (*dbName) );
	strcat( buffer, file );

	system( buffer );

	free( buffer );

}

void openFilePutUser( char ** dbName  ){

	char * user;
        char * directory = "~/npdb/Databases/";
	char * file = "/.users.txt";

        char * buffer = ( char * ) malloc ( 50 );

        strcpy( buffer, directory );
        strcat( buffer, (*dbName) );
        strcat( buffer, file );

	printf ("%s %d", buffer, strlen(buffer));

        FILE * Users = fopen( buffer, "a+" );

                if (Users == NULL){
                        printf ("\nError Arquivo nao encontrado\n");
                        free(buffer);
			exit (-1);
                }

                showInfoGetString( "UserName" );
                getString( &user );

                fprintf (Users,"%s", user);

        fclose( Users );

        free( buffer );

        free( user );

}


void defineAccess(   ){

}

// IMPLEMENTATION::end
