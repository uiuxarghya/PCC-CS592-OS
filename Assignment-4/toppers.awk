#!/usr/bin/awk -f
BEGIN {FS="~"}

NR==1 {subj[1]=$3; subj[2]=$4; subj[3]=$5}

NR>1 {
    for(i=3; i<=5; i++) {
        if(scores[i] < $i) {
            scores[i]=$i
            names[i]=$2
        }
    }
}

END {
    printf "Top Scorers:\n"
    for(i=3; i<=5; i++) {
        printf "\t%s -> %s (%d)\n", subj[i-2], names[i], scores[i]
    }
}

