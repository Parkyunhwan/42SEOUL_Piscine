#!/bin/bash
F1=$FT_LINE1
F2=$FT_LINE2
cat /etc/passwd | grep -v '#' | sed -n '2,$p' | awk 'NR%2' |awk -F ':' '{print $1}' | rev | sort -r | sed -n "${F1},${F2}p" | tr '\n' ',' | sed 's/,/, /g' | sed 's/, $/./' | tr -d '\n'
