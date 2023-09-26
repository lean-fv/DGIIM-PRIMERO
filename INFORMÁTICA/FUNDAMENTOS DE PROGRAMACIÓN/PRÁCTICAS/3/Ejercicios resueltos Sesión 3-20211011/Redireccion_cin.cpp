/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
/*
	Demostración simple de lectura de varios datos en la misma
	instrucción, incluso de diferentes tipos.

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

