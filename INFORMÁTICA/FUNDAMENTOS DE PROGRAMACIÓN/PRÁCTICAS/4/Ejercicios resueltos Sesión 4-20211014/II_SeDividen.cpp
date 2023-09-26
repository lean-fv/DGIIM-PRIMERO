/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 2
// 
/*	
	Programa que lee dos valores enteros desde teclado y dice si
	cualquiera de ellos divide o no (de forma entera) al otro.
	
	--> En el caso que uno de ellos divida al otro se indica que 
	    se ha detectado que uno de ellos es múltiplo del otro, y cuál es.
    --> Si no fueran múltiplos también se indica.
    
	Se contempla el caso en el que alguno de los valores introducidos 
	sea cero, en cuyo caso ninguno divide al otro.

	Tenemos especial cuidado en no mezclar entradas/salidas con cálculos.
	 
	Entradas: los dos valores (int) 
	Salidas: Un mensaje: "Uno divide al otro" ó "Ninguno divide al otro"
*/
/***************************************************************************/
 
#include <iostream>
using namespace std;

int main()
{
	int num1, num2;            
	int dividendo; // Si num1%num2==0, dividendo será num1 y divisor será num2
	int divisor;   // Si num2%num1==0, dividendo será num2 y divisor será num1
	
	/************************************************************************/
	// Entrada de datos
	
	cout << "Introduzca primer valor: ";
	cin >> num1;                           
	cout << "Introduzca segundo valor: ";
	cin >> num2;                          
	
	
	/************************************************************************/
	// Cálculos

	bool se_dividen;
	
	// Podríamos usar cualquiera de las dos variables lógicas:
	bool ninguno_es_cero = ((num1 != 0) && (num2 != 0));
	bool alguno_es_cero  = ((num1 == 0) || (num2 == 0));
	
	/*  DEMOSTRACIÓN: 
	
		Trabajemos con las Leyes de De Morgan 

		bool ninguno_es_cero = !(alguno_es_cero);
		ninguno_es_cero = !(alguno_es_cero);
		ninguno_es_cero = !((num1 == 0) || (num2 == 0));
		ninguno_es_cero = (!(num1 == 0) && !(num2 == 0));
		ninguno_es_cero = ((num1 != 0) && (num2 != 0));
	*/	
	
	// Ahora, dos soluciones equivalentes: 	
	
	// 1) con "ninguno_es_cero"
	
	if (ninguno_es_cero)
		se_dividen = (num1 % num2 == 0) || (num2 % num1 == 0);
	else 
		se_dividen = false; 
      
	// 2) con "alguno_es_cero"
	
	if (alguno_es_cero)
		se_dividen = false; 
	else 
		se_dividen = (num1 % num2 == 0) || (num2 % num1 == 0);
     
    // Si se dividen (da igual cómo se calculó) calcular "dividendo" 
	// y "divisor" 
      
	if (se_dividen) {
		
		dividendo = num1;  // Por defecto
		divisor   = num2;  // Por defecto
		
		if (num1<num2) {
			dividendo = num2;
			divisor   = num1;
		} 
	}

	/************************************************************************/	
	// Resultados
	
	cout << endl;
	
	if (alguno_es_cero) // alguno es cero 
	// También if (!ninguno_es_cero) 
		cout << "CUIDADO: Alguno de los valores es cero" << endl;

	if (se_dividen) {
		cout << "Uno divide al otro --> "; 
		cout << dividendo << " es multiplo de " << divisor << endl;
	}
	else
		cout << "Ninguno divide al otro" << endl;
		
	cout << endl;
	
	
	return 0;
}
