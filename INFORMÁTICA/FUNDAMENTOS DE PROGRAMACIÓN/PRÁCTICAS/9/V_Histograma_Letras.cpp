/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS V

35. (Examen Extraordinario 2016) Queremos calcular la frecuencia absoluta de
las vocales presentes en un texto y mostrar el resultado en forma de histograma
usando caracteres. El histograma resultante deberá tener un aspecto como el de
la figura 23.

El histograma que nos interesa, tal como se muestra en la figura, se puede
mostrar a partir de una matriz de caracteres. El del ejemplo tiene tantas
líneas como la frecuencia de la vocal que más se repite (7), y tantas columnas
como el número de vocales (5). Se emplea el carácter asterisco (ASCII 42) para
indicar que la casilla está ocupada y el carácter espacio (ASCII 32) para
indicar que la casilla está libre.

Escribir un programa completo que lea una serie indefinida de caracteres de
caracteres de la entrada estándar (terminados por *) y que muestre el
histograma que representa la frecuencia absoluta de las vocales introducidas.
Suponed que la frecuencia mayor de la vocal que más se repite fuera 500.

36. Vamos a mejorar el ejercicio 35 calculando el histograma para todas las
letras del alfabeto español∗.

Escribir un programa completo que lea una serie indefinida de caracteres de la
entrada estándar (terminados por *) y que muestre el histograma que
representa la frecuencia de las letras introducidas.

Como ayuda, considere las definiciones:
// Numero de caracteres a considerar
const int MUM_CARACTERES = ’z’-’a’+1;
char las_letras [MUM_CARACTERES]; // Letras a procesar
int veces_letras[MUM_CARACTERES] = {0}; // Contadores

// Dimensiones del tablero de dibujo
const int NUM_FILAS = 30; // Núm. de filas
const int NUM_COLS = MUM_CARACTERES; // Núm. de columnas
char histograma [NUM_FILAS][NUM_COLS];
A la letra más frecuente (en el ejemplo, la ’o’ siempre se le asociará una
barra con NUM_FILAS (en el ejemplo, 30) caracteres y a las demás letras se les
asociará una barra con una altura proporcional a su frecuencia tomando como
referencia la de la letra más frecuente.

∗ Algunas consideraciones prácticas:

a) No se van a diferenciar mayúsculas de minúsculas. En el ejemplo que les
mostramos hemos considerado las letras minúsculas por lo que las mayúsculas se
han transformado a minúsculas antes de procesarlas.

b) Considere las vocales acentuadas junto a sus correspondientes no acentuadas.
Por ejemplo, si encuentra el carácter á ó el carácter Á deberá considerarlos
como si fueran el carácter a.

c) Considere al carácter ü (resp.Ü) junto a la vocal u.

d) Considere al carácter ñ (resp. Ñ) junto al carácter n.

La lectura y procesamiento de los caracteres especiales (los específicos del
alfabeto español lo son) no se realiza exactamente igual que los demás. Para
entender cómo debe realizarse disponen en PRADO de un programa completo
(Prueba_de_letras.cpp) para entender cómo deben procesarlos.

ENTRADA: Una secuencia de caracteres.
SALIDA: Frecuencia de cada caracter y un histograma.

*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <clocale>

using namespace std;

/***************************************************************************/
// Devuelve "true" si "c" es un carácter especial del alfabeto español:
// á é í ó ú ñ Á É Í Ó Ú Ñ ü

bool EsCaracterEspecialEspaniol (unsigned char c)
{
	// á 225, é 233, í 237, ó 243, ú 250, ñ 241
	// Á 193, É 201, Í 205, Ó 211, Ú 218, Ñ 209, ü 252

	return (c==225 || c==233 || c==237 || c==243 || c==250 || c==241 ||
			c==193 || c==201 || c==205 || c==211 || c==218 || c==209 ||
			c==252);
}

/***************************************************************************/
// Convierte un carácter especial "c" a su equivalente estándar
// á (225) Á (193) --> a       ó (243) Ó (211) --> o
// é (233) É (201) --> e       ú (250) Ú (218) ü (252) --> u
// í (237) Í (205) --> i       ñ (241) Ñ (209) --> ñ
//
// Si "c" no requiere transformación devuelve el mismo valor

