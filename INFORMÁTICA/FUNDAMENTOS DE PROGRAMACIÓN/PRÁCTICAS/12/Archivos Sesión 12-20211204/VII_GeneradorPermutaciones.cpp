/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 7
//
/*
	Este programa continua trabajando con permutaciones de enteros: 
	colecciones de enteros sin elementos repetidos que coniene TODOS 
	los números entre el mínimo y el máximo de dichos valores.
	
	En otro ejercicio de esta relación de problemas se trabajó sobre 
	la clase "Permutacion", que se amplía en este programa. 

	Se presenta la clase "GeneradorPermutaciones" para generar permutaciones
	aleatorias de un conjunto de enteros entre un valor mínimo y un valor 
	máximo. 
	
	La clase tiene un único método: 
	
		Permutacion Genera(int primero, int ultimo)

	que se añade a la implementación de la clase del ejercicio 5.  
	
		Por ejemplo, si mínimo = 1 y máximo = 6, una permutación válida sería 
		{3,1,6,4,5,2,3}. Como puede observarse, no pueden aparecer elementos 
		repetidos y deben estar todos los valores entre 1 y 6.

	Evidentemente, se requiere un sistema para generar valore aleatorios. 
	Para ello se dispone de la clase "MyRandom" (leer explicaciones 
	detalladas en el Guión de Prácticas )
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>

#include <random>  // para la generación de números pseudoaleatorios
#include <chrono>  // para la semilla

using namespace std;

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
class GeneradorAleatorioEnteros
{  
private:
	
   mt19937 generador_mersenne;    // Mersenne twister
   uniform_int_distribution<int>  distribucion_uniforme;
   
   /************************************************************************/
   long long Nanosec(){
      return (chrono::high_resolution_clock::now().
              time_since_epoch().count());
   }
   /************************************************************************/ 

public:
	
   /************************************************************************/	
   GeneradorAleatorioEnteros()
      :GeneradorAleatorioEnteros(0, 1){
   }
   
   /************************************************************************/  
   GeneradorAleatorioEnteros(int min, int max) {
      const int A_DESCARTAR = 70000;
      // ACM TOMS Volume 32 Issue 1, March 2006
      
      auto semilla = Nanosec();
      generador_mersenne.seed(semilla);
      generador_mersenne.discard(A_DESCARTAR);
      distribucion_uniforme = uniform_int_distribution<int> (min, max);
   }
   
   /************************************************************************/
   int Siguiente(){
      return (distribucion_uniforme(generador_mersenne));
   }
   /************************************************************************/
};
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

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
					pos++;	// Continuar con la ssiguiente casilla

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

	int NumElementos(void)
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

	int Maximo(void)
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

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// Los objetos de esta clase generan permutaciones aleatorias (mediante el 
// método "Genera") entre dos valores dados.  

class GeneradorPermutacionesAleatorias 
{

public: 

	/***********************************************************************/

	Permutacion Genera (int primero, int ultimo)
	{
        /*

		Algoritmo:

		* Ir generando aleatoriamente enteros entre "primero" y "ultimo". 
		* Añadir a "permutados" el entero generado, siempre y cuando 
		  no se haya añadido anteriormente.

		El generador puede generar el mismo número varias veces, por lo que 
		necesitamos llevar la cuenta de cuáles son los que ya se han generado.
		
			P.e., si primero = 3 y ultimo = 5, necesitaremos el vector:
				ya_generado = {false, false, false}

			Cuando genere el 5:
				ya_generado = {false, false, true}

			Termino cuando haya generado todos los enteros entre 3 y 5.
            
		En vez de recorrer cada vez que se genera un entero completamente 
		el vector "ya_generado" en busca de algún false (indica algún hueco), 
		basta con contar cuántos enteros distintos llevo generados en cada 
		momento --> total_generados_distintos

            Si, por ejemplo, el primer entero generado es el 4, nos queda:
            permutados = {4, ? , ?}
        */
        
        // Número de valores a generar 
		int totales_a_generar = ultimo - primero + 1;
		
		
		static const int TAMANIO = 50; 	// Número de casillas disponibles
		bool ya_generado[TAMANIO];	 	// Vector auxiliar de control  	
		
		// Iniciar el vector de control a false (no se ha registrado 
		// ningún valor de la permutación)

		for (int i = 0; i < totales_a_generar; i++)
			ya_generado[i] = false;


		// El objeto "permutados" contendrá el resultado (permutación)
		SecuenciaEnteros permutados; 
		
	
		// Iniciar generador aleatorio 
		GeneradorAleatorioEnteros aleatorio (primero, ultimo); 
		
		
		int total_generados_distintos = 0;  
	
		while (total_generados_distintos < totales_a_generar) {

			// Obtener un nuevo valor aleatorio entre "primero" y "ultimo"

			int generado = aleatorio.Siguiente();  
			
			int indice_generado = generado - primero;
			// El índice de "primero" es 0, el de "primero"+1 es 1, ...
			// Sirve para consultar el vector de control

			// Si no ha sido generado, añadirlo al vector resultado 
			// Si ha sido generado, no hacer nada: en la siguiente iteración 
			// se generará otro valor aleatorio.

			if (!ya_generado[indice_generado]) {

				total_generados_distintos++;
				
				ya_generado[indice_generado] = true;
				
				permutados.Aniade(generado);
			}

		} // while (total_generados_distintos < totales_a_generar)
      
      
		// Crear la permutación con la secuencia de enteros y devolverla

		Permutacion permutacion (permutados);
		
		return (permutacion);
   }
   
	/***********************************************************************/
};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	const int MAX_LINE = 10; // Mostrar MAX_LINE números por línea 

	// Pedir los valores extremos de la permutación

	int minimo, maximo; 

	cout << "Introduzca los dos valores extremos de la permutacion: ";
	cin >> minimo >> maximo; 

	if (maximo < minimo) {
		int tmp = maximo; 
		maximo = minimo; 
		minimo = tmp;
	}

	// Crear el objeto generador de permutaciones 
    GeneradorPermutacionesAleatorias gen_permutaciones;


	bool sigo = true; 

	while (sigo) {

		// Observar cómo actúa el constructor de copia de la clase Permutacion
		Permutacion permutacion(gen_permutaciones.Genera(minimo,maximo));


		// Consultar cuántos elementos tiene la permutación

		int tope = permutacion.NumElementos();
	
		cout << "La permutacion tiene " << tope << " elementos." << endl;
		cout << "Rango: " << permutacion.Minimo() 
			 << " - " << permutacion.Maximo() << endl;
		cout << endl;

		// Mostrar los elementos de la permutación

		for (int i=0; i<tope; i++) {

			char separador;

			if ((i+1)%MAX_LINE == 0) 
				separador = '\n';
			else 
				separador = ' ';
			cout << setw(4) << permutacion.Elemento(i) << separador;
		}
		cout << endl << endl;
		
		// Calcular el número de lecturas 
	
		cout << "La permutacion tiene " << permutacion.NumeroLecturas() 
			 << " lecturas." << endl;
		cout << endl << endl;
		
			
		// Pedir otra permutación

		char respuesta;
		cout << "Generar otra permutacion (s)? ";
		cin >> respuesta; 

		if (toupper(respuesta)!='S') 
			sigo = false; 
	}

    cout << endl << endl;

	return 0;
}

/***************************************************************************/
/***************************************************************************/

