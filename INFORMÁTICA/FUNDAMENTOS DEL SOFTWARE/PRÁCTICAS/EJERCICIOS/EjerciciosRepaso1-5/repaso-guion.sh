#!/bin/bash
#repaso-guion.sh 1-5

if [[ $# == 3 ]]; then

	if [[ ! -d $1 ]]; then mkdir $1; fi;
	
	if [[ $2 == d || $2 == f ]]; then
	
		(grep -rnw $3 $1)>resultado;
		
		(find -type $2)>>resultado;
	
	else printf "El segundo argumento no es ni d (directorio) ni f (fichero regular).\n"; exit -2; fi;


else printf "Numero de argumentos incorrecto.\nCorrecto formato: examen-guion <nombre_directorio> <letra> <palabra>\n"; exit -1; fi;
