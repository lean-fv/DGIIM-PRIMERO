/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 7
//
/*	
	TABLA DENTADA -	SECUENCIA DE SECUENCIAS

	Este programa presenta la clase "TablaDentadaCaracteres".
	Se emplea como dato miembro privado una secuencia de secuencias 
	de caracteres.
	
		static const int TAMANIO = 100; // Número de casillas disponibles
		SecuenciaCaracteres vector_privado[TAMANIO];
		
		//PRE: 0 <= total_utilizados <= TAMANIO
		int total_utilizados;	// Número de casillas ocupadas
	
	Además de los métodos básicos de gestión de la clase, se añade el método:
	
		void Inserta (int num_fila, SecuenciaCaracteres fila_nueva)

	para que inserte una fila completa (dada por una secuencia de caracteres
	-fila_nueva- en la fila "num_fila". Tras la inserción, la secuencia
	insertada estará en la fila "num_fila"
*/
/***************************************************************************/


#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


///////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class SecuenciaCaracteres
{

private:

	static const int TAMANIO = 50; // Número de casillas disponibles
	char vector_privado[TAMANIO];

	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;	// Número de casillas ocupadas

public:

	/***********************************************************************/
	// Constructor sin argumentos

	SecuenciaCaracteres (void)
	{
		total_utilizados = 0;
	}

	/***********************************************************************/
	// Constructor con argumento string
	// Recibe: la_palabra, dato string que se usa para iniciar el objeto.
	// Si "la_palabra" tiene más caracteres que caben en el objeto, no se
	// copia nada y se crea un objeto vacío.
	//
	// PRE: "la_palabra" está formada por una única palabra

	SecuenciaCaracteres (string la_palabra)
	{
		total_utilizados = 0;

		int longitud_la_palabra = la_palabra.length();

		if (longitud_la_palabra <= TAMANIO) {

			for (int i=0; i<longitud_la_palabra; i++)
				vector_privado[i]= la_palabra[i];

			total_utilizados = longitud_la_palabra;
		}
	}

	/***********************************************************************/
	// Métodos de lectura (Get) de los datos individuales

	// Devuelve el número de casillas ocupadas
	int TotalUtilizados (void)
	{
		return (total_utilizados);
	}

	// Devuelve el número de casillas disponibles
	int Capacidad (void)
	{
		return (TAMANIO);
	}

	/***********************************************************************/
	// Añade un elemento al vector.
	// Recibe: nuevo, el elemento que se va a añadir.
	//
	// PRE: total_utilizados < TAMANIO
	// 		La adición se realiza si hay espacio para el nuevo elemento.
	// 		El nuevo elemento se coloca al final del vector.
	// 		Si no hay espacio, no se hace nada.

	void Aniade (char nuevo)
	{
		if (total_utilizados < TAMANIO) {
			vector_privado[total_utilizados] = nuevo;
			total_utilizados++;
		}
	}

	/***********************************************************************/
	// Devuelve el elemento de la casilla "indice"
	//
	// PRE: 0 <= indice < total_utilizados

	char Elemento (int indice)
	{
		return vector_privado[indice];
	}

	/***********************************************************************/
	// "Limpia" completamente una secuencia

	void EliminaTodos (void)
	{
			total_utilizados = 0;
	}

	/***********************************************************************/
	// "Limpia" completamente una secuencia

	string ToString (void)
	{
		string cadena;

		cadena = "|";
		for (int i=0; i<total_utilizados; i++)
			cadena = cadena + vector_privado[i] + "|";

		return (cadena);
	}

	/***********************************************************************/

};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class TablaDentadaCaracteres {
	
private:
	

private:

	static const int TAMANIO = 100; // Número de casillas disponibles
	SecuenciaCaracteres vector_privado[TAMANIO];
	
	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;	// Número de casillas ocupadas
	
public:
	
	/***********************************************************************/
	// Constructor sin argumentos

	TablaDentadaCaracteres (void) 	
	{
		total_utilizados = 0;
	}

	/***********************************************************************/
	// Constructor con un argumento "SecuenciaReales"

	TablaDentadaCaracteres (SecuenciaCaracteres la_secuencia) 	
	{
		vector_privado[0] = la_secuencia;
		total_utilizados = 1;
	}

	/***********************************************************************/
	// Devuelve el número de casillas disponibles
	
	int CapacidadFilas (void)
	{
		return (TAMANIO);
	}
	
	/***********************************************************************/
	// Devuelve el número de casillas disponibles
	
	int CapacidadColumnas (void)
	{
		return (SecuenciaCaracteres().Capacidad());
	}
	
	/*****************************************************************/
	// Devuelve cuántas filas hay en la tabla.

	int FilasUtilizadas (void)
	{
		return (total_utilizados);
	}
				
	/*****************************************************************/
	// Método de lectura: número real de columnas usadas en la fila "fila"
	// PRE: 0 <= fila < filas_utilizadas
	
	int ColumnasUtilizadas (int fila)
	{
		return (vector_privado[fila].TotalUtilizados());
	}
		
	/***********************************************************************/
	// Devuelve una fila completa, como un objeto de la clase 
	// "SecuenciaReales"
	//
	// PRE: 0 <= indice_fila < filas_utilizadas

	SecuenciaCaracteres Fila (int indice_fila)
	{
		return (vector_privado[indice_fila]);
	}
	
	
	/***********************************************************************/
	// Añade una secuencia a la tabla (al final)
	// Recibe: una_secuencia, la secuencia que se va a añadir
	//
	// PRE: total_utilizados < TAMANIO
	// 		La adición se realiza si hay espacio para el nuevo elemento. 
	// 		El nuevo elemento se coloca al final del vector. 
	// 		Si no hay espacio, no se hace nada.	

	void Aniade (SecuenciaCaracteres una_secuencia)
	{
		if (total_utilizados < TAMANIO) {

			vector_privado[total_utilizados]=una_secuencia;			
			total_utilizados++;
		}
	}
	
	/*****************************************************************/
	// Inserta una fila completa en una posición dada. 
	// La fila se porporciona en un objeto "SecuenciaCaracteres".
	// 
	// Recibe: num_fila, la posición que ocupará "fila_nueva" cuando se 
	//		 		inserte en la tabla.
	//		   fila_nueva, la secuencia que se va a insertar. Se trata 
	//				de un objeto de la clase SecuenciaCaracteres. 
	//
	// PRE:  filas_utilizadas < TAMANIO
	// PRE:  0 <= num_fila <= TotalUtilizados()
	//		 Si num_fila = 0, "nueva_fila" será la nueva primera fila. 
	//		 Si num_fila = TotalUtilizados(), "nueva_fila" será la nueva 
	//		 última fila (el resultado será equivalente al de "Aniade()" 
	
	void Inserta (int num_fila, SecuenciaCaracteres fila_nueva)
	{
		// Comprobar precondiciones
		
		if ((total_utilizados < TAMANIO) && 
			(0<=num_fila) && (num_fila <=total_utilizados)) {

			// "Desplazar" las filas hacia posiciones altas. 
			// La última fila se copia en una NUEVA FILA que ocupa la 
			// posición "filas_utilizadas", la penúltima se copia en 
			// "filas_utilizadas"-1, ... y se queda un "hueco" en 
			// la fila "num_fila ".
			// NOTA: no se modifica (todavía) "filas_utilizadas" 
			
			for (int fil=total_utilizados; fil>num_fila; fil--) 
			
				vector_privado[fil] = vector_privado[fil-1]; 
				
					
			// Copiar en el "hueco" (fila "num_fila") el contenido de 
			// la secuencia "fila_nueva"
			
			vector_privado[num_fila]= fila_nueva;
						
			total_utilizados++; // Actualización del tamaño de la tabla.
					
		}
	}
	
	/***********************************************************************/
	// Eliminar la secuencia que se encuentra en la posición dada por "indice".
	// Realiza un borrado físico (con desplazamiento y sustitución).
	//
	// PRE: 0 <= indice < total_utilizados 
	
	void Elimina (int indice) 
	{
		// Recorremos de izquierda a derecha toda las componentes 
		// que hay a la derecha de la posición a eliminar
		//		Le asignamos a cada componente la que hay a su derecha

		if ((indice >= 0) && (indice < total_utilizados)) {

			int tope = total_utilizados-1; // posición del último 
    
			for (int i = indice ; i < tope ; i++) {
				vector_privado[i] = vector_privado[i+1];
 	    	}
			total_utilizados--;    
		}
	}
		
	/*****************************************************************/
	// Método de lectura: devuelve el dato que ocupa la casilla 
	// de coordenadas (fila, columna)
	// PRE: 0 <= fila < filas_utilizadas
	// PRE: 0 <= columna < num_cols_utilizadas[fila]	
	
	double Elemento (int fila, int columna)
	{
		return (vector_privado[fila].Elemento(columna));
	}
		
	/***********************************************************************/
	// "Vacía" una secuencia
	
	void EliminaTodos (void)
	{
		total_utilizados = 0;
	}

	/***********************************************************************/
	// Devuelve TRUE si la secuencia está vacía
	
	bool EstaVacia (void)
	{
		return (total_utilizados==0);
	}
	
	/*****************************************************************/
	// Calcula si dos matrices dentadas son iguales

	bool EsIgual (TablaDentadaCaracteres otra)
	{
		bool son_iguales = true; 
		
		if (FilasUtilizadas()!= otra.FilasUtilizadas())
			
			son_iguales = false;
		
		else {
			
			int f=0; 
			
			while (f<FilasUtilizadas() && son_iguales) {
				
				if (ColumnasUtilizadas(f)!= otra.ColumnasUtilizadas(f)) 
				
					son_iguales = false;	
				
				else {
					
					int c=0; 
					
					while (c<ColumnasUtilizadas(f) && son_iguales) {
				
						if (Elemento(f,c) != otra.Elemento(f,c)) 
							son_iguales = false;
							
						c++;
						
					} // while c
		
					f++;
					
				} // else 
					
			} // while f
					
		} // else 
	
		return (son_iguales);
	}
	
	/*********************************************************************/
	// Forma un string con el contenido de la tabla.  
	// La primera línea es el encabezamiento indicado en "titulo".
	
	string ToString (string titulo)
	{
		string cad; 
		
		cad = "\n" + titulo + "\n"; 	
		cad = cad + "\n--------------------------------------\n"; 
		
		for (int fila=0; fila<total_utilizados; fila++) {
	
			SecuenciaCaracteres la_secuencia = Fila(fila);
			
			int num_datos = la_secuencia.TotalUtilizados();
	
			cad = cad + "Fila " + to_string(fila); 
			cad = cad + " (" + to_string(num_datos) + " datos): "; 
			cad = cad + la_secuencia.ToString() + "\n";
		}
		
		cad = cad + "--------------------------------------\n"; 
		cad = cad + "\n\n";
		
		return (cad); 
	}
	
	/*****************************************************************/
		
};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////


