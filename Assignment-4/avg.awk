#!/usr/bin/awk -f

BEGIN {
	FS="~"
	sum=0
	printf "Enter the subject number (1, 2, 3): "
	getline n < "-"
}

NR>1 {
	sum+=$(n+2)
}

END {
	avg=sum/5
	print "Average: "avg
}
