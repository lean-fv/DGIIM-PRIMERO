/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS III

19. Escribir la siguiente función para leer números reales:

double LeeReal (string titulo)

Lee y devuelve un dato double. Si el valor leido no fuera un double (p.e.
dos, 77 88, 0xA2, .) la función volvería a pedirlo hasta que se proporcione
un valor correcto. No se admiten valores en formato científico (p.e. 1e5). Se
admiten como válidos valores como .55 ó 22. ó 78. La lectura se etiqueta
con titulo. El funcionamiento es similar al de la función LeeEntero del
ejercicio 18.

ENTRADA: un real.
SALIDA: el real.

*/

#include <iostream>
#include <string>

using namespace std;

double LeeReal (string titulo) {

	string entrada;
	string numero;
	bool es_real;
	int contador_punto = 0;

	do{
		cout << titulo;
		getline (cin, entrada);

		int posicion = 0;
		es_real = true;

		/* Iremos recorriendo las posiciones de la cadena una a una (la primera
		posicion es la 0) comprobando que cada elemento de la misma es un
		digito o no (para ello usaremos isdigit) */

		while (posicion < entrada.length()){

			/* Si el primer elemento no es un digito ni un espacio, hemos de
		 	considerar que sea un signo mas o menos o un punto decimal. */

			//Contador de puntos decimales.

			if (!isdigit(entrada.at(posicion)) &&
			!isspace(entrada.at(posicion))){

				if ((entrada.at(posicion) == '-'
				|| entrada.at(posicion) == '+' || entrada.at(posicion) == '.')
				&& (numero.length() == 0)
				&& (isdigit(entrada.at(posicion + 1)))){

					/* Se le añade el primer elemento a la cadena de salida
					'numero', en este caso un signo negativo o positivo.
					En la siguiente iteracion del codigo esta parte no se
					ejecutara porque la longitud de la cadena 'numero' ya no
					sera 0. */

					numero.push_back(entrada.at(posicion));

				}

				if (entrada.at(posicion) == '.')
				contador_punto++;


				/* Si el primer elemento no es numero, signo, punto ni espacio,
				hacemos que posicion tenga el valor de la longitud de la
				cadena de entrada para que se salga del bucle. Tambien
				hemos de hacer que es_entero sea falso para que se vuelva
				a pedir un entero (recordar que esto es un bucle anidado) */

				else{

					posicion = entrada.length();
					es_real = false;
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

		if (entrada.length() == 0)
			es_real = false;

		if (contador_punto > 1)
		es_real = false;

	} while (!es_real);

	return (stod(numero));
}

int main(){

	int x;

	cout << "***********************************************" << endl << endl;

	x = LeeReal ("Introduzca un real: ");

	cout << "***********************************************" << endl << endl;

	return 0;
}
