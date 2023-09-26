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
	
		void EliminaMayusculas (void) 
		
	para eliminar todas las may�sculas del vector. 

	Se presentan dos versiones de este m�todo, 
	
	1) Ineficiente 
		Se realiza un borrado f�sico de cada may�scula detectada empleando 
		el m�todo "Elimina". Cada borrado supone el desplazamiento de los 
		elementos situados en posiciones superiores. 

	2) Eficiente 
		Realiza un borrado f�sico, aunque ahora se emplean dos variables que 
		act�an como apuntadores, para indicar la posici�n de lectura y la 
		posici�n de escritura, respectivamente.

*/
/***************************************************************************/

#include <iostream>
#include <cctype>
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
	// Eliminar todas las may�sculas del vector.
	// Realiza un borrado f�sico (con desplazamiento y sustituci�n).
	// Se emplea el m�todo "Elimina".
	
	void EliminaMayusculasIneficiente (void)
	{
 		/* Algoritmo: 

			Recorrer todas las componentes que hay en el vector
				Si la componente actual es may�scula
					Elimirla (llamar al m�todo Elimina())
				en otro caso
					Pasar a la siguiente componente

			Actualizar el n�mero de componentes utilizadas
			
			NOTA: Cada borrado supone el desplazamiento de los 
				  elementos situados en posiciones superiores.
		*/

		int pos = 0; // Primera posici�n

		while (pos < total_utilizados){
			if (isupper(vector_privado[pos]))
				Elimina(pos);	// Importante: "pos" se mantiene
			else
				pos++; // Siguiente posici�n
		}

		/*
			Hay que prestar atenci�n y no cometer el error mostrado a 
			continuaci�n, muy frecuente entre los principiantes: 
			El siguiente bucle es incorrecto porque cuando ha borrado 
			una may�scula, NO debe incrementar "pos"

			for (int pos=0; pos<total_utilizados; pos++)
				if (isupper(vector_privado[pos]))
					Elimina(pos);
		*/
	}

	/*****************************************************************/
	// Eliminar los caracteres may�scula del vector.
	// Realiza un borrado f�sico usando dos "apuntadores" para indicar 
	// las posiciones de lectura y escritura, respectivamente.
	// Versi�n eficiente

	void EliminaMayusculas (void)
	{
		int pos_escritura,  // posici�n donde escribir 
			pos_lectura;	// posici�n d�nde leer 

		/* Algoritmo: 

			Recorrer todas las componentes que hay en el vector
				Si la componente actual NO es may�scula
					ponedla d�nde indique "pos_escritura"
				Avanzar "pos_lectura"

			Actualizar el n�mero de componentes utilizadas
		*/

		pos_escritura = 0; // Primera posici�n tentativa de escritura
		
		// Se usa un ciclo for para "pos_lectura" porque se van a procesar 
		// TODAS las casillas del vector
		
		for (pos_lectura = 0; pos_lectura < total_utilizados; pos_lectura++) {

			if (islower(vector_privado[pos_lectura])) {

				vector_privado[pos_escritura] = vector_privado[pos_lectura];
				pos_escritura++;					

			}	// OJO: "pos_lectura" SIEMPRE avanza (for), mientras que
				// "pos_escritura" solo lo hace cuando encuentra min�sculas.
		}

		total_utilizados = pos_escritura;
	}
	/*****************************************************************/

};

/////////////////////////////////////////////////////////////////////////////

/***************************************************************************/

int main (void)
{
	SecuenciaCaracteres sec;

	// A�adir datos al vector

	sec.Aniade('h');
	sec.Aniade('E');
	sec.Aniade('L');
	sec.Aniade('o');
	sec.Aniade('l');
	sec.Aniade('L');
	sec.Aniade('O');
	sec.Aniade('a');


	// Mostrar el contenido de la secuencia
	
	cout  << "Secuencia original: " << sec.ToString() << endl;
	cout  << "Tiene " << sec.TotalUtilizados() << " elementos." << endl;
	cout << endl;


	// Copiar la secuencia original en "copia1" y "copia2"
	
	SecuenciaCaracteres copia1, copia2; 
	
	int tope = sec.TotalUtilizados();
	for (int i=0; i<tope; i++) {
		copia1.Aniade(sec.Elemento(i));
		copia2.Aniade(sec.Elemento(i));
	}

	/***********************************************************************/
	// Eliminar las may�sculas de "copia1" con el algoritmo ineficiente 

	cout << endl; 
	cout  << "Eliminando mayusculas de copia(1) - algoritmo ineficiente.";
	cout << endl; 

	copia1.EliminaMayusculasIneficiente();
	
	cout << endl;
	cout << "Secuencia modificada (eliminadas mayusculas): "
	     << copia1.ToString() << endl;
	cout  << "Tiene " << copia1.TotalUtilizados() << " elementos." << endl;
	cout << endl; 
	
	/************************************************************************/
	// Eliminar las may�sculas de "copia2" con el algoritmo eficiente 

	cout << endl; 
	cout  << "Eliminando mayusculas de copia(2) - algoritmo eficiente.";
	cout << endl; 

	copia2.EliminaMayusculas();
	
	cout << endl;
	cout << "Secuencia modificada (eliminadas mayusculas): "
	     << copia2.ToString() << endl;
	cout  << "Tiene " << copia2.TotalUtilizados() << " elementos." << endl;
	cout << endl;

	return (0);
}

/***************************************************************************/
