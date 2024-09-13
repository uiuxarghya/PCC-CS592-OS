#!/bin/bash

read -p "Enter the length: " len
if [ $len -lt 1 ]; then
	echo "Length should be at least 1"
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

	# Selection sort implementation
	for ((i = 0; i < len - 1; i++)); do
		minIndex=$i
		for ((j = i + 1; j < len; j++)); do
			if [[ ${arr[$j]} -lt ${arr[$minIndex]} ]]; then
				minIndex=$j
			fi
		done
		# Swap the found minimum element with the first element
		if [[ $minIndex -ne $i ]]; then
			temp=${arr[$i]}
			arr[$i]=${arr[$minIndex]}
			arr[$minIndex]=$temp
		fi
	done

	echo -n "Sorted array: "
	for ((i = 0; i < len; i++)); do
		echo -n "${arr[$i]} "
	done
	echo ''
fi
