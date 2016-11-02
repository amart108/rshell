#!/bin/sh

echo "Single command test cases: "
cd ..
make
cd tests
../bin/rshell < single.txt
cd ..
make clean
cd tests
echo "Finished singe command test cases."
