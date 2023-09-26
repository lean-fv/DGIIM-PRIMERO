/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 1
/*	
   Programa que lee un entero de tres d�gitos y los muestra individualmente, 
   separ�ndolos por tres espacios. 
   
   Entradas: un entero
   Salidas:  Los d�gitos del entero leido.
*/
/*********************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	// Entrada

	// Dato de entrada: una cadena formada por tres d�gitos decimales
	string cad_3digitos;
	
	cout << "Introduce un entero de tres digitos: ";
	cin >> cad_3digitos; 


	// C�lculos

	int numero_3dig; // n�mero de 3 d�gitos (unidades, decenas y centenas)  
	int numero_2dig; // n�mero de 2 d�gitos (unidades y decenas) 

	int centenas; // d�gito de las centenas
	int decenas;  // d�gito de las decenas 
	int unidades; // d�gito de las unidades

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
