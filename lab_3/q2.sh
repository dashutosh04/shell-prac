#!/bin/bash

# Write a shell program to find if a year is leap year or not.#

echo "Enter the year your want to check ."
read year

if [ $((year % 4)) == 0 ]; then
    if [ $((year % 100)) == 0 ]; then
        if [ $((year % 400)) == 0 ]; then
            echo "Leap Year"
        else
            echo "Not a Leap Year"
        fi
    else
        echo "Leap Year"
    fi
else
    echo "Not a Leap Year"
fi
