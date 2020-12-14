#!/bin/bash

for i in `ipcs -s | grep schi | awk '{print $2}'`; do
	ipcrm -s $i; 
done

