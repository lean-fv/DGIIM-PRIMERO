/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 1
/*	
   Programa que lee un carácter (minúscula), lo pasa a mayúscula y lo imprime.
   No pueden usarse las funciones toupper() ni tolower() de cctype.
   
   Entradas: caracter en minúscula
   Salidas:  caracter en mayúscula

   La tranformación debe realizarse considerando la equivalencia char - int
*/
/***************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	char letra_minuscula; // Entrada
	char letra_mayuscula; // Salida

	cout << endl;
	cout << "Introduzca una letra minuscula: ";
	cin >> letra_minuscula;

	/*
	Las mayúsculas están antes que las minúsculas en la tabla ASCII.
	Además, sabemos que hay el mismo número de mayúsculas que de
	minúsculas y obviamente se encuentran en el mismo orden. Por
	tanto, sólo necesitamos saber cuantos caracteres hay entre
	'A' y 'a'.

	El orden (número ASCII) de 'A' es 65 y el de 'a' 97.
	Por tanto, hay 97-65 = 32 caracteres entre ellos. 
	Así pues, bastaría considerar 
   
		letra_minuscula = letra_mayuscula + 32   
		letra_mayuscula = letra_minuscula - 32   
   
	El problema es que debo conocer el número "mágico" 32 --> NO HACERLO ASÍ
	*/
	
	letra_mayuscula = letra_minuscula - 32;      // :-(  MALA PRÁCTICA
   
	cout << endl;
	cout << "(1) El caracter " << letra_minuscula
         << " pasado a mayuscula es: " << letra_mayuscula << endl;
	cout << endl;


	/*
	El número de caracteres que hay entre 'A' y 'a' puede calcularse con 
	la expresión (int) 'a'-'A', que devuelve 32.
	Observe -será de utilidad- que 'a'-'a' es 0, 'b'-'a' es 1, ...
	*/

	const int DISTANCIA_MAY_MIN = 'a'-'A';    // :-)  BIEN HECHO
  
	letra_mayuscula = letra_minuscula - DISTANCIA_MAY_MIN;      // :-)
  
	cout << endl;
	cout << "(2) El caracter " << letra_minuscula
         << " pasado a mayuscula es: " << letra_mayuscula << endl;
	cout << endl;
   
	/*
	La menor minúscula es 'a' por lo que todas las demás se obtienen 
	sumando "salto" (0,1,2,...,'z'-'a') al carácter 'a'. Con las mayúsculas 
	ocurre algo similar: la menor es 'A' y todas las demás mayúsculas se 
	obtienen sumando "salto" (0,1,2,...,'Z'-'A') al carácter 'A'. 
	La distancia entre una letra "letra_minuscula" y 'a' es la misma que 
	la que hay entre "letra_mayuscula" y 'A' --> aprovechemos este hecho.
	*/
	
	int distancia_minuscula_a = letra_minuscula - 'a'; 

	letra_mayuscula = 'A' + distancia_minuscula_a;      // :-)
  	
   
	cout << endl;
	cout << "(3) El caracter " << letra_minuscula
         << " pasado a mayuscula es: " << letra_mayuscula << endl;
	cout << endl;
	
	return 0;	
}
