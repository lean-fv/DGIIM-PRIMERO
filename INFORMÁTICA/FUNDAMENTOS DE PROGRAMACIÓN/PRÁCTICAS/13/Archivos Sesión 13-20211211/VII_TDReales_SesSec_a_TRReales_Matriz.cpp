/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 7
//
/*	 
	Programa que crea una matriz rectangular de valores reales a partir de 
	una tabla dentada, usando los valores que están presentes en la mayor 
	tabla rectangular que puede formarse con la tabla dentada. 
	
	La tabla rectangular tendrá tantas filas como la tabla dentada, y tantas 
	columnas como columnas tenga la fila "más corta" de la tabla dentada. 
	
	.........................................................................
	
	Por ejemplo, a partir la tabla dentada: 
	
		 7   9  12  15   6  77	9  88  99
		 8   6   7  10
		99  12   8   5  33   1
	
	obtendremos la tabla rectangular: 
	
		 7   9  12  15
		 8   6   7  10
		99  12   8   5
		
	También crea otra matriz rectangular de valores enteros positivos 
	a partir de una tabla dentada, usando los valores restantes, los 
	que no están presentes en la mayor tabla rectangular que puede 
	formarse con la tabla dentada. Los "huecos" los rellena con ceros.
	
	La tabla rectangular tendrá tantas filas como la tabla dentada, y tantas 
	columnas como columnas tenga la fila "más larga" de la tabla dentada, 
	restando el número de columnas comunes. 
	
	Por ejemplo, a partir la tabla dentada: 
	
		 7   9  12  15   6  77	9  88  99
		 8   6   7  10
		99  12   8   5  33   1
	
	obtendremos la tabla rectangular: 		
		
		 6    77     9    88    99
		 0     0     0     0     0
		33     1     0     0     0
		
	Explicación:
	
		 7   9  12  15  ||	6    77     9    88    99
		 8   6   7  10  ||	0     0     0     0     0
		99  12   8   5  || 33     1     0     0     0		
	
		PARTE COMÚN     ||    PARTE NO COMÚN
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

	static const int TAMANIO = 50; // Número de casillas disponibles
	double vector_privado[TAMANIO];
	
	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;	// Número de casillas ocupadas

public:
	
	/***********************************************************************/
	// Constructor sin argumentos

	SecuenciaReales (void) 
	{
		total_utilizados = 0;
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
	// "Vacía" una secuencia
		
	void EliminaTodos (void) 
	{
		total_utilizados = 0;
	}
			
	/***********************************************************************/
	// Eliminar el dato de la posición dada por "indice".
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
    
			for (int i = indice ; i < tope ; i++)
				vector_privado[i] = vector_privado[i+1];  
    
			total_utilizados--;    
		}
	}
	
	/***********************************************************************/
	// Devuelve true si la secuencia está vacía

	bool EstaVacia (void) 
	{
		return (total_utilizados == 0);
	}
	

    /***********************************************************************/
    // Compone un string con todos los valores que están
    // almacenados en la secuencia y lo devuelve.

    string ToString()
    {
        string cadena = "{";

		if (total_utilizados > 0) {

	        for (int i=0; i<total_utilizados-1; i++)
	        	cadena = cadena + to_string(vector_privado[i])+", ";

			// Añadie el último seguido de '}'
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
// Tabla rectangular de reales

class TablaRectangularReales
{

private:

    static const int NUM_FILS = 50; // Filas disponibles
    static const int NUM_COLS = 40; // Columnas disponibles
    
    double  matriz_privada[NUM_FILS][NUM_COLS];

    // PRE: 0 <= filas_utilizadas <= NUM_FILS
    // PRE: 0 <= col_utilizadas < NUM_COLS
    
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
	// Constructor--> Recibe "numero_de_columnas" que indica el número de 
	// columnas que deben tener TODAS las filas. 
	// PRE: numero_de_columnas <= MAX_COL

	TablaRectangularReales (int numero_de_columnas)
		: filas_utilizadas(0), 
		  cols_utilizadas(numero_de_columnas)
	{
	}

	/***********************************************************************/
	// Constructor--> Recibe una secuencia de reales.  El número de 
	// elementos de la secuencia es el valor que se usa como "col_utilizadas"
	// PRE: primera_fila.TotalUtilizados() <= MAX_COL

	TablaRectangularReales (SecuenciaReales primera_fila)
		: filas_utilizadas(0), 
		  cols_utilizadas (primera_fila.TotalUtilizados())
	{
		Aniade(primera_fila); // Actualiza "filas_utilizadas"
	}


	/***********************************************************************/
	// Método de lectura: número máximo de filas

	int CapacidadFilas (void)
	{
		return (NUM_FILS);
	}

	/***********************************************************************/
	// Método de lectura: número máximo de columnas

	int CapacidadColumnas (void)
	{
		return (NUM_COLS);
	}

	/***********************************************************************/
	// Método de lectura: número real de filas usadas

	int FilasUtilizadas (void)
	{
		return (filas_utilizadas);
	}

	/***********************************************************************/
	// Método de lectura: número real de columnas usadas

	int ColumnasUtilizadas (void)
	{
		return (cols_utilizadas);
	}

	/***********************************************************************/
	// Método de lectura: devuelve el dato que ocupa la casilla 
	// de coordenadas (fila, columna)
	// PRE: 0 <= fila < filas_utilizadas
	// PRE: 0 <= columna < cols_utilizadas	
	
	double Elemento (int fila, int columna)
	{
		return (matriz_privada[fila][columna]);
	}

	/***********************************************************************/
	// Devuelve true si la tabla está vacía

	bool EstaVacia (void)
	{
		return (filas_utilizadas == 0);
	}
	
	/*****************************************************************/
	// Devuelve una fila completa (un objeto "SecuenciaReales")
	// PRE: 0 <= indice_fila < filas_utilizadas
	
	SecuenciaReales Fila (int indice_fila)
	{
		SecuenciaReales fila;

		for (int col=0; col<cols_utilizadas; col++)
			fila.Aniade(matriz_privada[indice_fila][col]);

		return (fila);
	}

	/***********************************************************************/
	// Devuelve una columna completa (un objeto "SecuenciaReales")
	// PRE: 0 <= indice_columna < cols_utilizadas
	
	SecuenciaReales Columna (int indice_columna)
	{
		SecuenciaReales columna;

		for (int fil=0; fil<filas_utilizadas; fil++)
			columna.Aniade (matriz_privada[fil][indice_columna]);

		return (columna);
	}

	/***********************************************************************/
	// Añade una fila completa (un objeto "SecuenciaReales")
	// PRE:  fila_nueva.TotalUtilizados() = cols_utilizadas
	// PRE:  filas_utilizadas < MAX_FIL
	
	void Aniade (SecuenciaReales fila_nueva)
	{
		int numero_columnas_fila_nueva = fila_nueva.TotalUtilizados();
					
		if ((filas_utilizadas < NUM_FILS) &&
			(numero_columnas_fila_nueva == cols_utilizadas)) {

			for (int col = 0; col < numero_columnas_fila_nueva; col++)
				matriz_privada[filas_utilizadas][col]=fila_nueva.Elemento(col);

			filas_utilizadas++;
		}
	}

	/***********************************************************************/
	// "Vacía" una tabla

	void EliminaTodos (void)
	{
		filas_utilizadas = 0;
	}
	
	/***********************************************************************/
	// Calcula si dos matrices rectangulares son iguales
	// Compara la tabla implícita con "otra" (tabla explícita) 

	bool EsIgual (TablaRectangularReales otra_tabla)
	{
		bool son_iguales = true; 
		
		if ((filas_utilizadas != otra_tabla.FilasUtilizadas()) || 
			 (cols_utilizadas != otra_tabla.ColumnasUtilizadas()))		
			
			son_iguales = false;
		
		else {
			
			int f=0; 
			
			while (f<filas_utilizadas && son_iguales) {
				
				int c=0; 
				
				while (c<cols_utilizadas && son_iguales) {
			
					if (matriz_privada[f][c] != otra_tabla.Elemento(f,c)) 
						son_iguales = false;
						
					c++;
					
				} // while c
	
				f++;
					
			} // while f
					
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
	    TablaRectangularReales traspuesta; // Inicialmente vacía
		
		if ((filas_utilizadas <= NUM_COLS) && (cols_utilizadas  <= NUM_FILS)) {
		
			// La traspuesta tiene tantas filas como columnas tiene la
			// matriz original
	
			TablaRectangularReales solucion (filas_utilizadas);
	
	
			SecuenciaReales columna; // Las filas de "traspuesta" serán las
									 // columnas de la tabla implícita
	
			for (int col = 0; col < cols_utilizadas; col++){
	
				columna = Columna(col);
				solucion.Aniade(columna);
			}
			
			traspuesta = solucion;
		} 

		return (traspuesta);
	}			
	

	/***********************************************************************/
	// Calcula si una matriz es simétrica.
	// CONDICIÓN NECESARIA: debe ser cuadrada. 
	// Este método comprueba directamente si cada componente es igual a
	// su simétrica, parando el recorrido cuando encuentre una componente
	// que no lo verifique.
	//
	// Evita el cálculo de la traspuesta, y el problema que puede surgir
	// si no se puede calcular la traspuesta de la matriz por problemas de
	// capacidad.

	bool EsSimetrica (void)
	{
		bool es_simetrica = true;

		// Si el número de filas y columnas no coinciden, no hay que seguir
		// porque la matriz no es simétrica.

		es_simetrica = (filas_utilizadas == cols_utilizadas);

		if (es_simetrica) {

			int f=0;

			while (f<filas_utilizadas && es_simetrica) {

				int c=0;

				while (c<cols_utilizadas && es_simetrica) {

					if (matriz_privada[f][c] != matriz_privada[c][f])
						es_simetrica = false;

					c++;

				} // while c

				f++;

			} // while f

		} // if (es_simetrica)

		return (es_simetrica);
	}
					
	/***********************************************************************/
	// Inserta una fila completa en una posición dada. 
	// La fila se porporciona en un objeto "SecuenciaReales".
	// 
	// Recibe: num_fila, la posición que ocupará "fila_nueva" cuando se 
	//		 		inserte en la tabla.
	//		   fila_nueva, la secuencia que se va a insertar. Se trata 
	//				de un objeto de la clase "SecuenciaReales". 
	//
	// PRE:  fila_nueva.TotalUtilizados() = cols_utilizadas
	// PRE:  filas_utilizadas < MAX_FIL
	// PRE:  0 <= num_fila <= TotalUtilizados()
	//		 Si num_fila = 0, "nueva_fila" será la nueva primera fila. 
	//		 Si num_fila = TotalUtilizados(), "nueva_fila" será la nueva 
	//		 última fila (el resultado será equivalente al de "Aniade()" 
	
	void Inserta (int num_fila, SecuenciaReales fila_nueva)
	{
		int numero_columnas_fila_nueva = fila_nueva.TotalUtilizados();
					
		// Comprobar precondiciones
		
		if ((filas_utilizadas < NUM_FILS) &&
			(numero_columnas_fila_nueva == cols_utilizadas) && 
			(0<=num_fila) && (num_fila <=filas_utilizadas)) {

			// "Desplazar" las filas hacia posiciones altas. 
			// La última fila se copia en una NUEVA FILA que ocupa la 
			// posición "filas_utilizadas", la penúltima se copia en 
			// "filas_utilizadas"-1, ... y se queda un "hueco" en 
			// la fila "num_fila ".
			// NOTA: no se modifica (todavía) "filas_utilizadas" 
			
			for (int fil=filas_utilizadas; fil>num_fila; fil--) {
				
				for (int col = 0; col < numero_columnas_fila_nueva; col++)
					matriz_privada[fil][col]=matriz_privada[fil-1][col];
			}
			
			// Copiar en el "hueco" (fila "num_fila") el contenido de 
			// la secuencia "fila_nueva"
			
			for (int col = 0; col < numero_columnas_fila_nueva; col++)
				matriz_privada[num_fila][col]=fila_nueva.Elemento(col);	
			
			filas_utilizadas++; // Actualización del tamaño de la tabla.
		}
	}

	/***********************************************************************/
	// Elimina una fila completa, dada una posición. 
	// 
	// Recibe: num_fila, la posición de la fila a eliminar.
	// PRE:  0 <= num_fila < TotalUtilizados()
	
	void Elimina (int num_fila)
	{		
		// Comprobar precondiciones
		
		if ((0<=num_fila) && (num_fila <=filas_utilizadas)) {

			// "Desplazar" las filas hacia posiciones bajas. 
			// En la posición "num_fila" se copia la que está en la posición
			// siguiente ("num_fila"+1), en su lugar se copia que está en 
			// "num_fila"+2, ... y en la posición "total_utilizados"-2 se 
			// copia la de "total_utilizados"-1. 
			
			for (int fil=num_fila; fil<filas_utilizadas-1; fil++) {
			
				int num_columnas = cols_utilizadas;
					
				for (int c=0; c<num_columnas; c++) 
					matriz_privada[fil][c]=matriz_privada[fil+1][c];
			}
			
			filas_utilizadas--; // Actualización del tamaño de la tabla.
		}
	}	
	
	/***********************************************************************/
	// Devuelve TRUE si la matriz contiene el valor "buscado"
	
	bool Contiene (int buscado)
	{
		bool encontrado = false;

		// Recorrido por columnas 

		int col = 0;

		while (col < cols_utilizadas && !encontrado) {

			int fil=0;

			while (fil < filas_utilizadas && !encontrado) {

				if (matriz_privada[fil][col] == buscado)
					encontrado = true;
				
				fil++;

			} // while fil

			col++; 

		} // while col

		return (encontrado);
	}
		
	/***********************************************************************/
	// Compone y devuelve un string con el contenido de la matriz
	
	string ToString ()
	{
		string cad; 
		
		for (int fila=0; fila<filas_utilizadas; fila++) {
			
			for (int col=0; col<cols_utilizadas; col++) {
			
				cad = cad + "\t" + 
				      to_string(matriz_privada[fila][col]);  
			}
			cad = cad + "\n";
		}
		
		return (cad);
	}
	
	/***********************************************************************/

};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// Tabla dentada de datos double
//
// Representación: Secuencias de "SecuenciaReales"

class TablaDentadaReales {
	
private:
	

private:

	static const int TAMANIO = 100; // Número de casillas disponibles
	SecuenciaReales vector_privado[TAMANIO];
	
	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;	// Número de casillas ocupadas
	
public:
	
	/***********************************************************************/
	// Constructor sin argumentos

	TablaDentadaReales (void) 	
	{
		total_utilizados = 0;
	}

	/***********************************************************************/
	// Constructor con un argumento "SecuenciaReales"

	TablaDentadaReales (SecuenciaReales la_secuencia) 	
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
		return (SecuenciaReales().Capacidad());
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

	SecuenciaReales Fila (int indice_fila)
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

	void Aniade (SecuenciaReales una_secuencia)
	{
		if (total_utilizados < TAMANIO) {

			vector_privado[total_utilizados]=una_secuencia;			
			total_utilizados++;
		}
	}
	
	/*****************************************************************/
	// Inserta una fila completa en una posición dada. 
	// La fila se porporciona en un objeto "SecuenciaReales".
	// 
	// Recibe: num_fila, la posición que ocupará "fila_nueva" cuando se 
	//		 		inserte en la tabla.
	//		   fila_nueva, la secuencia que se va a insertar. Se trata 
	//				de un objeto de la clase SecuenciaReales. 
	//
	// PRE:  filas_utilizadas < TAMANIO
	// PRE:  0 <= num_fila <= TotalUtilizados()
	//		 Si num_fila = 0, "nueva_fila" será la nueva primera fila. 
	//		 Si num_fila = TotalUtilizados(), "nueva_fila" será la nueva 
	//		 última fila (el resultado será equivalente al de "Aniade()" 
	
	void Inserta (int num_fila, SecuenciaReales fila_nueva)
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

	bool EsIgual (TablaDentadaReales otra)
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
	
	/***********************************************************************/
	// Compone y devuelve un string con el contenido de la matriz
	
	string ToString ()
	{
		string cad; 
		
		for (int fila=0; fila<FilasUtilizadas(); fila++) {
			SecuenciaReales la_secuencia = Fila(fila);
			cad = cad + "\t" + la_secuencia.ToString() + "\n";
		}
		
		return (cad);
	}
	
	/***********************************************************************/
		
	TablaRectangularReales ExtraeTablaRectangularComun	(void)
	{
		// Calcular el mínimo número de columnas (es el número de columnas 
		// de la fila "más corta")
		
		SecuenciaReales una_fila;
		
		una_fila = Fila(0);
		int min_num_cols = una_fila.TotalUtilizados();
		
		int num_filas = total_utilizados;
		
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
		// Calcular el máximo número de columnas (es el número de columnas 
		// de la fila "más larga")
		
		int min_num_cols, max_num_cols;
		
		SecuenciaReales fila_leida;	
			
		fila_leida = Fila(0);		
		min_num_cols = max_num_cols= fila_leida.TotalUtilizados();
		
		int num_filas = total_utilizados;
		
		
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
			

/***************************************************************************/
// Rellena la matriz a discreción.
/*
	En este caso: 
		 7   9  12  15   6  77	9  88 99
		 8   6   7  10
		99  12   8   5  33   1
*/

TablaDentadaReales Inicia_matriz (void)
{
	// Añadir datos a la primera fila
	
	SecuenciaReales una_fila; 
	
	una_fila.Aniade (7);  una_fila.Aniade (9);  una_fila.Aniade (12); 
	una_fila.Aniade (15); una_fila.Aniade (6);  una_fila.Aniade (77); 
	una_fila.Aniade (9);  una_fila.Aniade (88); una_fila.Aniade (99); 
		
	// Crear la tabla a partir de la primera fila
	
	TablaDentadaReales matriz (una_fila);

	// Vaciar la secuencia, y añadir una nueva fila a "matriz" 
	
	una_fila.EliminaTodos();	// Para poder utilizarse posteriormente
		
	una_fila.Aniade (8);  una_fila.Aniade (6);  una_fila.Aniade (7); 
	una_fila.Aniade (10); 
	matriz.Aniade (una_fila);
		
	// Vaciar la secuencia, y añadir una nueva fila a "matriz" 
		
	una_fila.EliminaTodos();	// Para poder utilizarse posteriormente
	
	una_fila.Aniade (99); una_fila.Aniade (12); una_fila.Aniade (8); 
	una_fila.Aniade (5);  una_fila.Aniade (33);  una_fila.Aniade (1); 
	matriz.Aniade (una_fila);	

	return (matriz);
}

/***************************************************************************/

int main (void)
{
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 


	// La "TablaDentadaReales" que se va a formar. 
	TablaDentadaReales tabla = Inicia_matriz();


	// Mostrar contenido de "tabla"
	
	cout << endl; 			
	cout << "Tabla creada: " << endl;
	cout << endl; 		
	cout << tabla.ToString() << endl; 
	cout << endl; 
	
	
	// Construir la tabla rectangular común
	
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
