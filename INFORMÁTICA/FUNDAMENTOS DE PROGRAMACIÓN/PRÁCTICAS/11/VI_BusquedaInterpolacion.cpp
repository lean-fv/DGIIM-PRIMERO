/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS VI

42. Implementad la Búsqueda por Interpolación en la clase SecuenciaEnteros. El
método busca un valor buscado entre las posiciones izda y dcha.

Este algoritmo recuerda a la búsqueda binaria porque

1) requiere que el vector en el que se va a realizar la búsqueda esté ordenado y

2) en cada consulta sin éxito se descarta una parte del vector para la siguiente
búsqueda.

La diferencia fundamental con la búsqueda binaria es la manera en que se calcula
el elemento del vector que sirve de referencia en cada consulta (que ocupa la
posición pos). Ahora el valor de referencia no es el que ocupa la posición
central del subvector en el que se efectúa la búsqueda (el delimitado únicamente
por izda y dcha), sino que depende también del contenido de esas casillas, de
manera que

1) pos será más cercana a dcha si buscado es más cercano a v[dcha]

2) pos será más cercana a izda si buscado es más cercano a v[izda]. En
definitiva, se cumple la relación:

pos - izda		 buscado - v[izda]
-----------	 =	-----------------
dcha - izda		v[dcha] - v[izda]



ENTRADA: cadenas de digitos.
SALIDA: un vector entero relleno con esas cadenas, con un digito en cada
posicion. La posicion que ocupa un numero a buscar en el vector una vez se ha
ordenado.

*/

#include <iostream>
#include <string>

using namespace std;


/*---------------------------------------------------------------------------
								Clase SecuenciaEnteros
---------------------------------------------------------------------------*/

class SecuenciaEnteros {

private:

    static const int TAMANIO = 50; // Num.casillas disponibles
    int vector_privado[TAMANIO];

    // PRE: 0 <= total_utilizados <= TAMANIO

    int total_utilizados; // Num.casillas ocupadas

public:


    /***********************************************************************
    Constructor sin argumentos
	***********************************************************************/

    SecuenciaEnteros (void) : total_utilizados (0)
    {}



	/***********************************************************************
    Constructor con argumento string: "copia" el contenido del string en
	la secuencia.
	***********************************************************************/

    SecuenciaEnteros (string cad)
    {
    	int num_cifras;

    	int long_cad = cad.length();

		if (long_cad > TAMANIO) num_cifras = TAMANIO;
		else num_cifras = long_cad;

		for (int pos=0; pos<num_cifras; pos++)

			vector_privado[pos] = (cad.at(pos)) - '0';

		total_utilizados = num_cifras;
	}



    /***********************************************************************
    Constructor con dos int. Rellena la secuencia con "n" cifras "c".
	***********************************************************************/

	SecuenciaEnteros (int c, int n)
	{
		int num_caracteres;

		if (n > TAMANIO) num_caracteres = TAMANIO;
		else num_caracteres = n;

		for (int pos=0; pos<num_caracteres; pos++)
			vector_privado[pos] = c;

		total_utilizados = num_caracteres;
	}



    /***********************************************************************
    Getter TotalUtilizados: devuelve el numero de casillas ocupadas
	***********************************************************************/

    int TotalUtilizados (void)
    {
        return (total_utilizados);
    }



    /***********************************************************************
    Getter Capacidad: devuelve el numero de casillas disponibles.
	***********************************************************************/

    int Capacidad (void)
    {
        return (TAMANIO);
    }



    /***********************************************************************
	Metodo Aniade:

	Aniade un elemento ("nuevo") al vector.
    PRE: total_utilizados < TAMANIO

	La adicion se realiza si hay alguna casilla disponible.
    El nuevo elemento se coloca al final del vector.
    Si no hay espacio, no se hace nada.
	***********************************************************************/

    void Aniade (int nuevo)
    {
        if (total_utilizados < TAMANIO){
            vector_privado[total_utilizados] = nuevo;
            total_utilizados++;
        }
    }



