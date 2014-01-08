#!/bin/sh
LL=""

while  read LL
do
	echo $LL
	echo $LL >> abc2
done
