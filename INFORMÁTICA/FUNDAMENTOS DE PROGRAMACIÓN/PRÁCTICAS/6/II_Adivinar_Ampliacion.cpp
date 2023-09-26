/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS II

49. Diseñar un programa para jugar a adivinar un número. En cada jugada el
jugador introducirá un valor y el el juego indicará si el número introducido
por el jugador está por encima o por debajo del número introducido.

Como reglas de parada considerad:
a) que haya acertado, o
b) se no quiera seguir jugando a adivinar ese número (usad un valor especial
-terminador- para esta opción).

55. Ampliar la funcionalidad del programa escrito para solucionar el ejercicio
49. En esta ocasión, una vez terminado un juego de adivinación podrá volverse a
jugar de nuevo: el programa pedirá si queremos volver a jugar o no.

Igual que en el ejercicio 49 considerad dos reglas de parada para caga juego:
a) que haya acertado,
o b) se no quiera seguir jugando a adivinar ese número (escoged cómo se quiere
implementar esta opción).

ENTRADA: Multiples numeros.
SALIDA: Si se ha acertado el numero, numero de rondas, pista si no se ha
adivinado el numero, posibilidad de volver a jugar.

*/

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

	int num_jugadas; // Contador de intentos válidos
	int leido;	// Para leer el valor suministrado por el jugador

    bool en_rango;

	bool seguir_jugando; // Variable de control de seguir jugando.
	int volver_jugar;
	const int JUGAR = 1; //Valor que tiene que ser introducido para seguir
											 //jugando.


	// Leer la primera jugada del juego

	do{
		num_jugadas = 0;

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

		do{ //Filtro de dato correcto a la hora de volver a jugar.
			cout << "Para volver a jugar pulse 1 y para salir 0. " << endl;
			cin >> volver_jugar;
		}while (volver_jugar != FIN && volver_jugar != JUGAR);

		if (volver_jugar == JUGAR){
			seguir_jugando = true;
		}
		else seguir_jugando = false;


	}while (seguir_jugando);
	return 0;
}
