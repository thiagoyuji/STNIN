#!/bin/bash

CREATE_DIR_SH=src/DirFileTreatment/createDir.sh
CREATE_FILE_SH=src/DirFileTreatment/createFile.sh

REMOVE_DIR_SH=src/DirFileTreatment/removeDirFile.sh

chmod 777 $CREATE_DIR_SH
chmod 777 $CREATE_FILE_SH

chmod 777 $REMOVE_DIR_SH



DIR_NPDB=~/Npdb
DIR_NPDB_DATABASES=~/Npdb/Databases
DIR_NPDB_BACKUP=~/Npdb/Backup

echo "Information: Checking System -- Status: Checking ... "

sleep 2

if [ ! -d "$DIR_NPDB" ]; then

    echo "Information: Installing -- Status: Installing ..."

    sleep 2
    
    src/DirFileTreatment/./createDir.sh $DIR_NPDB
    
    src/DirFileTreatment/./createDir.sh $DIR_NPDB_DATABASES
    
    src/DirFileTreatment/./createDir.sh $DIR_NPDB_BACKUP
    
    # if root give all permission else do not (thinking maybe give access with password).
    
    echo "Information: Npdb Installed -- Status: Success"

fi

src/DirFileTreatment/./removeDirFile.sh $DIR_NPDB

cd Build/
    make
    
    #clear 
    
    ./database
    