    /***********************************************************************
	Getter Elemento: devuelve el elemento de la casilla "indice"

    PRE: 0 <= indice < total_utilizados
	***********************************************************************/

    int Elemento (int indice)
    {
        return (vector_privado[indice]);
    }



    /***********************************************************************
	Metodo Elimina: elimina la cifra de la posicion dada por "indice".
	Realiza un borrado fisico (desplazamiento y sustitucion).

	PRE: 0 <= indice < total_utilizados
	***********************************************************************/

    void Elimina (int indice)
    {
        if ((indice >= 0) && (indice < total_utilizados)) {

            int tope = total_utilizados-1; // posic. del �ltimo

            for (int i = indice ; i < tope ; i++)
                vector_privado[i] = vector_privado[i+1];

            total_utilizados--;
        }
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



	/***********************************************************************
	Metodo OrdenaVector: ordena vector_privado mediante el algoritmo de la
	burbuja.
	***********************************************************************/

	void OrdenaVector (void){

		bool cambio = true;

		for (int izda = 0; izda < total_utilizados && cambio; izda++){

			cambio = false;

			for (int i = total_utilizados - 1; i > izda; i--){

				if (vector_privado[i] < vector_privado[i-1]){

					int intercambia = vector_privado[i];
					vector_privado[i] = vector_privado[i-1];
					vector_privado[i-1] = intercambia;
					cambio = true;
				}
			}
		}
	}


	/***********************************************************************
	Metodo BusquedaInterpolacion: busca un elemento determinado mediante el
	algoritmo de busqueda por interpolacion.

	PRE: el vector tiene que estar ordenado.
	***********************************************************************/

	int BusquedaInterpolacion (int buscado){

		bool encontrado = false;
		int pos_encontrado = 0;
		int izda = 0;
		int dcha = total_utilizados - 1;
		int referencia = izda + ((buscado - vector_privado[izda]) *
		(dcha - izda))/ (vector_privado[dcha] - vector_privado[izda]);


		while (izda <= dcha && !encontrado){

			if (vector_privado[referencia] == buscado) encontrado = true;

			else if (buscado < vector_privado[referencia])
				dcha = referencia - 1;

			else izda = referencia + 1;

			referencia = izda + ((buscado - vector_privado[izda]) *
			(dcha - izda))/ (vector_privado[dcha] - vector_privado[izda]);
		}

		if (encontrado) pos_encontrado = referencia;
		else pos_encontrado = - 1;

		return pos_encontrado;

	}


};


/*---------------------------------------------------------------------------
							Programa principal
---------------------------------------------------------------------------*/
int main() {

	cout << "***********************************************" << endl << endl;

	SecuenciaEnteros sec_inicio ("0123456789");
	cout << "|" << sec_inicio.ToString() << "|"
	     << " (" << sec_inicio.TotalUtilizados() << ")" << endl << endl << endl;


	string cad1 = "4234515243412148290583626182938456585950";

	SecuenciaEnteros sec_larga (cad1);
	cout << "|" << sec_larga.ToString() << "| "
	     << " (" << sec_larga.TotalUtilizados() << ")" << endl << endl << endl;


	SecuenciaEnteros sec_limitada (1, 10);
	cout << "|" << sec_limitada.ToString() << "|"
	     << " (" << sec_limitada.TotalUtilizados() << ")"<< endl<< endl << endl;

	string cad2 = "5793148620";

	SecuenciaEnteros cad_buscar (cad2);
	cad_buscar.OrdenaVector();

	cout << "Vector ordenado: " << cad_buscar.ToString() << endl;

		 int buscado = 3;

	cout << buscado << " esta en el "
		 << cad_buscar.BusquedaInterpolacion(buscado) + 1
		 << "º lugar del vector ordenado." << endl << endl;


	cout << "***********************************************" << endl << endl;


	return 0;
}
