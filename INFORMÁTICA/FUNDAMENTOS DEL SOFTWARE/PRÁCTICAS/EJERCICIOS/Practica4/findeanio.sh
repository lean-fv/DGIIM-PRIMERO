#!/bin/bash
#findeanio.sh

declare -i diasanio=365;
declare -i diferencia=`expr $(date +%j -d"31 Dec") - $(date +%-j)`;

if [ $1 = "-h" ]; then printf "Este guión determina si el número de días restantes hasta fin de año es múltiplo de 5.\n"; fi

printf "Diferencia: $diferencia\n";

if (( $diferencia % 5 == 0 )); 
	then printf "El numero de dias que quedan hasta fin de año es múltiplo de 5.\n";

else printf "El numero de dias que quedan hasta fin de año no es múltiplo de 5.\n";

fi
