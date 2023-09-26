/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 2
//
/*	 
	Programa que calcula el un número combinatorio  

		( n )      n! 
		(   ) = -----------
		( m )    m! (n-m)!

	El combinatorio de n sobre m nos indica cuántas maneras hay de formar
	grupos de m elementos de un total de n, sin repetición y sin importar 
	el orden. El ejemplo típico es la lotería primitiva. 
		
	Entradas: n y m  
	Salidas:  El valor calculado según la expresión anterior
*/
/***************************************************************************/

#include <iostream>
using namespace std;

/***************************************************************************/
/***************************************************************************/

int main()
{
	// Datos de entrada
	int total_a_elegir, // n \ Restricción: total_a_elegir >= elegidos 
		elegidos;		// m / Si no se cumple, se vuelve a solicitar ambos.

	// Resultados
	long combinatorio_1, combinatorio_2_1, combinatorio_2_2;	
	
	
	// Lectura y filtrado de datos
	
	do {
		
		do {
			cout << "Introduzca total de elementos: ";
			cin >> total_a_elegir;
		} while (total_a_elegir <= 0);
		
		do {
			cout << "Introduzca cuántos va a elegir del total: ";
			cin >> elegidos;
		} while (elegidos <= 0);
		
		cout << endl;
		
	} while (total_a_elegir < elegidos);
	
	
	// Cálculos
	
	// Datos intermedios
	long factorial_total_a_elegir, // (n!)
		 factorial_elegidos,	   // (m!)
		 factorial_diferencia;	   // (n-m)!
		 
		 
		 
	/*
	SOLUCIÓN 1: 
	
		La primera solución aplica la fórmula del combinatorio directamente 
		(calculando tres factoriales):  n! / (m! (n-m)!)			
	*/

		 
	factorial_total_a_elegir = 1;
	for (int i = 2; i <= total_a_elegir; i++)
		factorial_total_a_elegir = factorial_total_a_elegir * i;

	factorial_elegidos = 1;
	for (int i = 2; i <= elegidos; i++)
		factorial_elegidos = factorial_elegidos * i;

	factorial_diferencia = 1;
	for (int i = 2; i <= total_a_elegir - elegidos; i++)
		factorial_diferencia = factorial_diferencia * i;

	combinatorio_1 = factorial_total_a_elegir / 
	                 (factorial_elegidos * factorial_diferencia);
	

	/*
		Esta solución directa puede producir desbordamiento incluso 
		utilizando tipos enteros grandes como long ó long long 
		
		Comprobadlo con 49 y 6 (combinaciones posibles en la lotería primitiva)
		http://www.nitrxgen.net/factorialcalc.php
		49! -> Tiene 63 cifras = 608281864034267560872252163321295376887552831	
		37921024000000000060415263063373835637355132068513997507264512000000000

		Se desborda con un long (4 bytes, Máximo = 2147483647 -10 cifras-) 
		y con un long long (8 bytes, Máximo = 9223372036854775807 ó 
		18446744073709551616 -20 cifras- cuando es unsigned) 
		Con un double tampoco valdría ya que, aunque le cupiese y no hubiese 
		desbordamiento, sólo podría representar 16 cifras de precisión.
	*/
	
	/*
	SOLUCIÓN 2: 

		Simplificamos la expresión del cálculo del combinatorio:
		n! / (m! (n-m)!)  =   n(n-1)...(n-m+1) / m!

		¡Hemos pasado a tener únicamente m multiplicaciones 
		en el numerador y denominador!

		total_a_elegir (total_a_elegir-1) ... 
		      (total_a_elegir - elegidos + 1) / elegidos!
		      
        P.e. (10) =  10!   10 9 8 7 6 ... 3 2 1   10 9 8 
             (  ) = ---- = --------------------	= ------- = 120
             ( 3)  3! 7!   3 2 1  7 6 ... 3 2 1    3 2 1
    		n=10, m=3, n-m+1=8
			
        P.e. (8) =  8!     8 7 6 ... 3 2 1     8 7
             ( ) = ---- = ------------------ = ---- = 28
             (2)  2! 6!    2 1  6 ... 3 2 1    2 1
    		n=8, m=2, n-m+1=7
	*/

	// Datos intermedios
	long numerador;			 // n (n-1) ... (n-m+1)

	/*
	SOLUCIÓN 2.1: Con dos ciclos independientes:
	*/
	
	// Numerador: n(n-1)...(n-m+1)
	numerador = 1;
	for (int i = total_a_elegir - elegidos + 1; i <= total_a_elegir; i++)
		numerador = numerador * i; 
	
	// Denominador: m!
	factorial_elegidos = 1;
	for (int i = 1; i <= elegidos; i++)
		factorial_elegidos = factorial_elegidos * i;
	
	combinatorio_2_1 = numerador/factorial_elegidos;
	

	/*
	SOLUCIÓN 2.2: Con un sólo bucle 
		(observad que los dos ciclos realizan el mismo número de iteraciones)  
	*/

	numerador = 1;
	factorial_elegidos = 1;
	for (int i = 1 ; i <= elegidos ; i++){
       factorial_elegidos = factorial_elegidos * i;
       numerador = numerador * (total_a_elegir - elegidos + i);
	}

	combinatorio_2_2 = numerador/factorial_elegidos;


	// Presentación de resultados
		
	cout << endl << endl;
	cout << "Combinaciones de " << total_a_elegir << " elementos ";
	cout << "tomados de " << elegidos << " en " << elegidos << endl;
	cout << endl;
	
	cout << "Solucion 1 (implementacion directa) = " 
	     << combinatorio_1 << endl;
	cout << endl;

	cout << "Solucion 2.1 (dos ciclos) = " 
	     << combinatorio_2_1 << endl;
	cout << endl;
	
	cout << "Solucion 2.2 (un ciclo) = " 
	     << combinatorio_2_2 << endl;
	cout << endl << endl;
	
	return 0;
}

/***************************************************************************/
/***************************************************************************/
