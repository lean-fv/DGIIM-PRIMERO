#!/bin/bash
# Titulo:	practica5 
# Fecha:	25/04/2022 
# Autor:	Leandro Jorge Fernández Vega 
# Versión:	1.0 
# Descripción: 
#Escribir un script que muestre un menú con el siguiente aspecto:

#Seleccione opción:

#1) Sumar números

#2) Restar números

#3) Multiplicar números

#4) Salir

#Elija la opción deseada:

#(a) La opción 1, debe solicitar por teclado dos números y deberá mostrar los números, así como la suma de ambos.

#(b) La opción 2, debe solicitar por teclado dos números y deberá mostrar los números, así como la diferencia entre ambos.

#(c) La opción 3, debe solicitar por teclado dos números y deberá mostrar los números, así como el producto de ambos.

#(d) La opción 4, debe permitir salir del script y volver al indicador del Shell. Mientras no se pulse este valor, siempre se mostrará el menú.

# Opciones: 	Ninguna 
# Uso: 	Prueba de bucles.

seguir=true;
declare suma;
declare resta;
declare producto;

while $seguir; do
	
	printf "Seleccione opción:\n1) Sumar números\n2) Restar números\n3) Multiplicar números\n4) Salir";
	printf "\n";
	read opcion;
	
	case $opcion in

		1) printf "Introduzca dos numeros. "; read NUM_1; read NUM_2; suma=$(($NUM_1 + $NUM_2)); printf "$NUM_1  $NUM_2 \n Suma = $suma \n" ;;
		2) printf "Introduzca dos numeros. "; read NUM_1; read NUM_2; resta=$(($NUM_1 - $NUM_2)); printf "$NUM_1  $NUM_2 \n Resta = $resta \n" ;;
		3) printf "Introduzca dos numeros. "; read NUM_1; read NUM_2; producto=$(($NUM_1 * $NUM_2)); printf "$NUM_1  $NUM_2 \n Producto = $producto \n" ;;
		*) seguir=false;;
	esac
done







