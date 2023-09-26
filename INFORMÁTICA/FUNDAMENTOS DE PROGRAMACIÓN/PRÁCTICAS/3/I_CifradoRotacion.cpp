/*
28. Para intercambiar mensajes de forma privada, se utilizan distintos
algoritmos que codifican/descodifican una cadena de caracteres.

Uno de los más sencillos y que fue utilizado por Julio César durante la época
del Imperio Romano es el de rotación. Consiste en seleccionar una clave
(un número entero), y desplazar las letras del alfabeto tantas posiciones como
indica la clave. Trabajaremos únicamente con mayúsculas.

Se considera una representación circular del alfabeto, de tal forma que
el carácter que sigue a ’Z’ es ’A’. Por ejemplo, si clave=4, entonces la
’A’ se reemplaza por la ’E’ y la ’Z’ por la ’D’. Utilizando clave=0 la
secuencia cifrada es igual a la original.

Construya un programa que lea un entero representando la clave y un carácter
(supondremos que se introduce correctamente una letra mayúscula del alfabeto
inglés).

El programa codificará el carácter según la clave introducida y lo mostrará
por pantalla.
*/

#include <iostream>

using namespace std;

int main() {

  //Declaración de variables.
  char letra, letra_cifrada;
  int clave;
  const char MIN = 'A';

  //Solicitud de datos al usuario.

  cout << "***********************************************" << endl << endl;

  cout << "Introduzca una letra mayuscula. ";
  cin >> letra;

  cout << endl << endl;
  cout << "***********************************************" << endl << endl;

  cout << "Introduzca su clave. ";
  cin >> clave;
  cout << endl << endl;

  /*

  El cifrado se realiza desplazando posiciones. Como solo se considera
  nuestro alfabeto, al rebasar la Z habría que regresar a la A.

  Para que el cifrado coincida con la letra introducida, ésta se debe
  desplazar 27 veces, que son las letras que tiene nuestro abecedario.

  Por ello, debemos sumar al primer elemento del intervalo (A) el espacio
  desplazado, que es la diferencia de nuestra letra y la A, sumado al
  desplazamiento de cifrado.

  Si se sale del intervalo, debemos ver cuánto espacio de más
  ha salido (de ahí el módulo con 27) y sumarlo a la A.

 */

  letra_cifrada = MIN + ((letra - MIN + clave) % 27);

  //Salida de datos.

  cout << "Su letra cifrada es " << letra_cifrada << endl;
  cout << "***********************************************" << endl << endl;



  return 0;
}
