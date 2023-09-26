/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS VI

36. Añadir un método EliminaExcesoBlancos() para eliminar el exceso de
caracteres en blanco, es decir, que sustituya todas las secuencias de espacios
en blanco por un sólo espacio. Por ejemplo, si el vector original es
{' ','a','h',' ',' ',' ','c'}, que contiene una secuencia de tres espacios
consecutivos, el vector resultante debe ser {' ','a','h',' ','c'}.

ENTRADA: Una secuencia de caracteres.
SALIDA: La secuencia con el exceso de espacios eliminados en caso de que haya
mas de uno entre palabra y palabra.

*/

#include <iostream>
#include <string>

using namespace std;


/*---------------------------------------------------------------------------
							Clase SecuenciaCaracteres
---------------------------------------------------------------------------*/
class SecuenciaCaracteres {

private:

    static const int TAMANIO = 50; // N�m.casillas disponibles
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


};

/*---------------------------------------------------------------------------
								Programa principal
---------------------------------------------------------------------------*/

int main() {

	// Declaraciones

	string cadena;

	// Entrada de datos

	cout << "***********************************************" << endl << endl;


	//cout << "Introduzca una secuencia de caracteres: ";
	getline(cin, cadena);

	cout << endl << endl;

	SecuenciaCaracteres secuencia(cadena);

	cout << "La secuencia introducida es: " << secuencia.ToString();
	cout << endl << endl;


	// Operaciones

	secuencia.EliminaExcesoBlancos();

	// Salida de datos


	cout << "La secuencia final es: " << secuencia.ToString() << endl;

	cout << "***********************************************" << endl << endl;


	return 0;
}
