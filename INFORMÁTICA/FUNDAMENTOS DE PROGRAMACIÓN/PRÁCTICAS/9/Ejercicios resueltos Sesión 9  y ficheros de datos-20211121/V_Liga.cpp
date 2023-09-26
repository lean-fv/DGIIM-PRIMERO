/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 5 (Matrices)
//
/*	
	Para gestionar un campeonato de "n" equipos se utiliza una matriz 
	cuadrada. En cada casilla  se puede almacenar uno de tres valores: 
	'1', 'X' ó '2'. La casilla (f, c) contendrá un valor que representa 
	el resultado del partido entre "f" y "c":  si vale '1' indica que ha 
	ganado "f", si vale 'X' han empatado y si vale '2' ha ganado "c".

	Suponga las declaraciones para una liga de 5 equipos: 
		const int NUM_EQUIPOS = 5;
		char liga[NUM_EQUIPOS][NUM_EQUIPOS];

	Dados dos equipos, "f" y "c", habrá dos partidos: uno en el que se 
	enfrentan "f" y "c" (el equipo local es "f") y el recíproco, de "c" 
	contra "f" (el equipo local es "c"). Además, el valor de la diagonal 
	no se usa, ya que un equipo no se enfrenta a sí mismo.

	Los puntos se contabilizan, para cada equipo, como sigue: una victoria 
	implica 3 puntos, un empate 1 punto, y una derrota 0 puntos. 

	Este programa lee el contenido de la matriz "liga" y calcula la 
	clasificación final del campeonato.
*/
/***************************************************************************/

#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

/***************************************************************************/
/***************************************************************************/

int main()
{
    cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales

    // Declarar e inicializar la matriz "liga"

	const int MAX_EQUIPOS = 30;	
	
	char liga[MAX_EQUIPOS][MAX_EQUIPOS] = {' '};	
    int num_equipos; 
    
    /***********************************************************************/
   	// LECTURA DE DATOS  (la lectura debería hacerse por redirección)
    /***********************************************************************/

    // 2 <= num_equipos <= MAX_EQUIPOS
   	cin >> num_equipos; 

	// liga[f][c] debe ser '1', 'X' ó '2'
	
	for (int f=0; f<num_equipos; f++) 
		for (int c=0; c<num_equipos; c++) 
			if (f!=c) cin >> liga[f][c];
	
    
	// Presentación de los datos leidos (num.equipos y matriz)
	
	cout << endl; 
	cout << "Num. equipos = " << setw(3) << num_equipos << endl; 
	cout << endl; 
	
	// Números de columna
	cout << "     ";
	for (int c=0; c<num_equipos; c++) 
		cout << setw (4) << c+1;
	cout << endl; 
	cout << "    -";		
	for (int c=0; c<num_equipos; c++) 
		cout << "----";
	cout << "--" << endl; 

	// Cuerpo de la tabla
	for (int f=0; f<num_equipos; f++) {
	
		// Número de fila
		cout << setw (3) << f+1 << " :";
		
		for (int c=0; c<num_equipos; c++) {
			cout <<setw(4)<< liga[f][c];
		}
		cout << endl; 
	}
   
    
    /***********************************************************************/
	// CALCULOS     
    /***********************************************************************/
    
    // Declarar e inicializar el array "resumen"
    struct InfoPuntos {
    	int num_equipo; 	// 1 <= num_equipo <= num_equipos
    	int puntos_equipo;  // 0 <= puntos_equipo
	};
	InfoPuntos resumen[MAX_EQUIPOS]; 
    int total_utilizados_resumen = num_equipos; 
	
	for (int pos=0; pos<total_utilizados_resumen; pos++) {
		resumen[pos].num_equipo = pos+1;
    	resumen[pos].puntos_equipo = 0;
	}	
	
	// Calcular los puntos de cada equipo
	
	for (int local=0; local<num_equipos; local++) {

		for (int visitante=0; visitante<num_equipos; visitante++) {
			
			switch (liga[local][visitante]) {
				case ('1') : // victoria local
					resumen[local].puntos_equipo+= 3;
					break;
				case ('X') : // empate
					resumen[local].puntos_equipo++;
					resumen[visitante].puntos_equipo++;					
					break;
				case ('2') : // victoria visitante
					resumen[visitante].puntos_equipo+= 3;				
					break;
			} // switch
		} // for visitante
	} // for local
	
	
    /***********************************************************************/
	// RESULTADOS     
    /***********************************************************************/
    
	cout << endl; 
	cout << "PUNTOS" << endl; 	
	cout << "--------------" << endl; 		
	cout << endl; 
	
	for (int pos=0; pos<total_utilizados_resumen; pos++) 
		cout << "EQUIPO " << setw(2) << pos+1 << ": " 
		     << setw(3) << resumen[pos].puntos_equipo << endl;
	cout << endl; 
		
	// Ordenación decreciente (p.e. por el método de intercambio "burbuja") 
	// según el valor de "puntos_equipo"
	
	for (int izda = 0; izda < total_utilizados_resumen; izda++) {
	
		for (int i = total_utilizados_resumen-1 ; i > izda ; i--)

			// ¿ Intercambiar ?	
			if (resumen[i].puntos_equipo > resumen[i-1].puntos_equipo){ 
				InfoPuntos intercambia = resumen[i];
				resumen[i] = resumen[i-1];
				resumen[i-1] = intercambia;
			}
	}
		
	cout << endl; 
	cout << "CLASIFICACION" << endl; 	
	cout << "--------------" << endl; 		
	cout << endl; 
		
	for (int pos=0; pos<total_utilizados_resumen; pos++) 
		cout << "EQUIPO " << setw(2) << resumen[pos].num_equipo  << ": " 
		     << setw(3) << resumen[pos].puntos_equipo << endl;
	cout << endl; 	
	
    	
	return 0;
}

/***************************************************************************/
/***************************************************************************/
