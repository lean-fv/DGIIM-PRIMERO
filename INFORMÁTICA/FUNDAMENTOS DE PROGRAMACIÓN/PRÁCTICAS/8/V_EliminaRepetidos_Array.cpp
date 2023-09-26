/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS V

13. Escribir un programa que lea un número indeterminado de números positivos
(termina la lectura cuando se introduce un negativo) aunque nunca leerá más de
50. Conforme los va leyendo, los va almacenando en un vector, datos.

A continuación elimina del vector los valores repetidos, dejando una sola copia.
No se dejan huecos en el vector y todos los números quedan agrupados en las
posiciones más bajas del vector.

c) El anterior algoritmo nos obliga a desplazar muchas componentes.

Implementar el algoritmo que usa dos apuntadores, posicion_lectura y
posicion_escritura, que nos van indicando, en cada momento, la componente que
se está leyendo y el sitio dónde tiene que escribirse.

Por ejemplo, supongamos que en un determinado momento la variable
posicion_lectura vale 6 y posicion_escritura 3. Si la componente en
la posición 6 está repetida, simplemente avanzaremos posicion_lectura. Por
el contrario, no estuviese repetida, la colocaremos en la posición 3 y
avanzaremos una posición ambas variables.

ENTRADA: una secuencia de datos repetidos o no.
SALIDA: una secuencia con esos datos sin repetidos.

*/

#include <iostream>

using namespace std;

int main() {

	//Declaraciones.

	const int MAX_DATOS = 50;
	int datos[MAX_DATOS];

	int total_utilizados = 0;

	bool sigo = true;
	int dato;

	//Entrada de datos.

	cout << "***********************************************" << endl << endl;

	cout << "Introduzca los valores del vector: ";
	cin >> dato;

	while ((dato >= 0) && (sigo)) {

		datos[total_utilizados]	= dato;
		total_utilizados++;

		if (total_utilizados == MAX_DATOS) sigo = false;

		else {

		cout << "Introduzca los valores del vector: ";
		cin >> dato;

		}
	}

	// Se muestran los datos originales

	cout << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << endl;
 	cout << "Datos originales " << "(" << total_utilizados << " datos): ";
	cout << endl;

	for (int i = 0; i < total_utilizados; i++)
		cout << datos[i] << "  ";

	cout << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << endl;

	//Calculos.

	int posicion_lectura;
	int posicion_escritura;

	// Comenzamos a comprobar los valores de la segunda posicion del vector

	posicion_lectura = 1;
	posicion_escritura = 1;

	while (posicion_lectura < total_utilizados){

		int valor_buscado = datos[posicion_lectura];

		/* Busco "valor_buscado" en el subvector desde 0 a pos_lectura */

		int pos = 0;
		bool encontrado = false;

		while ((pos < posicion_escritura) && (!encontrado)){

			if (datos[pos] == valor_buscado){

				encontrado = true;
			}

			else{

				pos++;
			}
		}

		if (!encontrado){

			/* Si el valor de la casilla en la que se encuentra posicion
			de lectura no esta repetido en las casillas anteriores, se
			copia su valor en el de la casilla de la posicion de
			escritura y posicion_escritura aumenta en una unidad */

			datos[posicion_escritura] = datos[posicion_lectura];
			posicion_escritura++;
		}

		/* La posicion de lectura siempre se aumenta independientemente de si
		el valor era repetido o no */

		posicion_lectura++;
	}

	cout << "Tras eliminar los repetidos, el vector queda asi: " << endl;
	for(int i = 0; i < posicion_escritura; i++){

		cout << datos[i] << "  ";
	}

	cout << endl;
	cout << "***********************************************" << endl << endl;

	return 0;

	}
