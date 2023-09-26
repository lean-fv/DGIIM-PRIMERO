/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 6
// 
/*	
	Programa que lee un valor "tope" y calcula la siguiente sumatoria:
    
       tope
       _____
	   \
	   /   i!   = 1! + 2! + 3! + ... + tope!
      -----
       i = 1
*/
/***************************************************************************/
 
#include <iostream>
using namespace std;

/***************************************************************************/
// Calcula n!
// PRE: n<=15

long Factorial (int n)
{
	long factorial = 1;

	for (int k = 2; k<=n ; k++)
		factorial = factorial * k;
			
	return (factorial);
}

/***************************************************************************/
// Calcula Sum (n!) n=1,...tope
// PRE: n<=15

long SumaFactorial_Directo (int tope)
{
	long suma_factoriales = 0;
	
	for (int i=1; i<=tope; i++) {
		suma_factoriales += Factorial (i);
	}
	return (suma_factoriales);
}

/***************************************************************************/
// Calcula n!
// Versión "optimizada" 
/* El método directo realiza muchos cálculos repetidos 
   Por ejemplo, para calcular la suma con T=5, realiza:   
  		1! = 1
  	 	2! = 1 * 2 = (1*2)
		3! = 1 * 2 * 3 = (1*2)*3
		4! = 1 * 2 * 3 * 4 = ((1*2)*3)*4
		5! = 1 * 2 * 3 * 4 * 5= (((1*2)*3)*4)*5
	Observe que 1*2, se realiza 4 veces, (1*2)*3 se calcula 
	3 veces y ((1*2)*3)*4 se calcula 2 veces. 
	
	Si reescribimos las operaciones para que al mismo tiempo que se 
	suma se van multiplicando términos podemos simplificar los 
	cálculos y un ciclo es suficiente: 
	
    (1) + 2 * (1) + 3 * (2*1) + 4 * (3*2*1) + 5 * (4*3*2*1)
               ^		  ^            ^             ^
		     antes	    antes        antes         antes 
*/
// PRE: n<=15

long SumaFactorial_Optimizado (int tope)
{
	long suma_factoriales = 1;
	long termino_i = 1;
	
	for (int i=2; i<=tope; i++) {

		termino_i = i*termino_i;
		suma_factoriales += termino_i;
	}
	return (suma_factoriales);	
}

/***************************************************************************/
/***************************************************************************/

int main()
{
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales
	
	const int MAX_TOPE = 15;

	int suma1, suma2; // Resultados
	
	
	// Lectura y filtrado de "tope"
	
	int tope;
	
	do {
		cout << "Introduzca un entero positivo entre 1 y " << MAX_TOPE << ": ";
		cin >> tope;
	} while ((tope<1) || (tope>MAX_TOPE));

	
	// Cálculos
	
	suma1 = SumaFactorial_Directo(tope); 	// Método directo
	suma2 = SumaFactorial_Optimizado(tope);	// Método optimizado
	
	
	// Presentación de resultados
	
	cout << endl;
	cout << "Con el metodo directo    = " << suma1 << endl; 
	cout << endl;
	

	cout << endl;
	cout << "Con el metodo optimizado = " << suma2 << endl; 
	cout << endl;
	
	return 0;
}
