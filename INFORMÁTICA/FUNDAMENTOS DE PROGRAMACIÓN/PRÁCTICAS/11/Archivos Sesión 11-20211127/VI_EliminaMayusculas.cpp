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

	Se presentan una versi�n ineficiente:
	 
		Se realiza un borrado f�sico de cada may�scula detectada empleando 
		el m�todo "Elimina". Cada borrado supone el desplazamiento de los 
		elementos situados en posiciones superiores. 
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
	
	void EliminaMayusculas (void)
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

};

/////////////////////////////////////////////////////////////////////////////

/***************************************************************************/

int main (void)
{
	SecuenciaCaracteres sec ("hELolLOa");

	// Mostrar el contenido de la secuencia
	
	cout << endl;
	cout  << "Secuencia original: " << sec.ToString() << endl;
	cout  << "Tiene " << sec.TotalUtilizados() << " elementos." << endl;
	cout << endl;


	// Copiar la secuencia original en "copia"
	
	SecuenciaCaracteres copia; 
	
	int tope = sec.TotalUtilizados();
	for (int i=0; i<tope; i++) {
		copia.Aniade(sec.Elemento(i));
	}

	/***********************************************************************/
	// Eliminar las may�sculas de "copia1" con el algoritmo ineficiente 
 
	cout  << "Eliminando mayusculas de copia - algoritmo ineficiente." << endl;
	cout << endl; 

	copia.EliminaMayusculas();
	
	cout << "Secuencia modificada (eliminadas mayusculas): "
	     << copia.ToString() << endl;
	cout  << "Tiene " << copia.TotalUtilizados() << " elementos." << endl;
	cout << endl; 

	cout  << "Secuencia original: " << sec.ToString() << endl;
	cout  << "Tiene " << sec.TotalUtilizados() << " elementos." << endl;
	cout << endl;
	
	return 0;
}

/***************************************************************************/
