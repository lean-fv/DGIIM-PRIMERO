/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 7
//
/*	
	TABLA RECTANGULAR - SECUENCIA DE SECUENCIAS

	Este programa presenta la clase TablaRectangularEnteros.
	Se emplea como dato miembro privado una secuencia de secuencias 
	de enteros, con la restricci�n de que todas las secuencias tienen 
	el mismo tama�o. 
	
	Este programa calcula si existe un valor MaxiMin en una tabla 
	rectangular de enteros: aquel que es a la vez m�ximo de su fila y 
	m�nimo de su columna.
	Si lo encuentra, muestra su valor y su posici�n.  
*/
/*********************************************************************/


#include <iostream>
#include <iomanip>
using namespace std;


///////////////////////////////////////////////////////////////////////

class SecuenciaEnteros  
{

private:

	static const int TAMANIO = 40; // N�mero de casillas disponibles
	int vector_privado[TAMANIO];
	
	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;	// N�mero de casillas ocupadas

public:
	
	/***********************************************************************/
	// Constructor sin argumentos

	SecuenciaEnteros (void) 
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

	void Aniade (int nuevo)
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

	int Elemento (int indice)
	{
		return vector_privado[indice];
	}

	/***********************************************************************/
	// Devuelve true si la secuencia est� vac�a

	bool EstaVacia (void)
	{
		return (total_utilizados == 0);
	}

	/***********************************************************************/
	// "Vac�a" una secuencia

	void EliminaTodos (void)
	{
		total_utilizados = 0;
	}
	
	/***********************************************************************/
	// FIN METODOS BASICOS
	/***********************************************************************/
	
	/***********************************************************************/
	// B�squeda de un valor en la secuencia, entre dos posiciones dadas. 
	// Realiza una b�squeda secuencial
	//
	// Recibe: 	buscado, el valor a buscar en la secuencia.
	//			izda y dcha, posiciones entre las que se realiza la b�squeda.
	// Devuelve: la posici�n del elemento "buscado", si est� en la secuencia,
	//			 o -1, si no lo encuentra.
	// PRE: 0 <= izda <= dcha < total_utilizados

	int Posicion (int buscado, int izda, int dcha)
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
	// Devuelve la posici�n del m�nimo valor de la secuencia
	//
	// PRE: 0 <= izda <= dcha < total_utilizados
	
	int PosicionMinimo (int izda, int dcha)
	{
		int posicion_minimo;
		int minimo;
	
		minimo = vector_privado[izda];
		posicion_minimo = izda;
		
		for (int i = izda; i <= dcha ; i++) { 
			
			if (vector_privado[i] < minimo){
				minimo = vector_privado[i];
				posicion_minimo = i;
			}
		}
		
		return (posicion_minimo);		
	}
	
	/***********************************************************************/
	// Devuelve la posici�n del m�ximo valor de la secuencia
	//
	// PRE: 0 <= izda <= dcha < total_utilizados
	
	int PosicionMaximo (int izda, int dcha)
	{
		int posicion_maximo;
		int maximo;
	
		maximo = vector_privado[izda];
		posicion_maximo = izda;
		
		for (int i = izda; i <= dcha ; i++) { 
			
			if (vector_privado[i] > maximo){
				maximo = vector_privado[i];
				posicion_maximo = i;
			}
		}
		
		return (posicion_maximo);		
	}
	
	/***********************************************************************/
	// Devuelve el m�nimo de la secuencia. 
	//
	// PRE: 0 <= izda <= dcha < total_utilizados

	int Minimo (int izda, int dcha)
	{
		return (vector_privado[PosicionMinimo(izda, dcha)]);
	}


	/***********************************************************************/
	// Devuelve el m�ximo de la secuencia. 
	//
	// PRE: 0 <= izda <= dcha < total_utilizados

	int Maximo (int izda, int dcha)
	{
		return (vector_privado[PosicionMaximo(izda, dcha)]);
	}
	
