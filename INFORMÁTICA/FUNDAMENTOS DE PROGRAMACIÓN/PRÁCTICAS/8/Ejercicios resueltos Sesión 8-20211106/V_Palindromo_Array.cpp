/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 5 (Arrays)
//
/*	
	Programa que lee un número indeterminado de caracteres (la lectura 
	termina cuando se introduce un '*'), los guarda en un vector y dice 
	si el vector es un palíndromo, es decir, que se lee igual de izquierda 
	a derecha que de derecha a izquierda.
	
	Presentamos dos versiónes: 
		1) La primera analiza el vector "tal cual es".
		2) La segunda no considera los separadores y no diferencia 
		   entre mayúsculas y minúsculas.
*/
/***************************************************************************/

#include <iostream>
#include <cctype>
using namespace std;


int main (void)
{		
	// Vector de datos
	
	const int TAMANIO = 100; 
	char vector[TAMANIO];
	int total_utilizados = 0;	
	
	
	// Lectura de datos 
	
	cout << "Introduzca un serie de caracteres (fin = *): ";
	
	char caracter;
	
	caracter = cin.get();	// Lectura adelantada
	
	while ((caracter != '*') && (total_utilizados<TAMANIO)) {
		
		vector[total_utilizados] = caracter;
		total_utilizados++;
	
		caracter = cin.get(); // Lectura adelantada
	}
	
	
	// Cálculos
	
	int izda, dcha; // Para recorrer el vector por los dos extremos 
		
		
		
	// VERSIÓN 1: El vector se procesa "tal cual"
	
	bool es_palindromo1 = true;
	
	izda = 0;	// Para recorrer de izqierda a derecha
	dcha = total_utilizados - 1; // Para recorrer de derecha a izquierda

	while ((izda < dcha) && es_palindromo1) {

		if (vector[izda] != vector[dcha])
		
			es_palindromo1 = false; // terminar
			
		else {	// seguir buscando
			izda++; // posición siguiente
			dcha--;	// posición anterior
		}

	} // while ((izda < dcha) && es_palindromo)



	// VERSIÓN 2: no se consideran separadores ni se diferencian mayúsculas 
	// y minúsculas
	
	bool es_palindromo2 = true;

	izda = 0;	// Para recorrer de izqierda a derecha
	dcha = total_utilizados - 1; // Para recorrer de derecha a izquierda

	while ((izda < dcha) && es_palindromo2) {

		while ((isspace(vector[izda])) && (izda < dcha))  izda++;
		while ((isspace(vector[dcha])) && (izda < dcha))  dcha--;
		
		if (izda < dcha) {
		
			if (toupper(vector[izda]) != toupper(vector[dcha]))
	
				es_palindromo2 = false; // terminar
	
			else {	// seguir buscando
				izda++; // posición siguiente
				dcha--;	// posición anterior
			}
		}

	} // while ((izda < dcha) && es_palindromo)
	
	// Mostrar Resultado
	
	cout << endl;
	
	cout << "Segun version 1: ";
	if (es_palindromo1) 
		cout << "Es un palindromo";
	else 
		cout << "No es un palindromo";
	cout << endl;
	
	cout << "Segun version 2: ";
	if (es_palindromo2) 
		cout << "Es un palindromo";
	else 
		cout << "No es un palindromo";
	cout << endl;
	
	return 0;
}
