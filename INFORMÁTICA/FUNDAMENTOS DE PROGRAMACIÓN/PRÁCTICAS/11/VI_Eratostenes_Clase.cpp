/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS VI

22. (Examen Septiembre 2012) La criba de Eratóstenes permite hallar todos los
números primos menores que un número natural dado n. Hemos trabajado sobre este
problema en el ejercicio 14 de la Relación de Ejercicios V.

En esta ocasión se trata de definir una clase llamada Eratostenes. Un objeto de
la clase podrá almacenar los números primos calculados en un vector de enteros:

// Todos los primos calculados serán menores que TAMANIO.
static const int TAMANIO = 500;
int vector_privado[TAMANIO];
//PRE: 0 <= total_utilizados <= TAMANIO
int total_utilizados; // Número de casillas ocupadas

lo que significa que en un objeto Eratostenes se podrá guardar un máximo de
TAMANIO números primos.

El usuario de la clase quiere generar primos menores o iguales que un valor
dado, por ejemplo:

Eratostenes primos;
primos.CalculaHasta(100);

El método void CalculaHasta(int n) calcula y guarda en el array interno los
primos menores o iguales que n. Este es el método en el que se implementa la
criba.

Cuando se ejecute el método, se almacenarán en un vector interno del objeto
todos los primos menores que n.

Se dará cuenta que el valor proporcionado puede ser demasiado ambicioso. Por
ejemplo, si n vale 5000 no habrá espacio en el vector interno (500 casillas)
para todos los primos menores que 5000. Debería guardar en el objeto Eratostenes
dos valores:

• n el valor que se suministró para calcular los primos guardados.
• n_real guarda el menor valor entero mayor o igual todos los primos del vector.

Si se pudieron guardar todos los primos solicitados, n y n_real coincidirán.
La clase ofrecerá, además, como mínimo, estos métodos:

• int GetReferencia() devuelve el valor que se suministró para calcular los
primos (el valor del campo n).

• int GetReferenciaReal() devuelve el menor valor entero mayor o igual todos
los primos del vector (el valor del campo n_real).

• int TotalCalculados() devuelve cuántos primos hay almacenados.

• int Elemento(int k) devuelve el k-ésimo primo almacenado.

Un programa que use esta clase podría ser, esquemáticamente:

Eratostenes primos;
primos.CalculaHasta(100);
cout << "Primos <= " << primos.GetReferencia() << endl;
cout << "Obtenidos <= " << primos.GetReferenciaReal() << endl;
cout << "El mayor es:
<< primos.Elemento(primos.TotalCalculados()-1) << endl;
cout << "Primos: " << endl;
for (int i=0; i<primos.TotalCalculados(); i++)
cout << setw(5) << primos.Elemento(i);

ENTRADA: Un numero
SALIDA: los primos anteriores a el.

*/

#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

class Eratostenes
{
	private:

		static const int TAMANIO = 500;
		int vector_privado[TAMANIO];

		//PRE: 0 <= total_utilizados <= TAMANIO
		int total_utilizados; // N�mero de casillas ocupadas

		int n;
		int n_real;

	public:

		//Constructor sin argumentos.
		Eratostenes (void): total_utilizados (0)
		{}


		// Metodo que calcula los primos menores que n para almacenarlos en el
		// vector dato miembro de la clase
		//PRE: 1 <= n_real <= TAMANIO

		void CalculaHasta (int numero)
		{
			bool es_primo[TAMANIO*TAMANIO];

			n = numero;
			if (n >= TAMANIO) n_real = TAMANIO;
			else n_real = n;

			for (int i=0; i < n_real; i++)
			es_primo[i] = true;

			// Criba

			for (int num=2; num*num <= n_real; num++){

				if (es_primo[num]) {

					for (int k=2; k*num <= n_real; k++) {
						es_primo[k*num] = false;
					}
				}
			}


			for (int i = 2; i <= n_real; i++) {

					if (es_primo[i]) {
						vector_privado[total_utilizados] = i;
						total_utilizados++;
					}
			}
		}


		//Devuelve el numero introducido para calcular sus primos.
		int GetReferencia (void)
		{
			return (n);
		}


		// Devuelve el primo de mayor valor almacenado tras la criba

		int GetReferenciaReal (void)
		{
			return (n_real);
		}


		// Devuelve cuantos primos hay almacenados actualmente

		int TotalCalculados (void)
		{
			return (total_utilizados);
		}

		// Devuelve el k-esimo primo

		int Elemento (int k)
		{
			return (vector_privado[k]);
		}


};



int main() {

	// Declaraciones

	int numero;

	// Entrada de datos

	cout << "***********************************************" << endl << endl;

	cout << "Introduzca un numero: ";
	cin >> numero;
	cout << endl << endl;


	Eratostenes primos;

	// Calculos

	primos.CalculaHasta(numero);
	int tope = primos.TotalCalculados();

	// Salida de datos

	cout << "Primos <= " << primos.GetReferencia() << endl;

	cout << "Obtenidos <= " << primos.GetReferenciaReal() << endl;

	cout << "El mayor es: "
		 << primos.Elemento(primos.TotalCalculados()-1) << endl;

	cout << "Primos: " << endl << endl;
	for (int i=0; i<primos.TotalCalculados(); i++)

		cout << setw(5) << primos.Elemento(i);


	cout << endl;

	cout << "***********************************************" << endl << endl;

	return 0;
}
