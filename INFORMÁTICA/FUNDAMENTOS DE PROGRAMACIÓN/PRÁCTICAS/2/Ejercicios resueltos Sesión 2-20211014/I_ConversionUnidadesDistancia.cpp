/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 1
/*
	Programa que pide una longitud cualquiera dada en metros y calcula el
	equivalente de dicha longitud en pulgadas, pies, yardas y millas.
	
	1 pulgada= 25,4 milímetros
	1 yarda = 0,9144 metros
	1 pie = 30,48 centímetros 
	1 milla = 1609,344 metros
	
	Para poder realizar las conversiones podemos emplear dos alternativas:

	1)	mantener los factores dados y transformar la distancia leida (por 
		ejemplo, metros) a la unidad del SI que se necesita para la 
		conversión de acuerdo a la lista dada.  	
	 
	2) 	reescribir los factores de conversión para que se expresen en base a 
		la misma unidad (en la lista aparecen referidos a milímetros, 
		centímetros y metros), por ejemplo, en metros: 
			1 pulgada= 0,0254 metros
			1 yarda = 0,9144 metros
			1 pie = 0,3048 metros
			1 milla = 1609,344 metros

   Entradas: número de metros
   Salidas:  pulgadas, pies, yardas y millas equivalentes
*/
/***************************************************************************/

#include <iostream>
using namespace std;
 
/***************************************************************************/
/***************************************************************************/

int main()
{
	// Datos de entrada
	double metros;

	// Resultado
	double pulgadas, pies, yardas, millas;
	double pulgadas_m, pies_m, yardas_m, millas_m;
	
	// Factores de conversión (originales)
	
	const double MILIMETROS_POR_PULGADA = 25.4;
	const double PULGADAS_POR_MILIMETRO = 1.0 / MILIMETROS_POR_PULGADA;
	
	const double METROS_POR_YARDA = 0.9144;
	const double YARDAS_POR_METRO = 1.0 / METROS_POR_YARDA;
	
	const double CENTIMETROS_POR_PIE = 30.48;
	const double PIES_POR_CENTIMETRO = 1.0 / CENTIMETROS_POR_PIE;
	
	const double KILOMETROS_POR_MILLA = 1.609;
	const double MILLAS_POR_KILOMETRO = 1.0 / KILOMETROS_POR_MILLA;

	// Factores de conversión (en base a metros)
	
	const double METROS_POR_KILOMETRO = 1000;
	const double KILOMETROS_POR_METRO = 1.0 / METROS_POR_KILOMETRO;
	
	const double CENTIMETROS_POR_METRO = 100;
	const double METROS_POR_CENTIMETRO = 1.0 / CENTIMETROS_POR_METRO;
	
	const double MILIMETROS_POR_CENTIMETRO = 10;
	const double CENTIMETROS_POR_MILIMETRO = 1.0 / MILIMETROS_POR_CENTIMETRO;
	
	const double MILIMETROS_POR_METRO = 
	             CENTIMETROS_POR_METRO * MILIMETROS_POR_CENTIMETRO;
		
	const double METROS_POR_PULGADA = 
	             MILIMETROS_POR_PULGADA / MILIMETROS_POR_METRO;
	const double PULGADAS_POR_METRO = 1.0 / METROS_POR_PULGADA;
	
	// const double METROS_POR_YARDA = 0.9144;
	// const double YARDAS_POR_METRO = 1.0 / METROS_POR_YARDA;

	const double METROS_POR_PIE = CENTIMETROS_POR_PIE / CENTIMETROS_POR_METRO;
	const double PIES_POR_METRO = 1.0 / METROS_POR_PIE;
	
	const double METROS_POR_MILLA = KILOMETROS_POR_MILLA*METROS_POR_KILOMETRO;
	const double MILLAS_POR_METRO = 1.0 / METROS_POR_MILLA;


	// Entrada de datos

	cout << "Metros: ";
	cin >> metros;

	// Cálculos (originales)
	
	pulgadas = (metros * MILIMETROS_POR_METRO) * PULGADAS_POR_MILIMETRO;
	pies = (metros * CENTIMETROS_POR_METRO) * PIES_POR_CENTIMETRO;
	yardas = metros * YARDAS_POR_METRO;
	millas = (metros / METROS_POR_KILOMETRO) * MILLAS_POR_KILOMETRO;

	// Resultado

	cout << endl;
	cout << metros << " metros son: " << endl;	
	cout << "\t" << pulgadas << " pulgadas." << endl;
	cout << "\t" << pies << " pies." << endl;
	cout << "\t" << yardas << " yardas." << endl;
	cout << "\t" << millas << " millas." << endl;
	cout << endl;

	// Cálculos (en base a metros)

	pulgadas_m = metros* PULGADAS_POR_METRO;
	pies_m = metros * PIES_POR_METRO;
	yardas_m = metros * YARDAS_POR_METRO;
	millas_m = metros * MILLAS_POR_METRO;

	// Resultado

	cout << endl;
	cout << metros << " metros son: " << endl;	
	cout << "\t" << pulgadas_m << " pulgadas." << endl;
	cout << "\t" << pies_m << " pies." << endl;
	cout << "\t" << yardas_m << " yardas." << endl;
	cout << "\t" << millas_m << " millas." << endl;
	cout << endl;

	return 0;
}
/***************************************************************************/
/***************************************************************************/
