/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 2
//
/*	
	Programa que calcula si es aplicable la subida de sueldo de una persona
	dada su edadingresos, de acuerdo con la regla:
	 
		"Se subirá el sueldo un 5% si tiene más de 55 años y sus ingresos
		son inferiores a 750 euros"
		
	Entradas: edad (int) e ingresos (double)
	Salidas: el nuevo sueldo ó el mensaje "No es aplicable la subida"
	
	NOTAS: Se exige que 
		* edad > 0
		* ingresos > 0
*/
/***************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	const int EDAD_MINIMA = 55; 
	const int INGRESO_MAXIMO = 750; 
	const double PORC_SUBIDA = 5.0;		// 5 % 

	int edad;
	double ingresos;

	// Lectura 
	
	cout << "Introduce la edad: ";
	cin >> edad;

	bool edad_ok = false;
	bool ingresos_ok = false;
	
	edad_ok = (edad > 0); 

	if (edad_ok) {
		cout << "Introduce los ingresos: ";
		cin >> ingresos;
		
		ingresos_ok =  (ingresos > 0); 
	}
	
	bool datos_ok = (edad_ok && ingresos_ok); 
	
	
	// Cálculos

	bool es_aplicable_subida; 

	if (datos_ok) {
			
		// Para independizar cálculos y presentación de resultados usaremos 
		// variables lógicas que registran estados. 
		
		bool es_senior;				// VERDAD si edad > EDAD_MINIMA
		bool tiene_ingresos_bajos;	// VERDAD si ingresos < INGRESO_MAXIMO
		
		// La variable "es_aplicable_subida" será VERDAD si son ciertas 
		// LAS DOS anteriores
		
		es_senior = (edad > EDAD_MINIMA);
		tiene_ingresos_bajos = (ingresos < INGRESO_MAXIMO);
		es_aplicable_subida = (es_senior && tiene_ingresos_bajos);
	
		if (es_aplicable_subida)
			ingresos = ingresos + ((ingresos*PORC_SUBIDA)/100.0);

	}

	// Resultado

	if (datos_ok) {

		cout << endl;
		if (!es_aplicable_subida)
			cout << "No es aplicable la subida";
			
		cout << endl;
		cout << "Salario Final: " << ingresos;
		cout << endl;
	}
	else { // Error en la entrada
		
		cout << endl;	
				
		if (!edad_ok) {
			cout << "Error: la edad no es correcta." << endl;	
		} 
		else { // edad correcta 
			if (!ingresos_ok) {
				cout << "Error: ingresos incorrectos." << endl;	
			} 			
		}
		cout << endl;	
	}
	
	return 0;
}
