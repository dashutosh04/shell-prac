#!/bin/bash

# Write a script to sort a given numbers in ascending or descending order.

echo "Enter the number of elements: "
read n

echo "Enter the elements: "
for ((i = 0; i < n; i++)); do
    read arr[$i]
done

echo "Enter 1 for ascending order or 2 for descending order: "
read choice

if [[ $choice -eq 1 ]]; then
    for ((i = 0; i < n; i++)); do
        for ((j = 0; j < n - i - 1; j++)); do
            if [[ ${arr[$j]} -gt ${arr[$((j + 1))]} ]]; then
                temp=${arr[$j]}
                arr[$j]=${arr[$((j + 1))]}
                arr[$((j + 1))]=$temp
            fi
        done
    done
else
    for ((i = 0; i < n; i++)); do
        for ((j = 0; j < n - i - 1; j++)); do
            if [[ ${arr[$j]} -lt ${arr[$((j + 1))]} ]]; then
                temp=${arr[$j]}
                arr[$j]=${arr[$((j + 1))]}
                arr[$((j + 1))]=$temp
            fi
        done
    done
fi

echo "Sorted array: "
for ((i = 0; i < n; i++)); do
    echo ${arr[$i]}
done
