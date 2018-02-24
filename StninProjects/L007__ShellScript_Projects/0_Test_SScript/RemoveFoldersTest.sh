#!/bin/bash

DIR_NAME=$1

if [ ! -d "$DIR_NAME" ]; then

    echo "Information: Directory dont Exist -- Status: Error"

else

    rm -rf $DIR_NAME

    echo "Information: Directory Removed -- Status: Success"

fi
