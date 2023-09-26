/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 1
/*	
   Entradas: string de 53 caracteres con formato:  
             sección (3 digitos -o espacios-) subsección (ídem)
             subsubsección (ídem) título (40 caracteres) 
             página (4 digitos -o espacios-)
   Salidas:  muestra el valor de cada componente por separado: sección, 
   			 subsección, subsubsección, título y página.
   			 
   	Ejemplos de string de entrada (los puntos indican espacios): 
   	
   	|..1......Introducción.a.la.Programación..............1|
   	|..1..1...El ordenador,.algoritmos.y.programas........2|
   	|..1..1...El Ordenador:.Conceptos.Básicos.............2|
   	|..1..1..1El Ordenador:.Conceptos.Básicos.............2|
   	|..1..1..2Datos.y.algoritmos..........................3|
   	|..1..1..3Lenguajes.de.programación...................6|
   	|..1..1..4Compilación................................13|
   	|..1..2...Especificación.de.programas................14|
*/
/***************************************************************************/

#include <iostream>   // Recursos de E/S
#include <string>     // Recursos para string 
#include <iomanip>    // Recursos de formato 
using namespace std;

int main()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	
	string cadena_leida; 
	
	int seccion, subseccion, subsubseccion; // Localización del apartado 
	string titulo; // Titulo del apartado
	int pagina; // Núm. página donde empieza el apartado

	// Entrada
		
	//cout << "Introduzca cadena de indice para analizar: ";
	getline (cin, cadena_leida); 


	// Cálculos
	
	seccion = stoi(cadena_leida.substr (0,3));
	subseccion = stoi(cadena_leida.substr (3,3));
	subsubseccion = stoi(cadena_leida.substr (6,3)); ;
	titulo = cadena_leida.substr (9,40);
	pagina = stoi(cadena_leida.substr (49,4));
	
	// Resultado

	cout << endl; 	
	cout << "Cadena leida: " << "|" << cadena_leida << "|" 
	     << " Longitud = " << setw(3) << cadena_leida.length() << endl; 	
	cout << endl; 	
	cout << "Seccion:       " << setw(3) << seccion << endl; 
	cout << "Subseccion:    " << setw(3) << subseccion << endl;
	cout << "Subsubseccion: " << setw(3) << subsubseccion << endl; 
	cout << "Pagina:        " << setw(3) << pagina << endl; 
	cout << "Titulo:        " << titulo << endl; 
	cout << endl;  
	cout << seccion << "."<< subseccion << "."<< subsubseccion << ". " 
	     << setw(40) << titulo << setw(4) << pagina << endl; 
	cout << endl;  
	
	return 0;
}
