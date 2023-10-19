#!/bin/bash

# Function to run the Monty program with a specific test file
run_test() {
    printf "Test $1: "
    if ./monty "bytecodes/test$1.m" &> /dev/null; then
        echo "Passed"
    else
        echo "Failed"
    fi
}

# Run the Malloc Failure tests
for i in {1..5}
do
    echo "Test $i: Malloc Failure"
    # Redirect error output to a file
    ./monty "bytecodes/test${i}_malloc_failure.m" 2> malloc_failure_output.txt
    # Check if the error message contains "malloc failed"
    if grep -q "malloc failed" malloc_failure_output.txt; then
        echo "Test $i: Passed"
    else
        echo "Test $i: Failed"
    fi
    # Clean up the output file
    rm -f malloc_failure_output.txt
done
