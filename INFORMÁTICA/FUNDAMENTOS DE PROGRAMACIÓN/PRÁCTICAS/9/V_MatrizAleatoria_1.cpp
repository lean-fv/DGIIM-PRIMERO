/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS V

45. Suponga una matriz que puede guardar datos enteros cuyas dimensiones son
NUM_FILAS y NUM_COLS columnas. Queremos rellenar completamente la matriz con
todos los valores comprendidos entre 1 y NUM_FILAS*NUM_COLS pero colocándolos
en posiciones aleatorias. También queremos saber cuántos intentos hemos
necesitado para cada valor, el total de intentos para llenar la matriz y cuál
es la media de intentos por valor.

El algoritmo para llenar la matriz será el siguiente:

a) Para cada valor a colocar en la matriz, genere una posición aleatoria de la
matriz (genere un número de fila y un número de columna).

b) Si la casilla está libre, coloque ahí el valor, y si está ocupada vuelva a
generar otra posición aleatoria.
El programa mostrará en primer lugar el número de intentos para alojar cada
valor (NUM_DATOS_LINEA datos por línea), a continuación el número total de
intentos y el valor medio. Finalmente mostrará la matriz de valores.

ENTRADA: numeros entre 1 y filas*columnas en una posicion aleatoria de la
matriz
SALIDA: los intentos para cada valor, los intentos totales, la media de
intentos por posicion y la matriz final.

*/

#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main() {

	//Declaraciones.

	const int NUM_FILAS = 5, NUM_COLS = 5;

	// Se generarán valores aleatorios entre MIN y MAX
	const int MIN = 0, MAX = NUM_FILAS - 1;
	const int NUM_VALORES = MAX - MIN + 1; // Número de valores posibles

	time_t t;
	srand ((int) time(&t)); // Inicializa el generador de números aleatorios
							// con el reloj del sistema  (hora actual).


	int matriz[NUM_FILAS][NUM_COLS] = {0};
	int posicion_filas;
	int posicion_columnas;

	const int TOTAL_CASILLAS = NUM_FILAS * NUM_COLS;
	int numeros[TOTAL_CASILLAS]; //Aloja los valores entre 1 y TOTAL_CASILLAS.

	//Entrada de datos.

	cout << "***********************************************" << endl << endl;

	/* Se rellena el vector con los valores entre 1 y el total de casillas de
	la matriz. */
	for (int i = 0; i < TOTAL_CASILLAS; i++){
		numeros[i] = i + 1;
	}


	//Calculos.

	int numeros_totales = 0;
	int intentos_posicion[TOTAL_CASILLAS] = {0};
	int posicion = 0;

	while (numeros_totales < TOTAL_CASILLAS){

		//Se genera posicion aleatoria.
		posicion_filas = (rand() % NUM_VALORES) + MIN;
		posicion_columnas = (rand() % NUM_VALORES) + MIN;


		if (matriz[posicion_filas][posicion_columnas] == 0){

			matriz[posicion_filas][posicion_columnas] = numeros[posicion];
			numeros_totales++; //Contador de cuantos numeros se han colocado.
			intentos_posicion[posicion]++;
			posicion++; //Cuando se coloca el numero avanza la posicion para
						//pasar a colocar el siguiente valor.
		}

		else {
			//Si no se coloca el valor aumentan los intentos.
			intentos_posicion[posicion]++;
		}
	}

	//Calculo de los intentos totales para alojar todos los numeros.
	int intentos_totales = 0;
	for (int i = 0; i < TOTAL_CASILLAS; i++){
		intentos_totales = intentos_totales + intentos_posicion[i];
	}
	//Media entre la suma de intentos y el numero de casillas de la matriz.
	double media = 1.0 * intentos_totales / TOTAL_CASILLAS;

	//Salida de datos.

	//Numero de intentos por numero a colocar.
	cout << "Intentos para alojar los valores: " << endl;
	for (int i = 0; i < TOTAL_CASILLAS; i++){
		cout << intentos_posicion[i] << " ";
	}

	cout << endl << endl;
	cout << "Intentos totales: " << intentos_totales << endl;

	//Media entre la suma de intentos y el numero de casillas de la matriz.
	cout << "Media: " << media << endl << endl;

	//Mostramos la matriz.
	cout << "Matriz de valores: " << endl << endl;
	for (int i = 0; i < NUM_FILAS; i++){
		cout << endl;
		for (int j = 0; j < NUM_COLS; j++){
			cout << matriz [i][j] << " ";
		}
	}

	cout << endl << endl;
	cout << "***********************************************" << endl << endl;

	return 0;
}
