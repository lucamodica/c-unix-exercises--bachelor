#!/bin/bash

let "ripeti = 1"
while [ $ripeti -lt 3 ]
do
	echo "hip hip"
	let "ripeti = $ripeti + 1"
done
echo "hurra!!"

