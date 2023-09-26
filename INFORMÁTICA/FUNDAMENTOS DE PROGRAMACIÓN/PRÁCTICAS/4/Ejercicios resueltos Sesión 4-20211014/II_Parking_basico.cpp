/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 2
/*	
	La tabla para el cálculo del precio a pagar en un parking es la siguiente:

	Desde el minuto 0 al 30 (CORTA): 0.0412 euros cada minuto
	Desde el minuto 31 al 90 (MEDIA): 0.0370 euros cada minuto
	Desde el minuto 91 al 120 (LARGA): 0.0311 euros cada minuto
	Desde el minuto 121 al 660 (MUY LARGA): 0.0305 euros cada minuto
	Desde el minuto 661 hasta máximo 24 horas (MAXIMA): 24.00 euros

	Dado una hora de entrada y otra de salida (ambas en horas y minutos)
	el programa calcula la tarifa final a cobrar.
	
	La hora de entrada puede pertenecer al día inmediatamente anterior.
	Se supone que NO transcurren más de 24 horas entre la hora de entrada y 
	la hora de salida.  
	
	NOTA: no se consideran los segundos

	Entradas: hora y minuto inicial
			  hora y minuto final.
	Salidas:  Cantidad a pagar
*/
/***************************************************************************/
 
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales
	
	// Constantes
	
	const int HORAS_DIA = 24;	
	const int MINS_HORA = 60;	
	const int MINS_DIA  = HORAS_DIA*MINS_HORA;
		
	const double CANT_CORTA     =  0.0412;
	const double CANT_MEDIA     =  0.0370;
	const double CANT_LARGA     =  0.0311;
	const double CANT_MUY_LARGA =  0.0305;
	const double CANT_MAX_DIA   = 24.0000; // 0.016 cent/min
	
	const int MINS_CORTA     =  30;
	const int MINS_MEDIA     =  90;
	const int MINS_LARGA     = 120;	
	const int MINS_MUY_LARGA = 660;

	/*
               30         90  	       120              660 
        0.0412     0.0370      0.0311          0.0305         24
     |---------|----------|------------|----------------|------------|      
        CORTA     MEDIA       LARGA        MUY_LARGA         PLANA
	*/
	
	
	// Datos de entrada
	int hora_inic, minuto_inic;
	int hora_fin, minuto_fin;
	
	
	bool hora_inic_ok = false; 
	bool hora_fin_ok  = false; 
	bool minuto_inic_ok = false; 
	bool minuto_fin_ok  = false; 
	bool datos_ok = false; 
	
	// Valores calculados
	
	int num_mins;	// Número de minutos en el parking

	double precio, suma_tramos;
	bool   tarifa_24h;	
			
	// Entrada de datos
	
	cout << "Introduzca hora inicial:" << endl;
	cout << "\tHora:    ";
	cin >> hora_inic;

	cout << "\tMinuto:  ";
	cin >> minuto_inic;

    cout << "Introduzca hora final:" << endl;
	cout << "\tHora:    ";
	cin >> hora_fin;		

	cout << "\tMinuto:  ";
	cin >> minuto_fin;
	
	// Comprobar la validez de los datos 
	
 	hora_inic_ok = (hora_inic >= 0 && hora_inic < HORAS_DIA);
	minuto_inic_ok = (minuto_inic >= 0 && minuto_inic < MINS_HORA);
	hora_fin_ok = (hora_fin >= 0 && hora_fin < HORAS_DIA);
 	minuto_fin_ok = (minuto_fin >= 0 && minuto_fin < MINS_HORA);	
		 		
	datos_ok = hora_inic_ok && hora_fin_ok && minuto_inic_ok && minuto_fin_ok; 
	   
		
	// Cálculos
	
	if (datos_ok) {
			
		// 1. Calcular número de minutos entre la entrada y la salida
		
		int mins_hora_inic = (hora_inic*MINS_HORA) + minuto_inic;
		int mins_hora_fin  = (hora_fin*MINS_HORA)  + minuto_fin;
	
		num_mins = mins_hora_fin - mins_hora_inic;
	
		//Calculamos si son de dias diferentes
		bool dia_diferente = (num_mins < 0);
		
		// Si el número de minutos es negativo significa que la hora de entrada
		// corresponde al día anterior
	
		if (dia_diferente) {
	
			// (MINS_DIA - mins_hora_inic) + mins_hora_fin
			// MINS_DIA - mins_hora_inic + mins_hora_fin
			// MINS_DIA + (mins_hora_fin - mins_hora_inic)
			// MINS_DIA + num_mins
	
			num_mins = MINS_DIA + num_mins;
		}

		/*
	               30         90  	       120              660 
	        0.0412     0.0370      0.0311          0.0305           24
	     |---------|----------|------------|----------------|--------------|      
	        CORTA     MEDIA       LARGA        MUY_LARGA         PLANA
		*/
		
		// El caso más simple es una larguísima permanencia --> precio único
		if (num_mins > MINS_MUY_LARGA) {
		
			suma_tramos = CANT_MAX_DIA;
			tarifa_24h = true;
		}
		else { // Calcular precio por tramo, desendentemente
	
			suma_tramos = 0; 
		
			int num_mins_quedan = num_mins;
	
			if (num_mins_quedan > MINS_LARGA){
				suma_tramos += (num_mins_quedan-MINS_LARGA)*CANT_MUY_LARGA;
				num_mins_quedan =  MINS_LARGA;
			}
			if (num_mins_quedan > MINS_MEDIA){
				suma_tramos += (num_mins_quedan-MINS_MEDIA)*CANT_LARGA;
				num_mins_quedan = MINS_MEDIA;
			}
			if (num_mins_quedan > MINS_CORTA){
				suma_tramos += (num_mins_quedan-MINS_CORTA)*CANT_MEDIA;
				num_mins_quedan =  MINS_CORTA;
			}
			if (num_mins_quedan > 0)
				suma_tramos += num_mins_quedan*CANT_CORTA;			
		}
	}
	

	//Salida de resultados

	if (datos_ok) {
	
		// El precio final se ajusta (trunca) a dos decimales 
		precio = trunc(suma_tramos*100) / 100; 
	
		cout << endl;
		cout << "Minutos de estancia = " << num_mins << endl;
		cout << "Tarifa =  "<< setw(7) << setprecision(4) << suma_tramos 
		     << " E  ---> "<< setw(7)<< setprecision(2)<< precio<< " E"<< endl;
		cout << endl;
		
		if (tarifa_24h)
			cout << "\tSe ha aplicado tarifa maxima." << endl;
			
	}
	else { // !datos_ok
	
		if (!hora_inic_ok) {
			cout << endl; 
			cout << "ERROR: Hora inicial incorrecta."<< endl; 
			cout << endl; 
		}
		if (!minuto_inic_ok) {
			cout << endl; 
			cout << "ERROR: Minuto inicial incorrecto."<< endl; 
			cout << endl; 
		}
		if (!hora_fin_ok) {
			cout << endl; 
			cout << "ERROR: Hora final incorrecta."<< endl; 
			cout << endl; 
		} 
		if (!minuto_fin_ok) {
 			cout << endl; 
			cout << "ERROR: Minuto final incorrecto."<< endl; 
			cout << endl; 	
		}	 
	}
	
	return 0;	
}
