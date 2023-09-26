#!/bin/bash
# Titulo:	archivosdirectorio 
# Fecha:	21/03/2022 
# Autor:	Leandro Jorge Fernández Vega 
# Versión:	1.0 
# Descripción: 
#		Crea un guión que muestre los archivos de un directorio (que se pasará como primer argumento) que han sido accedidos en los últimos x días (este número de días se pasará como 			segundo argumento al guión).
# Opciones: 	Ninguna 
# Uso: 	Prueba de elaboración de un guión con argumentos a la hora de ejecución.
 
printf "Los archivos del directorio $1 que han sido accedidos en los ultimos $2 dias son: \n\n" ; find $1 -atime -$2 ;