	/***********************************************************************/
	// Devuelve una secuencia incluida en la secuencia impl�cita, que empieza 
	// en la posici�n "pos_init" y tiene "num_datos" valores
	//
	// Recibe: pos_init, posici�n inicial desde donde empieza la copia a la 
	//					 subsecuencia. 
	//		   num_datos, n�mero de valores que se copian a la subsecuencia. 
	// Devuelve: una subsecuencia de la secuencia impl�cita. 
	// 
	// Casos: 1) Si 0 <= pos_init < total_utilizados Y 
	//			 pos_init+num_datos<=total_utilizados
	//			 se devuelve una subsecuencia de tama�o "num_datos"
	//		  2) Si 0 <= pos_init < total_utilizados Y 
	//			 pos_init+num_datos>total_utilizados, se devuelve una 
	//			 subsecuencia de tama�o total_utilizados-pos_init
	//		  3) Si pos_init < 0 � pos_init >= total_utilizados, 
	//			 se devuelve una subsecuencia vac�a.
	//		  4) Si num_datos = 0, se devuelve una subsecuencia vac�a.

	SecuenciaEnteros Subsecuencia (int pos_init, int num_datos)
	{
		SecuenciaEnteros a_devolver; // inicialmente vac�a
		
		if ((pos_init>=0) && (pos_init<total_utilizados) && (num_datos>0)) {
			
			int pos_end;
			
			if (pos_init+num_datos>total_utilizados) 
				pos_end = total_utilizados;
			else 
				pos_end = pos_init+num_datos;
			
			for (int pos=pos_init; pos<pos_end; pos++)
				a_devolver.Aniade(vector_privado[pos]);
		}
		
		return (a_devolver);
	}
		
	/***********************************************************************/
	// COMPARACI�N
	/***********************************************************************/
				
	/***********************************************************************/
	// Compara dos secuencias
	
