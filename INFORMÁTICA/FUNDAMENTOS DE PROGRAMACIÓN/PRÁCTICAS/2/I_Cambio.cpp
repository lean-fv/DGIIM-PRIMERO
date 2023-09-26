/*

12. Escribir un programa para una caja de un supermercado que lea un precio
desde el teclado y una cantidad (se supone que cantidad >= precio) e indique el
número de monedas de 1 euro, 50 céntimos, 10 céntimos, 5 céntimos y 1 céntimo
que se deben dar de cambio. Se indicará el menor número de monedas de cada
clase.

*/

#include <iostream>

using namespace std;

int main() {

	//Declaración de variables.

	double precio, pago, cambio;
	int monedas_1_euro;
	int monedas_50_cent, monedas_10_cent, monedas_5_cent, monedas_1_cent;

	const int CENTIMOS_EURO = 100;
	const int CINCUENTA_CENT = 50;
	const int VEINTE_CENT = 20;
	const int DIEZ_CENT = 10;
	const int CINCO_CENT = 5;

	//Solicitud de datos al usuario.

	cout << "**************************************************" << endl;

	cout << "Introduzca el precio de su compra en euros. ";
	cin >> precio;
	cout << endl;

	cout << "Introduzca su pago en euros. ";
	cin >> pago;
	cout << endl;

	//Operaciones.

	cambio = (pago - precio);

	//Las monedas de 1 euro son la parte entera del cambio.

	monedas_1_euro = cambio;

	/*

	Las demas monedas se calculan dividiendo el resto de centimos entre el
	valor correspondiente de la moneda.

	*/
	int resto_centimos = (cambio - monedas_1_euro) * CENTIMOS_EURO;

	monedas_50_cent = resto_centimos / CINCUENTA_CENT;

	monedas_10_cent = (resto_centimos % CINCUENTA_CENT) / DIEZ_CENT;

	monedas_5_cent = ((resto_centimos % CINCUENTA_CENT) % DIEZ_CENT)
					/ CINCO_CENT;

	monedas_1_cent = ((resto_centimos % CINCUENTA_CENT) % DIEZ_CENT)
					% CINCO_CENT;

	//Salida de datos.

	cout << "Se devuelven " << monedas_1_euro << " monedas de 1 euro, ";
	cout << monedas_50_cent << " monedas de 50 cent, ";
	cout << monedas_10_cent << " monedas de 10 cent, ";
	cout << monedas_5_cent << " monedas de 5 cent y ";
	cout << monedas_1_cent << " monedas de 1 cent. " << endl;

	cout << "****************************************************" << endl;

	return 0;
	}
