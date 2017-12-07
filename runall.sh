#!/usr/bin/env bash

for file in ./build/day*
do
    echo "Run: `basename $file`"
    $file/`basename $file`
done
