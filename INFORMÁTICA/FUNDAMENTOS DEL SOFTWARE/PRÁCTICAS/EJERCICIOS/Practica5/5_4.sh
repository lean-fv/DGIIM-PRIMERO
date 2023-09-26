#!/bin/bash

#5_4.sh

meses=(Jan Feb Mar Apr Jun Jul Aug Sep Oct Nov Dec)
meses_completos=(January February March April June July August September October November December)
n_mes=(1 2 3 4 5 6 7 8 9 10 11 12)
declare -i hay_mes=1

for (( i=0; i<12 && hay_mes !=0 ; i++ )); do

	if [[ $1 == ${meses[i]} ]]; then 
		printf "Your month is ${meses_completos[i]}\n";
		hay_mes=0;
	elif [[ $1 == ${n_mes[i]} ]]; then 
		printf "Your month is ${meses_completos[i]}\n";
		hay_mes=0;
	fi;
done

if [[ $hay_mes != 0 ]]; then printf "Incorrect format.\n";fi;
