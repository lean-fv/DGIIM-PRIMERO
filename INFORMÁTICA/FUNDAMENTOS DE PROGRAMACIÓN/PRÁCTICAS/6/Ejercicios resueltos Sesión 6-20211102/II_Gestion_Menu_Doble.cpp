/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 2
//
/* 	
	En este programa en el que se presente un menú principal para que el 
	usuario pueda elegir las siguientes opciones:
	
		A–>Calcular adición.
		P–>Calcular producto.
		X–>Salir.

	Si el usuario elige en el menú principal:

		(X) Salir --> el programa terminará su ejecución.
		(A) Calcular adición --> se presenta un menú (secundario) para que 
			el usuario pueda elegir entre las siguientes opciones:

			S–>Calcular suma.
			R–>Calcular resta.
			X–>Salir.

		(P) Calcular producto --> se presenta un menú (secundario) para que 
			el usuario pueda elegir entre las siguientes opciones:

			M–>Calcular multiplicación.
			D–>Calcular división.
			X–>Salir.

	En las operaciones seleccionadas desde los menús secundarios el programa 
	pedirá dos números reales, realizará la operación seleccionada, mostrará 
	el resultado y volverá a mostrar el menú secundario seleccionado 
	anteriormente.
	En los dos menús secundarios la selección de (X) Salir hace que el 
	programa vuelva a mostrar el menú principal.
*/
/***************************************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 
	
	
	bool seguir_en_menu_principal = true; 
	char opcion;
		
	while (seguir_en_menu_principal) {
		
		// Mostrar opciones - Menú principal"
		
		cout << endl << endl;
		cout << "A -> Calcular adicion." << endl;
		cout << "P -> Calcular producto." << endl;
		cout << "X -> Salir." << endl;
		
		// Leer opción
		
		bool error_opcion;
		
		do {
			cout << endl;
			cout << "Introduzca la opcion elegida --> ";
			cin >> opcion;
			opcion = toupper(opcion);
			
			error_opcion = (opcion!='A' && opcion!='P' && opcion!='X');
			
		} while (error_opcion);	
		
		// Dirigir el flujo según la opción
		
		switch (opcion) {
			
			case ('X'):	{ // Salir
				
				seguir_en_menu_principal = false;
				break;
			}
	
			case ('A'): { // Adición							
				
				bool seguir_en_menu_secundario = true; 
				char opcion;
					
				while (seguir_en_menu_secundario) {
					
					// Mostrar opciones - Menú "Adición"
					
					cout << endl << endl;
					cout << "S -> Calcular suma." << endl;
					cout << "R -> Calcular resta." << endl;
					cout << "X -> Salir." << endl;	
					
					// Leer opción
					
					bool error_opcion;
					
					do {
						cout << endl;
						cout << "Introduzca la opcion elegida --> ";
						cin >> opcion;
						opcion = toupper(opcion);
						
						error_opcion = (opcion!='S'&&opcion!='R'&&opcion!='X');
						
					} while (error_opcion);				
					
													
					// Dirigir el flujo según la opción
					// En este punto, opcion vale 'X', 'S' ó 'R'
	
					switch (opcion) {
						
						case ('X'):	{ 
	
							seguir_en_menu_secundario = false;
							break; 
							
						} // case ('X')
						
						case ('S'): {  // Suma				

							double valor1, valor2, resultado; 
	
							cout << endl;										
							cout << "Introduzca operando 1: "; 
							cin >> valor1; 
							cout << "Introduzca operando 2: "; 
							cin >> valor2; 
													
							resultado = valor1 + valor2 ;
	
							cout << endl;
							cout << "El resultado es: " << resultado << endl;
							cout << endl;
							
							break; 	
							
						} // case ('S')
							
						case ('R'): {   // Resta		
										
							double valor1, valor2, resultado; 
								
							cout << endl;										
							cout << "Introduzca operando 1: "; 
							cin >> valor1; 
							cout << "Introduzca operando 2: "; 
							cin >> valor2; 
													
							resultado = valor1 - valor2 ;
	
							cout << endl;
							cout << "El resultado es: " << resultado << endl;
							cout << endl;
							
							break; 	
								
						} // case ('R')
																			
					}  // switch (opcion)
					
				} // while (seguir_en_menu_secundario) 		
				
				break; 	
				
			} // case ('A')
			
			
			case ('P'):  { // Producto

				bool seguir_en_menu_secundario = true; 
				char opcion;
					
				while (seguir_en_menu_secundario) {
							
					// Mostrar opciones - Menú "Producto"
					
					cout << endl << endl;
					cout << "M -> Calcular multiplicacion." << endl;
					cout << "D -> Calcular division." << endl;
					cout << "X -> Salir." << endl;	
					
					// Leer opción
					
					bool error_opcion;
					
					do {
						cout << endl;
						cout << "Introduzca la opcion elegida --> ";
						cin >> opcion;
						opcion = toupper(opcion);
						
						error_opcion = (opcion!='M'&&opcion!='D'&&opcion!='X');
						
					} while (error_opcion);				
					
													
					// Dirigir el flujo según la opción
					// En este punto, opcion vale 'X', 'M' ó 'D'

					switch (opcion) {
						
						case ('X'): { // Terminar
	
							seguir_en_menu_secundario = false;
							break; 
							
						} // case ('X')
					
						case ('M'): {  // Multiplicación				

							double valor1, valor2, resultado; 
	
							cout << endl;										
							cout << "Introduzca operando 1: "; 
							cin >> valor1; 
							cout << "Introduzca operando 2: "; 
							cin >> valor2; 
													
							resultado = valor1 * valor2 ;
	
							cout << endl;
							cout << "El resultado es: " << resultado << endl;
							cout << endl;
							
							break; 	
							
						} // case ('M')
						
						case ('D'): {  // División		

							double valor1, valor2, resultado; 
											
							cout << endl;										
							cout << "Introduzca operando 1: "; 
							cin >> valor1; 
							cout << "Introduzca operando 2: "; 
							cin >> valor2; 
													
							resultado = valor1 / valor2 ;
	
							cout << endl;
							cout << "El resultado es: " << resultado << endl;
							cout << endl;
							
							break; 
							
						} // case ('D')
	
					}  // switch (opcion)
					
				} // while (seguir_en_menu_secundario) 				
				
				break; 	
				
			} // case ('P')
			
		} // switch (opcion)
		
	} // while (seguir_en_menu_principal) 

	cout << endl << endl;
	
	return 0;
}

/***************************************************************************/
/***************************************************************************/
