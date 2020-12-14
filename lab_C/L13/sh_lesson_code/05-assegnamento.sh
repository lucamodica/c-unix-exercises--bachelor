#!/bin/bash

tmp=`ls -la | wc -l`
tmp1=`ls -l | wc -l`

echo "numero di elementi nella directory: "$tmp
echo "di questi, non hidden: " $tmp1

let "diff=$tmp-$tmp1"
echo "hidden: " $diff

