/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS III

18. Escribir las siguientes funciones para leer números enteros:

int LeeEntero (string titulo)

Lee y devuelve un dato int. Si el valor leido no fuera un int (p.e. 94.5,
dos, 77 88, 0xA2, 55.0) la función volvería a pedirlo hasta que se proporcione
un valor correcto. La lectura se etiqueta con titulo.

Por ejemplo, si x es int, la ejecución de la instrucción
x = LeeEntero("Introduzca la coordenada x: "); muestra Introduzca la coordenada
x: _ y espera a la introducción de un valor int. Si el valor introducido no
fuera int vuelve a pedirlo.

int LeeEnteroEnRango (string titulo, int menor, int mayor)

Lee y devuelve un dato int en un rango dado. Si el valor leido no fuera int
ó éste fuera menor que menor o mayor que mayor la función volvería a
pedirlo hasta que se proporcionara un valor correcto. La lectura se etiqueta
con titulo.

int LeeEnteroMayorOIgual (string titulo, int referencia)

Lee y devuelve un dato int que debe ser mayor o igual que referencia.
Si el valor leido no fuera int ó éste fuera menor que referencia la función
volvería a pedirlo hasta que se proporcionara un valor correcto. La lectura se
etiqueta con titulo.

ENTRADA: un entero.
SALIDA: el entero.

*/

#include <iostream>
#include <string>

using namespace std;

int LeeEntero (string titulo) {

	string entrada;
	string numero;
	bool es_entero;

	do{
		cout << titulo;
		getline (cin, entrada);

		int posicion = 0;
		es_entero = true;

		/* Iremos recorriendo las posiciones de la cadena una a una (la primera
		posicion es la 0) comprobando que cada elemento de la misma es un
		digito o no (para ello usaremos isdigit) */

		while (posicion < entrada.length()){

			/* Si el primer elemento no es un digito ni un espacio, hemos de
		 	considerar que sea un signo mas o menos. */

			if (!isdigit(entrada.at(posicion)) &&
			!isspace(entrada.at(posicion))){

				if ((entrada.at(posicion) == '-'
				|| entrada.at(posicion) == '+') && (numero.length() == 0)
				&& (isdigit(entrada.at(posicion + 1)))){

					/* Se le añade el primer elemento a la cadena de salida
					'numero', en este caso un signo negativo o positivo.
					En la siguiente iteracion del codigo esta parte no se
					ejecutara porque la longitud de la cadena 'numero' ya no
					sera 0. */

					numero.push_back(entrada.at(posicion));
				}

				/* Si el primer elemento no es numero, signo ni espacio,
				hacemos que posicion tenga el valor de la longitud de la
				cadena de entrada para que se salga del bucle. Tambien
				hemos de hacer que es_entero sea falso para que se vuelva
				a pedir un entero (recordar que esto es un bucle anidado) */

				else{

					posicion = entrada.length();
					es_entero = false;
				}
			}

			/* Si el elemento que se esta evaluando es un digito, se añade al
			final de la cadena 'numero' */

			else{

				numero.push_back(entrada.at(posicion));
			}

			// Actualizamos la posicion a la del siguiente elemento a examinar

			posicion++;
		}

		/* Si la cadena fuese vacia, se debe pedir un entero otra vez, es decir,
		es_entero = false para que el bucle se vuelva a ejecutar */

		if (entrada.length() == 0){

			es_entero = false;
		}

	} while (!es_entero);

	return (stoi(numero));
}

/*****************************************************************************
Funcion LeeEntero: filtra un dato entero y comprueba si es correcto.
*****************************************************************************/
int LeeEnteroEnRango (string titulo, int menor, int mayor){

	int numero;

	do{
		numero = LeeEntero (titulo);
	}
	while ((numero < menor) || (numero > mayor));

	return (numero);
}

/*****************************************************************************
Funcion LeeEnteroEnRango: comprueba que el dato entero este en un rango.
*****************************************************************************/
 int LeeEnteroMayorOIgual (string titulo, int referencia){

 	int numero;

 	do{
 		numero = LeeEntero (titulo);
 	}
 	while (numero < referencia);

 	return (numero);
 }

 /*****************************************************************************
 Funcion LeeEnteroMayorOIgual: comprueba que el dato entero sea mayor o igual
 que una referencia.
 *****************************************************************************/

int main(){

	int x,y,z;

	cout << "***********************************************" << endl << endl;

	x = LeeEntero ("Introduzca un entero: ");
	y = LeeEnteroEnRango ("Introduzca un entero entre -10 y 10: ", -10, 10);
	z = LeeEnteroMayorOIgual ("Introduzca un entero mayor o igual que 5: ", 5);


	cout << "***********************************************" << endl << endl;

	return 0;
}
