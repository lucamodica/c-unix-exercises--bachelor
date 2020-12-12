#!/bin/bash

DEFDIR=path_to_dir
if [ $1 ]
	then
	if [ $1 = "-d" ]
		then
		mia_var=`wc -l $2`
		echo $mia_var
	else 
		echo "opzione sconosciuta"
	fi
	else
		mia_var=`wc -l $DEFDIR`
		echo $mia_var
fi