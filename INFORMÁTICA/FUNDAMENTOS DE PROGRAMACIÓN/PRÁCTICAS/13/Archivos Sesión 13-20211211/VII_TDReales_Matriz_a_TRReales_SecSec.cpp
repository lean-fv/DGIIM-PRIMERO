/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 7
//
/*	 
	Programa que crea una matriz rectangular de valores reales (secuencia de 
	secuencias) a partir de una tabla dentada de reales (matriz cl�sica), 
	usando los valores que est�n presentes en la mayor tabla rectangular 
	que puede formarse con la tabla dentada. 
	
	La tabla rectangular tendr� tantas filas como la tabla dentada, y tantas 
	columnas como columnas tenga la fila "m�s corta" de la tabla dentada. 
	
	.........................................................................
	
	Por ejemplo, a partir la tabla dentada: 
	
		 7   9  12  15   6  77	9  88  99
		 8   6   7  10
		99  12   8   5  33   1
	
	obtendremos la tabla rectangular: 
	
		 7   9  12  15
		 8   6   7  10
		99  12   8   5
		
	Tambi�n crea otra matriz rectangular de valores enteros positivos 
	a partir de una tabla dentada, usando los valores restantes, los 
	que no est�n presentes en la mayor tabla rectangular que puede 
	formarse con la tabla dentada. Los "huecos" los rellena con ceros.
	
	La tabla rectangular tendr� tantas filas como la tabla dentada, y tantas 
	columnas como columnas tenga la fila "m�s larga" de la tabla dentada, 
	restando el n�mero de columnas comunes. 
	
	Por ejemplo, a partir la tabla dentada: 
	
		 7   9  12  15   6  77	9  88  99
		 8   6   7  10
		99  12   8   5  33   1
	
	obtendremos la tabla rectangular: 		
		
		 6    77     9    88    99
		 0     0     0     0     0
		33     1     0     0     0
		
	Explicaci�n:
	
		 7   9  12  15  ||	6    77     9    88    99
		 8   6   7  10  ||	0     0     0     0     0
		99  12   8   5  || 33     1     0     0     0		
	
		PARTE COM�N     ||    PARTE NO COM�N
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class SecuenciaReales  
{

private:

	static const int TAMANIO = 50; // N�mero de casillas disponibles
	double vector_privado[TAMANIO];
	
	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;	// N�mero de casillas ocupadas

public:
	
	/***********************************************************************/
	// Constructor sin argumentos

	SecuenciaReales (void) 
	{
		total_utilizados = 0;
	}

	/***********************************************************************/
	// M�todos de lectura (Get) de los datos individuales 

	// Devuelve el n�mero de casillas ocupadas
	int TotalUtilizados (void)
	{
		return (total_utilizados);
	}

	// Devuelve el n�mero de casillas disponibles
	int Capacidad (void)
	{
		return (TAMANIO);
	}

	/***********************************************************************/
	// A�ade un elemento al vector.
	// Recibe: nuevo, el elemento que se va a a�adir.
	//
	// PRE: total_utilizados < TAMANIO
	// 		La adici�n se realiza si hay espacio para el nuevo elemento. 
	// 		El nuevo elemento se coloca al final del vector. 
	// 		Si no hay espacio, no se hace nada.	

	void Aniade (double nuevo)
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

	double Elemento (int indice)
	{
		return vector_privado[indice];
	}
	
	/***********************************************************************/
	// "Vac�a" una secuencia
		
	void EliminaTodos (void) 
	{
		total_utilizados = 0;
	}
			
	/***********************************************************************/
	// Eliminar el dato de la posici�n dada por "indice".
	// Realiza un borrado f�sico (con desplazamiento y sustituci�n).
	//
	// PRE: 0 <= indice < total_utilizados 
	
	void Elimina (int indice) 
	{
		// Recorremos de izquierda a derecha toda las componentes 
		// que hay a la derecha de la posici�n a eliminar
		//		Le asignamos a cada componente la que hay a su derecha

		if ((indice >= 0) && (indice < total_utilizados)) {

			int tope = total_utilizados-1; // posici�n del �ltimo 
    
			for (int i = indice ; i < tope ; i++)
				vector_privado[i] = vector_privado[i+1];  
    
			total_utilizados--;    
		}
	}
	
	/***********************************************************************/
	// Devuelve true si la secuencia est� vac�a

	bool EstaVacia (void) 
	{
		return (total_utilizados == 0);
	}
	
	/***********************************************************************/
	// Devuelve true si las secuencias son iguales

	bool EsIgual (SecuenciaReales otra) 
	{
		bool son_iguales = true; 
		
		if (total_utilizados != otra.total_utilizados)
		
			son_iguales = false;
		
		else {
				
			bool sigo = true;
			int pos = 0;
			
			while (sigo && (pos < total_utilizados)) {
	
				if (vector_privado[pos]!=otra.vector_privado[pos]) {
					sigo = false;
					son_iguales = false;
				}
				else
					pos++; 
			} // while (sigo && pos < total_utilizados) 
		}
			
		return (son_iguales);
	}
	
	/***********************************************************************/
	// B�squeda de un valor en la secuencia, entre dos posiciones dadas. 
	// Realiza una b�squeda secuencial
	//
	// Recibe: 	buscado, el valor a buscar en la secuencia.
	//			izda y dcha, posiciones entre las que se realiza la b�squeda.
	// Devuelve: la posici�n del elemento "buscado", si est� en la secuencia,
	//			 o -1, si no lo encuentra.
	// PRE: 0 <= izda <= dcha < total_utilizados

	int Posicion (double buscado, int izda, int dcha)
	{
		bool encontrado = false; 
		int pos = izda; 

		while ((pos <= dcha) && (!encontrado)) {

			if (vector_privado[pos] != buscado) // Seguir buscando
				pos++;
			else // Terminar la b�squeda: �xito
				encontrado =  true;
		} 

		if (encontrado)
			return (pos);
		else 
			return (-1);

	}
	
    /***********************************************************************/
    // Compone un string con todos los valores que est�n
    // almacenados en la secuencia y lo devuelve.

    string ToString()
    {
        string cadena = "{";

		if (total_utilizados > 0) {

	        for (int i=0; i<total_utilizados-1; i++)
	        	cadena = cadena + to_string(vector_privado[i])+", ";

			// A�adie el �ltimo seguido de '}'
	        cadena = cadena + to_string(vector_privado[total_utilizados-1]);
		}

        cadena = cadena + "}";

        return (cadena);
    }
    
   	/***********************************************************************/
   	
};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

		
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// Tabla dentada de datos double
//
// Representaci�n: Secuencias de "SecuenciaReales"

