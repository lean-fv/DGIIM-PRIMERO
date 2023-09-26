/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 6
//
/*	
	Se ampl�a la clase SecuenciaCaracteres con el constructor:
	
    	SecuenciaCaracteres (string cad); 

    Constructor con argumento string. "Copia" el contenido del string en 
	la secuencia .
*/
/***************************************************************************/

#include <iostream>
#include <string>
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
};

/////////////////////////////////////////////////////////////////////////////

/***************************************************************************/

int main (void)
{
	SecuenciaCaracteres sec_hola ("�Hola, mundo!");
	cout << "|" << sec_hola.ToString() << "|" 
	     << " (" << sec_hola.TotalUtilizados() << ")" << endl;
	
	
	string cad = "adipiscing elit, sed diam nonummy nibhLorem ipsum dolor \
	sit amet, consectetuer  euismod tincidunt ut laoreet dolore magna \
	aliquam erat volutpat. Ut wisi enim ad minim veniam, \
	quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut \
	aliquip ex ea commodo consequat. Duis autem vel eum iriure dolor \
	in hendrerit in vulputate velit esse molestie consequat, \
	vel illum dolore eu feugiat nulla facilisis at vero eros et accumsan \
	et iusto odio dignissim qui blandit praesent luptatum zzril delenit \
	augue duis dolore te feugait nulla facilisi.";
	
	SecuenciaCaracteres sec_larga (cad);
	cout << "|" << sec_larga.ToString() << "| " 
	     << " (" << sec_larga.TotalUtilizados() << ")" << endl;
	
	
	SecuenciaCaracteres sec_asteriscos ('*', 10);
	cout << "|" << sec_asteriscos.ToString() << "|" 
	     << " (" << sec_asteriscos.TotalUtilizados() << ")" << endl;
	
	return 0;
}

/***************************************************************************/
