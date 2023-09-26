/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 7
//
/*
	Este programa continua trabajando con permutaciones de enteros: 
	colecciones de enteros sin elementos repetidos que coniene TODOS 
	los n�meros entre el m�nimo y el m�ximo de dichos valores.
	
	En otro ejercicio de esta relaci�n de problemas se trabaj� sobre 
	la clase "Permutacion", que se ampl�a en este programa. 

	Se presenta la clase "GeneradorPermutaciones" para generar permutaciones
	aleatorias de un conjunto de enteros entre un valor m�nimo y un valor 
	m�ximo. 
	
	La clase tiene un �nico m�todo: 
	
		Permutacion Genera(int primero, int ultimo)

	que se a�ade a la implementaci�n de la clase del ejercicio 5.  
	
		Por ejemplo, si m�nimo = 1 y m�ximo = 6, una permutaci�n v�lida ser�a 
		{3,1,6,4,5,2,3}. Como puede observarse, no pueden aparecer elementos 
		repetidos y deben estar todos los valores entre 1 y 6.

	Evidentemente, se requiere un sistema para generar valore aleatorios. 
	Para ello se dispone de la clase "MyRandom" (leer explicaciones 
	detalladas en el Gui�n de Pr�cticas )
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>

#include <random>  // para la generaci�n de n�meros pseudoaleatorios
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
					pos++;	// Continuar con la ssiguiente casilla

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

	int NumElementos(void)
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

	int Maximo(void)
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

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// Los objetos de esta clase generan permutaciones aleatorias (mediante el 
// m�todo "Genera") entre dos valores dados.  

class GeneradorPermutacionesAleatorias 
{

public: 

	/***********************************************************************/

	Permutacion Genera (int primero, int ultimo)
	{
        /*

		Algoritmo:

		* Ir generando aleatoriamente enteros entre "primero" y "ultimo". 
		* A�adir a "permutados" el entero generado, siempre y cuando 
		  no se haya a�adido anteriormente.

		El generador puede generar el mismo n�mero varias veces, por lo que 
		necesitamos llevar la cuenta de cu�les son los que ya se han generado.
		
			P.e., si primero = 3 y ultimo = 5, necesitaremos el vector:
				ya_generado = {false, false, false}

			Cuando genere el 5:
				ya_generado = {false, false, true}

			Termino cuando haya generado todos los enteros entre 3 y 5.
            
		En vez de recorrer cada vez que se genera un entero completamente 
		el vector "ya_generado" en busca de alg�n false (indica alg�n hueco), 
		basta con contar cu�ntos enteros distintos llevo generados en cada 
		momento --> total_generados_distintos

            Si, por ejemplo, el primer entero generado es el 4, nos queda:
            permutados = {4, ? , ?}
        */
        
        // N�mero de valores a generar 
		int totales_a_generar = ultimo - primero + 1;
		
		
		static const int TAMANIO = 50; 	// N�mero de casillas disponibles
		bool ya_generado[TAMANIO];	 	// Vector auxiliar de control  	
		
		// Iniciar el vector de control a false (no se ha registrado 
		// ning�n valor de la permutaci�n)

		for (int i = 0; i < totales_a_generar; i++)
			ya_generado[i] = false;


		// El objeto "permutados" contendr� el resultado (permutaci�n)
		SecuenciaEnteros permutados; 
		
	
		// Iniciar generador aleatorio 
		GeneradorAleatorioEnteros aleatorio (primero, ultimo); 
		
		
		int total_generados_distintos = 0;  
	
		while (total_generados_distintos < totales_a_generar) {

			// Obtener un nuevo valor aleatorio entre "primero" y "ultimo"

			int generado = aleatorio.Siguiente();  
			
			int indice_generado = generado - primero;
			// El �ndice de "primero" es 0, el de "primero"+1 es 1, ...
			// Sirve para consultar el vector de control

			// Si no ha sido generado, a�adirlo al vector resultado 
			// Si ha sido generado, no hacer nada: en la siguiente iteraci�n 
			// se generar� otro valor aleatorio.

			if (!ya_generado[indice_generado]) {

				total_generados_distintos++;
				
				ya_generado[indice_generado] = true;
				
				permutados.Aniade(generado);
			}

		} // while (total_generados_distintos < totales_a_generar)
      
      
		// Crear la permutaci�n con la secuencia de enteros y devolverla

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
	const int MAX_LINE = 10; // Mostrar MAX_LINE n�meros por l�nea 

	// Pedir los valores extremos de la permutaci�n

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

		// Observar c�mo act�a el constructor de copia de la clase Permutacion
		Permutacion permutacion(gen_permutaciones.Genera(minimo,maximo));


		// Consultar cu�ntos elementos tiene la permutaci�n

		int tope = permutacion.NumElementos();
	
		cout << "La permutacion tiene " << tope << " elementos." << endl;
		cout << "Rango: " << permutacion.Minimo() 
			 << " - " << permutacion.Maximo() << endl;
		cout << endl;

		// Mostrar los elementos de la permutaci�n

		for (int i=0; i<tope; i++) {

			char separador;

			if ((i+1)%MAX_LINE == 0) 
				separador = '\n';
			else 
				separador = ' ';
			cout << setw(4) << permutacion.Elemento(i) << separador;
		}
		cout << endl << endl;
		
		// Calcular el n�mero de lecturas 
	
		cout << "La permutacion tiene " << permutacion.NumeroLecturas() 
			 << " lecturas." << endl;
		cout << endl << endl;
		
			
		// Pedir otra permutaci�n

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

