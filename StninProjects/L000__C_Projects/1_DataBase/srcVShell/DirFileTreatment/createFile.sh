#!/bin/bash

FILE_NAME=$1

if [ ! -e "$FILE_NAME" ]; then

    touch $FILE_NAME
    
    chmod 644 $FILE_NAME
    
    echo "Information: File $FILE_NAME Created -- Status: Success"

fi
 
