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
	
		void EliminaMayusculas (void) 
		
	para eliminar todas las mayúsculas del vector. 

	Se presentan una versión ineficiente:
	 
		Se realiza un borrado físico de cada mayúscula detectada empleando 
		el método "Elimina". Cada borrado supone el desplazamiento de los 
		elementos situados en posiciones superiores. 
*/
/***************************************************************************/

#include <iostream>
#include <cctype>
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
	// Eliminar todas las mayúsculas del vector.
	// Realiza un borrado físico (con desplazamiento y sustitución).
	// Se emplea el método "Elimina".
	
	void EliminaMayusculas (void)
	{
 		/* Algoritmo: 

			Recorrer todas las componentes que hay en el vector
				Si la componente actual es mayúscula
					Elimirla (llamar al método Elimina())
				en otro caso
					Pasar a la siguiente componente

			Actualizar el número de componentes utilizadas
			
			NOTA: Cada borrado supone el desplazamiento de los 
				  elementos situados en posiciones superiores.
		*/

		int pos = 0; // Primera posición

		while (pos < total_utilizados){
			if (isupper(vector_privado[pos]))
				Elimina(pos);	// Importante: "pos" se mantiene
			else
				pos++; // Siguiente posición
		}

		/*
			Hay que prestar atención y no cometer el error mostrado a 
			continuación, muy frecuente entre los principiantes: 
			El siguiente bucle es incorrecto porque cuando ha borrado 
			una mayúscula, NO debe incrementar "pos"

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
	// Eliminar las mayúsculas de "copia1" con el algoritmo ineficiente 
 
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
