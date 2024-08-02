#!/bin/bash

if [ -z "$1" ]; then
	echo "Usage: $0 <integer>"
	exit 1
fi

if ! [[ "$1" =~ ^[0-9]+$ ]]; then
	echo "Error: Argument must be a positive integer."
	exit 1
fi

n=$1

logN=$(echo "scale=2; l($n)/l(10)" | bc -l)

echo "The common logarithm value of $n is $logN."
