/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS V

15. En el ejercicio 47 de la Relación de Problemas II se pedía escribir un
programa que lea un número entero positivo y muestre su descomposición en
factores primos.

Ahora deberá realizar un programa que lea un número indeterminado de enteros
positivos (finalizar cuando se introduce un cero) y exprese cada uno de ellos
en base al producto de sus factores primos. Exprese el resultado como el
producto de potencias (apartado b del ejercicio antes mencionado). Por ejemplo:
360 = 2^3 * 3^2 * 5
121 = 11^2
11 = 11

Para la solución deberá considerar únicamente los factores primos. Para ello
deberá calcular (y guardar en un array) los números primos antes de leer ningún
número.

Use la Criba de Eratóstenes descrita en el ejercicio 14 de esta misma relación
de problemas.

Recomendamos usar un struct del tipo:
struct Pareja {
int primo;
int potencia;
};
para guardar cada pareja primo-potencia. Cada una de estas parejas se guardará
en una casilla del array descomposicion:

const int CASILLAS_DESCOMPOSICION = 50;
Pareja descomposicion[CASILLAS_DESCOMPOSICION] = {{0,0}};
int utilizados_descomposicion = 0;

14. (Examen Septiembre 2012) La criba de Eratóstenes (Cirene, 276 a. C.
Alejandría, 194 a. C.) es un algoritmo que permite hallar todos los números
primos menores que un número natural dado n.

El procedimiento “manual” consiste en escribir todos los números naturales
comprendidos entre 2 y n y tachar los números que no son primos de la siguiente
manera:

el primero (el 2) se declara primo y se tachan todos sus múltiplos; se busca el
siguiente número entero que no ha sido tachado, p, se declara primo y se
procede  a tachar todos sus múltiplos, y así sucesivamente.

El proceso de criba termina cuando el cuadrado de p es mayor que n.

Si MAX_PRIMO es el mayor número que se va a considerar (establezca su valor a
5000, p.e.) escribir un programa que lea un valor n (1 ≤ n ≤MAX_PRIMO) y calcule
y muestre todos los primos menores o iguales que n.

Recomendaciones:

a) Para realizar la criba use el vector es_primo de datos bool de manera que si
es_primo[i] es true entonces, i es primo.

b) El resultado (los números primos calculados) se guardarán en el vector
primos, de datos int, almacenados de manera consecutiva, sin huecos.
Se establece un tamaño máximo para el vector de MAX_DATOS casillas (piense en
un valor sensato para MAX_DATOS basándose en MAX_PRIMO).

c) Tenga en cuenta las posibles situaciones de error, detéctelas y actúe
correctamente.

ENTRADA: Una serie de enteros positivos.
SALIDA: Su descomposicion en factores primos.

*/

#include <iostream>

using namespace std;


struct Pareja {
int primo;
int potencia;
};

const int MAX_DATOS = 5000;
const int MAX_PRIMO = 5000;

int main() {

	//Declaraciones.

	int n;
	bool es_primo[MAX_DATOS];
	int primos [MAX_DATOS]; //Array para guardar los primos.
	int natural [MAX_DATOS]; //Serie de naturales desde el 0 hasta el numero.

	const int TERMINADOR = 0;
	const int CASILLAS_DESCOMPOSICION = 50;
	Pareja descomposicion[CASILLAS_DESCOMPOSICION] = {{0,0}};
	int utilizados_descomposicion = 0;
	int numero;
	int exponente = 0;

	//Entrada de datos.

	cout << "***********************************************" << endl << endl;

	//Lectura anticipada.
	do{ //Filtro
		cout << "Introduzca un entero positivo. ";
		cin >> n;
		cout << endl;
	} while (n < 1 && n > MAX_PRIMO);

	int contador = 0;

	while (n != TERMINADOR){


		//Calculos.

		/* Metemos todos los naturales menores o iguales que el numero
		introducido en un vector auxiliar.*/
		for (int i = 0; i <= n; i++){
			natural[i] = i;
			es_primo [i] = true;
		}


		//Criba.
		for (int i = 2; i <= n; i++){

			if (es_primo[i]){

				int limite = n / natural[i];

				//Despejando la ecuacion de fin de la Criba
				//queda la siguiente condicion.
				for (int j = natural[i]; j <= limite; j++){

					es_primo [j * natural[i]] = false;

				}

				primos[utilizados_descomposicion] = natural[i];
				utilizados_descomposicion++;
			}


		}

		//Algoritmo de obtencion de potencias.
		numero = n;
		for (int i = 0; i < utilizados_descomposicion; i++){

			while (numero%primos[i] == 0){
				numero = numero / primos[i];
				exponente++;
			}
			descomposicion[i].primo =
			primos[i];
			descomposicion[i].potencia = exponente;


			exponente = 0;
		}

		//Salida de datos.
		cout << n << " = ";
		for (int i = 0; i < utilizados_descomposicion; i++){

			if (descomposicion[i].potencia == 0){

				cout << "";
			}

			else if (descomposicion[i].potencia == 1){

				cout << descomposicion[i].primo << " * ";
			}

			else {

				cout << descomposicion[i].primo << " ^ "
					 << descomposicion[i].potencia << " * ";
				}
			}

		cout << endl;

		//Consecuencia de la lectrura anticipada.
		do{ //Filtro
			cout << "Introduzca un entero positivo. ";
			cin >> n;
			cout << endl;
		} while (n < 1 && n > MAX_PRIMO);
	}

	cout << "***********************************************" << endl << endl;



	return 0;
}
