/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// 
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 1
/*	
   Programa que calcula e imprime la media muestral y la desviaci�n 
			t�pica de tres valores de altura 
   Entradas: los tres valores (altura1, altura2 y altura3) 
   Salidas:  El valor de la media y de la desviaci�n t�pica calculada 
			 mediante las expresiones conocidas: 

			(N es el n�mero de muestras)
 
			         1    N 
			media = --- suma (x_i)
			         N   i=1
			                ________________________________
			               /   1     N  (                 )
			desviacion =  / ( ---  suma ( (x_i - media)^2 )
			             V     N    i=1 (                 )
*/
/***************************************************************************/


#include <iostream>
#include <cmath>
#include <string>  //  <- Es necesario para poder usar el tipo string

using namespace std;

int main()
{
	const string MENSAJE_ENTRADA_DATOS = "Introduzca una altura en cm: ";

	double altura1, altura2, altura3;	// Datos de entrada
	double media, desviacion;			// Datos de salida (Resultados)

	// Entrada
	
	cout << endl;
	cout << MENSAJE_ENTRADA_DATOS;
	cin >> altura1;
	cout << MENSAJE_ENTRADA_DATOS;
	cin >> altura2;   
	cout << MENSAJE_ENTRADA_DATOS;
	cin >> altura3;
   
	// C�lculos
	
	media = (altura1 + altura2 + altura3) / 3;    
	desviacion =  sqrt( ( pow(altura1 - media , 2) +  
						  pow(altura2 - media , 2) + 
						  pow(altura3 - media , 2)
						 ) / 3
					   );
   
	// Salida
	
	cout << endl;
	cout << "Media aritmetica: " << media << endl;
	cout << "Desviacion tipica: " << desviacion << endl;
	cout << endl;

	return 0;
}
