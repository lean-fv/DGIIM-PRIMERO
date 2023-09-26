/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS II

13. Se quiere leer un carácter letra_original desde teclado y

• Si es una letra mayúscula, almacenaremos en la variable letra_convertida
la correspondiente letra minúscula.

• Si es una letra minúscula, almacenaremos en la variable letra_convertida
la correspondiente letra mayúscula.

• Si es un carácter no alfabético, almacenaremos el mismo carácter en la
variable letra_convertida.

Finalmente, imprimiremos en pantalla alguno de los siguientes mensajes:

• La letra era una mayúscula. Una vez convertida es ...
• La letra era una minúscula. Una vez convertida es ...
• El carácter no era una letra.

21. Tome como referencia la solución al ejercicio 13 de esta misma relación de
problemas.

Ahora deberá emplear un tipo enumerado que permita guardar el tipo de carácter
de letra_original. Considere que ahora podría ser: una letra mayúscula,
una letra minúscula, un dígito u otro carácter.

Importante: las vocales con tilde (mayúsculas y minúsculas) y las letras ú,
Ü, ñ y Ñ se englobarán en la categoría de otros por simplificar la solución.

ENTRADA: un caracter.
SALIDA: su correspondiente en mayuscula, minuscula o igual.

*/

#include <iostream>

using namespace std;

int main() {

  //Declaraciones.

  //Enumeracion.
  enum class TipoCaracter {mayuscula, minuscula, otro};
  TipoCaracter letra;

  //Caracteres.
  char letra_original, letra_convertida;

  //Constantes.
  const int EXTREMO1 = 'A';
  const int EXTREMO2 = 'Z';
  const int EXTREMO3 = 'a';
  const int EXTREMO4 = 'z';
  const int EXTREMO5 = '0';
  const int EXTREMO6 = '9';

  const int CONVERSION_MAYUS = 'B' - 'b';
  const int CONVERSION_MINUS = 'b' - 'B';


  //Entrada de datos.

  cout << "***********************************************" << endl << endl;
  cout << "Introduzca un caracter ";
  cin >> letra_original;
  cout << endl;

  /* Calculos:
  Proceso de transformación de minúscula a mayúscula: sumo al
  carácter el valor correspondiente (que en este caso es + - 32), ya que
  todos los caracteres tienen un valor en la tabla ASCII. */

  if ((letra_original >= EXTREMO1) && (letra_original <= EXTREMO4)) {


    if ((letra_original >= EXTREMO1) && (letra_original <= EXTREMO2)) {

      letra = TipoCaracter :: mayuscula;
      letra_convertida = letra_original + CONVERSION_MINUS;

    } //Mayusculas.

    if ((letra_original >= EXTREMO3) && (letra_original <= EXTREMO4)) {

      letra = TipoCaracter :: minuscula;
      letra_convertida = letra_original + CONVERSION_MAYUS;

    } //Minusculas.
  } //Es letra.

  else {

          letra = TipoCaracter :: otro;
          letra_convertida = letra_original;

  } //No es letra.


  //Salida de datos.

  if (letra == TipoCaracter :: mayuscula){

    cout << "La letra era una mayuscula. Una vez convertida es "
         << letra_convertida;
  }

  if (letra == TipoCaracter :: minuscula){

    cout << "La letra era una minuscula. Una vez convertida es "
         << letra_convertida;
  }

  if (letra == TipoCaracter :: otro){

    cout << "El caracter introducido no era una letra.";

  }

  cout << endl << endl;
  cout << "***********************************************" << endl << endl;



  return 0;
}
