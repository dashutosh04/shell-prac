#!/bin/bash

# Write a shell script to count the frequency of each element in an array.

echo "Enter the size of the array: "
read n
echo "Enter the elements of the array: "

for ((i = 0; i < n; i++)); do
    read arr[$i]
done

declare -a freq

for ((i = 0; i < n; i++)); do
    if [ -z ${freq[${arr[$i]}]} ]; then
        freq[${arr[$i]}]=1
    else
        freq[${arr[$i]}]=$((freq[${arr[$i]}] + 1))
    fi
done

echo "The frequency of each element in the array is: "

for key in "${!freq[@]}"; do
    echo "$key: ${freq[$key]}"
done
