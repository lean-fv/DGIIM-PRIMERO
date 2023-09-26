/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 2
/*	
	Programa que acepta el número de un año e indique si es bisiesto o no.
	Un año es bisiesto si es múltiplo de cuatro, pero no de cien. 
	Excepción a la regla anterior son los múltiplos de cuatrocientos que 
	siempre son bisiestos. Son bisiestos: 1600, 1996, 2000, 2004. 
	No son bisiestos: 1700, 1800, 1900, 1998, 2002.
	
	NOTA: El programa sólo procesa años del siglo XX en adelante

*/
/***************************************************************************/

#include <iostream>
using namespace std;

int main()
{
   	int	anio;


	// Entrada
	
	cout << "Introduzca un anio : ";
	cin >> anio;


	// Cálculos
	
	bool es_siglo_XX_o_posterior = (anio > 1900);
	
	bool es_bisiesto;
	
	if (es_siglo_XX_o_posterior) {

		es_bisiesto = (((anio%4 == 0) && (anio%100 != 0)) || (anio%400 == 0));
	}	
	
	// Resultados
	
	cout << endl;
	
	if (es_siglo_XX_o_posterior) {
	
		if (es_bisiesto)
			cout << "El anio " << anio << " es bisiesto" << endl;
		else	
			cout << "El anio " << anio << " no es bisiesto" << endl;
	}
	else {
		cout << "Error: el anio no es correcto" << endl;
	}

	cout << endl;

	return 0;
}
