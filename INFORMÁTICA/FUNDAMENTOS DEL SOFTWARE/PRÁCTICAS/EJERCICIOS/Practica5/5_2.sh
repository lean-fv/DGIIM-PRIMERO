#!/bin/bash
#5_2.sh
if test -d $1 ; then
	for archivo in $(ls $1);
	do
		if test -f $1/$archivo ; then printf "Archivo regular: $archivo \n";
		elif test -d $1/$archivo ; then printf "Directorio: $archivo \n";
		else printf "Enlace: $archivo \n";
		
		fi;
	done

fi
