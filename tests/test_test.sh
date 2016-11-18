#!/bin/sh
echo "starting Testtests"
cd ..
make
cd tests
../bin/rshell < test.txt
cd ..
make clean cd tests
echo "done"
