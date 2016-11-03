#!/bin/sh

echo "Starting comment tests:"
cd ..
make
cd tests
../bin/rshell < comments.txt
cd ..
make clean
cd tests
echo "done"

