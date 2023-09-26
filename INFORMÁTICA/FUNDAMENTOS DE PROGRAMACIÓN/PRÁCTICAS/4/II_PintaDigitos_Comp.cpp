/* **************************************************************************

	 FUNDAMENTOS DE PROGRAMACI�N

 	 LEANDRO JORGE FERNÁNDEZ VEGA
 	 DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS


 	 RELACI�N DE PROBLEMAS II

   Programa que lee un entero de tres d�gitos y los muestra individualmente,
   separ�ndolos por tres espacios.

   Entradas: un entero
   Salidas:  Los d�gitos del entero leido.

******************************************************************** */

#include <iostream>
#include <string>
using namespace std;

int main()
{
	// Entrada

	// Dato de entrada: una cadena formada por tres d�gitos decimales
	string cad_3digitos;

	cout << "Introduce un entero de tres digitos: ";
	cin >> cad_3digitos;

	int numero_3dig; // n�mero de 3 d�gitos (unidades, decenas y centenas)
	int numero_2dig; // n�mero de 2 d�gitos (unidades y decenas)

	int centenas; // d�gito de las centenas
	int decenas;  // d�gito de las decenas
	int unidades; // d�gito de las unidades

	const int EXTREMO_INTERVALO_1 = 100;
	const int EXTREMO_INTERVALO_2 = 999;

	// Transformar "cad_3digitos" (string) a numero_3dig (int)
	numero_3dig = stoi(cad_3digitos);

  //Bandera
  bool es_numero_3dig = ((numero_3dig >= EXTREMO_INTERVALO_1)
											&& (numero_3dig <= EXTREMO_INTERVALO_2));


  // C�lculos

  if (es_numero_3dig){

    centenas    = numero_3dig / 100; // Valor de las centenas
  	numero_2dig = numero_3dig % 100; // Las dos cifras menos significativas

  	decenas     = numero_2dig / 10;  // Valor de las decenas
  	unidades    = numero_2dig % 10;  // La cifra menos significativa(unidades)

  }

  const string SEPARADOR = "...";
  string cad_resultado = SEPARADOR + to_string(centenas) +
               SEPARADOR + to_string(decenas) +
                         SEPARADOR + to_string(unidades);

	// Salida

	cout << endl;

  if (es_numero_3dig){

    cout << cad_resultado << endl;
  }

  else {

    cout << "No ha introducido bien los datos. ";
  }

  cout << endl;

	return 0;
}
