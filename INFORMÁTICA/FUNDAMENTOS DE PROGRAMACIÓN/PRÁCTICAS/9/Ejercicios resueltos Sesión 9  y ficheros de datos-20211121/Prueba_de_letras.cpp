/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
/* 	
	Prueba de lectura y gestión de caracteres especiales del español. 
	
	CONSEJO: ejecutar usando redirección de E y S
	
	Prueba_de_letras < caracteres_especiales_fin_asterisco.txt > resultado
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <clocale> 

using namespace std;

/***************************************************************************/
// Devuelve "true" si "c" es un carácter especial del alfabeto español: 
// á é í ó ú ñ Á É Í Ó Ú Ñ ü

bool EsCaracterEspecialEspaniol (unsigned char c) 
{
	// á 225, é 233, í 237, ó 243, ú 250, ñ 241 
	// Á 193, É 201, Í 205, Ó 211, Ú 218, Ñ 209, ü 252
	
	return (c==225 || c==233 || c==237 || c==243 || c==250 || c==241 || 
			c==193 || c==201 || c==205 || c==211 || c==218 || c==209 || 
			c==252);
}

/***************************************************************************/
// Convierte un carácter especial "c" a su equivalente estándar
// á (225) Á (193) --> a       ó (243) Ó (211) --> o
// é (233) É (201) --> e       ú (250) Ú (218) ü (252) --> u 
// í (237) Í (205) --> i       ñ (241) Ñ (209) --> ñ  
//
// Si "c" no requiere transformación devuelve el mismo valor

char TransformaCaracterEspecialEspaniol (unsigned char c) 
{
	char nuevo; 
	
	switch (c) {
		
		case (225) : 
		case (193) : nuevo = 'a'; 
					 break; 
		case (233) : 
		case (201) : nuevo = 'e'; 
					 break; 
		case (237) : 
		case (205) : nuevo = 'i'; 
					 break; 
		case (243) : 
		case (211) : nuevo = 'o'; 
					 break; 
		case (250) : 
		case (218) : 
		case (252) : nuevo = 'u'; 
					 break; 
		case (241) : 
		case (209) : nuevo = 'n'; 
					 break; 
		default: 	nuevo = c; 
					break; 		 	
	}
	
	return (nuevo);
}

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	setlocale(LC_CTYPE, "Spanish");
	
	unsigned char c;	
	
	while ((c=cin.get()) != '*')  {

		if (isalpha(c)) {
			
			cerr << c << " alpha" << " --> minuscula es " 
			     << (c = tolower(c)) << endl; 
			cerr << "Es caracter especial espaniol --> " 
			     << boolalpha << EsCaracterEspecialEspaniol(c) << endl;  
			cerr << "Transformado es " 
				 << (c=TransformaCaracterEspecialEspaniol(c)) << endl; 

			cerr << endl;
						
		} // if (isalpha(c))
		
		cout << c; 
		
	} // while ((c=cin.get()) != '*')

	return 0;
}

/***************************************************************************/
/***************************************************************************/
