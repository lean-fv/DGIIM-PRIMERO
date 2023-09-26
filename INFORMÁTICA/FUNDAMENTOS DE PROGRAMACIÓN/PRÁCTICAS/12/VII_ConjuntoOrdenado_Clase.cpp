/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS VII

11. (Examen Septiembre 2012) Definid la clase ConjuntoOrdenado para almacenar
una secuencia ordenada de números enteros sin repetidos. Definid métodos para:

• Añadir un entero (de forma ordenada y sin almacenar repetidos).

• Calcular la unión con otro conjunto. En la unión se deben incluir los
elementos que estén en cualquiera de ellos.

• Calcular la intersección con otro conjunto. En la intersección se deben
incluir los elementos que sean comunes a ambos conjuntos.

ENTRADA: Los elementos de dos conjuntos.
SALIDA: Los conjuntos ordenados, sin repetidos, su union e interseccion.

*/

#include <iostream>
#include <string>

using namespace std;

/*---------------------------------------------------------------------------
							Clase ConjuntoOrdenado
---------------------------------------------------------------------------*/

class ConjuntoOrdenado{

private:

	static const int TAM = 100;
	int vector_privado[TAM];

	//Pre: 0 <= total_utilizados < TAM
	int total_utilizados;


public:

	//Constructor sin argumentos.

	ConjuntoOrdenado (void): total_utilizados(0)
	{}

	//Getters.

	const int GetTAM (void){

		return TAM;
	}


	int GetTotalUtilizados (void){

		return total_utilizados;
	}


	int Elemento (int indice) {

		return (vector_privado[indice]);
	}


	/***********************************************************************
	Metodo Aniade: aniade un elemento ("nuevo") al vector.

    La adicion se realiza si hay alguna casilla disponible.
    El nuevo elemento se coloca de forma ordenada y siempre que no este ya.
    Si no hay espacio, no se hace nada.

	PRE: total_utilizados < TAMANIO
	***********************************************************************/

	void Aniade (int nuevo){

		if (total_utilizados < TAM){

			if(total_utilizados == 0){

				//Se aniade el primero ya que no va a estar repetido.
				vector_privado[0] = nuevo;
				total_utilizados++;
			}
			else if (total_utilizados < TAM ){

				//Si se encuentra, no se aniade el entero.
				bool encontrado = false;

				//Una vez que se aniade, pasa a false.
				bool seguir = true;

				//Primero se comprueba si es mayor que el de la ultima posicion.
				if(nuevo > vector_privado[total_utilizados-1]){

					seguir = false;
					vector_privado[total_utilizados] = nuevo;
					total_utilizados++;
				}

				int i = 0;

				while(!encontrado && seguir && i < total_utilizados){

					if(nuevo == vector_privado[i]) encontrado = true;

					if(!encontrado && vector_privado[i] > nuevo){
						seguir = false;

						for(int j = total_utilizados; j > i; j--){
		            		vector_privado[j] = vector_privado[j-1];
						}

						vector_privado[i] = nuevo;
						total_utilizados++;
					}
					i++;
				}
	        }
	    }
	}


	/***********************************************************************
	Metodo Union: devuelve la union de dos conjuntos ordenados.

	PRE: total_utilizados + otro_conjunto.total_utilizados < TAM
	***********************************************************************/

    ConjuntoOrdenado Union(ConjuntoOrdenado otro_conjunto){

		ConjuntoOrdenado resultado(otro_conjunto);

    	for(int i = 0; i < total_utilizados; i++){
    		resultado.Aniade(vector_privado[i]);
    	}

    	return resultado;
    }

	/***********************************************************************
	Metodo Interseccion: devuelve la interseccion de dos conjuntos ordenados.

	PRE: total_utilizados + otro_conjunto.total_utilizados < TAM
	***********************************************************************/

    ConjuntoOrdenado Interseccion(ConjuntoOrdenado otro_conjunto){
    	ConjuntoOrdenado resultado;

    	for(int i = 0; i < total_utilizados; i++){
    		int j = 0;

    		//Cuando otro_conjunto.vector_privado[j]>vector_privado[i] o
			//cuando se aniada un elemento, cesa el bucle while.

			bool seguir=true;
    		while(j < otro_conjunto.total_utilizados && seguir){

				if(vector_privado[i] == otro_conjunto.vector_privado[j]){

					resultado.Aniade(vector_privado[i]);
					seguir = false;

				}else if(otro_conjunto.vector_privado[j] > vector_privado[i]){
					seguir = false;
				}

    			j++;
			}
    	}

    	return resultado;
    }


	/***********************************************************************
	Metodo ToString: compone un string con todos las cifras que
	almacenadas en la secuencia y lo devuelve.
	***********************************************************************/

    string ToString()
    {
        string cadena;

        for (int i=0; i < total_utilizados; i++)
            cadena = cadena + " " + to_string (vector_privado[i]);

        return (cadena);
    }


};


/*---------------------------------------------------------------------------
							Programa principal
---------------------------------------------------------------------------*/
int main() {

	//Declaraciones.

	int numero;
	const int FIN = - 1;
	ConjuntoOrdenado conjunto_1, conjunto_2;

	//Entrada de datos.

	cout << "***********************************************" << endl << endl;

	cout << "Introduzca un entero para el primer conjunto: ";
	cin >> numero;
	cout << endl;

	const int TAM = conjunto_1.GetTAM();

	while (numero != FIN && conjunto_1.GetTotalUtilizados() < TAM){

		conjunto_1.Aniade(numero);

		cout << "Introduzca un entero para el primer conjunto: ";
		cin >> numero;
		cout << endl;
	}



	cout << "Introduzca un entero para el segundo conjunto: ";
	cin >> numero;
	cout << endl;

	while (numero != FIN && conjunto_2.GetTotalUtilizados() < TAM){

		conjunto_2.Aniade(numero);

		cout << "Introduzca un entero para el segundo conjunto: ";
		cin >> numero;
		cout << endl;
	}

	//Calculos.

	ConjuntoOrdenado unioon (conjunto_1.Union(conjunto_2));
	ConjuntoOrdenado interseccion (conjunto_1.Interseccion(conjunto_2));


	//Salida de datos.

	cout << "Primer conjunto: " << endl;
	cout << conjunto_1.ToString() << endl << endl;

	cout << "Segundo conjunto: " << endl;
	cout << conjunto_2.ToString() << endl << endl;

	cout << "Union:" << endl;
	cout << unioon.ToString() << endl << endl;

	cout << "Interseccion: " << endl;
	cout << interseccion.ToString() << endl << endl;


	cout << "***********************************************" << endl << endl;



	return 0;
}
