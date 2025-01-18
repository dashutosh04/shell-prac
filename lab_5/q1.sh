#!/bin/bash

# Write a shell script to merge two sorted arrays into a sorted one.

echo "Size of array 1: "
read n1
echo "Elements of array 1: "

for ((i = 0; i < n1; i++)); do
    read arr1[$i]
done

echo "Size of array 2: "
read n2
echo "Elements of array 2: "

for ((i = 0; i < n2; i++)); do
    read arr2[$i]
done

i=0
j=0
k=0

while [ $i -lt $n1 -a $j -lt $n2 ]; do
    if [ ${arr1[$i]} -lt ${arr2[$j]} ]; then
        arr3[$k]=${arr1[$i]}
        i=$((i + 1))
    else
        arr3[$k]=${arr2[$j]}
        j=$((j + 1))
    fi
    k=$((k + 1))
done

while [ $i -lt $n1 ]; do
    arr3[$k]=${arr1[$i]}
    i=$((i + 1))
    k=$((k + 1))
done

while [ $j -lt $n2 ]; do
    arr3[$k]=${arr2[$j]}
    j=$((j + 1))
    k=$((k + 1))
done

echo "The merged array is: "
for ((i = 0; i < n1 + n2; i++)); do
    echo ${arr3[$i]}
done
