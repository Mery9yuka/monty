#!/bin/bash

# Test 1: Missing File Argument
echo "Test 1: Missing File Argument"
./monty

# Test 2: Unable to Open File
echo "Test 2: Unable to Open File"
./monty non_existent_file.m

# Test 3: Unknown Instruction
echo "Test 3: Unknown Instruction"
echo "foo" > unknown_instruction.m
./monty unknown_instruction.m

# Test 4: Invalid `push` Argument
echo "Test 4: Invalid push Argument"
echo "push abc" > invalid_push_arg.m
./monty invalid_push_arg.m

# Test 5: Malloc Failure (simulate by pushing a large number of items)
echo "Test 5: Malloc Failure"
for i in {1..100000}
do
    echo "push $i" >> malloc_failure.m
done
./monty malloc_failure.m

# Clean up test files
rm -f unknown_instruction.m invalid_push_arg.m malloc_failure.m
