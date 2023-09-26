/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 6
//
// Juego de adivinación con la clase GeneradorAleatorioEnteros
//
// Programa para jugar a adivinar un número. 
// El juego tiene que dar pistas de si el número introducido por 
// el jugador está por encima o por debajo del número introducido. 
// El programa genera de manera aleatoria el número que el jugador 
// debe adivinar. 
//
// Las reglas de parada son: 
//		1) Que el jugador adivine el número.
//		2) Que el jugador decida abandonar (el usuario escribirá 0 
//			cuando se le pide el número tentativo).
//
// Al finalizar un juego (no importa porqué) se pide al usuario si 
// desea seguir jugando. 
//
/***************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>

#include <random>  // para la generación de números pseudoaleatorios
#include <chrono>  // para la semilla

using namespace std;

/////////////////////////////////////////////////////////////////////////////

class GeneradorAleatorioEnteros
{  
private:
	
	mt19937 generador_mersenne;    // Mersenne twister
	uniform_int_distribution<int>  distribucion_uniforme;
	
	/************************************************************************/
	
	long long Nanosec(){
	return (chrono::high_resolution_clock::now().time_since_epoch().count());
	}
	
	/************************************************************************/ 
	
public:
	
	/************************************************************************/
		
	GeneradorAleatorioEnteros() : GeneradorAleatorioEnteros(0, 1) 
	{ }
	
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


/***************************************************************************/
// Devuelve una NUEVA cadena, resultante de eliminar los últimos caracteres 
// separadores de "cadena". Los caracteres separadores son el espacio en 
// blanco, el tabulador y el salto de línea. 
// Usaremos la función isspace() para simplificar el cálculo. 
// 
// Recibe:  cadena, string sobre la que se va a trabajar.
// Devuelve: cadena resultante de eliminar los últimos separadores de "cadena".
/***************************************************************************/

string EliminaUltimosSeparadores (string cadena)
{
   	while (cadena.length()>0 && isspace(cadena.back()))
		cadena.pop_back();
        
	return (cadena);
}

/***************************************************************************/
// Devuelve una NUEVA cadena, resultante de eliminar los primeros caracteres 
// separadores de "cadena". Los caracteres separadores son el espacio en 
// blanco, el tabulador y el salto de línea. 
// Usaremos la función isspace() para simplificar el cálculo. 
// 
// Recibe:  cadena, string sobre la que se va a trabajar.
// Devuelve: cadena resultante de eliminar los primeros separadores de "cadena".
/***************************************************************************/

string EliminaPrimerosSeparadores (string cadena)
{	
	// Buscar el primer carácter no espacio
	int pos = 0;
	while (pos <cadena.length() && isspace(cadena.at(pos))) pos++;

	string local; 
	
	// Copiar todos los que quedan
	while (pos <cadena.length()) {
		local.push_back(cadena.at(pos));
		pos++;
	}
		
	return (local);
}

/***************************************************************************/
// Devuelve una NUEVA cadena, resultante de eliminar los caracteres 
// separadores iniciales y finales de "cadena". Los caracteres separadores 
// son el espacio en blanco, el tabulador y el salto de línea. 
// Usaremos la función isspace() para simplificar el cálculo. 
// 
// Recibe:  cadena, string sobre la que se va a trabajar.
// Devuelve: cadena resultante de eliminar los primeros separadores de "cadena"
/***************************************************************************/

string EliminaSeparadoresInicialesyFinales (string cadena)
{	
	return (EliminaUltimosSeparadores(EliminaPrimerosSeparadores(cadena))); 
}

/***************************************************************************/
// Comprueba si un string es la representación textual de un dato int
// 
// Recibe:  cadena, string sobre la que se va a trabajar.
// Devuelve: "true" si "cadena"  es la representación textual de un entero
/***************************************************************************/

