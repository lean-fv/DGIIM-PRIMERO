/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 2
//
/*	
	Programa que actualiza el sueldo de una persona según su edad y salario.  
	 
		"Subid el salario un 4% si es mayor de 65 o menor de 35 años. 
		Si además de cumplir la anterior condición, también tiene un 
		salario inferior a 300 euros, se le subirá otro 3 % y si el 
		salario es mayor o igual que 300 euros e inferior a 900 euros 
		se incrementará un 1.5 %"
		
	Entradas: edad (int) e ingresos (double)
	Salidas: el nuevo sueldo ó el mensaje "No es aplicable la subida"
*/
/***************************************************************************/

#include <iostream>
using namespace std;
 
int main()
{
	const int 	 EDAD_JOVEN = 35;
	const int 	 EDAD_MAYOR = 65;	
	const double UMBRAL_SALARIO_MUY_BAJO = 300.0;
	const double UMBRAL_SALARIO_BAJO = 1000.0;
	
	const double INCR_EDAD = 1.04;
	const double INCR_SALARIO_MUY_BAJO = 1.03;	
	const double INCR_SALARIO_BAJO = 1.015;	
	
	int edad;
	double salario;
	double salario_final_1, salario_final_2; // Dos soluciones

	// Lectura 
	
	cout << "Introduce la edad: ";
	cin >> edad;
	cout << "Introduce el salario: ";
	cin >> salario;


	/***********************************************************************/
	// SOLUCIÓN 1: sin datos enumerados 
	
	// Para independizar cálculos y presentación de resultados usaremos 
	// variables lógicas que registran estados. 
	
	bool es_mayor, es_joven; 	 // edad>EDAD_MAYOR - edad<EDAD_JOVEN  	
	bool tiene_salario_muy_bajo; // salario<UMBRAL_SALARIO_MUY_BAJO
	bool tiene_salario_bajo;	 
	                   // UMBRAL_SALARIO_MUY_BAJO<=salario<UMBRAL_SALARIO_BAJO

	bool verifica_criterio_edad; // si es mayor ó es joven
		
	// Cálculos

	es_mayor = (edad > EDAD_MAYOR);
	es_joven = (edad < EDAD_JOVEN);
	verifica_criterio_edad = (es_mayor || es_joven);
	
	tiene_salario_muy_bajo = (salario<UMBRAL_SALARIO_MUY_BAJO); 
	tiene_salario_bajo = (UMBRAL_SALARIO_MUY_BAJO<=salario && 
	                      salario<UMBRAL_SALARIO_BAJO);	 
	     	
	     	
	if (verifica_criterio_edad) {
		
		salario_final_1 = salario * INCR_EDAD;
				
		if (tiene_salario_muy_bajo)
			salario_final_1 = salario_final_1 * INCR_SALARIO_MUY_BAJO;	
		else {
			if (tiene_salario_bajo)
				salario_final_1 = salario_final_1 * INCR_SALARIO_BAJO;	
		}
	}
	else 
		salario_final_1 = salario;

	// Resultado

	cout << endl;
	
	if (!verifica_criterio_edad)
	
		cout << "No es aplicable la subida (razon: edad)";
		
	else {

		cout << "--> Se aplica subida por edad" << endl;
	
		if (tiene_salario_muy_bajo)
			cout << "--> Se aplica -extra- subida por salario muy bajo" << endl;
		else {
			if (tiene_salario_bajo)
			   cout << "--> Se aplica -extra- subida por salario bajo" << endl;
		}
	}

	cout << endl;
	cout << "Salario Final: " << salario_final_1;
	cout << endl;						



	/***********************************************************************/
	// SOLUCIÓN 2: con datos enumerados 
	
	enum class CategoriaEdad {Joven, Maduro, Mayor};
	enum class CategoriaSalario {MuyBajo, Bajo, Otro};
	
	CategoriaEdad    franja_edad; 
	CategoriaSalario franja_salario; 
	
	
	// Cálculos
	
	//	1. Asignar valor al dato enumerado "franja_edad"  

	if  (edad < EDAD_JOVEN) 
		franja_edad = CategoriaEdad::Joven;
	else 
		if  (edad <= EDAD_MAYOR)
			franja_edad = CategoriaEdad::Maduro;
		else 
			franja_edad = CategoriaEdad::Mayor;

	//	2. Asignar valor al dato enumerado "franja_salario"  

	if  (salario < UMBRAL_SALARIO_MUY_BAJO) 
		franja_salario = CategoriaSalario::MuyBajo;
	else 
		if  (salario < UMBRAL_SALARIO_BAJO)
			franja_salario = CategoriaSalario::Bajo;
		else 
			franja_salario = CategoriaSalario::Otro;


	//	3. Actualización del salario  

	// Dos alternativas para el if:
	/*
	1) if (franja_edad==Categoria::Joven || franja_edad==Categoria::Mayor) 
	2) if ( !(franja_edad==Categoria::Maduro ))
	*/

	if (franja_edad==CategoriaEdad::Joven||franja_edad==CategoriaEdad::Mayor) {
	
		salario_final_2 = salario * INCR_EDAD;
		
		if (franja_salario!=CategoriaSalario::Otro) {
			
			if (franja_salario==CategoriaSalario::MuyBajo)
				salario_final_2 = salario_final_2 * INCR_SALARIO_MUY_BAJO;	
			else 
				salario_final_2 = salario_final_2 * INCR_SALARIO_BAJO;	
		}
	}
	else 
		salario_final_2 = salario;


	// Resultado

	cout << endl;
	
	if (franja_edad==CategoriaEdad::Maduro)
	
		cout << "No es aplicable la subida (razon: edad)";
		
	else {

		cout << "--> Se aplica subida por edad" << endl;
	
		if (franja_salario!=CategoriaSalario::Otro) {
		
			if (franja_salario==CategoriaSalario::MuyBajo)
				cout << "--> Se aplica -extra- subida por salario muy bajo";
			else 
				cout << "--> Se aplica -extra- subida por salario bajo";
				
			cout << endl; 		
		}
	}

	cout << endl;
	cout << "Salario Final: " << salario_final_2;
	cout << endl;					


	return 0;
}
