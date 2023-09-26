/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 2
/*		
	En este programa se piden los parámetros de la función gaussiana 
	(esperanza y desviación) y calcula e imprime valores de la gaussiana 
	para todos los valores entre el mínimo y el máximo, con el incremento 
	indicado: minimo, minimo+incr, min+2*incr, ...., maximo (siempre que 
	maximo <= min+n*incr).
			
   	Recordemos que f(x) =  
	                                            {        (x-esperanza)^2 }
							                    { -0.5 * (-----------)   }
	                        1                   {        (desviacion )   }
				  = ----------------------  * e^                  
	                               ______
				     desviacion * V 2*PI     
				     
	Esta versión comprueba la validez del parámetro "desviacion" de tal 
	manera que si no es positivo no hace nada. 
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales
	
	
	const double PI = 6 * asin(0.5);

	double esperanza, desviacion; // Entrada: parámetros de la gaussiana
 	double x, y; 
  
	// Entrada 
   
   	cout << endl;
	cout << "Introduzca el valor del parametro 'esperanza' : ";
	cin >> esperanza;

	cout << "Introduzca el valor del parametro 'desviacion' : ";
	cin >> desviacion;
	
	bool correctos_datos = (desviacion > 0); // bandera
	
	if (correctos_datos) {
	 
	   	cout << endl;
		cout << "Introduzca el valor de la abscisa: ";
		cin >> x;	
		
	}
	
	// Cálculos 
	
	if (correctos_datos) {
		
		// Cálculo de la ordenada y = gaussiana (x)
		y = exp (-0.5 * pow ((x - esperanza)/desviacion, 2)) / 
			(desviacion * sqrt(2*PI));
	}
	
	
	// Salida (presentación de resultados) 
	
	if (correctos_datos) {
	
		cout << endl;
		cout << "El valor de la funcion gaussiana en " << x << " es " << y;
		cout << endl;		
	}
	else {
		cout << endl;
		cout << "Error: el valor de 'desviacion' es incorrecto."<< endl;
		cout << "       Se requiere: 'desviacion' > 0"<< endl;
		cout << endl;		
	}
	
	cout << endl;		

	return 0;
}
