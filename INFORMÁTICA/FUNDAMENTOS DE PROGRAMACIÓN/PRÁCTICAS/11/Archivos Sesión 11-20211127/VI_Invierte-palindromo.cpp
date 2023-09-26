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

	Este método indica si el vector es un palíndromo, es decir, que se 
	lee igual de izquierda a derecha que de derecha a izquierda. 
	
	Se emplean los métodos:
	
	1)	void IntercambiaComponentes(int pos_1, int pos2) 

		Intercambia las componentes dadas por los índices "pos_1" y "pos_2". 
		Si alguno de los índices no es correcto el método no hace nada. 

	2)	void Invierte() 
	
		Invierte el vector, de forma que se intercambian el primero con el 
		último, el segundo con el penúltimo, .... La implementación está 
		basada en IntercambiaComponentes() 
*/
/***************************************************************************/

#include <iostream>
using namespace std;


/////////////////////////////////////////////////////////////////////////////

class SecuenciaCaracteres {

private:

    static const int TAMANIO = 50; // Núm.casillas disponibles
    char vector_privado[TAMANIO];

    // PRE: 0<=total_utilizados<TAMANIO

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
	// Intercambia los valores guardados en dos posiciones del vector.
	//
	// PRE: 0 <= pos_1 < total_utilizados 
	// PRE: 0 <= pos_2 < total_utilizados 
	//		El intercambio se realiza si las dos posiciones sonn válidas.
	// 		Si no es así, no se hace nada.

	void IntercambiaComponentes (int pos_1, int pos_2) 
	{
		if ((pos_1 >= 0) && (pos_1 < total_utilizados)  && 
			(pos_2 >= 0) && (pos_2 < total_utilizados)) {

			char tmp; 
			tmp = vector_privado[pos_1];
			vector_privado[pos_1] = vector_privado[pos_2];
			vector_privado[pos_2] = tmp;
		}
	}		

	/***********************************************************************/
	// Invierte un vector, intercambiando el primer carácter con el ultimo, 
	// el segundo con el penúltimo,... 
	
	void Invierte (void) 
	{
		
		int izda, dcha; // Para recorrer el vector por los dos extremos 

		izda = 0;	// Para recorrer de izqierda a derecha
		dcha = total_utilizados - 1; // Para recorrer de derecha a izquierda
		
		while (izda < dcha) {

			IntercambiaComponentes (izda, dcha);
			izda++; // posición siguiente
			dcha--;	// posición anterior
		} 	
	}

	/***********************************************************************/
	// Devuelve true si el vector es un palíndromo. 
	// Se trata de: 1) copiar la secuencia original en "local", 
	// 2) Invertir "local" y 3) Recorrer simultaneamente las dos secuencias.
	// Si son iguales, la secuencia original es un palíndromo. 
	
	bool EsPalindromo (void)
	{
	
		SecuenciaCaracteres local;
		
		// Copiar el objeto implícito en "local"
		for (int i=0; i<total_utilizados; i++)
			 local.vector_privado[i] = vector_privado[i];
			//local.Aniade(Elemento(i)); // Alternativa
			 
		local.total_utilizados = total_utilizados;
		/* 
			En el caso de haber realizado la copia con métodos: 
				local.Aniade(Elemento(i)); // Alternativa
			esta última instrucción sería innecesaria porque el 
			método "Aniade" actualiza "total_utilizados"
		*/
				
		// Invertir "local"
		local.Invierte();
				
		
		bool es_palindromo;
		int pos = 0; // Para recorrer los dos vectores simultaneamente
		
		es_palindromo = true; 
		
		while ((pos < total_utilizados) && es_palindromo) {

			if (vector_privado[pos] != local.vector_privado[pos])
				es_palindromo = false; // terminar
			else
				pos++;

		} // while ((pos < total_utilizados) && es_palindromo)

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
	
	return (0);
}
