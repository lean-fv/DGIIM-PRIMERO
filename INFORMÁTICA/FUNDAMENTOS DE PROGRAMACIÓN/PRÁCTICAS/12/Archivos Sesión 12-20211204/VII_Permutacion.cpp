/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 7
//
/*
	Programa que gestiona permutaciones de enteros: colecciones de enteros 
	sin elementos repetidos que coniene TODOS los números entre el mínimo 
	y el máximo de dichos valores.
	Por ejemplo, (2,3,6,5,4) es una permutación correcta, pero no lo es 
	(7,7,6,5) -> el 7 está repetido, ni tampoco (7,6,4)-> falta el 5.

	La resolución de este programa se realiza usando la clase "Permutacion":

	1) Representación: Usa un vector de enteros como dato miembro privado. 
	2) Ofrece los métodos:  
	* Permutacion (SecuenciaEnteros una_permutacion);
		Constructor con argumentos. 
		Recibe un dato de la clase "SecuenciaEnteros" con los valores que 
		forman la permutación.
		PRE: Supondremos que la secuencia es una permutación correcta. 
	* int Maximo();
	* int Minimo();
		Devuelve el máximo / mínimo de la permutación. 
		PRE: al menos hay un elemento 
	* int NumeroLecturas (void);
		Calcula el número de lecturas de la permutación. 
		Se dice que una permutación de t elementos C = {n_1,n_2,...,n_t} 
		tiene k lecturas si para leer sus elementos en orden creciente 
		(de izquierda a derecha) hay que recorrer la permutación k veces. 
		P.e., la siguiente permutación del conjunto {0,1,...,8}: 
			4 0 8 1 2 5 3 6 7
		necesita 3 lecturas: en la primera obtendríamos 0, 1, 2 y 3; en la 
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

	static const int TAMANIO = 50; // Número de casillas disponibles
	int vector_privado[TAMANIO];
	
	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;	// Número de casillas ocupadas


public:
	
	/***********************************************************************/
	// Constructor sin argumentos

	SecuenciaEnteros (void) 
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
	// Sustituye la componente situada en la posición "indice_componente" 
	// por el valor "nuevo".
	//
	// PRE: 0 <= indice < total_utilizados 
	// 		La modificación se realiza si "indice_componente" es correcto. 
	// 		Si no es así, no se hace nada.	
	
	void Modifica (int indice_componente, int nuevo)
	{
		if ((indice_componente>=0)  &&  (indice_componente<total_utilizados))

			vector_privado[indice_componente] = nuevo;
	}
	
	/***********************************************************************/
	// Devuelve la posición del mínimo valor de la secuencia
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
	// Devuelve la posición del máximo valor de la secuencia
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
	// Comprueba si la secuencia es una permutación correcta. 
	//
	// PRE: total_utilizados > 0
	
	bool EsPermutacion (void)
	{
		// Calcular el mínimo y el máximo valor de la secuencia
		int minimo = Elemento(PosicionMinimo());
		int maximo = Elemento(PosicionMaximo());

		/* 	
			Si el número de elementos de la secuencia (total_utilizados) no 
			es exactamente "maximo"-"minimo"+"1", faltan valores o hay valores
			repetidos. En este caso ya descartamos que sea una permutacion sin 
			necesidad de hacer más comprobaciones.
		*/
		
		bool es_permutacion;

		if (total_utilizados != maximo-minimo+1) 
			es_permutacion = false; 
		else 
			es_permutacion = true; 

		/*
			Comprobar si están todos los valores comprendidos entre "minimo" 
			y "maximo". Se termina si no se encuentra alguno (en ese caso 
			la secuencia no es una permutación). Si se encuentran todos los 
			valores entonces la secuencia forma una permutación. 
		*/

		// Sabemos que "minimo" y "maximo" están en la secuencia, 
		// evidentemente. La comprobación se hará entonces desde el siguiente 
		// al mínimo y hasta el anterior al máximo. 
		
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

			if (!encontrado) // El valor buscado no está
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
// La clase Permutacion representa una permutación de enteros, es decir, el 
// conjunto de todos los enteros entre un mínimo y un máximo sin repetidos 
// y no necesariamente ordenado.

class Permutacion
{

private:

	// Datos asociados a la estructura de datos empleada para guardar 
	// la permutación (vector enteros)

	static const int TAMANIO = 50; // Número de casillas disponibles
	int vector_privado[TAMANIO];
	
	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;	// Número de casillas ocupadas

public: 

	/***********************************************************************/
	// Constructor con argumentos
	// Recibe: una_permutacion, un dato de tipo "SecuenciaEnteros". 
	//
	// PRE: Supondremos que "una_permutacion" es una permutación correcta. 
	//		Existe un método de la clase "SeuenciaEnteros" que permite 
	//		comprobar que se cumple esta precondición. 
	
	Permutacion (SecuenciaEnteros una_permutacion) 
	{
		int num_elementos_una_permutacion = una_permutacion.TotalUtilizados();
		
		for (int i=0; i<num_elementos_una_permutacion; i++) 
			vector_privado[i] = una_permutacion.Elemento(i);
			
		total_utilizados = num_elementos_una_permutacion;
	}

	/***********************************************************************/
	// Devuelve el número de elementos de la permutación. 

	int NumElementos (void)
	{
		return (total_utilizados);
	}

	/***********************************************************************/
	// Devuelve la posición del mínimo de la permutación. 
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
	// Devuelve el mínimo de la permutación. 
	// PRE: total_utilizados > 0 

	int Minimo (void)
	{
		return (vector_privado[PosMinimo()]);
	}

	/***********************************************************************/
	// Devuelve la posición del máximo de la permutación. 
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
	// Devuelve el máximo de la permutación. 
	// PRE: al menos hay un elemento 

	int Maximo()
	{
		return (vector_privado[PosMaximo()]);
	}

	/***********************************************************************/
	// Devuelve el elemento de la casilla "indice" 
	// PRE: la posición dada por "indice" es correcta.

	int Elemento(int indice)
	{
		return (vector_privado[indice]);
	}

	/***********************************************************************/
	// Calcula el número de lecturas de la permutación

	int NumeroLecturas (void)
	{	
		int num_elementos = NumElementos();
		int contador_lecturas = 1; 
		int pos = 0; 

		// Usaremos un ciclo for porque sabemos exactamente los números 
		// que deben buscarse: Minimo(), Minimo()+1,Minimo()+2,...,Maximo()

		for (int n=Minimo(); n<=Maximo(); n++) {

			bool encontrado = false;

			while (!encontrado) {

				if (vector_privado[pos] == n) 
					encontrado = true; 

				else {
					if (pos==num_elementos-1)	// se ha examinado el último->
						contador_lecturas++;	// empieza otra lectura.

					pos = (pos+1)%num_elementos; // Incremento de "pos"

					// CLAVE: La operación "% num_elementos" permite que el 
					// siguiente al último (posición = "num_elementos"-1) 
					// sea el primero (posición = 0)			
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

	const int MAX_LINE = 10; // Mostrar MAX_LINE números por línea 

	// Creación y relleno del vector que formará la permutación

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
	
	
		// Crear una permutación a partir de v --> Constructor 
	
		Permutacion perm (v);
	
	
		// Consultar cuántos elementos tiene la permutación
	
		int tope = perm.NumElementos();
		
		cout << "Se creo una permutacion a partir de una secuencia" << endl;	
		cout << "La permutacion tiene " << tope << " elementos." << endl;
		cout << "Rango: " << perm.Minimo() << " - " << perm.Maximo() << endl;
		cout << endl;
	
	
		// Mostrar los elementos de la permutación
	
		for (int i=0; i<tope; i++) {
	
			char separador;
	
			if ((i+1)%MAX_LINE == 0) 
				separador = '\n';
			else 
				separador = ' ';
			cout << setw(4) << perm.Elemento(i) << separador;
		}
		cout << endl << endl;
	
		// Calcular el número de lecturas 
	
		cout << "La permutacion tiene " << perm.NumeroLecturas() 
			 << " lecturas." << endl;
		cout << endl << endl;

	}
	
	
	// Segundo ejemplo: una permutación ordenada 

	SecuenciaEnteros v_ordenado;

	v_ordenado.Aniade (3);
	v_ordenado.Aniade (4);
	v_ordenado.Aniade (5);
	v_ordenado.Aniade (6);

	// Crear una permutación a partir de v --> Constructor 

	Permutacion perm_ordenada (v_ordenado);


	// Consultar cuántos elementos tiene la permutación

	int tope_ordenada = perm_ordenada.NumElementos();

	cout << "Se creo una permutacion ordenada crecientemente" << endl;	
	cout << "La permutacion tiene " << tope_ordenada << " elementos.\n";
	cout << "Rango: " << perm_ordenada.Minimo() 
		 << " - " << perm_ordenada.Maximo() << endl;
	cout << endl;


	// Mostrar los elementos de la permutación

	for (int i=0; i<tope_ordenada; i++) {

		char separador;

		if ((i+1)%MAX_LINE == 0) 
			separador = '\n';
		else 
			separador = ' ';
		cout << setw(4) << perm_ordenada.Elemento(i) << separador;
	}
	cout << endl << endl;

	// Calcular el número de lecturas 

	cout << "La permutacion tiene " << perm_ordenada.NumeroLecturas() 
		 << " lecturas." << endl;
	cout << endl << endl;



	// Tercer ejemplo: una permutación en orden decreciente

	SecuenciaEnteros v_decreciente;

	v_decreciente.Aniade (8);
	v_decreciente.Aniade (7);
	v_decreciente.Aniade (6);
	v_decreciente.Aniade (5);

	// Crear una permutación a partir de v_decreciente --> Constructor 

	Permutacion perm_decreciente (v_decreciente);


	// Consultar cuántos elementos tiene la permutación

	int tope_decreciente = perm_decreciente.NumElementos();
	
	cout << "Se creo una permutacion ordenada decrecientemente" << endl;	
	cout << "La permutacion tiene " << tope_decreciente << " elementos.\n";
	cout << "Rango: " << perm_decreciente.Minimo() 
		 << " - " << perm_decreciente.Maximo() << endl;
	cout << endl;


	// Mostrar los elementos de la permutación

	for (int i=0; i<tope_decreciente; i++) {

		char separador;

		if ((i+1)%MAX_LINE == 0) 
			separador = '\n';
		else 
			separador = ' ';
		cout << setw(4) << perm_decreciente.Elemento(i) << separador;
	}
	cout << endl << endl;


	// Calcular el número de lecturas 

	cout << "La permutacion tiene " << perm_decreciente.NumeroLecturas() 
		 << " lecturas." << endl;
		 
	cout << endl << endl;

	return 0;
}

/***************************************************************************/
/***************************************************************************/

