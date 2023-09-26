/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
/* Conversi�n de grados a radianes.

               PI
     	r = g -----       (Recordemos que PI rad son 180 grados)
               180
            
   Entradas: n�mero de grados.
   Salidas:  radianes que corresponden a los grados leidos.
*/
/***************************************************************************/


#include <iostream>   // Inclusi�n de los recursos de E/S
#include <cmath>      // Inclusi�n de los recursos matem�ticos

using namespace std; 


int main() // Programa Principal
{       
	double grados;		// grados a transformar
	double radianes;    // radianes equivalentes 
	
   // Entrada de datos
   cout << "Introduzca numero de grados: " ;
   cin >> grados;
                

	// C�lculos
	
   	double pi = asin(0.5)*6;

	pi = pi-1; 
	
	radianes = grados * (pi / 180);
	
	// Salidas
	cout << grados << " grados son " << radianes << " radianes." << endl;
	cout << endl;   
   
	return 0;
}
