/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS VI

14. Escriba la clase ManipuladorString. Esta clase se encargará de modificar un
dato string y realizar cálculos complejos sobre él con funciones no ofertadas
por la clase string. Proponemos que trabaje sobre el siguiente esquema:

								ManipuladorString
----------------------------------------------------------------------------
- string cadena
----------------------------------------------------------------------------

+ ManipuladorString (void);
+ ManipuladorString (string la_cadena);
+ void SetCadena (string la_cadena);
+ string GetCadena (void);
+ void EliminaPrimerosSeparadores (void);
+ void EliminaUltimosSeparadores (void);
+ void EliminaPrimerosYUltimosSeparadores (void);
+ void ConvierteAMayusculas (void);
+ void ConvierteAMinusculas (void);

-----------------------------------------------------------------------------

Mostraremos la manera de trabajar con esta clase con un ejemplo.

Suponga que quiere eliminar los espacios iniciales y finales de un dato string
llamado nombre. Necesitamos un objeto ManipuladorString que contenga una copia
del dato string que queremos manipular. Hay dos opciones:

a) con el constructor con un argumento:

ManipuladorString m (nombre);

b) con el constructor sin argumentos y el método SetCadena:

ManipuladorString m;
m.SetCadena(nombre);


Después se ejecuta el método deseado sobre m:

m.EliminaPrimerosYUltimosSeparadores();

que modifica el valor del campo privado cadena. Después la instrucción

nombre = m.GetCadena();

deja en nombre el resultado se la manipulación (cadena nombre sin espacios
iniciales ni finales). En cambio, si quisiéramos mantener el valor original de
nombre tendremos que usar otra variable string para guardar el resultado que
devuelve el método GetCadena.

string nombre_limpio = m.GetCadena();

ENTRADA: una cadena de caracteres.
SALIDA: la cadena sin espacios al principio y al final, la cadena en mayuscula
y minuscula.

*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;


/*---------------------------------------------------------------------------
							Clase ManipuladorString
---------------------------------------------------------------------------*/

class ManipuladorString {

private:

	string cadena;

public:


	//Setter.

	void SetCadena (string la_cadena){

		cadena = la_cadena;
	}

	//Getter.

	string GetCadena (void){

		return (cadena);
	}
	/*************************************************************************
	Metodo EliminaUltimosSeparadores: Elimina los últimos caracteres separadores
	de "cadena". Los caracteres  separadores son el espacio en blanco, el
	tabulador y el salto de línea. Usaremos la función isspace() para
	simplificar el cálculo.
	*************************************************************************/


	void EliminaUltimosSeparadores (void)
	{
	   	while (cadena.length()>0 && isspace(cadena.back()))
			cadena.pop_back();

	}

	/*************************************************************************
	Metodo EliminaPrimerosSeparadores: Elimina los primeros caracteres
	separadores de "cadena". Los caracteres separadores son el espacio en
	blanco, el tabulador y el salto de línea. Usaremos la función isspace()
	para simplificar el cálculo.
	*************************************************************************/

	void EliminaPrimerosSeparadores (void)
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

		SetCadena (local);
	}


	/*************************************************************************
	Metodo EliminaPrimerosYUltimosSeparadores: combina los anteriores metodos.
	*************************************************************************/

	void EliminaPrimerosYUltimosSeparadores (void){

		EliminaUltimosSeparadores();
		EliminaPrimerosSeparadores();
	}


	/********************************************************************
	Metodo ConvierteAMayusculas: convierte a mayusculas la cadena entera.
	********************************************************************/

	void ConvierteAMayusculas (void){

		int longitud = (int)cadena.length();
		string local = GetCadena();

		for (int i = 0; i < longitud; i++){

			if (isalpha(local.at(i))){
				local.at(i) = toupper(local.at(i));

			}
		}

		SetCadena(local);
	}

	/********************************************************************
	Metodo ConvierteAMinusculas: convierte a minusculas la cadena entera.
	********************************************************************/

	void ConvierteAMinusculas (void){

		int longitud = (int)cadena.length();
		string local = GetCadena();

		for (int i = 0; i < longitud; i++){

			if (isalpha(local.at(i))){
				local.at(i) = tolower(local.at(i));

			}
		}

		SetCadena(local);

	}

};

/*---------------------------------------------------------------------------
							Programa principal
---------------------------------------------------------------------------*/
int main() {

	//Declaraciones.

	string nombre;
	ManipuladorString m;


	//Entrada de datos.

	cout << "***********************************************" << endl << endl;

	cout << "Introduzca un nombre.";
	getline (cin, nombre);
	cout << endl << endl;

	//Calculos.

	m.SetCadena(nombre);

	m.EliminaPrimerosYUltimosSeparadores();
	string nombre_limpio = m.GetCadena();

	m.ConvierteAMayusculas();
	string nombre_mayusculas = m.GetCadena();

	m.ConvierteAMinusculas();
	string nombre_minusculas = m.GetCadena();

	//Salida de datos.

	cout << "Sin espacios: |" << nombre_limpio << "|" << endl;
	cout << "En mayusculas: " << nombre_mayusculas << endl;
	cout << "En minusculas: " << nombre_minusculas << endl << endl;

	cout << "***********************************************" << endl << endl;



	return 0;
}
