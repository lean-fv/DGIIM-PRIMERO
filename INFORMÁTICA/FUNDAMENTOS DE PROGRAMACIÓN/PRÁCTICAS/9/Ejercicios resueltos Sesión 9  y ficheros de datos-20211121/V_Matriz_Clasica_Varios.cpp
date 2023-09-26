/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 5 (Matrices)
//
/* 
	Programa que lee las dimensiones de una matriz, lee los valores que 
	se almacenan y realiza diversas operaciones sonbre ella: 

	1) Calcula la traspuesta de la matriz, guardando el resultado en otra
	matriz (siempre que sea posible).
	2) Multiplica dos matrices: Lee los datos de otra matriz 
	(incluidas sus dimensiones) que tenga la misma capacidad, las 
	multiplica y guarda el resultado en otra matriz.
	NOTA: Siempre que sea posible efectuar la multiplicación).
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define LECTURA

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 

	/***********************************************************************/
	// Declaraciones 
	
	
	// Matriz básica para los dos apartados 
	
	const int MAX_FILAS = 20;
	const int MAX_COLS =  30;
	int matriz_original [MAX_FILAS][MAX_COLS];
	
	int filas_utilizadas_matriz_original = 0; 
	int cols_utilizadas_matriz_original  = 0;
	
	/***********************************************************************/
	// "Rellenar" la matriz "matriz_original"
	
	#ifdef LECTURA
	
	/***********************************************************************/
	// Lectura de las dimensiones de la matriz y de su contenido. 
	
	int filas, columnas; // dimensión de la matriz
	
	do {
		cout << "Número de filas de la matriz 1 [1-"<< MAX_FILAS <<"]: ";
		cin >> filas;
	} while ((filas<1) || (filas>MAX_FILAS));
	
	do {
		cout << "Número de columnas de la matriz 1 [1-"<< MAX_COLS <<"]: ";
		cin >> columnas;
	} while ((columnas<1) || (columnas>MAX_COLS));


	// Lectura de los datos de la matriz
	
	for (int fila=0; fila<filas; fila++)
		for (int col=0; col<columnas; col++) {
			cout << "Elemento (" << fila << ", " << col << ") = ";
			cin >> matriz_original [fila][col];
		}

	filas_utilizadas_matriz_original = filas; 
	cols_utilizadas_matriz_original  = columnas;
	
	#else

	/***********************************************************************/
	// Versión simple y directa: se establecen las dimensiones y los valores. 
	
	filas_utilizadas_matriz_original = 3; 
	cols_utilizadas_matriz_original  = 4;	
	
	matriz_original [0][0] =  9;
	matriz_original [0][1] =  7;
	matriz_original [0][2] =  4;
	matriz_original [0][3] =  5;
	matriz_original [1][0] =  2;
	matriz_original [1][1] = 18;
	matriz_original [1][2] =  2;
	matriz_original [1][3] = 12;
	matriz_original [2][0] =  1;
	matriz_original [2][1] =  4;
	matriz_original [2][2] =  3;
	matriz_original [2][3] =  2;

	// Otra matriz de prueba: 
	/*
	matriz_original [0][0] =  1;
	matriz_original [0][1] =  7;
	matriz_original [0][2] =  3;
	matriz_original [0][3] =  2;
	matriz_original [1][0] =  2;
	matriz_original [1][1] = 18;
	matriz_original [1][2] =  2;
	matriz_original [1][3] = 12;
	matriz_original [2][0] =  9;
	matriz_original [2][1] =  7;
	matriz_original [2][2] =  4;
	matriz_original [2][3] =  5;
	*/	
		
	#endif
	
	/***********************************************************************/
	
		
	/***********************************************************************/
	// Mostrar los datos de la matriz
	
	cout << endl;
	cout << "Matriz orginal ";
	cout << "(" <<filas_utilizadas_matriz_original << ", " 
	     << cols_utilizadas_matriz_original << "):"<< endl;	
	cout << endl;

	for (int fila=0; fila<filas_utilizadas_matriz_original; fila++) {
		for (int col=0; col<cols_utilizadas_matriz_original; col++) 
			cout << setw(3) << matriz_original [fila][col];
		cout << endl;
	}
	cout << endl;
	

	/***********************************************************************/
	// Cálculo de la matriz traspuesta

	// Puede calcularse la traspuesta si el número de filas y columnas de 
	// la nueva matriz son correctas.
	
	if ((filas_utilizadas_matriz_original <= MAX_COLS) && 
		(cols_utilizadas_matriz_original <= MAX_FILAS)) {
	
		// Declaración de la mariz traspuesta: observe cómo se establece 
		// la capacidad de la matriz. 
		
		const int MAX_FILAS_TRASPUESTA = MAX_COLS;
		const int MAX_COLS_TRASPUESTA  = MAX_FILAS;
		
		int matriz_traspuesta [MAX_FILAS_TRASPUESTA][MAX_COLS_TRASPUESTA];
		
		int filas_utilizadas_matriz_traspuesta = 0; 
		int cols_utilizadas_matriz_traspuesta = 0; 
		
		// Rellenar "matriz_traspuesta" desde "matriz_original"
		
		for (int fila=0; fila<filas_utilizadas_matriz_original; fila++) 
			for (int col=0; col<cols_utilizadas_matriz_original; col++) 
				matriz_traspuesta[col][fila] = matriz_original [fila][col];
	
		filas_utilizadas_matriz_traspuesta=cols_utilizadas_matriz_original;
		cols_utilizadas_matriz_traspuesta =filas_utilizadas_matriz_original;
		
		
		// Mostrar los datos de la matriz traspuesta
		
		cout << endl;
		cout << "Matriz traspuesta " ;
		cout << "(" <<filas_utilizadas_matriz_traspuesta << ", " 
	     	 << cols_utilizadas_matriz_traspuesta << "):"<< endl;	
		cout << endl;
	
		for (int fila=0; fila<filas_utilizadas_matriz_traspuesta; fila++) {
			for (int col=0; col<cols_utilizadas_matriz_traspuesta; col++) 
				cout << setw(3) << matriz_traspuesta [fila][col];
			cout << endl;
		}
		cout << endl;
	}
	else 
		cout << "No puede calcularse la matriz traspuesta. " << endl;  
	
	cout << endl;


	/***********************************************************************/
	// Multiplicación de matrices.
			
	// Declaración de la otra matriz que se empleará para la multiplicación
	// Si A es una matriz mxn y B una matriz nxt la matriz A X B es mxt
	
	int matriz_nueva [MAX_FILAS][MAX_COLS];
	int filas_utilizadas_matriz_nueva = 0; 
	int cols_utilizadas_matriz_nueva  = 0;
	

	/***********************************************************************/
	// "Rellenar" la matriz "matriz_nueva"
	
	#ifdef LECTURA
	
	/***********************************************************************/
	// Lectura de las dimensiones de la matriz y de su contenido. 		
	
	do {
		cout << "Número de filas de la matriz 2 [1-"<< MAX_FILAS <<"]: ";
		cin >> filas;
	} while ((filas<1) || (filas>MAX_FILAS));
	
	do {
		cout << "Número de columnas de la matriz 2 [1-"<< MAX_COLS <<"]: ";
		cin >> columnas;
	} while ((columnas<1) || (columnas>MAX_COLS));


	// Lectura de los datos de la matriz
	
	for (int fila=0; fila<filas; fila++)
		for (int col=0; col<columnas; col++) {
			cout << "Elemento (" << fila << ", " << col << ") = ";
			cin >> matriz_nueva [fila][col];
		}

	filas_utilizadas_matriz_nueva = filas; 
	cols_utilizadas_matriz_nueva  = columnas;
	
	#else
	
	/***********************************************************************/
	// Versión simple y directa: se establecen las dimensiones y los valores. 
	
	filas_utilizadas_matriz_nueva = 4; 
	cols_utilizadas_matriz_nueva  = 2;	
	
	matriz_nueva [0][0] =  1;
	matriz_nueva [0][1] =  7;
	matriz_nueva [1][0] =  3;
	matriz_nueva [1][1] =  2;
	matriz_nueva [2][0] =  2;
	matriz_nueva [2][1] =  2;
	matriz_nueva [3][0] =  2;
	matriz_nueva [3][1] =  1;
			
	#endif
	
	/***********************************************************************/
	// Mostrar los datos de la matriz "nueva"
	
	cout << endl;
	cout << "Nueva matriz " ;
	cout << "(" <<filas_utilizadas_matriz_nueva << ", " 
	  	 << cols_utilizadas_matriz_nueva << "):"<< endl;	
	cout << endl;

		
	for (int fila=0; fila<filas_utilizadas_matriz_nueva; fila++) {
		for (int col=0; col<cols_utilizadas_matriz_nueva; col++) 
			cout << setw(3) << matriz_nueva [fila][col];
		cout << endl;
	}
	cout << endl;
	

	cout << endl;
	cout << "Se multiplica la matriz original por la otra matriz. " << endl;	
	cout << endl;	
	
	
	
	// Resultado de la multiplicación
	
	int matriz_resultado [MAX_FILAS][MAX_COLS];
	int filas_utilizadas_matriz_resultado = 0; 
	int cols_utilizadas_matriz_resultado = 0;	
	
	
	// Comprobación de las dimensiones para poder realizar la multiplicación: 
	// el número de columnas de la primera matriz debe coincidir con el número 
	// de filas de la segunda matriz. 
	
	if (cols_utilizadas_matriz_original != filas_utilizadas_matriz_nueva) {
		
		cout << "No es posible realizar la multiplicacion: " << endl; 
		cout << "El numero de columnas de la primera matriz debe coincidir ";
		cout << "con el número de filas de la segunda." << endl;
	}	
	
	else {
		
		for (int f=0; f<filas_utilizadas_matriz_original; f++) {
			
			for (int c=0; c<cols_utilizadas_matriz_nueva; c++) {
				
				
				int suma = 0;
				
				for (int i=0; i<cols_utilizadas_matriz_original; i++)
					
					suma+= matriz_original[f][i]*matriz_nueva[i][c];
		
				matriz_resultado[f][c] = suma;
			}
			
		}
		filas_utilizadas_matriz_resultado = filas_utilizadas_matriz_original; 
		cols_utilizadas_matriz_resultado  = cols_utilizadas_matriz_nueva;	 

		
		// Mostrar los datos de la matriz multipilcación
		
		cout << endl;
		cout << "Matriz multiplicacion " ;
		cout << "(" <<filas_utilizadas_matriz_resultado << ", " 
		  	 << cols_utilizadas_matriz_resultado << "):"<< endl;	
		cout << endl;
	
		for (int fila=0; fila<filas_utilizadas_matriz_resultado; fila++) {
			for (int col=0; col<cols_utilizadas_matriz_resultado; col++) 
				cout << setw(3) << matriz_resultado[fila][col];
			cout << endl;
		}
		cout << endl;
			
	}
	
	return 0;
}

/***************************************************************************/
/***************************************************************************/
