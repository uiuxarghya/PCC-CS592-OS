#!/bin/bash

read -p "Enter the length: " len
if [ $len -lt 1 ]; then
	echo "Length should atleast be 1"
else
	declare -A arr
	for ((i = 0; i < len; i++)); do
		read arr[$i]
	done

	echo -n "Unsorted array: "
	for ((i = 0; i < len; i++)); do
		echo -n "${arr[$i]} "
	done
	echo ''

	for ((i = 0; i < len; i++)); do
		for ((j = i + 1; j < len; j++)); do
			if [[ ${arr[$j]} -lt ${arr[$i]} ]]; then
				t=${arr[$i]}
				arr[$i]=${arr[$j]}
				arr[$j]=$t
			fi
		done
	done

	echo -n "Sorted array: "
	for ((i = 0; i < len; i++)); do
		echo -n "${arr[$i]} "
	done
	echo ''
fi
