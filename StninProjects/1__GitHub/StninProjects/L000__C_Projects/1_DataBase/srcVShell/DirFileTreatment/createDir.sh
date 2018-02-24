#!/bin/bash

DIR_NAME=$1

if [ ! -d "$DIR_NAME" ]; then

    mkdir -p $DIR_NAME
    
    chmod 755 $DIR_NAME
    
    echo "Information: Directory $DIR_NAME Created -- Status: Success"
    
fi
