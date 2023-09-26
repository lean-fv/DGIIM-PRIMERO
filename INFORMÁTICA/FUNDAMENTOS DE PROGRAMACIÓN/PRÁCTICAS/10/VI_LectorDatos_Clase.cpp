/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS VI

13. Encapsule en la clase Lector las funciones escritas en los ejercicios 17 y
18 de la Relación de Problemas III. El objetivo es disponer de una clase
(Lector) que ofrezca un conjunto de métodos seguros de lectura etiquetada de
datos int y double.

Deberá deducir la estructura de la clase a partir del siguiente ejemplo. Los
datos double se leerán de manera similar.

// Lectura de un entero

Lector lector_temp("Temperatura: ");
int temp = lector_temp.LeeEntero();
cout << "Temperatura leida = " << temp << endl;

// Lectura de enteros acotados superior e inferiormente
Lector lector_hora;

lector_hora.SetTitulo ("Introduzca hora: ");
int h = lector_hora.LeeEnteroEnRango (0, 23);
lector_hora.SetTitulo ("Introduzca minuto: ");
int m = lector_hora.LeeEnteroEnRango (0, 59);
lector_hora.SetTitulo ("Introduzca segundo: ");
int s = lector_hora.LeeEnteroEnRango (0, 59);
cout << "Hora: " << h << ":" << m << ":" << s << endl;

// Lectura de un entero acotado inferiormente

Lector lector_ingreso("Cantidad a ingresar: ");
int ingreso = lector_ingreso.LeeEnteroMayorOIgual (0);
cout << "Valor del ingreso = " << ingreso << endl;

ENTRADA: valores enteros y reales.
SALIDA: los valores enteros y reales siempre que lo introducido en cada seccion
sea o entero o real y cumpla las condiciones de cada seccion.

*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


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

			cout << mensaje;
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
	 		cout << mensaje;
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

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);

	cout << "***********************************************" << endl << endl;

	cout << setw (40) << "LECTURA DE ENTEROS" << endl;
	cout << "----------------------------------------------------------------";
	cout << endl << endl << endl;

	// Lectura de un entero

	Lector lector_temp("Temperatura: ");
	int temp = lector_temp.LeeEntero();
	cout << "Temperatura leida = " << temp << endl << endl;

	// Lectura de enteros acotados superior e inferiormente

	string cadena;
	Lector lector_hora;

	lector_hora.SetTitulo ("Introduzca hora: ");
	int h = lector_hora.LeeEnteroEnRango (0, 23);
	cout << endl;

	lector_hora.SetTitulo ("Introduzca minuto: ");
	int m = lector_hora.LeeEnteroEnRango (0, 59);
	cout << endl;

	lector_hora.SetTitulo ("Introduzca segundo: ");
	int s = lector_hora.LeeEnteroEnRango (0, 59);
	cout << endl;

	cout << "Hora: " << h << ":" << m << ":" << s << endl << endl;

	// Lectura de un entero acotado inferiormente

	Lector lector_ingreso("Cantidad a ingresar (>=0): ");
	int ingreso = lector_ingreso.LeeEnteroMayorOIgual (0);
	cout << "Valor del ingreso = " << ingreso << endl << endl << endl << endl;


	//-----------------------------------------------------------------------

	cout << setw (40) << "LECTURA DE REALES" << endl;
	cout << "----------------------------------------------------------------";
	cout << endl << endl << endl;

	// Lectura de un valor real arbitrario

	lector_temp.SetTitulo("Temperatura (con decimales): ");
	double temperatura = lector_temp.LeeReal();
	cout << endl;

	cout << "Valor de la temperatura = " << temperatura << endl << endl;


	// Lectura de un real acotado superior e inferiormente

	Lector lector_iva("IVA -entre 4.0 y 21.0-: ");

	double iva = lector_iva.LeeRealEnRango (4.0, 21.0);

	cout << endl;
	cout << "Valor del IVA = " << iva << endl << endl;

	// Lectura de un real acotado superior e inferiormente

	lector_iva.SetTitulo("Introduzca IVA (>=4.0): ");
	iva = lector_iva.LeeRealMayorOIgual (4.0);

	cout << endl;
	cout << "Valor del IVA = " << iva << endl << endl;

	cout << "***********************************************" << endl << endl;


	return 0;
}
