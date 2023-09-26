/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 2
//
/*	
	¿Cuántas veces aparece el dígito 9 en todos números que hay 
	entre el 1 y el 100? Por ejemplo, el 9 aparece una vez en los 
	números 19 y 92, mientras que aparece dos veces en el 99. 
	
	Este programa responde a esta sencilla pregunta, pero de forma 
	suficientemente generalizada: lee tres enteros: cifra (entre 1 y 9), 
	min y max y calcula el número de apariciones del dígito "cifra" en 
	los números contenidos en el intervalo cerrado [min, max].
	
	Entradas: cifra, min y max.
	Salidas:  Un mensaje indicando el número de veces que aparece 
		el dígito "cifra" en los números contenidos en el 
		intervalo cerrado [min, max].
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/***************************************************************************/
/***************************************************************************/

int main()
{

    int min, max;
	int cifra;
	
	
	// Lectura de datos
		
	do {
		cout << "Introduzca cifra a buscar: ";
		cin >> cifra;
	} while ((cifra < 0) || (cifra > 9));
	
	int	primero, ultimo; // Entrada: los valores de los extremos

	// Lectura de los extremos

	cout << "Introduzca un extremo del intervalo: ";
	cin >> primero;
	
	cout << "Introduzca el otro extremo: ";
	cin >> ultimo;

	// Reajustar los extremos para que min <= max
	
	if (primero < ultimo) {
		min = primero;
		max = ultimo;
	}
	else {
		min = ultimo;
		max = primero;
	}	
	
	cout << endl; 
	
			
	// Cálculos 

    // Inicio de código modularizable en forma de función, 
	// p.e.   veces = num_veces (k, izda, dcha);

    int veces = 0; // Resultado: contador global

    for (int num=min; num<=max; num++) {

        cout << "Probando: " << setw (4) << num;

        int cont = 0; // Contador de apariciones de "cifra" en "num"

        int n = num;

        while (n != 0) {

            if (n % 10 == cifra)
                cont++;

            n = n /10;
        }

        cout << " --> " << setw (3) << cont << " veces " << endl;

        veces += cont; // Actualizar el contador global
        
    }
       
    // Fin de código modularizable

	cout << endl << endl;
	cout << "El digito " << cifra << " aparece "
	     << setw(3) << veces << " veces entre "
	     << setw(3) << min << " y " << setw(3) << max << endl;
	cout << endl;

	return 0;
}

/***************************************************************************/
/***************************************************************************/