bool EsEntero (string cadena) 
{
	bool es_entero = true;

	cadena = EliminaSeparadoresInicialesyFinales (cadena);

	int long_cadena = cadena.length();
			
	if (long_cadena == 0) es_entero = false;
	else {	
	
		// Si el primer carácter es '+' ó '-', perfecto. En ese caso 
		// se pasa al siguiente carácter (posición 1).
		 		
		int pos;
		if (cadena.at(0)=='-'|| cadena.at(0) == '+') 
			if (long_cadena == 1) es_entero = false; 
			else pos=1;
		else pos=0;
		
		// Todos los caracteres desde la posición "pos" deben ser dígitos
		
		while ((pos < long_cadena) && es_entero) {
			if (!isdigit(cadena.at(pos))) es_entero = false;
			else pos++;
		}	
	}
	
	return (es_entero);
}

/***************************************************************************/
// Lee un dato int. La lectura está etiquetada con "titulo". La lectura se 
// efectúa repetidamente hasta que se introduce un valor int correcto. 
// 
// Recibe:  titulo, la cadena usada para etiquetar la lectura .
// Devuelve: el entero válido leído. 
/***************************************************************************/

int LeeEntero (string titulo)
{
	string cadena;

	do {
		cout << titulo;
		getline (cin, cadena);
						
	} while (!EsEntero(cadena));
			
	int numero = stoi(cadena);
 	
	return (numero);	
}

/***************************************************************************/
// Lee y devuelve un dato int. La lectura está etiquetada con "titulo". 
// Para que se considere correcta la lectura el dato int debe estar 
// comprendido entre "menor" y "mayor". 
// 
// Recibe:  titulo, la cadena usada para etiquetar la lectura .
// Devuelve: el entero válido leído. 
//
// PRE: menor <= mayor 
// POST: menor <= valor devuelto <= mayor 
/***************************************************************************/

int LeeEnteroMayorOIgual (string titulo, int referente)
{
	int numero;

	do {
		numero = LeeEntero (titulo);	
	} while (numero < referente);
	
	return (numero);
}

/***************************************************************************/
// Lee y devuelve un dato int positivo. 
// La lectura está etiquetada con "titulo". 
// Para que se considere correcta la lectura el dato int debe ser 
// estrictamente positivo. 
// 
// Recibe:  titulo, la cadena usada para etiquetar la lectura .
// Devuelve: el entero válido leído. 
//
// POST: 1 <= valor devuelto 
/***************************************************************************/

int LeeEnteroPositivo (string titulo)
{
	int numero;
	numero = LeeEnteroMayorOIgual (titulo, 1);		
	return numero;
}

/***************************************************************************/
// estrictamente positivo. 
// 
// Recibe:  titulo, la cadena usada para etiquetar la lectura .
// Devuelve: el entero válido leído. 
//
// POST: 1 <= valor devuelto 
/***************************************************************************/

char LeeSN (string msg)
{
	char c; 
	string cadena;
	bool es_char, es_SN;
	
	do {
				
		cout << msg;
		getline (cin, cadena);
		
		// Quitamos separadores
		cadena = EliminaSeparadoresInicialesyFinales (cadena);

		es_char = false;
		es_SN = false;
		
		if (cadena.length()== 1) { // ¿Se trata de un char?

			es_char = true; // Es char
		
			c = toupper(cadena.at(0));	// Pasar a mayúscula
			es_SN = ((c == 'S') || (c == 'N'));
		} 
		 
	} while (!es_char || !es_SN);

	return (c); 
}

/***************************************************************************/


/***************************************************************************/
/***************************************************************************/

