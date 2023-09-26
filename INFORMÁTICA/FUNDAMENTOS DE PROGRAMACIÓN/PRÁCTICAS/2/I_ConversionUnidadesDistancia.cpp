/*

15. Realizar un programa que nos pida una longitud cualquiera dada en metros.
El programa deberá calcular el equivalente de dicha longitud en pulgadas,
pies, yardas y millas, y mostrarnos los resultados en pantalla.

Para el cálculo, utilice la siguiente tabla de conversión del sistema métrico:

1 pulgada= 25,4 milímetros                1 yarda = 0,9144 metros
1 pie = 30,48 centímetros                 1 milla = 1,609344 kilómetros

*/

#include <iostream>

using namespace std;

int main() {

  //Declaración de variables.

  double medida, medida_pulgada, medida_pie, medida_yarda, medida_milla;

  //Solicitud de datos al usuario.

  cout << "***********************************************" << endl << endl;
  cout << "Introduzca una medida en metros. ";
  cin >> medida;
  cout << endl << endl;
  cout << "***********************************************" << endl << endl;

  /* Operaciones: divido la medida en metros entre su correspondiente,
  después de pasar éste a metros. */

  medida_pulgada = medida / (25.4 / 1000);
  medida_pie = medida / (30.48 /100);
  medida_yarda = medida / 0.9144;
  medida_milla = medida / (1.609344 * 1000);

  //Salida de datos.

  cout << medida << " metros es igual a " << medida_pulgada << " pulgadas, ";
  cout << medida_pie << " pies, " << medida_yarda << " yardas y ";
  cout << medida_milla << " millas." << endl << endl;

  return 0;
}
