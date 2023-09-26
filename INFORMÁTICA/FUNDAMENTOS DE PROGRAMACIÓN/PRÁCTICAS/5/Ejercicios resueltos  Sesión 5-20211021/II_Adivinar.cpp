/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 2
//
// Juego de adivinación 
//
// Programa para jugar a adivinar un número. 
// El juego tiene que dar pistas de si el número introducido por 
// el jugador está por encima o por debajo del número introducido. 
// El programa genera de manera aleatoria el número que el jugador 
// debe adivinar. 
//
// Las reglas de parada son: 
//		1) Que el jugador adivine el número.
//		2) Que el jugador decida abandonar (el usuario escribirá 0 
//			cuando se le pide el número tentativo).
//
/***************************************************************************/

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cctype>
using namespace std;

int main()
{
	const int FIN = 0; // Valor terminador (fuerza el abandono) 

    //.......................................................................
	// Para el cálculo del valor a adivinar (un número aleatorio)

    const int MIN = 1, MAX=10; 	// Se generarán valores aleatorios
								// entre MIN y MAX
	const int NUM_VALORES = MAX-MIN+1; // Número de valores posibles

	time_t t;
	srand ((int) time(&t)); // Inicializa el generador de números aleatorios
							// con el reloj del sistema  (hora actual)
    //.......................................................................

	
    int objetivo; // Valor a adivinar (se genera aleatoriamente)
   
	cout << "---------------------------------------------------" << endl;
   	cout << endl;
	       	

	// Calcular el número que se va a adiviar en este juego
    objetivo = (rand() % NUM_VALORES) + MIN; // MIN <= objetivo <= MAX

	// Juego
	
	int num_jugadas = 0; // Contador de intentos válidos
	int leido;	// Para leer el valor suministrado por el jugador 

    bool en_rango; 


	// Leer la primera jugada del juego 
	
	do {
		cout << "Jugada " << (num_jugadas+1) << " --> ";
	    cout << "Introduzca un numero entre " 
			 << MIN << " y " << MAX << ": ";
    	cin >> leido;
    	
    	en_rango = ((leido>=MIN) && (leido<=MAX));
    	
	} while ( !en_rango && (leido != FIN));
	

    while ((leido != FIN) && (leido != objetivo)) { 
		    
		num_jugadas++;	// Actualizar el número de jugadas
		    
		// Las pistas solo se muestran si se va a seguir jugando
		
		if (leido > objetivo)
 			cout << "   El numero es menor que " << leido << endl;
 		else 
			cout << "   El numero es mayor que " << leido << endl;
    
    
		// Leer la siguiente jugada del juego
		   		
		do {
			cout << "Jugada " << (num_jugadas+1) << " --> ";
		    cout << "Introduzca un numero entre " 
				 << MIN << " y " << MAX << ": ";
	    	cin >> leido;

    		en_rango = ((leido>=MIN) && (leido<=MAX));
    	
		} while ( !en_rango && (leido != FIN));
						
    } // while ((leido != FIN) && (leido != objetivo))
    
    // Ahora debemos discriminar la razón por la que terminó el ciclo
        
	if (leido==FIN) 
	    cout << "\nABANDONASTE EL JUEGO. ";	
	else {
	    cout << "\nHas acertado. ";
		num_jugadas++;
	}
	
	cout << " El numero buscado era " << objetivo << endl;  
   	cout << endl;    	
	cout << "Has jugado " << num_jugadas << " jugadas.";      
   	cout << endl;    	
	cout << "---------------------------------------------------" << endl;
   	cout << endl;    	
	
	return 0;
}