int main()
{
	
	const int FIN = 0; // Valor terminador (fuerza el abandono) 

    //.......................................................................

	int menor, mayor; // Extremos del intervalo
	int num_valores;  // Núm. de valores del intervalo (extremos incluidos)
	
	
	// Leer los extremos del intervalo	 	
	cout << "Extremos del intervalo de los numeros a adivinar: " << endl;
	menor = LeeEnteroPositivo ("Un extremo:   ");  // a
	mayor = LeeEnteroPositivo ("Otro extremo: ");  // b
	
	// Ajustar extremos, si es preciso
	if (menor > mayor) {
		int tmp = menor;
		menor = mayor;
		mayor = tmp;
	}
	
	// Objeto generador de números aleatorios
	GeneradorAleatorioEnteros generador_aleat (menor, mayor);
		
    //.......................................................................

	// La variable "seguir_jugando" controla si se va a volver a jugar una 
	// vez se ha terminado un juego de adivinación. 
	
	bool seguir_jugando;
	
	int num_juegos = 0; // Contador del número de juegos de adivinación 
						// iniciados, independientemente de si se acaban 
						// con éxito o se abandonan. 
				
	// Como al menos se va a iniciar un juego de adivinación es 
	// aconsejable emplear un ciclo do-while como ciclo principal. 
	// Cada iteración supone que se inicia un nuevo juego. 
	
    int objetivo; // Valor a adivinar (se genera aleatoriamente)
    
	do {
	
		cout << "---------------------------------------------------" << endl;
		
		num_juegos++; // Actualizar el contador de juegos; 
		
		// Calcular el número que se va a adiviar en este juego
	    objetivo = generador_aleat.Siguiente();

		// Juego
		
		int num_jugadas = 0; // Contador de intentos válidos
		int leido;	// Para leer el valor suministrado por el jugador 

	    bool en_rango; 
	
		// Leer la primera jugada del juego 
		
		cout << "Juego " << num_juegos << ". ";
		cout << "Jugada " << (num_jugadas+1) << endl;

		do {
			string msg = "\tIntroduzca un numero entre " + to_string(menor) 
			             + " y " + to_string(mayor) +  ": ";
	    	leido = LeeEntero (msg);
	    	
	    	en_rango = ((leido>=menor) && (leido<=mayor));
	    	
		} while ( !en_rango && (leido != FIN));
		
		num_jugadas++; // Actualizar el número de jugadas
		
	
	    while ((leido != FIN) && (leido != objetivo)) { 
			    
			// Las pistas solo se muestran si se va a seguir jugando
			
			cout << endl;
			if (leido > objetivo)
	        	cout << "   El numero es menor que " << leido << endl;
	      	else 
	        	cout << "   El numero es mayor que " << leido << endl;
			cout << endl;
	    
	    
			// Leer la siguiente jugada del juego
			   		
			cout << "Juego " << num_juegos << ". ";
			cout << "Jugada " << (num_jugadas+1) << endl;
	
			do {
				string msg = "\tIntroduzca un numero entre " + to_string(menor) 
				             + " y " + to_string(mayor) +  ": ";
		    	leido = LeeEntero (msg);
		    	
		    	en_rango = ((leido>=menor) && (leido<=mayor));
		    	
			} while ( !en_rango && (leido != FIN));
					
			num_jugadas++;	// Actualizar el número de jugadas
			
	    } // while ((leido != FIN) && (leido != objetivo))
	    
	    // Ahora debemos discriminar la razón por la que terminó el ciclo
	        
	        
		cout << endl << endl;
		if (leido==FIN) 
		    cout << "ABANDONASTE EL JUEGO. ";	
		else 
		    cout << "Has acertado. ";
	
		cout << "---> El numero buscado era " << objetivo << endl;  
		cout << endl;    	
		
		cout << "Has jugado " << num_jugadas << " jugadas.";      
		cout << endl << endl;    	
	
	
		// ¿Seguimos jugando?

		cout << endl;    	
		char seguirSN = LeeSN ("Desea jugar otra vez (s/n)? : ");
		cout << endl;    		
				
		seguir_jugando = (seguirSN == 'S'); 
				
	} while (seguir_jugando); 
	
	
	cout << "---------------------------------------------------" << endl;
	cout << endl;
	cout << "Has jugado " << num_juegos << " juegos.";      
	cout << endl << endl;    		
		
	return 0;
}
