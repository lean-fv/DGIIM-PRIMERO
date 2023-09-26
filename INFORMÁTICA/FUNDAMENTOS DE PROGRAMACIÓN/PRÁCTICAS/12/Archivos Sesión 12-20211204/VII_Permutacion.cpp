/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 7
//
/*
	Programa que gestiona permutaciones de enteros: colecciones de enteros 
	sin elementos repetidos que coniene TODOS los n�meros entre el m�nimo 
	y el m�ximo de dichos valores.
	Por ejemplo, (2,3,6,5,4) es una permutaci�n correcta, pero no lo es 
	(7,7,6,5) -> el 7 est� repetido, ni tampoco (7,6,4)-> falta el 5.

	La resoluci�n de este programa se realiza usando la clase "Permutacion":

	1) Representaci�n: Usa un vector de enteros como dato miembro privado. 
	2) Ofrece los m�todos:  
	* Permutacion (SecuenciaEnteros una_permutacion);
		Constructor con argumentos. 
		Recibe un dato de la clase "SecuenciaEnteros" con los valores que 
		forman la permutaci�n.
		PRE: Supondremos que la secuencia es una permutaci�n correcta. 
	* int Maximo();
	* int Minimo();
		Devuelve el m�ximo / m�nimo de la permutaci�n. 
		PRE: al menos hay un elemento 
	* int NumeroLecturas (void);
		Calcula el n�mero de lecturas de la permutaci�n. 
		Se dice que una permutaci�n de t elementos C = {n_1,n_2,...,n_t} 
		tiene k lecturas si para leer sus elementos en orden creciente 
		(de izquierda a derecha) hay que recorrer la permutaci�n k veces. 
		P.e., la siguiente permutaci�n del conjunto {0,1,...,8}: 
			4 0 8 1 2 5 3 6 7
		necesita 3 lecturas: en la primera obtendr�amos 0, 1, 2 y 3; en la 
		segunda 4, 5, 6 y 7; finalmente, en la tercera, 8.
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class SecuenciaEnteros 
{

private:

	static const int TAMANIO = 50; // N�mero de casillas disponibles
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
	// Sustituye la componente situada en la posici�n "indice_componente" 
	// por el valor "nuevo".
	//
	// PRE: 0 <= indice < total_utilizados 
	// 		La modificaci�n se realiza si "indice_componente" es correcto. 
	// 		Si no es as�, no se hace nada.	
	
	void Modifica (int indice_componente, int nuevo)
	{
		if ((indice_componente>=0)  &&  (indice_componente<total_utilizados))

			vector_privado[indice_componente] = nuevo;
	}
	
	/***********************************************************************/
	// Devuelve la posici�n del m�nimo valor de la secuencia
	//
	// PRE: total_utilizados > 0
	
	int PosicionMinimo (void)
	{
		int posicion_minimo;
		int minimo;
	
		minimo = vector_privado[0];
		posicion_minimo = 0;
		
		for (int i = 1; i < total_utilizados ; i++) { 
			
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
	// PRE: total_utilizados > 0
	
	int PosicionMaximo (void)
	{
		int posicion_maximo;
		int maximo;
	
		maximo = vector_privado[0];
		posicion_maximo = 0;
		
		for (int i = 1; i < total_utilizados ; i++) { 
			
			if (vector_privado[i] > maximo){
				maximo = vector_privado[i];
				posicion_maximo = i;
			}
		}
		
		return (posicion_maximo);		
	}
	
	/***********************************************************************/
	// Comprueba si la secuencia es una permutaci�n correcta. 
	//
	// PRE: total_utilizados > 0
	
	bool EsPermutacion (void)
	{
		// Calcular el m�nimo y el m�ximo valor de la secuencia
		int minimo = Elemento(PosicionMinimo());
		int maximo = Elemento(PosicionMaximo());

		/* 	
			Si el n�mero de elementos de la secuencia (total_utilizados) no 
			es exactamente "maximo"-"minimo"+"1", faltan valores o hay valores
			repetidos. En este caso ya descartamos que sea una permutacion sin 
			necesidad de hacer m�s comprobaciones.
		*/
		
		bool es_permutacion;

		if (total_utilizados != maximo-minimo+1) 
			es_permutacion = false; 
		else 
			es_permutacion = true; 

		/*
			Comprobar si est�n todos los valores comprendidos entre "minimo" 
			y "maximo". Se termina si no se encuentra alguno (en ese caso 
			la secuencia no es una permutaci�n). Si se encuentran todos los 
			valores entonces la secuencia forma una permutaci�n. 
		*/

		// Sabemos que "minimo" y "maximo" est�n en la secuencia, 
		// evidentemente. La comprobaci�n se har� entonces desde el siguiente 
		// al m�nimo y hasta el anterior al m�ximo. 
		
		int valor_buscado = minimo+1; 

		while ((es_permutacion) && (valor_buscado < maximo)) {
		
			bool encontrado = false;
			int pos = 0; 

			while ((!encontrado) && (pos < total_utilizados)) {

				if (vector_privado[pos] == valor_buscado) 
					encontrado = true; // Ya no es preciso seguir buscando
				else 
					pos++;	// Continuar con la siguiente casilla

			} //while ((!encontrado) && (pos < total_utilizados))

			if (!encontrado) // El valor buscado no est�
				es_permutacion = false;  
			else 			
				valor_buscado++; // Para comprobar el siguiente

		} // while ((es_permutacion) && (valor_buscado <= maximo) 

		return (es_permutacion);
	}
	
	/***********************************************************************/
};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// La clase Permutacion representa una permutaci�n de enteros, es decir, el 
// conjunto de todos los enteros entre un m�nimo y un m�ximo sin repetidos 
// y no necesariamente ordenado.

class Permutacion
{

private:

	// Datos asociados a la estructura de datos empleada para guardar 
	// la permutaci�n (vector enteros)

	static const int TAMANIO = 50; // N�mero de casillas disponibles
	int vector_privado[TAMANIO];
	
	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;	// N�mero de casillas ocupadas

public: 

	/***********************************************************************/
	// Constructor con argumentos
	// Recibe: una_permutacion, un dato de tipo "SecuenciaEnteros". 
	//
	// PRE: Supondremos que "una_permutacion" es una permutaci�n correcta. 
	//		Existe un m�todo de la clase "SeuenciaEnteros" que permite 
	//		comprobar que se cumple esta precondici�n. 
	
	Permutacion (SecuenciaEnteros una_permutacion) 
	{
		int num_elementos_una_permutacion = una_permutacion.TotalUtilizados();
		
		for (int i=0; i<num_elementos_una_permutacion; i++) 
			vector_privado[i] = una_permutacion.Elemento(i);
			
		total_utilizados = num_elementos_una_permutacion;
	}

	/***********************************************************************/
	// Devuelve el n�mero de elementos de la permutaci�n. 

	int NumElementos (void)
	{
		return (total_utilizados);
	}

	/***********************************************************************/
	// Devuelve la posici�n del m�nimo de la permutaci�n. 
	// PRE: total_utilizados > 0 

	int PosMinimo (void)
	{
		int min = vector_privado[0];
		int pos_min = 0; 

		for (int i=1; i<total_utilizados; i++) 
			if (vector_privado[i] < min) {
				min = vector_privado[i];
				pos_min = i; 
			}

		return (pos_min);
	}

	/***********************************************************************/
	// Devuelve el m�nimo de la permutaci�n. 
	// PRE: total_utilizados > 0 

	int Minimo (void)
	{
		return (vector_privado[PosMinimo()]);
	}

	/***********************************************************************/
	// Devuelve la posici�n del m�ximo de la permutaci�n. 
	// PRE: total_utilizados > 0 

	int PosMaximo (void)
	{
		int max = vector_privado[0];
		int pos_max = 0; 

		for (int i=1; i<total_utilizados; i++) 
			if (vector_privado[i] > max) {
				max = vector_privado[i];
				pos_max = i; 
			}

		return (pos_max);
	}


	/***********************************************************************/
	// Devuelve el m�ximo de la permutaci�n. 
	// PRE: al menos hay un elemento 

	int Maximo()
	{
		return (vector_privado[PosMaximo()]);
	}

	/***********************************************************************/
	// Devuelve el elemento de la casilla "indice" 
	// PRE: la posici�n dada por "indice" es correcta.

	int Elemento(int indice)
	{
		return (vector_privado[indice]);
	}

	/***********************************************************************/
	// Calcula el n�mero de lecturas de la permutaci�n

	int NumeroLecturas (void)
	{	
		int num_elementos = NumElementos();
		int contador_lecturas = 1; 
		int pos = 0; 

		// Usaremos un ciclo for porque sabemos exactamente los n�meros 
		// que deben buscarse: Minimo(), Minimo()+1,Minimo()+2,...,Maximo()

		for (int n=Minimo(); n<=Maximo(); n++) {

			bool encontrado = false;

			while (!encontrado) {

				if (vector_privado[pos] == n) 
					encontrado = true; 

				else {
					if (pos==num_elementos-1)	// se ha examinado el �ltimo->
						contador_lecturas++;	// empieza otra lectura.

					pos = (pos+1)%num_elementos; // Incremento de "pos"

					// CLAVE: La operaci�n "% num_elementos" permite que el 
					// siguiente al �ltimo (posici�n = "num_elementos"-1) 
					// sea el primero (posici�n = 0)			
				}

			} //while (!encontrado)

		} // for (int n=Minimo(); n<=Maximo(); n++) 

		return (contador_lecturas); 
	}
	
	/***********************************************************************/
};

///////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

/***************************************************************************/
/***************************************************************************/

int main (void)
{

	const int MAX_LINE = 10; // Mostrar MAX_LINE n�meros por l�nea 

	// Creaci�n y relleno del vector que formar� la permutaci�n

	SecuenciaEnteros v;

	v.Aniade (4);
	v.Aniade (0);
	v.Aniade (8);
	v.Aniade (1);
	v.Aniade (2);
	v.Aniade (5);
	v.Aniade (3);
	v.Aniade (6);   
	v.Aniade (7);
	
	if (!v.EsPermutacion()) {

		cout << "La secuencia NO es una permutacion correcta." << endl; 	
		cout << endl;
	}
	
	else {

		cout << "La secuencia es una permutacion correcta." << endl; 
		cout << endl;
	
	
		// Crear una permutaci�n a partir de v --> Constructor 
	
		Permutacion perm (v);
	
	
		// Consultar cu�ntos elementos tiene la permutaci�n
	
		int tope = perm.NumElementos();
		
		cout << "Se creo una permutacion a partir de una secuencia" << endl;	
		cout << "La permutacion tiene " << tope << " elementos." << endl;
		cout << "Rango: " << perm.Minimo() << " - " << perm.Maximo() << endl;
		cout << endl;
	
	
		// Mostrar los elementos de la permutaci�n
	
		for (int i=0; i<tope; i++) {
	
			char separador;
	
			if ((i+1)%MAX_LINE == 0) 
				separador = '\n';
			else 
				separador = ' ';
			cout << setw(4) << perm.Elemento(i) << separador;
		}
		cout << endl << endl;
	
		// Calcular el n�mero de lecturas 
	
		cout << "La permutacion tiene " << perm.NumeroLecturas() 
			 << " lecturas." << endl;
		cout << endl << endl;

	}
	
	
	// Segundo ejemplo: una permutaci�n ordenada 

	SecuenciaEnteros v_ordenado;

	v_ordenado.Aniade (3);
	v_ordenado.Aniade (4);
	v_ordenado.Aniade (5);
	v_ordenado.Aniade (6);

	// Crear una permutaci�n a partir de v --> Constructor 

	Permutacion perm_ordenada (v_ordenado);


	// Consultar cu�ntos elementos tiene la permutaci�n

	int tope_ordenada = perm_ordenada.NumElementos();

	cout << "Se creo una permutacion ordenada crecientemente" << endl;	
	cout << "La permutacion tiene " << tope_ordenada << " elementos.\n";
	cout << "Rango: " << perm_ordenada.Minimo() 
		 << " - " << perm_ordenada.Maximo() << endl;
	cout << endl;


	// Mostrar los elementos de la permutaci�n

	for (int i=0; i<tope_ordenada; i++) {

		char separador;

		if ((i+1)%MAX_LINE == 0) 
			separador = '\n';
		else 
			separador = ' ';
		cout << setw(4) << perm_ordenada.Elemento(i) << separador;
	}
	cout << endl << endl;

	// Calcular el n�mero de lecturas 

	cout << "La permutacion tiene " << perm_ordenada.NumeroLecturas() 
		 << " lecturas." << endl;
	cout << endl << endl;



	// Tercer ejemplo: una permutaci�n en orden decreciente

	SecuenciaEnteros v_decreciente;

	v_decreciente.Aniade (8);
	v_decreciente.Aniade (7);
	v_decreciente.Aniade (6);
	v_decreciente.Aniade (5);

	// Crear una permutaci�n a partir de v_decreciente --> Constructor 

	Permutacion perm_decreciente (v_decreciente);


	// Consultar cu�ntos elementos tiene la permutaci�n

	int tope_decreciente = perm_decreciente.NumElementos();
	
	cout << "Se creo una permutacion ordenada decrecientemente" << endl;	
	cout << "La permutacion tiene " << tope_decreciente << " elementos.\n";
	cout << "Rango: " << perm_decreciente.Minimo() 
		 << " - " << perm_decreciente.Maximo() << endl;
	cout << endl;


	// Mostrar los elementos de la permutaci�n

	for (int i=0; i<tope_decreciente; i++) {

		char separador;

		if ((i+1)%MAX_LINE == 0) 
			separador = '\n';
		else 
			separador = ' ';
		cout << setw(4) << perm_decreciente.Elemento(i) << separador;
	}
	cout << endl << endl;


	// Calcular el n�mero de lecturas 

	cout << "La permutacion tiene " << perm_decreciente.NumeroLecturas() 
		 << " lecturas." << endl;
		 
	cout << endl << endl;

	return 0;
}

/***************************************************************************/
/***************************************************************************/

