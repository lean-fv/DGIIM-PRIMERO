#!/bin/bash

if [ -f ./$1 ]; 

	then printf "El archivo ./$1 existe\n"; 

else #[ ! -f ./sesion5.pdf ]
	printf "El archivo ./$1 no existe\n";
	if [ -d $2 ];
		then printf "$2 es un directorio\n";	
	fi

fi
