#!/usr/bin/env bash

./travis.sh

for file in ./build/day*
do
    echo "Run: `basename $file`"
    $file/`basename $file`
done
