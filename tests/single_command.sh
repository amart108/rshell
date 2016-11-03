#!/bin/sh
echo "stating single commands"
cd ..
make
cd tests
../bin/rshell < single.txt
cd ..
make clean
cd tests
echo "done"
