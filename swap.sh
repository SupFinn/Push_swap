#!/bin/bash

# ANSI color codes
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\e[0;33m'
RESET='\033[0m'

# Make sure push_swap is compiled
if [ ! -f "./push_swap" ]; then
    echo -e "${RED}Error: push_swap executable not found!${RESET}"
    exit 1
fi

# Make sure checker_linux is present
if [ ! -f "./checker_linux" ]; then
    echo -e "${RED}Error: checker_linux executable not found!${RESET}"
    exit 1
fi

# Test 10 times
for i in {1..100}
do
    # Generate 100 random numbers between 1 and 1000
    ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' ')

    # Run push_swap and store output
    PS_OUTPUT=$(./push_swap $ARG)
    
    # Count lines (operations)
    OPS=$(echo "$PS_OUTPUT" | wc -l)

    # Check with checker_linux
    CHECK_RESULT=$(echo "$PS_OUTPUT" | ./checker_linux $ARG)

    # Determine colors
    if [ "$CHECK_RESULT" == "OK" ]; then
        RESULT_COLOR=$GREEN
    else
        RESULT_COLOR=$RED
    fi

    if [ "$OPS" -ge 700 ]; then
        OPS_COLOR=$RED
    else
        OPS_COLOR=$GREEN
    fi

    # Print colored result
    echo -e "${RESULT_COLOR}${CHECK_RESULT}${RESET} ${OPS_COLOR}${OPS}${RESET}"
done
