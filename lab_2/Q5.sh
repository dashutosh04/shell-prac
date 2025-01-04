#!/bin/bash

# 5. WAP to convert distance  in cm into  m , km #

echo "Enter the Distance in centimeters"
read dis_cm

dis_m=$(($dis_cm/100))
dis_km=$(($dis_m/1000))

echo "Distance in m = $dis_m"
echo "Distance in km = $dis_km"