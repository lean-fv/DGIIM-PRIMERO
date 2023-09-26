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

ENTRADA: Posicion del robot, secuencia de ordenes.
SALIDA: Si la secuencia de ordenes es correcta para permanecer en el rango,
cuantas veces se visito cada posicion cuantas posiciones validas visitadas.

*/

#include <iostream>
#include <string>


using namespace std;

int main() {

	//Declaraciones.
	const int EXTREMO_SUP = 100, EXTREMO_INF = 1, TAM = 200;
	char ord[TAM];
	string orden;
	int pos;
	const int D = 'D', I = 'I';
	bool pos_correcta = true;

	//Entrada de datos.

	cout << "***********************************************" << endl << endl;

	do{
		cout << "Introduzca una posicion inicial. ";
		cin >> pos;
		cout << endl;
	}while (pos < EXTREMO_INF || pos > EXTREMO_SUP);


		cout << "Introduzca una orden. ";
		cin >> orden;
		int lon = (int)orden.length();

		for (int i = 0; i < lon; i++){
			ord[i] = orden.at(i);
		}

	//Calculos.
	int numero_ordenes = 0;
	int pos_minima = EXTREMO_SUP;
	int repeticion_pos [TAM] = {0}; //Contabiliza las veces que pasa por una
									//posicion determinada.
	repeticion_pos[pos]++;

	for (int i = 0; (i < lon) && pos_correcta; i++){

		if (ord[i] == D){
			pos++;
		}
		else {
			pos--;
		}


		repeticion_pos[pos]++;

		//Mientras este en rango aumenta el numero de ordenes.
		if (pos >= EXTREMO_INF && pos <= EXTREMO_SUP){

			numero_ordenes++;

		}

		/* Si una posicion no es correcta sale del bucle y se mostrara cuantas
		ordenes mantuvieron al robot en rango. */
		else {
			pos_correcta = false;
		}

		//Establezco la posicion mas baja a la que ha llegado el robot.
		if (pos < pos_minima)
			pos_minima = pos;

	}

	//Salida de datos.

	cout << endl;
	if (pos_correcta){

		cout << "Serie de ordenes: correcta." << endl << endl;
		cout << "Frecuencia de visitas por posicion: " << endl;

		/*Como el vector estaba inicializado a 0, cuando el bucle llegue a una
		posicion donde no hay un valor mayor o igual que 1, cesara y se
		mostraran todas las posiciones recorridas de menos a mas y cuantas
		veces cada una. */

		while (repeticion_pos[pos_minima] > 0){
			cout << "(" << pos_minima << "," << repeticion_pos[pos_minima]
				 << ") ";
			pos_minima++;
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
