#!/bin/bash
#5_3.sh
fila=-1;

read -p "Introduzca una letra o un numero." caracter;

case $caracter in

	[0-9]) 	fila=0 ;;
	[qwertyuiop])	fila=1 ;;
	[asdfghjkl])	fila=2 ;;
	[zxcvbnm])	fila=3 ;;

esac

if [ $fila != -1 ]; then printf "El caracter esta en la fila $fila. \n";
else printf "Caracter no valido.\n";
fi