class TablaRectangularReales {
	
private:

    static const int MAX_FIL = 50; // "filas" disponibles
    static const int MAX_COL = 40;

    SecuenciaReales vector_privado[MAX_FIL];

    // PRE: 0 <= filas_utilizadas <= MAX_FIL
    // PRE: 0 <= cols_utilizadas <= MAX_COL
    
    int filas_utilizadas;
    int cols_utilizadas;

public:
	
	
	/***********************************************************************/
	// Constructor sin argumentos--> Crea matriz nula

	TablaRectangularReales (void)
		: filas_utilizadas(0), 
		  cols_utilizadas(0)
	{
	}

	/***********************************************************************/
	// Constructor--> Recibe "numero_de_columnas" que indica el n�mero de 
	// columnas que deben tener TODAS las filas. 
	// PRE: numero_de_columnas <= MAX_COL


	TablaRectangularReales (int numero_de_columnas)
		: filas_utilizadas(0), 
		  cols_utilizadas(numero_de_columnas)
	{
	}

	/***********************************************************************/
	// Constructor--> Recibe una secuencia de reales.  El n�mero de 
	// elementos de la secuencia es el valor que se usa como "col_utilizadas"
	// PRE: primera_fila.TotalUtilizados() <= MAX_COL

	TablaRectangularReales (SecuenciaReales primera_fila)
		: filas_utilizadas(0), 
		  cols_utilizadas (primera_fila.TotalUtilizados())
	{
		Aniade(primera_fila); // Actualiza "filas_utilizadas"
	}

	/***********************************************************************/
	// M�todo de lectura: n�mero m�ximo de filas

	int CapacidadFilas (void)
	{
		return (MAX_FIL);
	}

