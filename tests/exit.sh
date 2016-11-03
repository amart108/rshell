echo "Exit test case."
cd ..
make 
cd tests
../bin/rshell < exit.txt
cd ..
make clean
cd tests
echo "Finished exit  test cases."
