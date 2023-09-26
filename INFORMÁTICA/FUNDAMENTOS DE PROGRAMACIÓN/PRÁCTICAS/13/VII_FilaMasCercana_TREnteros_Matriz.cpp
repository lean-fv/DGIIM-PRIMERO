/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS VII

47. Ampliar la clase TablaRectangularEnteros con un método que busque la fila de
la matriz que más se parezca a un vector de enteros (clase SecuenciaEnteros) al
que llamaremos referencia. El método devolverá el número de la fila.
La similitud entre dos vectores x = (x1 · · · xp) e y = (y1 · · · yp) vendrá
dada por la distancia euclídea entre ambos:

			  _________________________________
dist(x, y) = V(x1 − y1)^2 + · · · + (xp − yp)^2

Además, la búsqueda solo se hará sobre un conjunto seleccionado de filas de la
tabla, enumeradas en la secuencia de enteros filas_a_comparar (un objeto de la
clase SecuenciaEnteros).

Por ejemplo, dada la matriz M (7 × 4),

→ 3 1 0 8
  4 5 1 5
→ 5 7 1 7
  7 9 6 1
→ 4 9 5 5
→ 2 8 2 2
  7 3 2 5

y los vectores referencia = 2, 8, 1, 1 y filas_a_comparar = 0, 2, 4, 5, el
programa deberá encontrar 5 como la fila más cercana a la secuencia referencia
(en el dibujo anterior se han marcado con una flecha las filas indicadas por el
vector filas_a_comparar).

ENTRADA: una matriz de datos enteros y un vector a comparar con determinadas
filas de ella.
SALIDA: la fila mas parecida al vector.

*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/*---------------------------------------------------------------------------
								Clase SecuenciaEnteros
---------------------------------------------------------------------------*/

class SecuenciaEnteros {

private:

    static const int TAMANIO = 50; // Num.casillas disponibles
    int vector_privado[TAMANIO];

    // PRE: 0 <= total_utilizados <= TAMANIO

    int total_utilizados; // Num.casillas ocupadas

public:


    /***********************************************************************
    Constructor sin argumentos
	***********************************************************************/

    SecuenciaEnteros (void) : total_utilizados (0)
    {}



	/***********************************************************************
    Constructor con argumento string: "copia" el contenido del string en
	la secuencia.
	***********************************************************************/

    SecuenciaEnteros (string cad)
    {
    	int num_cifras;

    	int long_cad = cad.length();

		if (long_cad > TAMANIO) num_cifras = TAMANIO;
		else num_cifras = long_cad;

		for (int pos=0; pos<num_cifras; pos++)

			vector_privado[pos] = (cad.at(pos)) - '0';

		total_utilizados = num_cifras;
	}



    /***********************************************************************
    Constructor con dos int. Rellena la secuencia con "n" cifras "c".
	***********************************************************************/

	SecuenciaEnteros (int c, int n)
	{
		int num_caracteres;

		if (n > TAMANIO) num_caracteres = TAMANIO;
		else num_caracteres = n;

		for (int pos=0; pos<num_caracteres; pos++)
			vector_privado[pos] = c;

		total_utilizados = num_caracteres;
	}



    /***********************************************************************
    Getter TotalUtilizados: devuelve el numero de casillas ocupadas
	***********************************************************************/

    int TotalUtilizados (void)
    {
        return (total_utilizados);
    }



    /***********************************************************************
    Getter Capacidad: devuelve el numero de casillas disponibles.
	***********************************************************************/

    int Capacidad (void)
    {
        return (TAMANIO);
    }



    /***********************************************************************
	Metodo Aniade:

	Aniade un elemento ("nuevo") al vector.
    PRE: total_utilizados < TAMANIO

	La adicion se realiza si hay alguna casilla disponible.
    El nuevo elemento se coloca al final del vector.
    Si no hay espacio, no se hace nada.
	***********************************************************************/

    void Aniade (int nuevo)
    {
        if (total_utilizados < TAMANIO){
            vector_privado[total_utilizados] = nuevo;
            total_utilizados++;
        }
    }



