/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 6
//
/*	 
	Este programa lee los valores de dos enteros, "n" y "k" y calcula, 
	almacena en un vector y muestra por pantalla los "k" primeros términos 
	de la sucesión de Fibonacci de orden n. 

		La sucesión de Fibonacci (a veces mal llamada serie de Fibonacci) 
		de orden "n" es una sucesión infinita de números naturales en la 
		que los dos primeros números de Fibonacci valen 1. 
		A partir del tercero se calculan como la suma de los "n" anteriores, 
		si ya hay "n" elementos disponibles, o la suma de todos los 
		anteriores, si hay menos de "n" elementos disponibles.
	
	Se presenta la clase "Fibonacci" con los métodos:  
	
	* Fibonacci (int orden)
		Constructor con parámetros. 
		La creación de la serie conlleva el cálculo de tantos elementos 
		como el orden de la serie. 

	* int GetOrden (void)
		Devuelve el orden de la serie.

	* void CalculaPrimeros(int tope) 
		Calcula los "tope" primeros elementos de la sucesión. 
		Los "orden" primeros elementos los calcula el constructor. 

	* int TotalCalculados() 
		Devuelve cuántos elementos hay actualmente almacenados 
		(el valor "tope" del método anterior)

	* int Elemento(int indice) 
		Devuelve el elemento indice-ésimo de la sucesión.
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/////////////////////////////////////////////////////////////////////////////

class Fibonacci 
{

private:

	// Datos asociados a la estructura de datos empleada para guardar 
	// los números de Fibonacci (una secuencia de enteros, realmente)
	
	static const int TAMANIO = 200; // Número de casillas disponibles
	int vector_privado[TAMANIO];
	
	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;	// Número de casillas ocupadas


	// Datos específicos de la clase: 

	int orden; // Orden de la serie de Fobonacci
	
public:
	
	/***********************************************************************/
	// Constructor con parámetros. 
	// La creación de la serie conlleva el cálculo de tantos elementos 
	// como el orden de la serie. 
	//
	// Recibe: n, el oren de la serie
	//
	// PRE: 2 <= n < TAMANIO

	Fibonacci (int n) 
	{

		orden = n; 

		// Calcular y guardar los primeros términos (1,1,2,...,n)
		// donde "n" es el orden de la sucesión.

		vector_privado[0] = 1;
		vector_privado[1] = 1;

		for (int pos=2; pos<orden; pos++) {

			// Calcular suma desde 0 hasta "pos"

			int suma = 0;
			for (int i=0; i<pos; i++) 
				suma += vector_privado[i];

			vector_privado[pos] = suma;
		}

		// Importante: el connstructor ha inicializado tantas casillas 
		// como el orden de la serie de Fibonacci. Actualizar el 
		// campo "total_utilizados"
		
		total_utilizados = orden; 
	}


	/***********************************************************************/
	// 	Devuelve cuántos elementos hay actualmente almacenados 
	
	int TotalCalculados (void) 
	{
		return (total_utilizados);
	}

	/***********************************************************************/
	// Devuelve el orden de la sucesión
	
	int GetOrden (void)
	{
		return orden;
	}

	/***********************************************************************/
	// Calcula los "tope" primeros elementos de la sucesión y los guarda. 
	//
	// NOTA: El constructor ya creó los primeros "orden" términos 
    //		(1, 2, ..., "orden") de la sucesión. 
	// Recibe: tope, el índice del mayor número de Fibonacci a calcular
	//
	// PRE:  2 <= tope < TAMANIO 
	//		 (si tope <= total_utilizados no se hace nada)
	
	void CalculaPrimeros (int tope) 
	{
		// Si alguno de los elementos solicitados no están guardados 
		// en "vector_privado" (tope > total_utilizados) 
		// se calculan los números de Fibonacci necesarios.
				
		if (tope > total_utilizados) {
			
			// Para cada valor nuevo de la serie (posición "pos") sumar los 
			// "orden" anteriores valores de la serie.  

			for (int pos=total_utilizados; pos<tope; pos++) {

				int suma = 0;
				for (int i=1; i<=orden; i++) 
					suma += vector_privado[pos-i];

				vector_privado[pos] = suma;  // guardar el nuevo valor 
				
			} // for pos
			
			total_utilizados = tope;

		} // if (tope > total_utilizados) 
		
	}

	/***********************************************************************/
	// Devuelve el elemento de la casilla "num_orden" 
	//
	// Recibe: indice, el índice del número de Fibonacci a calcular.
	// Devuelve: el número de Fibonacci de orden "indice".
	// 
	// PRE:  1 <= indice < TAMANIO 

	int Elemento (int num_orden)
	{
		// Si el elemento buscado no está guardado en "vector_privado" 
		// (total_utilizados < num_orden) && (num_orden < TAMANIO))
		// se calculan los números de Fibonacci necesarios 
		// (hasta "num_orden"). 
		
		if ((num_orden > total_utilizados) && (num_orden < TAMANIO)) 
			CalculaPrimeros (num_orden);
		
		// El elemento buscado ya está en "vector_privado" 

		return (vector_privado[num_orden-1]);
	}

	/***********************************************************************/
};

