/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 3
// 
/*
	Programa que usa las funciones 
	
		string EliminaUltimosSeparadores (string cad);
		string EliminaPrimerosSeparadores (string cad);

	que eliminan todos los separadores finales e iniciales, respectivamente, 
	de la cadena "cad". Devuelven una copia de "cad" después de haber 
	eliminado los separadores.
	
	Se añade la función 

		string EliminaSeparadoresInicialesyFinales (string cadena);
		
	que elimina todos los separadores finales e iniciales de la cadena 
	"cad". Devuelve una copia de "cad" después de haber eliminado los 
	separadores. Se basa en las anteriores.  		
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/***************************************************************************/
// Comprueba si un caracter dado es un separador. Los caracteres separadores 
// son el espacio en blanco, el tabulador y el salto de línea. 
// Función similar a isspace(). 
// 
// Recibe:  c, carácter a comprobar.
// Devuelve:  true si "c" es un caracter separador, y false en otro caso.
/***************************************************************************/

bool EsSeparador (char c) 
{
	return (c==' ' || c=='\t' || c=='\n');
}

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
// Devuelve una NUEVA cadena, resultante de eliminar los últimos caracteres 
// separadores de "cadena". Los caracteres separadores son el espacio en 
// blanco, el tabulador y el salto de línea. 
// Usaremos la función isspace() para simplificar el cálculo. 
// 
// Recibe:  cadena, string sobre la que se va a trabajar.
// Devuelve: cadena resultante de eliminar los últimos separadores de "cadena".
/***************************************************************************/

string EliminaUltimosSeparadores (string cadena)
{

   	while (cadena.length()>0 && isspace(cadena.back()))
		cadena.pop_back();
		
	/* El ciclo while podría sustituirse por este:
   	
	   while (cadena.length()>0 && EsSeparador(cadena.back()))
		cadena.pop_back();
	*/	
        
	return (cadena);
}

/***************************************************************************/
// Devuelve una NUEVA cadena, resultante de eliminar los primeros caracteres 
// separadores de "cadena". Los caracteres separadores son el espacio en 
// blanco, el tabulador y el salto de línea. 
// Usaremos la función isspace() para simplificar el cálculo. 
// 
// Recibe:  cadena, string sobre la que se va a trabajar.
// Devuelve: cadena resultante de eliminar los primeros separadores de "cadena".
/***************************************************************************/

string EliminaPrimerosSeparadores (string cadena)
{	
	// Buscar el primer carácter no espacio
	int pos = 0;
	while (pos <cadena.length() && isspace(cadena.at(pos))) pos++;
	
	/* El ciclo while podría sustituirse por este:
   	
	  	while (pos <cadena.length() && EsSeparador(cadena.at(pos))) pos++;
	*/	
	
	string local; 
	
	// Copiar todos los que quedan
	while (pos <cadena.length()) {
		local.push_back(cadena.at(pos));
		pos++;
	}
		
	return (local);
}

/***************************************************************************/
// Devuelve una NUEVA cadena, resultante de eliminar los caracteres 
// separadores iniciales y finales de "cadena". Los caracteres separadores 
// son el espacio en blanco, el tabulador y el salto de línea. 
// Usaremos la función isspace() para simplificar el cálculo. 
// 
// Recibe:  cadena, string sobre la que se va a trabajar.
// Devuelve: cadena resultante de eliminar los primeros separadores de "cadena".
/***************************************************************************/

string EliminaSeparadoresInicialesyFinales (string cadena)
{	
	return (EliminaUltimosSeparadores(EliminaPrimerosSeparadores(cadena))); 
}


/***************************************************************************/
// Una versión diferente de EliminaPrimerosSeparadores que usa la 
// función EliminaPrimeros
//
// Devuelve una NUEVA cadena, resultante de eliminar los primeros caracteres 
// separadores de "cadena". Los caracteres separadores son el espacio en 
// blanco, el tabulador y el salto de línea. 
// Usaremos la función isspace() para simplificar el cálculo. 
// 
// Recibe:  cadena, string sobre la que se va a trabajar.
// Devuelve: cadena resultante de eliminar los primeros separadores de "cadena".
/***************************************************************************/

