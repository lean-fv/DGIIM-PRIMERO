/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 3
//
/* 
	Programa que usa las funciones EliminaUltimos y EliminaPrimeros
	
	* 	EliminaUltimos elimina todos los caracteres finales de un
		string que son igual a un carácter determinado.

			Por ejemplo, al borrar la T del final de la cadena TabcTdTTTT 
			se obtendría la cadena TabcTd. Si la cadena fuese TabcTd, 
			el resultado de borrar la T del final de la cadena sería la 
			misma cadena TabcTd, ya que no hay ninguna T al final.

	*	EliminaPrimeros elimina todos los caracteres iniciales de
		un string que sean igual a un carácter determinado.
			
			Por ejemplo, al borrar la T del inicio de la cadena TabcTdTTTT 
			se obtendría la cadena abcTdTTTT. Si la cadena fuese abcTdTTTT, 
			el resultado de borrar la T del inicio de la cadena sería la 
			misma cadena abcTdTTTT, ya que no hay ninguna T al principio.

			NOTA: Se emplea un string local a la función para copiar a
				éste los caracteres de las posiciones p, p + 1, . . . de la 
				cadena original si todos los caracteres de las posiciones 
				0, 1, . . . , p..1 son iguales, e iguales al que se quiere 
				borrar. La función devolverá una copia de ese string local.
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


/***************************************************************************/
// Devuelve una NUEVA cadena, resultante de eliminar los últimos caracteres 
// de "cadena" iguales a "a_borrar".
// Recibe:  cadena, string sobre la que se va a trabajar
//			a_borrar, el carácter que se va a borrar
// Devuelve: la cadena resultante de eliminar los últimos caracteres de 
// 			"cadena" iguales a "a_borrar"
/***************************************************************************/

string EliminaUltimos(string cadena, char a_borrar)
{
   	while (cadena.length()>0 && cadena.back() == a_borrar)
		cadena.pop_back();
        
	return (cadena);
}

/***************************************************************************/
// Devuelve una NUEVA cadena, resultante de eliminar los primeros caracteres 
// de "cadena" iguales a "a_borrar".
// Recibe:  cadena, string sobre la que se va a trabajar
//			a_borrar, el carácter que se va a borrar
// Devuelve: la cadena resultante de eliminar los últimos caracteres de 
// 			"cadena" iguales a "a_borrar"
/***************************************************************************/

string EliminaPrimeros(string cadena, char a_borrar)
{	
	// Buscar el primer carácter diferente a "a_borrar"
	int pos = 0;
	while (pos <cadena.length() && cadena.at(pos) == a_borrar) pos++;

	string local; // Para el resultado
	
	// Copiar todos los que quedan
	while (pos <cadena.length()) {
		local.push_back(cadena.at(pos));
		pos++;
	}
		
	return (local);
}

/***************************************************************************/
/***************************************************************************/

int main()
{	
	string cad1 = "TabcTdTTTT";
	string cad2 = "TabcTd";
	string cad3 = "abcTdTTTT";

	
	cout << endl; 	
	cout << "Eliminar ultimos: " << endl; 
	cout << "\tOriginal : " <<"|" << cad1 << "|" << endl; 
	cout << "\tResultado: " <<"|" << EliminaUltimos(cad1, 'T') <<"|" <<endl; 
	cout << endl; 		
	cout << "\tOriginal : " <<"|" << cad2 << "|" << endl; 
	cout << "\tResultado: " <<"|" << EliminaUltimos(cad2, 'T') <<"|" <<endl; 	
	cout << endl; 	
	cout << "\tOriginal : " <<"|" << cad3 << "|"<< endl; 
	cout << "\tResultado: " <<"|" << EliminaUltimos(cad3, 'T') <<"|" <<endl; 	
		 
	cout << endl; 	
	cout << "Eliminar primeros: " << endl; 
	cout << "\tOriginal : " <<"|" << cad1 << "|" << endl; 
	cout << "\tResultado: " <<"|" << EliminaPrimeros(cad1, 'T') <<"|" <<endl; 
	cout << endl; 	
	cout << "\tOriginal : " <<"|" << cad2 << "|" << endl; 
	cout << "\tResultado: " <<"|" << EliminaPrimeros(cad2, 'T') <<"|" <<endl; 	
	cout << endl; 	
	cout << "\tOriginal : " <<"|" << cad3 << "|"<< endl; 
	cout << "\tResultado: " <<"|" << EliminaPrimeros(cad3, 'T') <<"|" <<endl; 	
	cout << endl; 	
		 		
	return 0;
}

/***************************************************************************/
/***************************************************************************/
