/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 2
//
/*	
	Este sencillo programa controla los tiempos que emplean los corredores 
	de una carrera popular.
	El programa empieza pidiendo la hora de inicio de la carrera 
	(hora, minuto y segundo) y la distancia.
	Después, para cada corredor que llega a meta (por orden de llegada) se 
	pide el número de dorsal y la hora de llegada (hora, minuto y segundo). 
	--> Se commprueba (y filtra) que los datos de los corredores se introducen 
		según orden de llegada. 
	Tras leer estos datos el programa muestra el tiempo que ha empleado 
	en completar la carrera (horas, minutos y segundos) y su ritmo (en km/h 
	y en minutos/km).

	El programa finaliza cuando al solicitar el número de dorsal se introduce 
	un valor negativo.
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/***************************************************************************/
/***************************************************************************/

int main()
{
	const int SEGS_MIN   = 60;  // Segundos en un minuto
	const int MINS_HORA  = 60;	// Minutos en una hora
	const int HORAS_DIAS = 24;	// Horas en un día
	
	const int SEGS_HORA = MINS_HORA * SEGS_MIN; 	// Segundos en una hora
	const int SEGS_DIA  = HORAS_DIAS*SEGS_HORA;
	
	
	// Datos de la carrera
	int hora_inicio_carrera; 
	int minuto_inicio_carrera; 
	int segundo_inicio_carrera; 

	double distancia; 	
	

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);

	// Entrada de datos de la carrera (con filtros)
	
	cout << "Introduzca hora de inicio de la carrera:" << endl;

	do {
		cout << "\tHora:    ";
		cin >> hora_inicio_carrera;
	} while ((hora_inicio_carrera<0) || (hora_inicio_carrera>=HORAS_DIAS)); 
	
	do {
		cout << "\tMinuto:  ";
		cin >> minuto_inicio_carrera;
	} while ((minuto_inicio_carrera<0) || (minuto_inicio_carrera>=MINS_HORA)); 
	
	do {
		cout << "\tSegundo: ";
		cin >> segundo_inicio_carrera;
	} while ((segundo_inicio_carrera<0) || (segundo_inicio_carrera>=SEGS_MIN)); 

	int segs_instante_inicio = (hora_inicio_carrera*SEGS_HORA) 
	               + (minuto_inicio_carrera*SEGS_MIN) + segundo_inicio_carrera;
		
		
	cout << endl; 	
	cout << "Introduzca distancia de la carrera:" << endl;
	
	do {
		cout << "\tDistancia: ";
		cin >> distancia;
	} while (distancia<=0); 

	
	// Datos de cada corredor
	
    int dorsal;
    
	int hora_llegada; 
	int minuto_llegada; 
	int segundo_llegada; 

	// Número de segundos desde las 0:0:0 ... 	
	int segs_instante_llegada; // ... del corredor actual
	int segs_instante_llegada_ant; // ... del corredor anterior
	
	// Diferencia de segundos entre dos instantes 
	int segs_entre_instantes; 
	
	
	// Tiempo del corredor (ficticio) previa al primero. 
	// Debemos asegurar que el tiempo del primero sea supperior o igual 
	// a su valor y 0 (o menos) es un valor apropiado. 
	segs_instante_llegada_ant = 0;
	
	cout << endl; 
	cout << "----------------------------------" << endl; 
	cout << endl; 
	
	cout << "Dorsal: " ;
	cin >> dorsal; 
	
	while (dorsal >= 0) {
			
		// Banderas para la corrección de la hora de llegada del corredor.
		// Tendrán el valor "truue" si la hora de llagad del corerdor es: 
		
		bool es_hora_llegada_ok; 		// posterior a la salida
		bool es_hora_llegada_ordenada; 	// posterior (o igual) a la del 
										// corredor anterior
		
		// Pedir hora de llegada y filtrarla adecuadamente
		
		do {  
		 
			cout << endl;
				
			do {
				cout << "\tHora:    ";
				cin >> hora_llegada;
			} while ((hora_llegada<0) || (hora_llegada>=HORAS_DIAS)); 
			
			do {
				cout << "\tMinuto:  ";
				cin >> minuto_llegada;
			} while ((minuto_llegada<0) || (minuto_llegada>=MINS_HORA)); 
			
			do {
				cout << "\tSegundo: ";
				cin >> segundo_llegada;
			} while ((segundo_llegada<0) || (segundo_llegada>=SEGS_MIN)); 
					
			segs_instante_llegada = (hora_llegada*SEGS_HORA) 
	               + (minuto_llegada*SEGS_MIN) + segundo_llegada;

			segs_entre_instantes = segs_instante_llegada-segs_instante_inicio;
			
			// Comprobar si la hora de llegada es posterior a la de salida			
			es_hora_llegada_ok =  (segs_entre_instantes >= 0);
			
			if (!es_hora_llegada_ok) { // hora de llegada incorrecta
				cout << endl;
				cout << "\t--> Llegada previa a salida." << endl;				
			}
			
			// Comprobar si la hora de llegada es posterior o igual a 
			// la hora de llegada del corredor anterior.	
			es_hora_llegada_ordenada = 
			     (segs_instante_llegada >= segs_instante_llegada_ant);

			if (!es_hora_llegada_ordenada) { // hora de llegada desordenada
				cout << endl;
				cout << "\t--> Llegada previa al anterior." << endl;
			}
		
		} while (!es_hora_llegada_ok || !es_hora_llegada_ordenada);
		
		// En este punnto aseguramos que la hora de llegada del corredor 
		// actual es correcta (0<=h<24, 0<=m<60, 0<=s<60) y que es posterior 
		// a la hora de salida y a la hora de llegada del corrredor anterior. 
		
		//...................................................................
		// Velocidad en Km/h
		
		double velocidad;       
		double minutos;  
		
		minutos  = segs_entre_instantes / static_cast<double>(SEGS_MIN);
				
		cout << endl; 
		cout << "\tSegundos: " << setw(6) << segs_entre_instantes << endl;
		cout << "\tMinutos:  " << setw(6) << setprecision(3) << minutos << endl;

		// La solucion es una sencilla regla de tres:
		// 		minutos ---------> distancia Km \
		// 		60.0 minutos ---->         x Km / x = (60.0*distancia)/minutos 

		velocidad = (MINS_HORA*distancia) / minutos;
		
		cout << endl;
		cout << "\tVelocidad = " << velocidad << " Km/h" << endl;
			
		
		//...................................................................
		// Velocidad en min/Km (mins:segs / Km)
			
		/*
		x km/h = x km/60 min = x/60 km/min --> 1/(x/60)) min/km = 60/x min/km
		*/
	
		double minutos_reales_por_km = static_cast<double>(MINS_HORA)/velocidad;
		
		int mins_ritmo = (int) floor (minutos_reales_por_km);
		int segs_ritmo = (int) ((minutos_reales_por_km-mins_ritmo)*SEGS_MIN);
	
		cout << "\tRitmo = " << setw(2) << mins_ritmo  << ":" 
		     << setw(2) << segs_ritmo << " / km";
		cout << " (" << setw(5) << setprecision(2) << minutos_reales_por_km 
		     << " Minutos/km)" << endl;
		cout << endl;		

		
		//...................................................................
		// Para la siguiente iteración, el corredor actual será el anterior 
			
		segs_instante_llegada_ant = segs_instante_llegada; 
			
		// Lectura del siguiente corredor
		
		cout << endl; 
		cout << "Dorsal: " ;
		cin >> dorsal; 
	}	
	
	return 0;
}

/***************************************************************************/
/***************************************************************************/