string EliminaPrimerosSeparadores2 (string cadena)
{	
	// Buscar el primer carácter no espacio
	while (isspace(cadena.at(0))) 
		cadena = EliminaPrimeros(cadena, cadena.at(0));
		
	/* El ciclo while podría sustituirse por este:
	
	while (EsSeparador(cadena.at(0))) 
		cadena = EliminaPrimeros(cadena, cadena.at(0));
	*/	
	
	return (cadena);
}

/***************************************************************************/
// Una versión diferente de EliminaUltimosSeparadores que usa la 
// función EliminaUltimos
//
// Devuelve una NUEVA cadena, resultante de eliminar los últimos caracteres 
// separadores de "cadena". Los caracteres separadores son el espacio en 
// blanco, el tabulador y el salto de línea. 
// Usaremos la función isspace() para simplificar el cálculo. 
// 
// Recibe:  cadena, string sobre la que se va a trabajar.
// Devuelve: cadena resultante de eliminar los últimos separadores de "cadena".
/***************************************************************************/

string EliminaUltimosSeparadores2 (string cadena)
{

   	while (cadena.length()>0 && isspace(cadena.back()))
		cadena = EliminaUltimos(cadena, cadena.back());
		
	/* El ciclo while podría sustituirse por este:
   	
	while (cadena.length()>0 && EsSeparador(cadena.back()))
		cadena = EliminaUltimos(cadena, cadena.back());
	*/	
        
	return (cadena);
}

/***************************************************************************/
// Una versión diferente de EliminaUltimosSeparadores que usa las 
// funciones EliminaPrimerosSeparadores2 y EliminaUltimosSeparadores2
//
// Devuelve una NUEVA cadena, resultante de eliminar los caracteres 
// separadores iniciales y finales de "cadena". Los caracteres separadores 
// son el espacio en blanco, el tabulador y el salto de línea. 
// Usaremos la función isspace() para simplificar el cálculo. 
// 
// Recibe:  cadena, string sobre la que se va a trabajar.
// Devuelve: cadena resultante de eliminar los primeros separadores de "cadena".
/***************************************************************************/

string EliminaSeparadoresInicialesyFinales2 (string cadena)
{	
	return (EliminaUltimosSeparadores2(EliminaPrimerosSeparadores2(cadena))); 
}


/***************************************************************************/
/***************************************************************************/

