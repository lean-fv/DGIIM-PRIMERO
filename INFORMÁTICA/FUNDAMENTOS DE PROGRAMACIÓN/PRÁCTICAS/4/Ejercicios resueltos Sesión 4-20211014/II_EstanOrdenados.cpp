/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 2
//
/*	 
	Programa que lee  tres enteros desde teclado y nos dice si están
	ordenados (da igual si es de forma ascendente o descendente)
	o no lo están.

	Entradas: los tres valores (int)
	Salidas: Un mensaje indicando si están ordenados o no lo están.
*/
/***************************************************************************/

#include <iostream>
using namespace std;
 
int main()
{
	int num1, num2, num3; // datos de entrada

	// Entrada de datos

	cout << "Introduzca primer valor:  ";
	cin >> num1;
	cout << "Introduzca segundo valor: ";
	cin >> num2;
	cout << "Introduzca tercer valor:  ";
	cin >> num3;
   
	// Cálculos

	bool ordenados_creciente, ordenados_decreciente;
	
   	if ((num1 >= num2) && (num2 >= num3))
		ordenados_decreciente = true;
   	else
		ordenados_decreciente = false;

   	if ((num1 <= num2) && (num2 <= num3))
		ordenados_creciente = true;
   	else
		ordenados_creciente = false;

	bool ordenados = (ordenados_creciente || ordenados_decreciente);

	// Salida de Resultados

	cout << endl;

	if (ordenados)
	
		if (ordenados_creciente)
			cout << "Ordenados. Orden creciente.";
		else
			cout << "Ordenados. Orden decreciente.";
			
	else
		cout << "No estan ordenados";
		
	cout << endl;

	return 0;
}
