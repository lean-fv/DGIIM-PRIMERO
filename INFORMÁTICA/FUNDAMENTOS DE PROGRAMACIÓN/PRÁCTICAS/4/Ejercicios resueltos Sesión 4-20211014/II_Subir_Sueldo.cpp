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

	// Para independizar cálculos y presentación de resultados usaremos 
	// variables lógicas que registran estados. 
	
	bool es_senior;				// VERDAD si edad > EDAD_MINIMA
	bool tiene_ingresos_bajos;	// VERDAD si ingresos < INGRESO_MAXIMO
	bool es_aplicable_subida;	// VERDAD si son ciertas LAS DOS anteriores

	// Cálculos

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
	En el anterior código usamos dos estructuras equivalentes:
		if (es_aplicable_subida)
		......
		if (!es_aplicable_subida)
	pero logramos independizar los cómputos de la salida de datos,
	lo cual es muy importante.
	
	Si no lo hubiéranmos hecho así, el código sería: 
		
		if (es_aplicable_subida)
			ingresos = ingresos * 1.05;
		else
			cout << "No es aplicable la subida";
	
	cout << endl;
	cout << "Salario Final: " << ingresos;
	cout << endl;
			
	No es una buena solución mezclar cálculos y presentación de resultados.
	*/
	
	return 0;
}