	/*****************************************************************/
	// M�todo de lectura: n�mero m�ximo de columnas

	int CapacidadColumnas (void)
	{
		return (MAX_COL);
	}

	/*****************************************************************/
	// M�todo de lectura: n�mero real de filas usadas

	int FilasUtilizadas (void)
	{
		return (filas_utilizadas);
	}

	/*****************************************************************/
	// M�todo de lectura: n�mero real de columnas usadas

	int ColumnasUtilizadas (void)
	{
		return (cols_utilizadas);
	}

	/*****************************************************************/
	// M�todo de lectura: devuelve el dato que ocupa la casilla 
	// de coordenadas (fila, columna)
	// PRE: 0 <= fila < filas_utilizadas
	// PRE: 0 <= columna < cols_utilizadas	
	
	int Elemento (int fila, int columna)
	{
		return ((vector_privado[fila]).Elemento(columna));
	}

	/*****************************************************************/
	// Devuelve una fila completa (un objeto "SecuenciaReales")
	// PRE: 0 <= indice_fila < filas_utilizadas
	
	SecuenciaReales Fila (int indice_fila)
	{
		return (vector_privado[indice_fila]);
	}

	/*****************************************************************/
	// Devuelve una columna completa (un objeto "SecuenciaReales")
	// PRE: 0 <= indice_columna < cols_utilizadas
	
	SecuenciaReales Columna (int indice_columna)
	{
		SecuenciaReales columna;

		for (int fil=0; fil<filas_utilizadas; fil++)
			columna.Aniade ((vector_privado[fil]).Elemento(indice_columna));

		return (columna);
	}

	/***********************************************************************/
	// A�ade una fila completa (un objeto "SecuenciaReales")
	// PRE:  fila_nueva.TotalUtilizados() = cols_utilizadas
	// PRE:  filas_utilizadas < MAX_FIL
	
	void Aniade (SecuenciaReales fila_nueva)
	{
		int numero_columnas_fila_nueva = fila_nueva.TotalUtilizados();
					
		if ((filas_utilizadas < MAX_FIL) && 
			(numero_columnas_fila_nueva == cols_utilizadas)) {

			vector_privado[filas_utilizadas] = fila_nueva;

			filas_utilizadas++;
		}
	}


	/***********************************************************************/
	// "Vac�a" una tabla

	void EliminaTodos (void)
	{
		filas_utilizadas = 0;
	}
	
	/*****************************************************************/
	// Calcula si dos matrices rectangulares son iguales
	// Compara la tabla impl�cita con "otra" (tabla expl�cita) 

	bool EsIgual (TablaRectangularReales otra)
	{
		bool son_iguales = true; 
		
		if ((filas_utilizadas != otra.FilasUtilizadas()) || 
			 (cols_utilizadas != otra.ColumnasUtilizadas()))		
			
			son_iguales = false;
		
		else {
			
			// Recorrido por filas 
	
			int fil = 0;
			
			while (fil < filas_utilizadas && !son_iguales) {
	
				SecuenciaReales una_fila = Fila (fil);
				SecuenciaReales otra_fila = otra.Fila (fil);	
				
				if (una_fila.EsIgual(otra_fila))
					fil++;
				else
					son_iguales = false;
					
			} // while fil
					
		} // else 
	
		return (son_iguales);
	}
	
	/***********************************************************************/
	// Devuelve la traspuesta de la matriz (si es posible calcularse)
	// PRE: filas_utilizadas <= MAX_COL
	// PRE: cols_utilizadas  <= MAX_FIL
	// Si no se puede calcular la traspuesta se devuelve una matriz nula. 
	
	TablaRectangularReales Traspuesta (void)
	{
	    TablaRectangularReales traspuesta; // Inicialmente vac�a
			    
		if ((filas_utilizadas <= MAX_COL) && (cols_utilizadas <= MAX_FIL)) {
		
			// La traspuesta tiene tantas filas como columnas tiene la 
			// matriz original

			TablaRectangularReales solucion (filas_utilizadas);


			SecuenciaReales columna; // Las filas de "traspuesta" ser�n las 
								      // columnas de la tabla impl�cita 

			for (int col = 0; col < cols_utilizadas; col++){

				columna = Columna(col);
				solucion.Aniade(columna); 
			}
			
			traspuesta = solucion;
		} 

		return (traspuesta);
	}	
	
