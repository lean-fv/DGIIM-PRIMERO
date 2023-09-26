/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS IV

44. Para controlar los tiempos que emplean los corredores de una carrera
popular se desea disponer de un programa muy sencillo que se irá ampliando en
sucesivas versiones. En esta primera versión el programa empezará pidiendo la
hora de inicio de la carrera (hora, minuto y segundo) y la distancia.

Después, para cada corredor que llega a meta (por orden de llegada) se pide el
número de dorsal y la hora de llegada (hora, minuto y segundo). Tras leer estos
datos el programa mostrará el tiempo que ha empleado en completar la carrera
(horas, minutos y segundos) y su ritmo (en km/h y en minutos/km).

El programa finalizará cuando al solicitar el número de dorsal se introduzca un
valor negativo.

Nota: Deberá filtrar todos los datos leídos.

14. Reescribid el programa construido para implementar la solución al ejercicio
44 de la Relación de Problemas II (control de una carrera) modularizando con
funciones. Bastará con modularizar, al menos, los filtros de lectura de la
hora, minuto y segundos.

Si encuentra alguna otra tarea que pueda modularizarse sensatamente, hágalo.

6. Reescribid el programa construido para implementar la solución al ejercicio
14 de la Relación de Problemas III (control de una carrera, con funciones).
Use datos de tipo Instante, para registrar tripletas (hora, minuto, segundo)
en la resolución de este problema.

ENTRADA: horas, minutos, segundos de salida y llegada, distancia y dorsal.
SALIDA: tiempo empleado, ritmo y velocidad.

*/


#include <iostream>

using namespace std;

struct Instante {

	int hora;
	int minuto;
	int segundo;
};

// Las siguientes funciones son filtros de datos correctos.

void HorasBien (Instante instante){
	while(instante.hora < 0 || instante.hora > 23){
		cout << "Vuelva a introducir las horas: ";
		cin >> instante.hora;
	}
}

void MinutosBien (Instante instante){
	while (instante.minuto < 0 || instante.minuto > 59){
		cout << "Vuelva a introducir los minutos: ";
		cin >> instante.minuto;
	}
}

void SegundosBien (Instante instante){
	while (instante.segundo < 0 || instante.segundo > 59){
		cout << "Vuelva a introducir los segundos: ";
		cin >> instante.segundo;
	}
}

int main () {

	//Declaraciones

	Instante inicio;
	Instante llegada;
	int segundos_iniciales;
	double distancia;
	int dorsal;
	int segundos_finales;
	int segundos_totales;
	double minutos_totales;

	double horas_totales;

	int segundos_salida;
	int minutos_salida;
	int horas_salida;
	double velocidad;
	double ritmo;

	const int SEGUNDOS_HORA = 3600;
	const int MINUTOS_HORA = 60;
	const int SEGUNDOS_MINUTO = 60;
	const int HORAS_DIA = 24;
	const int SEGS_DIA = 86400;


	cout << "Introduzca las horas del inicio de la carrera: ";
	cin >> inicio.hora;

	HorasBien (inicio);


	cout << "Introduzca los minutos del inicio de la carrera: ";
	cin >> inicio.minuto;

	MinutosBien (inicio);


	cout << "Introduzca los segundos del inicio de la carrera: ";
	cin >> inicio.segundo;

	SegundosBien (inicio);


	do{
		cout << "Introduzca la distancia a recorrer en la carrera: ";
		cin >> distancia;
	}
	while (distancia <= 0);


	cout << "Introduzca el numero de su dorsal: ";
	cin >> dorsal;


	bool dorsal_bien = (dorsal >= 0);

	while (dorsal_bien){ //Se ejecuta la instruccion mientras el dorsal sea +.


		cout << "Introduzca las horas de llegada: ";
		cin >> llegada.hora;

		HorasBien (llegada);

		cout << "Introduzca los minutos de llegada: ";
		cin >> llegada.minuto;

		MinutosBien (llegada);

		cout << "Introduzca los segundos de llegada: ";
		cin >> llegada.segundo;

		SegundosBien (llegada);

		// Calculos

		segundos_iniciales =
		inicio.hora*SEGUNDOS_HORA + inicio.minuto*SEGUNDOS_MINUTO
		+ inicio.segundo;
		segundos_finales =
		llegada.hora*SEGUNDOS_HORA + llegada.minuto*SEGUNDOS_MINUTO
		+ llegada.segundo;
		segundos_totales = segundos_finales - segundos_iniciales;


		// Si se empieza y termina la carrera el mismo dia.

		if (segundos_totales > 0){

			// Calculos.

			segundos_salida = segundos_totales%SEGUNDOS_MINUTO;
			minutos_salida = (segundos_totales/SEGUNDOS_MINUTO)%MINUTOS_HORA;
			horas_salida = (segundos_totales/SEGUNDOS_HORA)%HORAS_DIA;

			minutos_totales = segundos_totales/SEGUNDOS_MINUTO;
			ritmo = minutos_totales/distancia;

			horas_totales = segundos_totales/SEGUNDOS_HORA;
			velocidad = distancia/horas_totales;

			// Salida de datos

			cout << endl;
			cout << "Ha completado la carrera en " << horas_salida << " horas "
			<< minutos_salida << " minutos " << segundos_salida << " segundos";
			cout << endl;
			cout << "Su ritmo ha sido de " << ritmo << " min/km";
			cout << endl;
			cout << "Su velocidad ha sido de " << velocidad << " km/h";
		}

		// Si se empieza y termina la carrera en dias distintos.

		if (segundos_totales < 0){

			//Calculos


			segundos_totales=(SEGS_DIA - segundos_iniciales) + segundos_finales;

			segundos_salida = segundos_totales%SEGUNDOS_MINUTO;
			minutos_salida = (segundos_totales/SEGUNDOS_MINUTO)%MINUTOS_HORA;
			horas_salida = (segundos_totales/SEGUNDOS_HORA)%HORAS_DIA;

			minutos_totales = segundos_totales/SEGUNDOS_MINUTO;
			ritmo = minutos_totales/distancia;

			horas_totales = segundos_totales/SEGUNDOS_HORA;
			velocidad = distancia/horas_totales;

			// Salida de datos

			cout << endl;
			cout << "Ha completado la carrera en " << horas_salida << " horas "
			<< minutos_salida << " minutos " << segundos_salida << " segundos";
			cout << endl;
			cout << "Su ritmo ha sido de " << ritmo << " min/km";
			cout << endl;
			cout << "Su velocidad ha sido de " << velocidad << " km/h";
		}

		// Si el instante inicial y final son el mismo:

		if (segundos_totales == 0){

			cout << endl;
			cout << "Acaba de empezar la carrera";
		}

		// Se introduce un nuevo dorsal

		cout << endl;
		cout << "Introduzca el numero de su dorsal: ";
		cin >> dorsal;

		dorsal_bien = (dorsal >= 0);

	} //Se repite el bucle mientras dorsal sea +.

	if (!dorsal_bien){
		cout << endl;
		cout << "El programa ha finalizado";
	}

	return 0;

}
