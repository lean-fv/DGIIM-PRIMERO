/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS II

7. Una compañía aérea establece el precio del billete como sigue: en primer
lugar se fija una tarifa base de 150 euros, la misma para todos los destinos.
A continuación se suman 10 céntimos por cada kilómetro de distancia al destino.
Cree un programa que lea el número de kilómetros al destino y calcule el
precio final del billete.

4. Retome la solución del ejercicio 7 de la Relación de Problemas I.
La forma de calcular la tarifa final del billete cambia ahora de la forma
siguiente:

la tarifa base sigue siendo de 150 euros, la misma para todos los destinos.
Ahora bien, si el destino está a menos de 300 kilómetros, el precio final es
la tarifa base. Para destinos a más de  300 Km, se suman 10 céntimos por cada
kilómetro de distancia al destino  (a partir del Km 300).

Cree un programa para que lea el número de kilómetros al destino y calcule el
precio final del billete.

5. Continuando con el problema del cálculo de las tarifas aéreas que hemos
iniciado en el ejercicio 4 de esta relación de problemas, ahora se van a
aplicar descuentos a las tarifas ya calculadas. Los criterios a aplicar son
los siguientes:

a) Un primer descuento está determinado por el número de kilómetros del
trayecto. Si el trayecto es mayor de 700 km, se aplica un descuento del 2 %.

b) El segundo descuento dependerá del número de puntos de la tarjeta de
fidelización del cliente. Si el número de puntos es mayor de 100, se aplica
un descuento del 3 % y si es mayor de 200, se aplica un descuento del 4 %.

Los dos descuentos anteriores son independientes y acumulables. En cualquier
caso, ambos se aplican sobre el precio del billete: en este programa un
cliente  podría beneficiarse de un descuento del 2 %, del 3 %, del 4 %,
del 5 %,  del 6 %, o ninguno.

ENTRADA: numero de km y puntos.
SALIDA: precio final a pagar.
*/

#include <iostream>

using namespace std;

int main() {

  //Declaración de variables

  const int TARIFA_BASE = 150;
  const double PRECIO_KM = 0.1;
  const int KM_FRONTERA1 = 300;
  double numero_km, precio_final;

  //Descuento según km:
  const int KM_FRONTERA2 = 700;
  const double DESCUENTO1 = 0.02;

  //Descuento según puntos:
  int puntos;
  const int PUNTOS1 = 100;
  const double DESCUENTO2 = 0.03;
  const int PUNTOS2 = 200;
  const double DESCUENTO3 = 0.04;


  //Solicitud de datos al usuario.

  cout << "*************************************************" << endl << endl;
  cout << "Introduzca los kilómetros hasta su destino. ";
  cin >> numero_km;
  cout << endl;

  bool km_correctos = (numero_km >= 0);                       //Bandera.

  if (km_correctos){

    cout << "Introduzca sus puntos. ";
    cin >> puntos;
  }

  bool puntos_correctos = (puntos >= 0);                      //Bandera.
  bool datos_correctos = (km_correctos && puntos_correctos);  //Bandera
  cout << endl << endl;


  //Cálculo del precio.

  if (datos_correctos){

    precio_final = TARIFA_BASE;

    if (numero_km < KM_FRONTERA1){

      precio_final = TARIFA_BASE;

    }

    else {

      //Como se cobran 10 cent por cada km a partir de los 300, resto ambos.
      precio_final = precio_final + (numero_km - KM_FRONTERA1) * PRECIO_KM;

    }

    //Descuento si se superan los 700 km.
    if (numero_km > KM_FRONTERA2){

      precio_final = precio_final - precio_final * DESCUENTO1;
    }

    //Descuento si se superan los 100 puntos.
    if ((puntos > PUNTOS1) && (puntos <= PUNTOS2)) {

      precio_final = precio_final - precio_final * DESCUENTO2;
    }

    //Descuento si se superan os 200 puntos.
    if (puntos > PUNTOS2){

      precio_final = precio_final - precio_final * DESCUENTO3;
    }

  }

  //Salida de datos.

  cout << "*************************************************" << endl << endl;

  if (datos_correctos){

    cout << "El precio es " << precio_final << " euros.";

  }

  else {

    cout << "No ha introducido bien los datos.";
  }

  cout <<  endl << endl;



  return 0;
}
