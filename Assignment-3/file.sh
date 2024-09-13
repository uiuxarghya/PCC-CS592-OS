#!/bin/bash
while [ 1 ]
  echo "MENU:"
  echo "1.show permissions of a file or directory , 2.number of files and directories under current directory , 3.show last modification time of a file , 4.exit"
do
  read -p "Enter your choice: " choice
  case $choice in
  1)
    read -p "Enter the filename: " filename
    if [ -e $filename ]; then
      permissions=$(ls -l | grep "$filename" | cut -c2-10)
      echo "The permissions granted to the $filename are $permissions "
    else
      echo "$filename doesnot exist under the current directory."
    fi
    ;;
  2)
    files=$(ls -l | grep "^-" | wc -l)
    directory=$(ls -l | grep "^d" | wc -l)
    echo "The files existing under current directory are: $files"
    echo "The directiories existing under current directory are: $directory"
    ;;
  3)
    read -p "Enter the filename: " filename
    if [ -e $filename ]; then
      modify=$(ls -l | grep "$filename" | tr -s " " | cut -d" " -f8)
      echo "The last modification time of $filename in current directory is $modify"
    else
      echo "$filename doesnot exist under current directory."
    fi
    ;;
  4)
    echo "Program exited"
    exit
    ;;
  *)
    echo "Invalid choice"
    ;;
  esac
done