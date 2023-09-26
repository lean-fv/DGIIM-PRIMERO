/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 6
//
/*	
	En este ejercico se ampl�a la clase SecuenciaCaracteres con el m�todo:
	
		bool EsPalindromo (void)

	Este m�todo indica si el vector es un pal�ndromo.
*/
/***************************************************************************/

#include <iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////

class SecuenciaCaracteres {

private:

    static const int TAMANIO = 50; // N�m.casillas disponibles
    char vector_privado[TAMANIO];

    // PRE: 0<=total_utilizados<=TAMANIO

    int total_utilizados; // N�m.casillas ocupadas

public:

    /***********************************************************************/
    // Constructor sin argumentos

    SecuenciaCaracteres (void) : total_utilizados (0)
    {}

    /***********************************************************************/
    // Devuelve el n�mero de casillas ocupadas

    int TotalUtilizados (void)
    {
        return (total_utilizados);
    }

    /***********************************************************************/
    // Devuelve el n�mero de casillas disponibles

    int Capacidad (void)
    {
        return (TAMANIO);
    }

    /***********************************************************************/
    // A�ade un elemento ("nuevo") al vector.
    // PRE: total_utilizados < TAMANIO
    // 		La adici�n se realiza si hay alguna casilla disponible.
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
	// Devuelve true si el vector es un pal�ndromo. 
	
	bool EsPalindromo (void)
	{
		bool es_palindromo;
		int izda, dcha; // Para recorrer el vector por los dos extremos 

		es_palindromo = true; 
		
		izda = 0;	// Para recorrer de izqierda a derecha
		dcha = total_utilizados - 1; // Para recorrer de derecha a izquierda

		while ((izda < dcha) && es_palindromo) {

			if (vector_privado[izda] != vector_privado[dcha])

				es_palindromo = false; // terminar

			else {	// seguir buscando

				izda++; // posici�n siguiente
				dcha--;	// posici�n anterior
			}

		} // while ((izda < dcha) && es_palindromo)

		return (es_palindromo);
	}

	/***********************************************************************/
};

/////////////////////////////////////////////////////////////////////////////

/***************************************************************************/

int main (void)
{
	SecuenciaCaracteres sec;

	// Leer y a�adir caracteres a la secuencia

	cout << "Introducir una cadena (terminar con #): ";

	char c;

	c = cin.get();
	
	while (c != '#') {

		sec.Aniade (c);  // A�adir "c" a la secuencia "s"
		c = cin.get(); // Leer otro car�cter
	}

	// Mostrar la secuencia

	cout << endl;
	cout << "Secuencia leida: " << sec.ToString() << endl;
	cout << endl;
	
	// C�lculo
	
	bool es_palindromo = sec.EsPalindromo ();

	// Mostrar Resultado
	
	if (es_palindromo)
		cout << "Es un palindromo";
	else
		cout <<"No es un palindromo";
	cout << endl;
	
	return 0;
}

/***************************************************************************/
