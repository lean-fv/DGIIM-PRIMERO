/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS V

3. Declarar dos array de datos int con TOPE casillas. Rellenar cada array de la
siguiente manera: pedir que se introduzca por teclado una serie indeterminada
de números enteros (termina cuando se introduce la palabra FIN).

En primer lugar, el programa mostrará el valor medio de los valores
introducidos. Después, indicará si los dos array contienen los mismos valores y
en el mismo orden.

ENTRADA: valores en un array.
SALIDA: media de los valores, si los arrays contienen mismos valores y en el
mismo orden.

*/

#include <iostream>
#include <string>
#include <cctype>



using namespace std;

const int TOPE = 100;
const string FIN = "FIN";


int main() {

	//Declaraciones.

	string secuencia1, secuencia2;
	int array1[TOPE], array2[TOPE];
	int i = 0, total_utilizados1 = 0, total_utilizados2 = 0;


	//Entrada de datos.

	cout << "***********************************************" << endl << endl;


	do{ //1º secuencia.

		cout << "Introduzca un dato para la primera secuencia. ";
		getline (cin, secuencia1);
		cout << endl;

		if (secuencia1 != FIN) {
			array1[i] =  stoi (secuencia1);
			total_utilizados1++; //Contador de posiciones utilizadas.
			i++; //Variable de control para actualizar las posiciones del array.
		}

	}while (secuencia1 != FIN);


	i = 0;

	do{ //2º secuencia.

		cout << "Introduzca un dato para la segunda secuencia. ";
		getline (cin, secuencia2);
		cout << endl;

		if (secuencia2 != FIN) {
			array2[i] = stoi (secuencia2);
			total_utilizados2++;
			i++;
		}

	}while (secuencia2 != FIN);

	cout << endl;
	i = 0;

	//Calculos.

	double acumulados1 = 0, acumulados2 = 0;

	for (int i = 0; i < total_utilizados1; i++){ //Secuencia 1.

		acumulados1 = acumulados1 + array1[i];
	}

	for (int i = 0; i < total_utilizados2; i++){ //Secuencia 2.

		acumulados2 = acumulados2 + array2[i];
	}

	//Calculo de la media a partir de la suma de todos los valores en el array.

	double media1 = acumulados1 / total_utilizados1;
	double media2 = acumulados2 / total_utilizados2;


	bool mismo_ordenados = true;

	//Casos de orden y
	if (total_utilizados1 != total_utilizados2){
		mismo_ordenados = false;
	}

	i = 0;

	while (i < total_utilizados1 && mismo_ordenados){

		if (array1[i] != array2[i]){

			mismo_ordenados = false;
		}
		i++;
	}


	//Salida de datos.

	if (total_utilizados1 != 0 || total_utilizados2 != 0){

		cout << "La media de la primera serie de elementos es " << media1;
		cout << endl;
		cout << "La media de la segunda serie de elementos es " << media2;
		cout << endl;

		if (mismo_ordenados)
			cout << "Tienen los mismos elementos y en el mismo orden.";

		else
			cout << "No tienen los mismos elementos ni en el mismo orden.";
	}

	else cout << "No ha introducido ningun numero.";

	cout << endl;
	cout << "***********************************************" << endl << endl;



	return 0;
}
