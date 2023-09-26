/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS III

36. Como indica la Agencia Tributaria en

https://www.agenciatributaria.es/AEAT.internet/Inicio/La_
Agencia_Tributaria/Campanas/Censos__NIF_y_domicilio_fiscal/
Ciudadanos/Informacion/NIF_de_personas_fisicas.shtml

Con carácter general, el número de identificación fiscal de las personas
físicas de nacionalidad española será el número de su documento nacional de
identidad seguido por el código de verificación (DNI) y para los que carezcan
de nacionalidad española será el número de identidad de extranjero (NIE).
El Ministerio del Interior es el órgano competente para su asignación.

Escriba una función que verifique la validez de un NIF (de españoles residentes
mayores de edad) y del NIE (de extranjeros residentes en España).

En http://www.interior.gob.es/web/servicios-al-ciudadano/dni/
calculo-del-digito-de-control-del-nif-nie encontrará las especificaciones
técnicas para este cometido.

Escriba un programa que lea un número indefinido de NIFs/NIEs (finaliza cuando
de introduzca FIN) y verifique su validez.

Modularice el programa adecuadamente, usando funciones.

Puede comprobar los resultados obtenidos en http://letradni.appspot.com

ENTRADA: un NIF o NIE.
SALIDA: Si es valido o no.

*/

#include <iostream>
#include <string>
#include <cctype>


using namespace std;

const string TERMINADOR = "FIN";
const int NUMERO_MAX = 9;

char Letra (string secuencia){

	const int VERIFICADOR = 23;
	int longitud = secuencia.length();

	/* Si la secuencia fuera un NIF, cambio la primera letra por su
	correspondiente. */

	if (toupper (secuencia.at (0)) == 'X') secuencia.at (0) = '0';
	else if (toupper (secuencia.at (0)) == 'Y') secuencia.at (0) = '1';
	else if (toupper (secuencia.at (0)) == 'Z') secuencia.at (0) = '2';

	string parte_numerica = secuencia.substr (0, longitud - 1);
 	int parte_numerica_int = stoi (parte_numerica);

	int resto = parte_numerica_int % VERIFICADOR;
	string letras = "TRWAGMYFPDXBNJZSQVHLCKE";

	return letras.at(resto);
}
/********************************************************************
Letra: funcion que obtiene la letra final de un NIF/NIE.

Consiste en guardar la parte numerica de la secuencia y dividirla entre 23,
segun el algoritmo verificador, ya que despues se comparara la letra obtenida
segun el resto de la division, con la introducida.

Precondicion: que la secuencia introducida tenga 9 caracteres y una letra final,
o bien que tenga 9 caracteres y una letra inicial y final en el caso del NIE.
*********************************************************************/

bool EsValido (string secuencia){

	bool datos_ok = true;
	int longitud = secuencia.length();

	if (secuencia.at(longitud - 1) != Letra(secuencia)){
		datos_ok = false;
	}

	return datos_ok;

}

/********************************************************************
EsValido: funcion que verifica un NIF/NIE.

Compara la letra asociada a una secuancia de numeros determinada con la
introducida.

Precondicion: que la secuencia introducida tenga 9 caracteres y una letra final,
o bien que tenga 9 caracteres y una letra inicial y final en el caso del NIE.
*********************************************************************/

int main() {

	//Declaraciones.
	string secuencia;
	bool es_valido;
	int longitud;


	//Entrada de datos.

	cout << "***********************************************" << endl << endl;

	do{ //Filtro
		cout << "Introduzca un NIF/NIE: ";
		getline (cin, secuencia);
		longitud = secuencia.length();

	}while (longitud != NUMERO_MAX && secuencia != TERMINADOR);
	cout << endl;

	//Calculos.

	while (secuencia != TERMINADOR) {

		es_valido = (EsValido (secuencia));

		//Salida de datos.
		if (es_valido) cout << "Es valido." << endl << endl;
		else cout << "No es valido." << endl << endl;

		// Consecuencia de lectura anticipada:
		do{
			cout << "Introduzca un NIF/NIE: ";
			getline (cin, secuencia);
			longitud = secuencia.length();

		}while (longitud != NUMERO_MAX && secuencia != TERMINADOR);
		cout << endl;

	}

	cout << "***********************************************" << endl << endl;



	return 0;
}
