#!/bin/bash

# Write a script for arithemetic calculator using command line arguments.

op=$1
num1=$2
num2=$3

if [ "$op" == "add" ]; then
    echo "Result: $(($num1 + $num2))"
elif [ "$op" == "subtract" ]; then
    echo "Result: $(($num1 - $num2))"
elif [ "$op" == "multiply" ]; then
    echo "Result: $(($num1 * $num2))"
elif [ "$op" == "divide" ]; then
    if [ "$num2" -eq 0 ]; then
        echo "Error: Division by zero is not allowed."
    else
        echo "Result: $(($num1 / $num2))"
    fi
else
    echo "Error: Unsupported op. Use 'add', 'subtract', 'multiply', or 'divide'."
fi
