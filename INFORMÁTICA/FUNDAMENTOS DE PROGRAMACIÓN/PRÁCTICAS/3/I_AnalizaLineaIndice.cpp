/*
41. En este ejercicio se va a procesar el contenido de una cadena de caracteres
extrayendo sus componentes. El dato string que se va a procesar tiene un
formato fijo y predeterminado.

Las cadenas a procesar podrían ser líneas extraidas del índice de un documento.
En este caso, en concreto, están formadas por:

• un número que indica la sección (ocupa las tres primeras casillas y tiene un
máximo de tres dígitos),

• un número que indica la subsección (ocupa las tres siguientes casillas y
tiene un máximo de tres dígitos),

• un número que indica la subsubsección (ocupa las tres siguientes casillas y
tiene un máximo de tres dígitos),

• una serie de 40 caracteres que contiene el título del apartado, y

• un número que indica la página (ocupa las tres siguientes casillas y tiene un
máximo de cuatro dígitos).

Con estas indicaciones las cadenas tendrán una longitud -exacta- de 53
caracteres.

Por ejemplo, en la siguiente cadena (los puntos indican los espacios de la
cadena -se escriben en el ejemplo para ayudar a entenderlo- y las barras
inicial y final -que no forman parte de la cadena- se escriben para que quede
claro dónde empieza y termina la cadena):

|..1..1..4El.proceso.de.Compilacion.................13|

El resultado que mostrará el programa será:
Componentes:
Seccion: 1
Subseccion: 1
Subsubseccion: 4
Pagina: 13
Titulo: El proceso de Compilacion
Linea procesada:
1.1.4. El proceso de Compilacion 13

Nota: En la cadena leida, las secciones se numeran con un cero en la subsección
y subsubseción. Las subsecciones se numeran con un cero en la subsubseción.

Ejemplos:
|..1..0..0Introduccion.a.la.Programacion.............1|
|..1..1..0El.ordenador,.algoritmos.y.programas.......2|
*/

#include <iostream>
#include <string>

using namespace std;

int main() {

  //Declaración de variables.

  string indice;


  //Solicitud de datos al usuario.

  cout << "***********************************************" << endl << endl;
  cout << "Introduzca la cadena que desea analizar.";
  getline (cin, indice);
  cout << endl << endl;
  cout << "***********************************************" << endl << endl;

  /* Creo una cadena de caracteres para cada apartado que quiero mostrar.
  A cada uno le asigno su porción correspondiente del índice introducido
  por el usuario mediante la funcion substr (). */

  string seccion = indice.substr (0,3);
  string subseccion = indice.substr (3,3);
  string subsubseccion = indice.substr (6,3);
  string titulo = indice.substr (9,39);
  string pagina = indice.substr (49,4);

  //Salida de datos.

  cout << "Componentes: " << endl << endl;
  cout << "Seccion: " << seccion << endl;
  cout << "Subseccion: " << subseccion << endl;
  cout << "Subsubseccion: " << subsubseccion << endl;
  cout << "Pagina: " << pagina << endl;
  cout << "Titulo: " << titulo << endl << endl;
  cout << "***********************************************" << endl << endl;



  return 0;
}
