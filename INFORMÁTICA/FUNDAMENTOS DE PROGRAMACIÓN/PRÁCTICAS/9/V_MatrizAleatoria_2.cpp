/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS V

46. Suponga una matriz que puede guardar datos enteros cuyas dimensiones son
NUM_FILAS y NUM_COLS columnas. Queremos rellenar completamente la matriz con
valores aleatorios comprendidos entre MIN_VALOR y MAX_VALOR. Tenga en cuenta
que un mismo valor podía aparecer varias veces en la matriz y que algunos
valores podrían no aparecer.

Queremos calcular cuántas veces aparece en la matriz cada uno de los valores
entre MIN_VALOR y MAX_VALOR y su frecuencia relativa (expresada como
porcentaje).

Escriba un programa que rellene la matriz y la muestre. Después calculará
cuántas veces aparece cada valor y realizará una prueba de integridad
(mostrando el resultado). La prueba consiste en comprobar si la suma de las
apariciones de los posibles valores que se pueden generar coincide con la
cantidad de valores de la matriz.

Finalmente mostrará para cada uno de los potenciales valores que pueden
generarse cuántas veces aparece y en qué porcentaje sobre el total.
En la figura 32 puede ver un ejemplo de ejecución usando una matriz de 10 filas
y 10 columnas rellena con números aleatorios entre 4 y 10.

ENTRADA: numeros aleatorios en un rango colocados en un matriz.
SALIDA: la matriz, cuantas veces se repite cada numero, y el porcentaje de
aparicion.

*/

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cctype>
#include<iomanip>


using namespace std;

int main() {

	//Declaraciones.

	const int NUM_FILAS = 10, NUM_COLS = 10;
	int matriz[NUM_FILAS][NUM_COLS];

	const int MIN = 1, MAX = 9; 	// Se generarán valores aleatorios
	const int NUM_VALORES = MAX - MIN + 1; // Número de valores posibles

	time_t t;
	srand ((int) time(&t)); // Inicializa el generador de números aleatorios
							// con el reloj del sistema  (hora actual)

	int aleatorio;

	//Entrada de datos.

	cout << "***********************************************" << endl << endl;

	for (int i = 0; i < NUM_FILAS; i++){
		for (int j = 0; j < NUM_COLS; j++){

			aleatorio = (rand() % NUM_VALORES) + MIN;
			matriz[i][j] = aleatorio;

		}
	}

	/* Vector que contiene los valores de aleatorios entre el maximo y el
	minimo incluidos. */
	int numeros[NUM_VALORES];
	for (int i = 0; i < NUM_VALORES; i++){
		numeros[i] = MIN + i;
	}


	//Calculos.

	//Contabiliza repeticiones de cada numero.
	int repeticiones[NUM_VALORES] = {0};

	int posicion = 0;

	/* El bucle se ejecuta hasta que se llega al maximo del intervalo de
	aleatorios. */
	while (numeros[posicion] <= MAX){

		/* Recorremos la matriz cada para cada numero en el intervalo de
		aleatorios. */
		for (int i = 0; i < NUM_FILAS; i++){
			for (int j = 0; j < NUM_COLS; j++){

				if (matriz[i][j] == numeros[posicion]){
					repeticiones[posicion]++;
				}
			}
		}

		/* Actualizacion de la posicion cuando se recorre la matriz, lo que
		implica el siguiente numero de intervalo de aleatorios. */
		posicion++;
	}

	//Suma de todas las repeticiones de numeros para verificar la integridad.
	int suma_repeticiones = 0;
	for (int i = 0; i < NUM_VALORES; i++){

		suma_repeticiones = suma_repeticiones + repeticiones[i];

	}

	cout << endl << endl;

	//Salida de datos.

	cout.setf (ios :: showpoint);
	cout.setf (ios :: fixed);

	cout << endl << endl;
	cout << "Generando numeros entre " << MIN << " y " << MAX << endl << endl;
	cout << "Matriz de valores: " << endl << endl;

	//Mostramos la matriz.
	for (int i = 0; i < NUM_FILAS; i++){
		cout << endl;
		for (int j = 0; j < NUM_COLS; j++){

			cout << matriz[i][j] << "  ";
		}
	}

	cout << endl << endl;

	const int TOTAL_VALORES = NUM_FILAS * NUM_COLS;

	//Comprobacion de la integridad.
	if (suma_repeticiones == TOTAL_VALORES)
		cout << "Integridad verificada.";

	cout << endl << endl;
	cout << "Repeticiones: " << endl << endl;

	//Muestra de cada numero en el intervalo.
	const double CONSTANTE_PORCENTAJE = 100 / TOTAL_VALORES;
	for (int i = 0; i < NUM_VALORES; i++){
		double porcentaje = repeticiones[i] * CONSTANTE_PORCENTAJE;
		cout << numeros[i] << ": " << setw(3) << repeticiones[i] << " "
			 << setprecision(2) <<  setw(6) << porcentaje << " % " << endl;
		cout << "---------------------------------------" << endl;
	}

	cout << endl;
	cout << "***********************************************" << endl << endl;



	return 0;
}
