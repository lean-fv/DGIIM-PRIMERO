#!/bin/bash
#repaso.sh 1-4

if [[ $# == 2 ]]; then

	if [ -f $2 ]; then
		
		printf "Creando archivo de salida....\nEscribiendo 3 primeras lineas del fichero de entrada.\n\n";
		(head -3 $2) > salida
		
		
	else printf "El segundo argumento no es un fichero regular.\n"; exit -2; fi;
	
	if [ -d $1 ]; then
	
		N=`find $1 -type f | wc -l`;
		printf "El directorio $1 tiene $N archivos\n";
		
		find $1 -type f -readable >> salida;
		LEIBLES=`find $1 -type f -readable | wc -l`;
		
	
		printf "De un total de $N archivos hay $LEIBLES con permiso de lectura.\n";
		
		
	else printf "Creando directorio $1\n"; mkdir $1; 
	fi;
	
	
	

else printf "Numero de argumentos incorrecto.\nCorrecto formato: prueba <nombre_directorio> <nombre_archivo>\n"; exit -1; fi;