/////////////////////////////////////////////////////////////////////////////

/***************************************************************************/

int main (void)
{
	int num_elementos;
	
	//*******************************************************************
	// Creación de la serie de orden 2 con el mínimo número de valores, 
	// tal como está diseñado el constructor y mostrar la serie

	Fibonacci serie1 (2);

	cout << "Creada una serie de Fibonacci de orden " << serie1.GetOrden() 
		 << " (Contiene " << serie1.TotalCalculados() << " valores)" << endl;

 	num_elementos = serie1.TotalCalculados();

	for (int i=1; i<=num_elementos; i++)
		cout << serie1.Elemento(i) << " ";

	cout << endl << endl; 

	//*******************************************************************
	// Creación de la serie de orden 4 con el mínimo número de valores, 
	// tal como está diseñado el constructor y mostrar la serie

	int n = 4; // orden 

	Fibonacci serie2 (n); // Creación de la serie -> constructor

	cout << "Creada una serie de Fibonacci de orden " << serie2.GetOrden() 
		 << " (Contiene " << serie2.TotalCalculados() << " valores)" << endl; 
	cout << endl; 
	
	num_elementos = serie2.TotalCalculados();

	for (int i=1; i<=num_elementos; i++)
		cout << serie2.Elemento(i) << " ";
	cout << endl << endl;
	
	//*******************************************************************
	// Calcular los 10 primeros valores de "serie2" y mostrarlos
	// Tenga en cuenta que los 4 primeros ya están calculados. 

	serie2.CalculaPrimeros(10);

	cout  << "Después de calcular los primeros " << 10 << " valores" 
		 << " (Contiene " << serie2.TotalCalculados() << " valores)" << endl; 
	cout << endl; 

	num_elementos = serie2.TotalCalculados(); 

	for (int i=1; i<=num_elementos; i++)
		cout << serie2.Elemento(i) << " ";
	cout << endl << endl;

	//*******************************************************************
	// Calcular los 11 primeros valores de "serie2" y mostrarlos
	// Tenga en cuenta que los 10 primeros ya están calculados. 

	serie2.CalculaPrimeros(11);

	cout  << "Después de calcular los primeros " << 11 << " valores" 
		 << " (Contiene " << serie2.TotalCalculados() << " valores)" << endl; 
	cout << endl; 

	num_elementos = serie2.TotalCalculados(); 

	for (int i=1; i<=num_elementos; i++)
		cout << serie2.Elemento(i) << " ";
	cout << endl << endl;
	
	//*******************************************************************
	// Calcular el número de Fibonacci de orden 15 y mostralo.
	// Tenga en cuenta que los 11 primeros ya están calculados. 
	// Calcular el elemento 15 fuerza a calcular y guardar los números 
	// de Fibonacci de orden 12, 13, 14 y 15

	cout << endl; 
	cout << "El elemento 15 es = " << serie2.Elemento(15) << " ";
	cout << endl; 
	
	cout  << "(La serie contiene " << serie2.TotalCalculados() 
		  << " valores)" << endl; 
	cout << endl; 

	num_elementos = serie2.TotalCalculados(); 

	for (int i=1; i<=num_elementos; i++)
		cout << serie2.Elemento(i) << " ";
	cout << endl << endl;

	//*******************************************************************
	// Calcular el número de Fibonacci de orden 18 y mostralo.
	// Tenga en cuenta que los 15 primeros ya están calculados. 
	// Calcular el elemento 18 fuerza a calcular y guardar los números 
	// de Fibonacci de orden 16, 17 y 18
	
	cout << endl; 
	cout << "El elemento 18 es = " << serie2.Elemento(18) << " ";
	cout << endl; 


	cout  << "(La serie contiene " << serie2.TotalCalculados() 
		  << " valores)" << endl; 
	cout << endl; 

	num_elementos = serie2.TotalCalculados(); 

	for (int i=1; i<=num_elementos; i++)
		cout << serie2.Elemento(i) << " ";
	cout << endl << endl;
	
	//*******************************************************************
	// Calcular el número de Fibonacci de orden 12 y mostralo.
	// Los 18 primeros ya están calculados, así que simplemente se  
	// accede al dato apropiado y se devuelve. 
	
	cout << endl; 
	cout << "El elemento 12 es = " << serie2.Elemento(12) << " ";
	cout << endl; 

	cout  << "(La serie contiene " << serie2.TotalCalculados() 
		  << " valores)" << endl; 
	cout << endl; 
	
	num_elementos = serie2.TotalCalculados(); 

	for (int i=1; i<=num_elementos; i++)
		cout << serie2.Elemento(i) << " ";
	cout << endl << endl;

	return 0;
}
