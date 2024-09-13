#!/bin/bash

while [ 1 ]
  echo "MENU"
  echo "1. Sort the records in reverse order"
  echo "2. Replace lower case letters with upper case letters"
  echo "3. Records with unique names"
  echo "4. Display 2nd and 3rd lines"
  echo "5. Exit"
  echo ""
do
  read -p "Enter your choice: " ch
  case $ch in
  1)
    sort -t '|' -k 2 -r Students.dat >> sorted.dat
    echo "File after sorting:"
    cat sorted.dat
    ;;
  2)
    tr [:lower:] [:upper:] < sorted.dat
    echo "File updated"
    ;;
  3)
    # Get unique first column values (sorted)
    list=$(cut -d'|' -f1 sorted.dat | sort | uniq)
    # Loop through each unique value
    while IFS= read -r i; do
      # Extract first occurrence of each unique value
      found=$(grep -w "^$i" sorted.dat | head -1)
      echo "$found"
    done <<<"$list"
    ;;
  4)
    cat Students.dat | head -n 3 | tail -n 2
    ;;
  5)
    exit
    ;;
  *)
    echo "\n Invalid key "
    ;;
  esac
done
