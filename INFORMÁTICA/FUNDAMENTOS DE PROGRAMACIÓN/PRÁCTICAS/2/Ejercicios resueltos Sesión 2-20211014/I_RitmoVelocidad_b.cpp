/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 1
/*	
   Programa que transforma ritmos expresados en km/h a min:seg/km
   
   Entradas: velocidad (en Km/h) 
   Salidas:  minutos y segundos (por Km)
*/
/***************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	const int MINS_HORA = 60; 
	const int SEGS_MIN  = 60; 
	const int SEGS_HORA = MINS_HORA*SEGS_MIN; 
	
	double velocidad;       // Entrada
	int segundos, minutos;  // Resultados

	cout << "Introduzca velocidad (km/h): ";
	cin >> velocidad;

	/*
		Soluci�n 1: Transformar a min/km, y de ah� a min:seg / km 

		x  [km/h] = x [km] / 60 [min] = x/60 [km/min] 
		
		Entonces, 1/(x/60)) [min/km] = 60/x [min/km]
	*/

	double minutos_reales_por_km = MINS_HORA / velocidad;
	
	cout << endl;
	cout << "Minutos/km = " << minutos_reales_por_km << " mins" << endl;

	minutos  = (int) floor (minutos_reales_por_km);
	segundos = (int) ((minutos_reales_por_km - minutos) * SEGS_MIN);

	cout << endl;
	cout << "Ritmo(1) = " << minutos  << " : " << segundos << " / km" << endl;
	cout << endl;

	/*
		Soluci�n 2: Transformar a segs/km, y despu�s ajustar esa cantidad a 
		            mins completos (el resto ser�n segundos)
		
		x km/h significa que en 1h se recorren x km (en 3600 s,  x km)
		
		�Cu�ntos segundos se han empleado en recorrer 1 km?
		
		3600 [s] / x [km] = 3600/x [s/km]
		 
		Entonces 3600/x ser�n los mins completos y 3600%x los segundos		
	*/
	
    int segundos_totales = SEGS_HORA/velocidad; // segundos/km
    
	// Ajustar a minutos completos y el resto ser�n segundos
	
    minutos  = segundos_totales / SEGS_MIN;
    segundos = segundos_totales % SEGS_MIN;

	cout << endl;
	cout << "Ritmo(2) = " << minutos  << " : " << segundos << " / km" << endl;
	cout << endl;

	return 0;
}
