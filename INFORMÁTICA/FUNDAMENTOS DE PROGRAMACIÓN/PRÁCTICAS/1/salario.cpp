// Indique cuál sería el resultado de las siguientes operaciones:

#include <iostream>

using namespace std;

int main() {

  int salario_base;
  int salario_final;
  int incremento;

  salario_base = 1000;
  salario_final = salario_base;                         //1000
  incremento = 200;

  salario_final = salario_final + incremento;           //1200
  salario_base = 3500;

  cout << endl;
  cout << "Salario base: " << salario_base << endl;     //3500
  cout << "Salario final: " << salario_final << endl;   //1200

  return 0;
}

/*

Responda razonadamente a la siguiente pregunta: ¿El hecho de realizar la asignación
salario_final = salario_base; hace que ambas variables estén ligadas
durante todo el programa y que cualquier modificación posterior de salario_base
afecte a salario_final?

No, las variables no están ligadas porque el programa se ejecuta de arriba a abajo,
y los valores se van actualizando conforme se asignen nuevos o se realicen operaciones.

*/
