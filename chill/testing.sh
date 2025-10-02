#!/bin/bash
#
# testing.sh     Jay Mason     October 2, 2025
#
# This script runs a sequence of test cases for chill.c.
# It demonstrates correctness for valid input, as well as
# appropriate error handling for invalid input cases.
#
# Usage:
#   bash -v testing.sh >& testing.out

# zero arguments
./chill

# one argument
./chill 32

# two arguments
./chill 32.5 10

# temperature out of range
./chill 55

# wind speed out of range
./chill 10 0

# usage with too many args
./chill 10 5 7
