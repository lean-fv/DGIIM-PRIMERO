/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 3 
//
/*	
	Programa que calcula el un número combinatorio:  

		( n )      n! 
		(   ) = -----------
		( m )    m! (n-m)!

		Ampliación de un ejercicio de la Relación de Problemas 2.
		La ampliación consiste en implementar la solución empleando funciones.
		Se presentan dos versiones diferentes: 	
			1) 	Calculando todos los factoriales, implementando la solución 
				de manera directa -literal- a la expresión --> Problemas de 
				desbordamiento si cualquiera de los dos términos es alto. 
			2) 	Simplificando la expresión: 
                  ( n )      n!          n(n-1)...(n-m+1) 
                  (   ) = ----------- = ------------------
                  ( m )    m! (n-m)!            m!
            De esta solución se proporcionan dos versiones.
			
	Entradas: n y m  
	Salidas:  El valor calculado según la expresión anterior
*/
/***************************************************************************/

#include <iostream>
using namespace std;

/***************************************************************************/
// Función que calcula el factorial de un número natural n
// 		n! = n * (n-1) * (n-2) * ... * 1 si n>1
// 		0! = 1! = 1 
//
// Entradas: 
//		n: número del que queremos calcular su factorial
// Devuelve: 
//		n! (el factorial de n)
//
// PRE: n >= 0
// 
// PRECAUCIÓN: Esta solución puede producir desbordamiento
	
long Factorial (int n) 
{
	long factorial;	// OJO: el tipo permite gestionar enteros "grandes"
					// El dato local "factorial" no debe confundirse con
					// la función "Factorial"
	factorial = 1;

	for (int multiplicando = 2; multiplicando <=n ; multiplicando++)
		factorial = factorial * multiplicando;

	return (factorial);	
}
 
/***************************************************************************/
// Calculo del combinatorio n sobre m usando la formulación directa: 
//
//      ( n )      n! 
//      (   ) = -----------
//      ( m )    m! (n-m)!
//
//	PRECAUCIÓN: Esta solución puede producir desbordamiento
//	(ver la solución del ejercicio 18 de la Relación de Problemas 2)
//
// Entradas: 
//		n: número total de elementos 
//		m: número de elementos de cada grupo
// Devuelve: 
//		El número de grupos de "m" elementos diferentes que se pueden formar 
//		a partir de un conjunto de "n" elementos.
//
// PRE: m >= 0
//	 	n >= 0
//      n >= m

long Combinatorio1 (int n, int m)
{
	long combinatorio = Factorial (n) / (Factorial (m)  * Factorial (n - m));
	return (combinatorio);
}

/***************************************************************************/
// Calculo del combinatorio n somre m usando la formulación simplificada: 
//
//      ( n )      n!          n(n-1)...(n-m+1) 
//      (   ) = ----------- = ------------------
//      ( m )    m! (n-m)!            m!
//        
//      (ver la solución del ejercicio 18 de la Relación de Problemas 2)
//
// En esta solución se calculan numerador y denominador por separado
// 
// Entradas: 
//		n: número total de elementos 
//		m: número de elementos de cada grupo
// Devuelve: 
//		El número de grupos de "m" elementos diferentes que se pueden formar 
//		a partir de un conjunto de "n" elementos.
//
// PRE: 1) m >= 0, 2) n >= 0, 3) n >= m

long Combinatorio2 (int n, int m)
{

	long numerador;	    // n (n-1) ... (n-m+1)
	long factorial_m; 	// m!
	
	factorial_m = Factorial(m); // Llamada a función Factorial
	
	numerador = 1;

	for (int i = 1 ; i <= m ; i++){
       numerador = numerador * (n - m + i);
	}

	return (numerador/factorial_m);
	
}

/***************************************************************************/
// Calculo del combinatorio n somre m usando la formulación simplificada: 
//
//      ( n )      n!          n(n-1)...(n-m+1) 
//      (   ) = ----------- = ------------------
//      ( m )    m! (n-m)!            m!
//        
//      (ver la solución del ejercicio 18 de la Relación de Problemas 2)
//
// En esta solución se calculan numerador y denominador en el mismo ciclo
//
// Entradas: 
//		n: número total de elementos 
//		m: número de elementos de cada grupo
// Devuelve: 
//		El número de grupos de "m" elementos diferentes que se pueden formar 
//		a partir de un conjunto de "n" elementos.
//
// PRE: 1) m >= 0, 2) n >= 0, 3) n >= m

long Combinatorio3 (int n, int m)
{

	long numerador;	    // n (n-1) ... (n-m+1)
	long factorial_m; 	// m!
	
	numerador = 1;
	factorial_m = 1;
	
	for (int i = 1 ; i <= m ; i++){
       factorial_m = factorial_m * i;
       numerador = numerador * (n - m + i);
	}

	return (numerador/factorial_m);
	
}

/***************************************************************************/

int main()
{
	// Datos de entrada
	int total_a_elegir, // n \ Restricción: total_a_elegir >= elegidos 
		elegidos;		// m / Si no se cumple, se vuelve a solicitar ambos.

	// Resultados
	long combinatorio1;	// Versión directa	
	long combinatorio2;	// Versión simplificada
	long combinatorio3;	// Versión muy simplificada

	// Lectura y filtrado de datos
	
	do {
		
		do {
			cout << "Introduzca total de elementos: ";
			cin >> total_a_elegir;
		} while (total_a_elegir <= 0);
		
		cout << endl; 
		
		do {
			cout << "Introduzca cuantos va a elegir del total: ";
			cin >> elegidos;
		} while (elegidos <= 0);
		
	} while (total_a_elegir < elegidos);
	
	// Cálculos

	combinatorio1 = Combinatorio1 (total_a_elegir, elegidos);
	combinatorio2 = Combinatorio2 (total_a_elegir, elegidos);
	combinatorio3 = Combinatorio3 (total_a_elegir, elegidos);

	// Presentación de resultados
	
	cout << endl << endl;
	cout << "Version directa:" << endl;
	cout << "Combinaciones de " << total_a_elegir << " elementos ";
	cout << "tomados de " << elegidos << " en " << elegidos;
	cout << " = " << combinatorio1 << endl;
	cout << endl;

	cout << endl;
	cout << "Version simplificada:" << endl;
	cout << "Combinaciones de " << total_a_elegir << " elementos ";
	cout << "tomados de " << elegidos << " en " << elegidos;
	cout << " = " << combinatorio2 << endl;
	cout << endl;
	
	cout << endl;
	cout << "Version muy simplificada:" << endl;
	cout << "Combinaciones de " << total_a_elegir << " elementos ";
	cout << "tomados de " << elegidos << " en " << elegidos;
	cout << " = " << combinatorio3;
	cout << endl;
		
	return 0;
}
