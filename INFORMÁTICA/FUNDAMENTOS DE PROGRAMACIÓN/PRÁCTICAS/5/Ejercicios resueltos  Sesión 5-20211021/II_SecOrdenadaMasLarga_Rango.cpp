/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 2
//
/*	
	Programa que lee una secuencia indeterminada de números reales y calcula 
	la subsecuencia de números ordenada, de menor a mayor, de mayor	longitud.
	
	Los datos deben estar en un rango prefijado, p.e. [-90, 60]
	La entrada de datos parará cuando se introduzca una temperatura fuera 
	del rango.
	
	El programa indica la longitud de la subsecuencia y dónde empieza. 
	
		Por ejemplo, ante la entrada siguiente:
			     17.2 17.3 16.2 16.4 17.1 19.2 18.9 100
		el programa indica que la mayor subsecuencia empieza en la posición 3
		y tiene longitud 4. 
*/
/***************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	const double MIN_RANGO = 1.0;  
	const double MAX_RANGO = 10.0;  

	// "actual" guardará el valor recién leido mientras que "anterior" 
	// guardará el valor que se leyó en la iteración anterior
	double actual, anterior;
		
	// Posición (o número de orden) en la secuencia global del valor "actual"
	int pos;
		
	// Variables asociadas a la secuencia actual
	int longitud_secuencia = 0, 
		pos_inicio_secuencia = 0;
	
	// Variables asociadas a la secuencia máxima
	int longitud_secuencia_maxima = 0, 
		pos_inicio_secuencia_maxima = 0;	
	
	
	bool continuar; // Control de si hemos llegado al fin de la secuencia


	// La lectura se hará, necesariamente, usando la técnica de la 
	// lectura adelantada ya que no sabemos cuántos valores se van a leer.

	// Lectura del primer valor 
	
	pos = 1; // EL primer valor ocupa la posición 1
	
	cin >> actual;	
	continuar = (MIN_RANGO <= actual && actual <= MAX_RANGO);	
	
	
	if (continuar) {
	
		// El primer valor no es el TERMINADOR
		
		anterior = actual; // El primer valor se trata de manera especial 

		// Se ha leido un valor (pos=1), por lo que tenemos ya una secuencia 
		// que empieza en la posición 1 (pos_inicio_secuencia=1) con un solo 
		// elemento (longitud_secuencia = 1)	
			
		pos_inicio_secuencia = 1;
		longitud_secuencia = 1;		
		
		// La primera secuencia (su longitud actual es 1) es también la máxima
		 
		longitud_secuencia_maxima = 1;
		pos_inicio_secuencia_maxima = 1;
		
		// Lectura (anticipada) de un nuevo valor. Los demás se leerán 
		// dentro de un un ciclo de lectura adelantada ya que no sabemos 
		// cuántos valores se van a leer.
		
		pos++;			
		
		cin >> actual;	// Lectura anticipada
		continuar = (MIN_RANGO <= actual && actual <= MAX_RANGO);		

				
		while (continuar) {
				
			if (actual < anterior) { 	// Ha terminado una secuencia ordenada  
			
				// Comprobar si su longitud es mayor que la de la máxima 
				
				if (longitud_secuencia > longitud_secuencia_maxima) {
					
					// Se ha encontrado una nueva secuencia máxima: 
					// Actualizar las variables asociadas a la máxima secuencia 
					
					longitud_secuencia_maxima = longitud_secuencia;
					pos_inicio_secuencia_maxima = pos_inicio_secuencia;
					
				}
				
				// Establecer los valores adecuados para la nueva secuencia 
				// que empieza con el valor leido
	
				longitud_secuencia = 1;
				pos_inicio_secuencia = pos; 
			}      
			
			else { // Como actual>=anterior la secuencia continúa
				
				longitud_secuencia++;

			}

			// Preparar la siguiente iteración
			
			anterior = actual; 
			
			// Lectura de un nuevo valor 
			
			pos++;			
			
			cin >> actual;	// Lectura anticipada
			continuar = (MIN_RANGO <= actual && actual <= MAX_RANGO);		
								
		}  // while (continuar)
	
	} // if (continuar) 
	
	
	// Resultado

	cout << endl;

	if (longitud_secuencia_maxima >= 1)	{

		if (longitud_secuencia_maxima==1 && longitud_secuencia >= 1) 
			longitud_secuencia_maxima = longitud_secuencia;
		
		cout << "La secuencia maxima empieza en la posicion "
			 << pos_inicio_secuencia_maxima  << endl;      
		cout << "Su longitud es " << longitud_secuencia_maxima  << endl;      
	} 
	else {
		cout << "No hay nada que mostrar. ";
	}
	cout << endl;

	return 0;
}
