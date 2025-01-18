#!/bin/bash

# Write a shell script to reverse an array.

echo "Enter the size of the array: "
read n
echo "Enter the elements of the array: "

for ((i = 0; i < n; i++)); do
    read arr[$i]
done

for ((i = 0; i < n / 2; i++)); do
    temp=${arr[$i]}
    arr[$i]=${arr[$((n - i - 1))]}
    arr[$((n - i - 1))]=$temp
done

echo "The reversed array is: "
for ((i = 0; i < n; i++)); do
    echo ${arr[$i]}
done
