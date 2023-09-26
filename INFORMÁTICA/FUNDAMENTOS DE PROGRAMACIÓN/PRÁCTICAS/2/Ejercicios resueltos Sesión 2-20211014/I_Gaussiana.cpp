/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 1
//
/*	
   Programa que calcula e imprime el valor de una gaussiana, dados 
   sus parámetros (desviación típica y esperanza)   
   Entradas: parámetros de la gaussiana (desviacion, esperanza) y 
			 la abscisa (x)
   Salidas:  El valor de la ordenada (y), calculada mediante: 

	                                            {        (x-esperanza)^2 }
							                    { -0.5 * (-----------)   }
	                        1                   {        (desviacion )   }
				y = ----------------------  * e^                  
	                               ______
				     desviacion * V 2*PI     
*/
/***************************************************************************/
 
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);	
	
	const double PI = 3.1415927; 

	double esperanza, desviacion; // Entrada: parámetros de la gaussiana
	double x;   // Entrada (abscisa)
	double y;	// Salida  (ordenada) y = gaussiana (x)
   
   	cout << endl;
	cout << "Introduzca el valor del parametro 'esperanza' : ";
	cin >> esperanza;

	cout << "Introduzca el valor del parametro 'desviacion' : ";
	cin >> desviacion;

	cout << endl;
	cout << "Calculando g --> N (" << setw(8) << setprecision(4) << esperanza  
	     <<"," << setw(8) << setprecision(4) << desviacion << ")" << endl;
	cout << endl;

	cout << "Introduzca el valor de la abscisa: ";
	cin >> x;
   
	// Cálculo de la ordenada y = gaussiana (x)
	y = exp (-0.5 * pow ((x - esperanza)/desviacion, 2)) / 
		(desviacion * sqrt(2*PI));
   
	cout << endl;
	cout << "g (" << setw(8) << setprecision(4) << x << ") = " 
		 << setw(8) << setprecision(4) << y << endl;
	cout << endl;

	return 0;
}
