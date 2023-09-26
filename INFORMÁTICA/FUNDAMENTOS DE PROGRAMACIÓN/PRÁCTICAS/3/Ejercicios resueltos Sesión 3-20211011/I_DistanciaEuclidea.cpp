/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 1
/*	
   Programa que calcula la distancia Euclídea entre dos puntos
   Dados P1 (x_1, y_1) y P2 (x_2, y_2)
   		d (P1, P2) = sqrt ((x_1 - x_2)^2 + (y_1-y_2)^2)

   Entradas: Coordenadas de los dos puntos (x_1, y_1, x_2 e y_2)
   Salidas:  La distancia Euclídea entre ellos
*/
/***************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{

	double x_1, y_1; 	// Coordenadas del primer punto
	double x_2, y_2; 	// Coordenadas del segundo punto

	cout << endl;
	cout << "Introduzca coordenada x del primer punto: ";
	cin >> x_1;
	cout << "Introduzca coordenada y del primer punto: ";
	cin >> y_1;

	cout << endl;
	cout << "Introduzca coordenada x del segundo punto: ";
	cin >> x_2;
	cout << "Introduzca coordenada y del segundo punto: ";
	cin >> y_2;
	
	double distancia = sqrt(pow(x_1 - x_2, 2) + pow(y_1 - y_2, 2)); 
	
	cout << endl;
	cout << "La distancia entre ( " << x_1 << ", " << y_1 << ") y ("
	     << x_2 << ", " << y_2 << ") es " << distancia << endl;
	cout << endl;

	return 0;
}
