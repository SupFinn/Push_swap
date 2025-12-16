#!/bin/bash

# Make sure push_swap is compiled
if [ ! -f "./push_swap" ]; then
    echo "Error: push_swap executable not found!"
    exit 1
fi

# Test 10 times
for i in {1..10}
do
    # Generate 100 random numbers between 1 and 1000
    ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' ')

    # Run push_swap and count lines (operations)
    OPS=$(./push_swap $ARG | wc -l)

    # Check if it exceeds 700
    if [ "$OPS" -gt 700 ]; then
        echo "$OPS --> Flex"
    else
        echo "$OPS"
    fi
done

