/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 1
/*	
   Programa que lee un número real y trunca su parte decimal a un número 
   dado de cifras decimales.
   
   Entradas: num_real (número real a truncar) 
   			 num_decimales (número de decimales deseados) 
   Salidas:  num_real_truncado (número real truncado en su parte decimal) 

	Ejemplo de entrada: 1.23456 2 -- Salida correcta: 1.23
	Ejemplo de entrada: 1.237   2 -- Salida correcta: 1.23
	Ejemplo de entrada: 1.237   1 -- Salida correcta: 1.2
	Ejemplo de entrada: 1.237   0 -- Salida correcta: 1.0
		
	P.e para   num_real = 1.23456     num_decimales = 2
		
	real_truncado = trunc(num_real*10^num_decimales) / (10^num_decimales)
		
		real_truncado = trunc(1.23456*100.0)/100.0 = 
			          = trunc(123.456)/100.0 = 123/100.0 = 1.23
*/
/***************************************************************************/

#include <iostream>  
#include <cmath>
using namespace std; 

int main()
{ 	
	double real;		// Valor inicial
	int num_decimales;	// Num. decimales deseado
	
	double real_truncado; // Resultado

	// Entrada
	
	cout << "Truncar real a un número de cifras decimales. "<< endl;   
	cout << endl;
	cout << "Introduzca el valor real y el num. de cifras decimales: ";
	
	cin >> real;
	cin >> num_decimales;
	
	// Cálculos
	
	double desplazamiento = pow(10, num_decimales);
	double real_desplazado = real * desplazamiento;
	
	int entero = trunc(real_desplazado); // :-)
	
	// Otras posibilidades:
	//  int entero = static_cast <int> (real_desplazado); // casting
	//  int entero = (int) (real_desplazado);// casting
	//	int entero = real_desplazado;  // Truncado automático 
	
	real_truncado = entero / desplazamiento;
	
	
	// Salida
	
	cout << endl;
	cout << "Resultado: " << real_truncado << endl;
	cout << endl;
	
	return 0;
}