	bool EsIgual (SecuenciaEnteros otra_secuencia) 
	{
		bool son_iguales = true; 
		
		if (total_utilizados != otra_secuencia.total_utilizados)
		
			son_iguales = false;
		
		else {
				
			bool sigo = true;
			int pos = 0;
			
			while (sigo && (pos < total_utilizados)) {
	
				if (vector_privado[pos]!=otra_secuencia.vector_privado[pos]) {
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

};

/////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
// El tipo de dato PosicionEnMatriz se emplea para guardar posiciones 	
// dentro de una matriz: se registra la pareja (fila, columna)
	
struct PosicionEnMatriz {
	int fila;
	int columna;
};

/////////////////////////////////////////////////////////////////////////////
// La clase "SecuenciaPosicionEnMatriz" es �til para representar una secuencia
// de  posiciones (coordenadas) en una tabla bidimensional.	
	
class SecuenciaPosicionEnMatriz
{
private:

	static const int TAMANIO = 50; // N�mero de casillas disponibles
	PosicionEnMatriz vector_privado[TAMANIO];
	
	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;	// N�mero de casillas ocupadas

public: 
	
	/***********************************************************************/
	// Constructor sin argumentos

	SecuenciaPosicionEnMatriz (void) 
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

	void Aniade (PosicionEnMatriz nuevo)
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

	PosicionEnMatriz Elemento (int indice)
	{
		return vector_privado[indice];
	}
	
	/***********************************************************************/
};

/////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////////
// Tabla rectangular de enteros

class TablaRectangularEnteros
{

private:

    static const int MAX_FIL = 50; // "filas" disponibles
    static const int MAX_COL = 40;

    SecuenciaEnteros vector_privado[MAX_FIL];

    // PRE: 0 <= filas_utilizadas <= MAX_FIL
    // PRE: 0 <= cols_utilizadas <= MAX_COL
    
    int filas_utilizadas;
    int cols_utilizadas;

public:
	
	
	/***********************************************************************/
	// Constructor sin argumentos--> Crea matriz nula

	TablaRectangularEnteros(void): filas_utilizadas(0),cols_utilizadas(0) { }

	/***********************************************************************/
	// Constructor--> Recibe "numero_de_columnas" que indica el n�mero de 
	// columnas que deben tener TODAS las filas. 
	// PRE: numero_de_columnas <= MAX_COL


	TablaRectangularEnteros (int numero_de_columnas)
		: filas_utilizadas(0), cols_utilizadas(numero_de_columnas)
	{ }

	/***********************************************************************/
	// Constructor--> Recibe una secuencia de enteros.  El n�mero de 
	// elementos de la secuencia es el valor que se usa como "col_utilizadas"
	// PRE: primera_fila.TotalUtilizados() <= MAX_COL

	TablaRectangularEnteros (SecuenciaEnteros primera_fila)
		: filas_utilizadas(0), cols_utilizadas (primera_fila.TotalUtilizados())
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
	// Devuelve una fila completa (un objeto "SecuenciaEnteros")
	// PRE: 0 <= indice_fila < filas_utilizadas
	
	SecuenciaEnteros Fila (int indice_fila)
	{
		return (vector_privado[indice_fila]);
	}

	/*****************************************************************/
	// Devuelve una columna completa (un objeto "SecuenciaEnteros")
	// PRE: 0 <= indice_columna < cols_utilizadas
	
	SecuenciaEnteros Columna (int indice_columna)
	{
		SecuenciaEnteros columna;

		for (int fil=0; fil<filas_utilizadas; fil++)
			columna.Aniade ((vector_privado[fil]).Elemento(indice_columna));

		return (columna);
	}

	/***********************************************************************/
	// A�ade una fila completa (un objeto "SecuenciaEnteros")
	// PRE:  fila_nueva.TotalUtilizados() = cols_utilizadas
	// PRE:  filas_utilizadas < MAX_FIL
	
	void Aniade (SecuenciaEnteros fila_nueva)
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

	bool EsIgual (TablaRectangularEnteros otra)
	{
		bool son_iguales = true; 
		
		if ((filas_utilizadas != otra.FilasUtilizadas()) ||  
			 (cols_utilizadas != otra.ColumnasUtilizadas()))		
			
			son_iguales = false;
		
		else {
			
			// Recorrido por filas 
	
			int fil = 0;
			
			while (fil < filas_utilizadas && !son_iguales) {
	
				SecuenciaEnteros una_fila = Fila (fil);
				SecuenciaEnteros otra_fila = otra.Fila (fil);	
				
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
	
	TablaRectangularEnteros Traspuesta (void)
	{
	    TablaRectangularEnteros traspuesta; // Inicialmente vac�a
			    
		if ((filas_utilizadas <= MAX_COL) && (cols_utilizadas <= MAX_FIL)) {
		
			// La traspuesta tiene tantas filas como columnas tiene la 
			// matriz original

			TablaRectangularEnteros solucion (filas_utilizadas);


			SecuenciaEnteros columna; // Las filas de "traspuesta" ser�n las 
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
	// La fila se porporciona en un objeto "SecuenciaEnteros".
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
	
	void Inserta (int num_fila, SecuenciaEnteros fila_nueva)
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

		// Recorrido por filas 

		int fil = 0;

		while (fil < filas_utilizadas  && !encontrado) {

			SecuenciaEnteros una_fila = Fila (fil);
			
			int pos_buscado = una_fila.Posicion(buscado,0,cols_utilizadas-1);

			if (pos_buscado != -1) 
				encontrado = true;
			else 
				fil++; 

		} // while fil

		return (encontrado);
	}
		
	/*****************************************************************/
	// Encontrar un dato en la matriz y devolver su posici�n.
	// El valor devuelto contiene informaci�n acerca de la posici�n 
	// (fila y columna) de "buscado".  
	// 		En el caso de que no est� contendr� {-1,-1}. 
	// La consulta de la fila y la columna se delega en los m�todos de 
	// la clase "PosicionEnMatriz" 

	PosicionEnMatriz PrimeraOcurrencia (int buscado)
	{
		PosicionEnMatriz posicion_dato_buscado = {-1,-1};
      
		bool encontrado = false;

		// Recorrido por filas 

		int fil = 0;
		
		while (fil < filas_utilizadas && !encontrado) {

			SecuenciaEnteros una_fila = Fila (fil);
			
			int pos_buscado = una_fila.Posicion(buscado,0,cols_utilizadas-1);

			if (pos_buscado != -1) {
				encontrado = true;
				posicion_dato_buscado.fila = fil;
				posicion_dato_buscado.columna = pos_buscado;		
			}
			else 
				fil++; 

		} 
      
		return (posicion_dato_buscado);
	} 

	/***********************************************************************/
	// Devuelve true si la tabla est� vac�a

	bool EstaVacia (void) 
	{
		return (filas_utilizadas == 0);
	}		

	/***********************************************************************/
			
};

/////////////////////////////////////////////////////////////////////////////


/***************************************************************************/

int main (void)
{
	// A�adir datos a la primera fila
	
	SecuenciaEnteros una_fila; 
	
	una_fila.Aniade (9); una_fila.Aniade (7);	
	una_fila.Aniade (4); una_fila.Aniade (5);

	// Crear la tabla a partir de la primera fila
	
	TablaRectangularEnteros matriz (una_fila);

	// Vaciar la secuencia, y a�adir una nueva fila a "matriz" 
	
	una_fila.EliminaTodos();	// Para poder utilizarse posteriormente
		
	una_fila.Aniade (2); una_fila.Aniade (18);	
	una_fila.Aniade (2); una_fila.Aniade (12);
	matriz.Aniade (una_fila);
		
	// Vaciar la secuencia, y a�adir una nueva fila a "matriz" 
		
	una_fila.EliminaTodos();	// Para poder utilizarse posteriormente
	
	una_fila.Aniade (1); una_fila.Aniade (4);	
	una_fila.Aniade (3); una_fila.Aniade (2);
	matriz.Aniade (una_fila);

	una_fila.EliminaTodos(); 	// Para poder utilizarse posteriormente
	
	
	// Guardar el n�mero de filas y columnas de "matriz"
	
	int num_filas_matriz = matriz.FilasUtilizadas();
	int num_cols_matriz  = matriz.ColumnasUtilizadas();
	
	
	/***********************************************************************/
	// Mostrar los datos de la matriz
	
	cout << endl;
	cout << "Matriz orginal: " << endl;	
	cout << endl;
		
	for (int f=0; f<num_filas_matriz; f++) {

		for (int c=0; c<num_cols_matriz; c++) {
			cout << setw (3) << matriz.Elemento(f,c);	
		}
		cout << endl;
	}
	cout << endl;



	/***********************************************************************/
	// Calcular si existe un elemento MaxiMin, es decir, que sea a la vez 
	// m�ximo de su fila y m�nimo de su columna.
	
	// Calcular los m�ximos (por filas) y guardarlos, junto a sus posiciones 
	
	SecuenciaEnteros maximos_fila;
	SecuenciaPosicionEnMatriz posiciones_maximos_fila;
	
	for (int f=0; f<num_filas_matriz; f++) {
		
		// Extraer una copia de la fila "f"
		
		una_fila = matriz.Fila(f);
		
		// Calcular el m�nimo de "una_fila"
		
		int pos_max = una_fila.PosicionMaximo(0, num_cols_matriz-1);	
		int max = una_fila.Elemento(pos_max);

		PosicionEnMatriz pos_max_fila_en_matriz;	
		
		// Guardar el m�nimo y su posici�n 
			
		maximos_fila.Aniade(max); // Guardar el valor del m�nimo de la fila

		// Guardar la posici�n que ocupa en la matriz.

		pos_max_fila_en_matriz.fila = f;
		pos_max_fila_en_matriz.columna = pos_max;
		posiciones_maximos_fila.Aniade(pos_max_fila_en_matriz); 
	}
	int num_elem_maximos_fila = maximos_fila.TotalUtilizados();
	int num_elem_pos_maximos_fila = posiciones_maximos_fila.TotalUtilizados();


	cout << "Maximos por fila = " << endl;  	 	
	for (int pos=0; pos<num_elem_maximos_fila; pos++) 		
		cout << "\tFila " << pos << " = " <<setw(3)<< maximos_fila.Elemento(pos)
			 << " Posicion = (" 
			 << (posiciones_maximos_fila.Elemento(pos)).fila
			 << ", " 
			 << (posiciones_maximos_fila.Elemento(pos)).columna 
			 << ")" << endl;
	cout << endl; 

	
	// Calcular los m�nimos (por columnas) y guardarlos, junto a sus posiciones 
	
	SecuenciaEnteros minimos_col;
	SecuenciaPosicionEnMatriz posiciones_minimos_col;
	
	SecuenciaEnteros una_columna; 
		
	for (int c=0; c<num_cols_matriz; c++) {
		
		// Extraer una copia de la columna "c"
		
		una_columna = matriz.Columna(c);
		
		// Calcular el m�nimo de "una_columna"
		
		int pos_min = una_columna.PosicionMinimo(0, num_filas_matriz-1);	
		int min = una_columna.Elemento(pos_min);
			
		PosicionEnMatriz pos_min_col_en_matriz;	
						
		// Guardar el m�nimo y su posici�n 
			
		minimos_col.Aniade(min); // Guardar el valor del m�nimo de la columna

		// Guardar la posici�n que ocupa en la matriz.

		pos_min_col_en_matriz.fila = pos_min;
		pos_min_col_en_matriz.columna = c;
		posiciones_minimos_col.Aniade(pos_min_col_en_matriz); 
	}
	int num_elem_minimos_col = minimos_col.TotalUtilizados();
	int num_elem_pos_minimos_col = posiciones_minimos_col.TotalUtilizados();
	

	cout << "Minimos por columna = " << endl;  	
	for (int pos=0; pos<num_elem_minimos_col; pos++) 		
		cout << "\tColumna " <<pos<<" = "<<setw(3)<<minimos_col.Elemento(pos)
			 << " Posicion = (" 
			 << (posiciones_minimos_col.Elemento(pos)).fila
			 << ", " 
			 << (posiciones_minimos_col.Elemento(pos)).columna 
			 << ")" << endl;
	cout << endl; 

	
	// Calcular si existe MaxiMin
	// Ya hemos calculado los m�ximos (por filas) y sabemos sus posiciones. 
	// Tambi�n tenemos los m�nimos (por columnas) y sus posiciones. 
		
	int MaxiMin;	
	PosicionEnMatriz posicion_MaxiMin;
			
	int fila = 0;
	bool encontrado_MaxiMin = false; // Para terminar la b�squeda 
	
	while ((fila < num_elem_maximos_fila) && (!encontrado_MaxiMin)) {
		
			// Valor del m�ximo de la fila "fila"
			int valor_del_maximo_fila = maximos_fila.Elemento(fila);
			
			// Columna del m�ximo de la fila "fila"
			int col_del_maximo_fila = 
						(posiciones_maximos_fila.Elemento(fila)).columna;
			
			// El m�ximo de la fila "fila" est� en la posici�n de la matriz: 
			//		(fila, col_del_maximo_fila)
			//
			// Ahora nos interesa la columna donde se ha encontrado el m�ximo. 
			// En realidad, el valor del m�nimo de esa columna, al que llamamos
			// "valor_min_col_del_maximo_fila" (valor del m�nimo de la columna 
			// en la que est� el m�ximo de la fila "fila")
			
			int valor_min_col_del_maximo_fila = 
								minimos_col.Elemento(col_del_maximo_fila);
			
			// Si el m�ximo de la fila coincide con el m�nimo de la columna, 
			// 		hemos encontrado un elemento Maximin--> terminar
			// Si no, continuar con la siguiente fila.
			
			if (valor_del_maximo_fila == valor_min_col_del_maximo_fila) {
				
				encontrado_MaxiMin = true;		
			
				// Valores para la presentaci�n de resultados 	
				posicion_MaxiMin.fila = fila;
				posicion_MaxiMin.columna = col_del_maximo_fila;
			
				MaxiMin = valor_del_maximo_fila;
			}
			else fila++;
	}
	
	if (encontrado_MaxiMin) {
		
		cout << "Existe MaxiMin. " << endl;
		cout << "\tValor = " << MaxiMin << endl;
		cout << "\tPosicion  = (" << posicion_MaxiMin.fila
			 << ", " << posicion_MaxiMin.columna << ")" << endl;	
	}
	else {
		cout << "NO Existe MaxiMin." << endl;		
	}
	cout << endl << endl;

	return 0;
}
/***************************************************************************/
