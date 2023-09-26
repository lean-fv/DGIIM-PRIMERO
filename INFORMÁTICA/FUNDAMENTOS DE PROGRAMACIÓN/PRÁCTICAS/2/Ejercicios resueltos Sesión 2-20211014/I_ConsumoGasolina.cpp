/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 1
//
/*
	Programa que calcula el consumo de gasolina.
	Pide la distancia recorrida (en kms), los litros de gasolina consumidos
	y los litros que quedan en el depósito.
	El programa debe informar el consumo en km/litro, los litros/100 km y
	cuantos kilómetros de autonomía le restan con ese nivel de consumo.

   Entradas: distancia recorrida, litros consumidos y litros restantes.
   Salidas:  consumo y autonomía
*/
/***************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	const double DISTANCIA_REF = 100; // en Km
	
	// Datos de entrada
	double distancia_recorrida;
	double litros_consumidos, litros_quedan;

	// Resultados
	double distancia_litro, consumo_DISTANCIA_REF;
	double autonomia;

	// Entrada de datos
	cout << "Distancia recorrida (km) = ";
	cin >> distancia_recorrida;
	cout << "Litros consumidos = ";
	cin >> litros_consumidos;
	cout << "Litros que quedan en el deposito = ";
	cin >> litros_quedan;

	// Cálculos
	
	// El valor base es el número de km que se recore con 1 l de combustible
	distancia_litro = distancia_recorrida/litros_consumidos; 
	
	// Consumo cada DISTANCIA_REF km
	consumo_DISTANCIA_REF = DISTANCIA_REF / distancia_litro; 

	// Km que puede recorrer
	autonomia = litros_quedan * distancia_litro; 

	// Resultado
	cout << endl;
	cout << "Recorrido por litro = " << distancia_litro << " km/l "; 
	cout << "(Consumo de " << consumo_DISTANCIA_REF << " l/100 km)" << endl;
	cout << endl;
	
	cout << "Autonomia = " << autonomia << " km" << endl;
	cout << endl;

	return 0;
}
