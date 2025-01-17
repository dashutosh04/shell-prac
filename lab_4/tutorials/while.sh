#!/bin/bash

n=1
while [ $n -lt 11 ]; do
    echo "$n"
    n=$(expr $n + 1)
done
