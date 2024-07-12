#!/bin/bash

# Initialize max_ops to a very small number
max_ops=-1
numbers=""

# Run the command and process its output line by line
./test_swap perm 9 | grep --line-buffered "Ops:\|Sorting:" | \
awk '{
    # Check if the line contains the list of numbers
    if ($1 == "Sorting:") {
        numbers = substr($0, 10);  # Store the list of numbers
    }
    # Extract the Ops value
    if ($1 == "Ops:") {
        ops_value = $2;
        # Update max_ops if current ops_value is greater
        if (ops_value > max_ops) {
            max_ops = ops_value;
            # Print the current max_ops and the corresponding numbers
            print "The current maximum Ops value is:", max_ops;
            print "Numbers being sorted:", numbers;
        }
    }
}'