	/***********************************************************************/
	// Calcula si una matriz es sim�trica.
	// CONDICI�N NECESARIA: debe ser cuadrada. 
	// Este m�todo comprueba directamente si cada componente es igual a
	// su sim�trica, parando el recorrido cuando encuentre una componente
	// que no lo verifique.
	//
	// Evita el c�lculo de la traspuesta, y el problema que puede surgir
	// si no se puede calcular la traspuesta de la matriz por problemas de
	// capacidad.

	bool EsSimetrica (void)
	{
		bool es_simetrica = true;
		
		// Si el n�mero de filas y columnas no coinciden, no hay que seguir
		// porque la matriz no es sim�trica.
		
		es_simetrica = (filas_utilizadas == cols_utilizadas);

		if (es_simetrica) {
		
			int f=0; 
			
			while (f<filas_utilizadas && es_simetrica) {
				
				int c=0; 
				
				while (c<cols_utilizadas && es_simetrica) {
			
					if (Elemento(f,c) != Elemento(c,f)) 
						es_simetrica = false;
						
					c++;
					
				} // while c
	
				f++;
					
			} // while f
			
		} // if (es_simetrica)
		
		return (es_simetrica);
	}
	
	
	/*****************************************************************/
	// Inserta una fila completa en una posici�n dada. 
	// La fila se porporciona en un objeto "SecuenciaReales".
	// 
	// Recibe: num_fila, la posici�n que ocupar� "fila_nueva" cuando se 
	//		 		inserte en la tabla.
	//		   fila_nueva, la secuencia que se va a insertar. Se trata 
	//				de un objeto de la clase SecuenciaEnteros. 
	//
	// PRE:  fila_nueva.TotalUtilizados() = cols_utilizadas
	// PRE:  filas_utilizadas < MAX_FIL
	// PRE:  0 <= num_fila <= TotalUtilizados()
	//		 Si num_fila = 0, "nueva_fila" ser� la nueva primera fila. 
	//		 Si num_fila = TotalUtilizados(), "nueva_fila" ser� la nueva 
	//		 �ltima fila (el resultado ser� equivalente al de "Aniade()" 
	
	void Inserta (int num_fila, SecuenciaReales fila_nueva)
	{
		int numero_columnas_fila_nueva = fila_nueva.TotalUtilizados();
					
		// Comprobar precondiciones
		
		if ((filas_utilizadas < MAX_FIL) && 
			(numero_columnas_fila_nueva == cols_utilizadas) && 
			(0<=num_fila) && (num_fila <=filas_utilizadas)) {

			// "Desplazar" las filas hacia posiciones altas. 
			// La �ltima fila se copia en una NUEVA FILA que ocupa la 
			// posici�n "filas_utilizadas", la pen�ltima se copia en 
			// "filas_utilizadas"-1, ... y se queda un "hueco" en 
			// la fila "num_fila ".
			// NOTA: no se modifica (todav�a) "filas_utilizadas" 
			
			for (int fil=filas_utilizadas; fil>num_fila; fil--) 			
				vector_privado[fil]=vector_privado[fil-1];
			
			// Copiar en el "hueco" (fila "num_fila") el contenido de 
			// la secuencia "fila_nueva"
			
			vector_privado[num_fila]=fila_nueva;	
			
			filas_utilizadas++; // Actualizaci�n del tama�o de la tabla.
		}
	}

	/*****************************************************************/
	// Elimina una fila completa, dada una posici�n. 
	// 
	// Recibe: num_fila, la posici�n de la fila a eliminar.
	// PRE:  0 <= num_fila < TotalUtilizados()
	
	void Elimina (int num_fila)
	{		
		// Comprobar precondiciones
		
		if ((0<=num_fila) && (num_fila <=filas_utilizadas)) {

			// "Desplazar" las filas hacia posiciones bajas. 
			// En la posici�n "num_fila" se copia la que est� en la posici�n
			// siguiente ("num_fila"+1), en su lugar se copia que est� en 
			// "num_fila"+2, ... y en la posici�n "total_utilizados"-2 se 
			// copia la de "total_utilizados"-1. 
			
			for (int fil=num_fila; fil<filas_utilizadas-1; fil++) 
				vector_privado[fil]=vector_privado[fil+1];
			
			filas_utilizadas--; // Actualizaci�n del tama�o de la tabla.
		}
	}
	
