/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 5 (Matrices)
//
	/*	
	Se dispone de un robot que se mueve en una línea, utilizando paso 
	de longitud fija. Inicialmente, el robot se ubica en la posición "pos", 
	siendo "pos" un valor entero positivo 1 <= pos <= 100.
	 
	El robot ejecuta una serie de órdenes, indicadas mediante un array "ord" 
	de tipo char, con longitud "lon". Cada orden es una letra 'I' o 'D', 
	indicando si el robot se mueve a la izquierda (decrementando la posición 
	actual "pos" en 1 unidad) o a la derecha (incrementando la posición actual 
	"pos" en 1 unidad). Las posiciones válidas del robot cumplen 
	1 <= pos <= 100. Se dice que una serie de órdenes es correcta si el 
	robot nunca se sale de las posiciones válidas.

	El programa lee la posición inicial del robot, "pos" y una lista de 
	órdenes en el string "cad_ord" (la longitud del string es "lon"). 
	Si la cadena de órdenes "cad_ord" contiene caracteres válidos ('I' o 'D') 
	traspasa esos caracteres al array "ord" para cumplir los requisitos del 
	problema y entonces:  
		* Si la serie de órdenes es correcta, muestra cuántas veces se 
		  visita cada posición. 
		* Si la serie de órdenes NO es correcta, el programa termina 
		  indicando cuántas órdenes se pudieron ejecutar.
*/
/*********************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/***************************************************************************/
/***************************************************************************/
	
// las posiciones se registran en un dato struct de tipo "PosicionTablero"

struct PosicionTablero {
	int f;
	int c; 
};
	
/***************************************************************************/
/***************************************************************************/

string ToString (PosicionTablero posicion)
{	
	return "["+to_string(posicion.f)+", "+to_string(posicion.c)+"]"; 
}


/***************************************************************************/
/***************************************************************************/

