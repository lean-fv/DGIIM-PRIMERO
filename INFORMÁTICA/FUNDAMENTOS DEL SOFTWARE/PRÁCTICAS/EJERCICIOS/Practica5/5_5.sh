#!/bin/bash

#5_5.sh

seguir=true;
declare -i n;
while $seguir; do

read -p "Introduzca un numero: " n;
if [[ $n -ge 1 && $n -le 10 ]]; then seguir=false; fi;
done


