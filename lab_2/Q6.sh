#!/bin/bash

# 6.  WAP to convert temp  in Celsius into Fahrenheit. #

echo "Enter temperature in Celsius "
read temp_c

Fahrenheit=$(($temp_c*9/5 + 32))

echo "Temperature in Fahrenheit is ${Fahrenheit}"