/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 1
/*	
   Programa que lee y muestra un intervalo. La lectura no es nada sofisticada, 
   se hace elemento a elemento (ver enunciado)   
*/
/***************************************************************************/

#include <iostream>
#include <string>

using namespace std;

int main() {
	
	double a, b;
	char   caracter_izda, caracter_dcha, separador;
	
	// Entrada
	cout << "Escriba el intervalo: ";
	
	cin >> caracter_izda; 
	cin >> a;
	cin >> separador; 
	cin >> b;
	cin >> caracter_dcha; 
	
	// C�lculos y salida 
	
	cout << endl;
	cout << "Intervalo: "  << caracter_izda << " " << a << " " 
	     << separador << " " << b << " " << caracter_dcha;
	cout << endl;
	
	// Versi�n 2: separamos c�lculos de la presentaci�n.
	
	/*  Se trata de componer una dato string a partir de los datos leidos 
	 	y darle la apariencia de un intervalo. Emplearemos el operador + 
	 	para componer el string mediante concatenaci�n y la funci�n to_string
	 	para convertir los datos double a string.
	*/

	// C�lculos
	
	string intervalo; 	// Inicialmente, cadena vac�a. Se puede inicializar 
						// expl�citamente: string intervalo = ""; 

	intervalo = intervalo + caracter_izda + to_string(a) + separador;
	intervalo = intervalo + " " + to_string(b) + caracter_dcha;
			
	// Salida 
	
	cout << endl;
	cout << "Intervalo: "  << intervalo;
	cout << endl;

   return 0; 
}


