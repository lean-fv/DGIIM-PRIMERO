/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 2
//
/*	
	Programa que calcula si es aplicable la subida de sueldo de una persona
	dada su edadingresos, de acuerdo con la regla:
	 
		"Se subir� el sueldo un 5% si tiene m�s de 55 a�os y sus ingresos
		son inferiores a 750 euros"
		
	Entradas: edad (int) e ingresos (double)
	Salidas: el nuevo sueldo � el mensaje "No es aplicable la subida"
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
	cout << "Introduce los ingresos: ";
	cin >> ingresos;

	// Para independizar c�lculos y presentaci�n de resultados usaremos 
	// variables l�gicas que registran estados. 
	
	bool es_senior;				// VERDAD si edad > EDAD_MINIMA
	bool tiene_ingresos_bajos;	// VERDAD si ingresos < INGRESO_MAXIMO
	bool es_aplicable_subida;	// VERDAD si son ciertas LAS DOS anteriores

	// C�lculos

	es_senior = (edad > EDAD_MINIMA);
	tiene_ingresos_bajos = (ingresos < INGRESO_MAXIMO);
	es_aplicable_subida = (es_senior && tiene_ingresos_bajos);

	if (es_aplicable_subida)
		ingresos = ingresos + ((ingresos*PORC_SUBIDA)/100.0);

	// Resultado

	cout << endl;
	if (!es_aplicable_subida)
		cout << "No es aplicable la subida";
		
	cout << endl;
	cout << "Salario Final: " << ingresos;
	cout << endl;

	/*
	En el anterior c�digo usamos dos estructuras equivalentes:
		if (es_aplicable_subida)
		......
		if (!es_aplicable_subida)
	pero logramos independizar los c�mputos de la salida de datos,
	lo cual es muy importante.
	
	Si no lo hubi�ranmos hecho as�, el c�digo ser�a: 
		
		if (es_aplicable_subida)
			ingresos = ingresos * 1.05;
		else
			cout << "No es aplicable la subida";
	
	cout << endl;
	cout << "Salario Final: " << ingresos;
	cout << endl;
			
	No es una buena soluci�n mezclar c�lculos y presentaci�n de resultados.
	*/
	
	return 0;
}
