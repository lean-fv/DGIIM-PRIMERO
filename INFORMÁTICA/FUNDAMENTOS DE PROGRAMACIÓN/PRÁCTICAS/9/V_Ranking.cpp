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



44. Se desea ampliar la funcionalidad del programa escrito en el ejercicio 29
de esta misma Relación de Problemas (calcular el ránking en la prueba de
1500ML). En esta ocasión se va a calcular el ránking en varias pruebas
seleccionadas anteriormente.

La solución, no obstante, no debería ser muy distinta. Se proponía la
ordenación del array marcas en base al tiempo. Piense en el problema actual
como una extensión: como si dispusiéramos de varios array (uno por prueba) y
cada uno contuviera sus marcas, en cantidades posiblemente distintas a los de
las otras pruebas.

Concretando, se propone organizar todas las marcas en la matriz marcas:

const int MAX_PRUEBAS = 20;
const int MAX_MARCAS_EN_PRUEBA = 100;
RegistroDeMarca marcas[MAX_PRUEBAS][MAX_MARCAS_EN_PRUEBA];
// Número de filas ocupadas de "marcas"
int num_pruebas; // PRE: 0 <= num_pruebas <= MAX_PRUEBAS

En cada fila se guardarán todas las marcas de la misma prueba. Su número podría
ser distinto para diferentes filas (no todas las pruebas tienen el mismo número
de marcas).

Para guardar el número de casillas ocupadas por fila habrá que usar un array:

int num_marcas_en_prueba[MAX_PRUEBAS];
// PRE: 0<=num_marcas_en_prueba[i]<=MAX_MARCAS_EN_PRUEBA

de manera que num_marcas_en_prueba[f] guardará cuántas marcas de la prueba f
(0 <= f < num_pruebas) están guardadas en la matriz marcas.

Los datos sobre los que se va a trabajar se leen de la entrada estándar. El
formato es muy simple. Por ejemplo:
5 100ML 200ML 400ML 800ML 1500ML
1500ML 07/05/2021 GR-4567 00:03:45:105
800ML 22/01/2021 GR-237 00:01:21:147
200ML 05/08/2021 GR-465 00:00:22:122
1500ML 01/02/2021 GR-1234 00:04:01:045
100ML 22/05/2021 B-1092 00:00:12:345
......
100ML 07/11/2021 SE-123 00:00:12:345
400ML 22/07/2021 GR-237 00:00:43:258
FIN
La primera fila: 5 100ML 200ML 400ML 800ML 1500ML
indica que se van a considerar 5 pruebas (num_pruebas valdrá 5) y las pruebas
serán las etiquetadas con las palabras 100ML, 200ML, 400ML, 800ML y 1500ML (el
orden no debería ser importante).

Después aparecerán las marcas. El final de la serie de marcas está indicada por
la palabra FIN. Observe que la líneas tienen un formato similar al del ejercicio
29 solo que ahora aparece un nuevo elemento al principio: una palabra que
identifica la prueba (debe suponer que será una de las etiquetas que aparece en
la primera línea).

El programa leerá los datos, los guardará en la matriz marcas, ordenará por
filas los registros de marcas de acuerdo al tiempo y presentará el resultado de
manera legible.

Por ejemplo:

Ranking general.
100ML
1 GR-1234 1 Febrero 2021 00:11:045
2 GR-6789 5 Agosto 2021 00:12:000
3 B-1092 22 Mayo 2021 00:12:345
4 SE-123 7 Noviembre 2021 00:12:345
200ML
1 MA-67 12 Abril 2021 00:21:129
2 GR-465 5 Agosto 2021 00:22:122
3 GR-6789 5 Agosto 2021 00:24:135
400ML
1 MA-1247 15 Junio 2021 00:41:002
2 AL-543 18 Marzo 2021 00:41:098
3 MA-4547 2 Enero 2021 00:41:132
4 AL-47 6 Octubre 2021 00:42:232
5 GR-237 22 Julio 2021 00:43:258
800ML
1 GR-237 22 Enero 2021 01:21:147
2 M-11234 15 Octubre 2021 01:22:001
3 V-35 12 Septiembre 2021 01:24:345
1500ML
1 MA-67 12 Abril 2021 03:43:129
2 GR-4567 7 Mayo 2021 03:45:105
3 J-1237 17 Octubre 2021 03:47:587
4 B-1092 22 Mayo 2021 03:52:345
5 M-11234 5 Diciembre 2021 03:52:345
6 GR-1234 1 Febrero 2021 04:01:045

