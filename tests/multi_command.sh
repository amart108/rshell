#!/bin/sh
echo "starting multi tests"
cd ..
make
cd tests
../bin/rshell < multi.txt
cd ..
make clean cd tests
echo "done"
