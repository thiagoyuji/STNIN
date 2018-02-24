#!/bin/bash

DIR_NAME=$1

if [ ! -d "$DIR_NAME" ]; then

    mkdir -p $DIR_NAME

    chmod 755 $DIR_NAME

    echo "Information: Directory Created -- Status: Success"

else

    echo "Information: Directory Exist -- Status: Error"

fi
