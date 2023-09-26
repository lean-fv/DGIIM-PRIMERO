/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 1
/*	
   Programa que pide la intensidad de la corriente y la resistencia para 
			calcular e imprimir en pantalla el voltaje
   Entradas: Intensidad de la corriente (intensidad) y 
			 la resistencia (resistencia)
   Salidas:  El voltaje, calculado mediante la ley de Ohm: 
				voltaje = intensidad * resistencia
*/
/***************************************************************************/

#include <iostream>
using namespace std;

/***************************************************************************/
/***************************************************************************/

int main()
{
	double intensidad;  // Entrada: intensidad de corriente
	double resistencia;	// Entrada: resistencia 
	double voltaje;		// Salida: voltaje 

	// Entrada de datos
	cout << "Introduzca el valor de intensidad: ";
	cin >> intensidad;
	cout << "Introduzca el valor de resistencia: ";
	cin >> resistencia;

	// C�lculos
	voltaje = intensidad * resistencia;

	// Salida
	cout << endl;
	cout << "El valor de voltaje es: " << voltaje << endl;
	cout << endl;
	
	return 0;
}
/***************************************************************************/
/***************************************************************************/
