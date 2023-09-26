/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS V

28. (Examen Ordinario 2020)
Se dispone de un robot que se mueve en una línea, utilizando pasos de longitud
fija.

Inicialmente, el robot se ubica en la posición pos, siendo pos un valor entero
positivo 1 ≤ pos ≤ 100. Luego, el robot ejecuta una serie de órdenes, indicadas
mediante un array ord de tipo char, con longitud lon. Cada orden es una letra I
ó D, indicando si el robot se mueve a la izquierda (decrementando la posición
actual pos en 1 unidad) o a la derecha (incrementando la posición actual pos en
1 unidad). Las posiciones válidas del robot cumplen 1 ≤ pos ≤ 100. Se dice que
una serie de órdenes es correcta si el robot nunca se sale de las posiciones
válidas.

Se pide implementar un programa (directamente en la función main) para que,
dada una posición inicial pos y una lista de órdenes ord de longitud lon, haga
lo siguiente:

• Si la serie de órdenes es correcta, muestre cuántas veces se visitó cada
posición.
• Si la serie de órdenes NO es correcta, el programa terminará indicando cuántas
órdenes se pudieron ejecutar.

42. Se va a dotar de mayor funcionalidad al robot desarrollado en el ejercicio
28 de esta misma Relación de Problemas para que se mueva en un tablero de 10
filas y 10 columnas.

Inicialmente, el robot se ubica en la posición pos, siendo pos una pareja de
enteros positivos (f, c) donde 1 ≤ f ≤ 10 y 1 ≤ c ≤ 10. Luego, el robot ejecuta
una serie de órdenes, indicadas mediante un array ord de tipo char, con
longitud lon.

Cada orden es una letra ’I’, ’D’, ’A’ o ’B’ indicando si el robot se mueve a la
izquierda, derecha, arriba o abajo. Las posiciones válidas del robot cumplen
que para cada posición pos sus coordenadas (f, c) son correctas. Se dice que
una serie de órdenes es correcta si el robot nunca se sale de las posiciones
válidas.

Se pide implementar un programa que lea la posición inicial pos (fila y
columna, por separado) y la secuencia de órdenes a ejecutar. Le recomendamos
que use un dato string, p.e. cad_ordenes para la lectura. Si el string es
correcto, el array ord se rellenará a partir de cad_ordenes, siendo lon la
longitud de cad_ordenes.

Recomendación: use un tipo enumerado para las posiciones.

Después de la lectura de los datos haga lo siguiente:
• Si la serie de órdenes es correcta, muestre cuántas veces se visitó cada
posición. Use una representación bidimensional (figura 29).
• Si la serie de órdenes NO es correcta, el programa terminará indicando cuántas
órdenes se pudieron ejecutar.

ENTRADA: Posicion del robot, secuencia de ordenes.
SALIDA: Si la secuencia de ordenes es correcta para permanecer en el rango,
cuantas veces se visito cada posicion cuantas posiciones validas visitadas.

*/

#include <iostream>
#include <string>
#include<iomanip>


using namespace std;

int main() {

	//Declaraciones.
	const int NUM_FILAS = 10, NUM_COLS = 10, MIN = 1, TAM = 200;
	char ord[TAM];
	string orden;
	int f, c;
	const int D = 'D', I = 'I', A = 'A', B = 'B';
	bool pos_correcta = true;

	//Entrada de datos.

	cout << "***********************************************" << endl << endl;

	do{
		cout << "Introduzca una posicion inicial (filas). ";
		cin >> f;
		cout << endl;
	}while (f < MIN || f > NUM_FILAS);

	do{
		cout << "Introduzca una posicion inicial (columnas). ";
		cin >> c;
		cout << endl;
	}while (c < MIN || c > NUM_COLS);


		cout << "Introduzca una orden. ";
		cin >> orden;
		int lon = (int)orden.length();

		for (int i = 0; i < lon; i++){
			ord[i] = orden.at(i);
		}

	//Calculos.
	int pos_fila = NUM_FILAS - f, pos_columna = c - 1;
	int numero_ordenes = 0;

	//Contabiliza las veces que pasa por una posicion determinada.
	int repeticion_pos [TAM][TAM] = {0,0};
	repeticion_pos[pos_fila][pos_columna]++;

	for (int i = 0; (i < lon) && pos_correcta; i++){

		if (ord[i] == D){
			pos_columna++;
		}
		else if (ord[i] == I){
			pos_columna--;
		}
		else if (ord[i] == A){
			pos_fila--;
		}
		else pos_fila++;


		repeticion_pos[pos_fila][pos_columna]++;

		//Mientras este en rango aumenta el numero de ordenes.
		if (pos_fila + 1 >= MIN && pos_fila + 1 <= NUM_FILAS
			&& pos_columna + 1 >= MIN && pos_columna + 1 <= NUM_COLS ){

			numero_ordenes++;

		}

		/* Si una posicion no es correcta sale del bucle y se mostrara cuantas
		ordenes mantuvieron al robot en rango. */
		else {
			pos_correcta = false;
		}

	}

	//Salida de datos.

	cout.setf (ios :: showpoint);
	cout.setf (ios :: fixed);

	cout << endl;

	cout << "VALORES INICIALES" << endl << endl;

	cout << "Posicion inicial [" << f << ", " << c << "]" << endl;

	cout << "Ordenes = ";

	for (int i = 0; i < lon; i++){
		cout << ord[i];
	}
	cout << endl;
	cout << "Num. ordenes = " << lon << endl << endl;

	cout << "----------------------------" << endl << endl;

	if (pos_correcta){

		cout << "Serie de ordenes: correcta." << endl << endl;
		cout << "Se ejecutaron " << numero_ordenes << " ordenes";
		cout << endl << endl;


		for (int i = 0; i < NUM_FILAS; i++){
			cout << setw(3) << NUM_FILAS - i << "|"<< setw(4);
			for (int j = 0; j < NUM_COLS; j++){
				cout << repeticion_pos [i][j] << "  ";
			}
			cout << endl;
		}
		cout << endl;
		cout << setw(8);
		for (int j = 0; j < NUM_COLS; j++){

			cout << j + 1 << "| ";
		}

	}
	else {
		cout << "Serie de ordenes: incorrecta."<< endl;
		cout << "Se ejecutaron " << numero_ordenes << " ordenes." << endl;

	}

	cout << endl;
	cout << "***********************************************" << endl << endl;



	return 0;
}
