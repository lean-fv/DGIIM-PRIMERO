/*

Cread un programa que nos pida la longitud del radio, calcule el área del círculo y
la longitud de la circunferencia correspondientes, y nos muestre los resultados en
pantalla. Recordad que:
longitud circunferencia = 2*pi*r área circulo = pi*r2

*/

#include <iostream>

using namespace std;

int main() {

  double radio, pi=3.1415927, longitud_circunferencia, area_circulo;

  cout << "Introduzca un valor para el radio de la circunferencia en metros." << endl;
  cin>> radio;

  longitud_circunferencia= 2*pi*radio;
  cout << "La longitud de la circunferencia es de " << longitud_circunferencia << " metros." <<endl;

  area_circulo= pi*radio*radio;
  cout << "El área del círculo es de " << area_circulo << " metros." << endl;


  return 0;
}