    /***********************************************************************
	Getter Elemento: devuelve el elemento de la casilla "indice"

    PRE: 0 <= indice < total_utilizados
	***********************************************************************/

    int Elemento (int indice)
    {
        return (vector_privado[indice]);
    }



    /***********************************************************************
	Metodo Elimina: elimina la cifra de la posicion dada por "indice".
	Realiza un borrado fisico (desplazamiento y sustitucion).

	PRE: 0 <= indice < total_utilizados
	***********************************************************************/

    void Elimina (int indice)
    {
        if ((indice >= 0) && (indice < total_utilizados)) {

            int tope = total_utilizados-1; // posic. del �ltimo

            for (int i = indice ; i < tope ; i++)
                vector_privado[i] = vector_privado[i+1];

            total_utilizados--;
        }
    }


	/***********************************************************************
	Metodo EliminaTodos: elimina la secuencia.
	***********************************************************************/

	void EliminaTodos (void)
	{
		total_utilizados = 0;
	}



    /***********************************************************************
	Metodo ToString: compone un string con todos las cifras que
	almacenadas en la secuencia y lo devuelve.
	***********************************************************************/

    string ToString(void)
    {
        string cadena;

        for (int i=0; i < total_utilizados; i++)
            cadena = cadena + " " + to_string (vector_privado[i]);

        return (cadena);
    }



	/***********************************************************************
	Metodo OrdenaVector: ordena vector_privado mediante el algoritmo de la
	burbuja.
	***********************************************************************/

	void OrdenaVector (void){

		bool cambio = true;

		for (int izda = 0; izda < total_utilizados && cambio; izda++){

			cambio = false;

			for (int i = total_utilizados - 1; i > izda; i--){

				if (vector_privado[i] < vector_privado[i-1]){

					int intercambia = vector_privado[i];
					vector_privado[i] = vector_privado[i-1];
					vector_privado[i-1] = intercambia;
					cambio = true;
				}
			}
		}
	}


	/***********************************************************************
	Metodo BusquedaInterpolacion: busca un elemento determinado mediante el
	algoritmo de busqueda por interpolacion.

	PRE: el vector tiene que estar ordenado.
	***********************************************************************/

	int BusquedaInterpolacion (int buscado){

		bool encontrado = false;
		int pos_encontrado = 0;
		int izda = 0;
		int dcha = total_utilizados - 1;
		int referencia = izda + ((buscado - vector_privado[izda]) *
		(dcha - izda))/ (vector_privado[dcha] - vector_privado[izda]);


		while (izda <= dcha && !encontrado){

			if (vector_privado[referencia] == buscado) encontrado = true;

			else if (buscado < vector_privado[referencia])
				dcha = referencia - 1;

			else izda = referencia + 1;

			referencia = izda + ((buscado - vector_privado[izda]) *
			(dcha - izda))/ (vector_privado[dcha] - vector_privado[izda]);
		}

		if (encontrado) pos_encontrado = referencia;
		else pos_encontrado = - 1;

		return pos_encontrado;

	}


};



/*---------------------------------------------------------------------------
						Clase TablaRectangularEnteros
---------------------------------------------------------------------------*/


class TablaRectangularEnteros
{

private:

    static const int NUM_FILS = 50;
    static const int NUM_COLS = 40;

    int  matriz_privada[NUM_FILS][NUM_COLS];

    // PRE: 0 < filas_utilizadas <= NUM_FILS
    // PRE: 0 < col_utilizadas <= NUM_COLS

    int filas_utilizadas;
    int cols_utilizadas;

public:


	// Constructor sin argumentos.

	TablaRectangularEnteros(void): filas_utilizadas(0), cols_utilizadas(0)
	{}


	// Constructores con argumentos.


	// PRE: numero_de_columnas <= NUM_COLS
	TablaRectangularEnteros (int numero_de_columnas) : filas_utilizadas(0),
		  cols_utilizadas(numero_de_columnas)
	{}



