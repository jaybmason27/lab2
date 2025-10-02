#!/bin/bash
#
# testing.sh     Jay Mason     October 2, 2025
#
# This script runs a sequence of test cases for words.c.
# It demonstrates correctness for valid input sources,
# proper handling of stdin and multiple files, as well
# as error handling for invalid files.
#
# Usage:
#   bash -v testing.sh >& testing.out
#

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
