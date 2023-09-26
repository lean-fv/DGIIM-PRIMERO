/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 5 (Arrays)
// 
/*	
	Programa que lee un número indeterminado de caracteres (la lectura 
	termina cuando se introduce un '*') y muestra estadísticas sobre 
	los caracteres introducidos. 
	 
	(ver enunciado para más detalles) 
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;
 
/***************************************************************************/

int main (void)
{	

	const char TERMINADOR = '*';
	
	// Vector de datos. Declaración e inicialización.
	
	const int NUM_LETRAS = 'Z'-'A'+1; 
	
	int contador[NUM_LETRAS] = {0};
	
	const long TAM = 20000;
	char texto[TAM];

	// Lectura de datos 

	cout << "Introduzca un serie indeterminada de caracteres." << endl;
	cout << "Escriba libremente, con espacios y saltos de linea. " << endl;
	cout << "Puede corregir. Al pulsar ENTER la linea queda validada." << endl;
	cout << "--> Para terminar escriba  *" << endl;
	cout << endl;
	
	
	int cont_total = 0;  // Contador de caracteres leidos 
	int cont_sep = 0;	 // Contador de separadores
	int cont_letras = 0; // Contador de letras
	int cont_otros = 0;  // Contador de "otros"

	
	char caracter;
	
	caracter = cin.get();
	
	while ( caracter != TERMINADOR) {
	
		cont_total++;
		
		if (isalpha(caracter))	{

			cont_letras++; 
			
			caracter = toupper(caracter);
			contador[caracter-'A']++;
		}
		else 
			if (isspace(caracter)) cont_sep++;
			else cont_otros++;
			
		caracter = cin.get();

	}


	// Presentación de resultados
	
	// Resumen
			 	
	cout << endl;	
	cout << "Total letras    = " << setw(6) << cont_letras << endl;
	cout << "Total sepadores = " << setw(6) << cont_sep << endl;
	cout << "Total \"otros\"   = " << setw(6) << cont_otros << endl;
	cout << endl;
	cout << "Total global    = " << setw(6) << cont_total << endl;	
	cout << endl;
	
	
	// Mostrar letras que no han aparecido
	
	cout << "Letras que no han aparecido: ";	
	
	int cont_letras_no_aparecidas  = 0; 
	
	for (int pos=0; pos<NUM_LETRAS; pos++) {
		
		char letra = 'A' + pos;
					
		if (contador[pos] == 0) {
			cout << letra << " ";
			cont_letras_no_aparecidas++;
		}
				
	}
	
	cout << endl;
	if (cont_letras_no_aparecidas > 0) 
		cout << "Num. de letras no aparecidas = " 
		     << setw(6) << cont_letras_no_aparecidas << endl;	
	else 
		cout << "Han aparecido todas las letras. " << endl;	
	cout << endl << endl;

	
	// Mostrar letras que han aparecido
	
	int cont_letras_aparecidas = 0; // Contador de letras

	for (int pos=0; pos<NUM_LETRAS; pos++) {
		
		char letra = 'A' + pos;
	
		// Solo procesamos si hay alguna letra	
				
		if (contador[pos] != 0) {
			cout << letra << " --> " << setw(6) << contador[pos] << endl; 
			cont_letras_aparecidas += contador[pos];
		}
	}
	
	// Comprobación de integridad
	if (cont_letras+cont_sep+cont_otros != cont_total) {
		cout << endl;
		cout << "Error de integridad (1)." << endl; 
		cout << endl;
	}	
	if (cont_letras != cont_letras_aparecidas) {
		cout << endl;
		cout << "Error de integridad (2)." << endl; 
		cout << endl;
	}
	
	
	// Calcular la letra más y menos frecuente entre las que han aparecido 
	// al menos una vez. 
	
	int min_veces = cont_total+1; // primer minimo
	int max_veces = 0; 			  // primer maximo
	char min_letra, max_letra;
	
	
	for (int pos=0; pos<NUM_LETRAS; pos++) {
		
		char letra = 'A' + pos;
	
		// Solo procesamos si hay alguna letra	
				
		if (contador[pos] != 0) {
			
			if (contador[pos] < min_veces) {
				min_veces = contador[pos];	
				min_letra = letra;
			}
			if (contador[pos] > max_veces) {
				max_veces = contador[pos];	
				max_letra = letra;
			}	
			
		}
	}
	
	cout << endl;	
	cout << "Letra menos frecuente = " << min_letra << ". ";
	cout << "Veces que aparece = " << setw(6) << min_veces << endl;
	cout << "Letra mas frecuente   = " << max_letra << ". ";
	cout << "Veces que aparece = " << setw(6) << max_veces << endl;	
	cout << endl << endl;

	return 0;
}
