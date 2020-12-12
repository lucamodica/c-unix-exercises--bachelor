#!/bin/bash
VAR=schi
VAR1=23
echo $VAR $VAR1
echo $0 $1

echo "il valore è $VAR"
echo `ls -l | grep schi`
echo `ls -l | grep $VAR`
echo '$VAR'