ENTRADA: numero de pruebas, fecha, codigo de licencia y tiempo.
SALIDA: ranking ordenado por tiempo de cada prueba.

*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MILESIMAS_H = 3600000;
const int MILESIMAS_MIN = 60000;
const int MILESIMAS_SEG = 1000;

/*struct Tiempo{
	string horas;
	string minutos;
	string segundos;
	string centesimas;
};

*/

//Registro cuyos campos son los integrantes de nua marca de una carrera.
struct RegistroDeMarca{
	string prueba;
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

	const int MAX_PRUEBAS = 20;
	const int MAX_MARCAS_EN_PRUEBA = 100;
	RegistroDeMarca clasificacion[MAX_PRUEBAS][MAX_MARCAS_EN_PRUEBA];
	// Número de filas ocupadas de "marcas"
	int num_pruebas; // PRE: 0 <= num_pruebas <= MAX_PRUEBAS


	int num_marcas_en_prueba[MAX_PRUEBAS] = {0};
	// PRE: 0<=num_marcas_en_prueba[i]<=MAX_MARCAS_EN_PRUEBA


	//Entrada de datos.

	cout << "***********************************************" << endl << endl;

	do{
		cout << "Introduzca el numero de pruebas.";
		cin >> num_pruebas;
	}while (num_pruebas < 0 || num_pruebas > MAX_PRUEBAS);

	string tipo_pruebas[MAX_PRUEBAS];
	int total_pruebas = 0;
	while (total_pruebas < num_pruebas){
		cout << "Introduzca sus pruebas.";
		cin >> tipo_pruebas[total_pruebas];
		total_pruebas++;
	}

	int utilizados_pruebas = 0;

	cout << "Introduzca el tipo de prueba.";
	cin >> marcas[utilizados_pruebas].prueba;

	while ((marcas[utilizados_pruebas].prueba != TERMINADOR) &&
			(utilizados_pruebas < MAX_MARCAS_EN_PRUEBA)){

		cout << endl;
		cout << "Introduzca su licencia.";
		cin >> marcas[utilizados_pruebas].licencia;
		cout << endl;

		cout << "Introduzca su tiempo:" << endl << endl;
		cin >> marcas[utilizados_pruebas].tiempo;


		utilizados_pruebas++; // Contador de total de posiciones utilizadas.

		cout << "Introduzca el tipo de prueba.";
		cin >> marcas[utilizados_pruebas].prueba;
	}

	//Calculos.

	for (int i = 0; i < utilizados_pruebas; i++){

		for (int j=0; i < utilizados_pruebas; j++){

			if (tipo_pruebas[i] == marcas[j].prueba){
				num_marcas_en_prueba[i]++;
			}
		}
	}

	//Algoritmo de ordenacion de un vector por seleccion.
	for (int izda = 0; izda < utilizados_pruebas; izda++){

		int minimo = CalculaMilesimas (marcas[izda].tiempo);
		int pos_min = izda;
		RegistroDeMarca intercambia;

		for (int i = izda + 1; i < utilizados_pruebas; i++){
			if (CalculaMilesimas(marcas[i].tiempo) < minimo){
				minimo = CalculaMilesimas (marcas[i].tiempo);
				pos_min = i;
			}
		}
		intercambia = marcas[izda];
		marcas[izda] = marcas[pos_min];
		marcas[pos_min] = intercambia;
	}

	for (int i = 0; i < total_pruebas; i++){

		for (int j = 0; j < num_marcas_en_prueba[i]; j++){

			clasificacion [i][j] = marcas[j];

		}
	}
	//Salida de datos.

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);

	for (int i = 0; i < num_pruebas; i++){
		cout << endl;
		for (int j = 0; j < num_marcas_en_prueba[i]; j++){

			cout << clasificacion[i][j].fecha << " "
				 << clasificacion[i][j].licencia << " "
				 <<clasificacion[i][j].tiempo << " ";

		}
	}
	cout << "***********************************************" << endl << endl;



	return 0;
}
