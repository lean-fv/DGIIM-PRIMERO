/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS II

18. Realizar un programa que realice la conversión entre dos unidades de
distancia del SI. Las unidades contempladas serán: mm (milímetros),
cm (centímetros), m (metros) y km (kilómetros).

El programa mostrará el prompt > y el usuario escribirá cuatro tokens:

valor unidad_inicial a unidad_final

y el programa mostrará el resultado de la transformación.

Por ejemplo, si quisiéramos transformar 7 centímetros a metros escribiremos:
> 7 cm a m
7.000 cm = 0.007 m

y para convertir 5.2 kilómetros a milímetros:
> 5.2 km a mm
5.200 km = 5200000.000 mm

ENTRADA: Una medida en una unidad.
SALIDA: La medida convertida a otra unidad.

*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {

  //Declaración de variables.
  double medida, medida_final;
  string unidad_inicial, unidad_final;
  char palabra_a;

  //Declaracion de constantes.
  const char LETRA_A = 'a';
  const string MM = "mm";
  const string CM = "cm";
  const string M = "m";
  const string KM = "km";
  const int MULTIPLO_10 = 10;
  const int MULTIPLO_100 = 100;
  const int MULTIPLO_1000 = 1000;
  const int MULTIPLO_100000 = 100000;
  const int MULTIPLO_1M = 1000000;

  //Entrada de datos.

  cout << "***********************************************" << endl << endl;
  cout << "> ";
  cin >> medida;
  cin >> unidad_inicial;
  cin >> palabra_a;
  cin >> unidad_final;
  cout << endl;

  //Banderas.
  bool medida_correcta = (medida >= 0);

  bool unidad_inicial_correcta = ((unidad_inicial == MM)
  || (unidad_inicial == CM) || (unidad_inicial == M)
  || (unidad_inicial == KM));

  bool palabra_a_correcta = (palabra_a == LETRA_A);

  bool unidad_final_correcta = ((unidad_final == MM)
  || (unidad_final == CM) || (unidad_final == M) ||(unidad_final == KM));

  bool datos_correctos = (medida_correcta && unidad_inicial_correcta
  && palabra_a_correcta && unidad_final_correcta);

  //Cálculos.

  if (datos_correctos){

    if (unidad_inicial == unidad_final){

      medida_final = medida;
    }

    //Unidad inicial MM.

    if ((unidad_inicial == MM) && (unidad_final == CM)){

      medida_final = medida / MULTIPLO_10;
    }

    if ((unidad_inicial == MM) && (unidad_final == M)){

      medida_final = medida / MULTIPLO_1000;
    }

    if ((unidad_inicial == MM) && (unidad_final == KM)){

      medida_final = medida / MULTIPLO_1M;
    }

    //Unidad inicial CM.

    if ((unidad_inicial == CM) && (unidad_final == MM)){

      medida_final = medida * MULTIPLO_10;
    }

    if ((unidad_inicial == CM) && (unidad_final == M)){

      medida_final = medida / MULTIPLO_100;
    }

    if ((unidad_inicial == CM) && (unidad_final == KM)){

      medida_final = medida / MULTIPLO_100000;
    }

    //Unidad inicial M.

    if ((unidad_inicial == M) && (unidad_final == MM)){

      medida_final = medida * MULTIPLO_1000;
    }

    if ((unidad_inicial == M) && (unidad_final == CM)){

      medida_final = medida * MULTIPLO_100;
    }

    if ((unidad_inicial == M) && (unidad_final == KM)){

      medida_final = medida / MULTIPLO_1000;
    }

    //Unidad inicial KM.

    if ((unidad_inicial == KM) && (unidad_final == MM)){

      medida_final = medida * MULTIPLO_1M;
    }

    if ((unidad_inicial == KM) && (unidad_final == CM)){

      medida_final = medida * MULTIPLO_100000;
    }

    if ((unidad_inicial == KM) && (unidad_final == M)){

      medida_final = medida * MULTIPLO_1000;
    }

}

  //Salida de datos.

  cout.setf (ios :: showpoint);
  cout.setf (ios :: fixed);

  //MM

  if (datos_correctos){


    if ((unidad_inicial == MM) && (unidad_final == MM)){

      cout << medida << MM << " = "
           << setprecision (10) << medida_final << MM;
    }

    if ((unidad_inicial == MM) && (unidad_final == CM)){

      cout << medida << MM << " = "
           << setprecision (10) << medida_final << CM;
    }

    if ((unidad_inicial == MM) && (unidad_final == M)){

      cout << medida << MM << " = "
           << setprecision (10) << medida_final << M;

    }

    if ((unidad_inicial == MM) && (unidad_final == KM)){

      cout << medida << MM << " = "
           << setprecision (10) << medida_final << KM;
    }

    //CM
    if ((unidad_inicial == CM) && (unidad_final == CM)){

      cout << medida << CM << " = "
           << setprecision (10) << medida_final << CM;
    }

    if ((unidad_inicial == CM) && (unidad_final == MM)){

      cout << medida << CM << " = "
           << setprecision (10) << medida_final << MM;
    }

    if ((unidad_inicial == CM) && (unidad_final == M)){

      cout << medida << CM << " = "
           << setprecision (10) << medida_final << M;
    }

    if ((unidad_inicial == CM) && (unidad_final == KM)){

      cout << medida << CM << " = "
           << setprecision (10) << medida_final << KM;
    }

    //M
    if ((unidad_inicial == M) && (unidad_final == M)){

      cout << medida << M << " = "
           << setprecision (10) << medida_final << M;
    }

    if ((unidad_inicial == M) && (unidad_final == MM)){

      cout << medida << M << " = "
           << setprecision (10) << medida_final << MM;
    }

    if ((unidad_inicial == M) && (unidad_final == CM)){

      cout << medida << M << " = "
           << setprecision (10) << medida_final << CM;  }

    if ((unidad_inicial == M) && (unidad_final == KM)){

      cout << medida << M << " = "
           << setprecision (10) << medida_final << KM;
    }

    //KM

    if ((unidad_inicial == KM) && (unidad_final == KM)){

      cout << medida << KM << " = "
           << setprecision (10) << medida_final << KM;
    }

    if ((unidad_inicial == KM) && (unidad_final == MM)){

      cout << medida << KM << " = "
           << setprecision (10) << medida_final << MM;
    }

    if ((unidad_inicial == KM) && (unidad_final == CM)){

      cout << medida << KM << " = "
           << setprecision (10) << medida_final << CM;  }

    if ((unidad_inicial == KM) && (unidad_final == M)){

      cout << medida << KM << " = "
           << setprecision (10) << medida_final << M;
    }

  }

  else {

    cout << "No ha introducido bien los datos.";
  }

  cout << endl << endl;
  cout << "***********************************************" << endl << endl;



  return 0;
}