int main()
{
    cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales

	// "ord" es un array de char que contiene las órdenes que va a ejecutar 
	// el robot. Su capacidad se establece a "TAM_ORDENES" (valor arbitrario) 
	// pero el número de órdenes guardadas estará guardado en "lon"
	
	const int TAM_ORDENES = 200;
	char ord[TAM_ORDENES];
	int lon = 0; // 0 <= lon <= TAM_ORDENES

	
	// El array "posiciones_visitadas" guardará las posiciones válidas por 
	// las que ha pasado el robot. La primera, si es válida, ocupará la 
	// posición 0.
	PosicionTablero posiciones_visitadas[TAM_ORDENES+1];
	int util_posiciones_visitadas = 0; 
		
	
	// "num_visitas" es una matriz de contadores que guarda el número de 
	// veces que cada casilla ha sido visitada por el robot. 
	// Todas las casillas tienen un valor significativo (las no visitadas 
	// contienen un 0) por lo que NO hay una huecos (ni una variable que 
	// indique cuántas casillas contienen un valor válido).  
	
	const int NUM_FILAS = 10;
	const int NUM_COLS  = 10;
	int num_visitas[NUM_FILAS][NUM_COLS] = {0}; 
	// El num. de visitas a la posicion "pos" (f,c) se guarda en la 
	// casilla de coordenadas ("f"-1, "c"-1). 


	// Leer posición inicial ("pos"). Este valor deberá verificar: 
	// 		1 <= pos.f <= NUM_FILAS
	// 		1 <= pos.c <= NUM_COLS
	
	PosicionTablero pos;  
	
	string cad_valor;
	int valor; 
	
	do {
		do {
			cout << "Introduzca pos.inicial (fila): ";
			getline (cin, cad_valor);
		} while (cad_valor.length() == 0);
		
		valor = stoi(cad_valor);
		
		 // Salir solo si 1 <= valor <= NUM_FILAS 
	} while (valor<1 || valor>NUM_FILAS);

	pos.f = valor;	

	do {
		do {
			cout << "Introduzca pos.inicial (columna): ";
			getline (cin, cad_valor);
		} while (cad_valor.length() == 0);
		
		valor = stoi(cad_valor);
		
		 // Salir solo si 1 <= valor <= NUM_COLS 
	} while (valor<1 || valor>NUM_COLS);
	
	pos.c = valor;	
	
	// Podemos asegurar que "pos" (posición inicial) tiene una posición válida 
	
	
	// Leer "ordenes" y calcular "lon". 
	// Se verifica que todos los caracteres que se van a guardar en "ord" 
	// sean correctos: 'D','I','A' ó 'B'. Si es así, el número de órdenes 
	// ("lon") deberá verificar 1 <= lon <= TAM_ORDENES
	// Si hubiera alguna orden incorrecta, o el número de órdenes fuera 
	// fuera incorrecto, se volvería a leer la secuencia de órdenes.  
	
	string cad_ordenes;

	bool secuencia_ok;

	do {
		// Comprobar que la longitud de la cadena sea correcta, esto es, 
		// 1 <= lon <= TAM_ORDENES
		do {
			cout << "Introduzca secuencia de ordenes: ";
			getline (cin, cad_ordenes);
				
			// Calcular longitud (num. ordenes)  
			lon = cad_ordenes.length();
		
		} while (lon==0 || lon>TAM_ORDENES);
		
		secuencia_ok = true;
		
		// Comprobar que los caracteres son correctos
		int p=0;
		while (p<lon && secuencia_ok) {
			char orden_p = toupper(cad_ordenes.at(p));
			if (orden_p!='I' && orden_p!='D' && orden_p!='A' && orden_p!='B') 
				secuencia_ok = false;
			else p++;
		} 		
		
	} while (!secuencia_ok);
	
	// Copiar desde "cad" a "ord"
	for (int p=0; p<lon; p++) ord[p] = toupper(cad_ordenes.at(p));

	// Mostrar "pos", "ord" y "lon"
	
	cout << endl;
	cout << "------------------------" << endl;
	cout << endl;

	cout << "VALORES INICIALES" <<endl; 
	cout << endl;	
	cout << "Posicion inicial = " << ToString (pos) << endl;	
	cout << "Ordenes = ";
	for (int p=0; p<lon; p++) 
		cout << ord[p];
	cout << endl;
	cout << "Num. ordenes = " << setw(3) << lon << endl;
	
	cout << endl;
	cout << "------------------------" << endl;
	cout << endl;
	
	/***********************************************************************/
	// MOVIMIENTOS 	
	/***********************************************************************/
	// El robot empieza a moverse
	// En este punto:
 	//	1)  num_visitas[f][c]=0 para f = 0,1,2, ..., NUM_FILAS-1 y 
	//                               c = 0,1,2, ..., NUM_COLS-1
	//	2)	1 <= pos.f <= NUM_FILAS 
	//      1 <= pos.c <= NUM_COLS
	//	3) "ord" contiene "lon"  (<1 <= lon <= TAM_ORDENES ) valores 
	//      correctos ('D','I','A' ó 'B') 
	
	// Registrar primera visita, la de la posición inicial
	
	num_visitas[pos.f-1][pos.c-1]++;

	bool pos_ok = true; 
	int num_orden = 0;
	
	while (pos_ok && num_orden<lon) {
		
		if (ord[num_orden] == 'I') pos.c--;  // Izquierda
		else if (ord[num_orden] == 'D') pos.c++;  // Derecha
		else if (ord[num_orden] == 'A') pos.f++;  // Arriba
		else pos.f--;  // Abajo
		
		// Comprobar si la nueva posicion "pos" es correcta 
		// 1 <= pos.f <= NUM_FILAS 
		// 1 <= pos.c <= NUM_COLS
				
		if (1<=pos.f && pos.f<=NUM_FILAS && 1<=pos.c && pos.c<=NUM_COLS) {
			num_orden++;	// Actualizar núm. de órdenes correctas
			num_visitas[pos.f-1][pos.c-1]++; // Registrar nueva visita 
		}		
		else pos_ok = false;	// Para terminar
		
	} // while (pos_ok && num_orden<lon) 
	
	cout << "La serie de ordenes es : ";
	
	if (num_orden==lon) { // También if (pos_ok)
		cout << "correcta" << endl;
		cout << "Se ejecutaron " << setw(3) << num_orden << " ordenes"<< endl;		
 			
		cout << endl; 
 
 		// Números de columna
 		cout << "    :";
 		for (int c=0; c<NUM_COLS; c++) 
			cout << setw (4) << c+1;
		cout << endl; 
		cout << "    -";		
		for (int c=0; c<NUM_COLS; c++) 
			cout << "----";
		cout << "--" << endl; 
		
 		
 
 		// Cuerpo de la tabla
		for (int f=0; f<NUM_FILAS; f++) {
		
			// Número de fila
			cout << setw (3) << NUM_FILAS-f << " :";
			
			for (int c=0; c<NUM_COLS; c++) {
	
				if (num_visitas[NUM_FILAS-f-1][c] != 0) 
					cout <<setw(4)<< num_visitas[NUM_FILAS-f-1][c];
				else 
					cout << "   .";
				
			}
			
			cout << " : "<< setw (3) << NUM_FILAS-f;
			cout << endl; 
		}
		
 		// Números de columna
 		
 		cout << "    -";		
		for (int c=0; c<NUM_COLS; c++) 
			cout << "----";
		cout << "--" << endl; 	
 		cout << "    :";
 		for (int c=0; c<NUM_COLS; c++) 
			cout << setw (4) << c+1;
 		cout << endl; 
		
	}
	else {
		cout << "incorrecta" << endl;
		cout << "Se ejecutaron " << setw(3) << num_orden << " ordenes"<< endl;		
	}

	return 0;
}

/***************************************************************************/
/***************************************************************************/
