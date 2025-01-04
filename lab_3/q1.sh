#!/bin/bash

#  Write a shell program to find greatest among three numbers #


echo "Enter first number. "
read a

echo "Enter second number. "
read b

echo "Enter third number. "
read c


if [ $a -gt $b ] && [ $a -gt $c ]; then
   echo "The greatest number is $a."
   exit 0
fi

if [ $b -gt $a ] && [ $b -gt $c ]; then
   echo "The greatest number is $b."
   exit 0
fi

echo "The greatest number is $c."

exit 0

