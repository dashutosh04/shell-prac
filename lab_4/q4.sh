#!/bin/bash

# Write a script to read 'n' and generate Fibonnaci number less than or equal to n

echo "Enter a number: "
read n

a=0
b=1

echo "Fibonacci series less than or equal to $n: "

while [ $a -le $n ]; do
    echo "$a"
    c=$(($a + $b))
    a=$b
    b=$c
done
