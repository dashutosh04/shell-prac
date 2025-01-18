#!/bin/bash

# Write a script to sort given numbers in ascending or descending order using builtin sort.

echo "Enter the number of elements: "
read n

echo "Enter the elements: "
for ((i = 0; i < n; i++)); do
    read arr[$i]
done

echo "Enter 1 for ascending order or 2 for descending order: "
read choice

if [ $choice -eq 1 ]; then
    sorted_arr=($(printf "%s\n" "${arr[@]}" | sort -n))
else
    sorted_arr=($(printf "%s\n" "${arr[@]}" | sort -nr))
fi

echo "Sorted array: ${sorted_arr[@]}"
