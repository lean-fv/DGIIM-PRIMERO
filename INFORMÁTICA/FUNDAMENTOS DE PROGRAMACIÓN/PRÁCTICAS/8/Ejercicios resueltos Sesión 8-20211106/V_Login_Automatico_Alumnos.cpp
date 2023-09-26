/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 5 (Arrays)
/*	
	Se está diseñando un sistema web que recolecta datos personales 
	de un usuario y, en un momento dado, debe sugerirle un nombre de 
	usuario (login). 
	Dicho login estará basado en el nombre y los apellidos, en concreto 
	estará formado por los N primeros caracteres de cada nombre y apellido 
	(en minúusculas, unidos y sin espacios en blanco). 
	
		Por ejemplo, si el nombre es "Antonio Francisco Molina Ortega" 
		y N=2, el nombre de usuario sugerido será "anfrmoor".

	Debe tener en cuenta que el número de palabras que forman el nombre y 
	los apellidos puede ser cualquiera. Además, si N es mayor que alguna de 
	las palabras que aparecen en el nombre, se incluirá la palabra completa. 
	
		Por ejemplo, si el nombre es "Ana CAMPOS de la Blanca" y N=4, 
		entonces la sugerencia será "anacampdelablan" (observe que se pueden 
		utilizar varios espacios en blanco para separar palabras).

	Implemente un módulo que reciba una cadena de caracteres formada por nombre 
	y apellidos (separados por uno o más espacios en blanco) y un valor entero 
	N y que devuelva otra cadena con la sugerencia de login.
*/
/*********************************************************************/


#include <iostream>
#include <string>
#include <cctype>
using namespace std;


/***************************************************************************/
// Codifica la cadena "cad" de acuerdo a "n". Toma los primeros "n" 
// caracteres de cada palabra de "cad". Si alguna palabra no tiene "n" 
// caracteres, los toma todos. 
//
// Recibe:  cad, la cadena que se va a codificar.
// 			n, el número de caracteres que se van a tomar de cada palabra. 
// Devuelve: la cadena codificada. 
//
// PRE: 0 < n
// 		longitud(cad) > 0
/***************************************************************************/

string Codifica (string cad, int n) 
{
	string login = ""; // variable local para devolver la cadena de login

	int long_cadena = cad.length(); // longitud de "nombre"

	int contador_copiados = 0; 

	for (int pos_lectura = 0; pos_lectura < long_cadena; pos_lectura++) {

		if (!(isspace(cad[pos_lectura])) && (contador_copiados < n)) {

			char c = tolower(cad[pos_lectura]);	// Se añade el caracter 
			login = login + c;					// en minúsculas

			contador_copiados++;
		}

		if (isspace(cad[pos_lectura])) // Palabra nueva
			contador_copiados = 0; 
	}

	return (login);
}

/*********************************************************************/

int main (void)
{
	string nombre_completo; // Nombre y apellidos
	string login_sugerido;	// Resultado --> sugerencia de login

	const string TERMINADOR = "FIN";
		
	int num_caracteres;		// Num. máximo de caracteres por palabra 


	string cad_leida; 	// Las lecturas se recogen en este string
	
	
	// Lectura adelantada 

	cout << endl; 
	do {			
		cout << "Nombre y apellidos (terminar con " << TERMINADOR <<"): ";
		getline (cin, cad_leida); 
	} while (cad_leida.length()==0);

	// Ciclo principal

	while (cad_leida != TERMINADOR) {

		nombre_completo = cad_leida;

		// La lectura del número de caracteres confía en la honestidad 
		// del usuario respecto al valor dado (supone que puede convertirse 
		// a un dato int).
		
		do {
			cout << "Introduzca número de caracteres: ";
			getline (cin, cad_leida); 
			num_caracteres = stoi (cad_leida);
		} while (num_caracteres <= 0);


		cout << endl; 
		cout << "Nombre y apellidos: " << nombre_completo << endl; 
		cout << "número de caracteres = " << num_caracteres << endl; 

		login_sugerido =  Codifica (nombre_completo, num_caracteres);

		cout << endl; 
		cout << "Sugerencia de login: " << login_sugerido << endl; 

		
		// Nueva lectura adelantada 

		cout << endl; 
		do {
			cout << "Nombre y apellidos (terminar con " << TERMINADOR <<"): ";
			getline (cin, cad_leida); 
		} while (cad_leida.length()==0);

	}

	cout << endl << endl; 
}
