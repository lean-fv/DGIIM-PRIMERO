/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// 
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 3
// Versión 1
//
/*	 
	¿Cuántas veces aparece el dígito 9 en todos números que hay 
	entre el 1 y el 100? Por ejemplo, el 9 aparece una vez en los 
	números 19 y 92, mientras que aparece dos veces en el 99. 
	
	Este programa responde a esta sencilla pregunta, pero de forma 
	suficientemente generalizada: lee tres enteros: cifra (entre 1 y 9), 
	min y max y calcula el número de apariciones del dígito "cifra" en 
	los números contenidos en el intervalo cerrado [min, max].

	Versión 1:
		* Funciones para gestionar los datos de entrada
	
	Entradas: cifra, primero y ultimo.
	Salidas:  Un mensaje indicando el número de veces que aparece 
		el dígito "cifra" en los números contenidos en el 
		intervalo cerrado [min, max] donde 
		   min=minimo(primero,ultimo)
		   max=maximo(primero,ultimo)		   
		
	PRE: 0 <= cifra <= 9
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/***************************************************************************/
// Función que lee y devuelve una cifra (un dígito)
//
// Recibe: Nada
// Devuelve: Un número entero entre 0 y 9 (incluidos) 
//
// POST: 1 <= cifra <= 9

int LeeCifra (void)
{
	int cifra; 
	
	do {
		cout << "Introduzca cifra a buscar: ";
		cin >> cifra;
	} while ((cifra < 1) || (cifra > 9));

	return (cifra);
}

/***************************************************************************/
// Función que calcula y devuelve el menor de dos números
//
// Recibe: "num1" y "num2", los números a evaluar 
// Devuelve: el menor entre "num1" y "num2" 

int Menor (int num1, int num2)
{
	int min; 
	
	if (num1 < num2) 
		min = num1;
	else 
		min = num2;
			
	/*
	// Alternativa:
	
	int min = num1; 
	
	if (num2 < num1)
		min = num2; 
	*/
	
	return (min);
}

/***************************************************************************/
// Función que calcula y devuelve el mayor de dos números
//
// Recibe: "num1" y "num2", los números a evaluar 
// Devuelve: el mayor entre "num1" y "num2" 

int Mayor (int num1, int num2)
{
	int max; 
	
	if (num1 > num2) 
		max = num1;
	else 
		max = num2;
			
	/*
	// Alternativa:
	
	int max = num1; 
	
	if (num2 > num1)
		max = num2; 
	*/		
		
	return (max);
}

/***************************************************************************/

int main()
{
    int min, max;
	int cifra;
	
	
	// Entrada
	
	cifra = LeeCifra (); 	// Lectura de la cifra a buscar
			
	// Aseguramos que 1 <= cifra <= 9		
			
	int	primero, ultimo; // Entrada: los valores de los extremos

	cout << "Introduzca un extremo del intervalo: ";
	cin >> primero;
	
	cout << "Introduzca el otro extremo: ";
	cin >> ultimo;

	cout << endl;

	// Reajustar los extremos para que min <= max
	
	min = Menor (primero, ultimo);
	max = Mayor (primero, ultimo);
	
	// Aseguramos que min <= max y que 
	// min = minimo(primero, segundo)  y  max = maximo (primero, segundo)		

					
	// Cálculos 

    int veces_total = 0; // Num. veces que "cifra" aparece en total

    for (int num=min; num<=max; num++) {

        cout << "Probando: " << setw (4) << num; // Mensaje opcional

        int veces_en_num = 0; // Num. veces que "cifra" aparece en "num"

        int n = num;

        while (n != 0) {

            if (n % 10 == cifra)
                veces_en_num++;

            n = n /10;
        }

        cout << " --> " << setw (3) << veces_en_num // Mensaje opcional
			 << " veces " << endl;

        veces_total += veces_en_num;
    }


    // Presentación de resultados 

	cout << endl << endl;
	cout << "El digito " << cifra << " aparece "
	     << setw(3) << veces_total << " veces entre "
	     << setw(3) << min << " y " << setw(3) << max << endl;
	cout << endl << endl;

	return 0;
}
