/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS VII

10. (Examen Septiembre 2014)

Sobre la clase SecuenciaCaracteres implemente el algoritmo Counting Sort para
ordenar sus valores.

SecuenciaCaracteres CountingSort()

El método no modificará las componentes del vector privado sino que debe
construir una secuencia nueva y devolverla. El algoritmo funciona de la
siguiente forma:

• Calcular los valores mínimo y máximo del vector. Por ejemplo, si el vector
contiene c b b a b c c a g c b g c el mínimo es 'a' y el máximo 'g'.

• Construir un vector local de frecuencias de todos los caracteres que hay entre
el mínimo y el máximo. Con el ejemplo anterior, el vector de frecuencias será
2 4 5 0 0 0 2
que corresponden a las frecuencias de las letras que hay entre 'a' y 'g'.

• Recorrer el vector de frecuencias almacenando cada carácter tantas veces como
indique su frecuencia (2 veces el 'a', cuatro veces el 'b', etc.)
a a b b b b c c c c c g g

Para resolver este problema, debe definir un segundo método auxiliar:
SecuenciaCaracteres CountingSortEntre(char min, char max)

Este método sólo ordena los valores de la secuencia que hay entre un carácter
izquierda y otro carácter derecha. Por ejemplo, si izquierda es 'b' y derecha es
'g' el resultado sería la siguiente secuencia:
b b b b c c c c c g g

Debe llamar a este método dentro de CountingSort().

ENTRADA: Una secuencia de caracteres.
SALIDA: La secuencia ordenada de menor a mayor a traves del algoritmo Counting
Sort.

*/

#include <iostream>
#include <string>

using namespace std;


/*---------------------------------------------------------------------------
							Clase SecuenciaCaracteres
---------------------------------------------------------------------------*/
class SecuenciaCaracteres {

private:

    static const int TAMANIO = 50; // Num.casillas disponibles
    char vector_privado[TAMANIO];

    // PRE: 0<=total_utilizados<=TAMANIO

    int total_utilizados;


	// Metodo que rellena el vector privado del objeto a partir de un
	// dato string

	void StringACaracteres (string cadena)
	{

		int longitud = (int) (cadena.length());
		for(int i = 0; i < longitud; i++){

			Aniade(cadena.at(i));
		}
	}

public:

    /***********************************************************************/
    // Constructor sin argumentos

    SecuenciaCaracteres (void) : total_utilizados (0)
    {}

	/***********************************************************************/
    // Constructor con argumento string.
    // "Copia" el contenido del string en la secuencia

    SecuenciaCaracteres (string cad)
    {
    	int num_caracteres;

    	int long_cad = cad.length();

		if (long_cad > TAMANIO) num_caracteres = TAMANIO;
		else num_caracteres = long_cad;

		for (int pos=0; pos<num_caracteres; pos++)
			vector_privado[pos] = cad.at(pos);

		total_utilizados = num_caracteres;
	}

    /***********************************************************************/
    // Constructor con char e int.
    // Rellena la secuencia con "n" caracteres "c".

	SecuenciaCaracteres (char c, int n)
	{
		int num_caracteres;

		if (n > TAMANIO) num_caracteres = TAMANIO;
		else num_caracteres = n;

		for (int pos=0; pos<num_caracteres; pos++)
			vector_privado[pos] = c;

		total_utilizados = num_caracteres;
	}

    /***********************************************************************/
    // Devuelve el numero de casillas ocupadas

    int TotalUtilizados (void)
    {
        return (total_utilizados);
    }

    /***********************************************************************/
    // Devuelve el numero de casillas disponibles

    int Capacidad (void)
    {
        return (TAMANIO);
    }

    /***********************************************************************/
    // Aniade un elemento ("nuevo") al vector.
    // PRE: total_utilizados < TAMANIO
    // 		La adicion se realiza si hay alguna casilla disponible.
    // 		El nuevo elemento se coloca al final del vector.
    // 		Si no hay espacio, no se hace nada.

    void Aniade (char nuevo)
    {
        if (total_utilizados < TAMANIO){
            vector_privado[total_utilizados] = nuevo;
            total_utilizados++;
        }
    }

    /***********************************************************************/
    // Devuelve el elemento de la casilla "indice"
    // PRE: 0 <= indice < total_utilizados

    char Elemento (int indice)
    {
        return (vector_privado[indice]);
    }

    /***********************************************************************/
    // Eliminar el car�cter de la posici�n dada por "indice".
    // Realiza un borrado f�sico (desplazamiento y sustituci�n).
    // PRE: 0 <= indice < total_utilizados

    void Elimina (int indice)
    {
        if ((indice >= 0) && (indice < total_utilizados)) {

            int tope = total_utilizados-1; // posic. del �ltimo

            for (int i = indice ; i < tope ; i++)
                vector_privado[i] = vector_privado[i+1];

            total_utilizados--;
        }
    }

    /***********************************************************************/
    // Compone un string con todos los caracteres que est�n
    // almacenados en la secuencia y lo devuelve.

    string ToString()
    {
        string cadena;

        for (int i=0; i<total_utilizados; i++)
            cadena = cadena + vector_privado[i];

        return (cadena);
    }