/***************************************************************************/
/***************************************************************************/

int main (void)
{
	// Añadir datos a la primera fila
	
	SecuenciaCaracteres una_fila; 
	
	una_fila.Aniade ('c'); una_fila.Aniade ('b');	
	una_fila.Aniade ('a'); una_fila.Aniade ('l');

	// Crear la tabla a partir de la primera fila
	
	TablaDentadaCaracteres matriz;
	
	matriz.Aniade (una_fila);

	// Vaciar la secuencia, y añadir una nueva fila a "matriz" 
	
	una_fila.EliminaTodos();	// Para poder utilizarse posteriormente
		
	una_fila.Aniade ('f'); una_fila.Aniade ('g');	
	una_fila.Aniade ('h'); 
	
	matriz.Aniade (una_fila);
		
	una_fila.EliminaTodos();	// Para poder utilizarse posteriormente
		
	
	
	// Mostrar los datos leidos
	
	cout << matriz.ToString("Tabla orginal:"); 	
	
	
	// Rellenar una secuencia pra insertarla en "matriz" 
		
	una_fila.Aniade ('d'); una_fila.Aniade ('d');	
	una_fila.Aniade ('e');
	
	matriz.Inserta (1, una_fila);
		
	una_fila.EliminaTodos();	// Para poder utilizarse posteriormente
	
		
		
	// Mostrar la matriz tras la inserción
	
	cout << matriz.ToString("Tabla tras insercion:"); 		
	
	// Rellenar una secuencia para insertarla en "matriz" 
		
	una_fila.Aniade ('a'); una_fila.Aniade ('b');	
	
	matriz.Inserta (matriz.FilasUtilizadas(), una_fila);
		
	una_fila.EliminaTodos();	// Para poder utilizarse posteriormente
	
		
	// Mostrar la matriz tras la inserción
	
	cout << matriz.ToString("Tabla tras otra insercion:"); 		


	// Elimina una fila
	
	matriz.Elimina(2);
			
	// Mostrar la matriz tras el borrado
	
	cout << matriz.ToString("Tabla tras borrar fila 2:"); 	


	// Elimina una fila
	
	matriz.Elimina(0);
			
	// Mostrar la matriz tras el borrado
	
	cout << matriz.ToString("Tabla tras borrar fila 0:"); 	
	
	return 0;
}
