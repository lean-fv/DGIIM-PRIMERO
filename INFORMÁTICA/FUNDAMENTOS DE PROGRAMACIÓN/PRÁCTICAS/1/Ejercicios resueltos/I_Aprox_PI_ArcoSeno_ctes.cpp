/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS I
//
/*  Programa para calcular un valor aproximado de PI a partir del arco-seno.
	El valor de PI se almacena en una constante.

   Como PI/6 = arco-seno (0.5) ---> PI = arco-seno(0.5)*6
   
   Entradas: No hay.
   Salidas:  Valor aproximado de PI
*/
/***************************************************************************/


#include <iostream>   // Inclusi�n de los recursos de E/S
#include <cmath>      // Inclusi�n de los recursos matem�ticos

using namespace std; 


int main() // Programa Principal
{                       

   const double PI = 6 * asin(0.5);
   
	// Salidas
	cout << "La aproximaci�n de PI calculada es " << PI << endl << endl;
   
	return 0;
}
