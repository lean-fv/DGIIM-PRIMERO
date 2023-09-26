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


	// Entrada de datos y comprobación de la validez de los mismos
	
	/*	Sugiero dos estrategias: 
	
	 	1. Comprobación individualizada de datos
	
			Podría comprobarse la validez de cada dato independientemente de 
			los demás, de manera que 1) se pasara a leer el siguiente dato solo 
			cuando se compruebe la validez del anterior, o 2) se acabara la 
			ejecución al detectar una entada erronea. 
			
			Si tenemos en cuanta que se van a leer 6 datos, esta solución 
			produce un código con mucha indentación: 
		
			Lee hora_inic
			Si es correcta hora_inic
			
				Lee minuto_inic
				Si es correcto minuto_inic
				......
				si-no
					error_minuto_inic <-- VERDAD
			si-no
				error_hora_inic <-- VERDAD
			
			 
			error_datos = (error_minuto_inic || error_hora_inic || ...)
			
			Si (!error_datos) 
			
				CALCULAR DIFERENCIA DE TIEMPO
				
			si-no
				Procesar errores
	
		2. Comprobación por bloques de datos
		
			Haremos dos comprobaciones únicamente, y secuenciales: 1) instante 
			inicial-completo-, y (si procede) 2) instante final-completo-. 
			Si se detecta que el primer instante tiene algún dato incorrecto, 
			se termina la ejecución. Si no, se piden los datos del instante 
			final y si se detecta que el tiene algún dato incorrecto, se 
			termina la ejecución.
			
			Adoptaremos esta estrategia para la solución, por simplicidad. 
	*/
	
	// Banderas para controlar la corrección de los instantes leídos
	bool instante_inic_mal; // Corrección del instante inicial
	bool instante_fin_ok;   // Corrección del instante final
	
	bool instantes_ok = false;	// Corrección de los dos instantes
	
	
	cout << "Introduzca hora inicial:" << endl;
	cout << "\tHora:    ";
	cin >> hora_inic;
	cout << "\tMinuto:  ";
	cin >> minuto_inic;
	cout << "\tSegundo: ";
	cin >> segundo_inic;
    
	bool hora_inic_mal     = ((hora_inic<0) || (hora_inic>=HORAS_DIAS));
	bool minuto_inic_mal   = ((minuto_inic<0) || (minuto_inic>=MINS_HORA));
	bool segundo_inic_mal  = ((segundo_inic<0) || (segundo_inic>=SEGS_MIN));
	
	instante_inic_mal = (hora_inic_mal||minuto_inic_mal||segundo_inic_mal);
	       	
    if (!instante_inic_mal) {
    
		// En este punto, instante_inicial_mal==false
			
	    cout << "Introduzca hora final:" << endl;
		cout << "\tHora:    ";
		cin >> hora_fin;
		cout << "\tMinuto:  ";
		cin >> minuto_fin;
		cout << "\tSegundo: ";
		cin >> segundo_fin;
		
		bool hora_fin_ok     = ((hora_fin>=0) && (hora_fin<HORAS_DIAS));
		bool minuto_fin_ok   = ((minuto_fin>=0) && (minuto_fin<MINS_HORA));
		bool segundo_fin_ok  = ((segundo_fin>=0) && (segundo_fin<SEGS_MIN));
		
		instante_fin_ok = (hora_fin_ok && minuto_fin_ok && segundo_fin_ok);
   	
   		instantes_ok = instante_fin_ok;

	}

	if (instantes_ok) {
		
		// Aquí, 1) instante_inicial_mal==false, y 2) instante_fin_ok==true
		
		// Cálculos
	   			
		/* 	En primer lugar se calcula si los dos instantes pertenecen al 
			mismo día o no. Después, se calculan los segundos transcurridos 
			en base al primer resultado.  
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
							if (segundo_inic>segundo_fin) mismo_dia=false;
							else // (hora_inic == hora_fin && 
						 		 //  minuto_inic == minuto_fin && 
						 		 //  segundo_inic == segundo_fin)--> 0 segs
								mismo_dia = true;
				
		int segs_hora_inic, segs_hora_fin;
		
		segs_hora_inic = (hora_inic * SEGS_HORA) + (minuto_inic * SEGS_MIN)
		                 + segundo_inic;
		segs_hora_fin  = (hora_fin * SEGS_HORA) + (minuto_fin * SEGS_MIN) 
		                 + segundo_fin;
		
		if (mismo_dia) 
			num_segs_entre_instantes = segs_hora_fin - segs_hora_inic;
		else 
			num_segs_entre_instantes = (SEGS_DIA - segs_hora_inic) 
			                           + segs_hora_fin;
		
		
		// Resultado 
		
		cout << endl;
		cout << "Entre las " << hora_inic << ":" << minuto_inic
			 << ":" << segundo_inic << " y las " << hora_fin << ":"
			 << minuto_fin << ":" << segundo_fin << " hay "
			 << num_segs_entre_instantes << " segundos." << endl;
		cout << endl;
		
		if (mismo_dia) 
			cout << "Los dos instantes son del mismo dia." << endl;	
		else 
			cout << "Ha habido cambio de dia." << endl;	
		
		cout << endl;
		
	} // if (instantes_ok) 
		
	else { // instantes_ok == false
		
		/* 	El valor de instantes_ok empieza siendo false (se declara y se 
			inicializa a false.
			
			1) 	Si instante_inic_mal==true, !instante_inic_mal==false --> no 
				se piden los valores del instante final y se mantiene el valor 
				de instantes_ok (false).
			
			2) 	Si instante_inic_mal==false, !instante_inic_mal==true --> se 
				piden los valores del instante final y el resultado de 
				instantes_ok será el de instante_fin_ok (recuerde que 
				instante_inic_mal==false) 	
		*/
	
		// Comprobar qué instante es incorrecto e informar
		
		if (instante_inic_mal) {	
			cout << endl;
			cout << "Error: la hora inicial esta mal especificada." << endl;
			cout << endl;	    	
	    }
		else { // instante_inicial_mal==false && instante_fin_ok==false
	
			cout << endl;
			cout << "Error: la hora final esta mal especificada." << endl;
			cout << endl;	    	    	
	    }

	} // else de if (instantes_ok)
	
	return 0;
}