	/*****************************************************************/
	// Devuelve TRUE si la matriz contiene el valor "buscado"
	
	bool Contiene (int buscado)
	{
		bool encontrado = false;

		// Recorrido por columnas 

		int fil = 0;

		while (fil < filas_utilizadas  && !encontrado) {

			SecuenciaReales una_fila = Fila (fil);
			
			int pos_buscado = una_fila.Posicion(buscado,0,cols_utilizadas-1);

			if (pos_buscado != -1) 
				encontrado = true;
			else 
				fil++; 

		} // while fil

		return (encontrado);
	}
		
	/***********************************************************************/
	// Devuelve true si la tabla est� vac�a

	bool EstaVacia (void) 
	{
		return (filas_utilizadas == 0);
	}		

	/***********************************************************************/
	// Compone y devuelve un string con el contenido de la matriz
	
	string ToString ()
	{
		string cad; 
		
		for (int fila=0; fila<filas_utilizadas; fila++) {
			SecuenciaReales la_fila = Fila(fila);
			cad = cad + "\t" + la_fila.ToString() + "\n";
		}
		
		return (cad);
	}
	
	/***********************************************************************/
		
};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// Tabla dentada de datos double
//
// Representaci�n: matriz "cl�sica"

class TablaDentadaReales 
{
private:

  	static const int NUM_FILS = 50;  // Filas disponibles
    static const int NUM_COLS = 40;  // Columnas disponibles

    double matriz_privada[NUM_FILS][NUM_COLS];

    // PRE: 0 <= filas_utilizadas <= NUM_FILS

    int filas_utilizadas;

    // PRE: 0 <= num_cols_utilizadas[i] <= NUM_COLS
    //      para i=0,1,...,filas_utilizadas-1
    // N�mero de columnas ocupadas en cada fila

    int num_cols_utilizadas[NUM_FILS];
	
public:
	
	/***********************************************************************/
	// Constructor sin argumentos--> Crea matriz nula

	TablaDentadaReales (void)
		: filas_utilizadas(0)
	{
	}

	/***********************************************************************/
	// Constructor--> Recibe una secuencia de caracteres que ser� la primera 
	// fila de la tabla. 

	TablaDentadaReales (SecuenciaReales primera_fila)
		: filas_utilizadas(0)
	{
		Aniade(primera_fila); // Actualiza "filas_utilizadas"
	}
	
	/***********************************************************************/
	// Devuelve el n�mero de casillas disponibles
	
	int CapacidadFilas (void)
	{
		return (NUM_FILS);
	}
	
	/*****************************************************************/
	// M�todo de lectura: n�mero m�ximo de columnas

	int CapacidadColumnas (void)
	{
		return (NUM_COLS);
	}
	
	/*****************************************************************/
	// M�todo de lectura: n�mero real de filas usadas

	int FilasUtilizadas (void)
	{
		return (filas_utilizadas);
	}
			
	/*****************************************************************/
	// M�todo de lectura: n�mero real de columnas usadas en la fila "fila"
	// PRE: 0 <= fila < filas_utilizadas
	
	int ColumnasUtilizadas (int fila)
	{
		return (num_cols_utilizadas[fila]);
	}
	
	/*****************************************************************/
	// M�todo de lectura: devuelve el dato que ocupa la casilla 
	// de coordenadas (fila, columna)
	// PRE: 0 <= fila < filas_utilizadas
	// PRE: 0 <= columna < num_cols_utilizadas[fila]	
	
	double Elemento (int fila, int columna)
	{
		return (matriz_privada[fila][columna]);
	}
	
	/***********************************************************************/
	// Devuelve true si la tabla est� vac�a

	bool EstaVacia (void) 
	{
		return (filas_utilizadas == 0);
	}
	
	/***********************************************************************/
	// "Vac�a" una tabla
	
	void EliminaTodos (void)
	{
		filas_utilizadas = 0;
	}
	
