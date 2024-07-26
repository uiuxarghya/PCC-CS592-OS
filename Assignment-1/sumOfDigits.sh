#!/bin/bash

read -p "Enter a number: " num

if ! [[ $num =~ ^[0-9]+$ ]]; then
  echo "Error: Invalid input. Please enter a positive integer."
else
  sum=0
  while [ $num -gt 0 ]; do
    digit=$((num % 10))
    sum=$((sum + digit))
    num=$((num / 10))
  done
  echo "The sum of digits is: $sum"
fi
