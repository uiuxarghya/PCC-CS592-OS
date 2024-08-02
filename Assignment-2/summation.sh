#!/bin/bash

if [ $# -eq 0 ]; then
	echo "Usage: $0 num1 num2 num3 ... numN"
	exit 1
fi

sum=0

for num in $@; do
	sum=$((sum + num))
done

echo "The summation of the given natural numbers is : $sum"
