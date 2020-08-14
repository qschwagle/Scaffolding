
# create test_directory
mkdir test_directory

# move to test_directory
cd test_directory

# generate document
../../build/scaffold hello.cpp

# check document
diff ../test-1-expected hello.cpp

# move up
cd ..

# delete directory
rm -r test_directory


