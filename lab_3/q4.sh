#!/bin/bash

# Check if a number is even or odd. #

echo "Enter a number to test. "
read number

if [ $((number % 2)) == 0 ]; then
    echo "$number is an even number."
    exit 0
else
    echo "$number is an odd number."
    exit 0
fi
