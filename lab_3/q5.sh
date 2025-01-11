#!/bin/bash

# Write a shell program to take a character input and determine its type. #

echo "Enter a input character "
read c

case "$c" in
[a-z])
    echo "$c is a lowercase letter"
    ;;
[A-Z])
    echo "$c is an uppercase letter"
    ;;
[0-9])
    echo "$c is a digit"
    ;;
*['!&()'@#$%^*_+]*)
    echo "$c is a symbol"
    ;;
*)
    echo "$c is an unknown character type"
    ;;
esac
