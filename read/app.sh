#!/bin/sh
LL=""
echo $LL
while true
do
	read LL
	Length=${#LL}
	LL=$LL+" L="+$Length
	echo $LL
done
