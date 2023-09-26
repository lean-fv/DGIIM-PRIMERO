/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 3
/*	 
	Programa que lee un entero y muestra los dígitos que lo componen 
	individualmente, separándolos por la barra vertical '|' 
	
	Se implementa la función:
	
	string EnteroToString (int n)
		que recibe el dato "n" (int) y devuelve un string con los dígitos 
		que lo componen separados por la barra vertical '|' 
	
	Entradas: un entero
	Salidas:  Los dígitos del entero leido.
*/
/***************************************************************************/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;


/***************************************************************************/
// Función: LeeEnteroPositivo
// Recibe: msg, el texto que etiqueta la lectura 
// Devuelve: un número entero positivo
/***************************************************************************/
int LeeEnteroPositivo (string msg)
{
	int n;
		
	cout << endl;

	do {
		
		cout << msg;
		cin >> n;
		
	} while (n <= 0);

	return n;
}
 
/***************************************************************************/
// Función: NumDigitos
// Recibe: "n" (int) 
// Devuelve: el número de dígitos de "n"
/***************************************************************************/
int NumDigitos (int n)
{
	int num_digitos = 0; // Contador del número de dígitos

	while (n != 0) {

		n /= 10;		// Actualiza el número 
		num_digitos++;  // Aumenta el contador
	}	
	
	return (num_digitos);
}

/***************************************************************************/
// Función: EnteroToString
// Recibe: "n" (int) 
// Recibe: "separador" (char) 
// Devuelve: un string con los dígitos que componen el número "n" separados 
//		por el  caracter "separador" 
/***************************************************************************/

string EnteroToString (int n, char separador)
{	
	int num_digitos = NumDigitos(n);

	/*
		Cada uno de los digitos de "n" se calcula dvividiendo por la potencia 
		de 10 más cercana (por defecto) a "n" y tomando el cociente de la 
		división como el dígito. Para el siguiente dígito, "n" será el resto 
		y vuelta a empezar. Se termina cuando la potencia de 10 sea 1 (queda 
		un  número de un dígito). En este caso, "n" es el último dígito. 
		
		P.e. 2435 (num_digitos es 3)
			La potencia de 10 más cercana es 1000 (10^(num_digitos-1))
			paso 1)	2435/1000 = 2 --> primer dígito = 2
					2435%1000 = 435 --> continuar con 435
					potencia = 100
			paso 2)	435/100 = 4  --> segundo dígito = 4
					435%100 = 35 --> continuar con 35
					potencia = 10
			paso 3)	35/10 = 3  --> tercer dígito = 3
					35%10 = 5 --> continuar con 5
					potencia = 1
			Fin:  	Como potencia == 1 --> cuarto dígito = 5
	*/
	
	string cad;  // inicialmente vacía
	
	int potencia = (int) pow (10, num_digitos-1); // 10^(num_digitos-1)
		
	while (potencia > 1) {  // potencia es 1 cuando num_digitos es 1 
							// (10^(1-1) == 10^0 == 1

		int digito = n / potencia;
		n = n % potencia;	
			
		cad = cad + separador + to_string(digito);
		
		potencia /= 10;
	}
	
	// Añadir el último dígito (unidades) 
	cad = cad + separador + to_string(n) + separador;

	return (cad);
}

/***************************************************************************/

int main()
{
	int numero;	
	
	// Entrada

	numero = LeeEnteroPositivo("Entero positivo a descomponer: ");
	
	// Cálculos 
	
	string numero_con_EnteroToString = EnteroToString (numero, '|');
	string numero_con_to_string = to_string (numero);
	
	// 	Resultados		
	
	cout << endl;	
	cout << "numero_con_EnteroToString = "<< numero_con_EnteroToString << endl;
	cout << "numero_con_to_string = "<< numero_con_to_string << endl;
	cout << endl;	
	
	return 0;
}
