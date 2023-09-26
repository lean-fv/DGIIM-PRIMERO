/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 1
/*	
   Programa que lee un entero de tres dígitos y los muestra individualmente, 
   separándolos por tres espacios. 
   
   Entradas: un entero
   Salidas:  Los dígitos del entero leido.
*/
/*********************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	// Entrada

	// Dato de entrada: una cadena formada por tres dígitos decimales
	string cad_3digitos;
	
	cout << "Introduce un entero de tres digitos: ";
	cin >> cad_3digitos; 


	// Cálculos

	int numero_3dig; // número de 3 dígitos (unidades, decenas y centenas)  
	int numero_2dig; // número de 2 dígitos (unidades y decenas) 

	int centenas; // dígito de las centenas
	int decenas;  // dígito de las decenas 
	int unidades; // dígito de las unidades

	// Transformar "cad_3digitos" (string) a numero_3dig (int)
	numero_3dig = stoi(cad_3digitos);	
	
	centenas    = numero_3dig / 100; // Valor de las centenas
	numero_2dig = numero_3dig % 100; // Las dos cifras menos significativas
	
	decenas     = numero_2dig / 10;  // Valor de las decenas
	unidades    = numero_2dig % 10;  // La cifra menos significativa(unidades)

	const string SEPARADOR = "..."; 
	string cad_resultado = SEPARADOR + to_string(centenas) + 
						   SEPARADOR + to_string(decenas) + 
	                       SEPARADOR + to_string(unidades); 
	
	// Salida
	
	cout << endl;
	cout << cad_resultado << endl;	
	cout << endl;

	return 0;
}
