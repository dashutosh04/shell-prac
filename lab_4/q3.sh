#!/bin/bash

# write a script to print a given number in reverse order.

echo "Enter a number: "
read number

reverse=0
while [ $number -gt 0 ]; do
    remainder=$(($number % 10))
    reverse=$(($reverse * 10 + $remainder))
    number=$(($number / 10))
done

echo "Reverse of the number is $reverse."
