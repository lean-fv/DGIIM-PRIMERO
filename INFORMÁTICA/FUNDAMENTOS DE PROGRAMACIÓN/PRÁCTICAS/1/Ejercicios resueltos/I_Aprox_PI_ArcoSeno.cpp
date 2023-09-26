/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS I
//
/* Programa para calcular un valor aproximado de PI a partir del arco-seno.

   Como PI/6 = arco-seno (0.5) ---> PI = arco-seno(0.5)*6
   
   Entradas: No hay.
   Salidas:  Valor aproximado de PI
*/
/***************************************************************************/


#include <iostream>   // Inclusi�n de los recursos de E/S
#include <iomanip>   // Inclusi�n de los recursos para personalizar E/S
#include <cmath>      // Inclusi�n de los recursos matem�ticos


using namespace std; 


int main() // Programa Principal
{                     

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	  
	double pi; // Aproximaci�n de PI   

	// C�lculos
   	pi = asin(0.5)*6;

	// Salidas
	
	cout << endl;
	cout << "La aproximaci�n de PI calculada es " 
	     << setw(20) << setprecision(5) << pi << endl << endl;
	cout << endl;
   
	return 0;
}
