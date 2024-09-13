#!/bin/bash

DATA_FILE="personal.dat"

while true; do
  echo "Menu:"
  echo "1. Enter your personal details"
  echo "2. Display your personal details"
  echo "3. Exit"
  read -p "Enter your choice: " choice

  case $choice in
  1)
    read -p "Enter your name: " name
    read -p "Enter your age: " age
    read -p "Enter your address: " address
    read -sp "Enter your password: " password
    echo ""
    echo -e "$name|$age|$address|$password" >"$DATA_FILE"
    echo "Personal details saved."
    ;;
  2)
    if [ -f "$DATA_FILE" ]; then
      read -sp "Enter your password: " input_password
      echo ""
      stored_password=$(cut -d '|' -f 4 "$DATA_FILE")
      if [ "$input_password" == "$stored_password" ]; then
        details=$(cat "$DATA_FILE" | cut -d '|' -f 1-3)
        IFS='|' read -r name age address <<<"$details"
        echo "Name: $name"
        echo "Age: $age"
        echo "Address: $address"
      else
        echo "Incorrect password."
      fi
    else
      echo "No data file found."
    fi
    ;;
  3)
    echo "Exiting..."
    exit 0
    ;;
  *)
    echo "Invalid choice. Please select a valid option."
    ;;
  esac
done
