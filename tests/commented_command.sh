#!/bin/sh

echo "Comment test case."
cd ..
make 
cd tests
../bin/rshell < comments.txt
cd ..
make clean
cd tests
echo "Finished Comment test cases."
