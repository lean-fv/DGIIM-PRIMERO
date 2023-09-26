/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 3
/*	
	Nueva versión del problema del Parking usando funciones. 

	La tabla para el cálculo del precio a pagar en los parkings
	de Madrid para el 2015 es la siguiente:

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
using namespace std;

// Constantes globales

const int MINS_HORA = 60;	// Minutos en una hora
const int HORAS_DIA = 24;	// Horas en un día
const int MINS_DIA  = HORAS_DIA*MINS_HORA; // Minutos en un dia
	
/***************************************************************************/
// Lee una hora válida
//
// Recibe: msg, etiqueta para acompañar la lectura
// Devuelve: una hora válida
//
// POST: el valor devuelto (hora) cumple 0 <= hora < HORAS_DIA

int LeeHora (string msg)
{
	int hora; 
	
	do {
		cout << msg;
		cin >> hora;
	} while ((hora<0) || (hora>=HORAS_DIA)); 
	
	return (hora);
}	

/***************************************************************************/
// Lee un minuto válido
//
// Recibe: msg, etiqueta para acompañar la lectura
// Devuelve: un minuto válido
//
// POST: el valor devuelto (minuto) cumple 0 <= minuto < MINS_HORA

int LeeMinuto (string msg)
{
	int minuto; 
		
	do {
		cout << msg;
		cin >> minuto;
	} while ((minuto<0) || (minuto>=MINS_HORA)); 
	
	return (minuto);
}		

/***************************************************************************/
// Calcular número de minutos entre la entrada y la salida. 
//
// Recibe: h_inic y m_inic, hora y minuto del instante inicial
//         h_fin y m_fin, hora y minuto del instante final
// Devuelve: número de minutos entre los (h_inic, m_inic) y (h_fin, m_fin)
// 
// NOTA: Los instantes inicial y final pueden ser de dos días consecutivos. 
// PRE: No transcurren más de 24 horas entre los dios instantes.

int NumMinutos (int h_inic, int m_inic, int h_fin, int m_fin) 
{
	int mins_hora_inic = (h_inic*MINS_HORA) + m_inic;
	int mins_hora_fin  = (h_fin*MINS_HORA)  + m_fin;

	int num_mins = mins_hora_fin - mins_hora_inic;
	
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
	
	return (num_mins);	
}	

/***************************************************************************/
// Calcular tarifa de acuerdo al número de minutos de estancia y los precios 
// establecidos por tramo. 
//
// Recibe: num_mins, minutos que ha permanecido en el parking.
// Devuelve: Cantidad a pagar.

double CalcularTarifa (int num_mins) 
{
	// Constantes relacionadas con los tramos de estancia: 

	// 1) Precio por minuto en tramo:
	const double CANT_CORTA     =  0.0412;
	const double CANT_MEDIA     =  0.0370;
	const double CANT_LARGA     =  0.0311;
	const double CANT_MUY_LARGA =  0.0305;
	const double CANT_MAX_DIA   = 24.0000;
	
	// 2) Minutos de cada tramo:
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


	double precio; // valor a calcular
	
	// El caso más simple es una larguísima permanencia --> precio único
	if (num_mins > MINS_MUY_LARGA) {
	
		precio = CANT_MAX_DIA;
	}
	else { // Calcular precio por tramo, descendentemente
	
		precio = 0; 
		int num_mins_quedan = num_mins;

		if (num_mins_quedan > MINS_LARGA){
			precio = precio + (num_mins_quedan-MINS_LARGA)*CANT_MUY_LARGA;
			num_mins_quedan =  MINS_LARGA;
		}
		if (num_mins_quedan > MINS_MEDIA){
			precio = precio + (num_mins_quedan-MINS_MEDIA)*CANT_LARGA;
			num_mins_quedan = MINS_MEDIA;
		}
		if (num_mins_quedan > MINS_CORTA){
			precio = precio + (num_mins_quedan-MINS_CORTA)*CANT_MEDIA;
			num_mins_quedan =  MINS_CORTA;
		}
		if (num_mins_quedan > 0)
			precio = precio + num_mins_quedan*CANT_CORTA;			
	}

	return (precio);
}
	
/***************************************************************************/

int main()
{
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales
	
	// Datos de entrada (hora y minuto de llegada, hora y minuto de salida)
	
	int hora_inic, minuto_inic;
	int hora_fin, minuto_fin;
	
	// Valores calculados
	
	int num_mins;	// Número de minutos en el parking
	double precio;	// Precio final -total- a pagar 
	
	
			
	// Entrada de datos
	
	// Hora de llegada
	
	cout << "Introduzca hora de llegada:" << endl;

	hora_inic   = LeeHora   ("\tHora:    ");
	minuto_inic = LeeMinuto ("\tMinuto:    ");
		
	// Hora de salida
	
	cout << "Introduzca hora de salida:" << endl;

	hora_fin   = LeeHora   ("\tHora:    ");
	minuto_fin = LeeMinuto ("\tMinuto:    ");

		
		
	// Cálculos

	// 1. Calcular número de minutos entre la entrada y la salida
	
	num_mins = NumMinutos (hora_inic, minuto_inic, hora_fin, minuto_fin); 
	
	// 2. Calcular precio 

	precio = CalcularTarifa (num_mins); 
	


	// Salida de resultados

	cout << endl;
	cout << "Tarifa final =  "<< setw(6)<< setprecision(2)<< precio <<endl;
	cout << endl;
	cout << "Minutos de estancia = " << num_mins << endl;
	cout << endl;		

	return 0;
}