	/*****************************************************************/
	// Devuelve una fila completa, como un objeto de la clase 
	// "SecuenciaReales"
	// PRE: 0 <= indice_fila < filas_utilizadas
	
	SecuenciaReales Fila (int indice_fila)
	{
		SecuenciaReales la_fila;
				
		int num_columnas = num_cols_utilizadas[indice_fila];
			
		for (int c=0; c<num_columnas; c++) 
			la_fila.Aniade (matriz_privada[indice_fila][c]);
		
		return (la_fila);
	}
	
	/***********************************************************************/
	// A�ade una fila completa. La fila se porporciona en un objeto de 
	// la clase "SecuenciaReales".
	// 
	// PRE:  fila_nueva.TotalUtilizados() <= MAX_COL
	// PRE:  filas_utilizadas < MAX_FIL
	//
	// 		La adici�n se realiza si hay espacio para el nuevo elemento. 
	// 		El nuevo elemento se coloca al final del vector. 
	// 		Si no hay espacio, no se hace nada.	
	
	void Aniade (SecuenciaReales fila_nueva)
	{
		int numero_columnas_fila_nueva = fila_nueva.TotalUtilizados();
					
		if ((filas_utilizadas < NUM_FILS) &&
			(numero_columnas_fila_nueva <= NUM_COLS)) {

			for (int c=0; c<numero_columnas_fila_nueva; c++) 
				matriz_privada[filas_utilizadas][c] = fila_nueva.Elemento(c);

			num_cols_utilizadas[filas_utilizadas]=numero_columnas_fila_nueva;
			
			filas_utilizadas++;

		}
	}

	/*****************************************************************/
	// Calcula si dos matrices dentadas son iguales

	bool EsIgual (TablaDentadaReales otra_tabla)
	{
		bool son_iguales = true; 
		
		if (filas_utilizadas != otra_tabla.FilasUtilizadas())
			
			son_iguales = false;
		
		else {
			
			int f=0; 
			
			while (f<filas_utilizadas && son_iguales) {
				
				if (num_cols_utilizadas[f] != otra_tabla.ColumnasUtilizadas(f)) 
				
					son_iguales = false;	
				
				else {
					
					int c=0; 
					
					while (c<num_cols_utilizadas[f] && son_iguales) {
				
						if (matriz_privada[f][c] != otra_tabla.Elemento(f,c)) 
							son_iguales = false;
							
						c++;
						
					} // while c
		
					f++;
					
				} // else 
					
			} // while f
					
		} // else 
	
		return (son_iguales);
	}
	
	/*****************************************************************/
	// Inserta una fila completa en una posici�n dada. 
	// La fila se porporciona en un objeto "SecuenciaReales".
	// 
	// Recibe: num_fila, la posici�n que ocupar� "fila_nueva" cuando se 
	//		 		inserte en la tabla.
	//		   fila_nueva, la secuencia que se va a insertar. Se trata 
	//				de un objeto de la clase SecuenciaReales. 
	//
	// PRE:  fila_nueva.TotalUtilizados() <= MAX_COL
	// PRE:  filas_utilizadas < MAX_FIL
	// PRE:  0 <= num_fila <= TotalUtilizados()
	//		 Si num_fila = 0, "nueva_fila" ser� la nueva primera fila. 
	//		 Si num_fila = TotalUtilizados(), "nueva_fila" ser� la nueva 
	//		 �ltima fila (el resultado ser� equivalente al de "Aniade()" 
	
	void Inserta (int num_fila, SecuenciaReales fila_nueva)
	{
		int numero_columnas_fila_nueva = fila_nueva.TotalUtilizados();
					
		// Comprobar precondiciones
		
		if ((filas_utilizadas < NUM_FILS) &&
			(numero_columnas_fila_nueva <= NUM_COLS) &&
			(0<=num_fila) && (num_fila <=filas_utilizadas)) {

			// "Desplazar" las filas hacia posiciones altas. 
			// La �ltima fila se copia en una NUEVA FILA que ocupa la 
			// posici�n "filas_utilizadas", la pen�ltima se copia en 
			// "filas_utilizadas"-1, ... y se queda un "hueco" en 
			// la fila "num_fila ".
			// NOTA: no se modifica (todav�a) "filas_utilizadas" 
			
			for (int fil=filas_utilizadas; fil>num_fila; fil--) {	
			
				int num_columnas = num_cols_utilizadas[fil-1];
					
				for (int c=0; c<num_columnas; c++) 
					matriz_privada[fil][c] = matriz_privada[fil-1][c]; 
					
				num_cols_utilizadas[fil] = num_cols_utilizadas[fil-1];
			}
					
			// Copiar en el "hueco" (fila "num_fila") el contenido de 
			// la secuencia "fila_nueva"
			
			for (int c=0; c<numero_columnas_fila_nueva; c++) 
				matriz_privada[num_fila][c] = fila_nueva.Elemento(c);
			
			num_cols_utilizadas[num_fila] = numero_columnas_fila_nueva;
			
			filas_utilizadas++; // Actualizaci�n del tama�o de la tabla.
		}
	}

