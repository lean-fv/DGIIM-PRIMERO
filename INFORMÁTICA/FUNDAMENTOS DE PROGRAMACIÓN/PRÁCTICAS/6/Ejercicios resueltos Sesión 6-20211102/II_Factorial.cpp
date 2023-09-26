/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// (C) JUAN CARLOS CUBERO TALAVERA
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 2
//
/*	 
	Programa que calcula el factorial de un entero n
	
		n! = n x (n-1) x (n-2) x ... x 2 x 1 si n>=1
		0! = 1
		
	Entradas: Un número entero, n
	Salidas:  EL factorial de n, n!
*/
/***************************************************************************/

#include <iostream>
using namespace std;

/***************************************************************************/
/***************************************************************************/

int main()
{

	// Cálculo del factorial
	// n! = n * (n-1) * (n-2) * ... * 1 si n>=1
	// 0! = 1

	long factorial; // OJO: para gestionar enteros "grandes"
	int n;
	int multiplicando;

	do {
		cout << "Introduzca un entero positivo: ";
		cin >> n;
	} while (n<0);

	factorial = 1;

	for (multiplicando = 2; multiplicando <=n ; multiplicando++)
		factorial = factorial * multiplicando;

	cout << endl;
	cout << n << "! = " << factorial;
	cout << endl;

	return 0;
}

/***************************************************************************/
/***************************************************************************/