char TransformaCaracterEspecialEspaniol (unsigned char c)
{
	char nuevo;

	switch (c) {

		case (225) :
		case (193) : nuevo = 'a';
					 break;
		case (233) :
		case (201) : nuevo = 'e';
					 break;
		case (237) :
		case (205) : nuevo = 'i';
					 break;
		case (243) :
		case (211) : nuevo = 'o';
					 break;
		case (250) :
		case (218) :
		case (252) : nuevo = 'u';
					 break;
		case (241) :
		case (209) : nuevo = 'n';
					 break;
		default: 	nuevo = c;
					break;
	}

	return (nuevo);
}

/***************************************************************************
Funcion que pasa a minuscula un caracter. */

char Pasar_Minuscula(char c){

	c = tolower(c) ;

	return c ;
}



int main() {

	setlocale(LC_CTYPE, "Spanish");

	//Declaraciones.

	// Numero de caracteres a considerar
	const int NUM_CARACTERES = 'z'-'a'+1;
	char las_letras [NUM_CARACTERES]; // Letras a procesar
	const char FIN = '*';

	char letras[NUM_CARACTERES]; //Contiene todas las letras.
	int veces_letras[NUM_CARACTERES] = {0}; // Contadores

	// Dimensiones del tablero de dibujo
	const int NUM_FILAS = 30; // Núm. de filas
	const int NUM_COLS = NUM_CARACTERES; // Núm. de columnas
	char histograma [NUM_FILAS][NUM_COLS];

	//Entrada de datos.

	cout << "***********************************************" << endl << endl;
	int total_utilizados = 0;

	//Lectura anticipada.

	cout << "Introduzca una serie de caracteres.";
	cin >> las_letras[total_utilizados];
	cout << endl;

	while (las_letras[total_utilizados] != FIN
		&& total_utilizados < NUM_CARACTERES){

		if (EsCaracterEspecialEspaniol(las_letras[total_utilizados])){
			las_letras[total_utilizados] = Pasar_Minuscula
			(TransformaCaracterEspecialEspaniol
			(las_letras[total_utilizados]));
		}

		else {
			las_letras[total_utilizados] =
			Pasar_Minuscula (las_letras[total_utilizados]);
		}
		total_utilizados++;

		cout << "Introduzca una serie de caracteres.";
		cin >> las_letras[total_utilizados];
		cout << endl;

	}

	//Calculos.

	//Rellenamos el vector con todas las letras del abecedario.
	for (int i = 0; i < NUM_CARACTERES; i++){
		letras[i] = 'a' + i;
	}

	//Recorremos el vector para contabilizar repeticiones de cada letra.
	for (int i = 0; i < NUM_CARACTERES; i++){

		for (int j = 0; j < total_utilizados; j++){

			if (letras[i] == las_letras[j]){
				veces_letras[i]++;
			}
		}
	}

	/* Algoritmo de calculo del maximo en el vector de repeticiones para
	truncar las filas del histograma respecto a ese valor. */

	int maximo, posicion_maximo;
	if (total_utilizados > 0){
		maximo = veces_letras[0];
		posicion_maximo = 0;

		for (int i= 0; i < total_utilizados; i++){
			if (veces_letras[i] > maximo){
				maximo = veces_letras[i];
				posicion_maximo = i;
			}
		}
	}
	else posicion_maximo = - 1;

	for (int i = 0; i < maximo; i++){

		for (int j = 0; j < NUM_COLS; j++){
			if(veces_letras[j]>i){
				histograma[i][j] = '*' ;
			}
			else{
				histograma[i][j] = '.' ;
			}
		}
	}

	//Salida de datos.

	cout << "  ";
	for (int i = 0; i < NUM_CARACTERES; i++){
		cout << letras[i] << " ";
	}
	cout << endl;
	cout << "  ---------------------------------------------------" << endl;
	for (int i = 0; i < maximo; i++){

		cout << i + 1 << " ";
		for (int j = 0; j < NUM_COLS; j++){
			cout << histograma[i][j] << " ";
		}

		cout << endl;
	}

	cout << endl << endl;
	cout << "***********************************************" << endl << endl;



	return 0;
}
