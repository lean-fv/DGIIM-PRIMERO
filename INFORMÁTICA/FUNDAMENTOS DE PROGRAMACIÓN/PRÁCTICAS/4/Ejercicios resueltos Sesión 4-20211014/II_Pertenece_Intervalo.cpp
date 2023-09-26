/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 2
/*	
   Programa que lee y muestra un intervalo. La lectura no es nada sofisticada, 
   se hace elemento a elemento (ver enunciado).
   A continuación lee un valor e indica si pertenece o no al intervalo.  
*/
/***************************************************************************/

#include <iostream>
#include <string>

using namespace std;

int main() {
	
	const char ABIERTO_IZDA = '(';
	const char ABIERTO_DCHA = ')';
	const char CERRADO_IZDA = '[';
	const char CERRADO_DCHA = ']';
	
	// Variables de entrada
	double a, b;  	// Cotas del intervalo
	char caracter_izda, caracter_dcha; // Delimitadores
	char separador; // Separador entre cotas
	
	
	// Entrada
	
	cout << "Escriba el intervalo: ";
	
	cin >> caracter_izda; 
	cin >> a;
	cin >> separador; 
	cin >> b;
	cin >> caracter_dcha; 

	// Comprobar la validez de los caracteres de entrada
	// y determinar el tipo de intervalo
	
	bool abierto_izda = false, abierto_dcha = false;
	bool cerrado_izda = false, cerrado_dcha = false;
	bool error_izda = false, error_dcha = false, error_separador = false;
	bool error; 
	
	
	char marca_izda, marca_dcha; // Caracteres a mostrar 
	
	if (caracter_izda=='(') {
		abierto_izda = true; 	
		marca_izda = ABIERTO_IZDA;
	}
	else 
		if (caracter_izda=='[') {
			cerrado_izda = true;
			marca_izda = CERRADO_IZDA;		
		}
		else error_izda = true;  
	
	if (caracter_dcha==')') {
		abierto_dcha = true; 
		marca_dcha = ABIERTO_DCHA;			
	}
	else 
		if (caracter_dcha==']') {
			cerrado_dcha = true;
			marca_dcha = CERRADO_DCHA;				
		}
		else error_dcha = true;  

	if (separador!=',') error_separador = true; 
	
	// Cualquiera de los tres tipos de error impide continuar 
	error = (error_izda || error_dcha || error_separador);
	
	if (!error) {
 
	 	// Salida (presentación del intervalo)
			
		cout << endl;
		cout << "Intervalo: "  << marca_izda << " " << a << " " 
		     << separador << " " << b << " " << marca_dcha;
		cout << endl;
		
		
		// Versión 2: separamos cálculos de la presentación.
		
		/*  Se trata de componer una dato string a partir de los datos leidos 
		 	y darle la apariencia de un intervalo. Emplearemos el operador + 
		 	para componer el string mediante concatenación y la función 
			to_string para convertir los datos double a string.
		*/
	
		// Cálculos
		
		string intervalo; 	// Inicialmente, cadena vacía. Se puede inicializar 
							// explícitamente: string intervalo = ""; 
	
		intervalo = intervalo + marca_izda + to_string(a) + separador;
		intervalo = intervalo + " " + to_string(b) + marca_dcha;
				
		// Salida  (presentación del intervalo)
		
		cout << endl;
		cout << "Intervalo: "  << intervalo;
		cout << endl;
	
		
		// Entrada: valor a comprobar
		
		double candidato; 
		
		cout << "Valor a comprobar: ";
		cin >> candidato; 	

		// Cálculos (pertenencia) 
		
		bool valido_izda = ((candidato >= a) && (cerrado_izda)) || 
		    ((candidato > a) && (abierto_izda));
		bool valido_dcha = ((candidato <= b) && (cerrado_dcha)) || 
		    ((candidato < b) && (abierto_dcha));
		    
		    
		// Salida    
		
		if (valido_izda && valido_dcha) {			
			cout << endl;
			cout << "El valor " << candidato << " pertenece a " << intervalo; 
			cout << endl << endl;
		}    
		else {	    
			cout << endl;
			cout << "El valor " << candidato <<" NO pertenece a " << intervalo; 
			cout << endl << endl;
		}    			
	
	} // if (!error)
	
	else { // error
		
		cout << endl;
		cout << "Error en la entrada del intervalo." << endl;
		cout << endl;
	}

   return 0;
}

