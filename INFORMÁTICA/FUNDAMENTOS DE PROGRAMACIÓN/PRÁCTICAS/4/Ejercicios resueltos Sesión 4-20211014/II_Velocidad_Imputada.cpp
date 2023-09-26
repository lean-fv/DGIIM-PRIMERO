/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 2 
//
/* 	Programa que calcula la velocidad imputada, de acuerdo a la velocidad 
	captada por un radar y al tipo de radar (fijo ó móvil)
	
		Detalles: ver enunciado.
*/
/***************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S

using namespace std; 


int main() // Programa Principal
{                 
	const double MIN_VELOCIDAD = 10.0; // Por debajo no capta
	
	const double UMBRAL_VELOCIDAD = 100.0;
   	const double PORC_MARGEN_FIJO = 5.0;	
	const double PORC_MARGEN_MOVIL = 7.0;		
   	const double KM_MARGEN_FIJO = 5.0;	
	const double KM_MARGEN_MOVIL = 7.0;	
	
	char tipo_radar;
	double velocidad_leida;
	double velocidad_imputada;	
	
	bool error_velocidad = false;
	bool radar_fijo = false;
			
   // Entrada de datos
   
   cout << "Introduzca tipo de radar y velocidad leida: " ;
   cin >> tipo_radar >> velocidad_leida;
   	
	if (velocidad_leida < MIN_VELOCIDAD) {
		
		error_velocidad = true;
		cout << "Error: la velocidad leida debe ser mayor o igual que " 
			 << MIN_VELOCIDAD << endl;		
	}
	else {
		
		// Cálculos
		
		if (toupper(tipo_radar) == 'F')	{
			radar_fijo = true; 
		}	
		
		double margen;
							
		if (velocidad_leida <= UMBRAL_VELOCIDAD) {
		
			if (radar_fijo) margen = KM_MARGEN_FIJO;
			else margen = KM_MARGEN_MOVIL;	
			
			velocidad_imputada = velocidad_leida - margen;
			
		}
		else { // velocidad_leida > UMBRAL_VELOCIDAD

			if (radar_fijo) margen =  PORC_MARGEN_FIJO;
			else margen =  PORC_MARGEN_MOVIL;
			
			velocidad_imputada = velocidad_leida * (1 - margen/100);
		}
		
	}
	
	
	// Salida: presentación de resultados 

	if (!error_velocidad) {
		cout << endl;
		cout << "Velocidad leida: " << velocidad_leida << " Km/h" << endl;
		cout << "Velocidad imputada: " << velocidad_imputada << " Km/h" << endl;
		cout << endl;
	}
	
	return 0;
}
