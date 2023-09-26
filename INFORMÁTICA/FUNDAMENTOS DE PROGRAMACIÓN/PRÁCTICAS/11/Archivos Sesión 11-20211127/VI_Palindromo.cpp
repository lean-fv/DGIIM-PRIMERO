/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 6
//
/*	
	En este ejercico se amplía la clase SecuenciaCaracteres con el método:
	
		bool EsPalindromo (void)

	Este método indica si el vector es un palíndromo.
*/
/***************************************************************************/

#include <iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////

class SecuenciaCaracteres {

private:

    static const int TAMANIO = 50; // Núm.casillas disponibles
    char vector_privado[TAMANIO];

    // PRE: 0<=total_utilizados<=TAMANIO

    int total_utilizados; // Núm.casillas ocupadas

public:

    /***********************************************************************/
    // Constructor sin argumentos

    SecuenciaCaracteres (void) : total_utilizados (0)
    {}

    /***********************************************************************/
    // Devuelve el número de casillas ocupadas

    int TotalUtilizados (void)
    {
        return (total_utilizados);
    }

    /***********************************************************************/
    // Devuelve el número de casillas disponibles

    int Capacidad (void)
    {
        return (TAMANIO);
    }

    /***********************************************************************/
    // Añade un elemento ("nuevo") al vector.
    // PRE: total_utilizados < TAMANIO
    // 		La adición se realiza si hay alguna casilla disponible.
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
    // Eliminar el carácter de la posición dada por "indice".
    // Realiza un borrado físico (desplazamiento y sustitución).
    // PRE: 0 <= indice < total_utilizados

    void Elimina (int indice)
    {
        if ((indice >= 0) && (indice < total_utilizados)) {

            int tope = total_utilizados-1; // posic. del último

            for (int i = indice ; i < tope ; i++)
                vector_privado[i] = vector_privado[i+1];

            total_utilizados--;
        }
    }
 
    /***********************************************************************/
    // Compone un string con todos los caracteres que están
    // almacenados en la secuencia y lo devuelve.

    string ToString()
    {
        string cadena;

        for (int i=0; i<total_utilizados; i++)
            cadena = cadena + vector_privado[i];

        return (cadena);
    }
 
	/***********************************************************************/
	// Devuelve true si el vector es un palíndromo. 
	
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

				izda++; // posición siguiente
				dcha--;	// posición anterior
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

	// Leer y añadir caracteres a la secuencia

	cout << "Introducir una cadena (terminar con #): ";

	char c;

	c = cin.get();
	
	while (c != '#') {

		sec.Aniade (c);  // Añadir "c" a la secuencia "s"
		c = cin.get(); // Leer otro carácter
	}

	// Mostrar la secuencia

	cout << endl;
	cout << "Secuencia leida: " << sec.ToString() << endl;
	cout << endl;
	
	// Cálculo
	
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
