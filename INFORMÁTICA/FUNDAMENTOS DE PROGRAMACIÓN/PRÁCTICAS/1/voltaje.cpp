/* Crear un programa que pida un valor de intensidad y resistencia e imprima el
voltaje correspondiente, según la Ley de Ohm:

                        voltaje = intensidad * resistencia
*/

#include <iostream>

using namespace std;

int main() {

  double voltaje, intensidad, resistencia;

  cout << "Introduce un valor para la intensidad" << endl;
  cin >> intensidad;

  cout << "Introduce un valor para la resistencia" << endl;
  cin >> resistencia;

  voltaje = intensidad * resistencia;
  cout << "El voltaje es de " << voltaje << " voltios." << endl;


  return 0;
}
