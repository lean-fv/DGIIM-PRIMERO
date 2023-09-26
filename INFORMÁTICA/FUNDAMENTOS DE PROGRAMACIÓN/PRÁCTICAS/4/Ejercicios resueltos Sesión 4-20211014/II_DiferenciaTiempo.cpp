/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 2
/*	
   Programa que calcula el número de segundos que han transcurrido entre dos
   instantes. Cada instante se caracteriza por la hora, minuto y segundo.
   los dos instantes pueden pertenecer a dos días consecutivos.
   
   NOTA:	Debe suponerse que los datos introducidos son correctos.
   
   Entradas: hora, minuto y segundo inicial, y hora, minuto y segundo final.
   Salidas:  número de segundos entre los dos instantes dados
*/
/***************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	const int SEGS_MIN   = 60;  // Segundos en un minuto
	const int MINS_HORA  = 60;	// Minutos en una hora
	const int HORAS_DIAS = 24;	// Horas en un día
	
	const int SEGS_HORA = MINS_HORA * SEGS_MIN; 	// Segundos en una hora
	const int SEGS_DIA  = HORAS_DIAS*SEGS_HORA;
			
	// Datos de entrada
	int hora_inic, minuto_inic, segundo_inic;
	int hora_fin,  minuto_fin,  segundo_fin;
	
	int num_segs_entre_instantes;  // Resultado


	// Entrada de datos
	
	cout << "Introduzca hora inicial:" << endl;
	cout << "\tHora:    ";
	cin >> hora_inic;
	cout << "\tMinuto:  ";
	cin >> minuto_inic;
	cout << "\tSegundo: ";
	cin >> segundo_inic;
           
    cout << "Introduzca hora final:" << endl;
	cout << "\tHora:    ";
	cin >> hora_fin;
	cout << "\tMinuto:  ";
	cin >> minuto_fin;
	cout << "\tSegundo: ";
	cin >> segundo_fin;
	
	
	// Cálculos 
	
	int segs_hora_inic, segs_hora_fin;
	segs_hora_inic = (hora_inic*SEGS_HORA)+(minuto_inic*SEGS_MIN)+segundo_inic;
	segs_hora_fin  = (hora_fin*SEGS_HORA) +(minuto_fin*SEGS_MIN) +segundo_fin;

	num_segs_entre_instantes = segs_hora_fin - segs_hora_inic;
	
	// CLAVE: Si el número de segundos es negativo significa que el instante 
	// inicial corresponde a un día anterior.
	
	
	// Solución 1 
	/* 	Se determina si pertenecen al mismo día o no en base al signo de la 
		diferencia. 
	*/
	
	bool cambio_dia = false;
	
	if (num_segs_entre_instantes < 0) {

		cambio_dia = true;
		
		// (SEGS_DIA - segs_hora_inic) + segs_hora_fin
		// SEGS_DIA - segs_hora_inic + segs_hora_fin
		// SEGS_DIA + (segs_hora_fin - segs_hora_inic)
		// SEGS_DIA + num_segs_entre_instantes

		num_segs_entre_instantes = SEGS_DIA + num_segs_entre_instantes;
	}

	// Resultado 1
	
	cout << endl;
	cout << "(1): Entre las " << hora_inic << ":" << minuto_inic
		 << ":" << segundo_inic << " y las " << hora_fin << ":"
		 << minuto_fin << ":" << segundo_fin << " hay "
		 << num_segs_entre_instantes << " segundos." << endl;
	cout << endl;
	
	if (cambio_dia) 
		cout << "Ha habido cambio de dia." << endl;		



	// Solución 2
	/* 	En primer lugar se calcula si los dos instantes pertenecen al mismo 
		día o no. Después, se calculan los segundos transcurridos en base 
		al primer resultado.  
	*/
	
	bool mismo_dia;
	
	if (hora_inic < hora_fin) mismo_dia = true;
	else 	
		if (hora_inic > hora_fin) mismo_dia = false;
		else  // hora_inic == hora_fin --> Minutos
			if (minuto_inic < minuto_fin) mismo_dia = true;
			else 
				if (minuto_inic > minuto_fin) mismo_dia = false;
				else // (hora_inic == hora_fin && 
					 //  minuto_inic == minuto_fin) --> Segundos
					if (segundo_inic < segundo_fin) mismo_dia = true;
					else 
						if (segundo_inic > segundo_fin) mismo_dia = false;
						else // (hora_inic == hora_fin && 
					 		 //  minuto_inic == minuto_fin && 
					 		 //  segundo_inic == segundo_fin) --> 0 segundos
							mismo_dia = true;
			
	if (!mismo_dia) 
		num_segs_entre_instantes = (SEGS_DIA - segs_hora_inic) + segs_hora_fin;
	
	
	// Resultado 2
	
	cout << endl;
	cout << "(2): Entre las " << hora_inic << ":" << minuto_inic
		 << ":" << segundo_inic << " y las " << hora_fin << ":"
		 << minuto_fin << ":" << segundo_fin << " hay "
		 << num_segs_entre_instantes << " segundos." << endl;
	cout << endl;
	
	if (!mismo_dia) 
		cout << "Ha habido cambio de dia." << endl;	
	
	
	return 0;
}
