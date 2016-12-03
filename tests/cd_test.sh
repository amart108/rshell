#!/bin/sh

echo "Starting cd tests: "
cd ..
make
cd tests
../bin/rshell < cd.txt
cd ..
make clean
cd tests
echo "Finished"

