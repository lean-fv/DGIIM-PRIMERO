/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 1
//
/*	
   Programa que pide dos valores, min y max, que determinan el intervalo 
   [min, max]. A continuaci�n pide un valor dentro del intervalo, numero, 
   y el valor de un desplazamiento.
   
   El programa sumar� a "numero" el valor "desplazamiento" y lo ajustar� 
   para que la suma quede en el intervalo  [min, max]. 
   
   NOTA: Piense que el conjunto de valores del intervalo se recorre 
   		 c�clicamente: min, min+1, ..., max, min, min+1, ... El operador 
		 m�dulo est� indicado para este tipo de problemas. 
*/
/***************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int min, max;  // Extremos del intervalo
	int numero;	   // Valor a "desplazar" dentro del intervalo
	int desplazamiento;	 // Valor del deplazamiento a aplicar a "numero"
	
	int nuevo_numero; 	// Salida: resultado del desplazamiento
	
		
	// Entrada de datos
	
	// Extremos del intervalo
	// PRE: min <= max
	
	cout << "Escriba extremos del intervalo: " << endl;
	cout << "\tMinimo: ";
	cin >> min;
	cout << "\tMaximo: ";	
	cin >> max;
	
	// Desplazamiento
	// PRE: 0 <= desplazamiento <= max-min
	
	cout << "Desplazamiento : ";
	cin >> desplazamiento;
	
	// Valor a "desplazar"
	// PRE: min <= numero <= max

	cout << "Valor a desplazar: ";
	cin >> numero;


	// C�lculos

	int num_valores = max-min+1;
	
	nuevo_numero = min + ( (numero-min+desplazamiento) % num_valores );

	/* 	
		-> numero-min proporciona un valor entre 0 (min-min) 
		   y num_valores-1 (max-min) --> el salto desde "min" hasta "numero"
		  
		-> Al sumar "desplazamiento" (numero-min+desplazamiento) podemos 
		   tener un valor mayor fuera del intervalo. 
		
		-> La operaci�n V % num_valores proporciona valores entre 
		   0 y num_valores-1
		  
		-> La operaci�n min + [V % num_valores] proporciona valores entre 
		   min (V % num_valores == 0 ) y max (V % num_valores=num_valores-1) 
		   o sea, en los l�mites establecidos.		
	*/
	
	// Resultado

	cout << endl;
	cout << "El nuevo numero es " << nuevo_numero << endl; 
	cout << endl;
	
	return 0;
}
