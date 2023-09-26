#!/bin/bash
#6_4.sh
declare -i i=1;
while (true); do

	sleep 1;
	printf "$i\n";
	i=$(( $i+1 ));

	
done