	// PRE: primera_fila.TotalUtilizados() <= NUM_COLS
	TablaRectangularEnteros (SecuenciaEnteros primera_fila)
		: filas_utilizadas(0), cols_utilizadas (primera_fila.TotalUtilizados())
	{
		Aniade(primera_fila); // Actualiza "filas_utilizadas"
	}



	//Getters.

	int CapacidadFilas (void)
	{
		return (NUM_FILS);
	}



	int CapacidadColumnas (void)
	{
		return (NUM_COLS);
	}



	int FilasUtilizadas (void)
	{
		return (filas_utilizadas);
	}



	int ColumnasUtilizadas (void)
	{
		return (cols_utilizadas);
	}



	// PRE: 0 <= fila < filas_utilizadas
	// PRE: 0 <= columna < cols_utilizadas

	int Elemento (int fila, int columna)
	{
		return (matriz_privada[fila][columna]);
	}



	/*************************************************************************
	Metodo Fila: devuelve una fila completa (un objeto "SecuenciaEnteros").

	PRE: 0 <= indice_fila < filas_utilizadas
	*************************************************************************/

	SecuenciaEnteros Fila (int indice_fila)
	{
		SecuenciaEnteros fila;

		for (int col=0; col<cols_utilizadas; col++)
			fila.Aniade(matriz_privada[indice_fila][col]);

		return (fila);
	}

	/**************************************************************************
	Metodo Columna: devuelve una columna completa (un objeto "SecuenciaEnteros")

	PRE: 0 <= indice_columna < cols_utilizadas
	**************************************************************************/

	SecuenciaEnteros Columna (int indice_columna)
	{
		SecuenciaEnteros columna;

		for (int fil=0; fil<filas_utilizadas; fil++)
			columna.Aniade (matriz_privada[fil][indice_columna]);

		return (columna);
	}


	/******************************************************************
	Metodo EstaVacia: devuelve true si la tabla esta vacia
	*******************************************************************/

	bool EstaVacia (void)
	{
		return (filas_utilizadas == 0);
	}



	/***********************************************************************
	Metodo Aniade: Aniade una fila completa (un objeto "SecuenciaEnteros")

	PRE:  fila_nueva.TotalUtilizados() = cols_utilizadas
	PRE:  filas_utilizadas < NUM_FILS
	*******************************************************************/

	void Aniade (SecuenciaEnteros fila_nueva)
	{
		int numero_columnas_fila_nueva = fila_nueva.TotalUtilizados();

		if ((filas_utilizadas < NUM_FILS) &&
			(numero_columnas_fila_nueva == cols_utilizadas)) {

			for (int col = 0; col < numero_columnas_fila_nueva; col++)
				matriz_privada[filas_utilizadas][col]=fila_nueva.Elemento(col);

			filas_utilizadas++;
		}
	}



	/***********************************************************************
	Metodo EliminaTodos: Vacia una tabla.
	*******************************************************************/

	void EliminaTodos (void)
	{
		filas_utilizadas = 0;
	}


	/***********************************************************************
	Metodo Elimina: elimina una fila completa, dada una posicion.

 	PRE:  0 <= num_fila < TotalUtilizados()
	*******************************************************************/

	void Elimina (int num_fila)
	{

		if ((0<=num_fila) && (num_fila <=filas_utilizadas)) {

			/* Desplazamos las filas hacia posiciones bajas.
			En la posicion "num_fila" se copia la que esta en la posicion
			siguiente ("num_fila"+1), y asi sucesivamente. */

			for (int fil=num_fila; fil<filas_utilizadas-1; fil++) {

				int num_columnas = cols_utilizadas;

				for (int c=0; c<num_columnas; c++)
					matriz_privada[fil][c]=matriz_privada[fil+1][c];
			}

			filas_utilizadas--; // Actualizacion del tamanio de la tabla.
		}
	}



	/**************************************************************************
	Metodo VectorSimilar: busca en la matriz dato miembro del objeto la fila
	mas parecida a un vector de referencia entre unas filas determinadas
	de la matriz, que vienen dadas por la secuencia filas_a_comparar.

	PRE: referencia.TotalUtilizados() = cols_utilizadas
	PRE: 0 < filas_a_comparar.TotalUtilizados <= filas_utilizadas
	PRE: filas_a_comparar.Elemento(i) con i = 0, 1,...,
	filas_a_comparar.TotalUtilizados() - 1 sea >= 0 y <= filas_utilizadas - 1
	***************************************************************************/

