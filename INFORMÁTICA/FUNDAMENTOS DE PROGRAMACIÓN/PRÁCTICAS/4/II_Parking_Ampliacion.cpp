/* **************************************************************************
FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS II

**************************************************************************

	La tabla para el c�lculo del precio a pagar en los parkings
	de Madrid para el 2015 es la siguiente:

	Desde el minuto 0 al 30 (CORTA): 0.0412 euros cada minuto
	Desde el minuto 31 al 90 (MEDIA): 0.0370 euros cada minuto
	Desde el minuto 91 al 120 (LARGA): 0.0311 euros cada minuto
	Desde el minuto 121 al 660 (MUY LARGA): 0.0305 euros cada minuto
	Desde el minuto 661 hasta m�ximo 24 horas (MAXIMA): 24.00 euros

	La hora de entrada puede pertenecer al d�a inmediatamente anterior.
	Se supone que NO transcurren m�s de 24 horas entre la hora de entrada y
	la hora de salida.

	NOTA: no se consideran los segundos

	17. Se acuerda la actualización de las tarifas de aparcamiento incorporando
	un nuevo tramo (desde el minuto 661 hasta el 900 a un coste de 0.0270 euros
	cada minuto) y subiendo el coste de la tarifa plana a 35 euros (aplicable
	ahora desde el minuto 901).

	Actualice el programa con estas nuevas condiciones.

	Entradas: hora y minuto inicial
			  hora y minuto final.
	Salidas:  Cantidad a pagar

***************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

	cout.setf(ios::fixed);		// Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales

	// Constantes

	const int HORAS_DIA = 24;
	const int MINS_HORA = 60;
	const int MINS_DIA  = HORAS_DIA * MINS_HORA;

	const double CANT_CORTA     =  0.0412;
	const double CANT_MEDIA     =  0.0370;
	const double CANT_LARGA     =  0.0311;
	const double CANT_MUY_LARGA =  0.0305;
	const double CANT_MUY_MUY_LARGA = 0.0270;
	const double CANT_MAX_DIA   = 35.0000;

	const int MINS_CORTA     =  30;
	const int MINS_MEDIA     =  90;
	const int MINS_LARGA     = 120;
	const int MINS_MUY_LARGA = 660;
	const int MINS_MUY_MUY_LARGA = 900;

	/*
         30         90  	       120              660						900
  0.0412     0.0370      0.0311          0.0305        	0.0270			 35
|---------|----------|------------|----------------|------------|---------|
	CORTA     MEDIA       LARGA        MUY_LARGA    	MUY_MUY_LARGA		PLANA
	*/

	// Datos de entrada
	int hora_inic, minuto_inic;
	int hora_fin, minuto_fin;

	int num_mins;

	bool hora_inic_ok = false;
	bool hora_fin_ok  = false;
	bool minuto_inic_ok = false;
	bool minuto_fin_ok  = false;
	bool datos_ok = false;

	// Valores calculados

	double precio;
	bool   tarifa_24h;

	int num_mins_muy_muy_larga = 0;
	int num_mins_muy_larga = 0;
	int num_mins_larga     = 0;
	int num_mins_media     = 0;
	int num_mins_corta     = 0;

	double cant_muy_muy_larga = 0.0;
	double cant_muy_larga = 0.0;
	double cant_larga     = 0.0;
	double cant_media     = 0.0;
	double cant_corta     = 0.0;


	// Entrada de datos

	cout << "Introduzca hora inicial:" << endl;
	cout << "\tHora:    ";
	cin >> hora_inic;

 	hora_inic_ok = (hora_inic >= 0 && hora_inic < HORAS_DIA);

	if (hora_inic_ok) {

		cout << "\tMinuto:  ";
		cin >> minuto_inic;

 		minuto_inic_ok = (minuto_inic >= 0 && minuto_inic < MINS_HORA);

		if (minuto_inic_ok) {

		    cout << "Introduzca hora final:" << endl;
			cout << "\tHora:    ";
			cin >> hora_fin;

		 	hora_fin_ok = (hora_fin >= 0 && hora_fin < HORAS_DIA);

			if (hora_fin_ok) {

				cout << "\tMinuto:  ";
				cin >> minuto_fin;

 				minuto_fin_ok = (minuto_fin >= 0 && minuto_fin < MINS_HORA);

				if (minuto_fin_ok) {
					datos_ok = true;
				}
			} // if (hora_fin_ok)

		} // if (minuto_inic_ok)

	} //  if (hora_inic_ok)


	/* El �ltimo bloque condicinal

	if (minuto_fin_ok) {
		datos_ok = true;
	}

	podr�a sustituirse por escribir en este punto (tras la lectura):

	datos_ok = hora_inic_ok && hora_fin_ok && minuto_inic_ok && minuto_fin_ok;

	pero es m�s costoso (razone por qu�).
	*/


	// C�lculos

	if (datos_ok) {

		// 1. Calcular n�mero de minutos entre la entrada y la salida

		int mins_hora_inic = (hora_inic * MINS_HORA) + minuto_inic;
		int mins_hora_fin = (hora_fin * MINS_HORA) + minuto_fin;

		num_mins = mins_hora_fin - mins_hora_inic;

		// Si el n�mero de minutos es negativo significa que la hora de entrada
		// corresponde al d�a anterior

		if (num_mins < 0) {

			// (MINS_DIA - mins_hora_inic) + mins_hora_fin
			// MINS_DIA - mins_hora_inic + mins_hora_fin
			// MINS_DIA + (mins_hora_fin - mins_hora_inic)
			// MINS_DIA + num_mins

			num_mins = MINS_DIA + num_mins;
		}

		// 2. Determinar la tarifa por partes

		precio = 0;

		int num_mins_quedan = num_mins;


		// El caso m�s simple es una largu�sima permanencia --> precio �nico
		if (num_mins > MINS_MUY_MUY_LARGA){

			/*
		         30         90  	       120              660						900
		  0.0412     0.0370      0.0311          0.0305        	0.0270			 35
		|---------|----------|------------|----------------|------------|********|
			CORTA     MEDIA       LARGA        MUY_LARGA    	MUY_MUY_LARGA		PLANA
			*/

			precio = CANT_MAX_DIA;
			tarifa_24h = true;

		}

		else { // Si no, hay que calcular el precio por tramo

			if (num_mins > MINS_MUY_LARGA) {

		/*
						30         90  	       120              660						900
		0.0412     0.0370      0.0311          0.0305        	0.0270			 35
	|---------|----------|------------|----------------|************|--------|
		CORTA     MEDIA       LARGA        MUY_LARGA    	MUY_MUY_LARGA		PLANA
		*/

		num_mins_muy_muy_larga = num_mins_quedan - MINS_MUY_LARGA;
		cant_muy_muy_larga = num_mins_muy_muy_larga  * CANT_MUY_MUY_LARGA;
		precio += cant_muy_muy_larga;
		num_mins_quedan = MINS_MUY_LARGA;

			}

				tarifa_24h = false;

				if (num_mins > MINS_LARGA) { // Muy larga estancia

			/*
							30         90  	       120              660						900
			0.0412     0.0370      0.0311          0.0305        	0.0270			 35
		|---------|----------|------------|****************|------------|--------|
			CORTA     MEDIA       LARGA        MUY_LARGA    	MUY_MUY_LARGA		PLANA
			*/
					num_mins_muy_larga = num_mins_quedan - MINS_LARGA;
					cant_muy_larga = num_mins_muy_larga  * CANT_MUY_LARGA;
					precio += cant_muy_larga;
					num_mins_quedan = MINS_LARGA;
				}

				if (num_mins > MINS_MEDIA) { // Larga estancia

			/*
							30         90  	       120              660						900
			0.0412     0.0370      0.0311          0.0305        	0.0270			 35
		|---------|----------|***********|-----------------|------------|--------|
			CORTA     MEDIA       LARGA        MUY_LARGA    	MUY_MUY_LARGA		PLANA

			*/
					num_mins_larga = num_mins_quedan - MINS_MEDIA;
					cant_larga = num_mins_larga * CANT_LARGA;
					precio += cant_larga;
					num_mins_quedan = MINS_MEDIA;
				}

				if (num_mins_quedan > MINS_CORTA) { // Media estancia

			/*
							30         90  	       120              660						900
			0.0412     0.0370      0.0311          0.0305        	0.0270			 35
		|---------|*******|-------------|-----------------|------------|--------|
			CORTA     MEDIA       LARGA        MUY_LARGA    	MUY_MUY_LARGA		PLANA

			*/
					num_mins_media = num_mins_quedan - MINS_CORTA;
					cant_media = num_mins_media * CANT_MEDIA;
					precio += cant_media;
					num_mins_quedan = MINS_CORTA;
				}

				// Corta estancia

		/*
						30         90  	       120              660						900
		0.0412     0.0370      0.0311          0.0305        	0.0270			 35
	|*********|---------|-------------|-----------------|------------|--------|
		CORTA     MEDIA       LARGA        MUY_LARGA    	MUY_MUY_LARGA		PLANA

		*/

				num_mins_corta = num_mins_quedan;
				cant_corta = num_mins_corta * CANT_CORTA;
				precio += cant_corta;

			}
	}

	// Salida

	if (datos_ok) {

		cout << endl;
		cout << "Tarifa final =  " <<setw(6)<< setprecision(2)<< precio<< endl;
		cout << endl;
		cout << "Minutos de estancia = " << num_mins << endl;
		cout << endl;

		if (tarifa_24h)

			cout << "\tSe ha aplicado tarifa maxima." << endl;

		else {

			cout << "\tCorta     = " << setw(3)
			     << num_mins_corta << " (x "
				 << setw(5) << setprecision(4) << CANT_CORTA << ") = "
				 << setw(5) << setprecision(2) << cant_corta << endl;
			cout << "\tMedia     = " << setw(3)
			     << num_mins_media << " (x "
				 << setw(5) << setprecision(4) << CANT_MEDIA << ") = "
				 << setw(5) << setprecision(2) << cant_media << endl;
			cout << "\tLarga     = " << setw(3)
			     << num_mins_larga << " (x "
				 << setw(5) << setprecision(4) << CANT_LARGA << ") = "
				 << setw(5) << setprecision(2) << cant_larga << endl;
			cout << "\tMuy Larga = " << setw(3)
			     << num_mins_muy_larga << " (x "
				 << setw(5) << setprecision(4) << CANT_MUY_LARGA << ") = "
				 << setw(5) << setprecision(2) << cant_muy_larga << endl;
			cout << "\tMuy Muy Larga = " << setw(3)
	 			   << num_mins_muy_muy_larga << " (x "
	 		 	 << setw(5) << setprecision(4) << CANT_MUY_MUY_LARGA << ") = "
	 			 << setw(5) << setprecision(2) << cant_muy_muy_larga << endl;
			cout << "                                     "
				 << "-----" << endl;
			cout << "                                     "
				 << setw(5) << setprecision(2) << precio << endl;
		}
		cout << endl;

	}

	else { // !datos_ok

		if (!hora_inic_ok) {
			cout << endl;
			cout << "ERROR: Hora inicial incorrecta."<< endl;
			cout << endl;
		}
		else if (!minuto_inic_ok) {
			cout << endl;
			cout << "ERROR: Minuto inicial incorrecto."<< endl;
			cout << endl;
		}
		else if (!hora_fin_ok) {
			cout << endl;
			cout << "ERROR: Hora final incorrecta."<< endl;
			cout << endl;
		}
		else {
 			cout << endl;
			cout << "ERROR: Minuto final incorrecto."<< endl;
			cout << endl;
		 }
	}

	return 0;
}
