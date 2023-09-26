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

	Se presentan dos versiones de este método, 
	
	1) Ineficiente 
		Se realiza un borrado físico de cada mayúscula detectada empleando 
		el método "Elimina". Cada borrado supone el desplazamiento de los 
		elementos situados en posiciones superiores. 

	2) Eficiente 
		Realiza un borrado físico, aunque ahora se emplean dos variables que 
		actúan como apuntadores, para indicar la posición de lectura y la 
		posición de escritura, respectivamente.

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
	
	void EliminaMayusculasIneficiente (void)
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

	/*****************************************************************/
	// Eliminar los caracteres mayúscula del vector.
	// Realiza un borrado físico usando dos "apuntadores" para indicar 
	// las posiciones de lectura y escritura, respectivamente.
	// Versión eficiente

	void EliminaMayusculas (void)
	{
		int pos_escritura,  // posición donde escribir 
			pos_lectura;	// posición dónde leer 

		/* Algoritmo: 

			Recorrer todas las componentes que hay en el vector
				Si la componente actual NO es mayúscula
					ponedla dónde indique "pos_escritura"
				Avanzar "pos_lectura"

			Actualizar el número de componentes utilizadas
		*/

		pos_escritura = 0; // Primera posición tentativa de escritura
		
		// Se usa un ciclo for para "pos_lectura" porque se van a procesar 
		// TODAS las casillas del vector
		
		for (pos_lectura = 0; pos_lectura < total_utilizados; pos_lectura++) {

			if (islower(vector_privado[pos_lectura])) {

				vector_privado[pos_escritura] = vector_privado[pos_lectura];
				pos_escritura++;					

			}	// OJO: "pos_lectura" SIEMPRE avanza (for), mientras que
				// "pos_escritura" solo lo hace cuando encuentra minúsculas.
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

	// Añadir datos al vector

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
	// Eliminar las mayúsculas de "copia1" con el algoritmo ineficiente 

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
	// Eliminar las mayúsculas de "copia2" con el algoritmo eficiente 

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