	SecuenciaEnteros VectorSimilar (SecuenciaEnteros referencia,
	SecuenciaEnteros filas_a_comparar)
	{
		double distancia = 0;
		double distancia_min = 0;
		SecuenciaEnteros resultado;

		/* En caso de que solo hubiese una fila con la que comparar, se
		establece la distancia minima calculando la distancia euclidea
		con respecto a la primera fila y se inicializa la secuencia
		resultado con los valores de la primera fila */

		for (int i = 0; i < cols_utilizadas; i++){

			distancia_min +=
			pow((referencia.Elemento(i)-
			Elemento(filas_a_comparar.Elemento(0), i)), 2);
		}

		distancia_min = sqrt(distancia_min);

		for (int i = 0; i < cols_utilizadas; i++){

			resultado.Aniade(Elemento(filas_a_comparar.Elemento(0), i));
		}

		/* En caso de que haya mas de una fila con la que comparar, se repite
		el proceso anterior a partir de la segunda fila. */

		for (int i = 1; i < filas_a_comparar.TotalUtilizados(); i++){

			for (int j = 0; j < cols_utilizadas; j++){

				distancia +=
				pow ((referencia.Elemento(j)
				-Elemento(filas_a_comparar.Elemento(i), j)), 2);
			}

			distancia = sqrt(distancia);

			/*En caso de que la distancia que se calcule sea menor que la
			la distancia minima, esta se actualiza, se borra lo que habia en
			la secuencia resultado y se le introducen los valores de la
			ultima fila estudiada. */

			if (distancia < distancia_min){

				distancia_min = distancia;
				resultado.EliminaTodos();

				for (int k = 0; k < cols_utilizadas; k++){

					resultado.Aniade(Elemento(filas_a_comparar.Elemento(i), k));
				}
			}

			/*Tras todo este proceso, se borra la distancia calculada para
			la siguiente iteracion.*/

			distancia = 0;
		}

		return (resultado);
	}



	/***********************************************************************
	Metodo ToString: representa mediante un dato string el estado del objeto.
	Muestra los elementos de la matriz dato miembro del objeto dispuestos
	por filas y columnas.
	*******************************************************************/

	string ToString (void)
	{
		string cad;

		for (int i = 0; i < filas_utilizadas; i++){

			for (int j = 0; j < cols_utilizadas; j++){

				cad += to_string(matriz_privada[i][j]) + " ";
			}

			cad+= "\n";
		}

		return(cad);
	}
};



/*---------------------------------------------------------------------------
								Clase Lector
---------------------------------------------------------------------------*/
class Lector{

private:

	string mensaje;



	/*************************************************************************
	Metodo EliminaUltimosSeparadores: Elimina los últimos caracteres separadores
	de "cadena". Los caracteres  separadores son el espacio en blanco, el
	tabulador y el salto de línea. Usaremos la función isspace() para
	simplificar el cálculo.
	*************************************************************************/


	string EliminaUltimosSeparadores (string cadena)
	{
	   	while (cadena.length()>0 && isspace(cadena.back()))
			cadena.pop_back();

		return (cadena);
	}



	/*************************************************************************
	Metodo EliminaPrimerosSeparadores: Elimina los primeros caracteres
	separadores de "cadena". Los caracteres separadores son el espacio en
	blanco, el tabulador y el salto de línea. Usaremos la función isspace()
	para simplificar el cálculo.
	*************************************************************************/

	string EliminaPrimerosSeparadores (string cadena)
	{
		// Buscar el primer carácter no espacio
		int pos = 0;
		while (pos < (int)cadena.length() && isspace(cadena.at(pos))) pos++;

		string local;

		// Copiar todos los que quedan
		while (pos < (int)cadena.length()) {
			local.push_back(cadena.at(pos));
			pos++;
		}

		return (local);
	}



