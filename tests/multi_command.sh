#!/bin/sh

echo "Muli-command test cases: "
cd ..
make 
cd tests
../bin/rshell < multi.txt
cd ..
make clean
cd tests echo "Finishe multi-command test cases."