int main()
{	
	const char SEP_ABRE = '[';
	const char SEP_CIERRA = ']';
	
	string cad1 = "   123456789    \n  \t  ";
	string cad2 = "\t\t   987654321.123\n\n  ";
	
	cout << endl; 	
	cout << "Original: " << SEP_ABRE << cad1 << SEP_CIERRA << endl; 
	cout << "EliminaPrimerosSeparadores: " << SEP_ABRE 
		 << EliminaPrimerosSeparadores(cad1) << SEP_CIERRA << endl; 
	cout << "EliminaUltimosSeparadores: " << SEP_ABRE 
		 << EliminaUltimosSeparadores(cad1) << SEP_CIERRA << endl; 
	cout << "Elimina todos (1): " << SEP_ABRE 
		 << EliminaPrimerosSeparadores(EliminaUltimosSeparadores(cad1)) 
		 << SEP_CIERRA << endl; 
	cout << "Elimina todos (2): " << SEP_ABRE 
		 << EliminaUltimosSeparadores(EliminaPrimerosSeparadores(cad1)) 
		 << SEP_CIERRA << endl; 
	cout << "EliminaSeparadoresInicialesyFinales: " << SEP_ABRE 
		 << EliminaSeparadoresInicialesyFinales(cad1) 
		 << SEP_CIERRA << endl; 
		 
		 
	cout << endl; 
	cout << "-------------------" << endl; 

	cout << endl; 	
	cout << "Original: " << SEP_ABRE << cad2 << SEP_CIERRA << endl; 
	cout << "EliminaPrimerosSeparadores: " << SEP_ABRE 
		 << EliminaPrimerosSeparadores(cad2) << SEP_CIERRA << endl; 
	cout << "EliminaUltimosSeparadores: " << SEP_ABRE 
		 << EliminaUltimosSeparadores(cad2) << SEP_CIERRA << endl; 
	cout << "Elimina todos (1): " << SEP_ABRE 
		 << EliminaPrimerosSeparadores(EliminaUltimosSeparadores(cad2)) 
		 << SEP_CIERRA << endl; 
	cout << "Elimina todos (2): " << SEP_ABRE 
		 << EliminaUltimosSeparadores(EliminaPrimerosSeparadores(cad2)) 
		 << SEP_CIERRA << endl; 
	cout << "EliminaSeparadoresInicialesyFinales: " << SEP_ABRE 
		 << EliminaSeparadoresInicialesyFinales(cad2) 
		 << SEP_CIERRA << endl; 		 
	cout << endl; 
	
	
	cout << endl; 
	cout << "-------------------" << endl; 
	
	string cad3 = "  \t   \n\n   qwerty    \n  \t  ";
	string cad4 = "\n\t\t  \t\tzxcvbnm\n\n \t\t \n\n";
	
	cout << endl; 	
	cout << "Original: " << SEP_ABRE << cad3 << SEP_CIERRA << endl; 
	cout << "EliminaPrimerosSeparadores2: " << SEP_ABRE 
		 << EliminaPrimerosSeparadores2(cad3) << SEP_CIERRA << endl; 
	cout << "EliminaUltimosSeparadores2: " << SEP_ABRE 
		 << EliminaUltimosSeparadores2(cad3) << SEP_CIERRA << endl; 
	cout << "Elimina todos (1): " << SEP_ABRE 
		 << EliminaPrimerosSeparadores2(EliminaUltimosSeparadores2(cad3)) 
		 << SEP_CIERRA << endl; 
	cout << "Elimina todos (2): " << SEP_ABRE 
		 << EliminaUltimosSeparadores2(EliminaPrimerosSeparadores2(cad3)) 
		 << SEP_CIERRA << endl; 		 
	cout << "EliminaSeparadoresInicialesyFinales2: " << SEP_ABRE 
		 << EliminaSeparadoresInicialesyFinales2(cad3) 
		 << SEP_CIERRA << endl; 
		 
	cout << endl; 	
	cout << "Original: " << SEP_ABRE << cad4 << SEP_CIERRA << endl; 	 		 
	cout << "EliminaPrimerosSeparadores2: " << SEP_ABRE 
		 << EliminaPrimerosSeparadores2(cad4) << SEP_CIERRA << endl; 
	cout << "EliminaUltimosSeparadores2: " << SEP_ABRE 
		 << EliminaUltimosSeparadores2(cad4) << SEP_CIERRA << endl; 
	cout << "Elimina todos (1): " << SEP_ABRE 
		 << EliminaPrimerosSeparadores2(EliminaUltimosSeparadores2(cad4)) 
		 << SEP_CIERRA << endl; 
	cout << "Elimina todos (2): " << SEP_ABRE 
		 << EliminaUltimosSeparadores2(EliminaPrimerosSeparadores2(cad4)) 
		 << SEP_CIERRA << endl; 		 
	cout << "EliminaSeparadoresInicialesyFinales2: " << SEP_ABRE 
		 << EliminaSeparadoresInicialesyFinales2(cad4) 
		 << SEP_CIERRA << endl; 
	cout << endl; 	
		 	
	return 0;
}

/***************************************************************************/
/***************************************************************************/
