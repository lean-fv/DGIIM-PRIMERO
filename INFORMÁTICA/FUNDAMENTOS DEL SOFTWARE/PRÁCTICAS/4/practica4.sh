#!/bin/bash
# Titulo:	practica4 
# Fecha:	28/03/2022 
# Autor:	Leandro Jorge Fernández Vega 
# Versión:	1.0 
# Descripción: 
#		Crea un guion que reciba dos argumentos de tipo numérico y realice las siguientes operaciones. Si el primer argumento es mayor que el segundo, entonces que se multipliquen los 			valores. En este caso, se ha de crear un archivo cuyo nombre contenga el resultado de la multiplicación. Por ejemplo: 12_multi.txt  Si el segundo es mayor que el primero, entonces 			que se resten. Si son el mismo número, entonces que muestre un mensaje indicándolo simplemente.
# Opciones: 	Ninguna 
# Uso: 	Prueba de condicionales.

echo Introduciendo dos valores numericos:
numero='^\-?[0-9]+$'

if (( $# == 2 )); 
	then 
	if [[ $1 =~ $numero && $2 =~ $numero ]];
	
	then
		if (( $1>$2 )) ; then touch $(( $1*$2 ))_multi.txt ; echo Se han multiplicado: resultado en $(( $1*$2 ))_multi.txt.;
		elif (( $1<$2 )) ; then echo Su resta es $(( $1-$2 ));
		else echo Son iguales.;
		fi
	
	else echo No son enteros.
	
	fi
	
else exit -1

fi
