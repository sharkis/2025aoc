#!/usr/bin/env bash

count=0
position=50
while read -r line; do
	# get first letter
	dir=${line:0:1}
	# get number
	delta=$(echo $line | tr -d -c 0-9)
	delta=$((delta + 0))
	echo $dir $delta
	# modulate position
	if [ $dir == "L" ]; then
		position=$((position - delta))
	else
		position=$((position + delta))
	fi
	# wrap if necessary
	while [ $position -gt 99 ]; do
		position=$((position-100))
	done
	while [ $position -lt 0 ]; do
		position=$((position+100))
	done
	if [ $position -eq 0 ]; then
		((count++))
	fi
	echo $position
	
done < input.txt
echo "count: " $count;
