# test reading from stdin (echo pipe)
echo "Hello world" | ./words

# test reading from a file
echo "This is a test file." > test1.txt
./words test1.txt

# test reading multiple files
echo "Second file." > test2.txt
./words test1.txt test2.txt

# test using '-' to include stdin in sequence
echo "inline stdin" | ./words test1.txt - test2.txt

# test with empty file
touch empty.txt
./words empty.txt

# test with invalid file
./words nosuchfileexists.txt
