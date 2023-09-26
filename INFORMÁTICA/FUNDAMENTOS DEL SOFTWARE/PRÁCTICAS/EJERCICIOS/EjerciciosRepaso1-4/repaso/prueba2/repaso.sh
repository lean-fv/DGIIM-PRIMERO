#!/bin/bash

if [[ $# != 2 ]]; then

	if [[ -f $2 ]]; then
		
		printf "Creando archivo de salida.\nEscribiendo 3 primeras lineas del fichero de entrada.\n";
		(head -3 $2) > salida
		
		
	else printf "El segundo argumento no es un fichero regular\n!"; exit -2; fi;
	
	if [[ -d $1 ]]; then
	
		N=`ls $1 | wc -l`;
		printf "El directorio $1 tiene $N archivos\n";
		
		X=`find $1 -perm r`
		$X>> salida;
	
		printf "De un total de $N archivos hay `X|  wc -l` con permiso de lectura.\n";
		
	else printf "Creando directorio $1\n"; mkdir $1; 
	fi;
	
	

else printf "Numero de argumentos incorrecto.\nCorrecto formato: prueba <nombre_directorio> <nombre_archivo>"; exit -1; fi;
