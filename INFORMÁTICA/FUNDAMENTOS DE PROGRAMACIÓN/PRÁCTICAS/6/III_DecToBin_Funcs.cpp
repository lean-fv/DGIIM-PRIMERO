/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS III

38. En el ejercicio 84 de la Relación de Problemas II se calculaba un dato
string que contenía la representación binaria de un número entero (positivo o
cero) usando un número predeterminado de bits.

Esta tarea se va a delegar a una función. Recibirá el número a codificar
num_decimal y el número de bits num_bits. Devolverá un string formado por
caracteres '0' ó '1' que contiene la representación binaria de num_decimal.

string DecToBin (int num_decimal, int num_bits);

La función proporciona siempre una representación correcta por lo que si
num_bits es menor que el número mínimo de bits que se necesitan, devolverá un
string con la longitud necesaria.

Por ejemplo, 35)10 = 100011)2 (6 bits). Las llamadas:

• DecToBin (35, 8) devuelve el string 00100011.
El valor decimal 33 requiere 6 bits, pero al llamar a la función pidiendo 8
bits se completa con dos ceros a la izquierda.

• DecToBin (35, 4) devuelve el string 100011. El valor decimal 33 requiere
6 bits, pero al llamar a la función pidiendo 4 bits se devuelve la cadena
formada por los 6 bits estrictamente necesarios.

Escriba un programa que pida un número entero n (n ≥ 0) y un número de bits t
(t > 0) y muestre la representación binaria de todos los valores 0 ≤ x ≤ n.
El resultado se mostrará en forma de tabla, con tres columnas: x,
representación binaria -estricta- de x y representación binaria de x con t bits
(ver figura 19).

ENTRADA: numero en base decimal.
SALIDA: el numero en binario con tantos bits como se desee.
*/

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

/* El proceso consiste en dividir entre dos tantas veces como sea posible y
tomar el ultimo cociente y todos los restos (0 y 1) en orden ascendente. Ese
sera el numero en binario. */
string DecToBin_Estricto (int num_decimal){


	string num_final;
	int binario;
	const char CERO = '0';
	const char UNO = '1';
	string numero_binario = "";

  if (num_decimal == 0){
    num_final = CERO;
  }

  else{

    while (num_decimal/2 != 1){
  		binario = num_decimal % 2;

      if (binario == 0) {
  			numero_binario = CERO + numero_binario;
  		} else if (binario == 1) {
  			numero_binario = UNO + numero_binario;
  		}

  		num_decimal = num_decimal/2;

  	}

  /* Cuando se lleva a cabo la ultima division, hay que determinar cual es el
  ultimo resto. */

    binario =  num_decimal % 2;

  		if (binario == 0){
  			num_final = CERO + numero_binario;
  		} else if (binario == 1){
  			num_final = UNO + numero_binario;
  		}

  //El ultimo cociente se coge y siempre sera 1.
  		num_final = UNO + num_final;
  }

  return num_final;

}

string DecToBin (int num_decimal, int num_bits){

	const char CERO = '0';

	string num_final = DecToBin_Estricto (num_decimal);
	//Se añade un cero mientras la longitud sea menor que los bits deseados.
	while (num_final.length() < num_bits) {
		num_final = CERO + num_final;
	}

	return num_final;
}


int main (){

	int num_decimal;
	int t;
	string num_final;


	//Entrada de datos.

  cout << "***********************************************" << endl << endl;

  do { //Filtro para binarios positivos.
    cout << "Introduzca el numero positivo a pasar a binario: ";
  	cin >> num_decimal;
  }while (num_decimal < 0);

  do { //Filtro para los bits a usar.
    cout << "Indique con cuantos bits desea que se represente: ";
  	cin >> t;
  } while (t <= 0);

	//Calculos.

	string num_final_estricto = DecToBin_Estricto (num_decimal);
	num_final = DecToBin (num_decimal, t);

	//Salida de datos.

	cout << "Numero binario estricto " << num_final_estricto << endl;
	cout << "Numero binario con bits deseados: " << num_final << endl << endl;

	/* No he conseguido hacer la tabla, ya que se corta despues del 0, aunque las
	funciones realizan correctamente su programacion. */
	const int ESPACIADO = 8;
	cout << "|		X	|  Estricto		|"
			 << setw(ESPACIADO) << t << " bits			|" << endl;


	for (int i = 0; i <= num_decimal; i++){

		num_final_estricto = DecToBin_Estricto (i);
		num_final = DecToBin (i, t);

		cout << "|		" << setw (ESPACIADO) << i << "|		"
				 << setw(ESPACIADO)
				 << num_final_estricto << "|     " <<  setw(ESPACIADO) << "		"
				 << num_final << "|";
				 cout << endl;
	}

	//cout << "El numero en binario sera: " << num_final << endl << endl;

  cout << "***********************************************" << endl << endl;


	return 0;
}
