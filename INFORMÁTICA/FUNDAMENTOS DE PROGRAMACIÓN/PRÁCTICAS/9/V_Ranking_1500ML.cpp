/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS V

29. Se quiere elaborar el ránking anual nacional de una prueba de atletismo. Se
trata de los 1500 ML en pista (AL). Cada Federación territorial ha recopilado
los tiempos oficiales de todas las competiciones celebradas y se han remitido a
la Federación nacional que ha elaborado un fichero de texto. En el fichero no
hay ningún orden en los datos aunque la información de cada registro
(un resultado concreto) ocupa una sóla línea. Cada línea tiene la siguiente
información: fecha de evento, código de licencia y tiempo.

• La fecha se encuentra en una palabra de longitud 10 con formato dd/mm/aaaa
• El código de licencia se encuentra en una palabra de longitud variable (su
formato no tiene importancia para este problema).
• El tiempo se encuentra en una palabra de longitud 12 con formato hh:mm:ss:mmm

El número de registros que se van a procesar se desconoce. Se sabe que no hay
más cuando se encuentra la palabra FIN en lugar de una fecha. Por ejemplo:

07/05/2021 GR-4567 00:03:45:105
12/04/2021 MA-67 00:03:43:129
17/10/2021 J-1237 00:03:47:587
01/02/2021 GR-1234 00:04:01:045
05/12/2021 M-11234 00:03:52:345
22/05/2021 B-1092 00:03:52:345
FIN

Escribir un programa que elabore el ránking, ordenando los datos de manera
creciente de acuerdo al tiempo. El resultado debe aparecer bien formateado.
Por ejemplo, para los datos dados anteriormente:
Ranking de la prueba: 1500ML
1 MA-67 12 Abril 2021 03:43:129
2 GR-4567 7 Mayo 2021 03:45:105
3 J-1237 17 Octubre 2021 03:47:587
4 M-11234 5 Diciembre 2021 03:52:345
5 B-1092 22 Mayo 2021 03:52:345
6 GR-1234 1 Febrero 2021 04:01:045

Algunas notas prácticas sobre la resolución:
a) Para mejorar la capacidad de abstracción y facilitar la resolución
recomendamos usar tipos de datos struct para caracterizar a las entidades
básicas fecha (tipo Fecha) y tiempo (tipo Tiempo).

b) La tripleta (fecha, licencia, tiempo) caracteriza a la entidad marca por lo
que también deberían agruparse en un dato struct (llámelo RegistroDeMarca).

c) Las línea del resultado empiezan con un número entero (tres casillas) que
indica la posición en el ránking. Puede usar la función ToString escrita como
solución al ejercicio 19 de la Relación de Problemas III.

d) El código de licencia ocupa 10 casillas.

e) La fecha se presenta en un formato diferente al que se ha leido:
i) Para mostrar el día del mes (dos casillas) use la función ToString
recientemente mencionada (ejercicio 19 de la Relación de Problemas III).
ii) se escribe el nombre del mes (el número de casillas está determinado por el
nombre de mes más largo.
Recomendamos escribir la función string ToString (Fecha la_fecha);

f) El tiempo de carrera se puede presentar de manera diferente a como se lee.
En el ejemplo observe que el campo horas no se muestra -para una prueba como
los 1500ML no procede- y en otros casos como la prueba de 100ML no sería
lógico mostrar los minutos (menos aún las horas).
Recomendamos escribir una función ToString para componer una cadena adecuada al
tipo de tiempo que se quiere mostar. Decida su formato.

g) La ordenación deberá realizarse en base al tiempo. Tenga en cuenta que no
podrá comparar dos datos Tiempo directamente (con los operadores de relación)
por lo que deberá escribir alguna función que compare dos datos de tipo Tiempo.
El siguiente código muestra el contenido del array marcas después de haber sido
ordenado. Puede servirle de referencia.

