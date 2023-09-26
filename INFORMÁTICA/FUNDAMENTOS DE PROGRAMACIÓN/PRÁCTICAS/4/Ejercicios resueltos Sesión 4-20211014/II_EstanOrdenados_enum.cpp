/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 2
//
/*	 
	Programa que lee  tres enteros desde teclado y nos dice si están
	ordenados (da igual si es de forma ascendente o descendente)
	o no lo están.

	Entradas: los tres valores (int)
	Salidas: Un mensaje indicando si están ordenados o no lo están.
*/
/***************************************************************************/

#include <iostream>
using namespace std;
 
int main()
{
	int num1, num2, num3; // datos de entrada

	// Entrada de datos

	cout << "Introduzca primer valor:  ";
	cin >> num1;
	cout << "Introduzca segundo valor: ";
	cin >> num2;
	cout << "Introduzca tercer valor:  ";
	cin >> num3;
   
   
	// Cálculos

	enum class TipoOrden {Creciente, Decreciente, SinOrden};

	TipoOrden orden;
	
   	if ((num1 <= num2) && (num2 <= num3))
		orden =  TipoOrden::Creciente;
   	else 
	   	if ((num1 >= num2) && (num2 >= num3))
			orden =  TipoOrden::Decreciente;
   		else
			orden =  TipoOrden::SinOrden;


	// Salida de Resultados

	cout << endl;
	
	switch (orden) {
		
		case (TipoOrden::Creciente) : 
			cout << "Ordenados. Orden creciente.";
			break;
		case (TipoOrden::Decreciente) : 
			cout << "Ordenados. Orden decreciente.";
			break;
		case (TipoOrden::SinOrden) : 
			cout << "No estan ordenados.";
			break;
		/* Este último caso podría haberse escrito:  
		default: 
			cout << "No están ordenados.";
			break;
		*/		
	}
		
	cout << endl;
	
	
	// APÉNDICE 
		
	/*
		enum class TipoOrden {Creciente, Decreciente, SinOrden};
	                              0           1          2
	    TipoOrden orden;
	*/
	
	 //cout << orden << endl;

	/*	
	cout << endl;
	cout << (int) orden << endl;
	cout << endl;
	
	
	orden = static_cast<TipoOrden> (0); 
	orden = (TipoOrden) 2; 
	
	cout << endl;
	cout << (int) orden << endl;
	cout << endl;
	*/
	
	return 0;
}
