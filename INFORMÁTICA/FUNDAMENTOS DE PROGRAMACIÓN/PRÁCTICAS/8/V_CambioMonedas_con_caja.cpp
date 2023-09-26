/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS V

12. Escribir un programa para una caja de un supermercado que lea un precio
desde el teclado y una cantidad (se supone que cantidad >= precio) e indique el
número de monedas de 1 euro, 50 céntimos, 10 céntimos, 5 céntimos y 1 céntimo
que se deben dar de cambio. Se indicará el menor número de monedas de cada
clase.

6. Este ejercicio se basa en el ejercicio 12 de la Relación de Problemas I.
Se trataba de calcular el mínimo número de monedas de cada tipo (2 euros,
1 euro, 50 céntimos, 20 céntimos, 10 céntimos, 5 céntimos, 2 céntimos y
1 céntimo) que se entregaban como vuelta después de haber recibido pagado
euros (dato double) por una compra de un importe de total euros (también es un
dato double).

Ahora hay que considerar las monedas disponibles en la caja, de manera que si
no hay monedas de un determinado valor, debe suplirlo usando unidades de valor
inferior.

NOTA: Deberá tener en cuenta la contingencia de no disponer de suficiente
cambio, por supuesto.

Proponemos usar dos array:

a) caja, para guardar las unidades de cada tipo de moneda,
b) valor, para guardar el valor (p.e. en céntimos) de cada tipo de moneda,

de manera que si valor[i] es 20 y caja[i] es 5 indica que disponemos de 5
monedas de 20 céntimos.

El programa leerá los valores de total y pagado y mostrará la cantidad de
monedas que deben devolverse de cada tipo.

NOTA: Por comodidad, inicialice explícitamente el contenido de caja.

Por ejemplo:

const int TIPOS_MONEDA = 8;
......
int caja[TIPOS_MONEDA] = {10, 0, 10, 10, 3, 0, 10, 25};

ó

const int TIPOS_MONEDA = 8;
......
int caja[TIPOS_MONEDA];
......
caja[0] = 10; // Monedas de 1 ct.
caja[1] = 0; // Monedas de 2 ct.
......

ENTRADA: un precio a pagar y cantidad pagada.
SALIDA: el cambio y con cuantas monedas de cada tipo se lleva a cabo.

*/


#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>      // Inclusión de los recursos matemáticos
#include <iomanip>    // Formato
using namespace std;

int main() {


	//Declaraciones.

	double total, pagado;

	const int TIPOS_MONEDA = 8;

	const int VALOR [TIPOS_MONEDA] = {1, 2 , 5 , 10, 20, 50, 100, 200};
	int caja[TIPOS_MONEDA] = 		 {10, 0, 10, 10, 3, 0, 10, 25};
	int devolucion[TIPOS_MONEDA] = 	 {0}; //Array que almacena los cambios de
										  //cada moneda.

	string nombre_moneda[TIPOS_MONEDA] = {"1 cent", "2 cent", "5 cent",
	"10 cent", "20 cent", "50 cent", "1 euro", "2 euros"};

	// Entrada de datos.
	// PRE: pagado >= total

	cout << "***********************************************" << endl << endl;

	cout << "Total a pagar: ";
	cin >> total;

	do{ //Filtro
		cout << "Cantidad pagada: ";
		cin >> pagado;
	}while (pagado < total);

	// Cálculos

	// "total" y "pagado" se ajustan (truncan) a dos decimales
 	total = trunc(total * 100) / 100;
 	pagado = trunc(pagado * 100) / 100;

	double cambio = pagado - total; //Conservamos lo que hay que devolver.

 	int total_int, pagado_int; // "total" y "pagado" en céntimos
 	int vuelta_int, euros_vuelta, centimos_vuelta; // Vuelta

 	total_int  = trunc(total * 100);     // Convertir "total" a céntimos
 	pagado_int = trunc(pagado * 100);	 // Convertir "pagado" a céntimos
	vuelta_int = pagado_int - total_int; //	Céntimos -totales- a devolver


	int total_cent_caja = 0; //Cantidad total de dinero que hay en la caja.

	for (int i = 0; i < TIPOS_MONEDA; i++){

		total_cent_caja = total_cent_caja + VALOR[i] * caja[i];

	}

	bool hay_suficiente; //Determina si el dinero en caja es suficiente para
						 //proporcionar el cambio.

	if (total_cent_caja >= vuelta_int) hay_suficiente = true;
	else hay_suficiente = false;

	int i = TIPOS_MONEDA - 1; //Posicion en los vectores.

	if (hay_suficiente){

		while ((total_cent_caja > vuelta_int) && (i >= 0) && (vuelta_int > 0)){

			int monedas_caja_iniciales = caja [i];

			/* Mientras la vuelta sea mayor que el valor de la moneda y haya
			monedas del tipo se resta a la vuelta el valor de la moneda y se
			reduce el numero de monedas de ese tipo. */

			while ((vuelta_int >= VALOR[i]) && (caja[i] > 0)){
				vuelta_int = vuelta_int - VALOR[i];
				caja[i]--;
			}

			total_cent_caja = total_cent_caja - monedas_caja_iniciales
							* VALOR[i];
			//Se guarda en un array las monedas de cada tipo que deben ser
			//devueltas.
			devolucion[i] = monedas_caja_iniciales - caja[i];

			//Se actualiza la posicion de la caja y el valor monetario.
			i--;
		}

	} //Hay suficiente dinero en caja.

	//Salida de datos.

	cout << "Cambio: " << cambio << endl;
	cout << "------------------------------------------" << endl;

	if (hay_suficiente){

		cout << "Su cambio es de: " << endl << endl;
		for (int j = TIPOS_MONEDA - 1; j>= 0; j--){

			cout << devolucion[j] << " monedas de " << nombre_moneda[j]
				 << endl;
			cout << "------------------------------------------" << endl;
		}
	}

	else cout << "No hay suficiente dinero en caja." << endl;

	cout << "******************************************" << endl << endl;
	cout << endl;

	return 0;
}
