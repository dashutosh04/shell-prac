#!/bin/bash

# Write a shell script to find the second largest and second smallest elements in an array.

echo "Enter the size of the array: "
read n
echo "Enter the elements of the array: "

for ((i = 0; i < n; i++)); do
    read arr[$i]
done

for ((i = 0; i < n; i++)); do
    for ((j = 0; j < n - i - 1; j++)); do
        if [ ${arr[$j]} -gt ${arr[$((j + 1))]} ]; then
            temp=${arr[$j]}
            arr[$j]=${arr[$((j + 1))]}
            arr[$((j + 1))]=$temp
        fi
    done
done

echo "The second largest element in the array is: ${arr[$((n - 2))]}"
echo "The second smallest element in the array is: ${arr[1]}"
