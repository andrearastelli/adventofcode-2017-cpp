#!/usr/bin/env bash
CXX=/usr/bin/g++-6
CC=/usr/bin/gcc-6

echo $CXX
echo $CC

mkdir build || true
cd build
cmake ..
