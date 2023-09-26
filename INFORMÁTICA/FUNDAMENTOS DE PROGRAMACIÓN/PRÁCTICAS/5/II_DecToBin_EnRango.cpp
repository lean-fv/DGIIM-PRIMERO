/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS II

83. Escribir un programa que muestre la representación binaria de un número
entero (positivo o cero) expresado en base 10.

El programa pedirá el número decimal que se va a convertir y calculará su
representación binaria sobre un dato string (los bits que conforman la
representación binaria del número serán caracteres '0' ó '1').

El número de bits del resultado (la longitud del string) dependerá del valor
del número a convertir. Por ejemplo, al convertir el valor 11 se genera el
string 1011 (longitud = 4) mientras que al convertir el valor 128 se genera
el string 10000000 (longitud = 8).

84. Ampliar la funcionalidad del ejercicio 83. El programa mostrará la
representación binaria de un número entero (positivo o cero) en un rango
predeterminado.

El programa pedirá en primer lugar el número de bits (llamémosle n) que tendrán
los valores binarios con los que se va a trabajar. Dado n los números enteros
que se admitirán estarán comprendidos entre 0 y 2^n − 1 (todos ellos pueden
representarse estrictamente con n bits o menos).

Igual que se pedía en el ejercicio 83 se calculará su representación binaria
sobre un dato string aunque ahora el número de bits del resultado siempre será
n (si fuera necesario se rellenarán con '0' a la izquierda del primer '1').

Por ejemplo, si se emplean 8 bits, al convertir el valor 11 ahora se genera el
string 00001011 y al convertir el valor 128 se genera el string 10000000
(en todos los casos la longitud será 8).

Comprobar y controlar adecuadamente toda las situaciones de error.

ENTRADA: numero en base decimal.
SALIDA: el numero en binario con tantos bits como se desee.
*/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main (){

	int decimal;
	int binario;
	int n_bits;
	char cero = '0';
	char uno = '1';
	string numero_binario = "";
	string num_final;


	//Entrada

  cout << "***********************************************" << endl << endl;

  do {
    cout << "Introduzca el numero positivo a pasar a binario: ";
  	cin >> decimal;
  }while (decimal < 0);

  do {
    cout << "Indique con cuantos bits desea que se represente: ";
  	cin >> n_bits;
  } while (n_bits <= 0 || (decimal > (pow(2, n_bits) - 1)));

	//Calculos.

	while (decimal/2 != 1){
		binario = decimal % 2;

    if (binario == 0) {
			numero_binario = cero + numero_binario;
		} else if (binario == 1) {
			numero_binario = uno + numero_binario;
		}

		decimal = decimal/2;

	}

  binario = decimal % 2;

		if (binario == 0){
			num_final = cero + numero_binario;
		} else if (binario == 1){
			num_final = uno + numero_binario;
		}

		num_final = uno + num_final;


	while (num_final.length() < n_bits) {
		num_final = cero + num_final;
	}


	//Salidas
	cout << endl ;
	cout << "El numero en binario sera: " << num_final << endl << endl;

  cout << "***********************************************" << endl << endl;


	return 0;
}
