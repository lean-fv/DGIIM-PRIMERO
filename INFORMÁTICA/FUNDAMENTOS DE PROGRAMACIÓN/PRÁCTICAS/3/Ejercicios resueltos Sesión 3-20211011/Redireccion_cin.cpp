/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
/*
	Demostraci�n simple de lectura de varios datos en la misma
	instrucci�n, incluso de diferentes tipos.

*/
/***************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int numero_entero;
	char caracter1, caracter2;
	
	cout << "\nIntroduzca un entero y dos caracteres --> ";
	cin >> numero_entero >> caracter1 >> caracter2;

	cout << "Entero: " << numero_entero << endl;
	cout << "Caracter 1: " << caracter1 << endl;
	cout << "Caracter 2: " << caracter2 << endl;	
	cout << "endl;
	
	return 0;
}

