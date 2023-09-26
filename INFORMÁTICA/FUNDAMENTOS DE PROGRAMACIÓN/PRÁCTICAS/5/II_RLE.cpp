/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS II

45. El método RLE (Run Length Encoding) codifica una secuencia de datos formada
por series de valores idénticos consecutivos como una secuencia de parejas de
números (valor de la secuencia y número de veces que se repite).

Esta codificación es un mecanismo de compresión de datos (zip) sin pérdidas.
Se aplica, por ejemplo, para comprimir los ficheros de imágenes en las que hay
zonas con los mismos datos (fondo blanco, por ejemplo).

Realizar un programa que lea una secuencia de números naturales terminada con
un número negativo y la codifique mediante el método RLE. Leed los datos desde
un fichero externo, tal y como se explica en la página 24.
Entrada: 1 1 1 2 2 2 2 2 3 3 3 3 3 3 5 -1
(tres veces 1, cinco veces 2, seis veces 3, una vez 5)
Salida: 3 1 5 2 6 3 1 5

ENTRADA: secuencia de numeros.
SALIDA: numeros y las veces que se repiten.

*/

#include <iostream>
#include <string>

using namespace std;

int main()
{

	//Declaraciones.

	int numero;
	int numero_anterior;
	int total_numero = 0;

	string salida;
	string espacio_anterior;
  const string ESPACIO = " ";

	// Entrada de datos.
  cout << "***********************************************" << endl << endl;

	cout << "Introduzca una secuencia de datos. ";
  cin >> numero;

  //Calculos.
	while (numero >= 0){

		if (numero == numero_anterior || total_numero == 0){

			total_numero++;

		}
		else {

			salida = salida + espacio_anterior;
			total_numero = 1;

		}

		espacio_anterior = to_string (total_numero) + ESPACIO +
						 to_string (numero) + ESPACIO;

		numero_anterior = numero;

	  cout << "Introduzca una secuencia de datos. ";
	  cin >> numero;

	}

	// Añado el ultimo tramo, que no coge el bucle.

	salida = salida + espacio_anterior;

	// Salida

	cout << endl << salida << endl;

  cout << "***********************************************" << endl << endl;

	return 0;

}