	/***********************************************************************/
	// Metodo que borra de la secuencia de caracteres un caracter dado por
	// el usuario.

	void EliminaOcurrencias (char a_borrar)
	{
		int pos_lectura = 0;
		int pos_escritura = 0;

		while (pos_lectura < total_utilizados){

			//La posicion de escritura solo avanza cuando no se detecta el
			//el caracter a borrar.
			if (vector_privado[pos_lectura] != a_borrar){

				vector_privado[pos_escritura] = vector_privado[pos_lectura];
				pos_escritura++;
			}

			pos_lectura++; //Pos_lectura avanza siempre.
		}

		total_utilizados = pos_escritura;
	}

	/*********************************************************************/
	// Metodo que elimina todos los espacios de una secuencia de espacios

	void EliminaExcesoBlancos (void)
	{
		int pos_lectura = 0;
		int pos_escritura = 0;
		int contador_espacios = 0;


		while (pos_lectura < total_utilizados){

			// Si el contenido de la casilla pos_lect no es un espacio, aumenta
			//posicion escritura.

			if(vector_privado[pos_lectura] != ' '){

				vector_privado[pos_escritura] = vector_privado[pos_lectura];
				pos_escritura++;
				contador_espacios = 0; //El contador debe reiniciarse.
			}

			else{

				/* Si se lee un espacio y el contador esta a 0, copiamos
				dicho espacio en la pos_escritura y aumentamos pos_escritura
				y el contador. */

				if (contador_espacios == 0){

					vector_privado[pos_escritura] = vector_privado[pos_lectura];
					pos_escritura++;
					contador_espacios++;
				}

				// Si no es el primer espacio leido, solo aumentamos el
				//contador de espacios.

				else{

					contador_espacios++;
				}
			}

			//Posicion lectura siempre aumenta.

			pos_lectura++;
		}


		total_utilizados = pos_escritura;
	}


	/*************************************************************************
	Metodo CountingSortEntre: crea un nuevo objeto SecuenciaCaracteres a partir
	de un maximo y un minimo, cuyo vector de caracteres se encuentra ordenado
	respecto al introducido en primer lugar.
	*************************************************************************/

	SecuenciaCaracteres CountingSortEntre(char min, char max){

		char vector_letras[TAMANIO];

		int utilizados_letras = 0;

		//Rellenamos un vector con las letras entre el maximo y minimo incluidos

		while ((utilizados_letras+min) <= max && utilizados_letras < TAMANIO){

			vector_letras[utilizados_letras] = utilizados_letras + min;
			utilizados_letras++;

		}

		int vector_frecuencias[TAMANIO] = {0};
		int utilizados_frecuencias = 0;

		for (int i = 0; i < utilizados_letras; i++){

			for (int j = 0; j < total_utilizados; j++){

				if (vector_letras[i] == vector_privado[j]){

					vector_frecuencias[utilizados_frecuencias]++;
				}
			}
			utilizados_frecuencias++;
		}

		SecuenciaCaracteres nueva_cadena;

		/*Rellenamos el vector de la nueva secuencia de manera ordenada a traves
		del vector de letras y el numero de veces que esta la letra presente en
		la cadena introducida en primer lugar. */

		for (int i = 0; i < utilizados_letras; i++){

			if (vector_frecuencias[i] != 0){

				for (int j = 0; j < vector_frecuencias[i]; j++){

					nueva_cadena.Aniade(vector_letras[i]);
				}
			}
		}

		return nueva_cadena;
	}

	/*************************************************************************
	Metodo CountingSort: calcula el caracter maximo y el minimo de una secuencia
	de caracteres y llama al metodo CountingSortEntre para construir un nuevo
	objeto SecuenciaCaracteres.
	*************************************************************************/
	SecuenciaCaracteres CountingSort(void){

		char minimo, maximo;

		//Algoritmo de obtencion del minimo y el maximo.

		if (total_utilizados > 0){

			minimo = vector_privado[0];
			maximo = vector_privado[0];

			for (int i = 1; i < total_utilizados; i++){

				if (vector_privado[i] < minimo) minimo = vector_privado[i];
				if (vector_privado[i] > maximo) maximo = vector_privado[i];

			}
		}

		else {

			minimo = - 1;
			maximo = - 1;
		}

		return SecuenciaCaracteres (CountingSortEntre(minimo, maximo));

	}


};


/*---------------------------------------------------------------------------
							Programa principal
---------------------------------------------------------------------------*/
int main() {

	//Declaraciones.

	string cadena;


	//Entrada de datos.

	cout << "***********************************************" << endl << endl;

	cout << "Introduzca una secuencia de caracteres:";
	getline (cin, cadena);
	cout << endl;

	//Calculos.
	SecuenciaCaracteres secuencia (cadena);
	SecuenciaCaracteres secuencia_ordenada (secuencia.CountingSort());

	//Salida de datos.

	cout << "La cadena ordenada es: " << endl << endl;
	cout << secuencia_ordenada.ToString() << endl;

	cout << "***********************************************" << endl << endl;



	return 0;
}