// Array que se usa para guardar los datos leidos y procesados
const int MAX_ATLETAS = 100;
RegistroDeMarca marcas[MAX_ATLETAS];
int utilizados_marcas = 0;
......
for (int i=0; i<utilizados_marcas; i++) {
cout << ToString(i+1, 3, ’ ’)
<< setw(10) << marcas[i].licencia << " "
<< ToString(marcas[i].fecha_marca) << " "
<< ToString(marcas[i].tiempo_marca,
CategoriaTiempo::minutos)
<< endl;
}

ENTRADA: fecha, codigo de licencia y tiempo.
SALIDA: ranking ordenado por tiempo.

*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MILESIMAS_H = 3600000;
const int MILESIMAS_MIN = 60000;
const int MILESIMAS_SEG = 1000;


//Registro cuyos campos son los integrantes de una marca de una carrera.
struct RegistroDeMarca{
	string fecha;
	string licencia;
	string tiempo;
};

/***************************************************************************
Funcion CalculaMilesimas: devuelve un tiempo en milesimas para facilitar la
ordenacion del vector posteriormente.
***************************************************************************/
int CalculaMilesimas (string tiempo){

	int horas =
	stoi (tiempo.substr (0,1));

	int minutos =
	stoi (tiempo.substr (3,4));

	int segundos =
	stoi (tiempo.substr (6,7));

	int milesimas =
	stoi (tiempo.substr (9,11));

	int total_milesimas =
	horas *  MILESIMAS_H + minutos * MILESIMAS_MIN
	+ segundos * MILESIMAS_SEG + milesimas;

	return total_milesimas;
}

/***************************************************************************
Programa principal.
***************************************************************************/
int main() {

	//Declaraciones.

	const string TERMINADOR = "FIN";

	const int MAX_ATLETAS = 100;
	RegistroDeMarca marcas[MAX_ATLETAS];
	int utilizados_marcas = 0; //Contador de posiciones utilizadas.


	//Entrada de datos.

	cout << "***********************************************" << endl << endl;

	//Lectura anticipada.
	cout << "Introduzca la fecha de su marca.";
	cin >> marcas[utilizados_marcas].fecha;

	while ((marcas[utilizados_marcas].fecha != TERMINADOR) &&
			(utilizados_marcas < MAX_ATLETAS)){

		cout << endl;
		cout << "Introduzca su licencia.";
		cin >> marcas[utilizados_marcas].licencia;
		cout << endl;

		cout << "Introduzca su tiempo:" << endl << endl;
		cin >> marcas[utilizados_marcas].tiempo;

		utilizados_marcas++; // Contador de total de posiciones utilizadas.

		cout << "Introduzca la fecha de su marca.";
		cin >> marcas[utilizados_marcas].fecha;

	}
	//Calculos.

	//Algoritmo de ordenacion de un vector por seleccion.
	for (int izda = 0; izda < utilizados_marcas; izda++){

		int minimo = CalculaMilesimas (marcas[izda].tiempo);
		int pos_min = izda;
		RegistroDeMarca intercambia;

		for (int i = izda + 1; i < utilizados_marcas; i++){
			if (CalculaMilesimas(marcas[i].tiempo) < minimo){
				minimo = CalculaMilesimas (marcas[i].tiempo);
				pos_min = i;
			}
		}
		intercambia = marcas[izda];
		marcas[izda] = marcas[pos_min];
		marcas[pos_min] = intercambia;
	}

	//Salida de datos.

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);

	cout << endl << endl;
	cout << "Ranking de la prueba: 1500ML" << endl << endl;

	for (int i=0; i<utilizados_marcas; i++){
		cout << i + 1 << setw(15) << marcas[i].fecha << " " << setw(10)
			 << marcas[i].licencia <<  " " << setw(15)
			 << marcas[i].tiempo << endl;
	}

	cout << "***********************************************" << endl << endl;



	return 0;
}
