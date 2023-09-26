/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 2
//
/* 	
	Programa que lee una serie indeterminada de matrícula, tipo de radar 
	('F' ó 'M') y velocidad captada. Calcula la máxima velocidad imputada. 
	La lectura finaliza cuando se lee 'FIN' como matrícula.
*/
/***************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
#include <string>  	 // Inclusión de los recursos para string

using namespace std; 

/***************************************************************************/
/***************************************************************************/

int main() // Programa Principal
{                 
	const double MIN_VELOCIDAD = 10.0; // Por debajo no capta
	
	const double UMBRAL_VELOCIDAD = 100.0;
   	const double PORC_MARGEN_FIJO = 5.0;	
	const double PORC_MARGEN_MOVIL = 7.0;		
   	const double KM_MARGEN_FIJO = 5.0;	
	const double KM_MARGEN_MOVIL = 7.0;	
	
	const string TERMINADOR = "FIN";
	
	string cad;
	 
	string matricula;
	char tipo_radar;
	double velocidad_leida;
	
	double velocidad_imputada;	
	double max_velocidad_imputada;

	int num_datos = 0;
	
	// Entrada de datos
	
	cout << "Introduzca matricula: " ;
	getline (cin, matricula);
   
	while (matricula != "FIN") {
		
		num_datos++;
   
		do {
			cout << "Introduzca tipo de radar: ";
			getline (cin, cad);
			tipo_radar = toupper(cad.at(0));
		} while ((tipo_radar != 'F') && (tipo_radar != 'M'));
	   
		do {
			cout << "Introduzca velocidad captada: " ;
			getline (cin, cad);
			velocidad_leida = stod(cad);
		} while (velocidad_leida < MIN_VELOCIDAD);
		
		// Cálculos

		bool radar_fijo = false;
		
		if (tipo_radar == 'F')	{
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
		
		// Salida: presentación de resultados 

		cout << endl;
		
		cout << "Matricula: " << matricula << endl;
		cout << "Radar: ";
		if (radar_fijo) 
			cout << "FIJO" << endl;
		else
			cout << "MOVIL" << endl;
		cout << "Velocidad leida: " << velocidad_leida << " Km/h" << endl;
		cout << "Velocidad imputada: " << velocidad_imputada << " Km/h"<< endl;
		cout << endl;
		
		
		// Actualización del máximo
		
		if (velocidad_imputada > max_velocidad_imputada)
			max_velocidad_imputada = velocidad_imputada;

	
		// Lectura adelantada
		
		cout << "Introduzca matricula: " ;
		getline (cin, matricula);
	
	} // while (matricula != "FIN") 
	
	
	// Mostrar la máxima velocidad imputada
	
	if (num_datos > 0) {
		
		cout << endl;		
		cout << "Maxima velocidad imputada: " 
		     << max_velocidad_imputada << " Km/h"<< endl;
		cout << endl;
	}

	return 0;
}

/***************************************************************************/
/***************************************************************************/
