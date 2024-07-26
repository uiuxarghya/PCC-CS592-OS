#!/bin/bash

factorial() {
  local num=$1
  local result=1
  for ((i = 1; i <= $num; i++)); do
    result=$((result * i))
  done
  echo $result
}

read -p "Enter a number: " num

if [ $num -lt 0 ]; then
  echo "Error: Factorial is not defined for negative numbers."
else
  result=$(factorial $num)
  echo "The factorial of $num is: $result"
fi
