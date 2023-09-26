/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS II

81. Escribir un programa en el que se presente un menú principal para que el
usuario pueda elegir entre las siguientes opciones:

A–>Calcular adición.
P–>Calcular producto.
X–>Salir.

Si el usuario elige en el menú principal:

a) Salir, el programa terminará su ejecución.

b) Calcular adición se presenta un menú (secundario) para que el usuario pueda
elegir entre las siguientes opciones:

S–>Calcular suma.
R–>Calcular resta.
X–>Salir.

c) Calcular producto se presenta un menú (secundario) para que el usuario
pueda elegir entre las siguientes opciones:

M–>Calcular multiplicación.
D–>Calcular división.
X–>Salir.

En las operaciones seleccionadas desde los menús secundarios el programa pedirá
dos números reales, realizará la operación seleccionada, mostrará el resultado
y volverá a mostrar el menú secundario seleccionado anteriormente.

En los dos menús secundarios la selección de Salir hace que el programa vuelva
a mostrar el menú principal.

ENTRADA: caracter para elegir una opcion, dentro de ella otras mas, o salir.
SALIDA: resultado de suma, resta, multiplicacion y division.

*/

#include <iostream>
#include <cctype>

using namespace std;

int main() {

  //Declaraciones.

  //Posibilidades de opcion en ambos niveles.
  char opcion1, opcion2, opcion3;
  const char ADICION = 'A', PRODUCTO = 'P', FIN = 'X';
  const char SUMA = 'S', RESTA = 'R';
  const char MULTIPLICACION = 'M', DIVISION = 'D';

  //Variables de calculo en el segundo nivel.
  double numero_suma1, numero_suma2;
  double numero_resta1, numero_resta2;
  double numero_multiplicacion1, numero_multiplicacion2;
  double numero_division1, numero_division2;
  double resultado;



  //Entrada de datos.

  cout << "***********************************************" << endl << endl;

  do{
    cout << "A–>Calcular adición. " << endl;
    cout << "P–>Calcular producto. " << endl;
    cout << "X–>Salir. " << endl << endl;


    do{ //Filtro de error primer menu.
      cout << "Introduzca un caracter. ";
      cin >> opcion1;
      cout << endl << endl;
      opcion1 = toupper (opcion1);
    }while (opcion1 != ADICION && opcion1 != PRODUCTO && opcion1 != FIN);

    //Calculos.

        if (opcion1 == ADICION){

          do{
            cout << "S–>Calcular suma. " << endl;
            cout << "R–>Calcular resta. " << endl;
            cout << "X–>Salir. " << endl << endl;

            do{ //Filtro de errores segundo menu.
              cout << "Introduzca un caracter. ";
              cin >> opcion2;
              opcion2 = toupper (opcion2);
            } while (opcion2 != SUMA && opcion2 != RESTA && opcion2 != FIN);


            if (opcion2 == SUMA){
              cout << "Introduzca un primer numero. ";
              cin >> numero_suma1;
              cout << "Introduzca un segundo numero. ";
              cin >> numero_suma2;
              resultado = numero_suma1 + numero_suma2;
            } //Suma

            else if (opcion2 == RESTA){
              cout << "Introduzca un primer numero. ";
              cin >> numero_resta1;
              cout << "Introduzca un segundo numero. ";
              cin >> numero_resta2;
              resultado = numero_resta1 - numero_resta2;
            } //Resta
            //Salida de datos de la adicion.
            if (opcion2 == SUMA || opcion2 == RESTA){
              cout << "El resultado es " << resultado << endl << endl;
            }
          }while (opcion2 != FIN); //Volver a mostrar segundo menu.
        } //Adicion

        else if (opcion1 == PRODUCTO){

          do{

            cout << "M–>Calcular multiplicacion. " << endl;
            cout << "D–>Calcular division. " << endl;
            cout << "X–>Salir. " << endl << endl;

            do{ //Filtro de error segundo menu.
              cout << "Introduzca un caracter. ";
              cin >> opcion2;
              opcion2 = toupper (opcion2);
            } while (opcion2 != MULTIPLICACION && opcion2 != DIVISION
              && opcion2 != FIN);

            if (opcion2 == MULTIPLICACION){
              cout << "Introduzca un primer numero. ";
              cin >> numero_multiplicacion1;
              cout << "Introduzca un segundo numero. ";
              cin >> numero_multiplicacion2;
              resultado = numero_multiplicacion1 * numero_multiplicacion2;
            } //Multiplicacion.

            else if (opcion2 == DIVISION){
              cout << "Introduzca un numerador. ";
              cin >> numero_division1;
              do{ //Filtro de un denominador igual a 0.
                cout << "Introduzca un denominador distinto de 0. ";
                cin >> numero_division2;
              } while (numero_division2 == 0);
              resultado = numero_division1 / numero_division2;
            } //Division
            //Salida de datos del producto.
            if (opcion2 == MULTIPLICACION || opcion2 == DIVISION){
              cout << "El resultado es " << resultado << endl << endl;
            }
          }while (opcion2 != FIN);//Volver a mostrar segundo menu.
        } //Producto

  }while (opcion1 != FIN); //Primer menu.

  //Salida de datos al salir.
  cout << "Ha salido." << endl << endl;

  cout << "***********************************************" << endl << endl;



  return 0;
}
