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

	31. Usando como base el programa que soluciona el ejercicio 17 escribid un
	programa que lea la hora actual (minutos y segundos, por separado) y una
	cantidad de dinero (en euros) y nos indique hasta qué hora podemos tener
	el coche aparcado si vamos a pagar con la cantidad especificada.

	Implementar los filtros adecuados al problema.

	Si dispone de 5 euros y 25 céntimos deberá indicar el valor 5.25 cuando se
	le pida el dinero disponible.

	Actualice el programa con estas nuevas condiciones.

	Entradas: hora y minuto inicial y dinero disponible.
	Salidas:  hora hasta que se puede dejar el coche en el parking.

***************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	cout.setf(ios::fixed);		// Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales

	// Constantes

	const int LIM_HORAS1 = 0;
	const int LIM_HORAS2 = 23;
	const int LIM_MINUTOS1 = 0;
	const int LIM_MINUTOS2 = 59;

	const int HORAS_DIA = 24;
	const int SEGUNDOS_MIN = 60;
	const int MINS_HORA = 60;
	const int MINS_DIA  = HORAS_DIA * MINS_HORA;
	const int SEGUNDOS_HORA = SEGUNDOS_MIN * MINS_HORA;

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

	const double PRECIO_CORTA = MINS_CORTA * CANT_CORTA;

	const double PRECIO_MEDIA =
	((MINS_MEDIA - MINS_CORTA) * CANT_MEDIA) + PRECIO_CORTA;

	const double PRECIO_LARGA =
	((MINS_LARGA - MINS_MEDIA) * CANT_LARGA) + PRECIO_MEDIA;

	const double PRECIO_MUY_LARGA =
	((MINS_MUY_LARGA - MINS_LARGA) * CANT_MUY_LARGA) + PRECIO_LARGA;

	const double PRECIO_MUY_MUY_LARGA =
	((MINS_MUY_MUY_LARGA - MINS_MUY_LARGA) * CANT_MUY_MUY_LARGA)
	+ PRECIO_MUY_LARGA;


	/*
         30         90  	       120              660						900
  0.0412     0.0370      0.0311          0.0305        	0.0270			 35
|---------|----------|------------|----------------|------------|---------|
	CORTA     MEDIA       LARGA        MUY_LARGA    	MUY_MUY_LARGA		PLANA
	*/

	// Datos de entrada
	int hora_inic, minuto_inic;
	double dinero;
	int hora_fin, minuto_fin;


	// Entrada de datos

	//Filtro horas.
	do{
		cout << "Introduzca hora inicial:" << endl;
		cout << "\tHora:    ";
		cin >> hora_inic;
	} while (hora_inic < LIM_HORAS1 || hora_inic > LIM_HORAS2);

	//Filtro minutos.
	do{
		cout << "\tMinuto:  ";
		cin >> minuto_inic;
	} while (minuto_inic < LIM_MINUTOS1 || minuto_inic > LIM_MINUTOS2);

	//Filtro dinero.
	do{
		cout << "\tDinero:  ";
		cin >> dinero;
	} while (dinero < 0);


	// C�lculos

		//Paso a minutos el momento incial.
		int minutos_hora_inic = hora_inic * MINS_HORA + minuto_inic;

		int minutos_adicionales;

		//Calculo por tramos.

		if (dinero >= PRECIO_MUY_MUY_LARGA && dinero < CANT_MAX_DIA) {

			minutos_adicionales =
			MINS_MUY_LARGA + (dinero - PRECIO_MUY_MUY_LARGA) / CANT_MUY_MUY_LARGA;

		/*
						30         90  	       120              660						900
		0.0412     0.0370      0.0311          0.0305        	0.0270			 35
	|---------|----------|------------|----------------|************|--------|
		CORTA     MEDIA       LARGA        MUY_LARGA    	MUY_MUY_LARGA		PLANA
		*/
		}

		else if (dinero >= PRECIO_MUY_LARGA && dinero < PRECIO_MUY_MUY_LARGA) {


			minutos_adicionales =
			MINS_LARGA + (dinero - PRECIO_MUY_LARGA) / CANT_MUY_LARGA;

			/*
							30         90  	       120              660						900
			0.0412     0.0370      0.0311          0.0305        	0.0270			 35
		|---------|----------|------------|****************|------------|--------|
			CORTA     MEDIA       LARGA        MUY_LARGA    	MUY_MUY_LARGA		PLANA
			*/

		}

		else if (dinero >= PRECIO_LARGA && dinero < PRECIO_MUY_LARGA){

			minutos_adicionales =
			MINS_MEDIA + (dinero - PRECIO_LARGA) / CANT_LARGA;

			/*
							30         90  	       120              660						900
			0.0412     0.0370      0.0311          0.0305        	0.0270			 35
		|---------|----------|***********|-----------------|------------|--------|
			CORTA     MEDIA       LARGA        MUY_LARGA    	MUY_MUY_LARGA		PLANA

			*/
		}

		else if (dinero >= PRECIO_MEDIA && dinero < PRECIO_LARGA) {

			minutos_adicionales =
			MINS_CORTA + (dinero - PRECIO_MEDIA) / CANT_MEDIA;

			/*
							30         90  	       120              660						900
			0.0412     0.0370      0.0311          0.0305        	0.0270			 35
		|---------|*******|-------------|-----------------|------------|--------|
			CORTA     MEDIA       LARGA        MUY_LARGA    	MUY_MUY_LARGA		PLANA

			*/

		}

		else if (dinero < PRECIO_CORTA) {

			minutos_adicionales = dinero / CANT_LARGA;

		/*
						30         90  	       120              660						900
		0.0412     0.0370      0.0311          0.0305        	0.0270			 35
	|*********|---------|-------------|-----------------|------------|--------|
		CORTA     MEDIA       LARGA        MUY_LARGA    	MUY_MUY_LARGA		PLANA

		*/

		}
		//Calculo los minutos totales en base al dinero que se introduzca.
		int minutos_totales = minutos_hora_inic + minutos_adicionales;

		/* Paso a horas y minutos y filtro para que no se exceda de 23 horas y
		59 minutos */
		hora_fin = (minutos_totales / MINS_HORA) % HORAS_DIA;
		minuto_fin = minutos_totales % MINS_HORA;



	// Salida

	if (dinero >= CANT_MAX_DIA){

		cout << "Puede dejar su coche en el parking hasta la misma hora del dia ";
		cout << "siguiente.";

	}

	else {
		cout << "Puede dejar su coche en el parking hasta las "
			   << hora_fin << " horas " << minuto_fin << " minutos.";
	}

	cout <<  endl << endl;

	return 0;
}