	/************************************************************************
	Metodo EsEntero: indica si un dato introducido es entero o no.
	************************************************************************/

	bool EsEntero (string cadena)
	{

		bool entero_bien = true;
		char caracter;

		cadena = EliminaPrimerosSeparadores (cadena);
		cadena = EliminaUltimosSeparadores  (cadena);

		int long_cadena = (int)cadena.length();

		if (long_cadena == 0) entero_bien = false; // No hay nada

		else { //Longitud > 0

			int posicion = 0;

			if ((cadena.at(posicion) == '-') || (cadena.at(posicion) == '+')){

				posicion++;
			}

			while (entero_bien && (posicion < cadena.length())){

				caracter = cadena.at(posicion);

				entero_bien = ((caracter >= '0') && (caracter <= '9'));

				posicion++;
			}
		}

		return(entero_bien);
	}



	/************************************************************************
	Metodo EsReal: indica si un dato introducido es real o no.
	************************************************************************/

	bool EsReal (string cadena)
	{
		bool es_real = true;

		cadena = EliminaPrimerosSeparadores (cadena);
		cadena = EliminaUltimosSeparadores  (cadena);

		int long_cadena = (int)cadena.length();

		if (long_cadena == 0) es_real = false; // No hay nada
		else {	// long_cadena > 0

			// Si el primer carácter es '+' ó '-', perfecto.
			// En ese caso (si hay algo más) en la cadena se pasa al
			// siguiente carácter (posición 1).

			int pos;
			if (cadena.at(0)=='-'|| cadena.at(0) == '+') {
				if (long_cadena>1) pos=1;
				else es_real = false; // Solo hay '-' ó '+'
			}
			else pos=0;

			// Bandera que se activa al encontrar un punto
			bool encontrado_un_punto = false;

			while ((pos < long_cadena) && es_real) {

				char c = cadena.at(pos);

				if (!isdigit(c)) {

					// Solo puede haber un punto.
					// Si se ha encontrado un punto y ya se había
					// encontrado otro, error. Si no, activar la bandera
					// "encontrado_un_punto" (ya no puede haber más).

					if (c =='.') {
						if (encontrado_un_punto) es_real= false;
						else encontrado_un_punto = true;
					}
					// Si no es un punto ni un dígito --> error
					else es_real= false;
				}

				pos++;

			}	// while ((pos < long_cadena) && es_real)

		} // else de if (long_cadena == 0)

		return (es_real);
	}

//----------------------------------------------------------------------------


public:

	//Constructor con argumentos.
	Lector (string cadena) : mensaje(cadena)

	{}

	//Constructor sin argumentos.
	Lector (void)

	{}


	//Setter que nos permite cambiar el valor del campo mensaje.
	void SetTitulo (string titulo){

		mensaje = titulo;

	}



	/**************************************************************************
	Metodo LeeEntero: filtra un dato entero comprobando si es entero.
	**************************************************************************/

	int LeeEntero (void)
	{
		string numero;

		do{

			//cout << mensaje;
			getline(cin, numero);

		}
		while (!EsEntero(numero));

		return(stoi(numero));
	}



	/**************************************************************************
	Metodo LeeEnteroEnRango: filtra un dato entero comprobando si esta en un
	rango determinado.
	**************************************************************************/

	int LeeEnteroEnRango (int menor, int mayor){

		int numero;

		do{
			numero = LeeEntero();

		} while ((numero < menor) || (numero > mayor));

		return (numero);
	}


	/**************************************************************************
	Metodo LeeEnteroMayorOIgual: filtra un dato entero comprobando si esta en
	un rango determinado.
	**************************************************************************/


	 int LeeEnteroMayorOIgual (int referencia){

	 	int numero;

	 	do{
	 		numero = LeeEntero();

	 	} while (numero < referencia);

	 	return (numero);
	 }



	 /*************************************************************************
	 Metodo LeeReal:

	 Lee un dato double.
	 La lectura está etiquetada con "titulo"
	 La lectura se efectúa repetidamente hasta que se introduce un valor double
	 correcto.

	 Devuelve: el double válido leído.
	 *************************************************************************/

