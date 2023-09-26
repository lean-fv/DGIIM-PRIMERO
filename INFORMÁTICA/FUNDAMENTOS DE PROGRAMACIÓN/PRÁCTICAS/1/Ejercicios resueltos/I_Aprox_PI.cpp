/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS I
//
/*	
   Programa que muestra en pantalla el resultado de las siguientes expresiones 
   num�ricas que constituyen una aproximaci�n al valor de PI. La primera es 
   del a�o 1800 a.C., la segunda (tambi�n de la misma era) es una aproximaci�n 
   introducida por los matem�ticos mesopot�micos y la tercera es del siglo 
   II (introducida por Claudio Ptolomeo)
   
                256                  1               377
      PI aprox. ---   PI aprox. 3 + ---   PI aprox.  ---
                 81                  8               120
                 
	El resultado debe ser 3.16049, 3.125 y 3.14167
*/
/***************************************************************************/

#include <iostream>
using namespace std;

int main(){
	
	double aprox_pi_Rhind;			// Ahmes, 1800 a. C. (papiro Rhind) 
	double aprox_pi_Mesopotamia;	// 1900-1600 a. C.
	double aprox_pi_Ptolomeo;		// Claudio Ptolomeo, siglo II
	
	// C�lculos
	
	aprox_pi_Rhind = 256.0 / 81;
	aprox_pi_Mesopotamia = 3 + 1/8.0;
	aprox_pi_Ptolomeo =  377 / 120.0;
	
	// Salidas
	
	cout << endl;
	cout << "Aproximaciones a PI: " << endl;		
	cout << "\tEgipto: " << aprox_pi_Rhind << endl;
	cout << "\tMesopotamia: " << aprox_pi_Mesopotamia << endl;
	cout << "\tPtolomeo: " << aprox_pi_Ptolomeo << endl; 
	cout << endl;

	return 0;
}