	/*****************************************************************/
	// Elimina una fila completa, dada una posici�n. 
	// 
	// Recibe: num_fila, la posici�n de la fila a eliminar.
	//
	// PRE:  0 <= num_fila < TotalUtilizados()
	
	void Elimina (int num_fila)
	{		
		// Comprobar precondiciones
		
		if ((0<=num_fila) && (num_fila <=filas_utilizadas)) {

			// "Desplazar" las filas hacia posiciones bajas. 
			// En la posici�n "num_fila" se copia la que est� en la posici�n
			// siguiente ("num_fila"+1), en su lugar se copia que est� en 
			// "num_fila"+2, ... y en la posici�n "total_utilizados"-2 se 
			// copia la de "total_utilizados"-1. 
			
			for (int fil=num_fila; fil<filas_utilizadas-1; fil++) {
			
				int num_columnas = num_cols_utilizadas[fil+1];
					
				for (int c=0; c<num_columnas; c++) 
					matriz_privada[fil][c]=matriz_privada[fil+1][c];
					
				num_cols_utilizadas[fil] = num_cols_utilizadas[fil+1];
			}
			
			filas_utilizadas--; // Actualizaci�n del tama�o de la tabla.
		}
	}
			
	/***********************************************************************/
	// Compone y devuelve un string con el contenido de la matriz
	
	string ToString ()
	{
		string cad; 
		
		for (int fila=0; fila<filas_utilizadas; fila++) {
			SecuenciaReales la_secuencia = Fila(fila);
			cad = cad + "\t" + la_secuencia.ToString() + "\n";
		}
		
		return (cad);
	}
	
	/***********************************************************************/
	
	TablaRectangularReales ExtraeTablaRectangularComun	(void)
	{
		// Calcular el m�nimo n�mero de columnas (es el n�mero de columnas 
		// de la fila "m�s corta")
		
		SecuenciaReales una_fila = Fila(0);
		int min_num_cols = una_fila.TotalUtilizados();
		
		int num_filas = filas_utilizadas;
		
		for (int f=1; f<num_filas; f++) {
	
			una_fila = Fila(f);
			int cols_fila_f = una_fila.TotalUtilizados();
			
			if (cols_fila_f < min_num_cols)  
				min_num_cols = cols_fila_f;
		}
		
		/*
		cout << "La fila mas corta tiene " << min_num_cols 
		     << " columnas" << endl; 
		*/
		
		
		// Crear la tabla rectangular
		TablaRectangularReales resultado (min_num_cols);
			
		// Rellenarla
		for (int f=0; f<num_filas; f++) {
	
			SecuenciaReales una_fila;
	
			for (int c=0; c<min_num_cols; c++) 
				una_fila.Aniade(Elemento(f,c));
	
			resultado.Aniade(una_fila);		
		}
		
		return (resultado);
		
	}
		
	/***********************************************************************/
		