	 double LeeReal (void)
	 {
	 	string cadena;

	 	do {
	 		//cout << mensaje;
	 		getline (cin, cadena);
	 	} while (!EsReal(cadena));

	 	return (stod(cadena));
	 }



	 /************************************************************************
	 Metodo LeeRealEnRango:

	 Lee un dato double que debe estar entre "menor" y "mayor" y lo devuelve.
	 La lectura está etiquetada con "titulo"

	 PRE: menor <= mayor
	 POST: menor <= valor devuelto <= mayor
	 ************************************************************************/


	 double LeeRealEnRango (double menor, double mayor)
	 {
	 	double numero;

	 	do {
	 		numero = LeeReal();
	 	} while ((numero<menor) || (numero>mayor));

	 	return (numero);
	 }



	 /************************************************************************
	 Metodo LeeRealMayorOIgual:

	 Lee un dato double que debe ser mayor o igual que "menor" y lo devuelve.
	 La lectura está etiquetada con "titulo"

	 POST: menor <= valor devuelto
	 ************************************************************************/

	 double LeeRealMayorOIgual (double referencia)
	 {
	 	double numero;

	 	do {
	 		numero = LeeReal ();
	 	} while (numero < referencia);

	 	return (numero);
	 }


};



/*---------------------------------------------------------------------------
							Programa principal
---------------------------------------------------------------------------*/

int main() {


	// Declaraciones.

	int filas_utilizadas;
	int cols_utilizadas;
	const int MAX_FIL = 50;
	const int MAX_COL = 40;
	Lector lector;
	int tamanio_posiciones;

	// Entrada de datos.

	cout << "***********************************************" << endl << endl;

	cout << "BUSQUEDA DE LA FILA MAS PROXIMA A UN VECTOR DE REFERENCIA DADO";
	cout << endl << endl;

	lector.SetTitulo("Numero de filas de su matriz: ");
	filas_utilizadas = lector.LeeEnteroEnRango(1, MAX_FIL);

	lector.SetTitulo("Numero de columnas de su matriz: ");
	cols_utilizadas = lector.LeeEnteroEnRango(1, MAX_COL);

	TablaRectangularEnteros tabla (cols_utilizadas);

	lector.SetTitulo("Introduzca un numero real: ");
	SecuenciaEnteros a_aniadir;

	for (int i = 0; i < filas_utilizadas; i++){

		//cout << endl;
		//cout << "Introduzca los valores de la fila " << i << ": ";
		//cout << endl;

		for (int j = 0; j < cols_utilizadas; j++){

			a_aniadir.Aniade(lector.LeeEntero());
		}

		tabla.Aniade(a_aniadir);

		a_aniadir.EliminaTodos();
	}

	// Mostrar matriz

	cout << endl;
	cout << tabla.ToString() << endl;

	// Entrada del vector de referencia a comparar

	//cout << "Introduzca el vector a comparar en la matriz: " << endl;
	lector.SetTitulo("Introduzca un numero entero: ");

	SecuenciaEnteros referencia;

	for (int i = 0; i < cols_utilizadas; i++)
		referencia.Aniade(lector.LeeEntero());

	cout << endl;

	// Entrada del vector de filas a comparar

	//cout << "Introduzca el numero de filas entre las que se va a buscar: "
	cout << endl;
	tamanio_posiciones = lector.LeeEnteroEnRango(1, filas_utilizadas);
	lector.SetTitulo("Introduzca la posicion: ");

	SecuenciaEnteros posiciones;

	for (int i = 0; i < tamanio_posiciones; i++){

		posiciones.Aniade(lector.LeeEnteroEnRango(0, filas_utilizadas-1));
	}

	// Calculos.

	SecuenciaEnteros fila_similar (tabla.VectorSimilar(referencia, posiciones));

	// Salida de datos.

	cout << endl << endl;
	cout << "La fila mas similar al vector introducido es: " <<
	fila_similar.ToString() << endl << endl;

	cout << "***********************************************" << endl << endl;

	return 0;
}
