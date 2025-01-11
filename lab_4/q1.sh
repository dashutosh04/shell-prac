#!/bin/bash

# Write a shell script  that implements a calculator with a menu-driven interface using a case statment
# Includes Addition ,Subtraction, Multiplication, Division, HCF and LCM

echo "Enter the first number: "
read num1

echo "Enter the second number :"
read num2

echo "Addition: $(($num1 + $num2))"
echo "Subtraction: $(($num1 - $num2))"
echo "Multiplication: $(($num1 * $num2))"

if [[ $num2 -eq 0 ]]; then
    echo "Division: Cannot divide by zero"
else
    echo "Division: $(($num1 / $num2))"
fi

hcf=1

for ((i = 1; i <= num1 && i <= num2; i++)); do
    if [[ $(($num1 % $i)) -eq 0 ]] && [[ $(($num2 % $i)) -eq 0 ]]; then
        hcf=$i
    fi
done

echo "HCF: $hcf"

lcm=$((($num1 * $num2) / $hcf))

echo "LCM: $lcm"
