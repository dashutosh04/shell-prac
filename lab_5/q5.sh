#!/bin/bash

# Write a shell script to check palindrome of array.

echo "Size of array : "
read n
echo "Enter elements : "

for ((i = 0; i < n; i++)); do
    read arr[$i]
done

flag=1

for ((i = 0; i < n / 2; i++)); do
    if [ ${arr[$i]} -ne ${arr[$((n - i - 1))]} ]; then
        flag=0
        break
    fi
done

if [ $flag -eq 1 ]; then
    echo "Palindrome."
else
    echo "Not a palindrome."
fi
