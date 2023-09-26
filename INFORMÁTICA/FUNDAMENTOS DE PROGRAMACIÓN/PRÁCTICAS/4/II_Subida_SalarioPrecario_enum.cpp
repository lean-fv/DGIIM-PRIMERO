/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS II

20. Cread un programa que lea el valor de la edad (dato de tipo entero) y
salario (dato de tipo real) de una persona.

Subid el salario un 4 % si es  mayor de 65 o menor de 35 años.
Si además de cumplir la anterior condición, también tiene un salario inferior
a 300 euros, se le subirá otro 3 %, mientras que si su salario es mayor o
igual que 300 euros pero inferior a 900 euros se le subirá un sólo el 1.5 %.

Imprimid el resultado por pantalla indicando qué subidas se han aplicado.

ENTRADA: Una edad y un salario.
SALIDA: Subidas aplicadas al salario segun edad y salario.

*/

#include <iostream>

using namespace std;

int main() {

  //Declaración.

  //Clases:
  enum class Edad {menos35_mas65};
  enum class Salario {salario_menos300, salario_entre_300y900};

  Edad persona_edad;
  Salario persona_salario;

  //Edad:
  int edad;
  const int EDAD_FRONTERA1 = 35;
  const int EDAD_FRONTERA2 = 65;
  const double SUBIDA1 = 0.04;

  //Salario:
  double salario, salario_final;
  const int SALARIO_FRONTERA1 = 300;
  const int SALARIO_FRONTERA2 = 900;
  const double SUBIDA2 = 0.03;
  const double SUBIDA3 = 0.015;



  //Entrada de datos.

  cout << "***********************************************" << endl << endl;
  cout << "Introduzca una edad. ";
  cin >> edad;
  cout << endl << endl;
  cout << "Introduzca un salario. ";
  cin >> salario;
  cout << endl << endl;

  //Calculos.
  salario_final = salario;

  if ((edad < EDAD_FRONTERA1) || (edad > EDAD_FRONTERA2)){

    salario_final = salario_final + salario * SUBIDA1;
    persona_edad = Edad :: menos35_mas65;

    if (salario < SALARIO_FRONTERA1){

      salario_final = salario_final + salario * SUBIDA2;
      persona_salario = Salario :: salario_menos300;

    }

    else {

      if ((salario >= SALARIO_FRONTERA1) && (salario < SALARIO_FRONTERA2)){

        salario_final = salario_final * SUBIDA3;
        persona_salario = Salario :: salario_entre_300y900;
      }

    }

  }


  //Salida de datos.

  bool esta_en_edad = (persona_edad == Edad :: menos35_mas65);
  bool salario_menos_300 = (persona_salario == Salario :: salario_menos300);
  bool salario_entre_300_y_900 =
  (persona_salario == Salario :: salario_entre_300y900);

  cout << "En la edad: " << (esta_en_edad ? "SI" : "NO") << endl;
  cout << "Subida por salario menos de 300 euros: "
       << (salario_menos_300 ? "SI" : "NO") << endl;
  cout << "Subida por salario entre 300 y 900 euros "
       << (salario_entre_300_y_900 ? "SI" : "NO") << endl;
  cout << "Salario final: " << salario_final << endl << endl;
  cout << "***********************************************" << endl << endl;



  return 0;
}