	TablaRectangularReales ExtraeTablaRectangularResto	(void)
	{
		// Calcular el m�ximo n�mero de columnas (es el n�mero de columnas 
		// de la fila "m�s larga")
		
		int min_num_cols, max_num_cols;
		
		SecuenciaReales fila_leida;	
			
		fila_leida = Fila(0);		
		min_num_cols = max_num_cols= fila_leida.TotalUtilizados();
		
		int num_filas = filas_utilizadas;
		
		
		for (int f=1; f<num_filas; f++) {
	
			fila_leida = Fila(f);
			int cols_fila_f = fila_leida.TotalUtilizados();
			
			if (cols_fila_f < min_num_cols)  
				min_num_cols = cols_fila_f;
				
			if (cols_fila_f > max_num_cols)  
				max_num_cols = cols_fila_f;
		}
		
		/*
		cout << "La fila mas corta tiene " << min_num_cols 
		     << " columnas" << endl; 
		cout << "La fila mas larga tiene " << max_num_cols 
		     << " columnas" << endl; 
		cout << "Creando tabla con " << max_num_cols -min_num_cols
		     << " columnas" << endl; 	
		*/
		
		
		// Crear la tabla rectangular
		TablaRectangularReales resultado (max_num_cols-min_num_cols);
			
			
		// Rellenarla
		
		for (int f=0; f<num_filas; f++) {
	
			SecuenciaReales fila_escrita;	
			
			fila_leida = Fila(f);
			int cols_fila_f = fila_leida.TotalUtilizados();
	
			for (int c=min_num_cols; c<cols_fila_f; c++) {
				fila_escrita.Aniade(Elemento(f,c));
			}
		
			for (int c=cols_fila_f; c<max_num_cols; c++)  
				fila_escrita.Aniade(0);
			
			resultado.Aniade(fila_escrita);		
		}
		
		return (resultado);
		
	}
	
	/***********************************************************************/
						
};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
	



/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////



/***************************************************************************/
// Rellena la matriz a discreci�n.
/*
	En este caso: 
		 7   9  12  15  6  77  9  88  99
		 8   6   7  10
		99  12   8  5  33  1
*/

TablaDentadaReales Inicia_matriz (void)
{
	// Crear la tabla vacia
	
	TablaDentadaReales matriz;


	// A�adir datos a la primera fila
	
	SecuenciaReales una_fila; 
	
	una_fila.Aniade (7);  
	una_fila.Aniade (9);  
	una_fila.Aniade (12); 
	una_fila.Aniade (15); 
	una_fila.Aniade (6);  
	una_fila.Aniade (77); 
	una_fila.Aniade (9);  
	una_fila.Aniade (88); 
	una_fila.Aniade (99); 
	
	// A�adir la primera fila
	
	matriz.Aniade(una_fila);
	
	
	// Vaciar la secuencia, y a�adir una nueva fila a "matriz" 
	
	una_fila.EliminaTodos();	// Para poder utilizarse posteriormente
		
	una_fila.Aniade (8);  una_fila.Aniade (6);  una_fila.Aniade (7); 
	una_fila.Aniade (10); 
	matriz.Aniade (una_fila);
		
	// Vaciar la secuencia, y a�adir una nueva fila a "matriz" 
		
	una_fila.EliminaTodos();	// Para poder utilizarse posteriormente
	
	una_fila.Aniade (99); una_fila.Aniade (12); una_fila.Aniade (8); 
	una_fila.Aniade (5);  una_fila.Aniade (33);  una_fila.Aniade (1); 
	matriz.Aniade (una_fila);	

	return (matriz);
}

/***************************************************************************/

int main (void)
{
	cout.setf(ios::fixed);		// Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 


	// La "TablaDentadaReales" que se va a formar. 
	TablaDentadaReales tabla = Inicia_matriz();


	// Mostrar contenido de "tabla"
	
	cout << endl; 			
	cout << "Tabla creada: " << endl;
	cout << endl; 		
	cout << tabla.ToString() << endl; 
	cout << endl; 
	
	
	// Construir la tabla rectangular com�n
	
	TablaRectangularReales comun = tabla.ExtraeTablaRectangularComun ();
	
	// Mostrar los datos calculados
	
	cout << endl; 			
	cout << "Tabla rectangular comun: " << endl;
	cout << endl; 		
	cout << comun.ToString() << endl; 
	cout << endl; 
	
	
	// Construir la tabla rectangular restante
	
	TablaRectangularReales resto = tabla.ExtraeTablaRectangularResto ();
	
	// Mostrar los datos calculados
	
	cout << endl; 			
	cout << "Tabla rectangular resto: " << endl;
	cout << endl; 		
	cout << resto.ToString() << endl; 
	cout << endl; 
	
	return 0;
}
