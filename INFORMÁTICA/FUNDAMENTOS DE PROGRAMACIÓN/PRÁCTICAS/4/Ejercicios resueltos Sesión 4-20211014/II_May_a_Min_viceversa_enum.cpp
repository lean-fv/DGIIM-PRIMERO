/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 2
//
/*	
	Leer un carácter desde teclado, y:
	1) si es mayúscula, pasarlo a minúscula.
	2) si es minúscula, pasarlo a mayúscula.
	3) si no es un carácter alfabético, dejarlo tal cual.

	NOTA: No se consideran vocales acentuadas, ni la ü, ni la la ñ 
	(tanto mayúsculas como minúsculas). 
	
*/
/***************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	char letra_convertida, letra_original;
	const int DISTANCIA_MAY_MIN = 'a'-'A';
	
	enum class TipoCaracter {Mayuscula, Minuscula, Digito, Otro};

	TipoCaracter tipo;
	
	
	// Lectura
	
	cout << "Introduzca una letra  --> ";
	cin >> letra_original;


	// Determinar la categoría de "letra_original"
	
	if ((letra_original >= 'A') && (letra_original <= 'Z'))
		tipo = TipoCaracter::Mayuscula;
	else 
		if ((letra_original >= 'a') && (letra_original <= 'z'))
			tipo = TipoCaracter::Minuscula;
		else 
			if ((letra_original >= '0')&&(letra_original <= '9'))
				tipo = TipoCaracter::Digito;
			else 		
				tipo = TipoCaracter::Otro;
	
	/* Alternativa a switch  con default: 
	
		1) Antes de switch: 
			letra_convertida = letra_original;
		2) No escribir default en el switch
	*/
	
	switch (tipo) {
		
		case (TipoCaracter::Mayuscula) : 
			letra_convertida = letra_original + DISTANCIA_MAY_MIN;
			break;	
		case (TipoCaracter::Minuscula) : 
			letra_convertida = letra_original - DISTANCIA_MAY_MIN;
			break;	
		default:  // TipoCaracter::Digito || TipoCaracter::Otro
			letra_convertida = letra_original;
			break;
	}

	// Resultado
	
	cout << endl;
	cout << "Letra original : " << letra_original << endl;

	
	switch (tipo) {
		
		case (TipoCaracter::Mayuscula) : 		
			cout << "La letra era una mayuscula. Una vez convertida es : "
			     << letra_convertida;
			break;	
		case (TipoCaracter::Minuscula) : 
			cout << "La letra era una minuscula. Una vez convertida es : "
				 << letra_convertida;
			break;	
		default: // TipoCaracter::Digito || TipoCaracter::Otro
			cout << "No se convierte (el caracter no era una letra).";
			break;
	}
	
   cout << endl;

   return 0;
}
