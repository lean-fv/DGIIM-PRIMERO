/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
// 
// RELACIÓN DE PROBLEMAS 3 
//
/*
	Dos números amigos son dos números naturales "a" y "b",	tales que la
	suma de los divisores propios de "a" más uno es igual a "b", y viceversa.
	
		Un ejemplo de números amigos es el par de naturales (220,284), ya que:
		* Los divisores propios de 220 son 2, 4, 5, 10, 11, 20, 22, 44,
		  55 y 110, que suman 283, y 283 + 1 = 284.
		* Los divisores propios de 284 son 2, 4, 71 y 142, que suman 219,
		  y 219 + 1 = 220. 

	Este programa implemente dos tareas sobre números amigos:

		1) Lee dos números naturales e indica si son o no amigos, y
		2) Lee otro número natural, "n", e informa si existe algún número
		   amigo de "n" en el intervalo centrado en "n" y de radio n/3
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/***************************************************************************/
// Calcula la suma de los divisores propios de un numero "n"
//
// PRE: n > 0

int SumaDivisoresPropios (int n)
{
	int suma_divisores = 0;

	/*
		Para calcular los divisores de "n" no es preciso comprobar todo
    	los candidatos 2,3,..., "n". No es preciso comprobar si los
		números mayores que sqrt(n) son divisores de "n"
	*/
	
	int parte_entera_raiz =  floor (sqrt(n)); // Tomamos la parte entera de
									          // la raiz cuadrada de "n"
	int ultimo = parte_entera_raiz; // último divisor a probar
	bool tiene_raiz_exacta = (n == ultimo*ultimo);
	
	for (int divisor = 2; divisor < ultimo; divisor++)  {

		if (n % divisor == 0)
			suma_divisores += (divisor + n/divisor);
			// OJO: se suman DOS divisores-->  "n" y "n"/"divisor"
	}

	// Observe que el ciclo termina sin hacer nada cuando "ultimo" 
	// es divisor de "n". Debe ahora comprobarse si éste es divisor, y 
	// en ese caso se considerará también su complementario solo si "n" 
	// no tiene raiz cuadrada exacta. 
	
	if (n % ultimo == 0) {
		
		suma_divisores += ultimo;	
	
		if (!tiene_raiz_exacta)
			suma_divisores +=  n/ultimo;
	}
	
	return (suma_divisores);
}

/***************************************************************************/
// Calcula si dos números naturales son amigos
//
// PRE: m,n > 0

bool Amigos (int a, int b)
{
	int suma_divisores_a = SumaDivisoresPropios (a);
	int suma_divisores_b = SumaDivisoresPropios (b);
	
	return ((suma_divisores_a+1 == b) && (suma_divisores_b+1 == a));
}

/***************************************************************************/
// Calcula si puede existe un amigo de "n" entre "izda" y "dcha"
//
// PRE: n, izda, dcha > 0
// PRE: izda <= dcha

bool PuedeExistirAmigo (int n, int izda, int dcha)
{
	int suma_divisores_n = SumaDivisoresPropios (n);
	
	return ((suma_divisores_n + 1 >= izda) && (suma_divisores_n + 1 <= dcha));
}

/***************************************************************************/

int main (void)
{
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales

	// Apartado 1.
	
	int m, n;
	
	do {
		cout << "Introduzca el primer numero natural: ";
		cin >> m;
	} while (m <= 0);
	
	do {
		cout << "Introduzca el segundo numero natural: ";
		cin >> n;
	} while (n <= 0);

	cout << endl;
	
	if (Amigos(m, n))
		cout << m << " y " << n << " son amigos." << endl;
	else
		cout << m << " y " << n << " NO son amigos." << endl;

	cout << endl;

	
	// Apartado 2.
	
	int centro;
	
	do {
		cout << "Introduzca un numero natural (centro del intervalo): ";
		cin >> centro;
	} while (centro <= 0);
	
	
	double ancho = centro/3.0;
	
	cout << endl;
	cout << "Centro = " << setw(8) << centro << endl;
	cout << "Ancho  = " << setw(8) << setprecision (3) << ancho << endl;

	int limite_izda =  ceil (centro-ancho);
	int limite_dcha =  floor (centro+ancho);
	
	cout << "Comprobando en el intervalo [" << limite_izda << ", "
	     << limite_dcha << "]" << endl;
	cout << endl;
	
	
	if (PuedeExistirAmigo (centro, limite_izda, limite_dcha))  {

		cout << "Puede existir algun amigo de " << centro
		     << " en el intervalo." << endl;
	
		int candidato = SumaDivisoresPropios(centro) + 1;
		
		cout << "\tEl candidato es "<< candidato << endl;
		     
		if (Amigos (centro, candidato))
			cout << "\t" << centro << " y " << candidato
			     << " son amigos." << endl;
		else
			cout << "\tNo existe ningun amigo." << endl;
	}
	else
		cout << "No pueden existir amigos en el intervalo." << endl;

	cout << endl;

	return 0;
}
