#!/usr/bin/env bash

/bin/bash ./travis.sh

for file in ./build/day*
do
    echo "Run: `basename $file`"
    $file/`basename $file`
done
