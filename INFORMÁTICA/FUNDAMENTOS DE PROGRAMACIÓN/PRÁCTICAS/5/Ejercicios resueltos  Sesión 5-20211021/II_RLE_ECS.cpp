/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 2
//
/*	
	El método RLE (Run Length Encoding) codifica una secuencia de datos
	formada por series de valores idénticos consecutivos como una secuencia de
	parejas de números(valor de la secuencia y número de veces que se repite).

	Este programa lee una secuencia de números naturales (terminada con -1) y
	la codifica mediante el método RLE.
	
	La lectura no está etiquetada, por lo que es aconsejable realizarla con
	redirección de entrada, tomando los datos de un fichero de texto.
*/
/***************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	const int TERMINADOR = -1;
	
	int actual;   	// número leido, en proceso
	int anterior; 	// número inmediantamente anterior al leido
	int iguales_hasta_ahora;  // número de valores iguales

	int num_valores = 0; // Cantidad de valores válidos procesados
	
	const string SEPARADOR = "| "; 
	string resultado = SEPARADOR; 
	
	
	// Entrada y cálculos

	cin >> actual;	// Lectura anticipada
	
	iguales_hasta_ahora = 1;

	while (actual != TERMINADOR) {     
	
		num_valores++; 
	
		anterior = actual;      
		cin >> actual;

		if (anterior == actual)
			iguales_hasta_ahora++;
			
		else {
	
			// Pintar pareja: num.veces - valor
			//cout << iguales_hasta_ahora << " " << anterior << " " << endl;      
 
			resultado += to_string(iguales_hasta_ahora) + " " + 
						 to_string(anterior) + " " + SEPARADOR; 

			iguales_hasta_ahora = 1; // empezar una nueva serie
		}
	}   
	
	// Resultados
	
	if (num_valores > 0) 
		cout << resultado << endl; 
	else
		cout << "No se introdujo ningun valor valido." << endl;      

	cout << endl;

	return 0;
}
