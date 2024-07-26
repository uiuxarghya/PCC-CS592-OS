#!/bin/bash

read -p "Enter the number of terms: " n

if ! [[ $n =~ ^[1-9][0-9]*$ ]]; then
  echo "Error: Invalid input. Please enter a positive integer greater than 0."
else
  a=0
  b=1
  echo "Fibonacci series up to $n terms:"
  echo -n "$a "
  for ((i = 2; i <= $n; i++)); do
    echo -n "$b "
    temp=$((a + b))
    a=$b
    b=$temp
  done
fi
echo
