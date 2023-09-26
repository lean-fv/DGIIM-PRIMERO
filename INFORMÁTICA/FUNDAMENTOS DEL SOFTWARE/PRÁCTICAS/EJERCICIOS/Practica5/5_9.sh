#!/bin/bash

#5_9.sh
#dirname=$1
#declare -i num_files=$2
#basefilename="$3"

if [[ $# == 3 ]]; then 

	if [[ $2 -ge 1 && $2 -le 99 ]]; then
	
		if [[ ! -d $1 ]]; then 
			
			printf "Creando directorio $1\n";
			mkdir $1;
		fi;
		
		chmod u+rw $1;
		
		for (( i=1; i<=$2; i++ )) do
		
			n_completo="";
			if [[ $i -lt 10 ]]; then n_completo="$30$i";
			else n_completo+="$3$i";
			fi;
			
			touch $1/$n_completo;
		
		done
			
	else printf "Segundo argumento no valido: Introduzca un numero entero entre 1 y 99\n"; exit 2; fi; 

else printf "Numero de argumentos incorrecto\n"; exit 1; fi;
