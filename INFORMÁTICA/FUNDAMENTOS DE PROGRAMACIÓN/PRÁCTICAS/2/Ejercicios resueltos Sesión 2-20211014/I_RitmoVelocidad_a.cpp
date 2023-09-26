/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 1
/*	
   Programa que transforma ritmos expresados en min:seg/km a km/h
   
   Entradas: minutos y segundos (por Km)
   Salidas:  velocidad (en Km/h)
*/
/***************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	const int MINS_HORA = 60; 
	const int SEGS_MIN = 60; 
	const int SEGS_HORA = MINS_HORA*SEGS_MIN; 
	
	int segundos, minutos; 	// Entradas
	double velocidad;       // Resultado
	
	cout << "Introduzca el ritmo (en mins:segs por km): " << endl;
	cout << "\tIntroduzca minutos: ";
	cin >> minutos;
	cout << "\tIntroduzca segundos: ";
	cin >> segundos;
           
           
    // Versi�n 1. Pasar a segundos(totales)/km y km/h
		      
    int segundos_totales = segundos + minutos*SEGS_MIN; // Segundos(totales)/km
    
	cout << endl;
	cout << "Segundos totales por km = " << segundos_totales << endl;   
    
	velocidad = ((double)SEGS_HORA) / segundos_totales; // [h^(-1) -->  km/h] 
         
   	cout << endl;
	cout << "Velocidad = " << velocidad << " Km/h" << endl;
        
		           
    // Versi�n 2. Pasar a minutos(totales)/km y km/h
           
	double minutos_totales  = (((double)segundos) / SEGS_MIN) + minutos;

	cout << endl;
	cout << "Minutos totales por km = " << minutos_totales << endl;

	velocidad = MINS_HORA / minutos_totales; // [h^(-1) -->  km/h] 
		
	cout << endl;
	cout << "Velocidad = " << velocidad << " Km/h" << endl;

	cout << endl;

	return 0;
}
