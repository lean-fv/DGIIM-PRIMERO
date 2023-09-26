/*
40. Suponga un caso de elección en el que se decide entre tres opciones:
A, B y C.

• El número de votantes totales (censo) está registrado en la constante
VOTANTES.

• El número total de de votos registrados es votos_emitidos, donde el número
total de de votos presenciales es votos_presenciales y el número total de
de votos por correo es votos_correo.

• Los votos registrados se dividen en válidos (votos_validos) y nulos
(votos_nulos).

• Entre los votos válidos se distinguen entre los recibidos
por correo (votos_validos_correo) y presencialmente
(votos_validos_presenciales).

• Cada opción recibe un número de votos válidos que se registra en las
variables votos_A, votos_B y votos_C, respectivamente.
*/

#include <iostream>

using namespace std;

int main() {

  //Declaración de variables.

  const int VOTANTES = 100;
  int votos_emitidos, votos_presenciales, votos_correo;
  int votos_validos, votos_nulos;
  int votos_validos_correo, votos_validos_presenciales;
  int votos_A, votos_B, votos_C;

  cin >> votos_presenciales;  // 70
  cin >> votos_correo;        // 10

  cin >> votos_validos;       //80
  cin >> votos_nulos;         //0

  cin >> votos_validos_correo;        //20
  cin >> votos_validos_presenciales;  //60

  cin >> votos_A;     //40
  cin >> votos_B;     //30
  cin >> votos_C;     //10

  /*
  
  Escriba expresiones lógicas para reflejar las situaciones que se describen a
  continuación. Para cada caso, el resultado debe guardarse en una variable
  lógica (escoja un nombre adecuado).

  1 = VERDADERO
  0 = FALSO

  */

  // a) El número de votos emitidos totales es mayor que el número de votantes.

  votos_emitidos = votos_presenciales + votos_correo;
  votos_emitidos = votos_validos + votos_nulos;

  bool votos_emitidos_mayor_que_votantes = (votos_emitidos > VOTANTES);

  cout << "El número de votos emitidos totales es mayor que el número de ";
  cout << "votantes " << votos_emitidos_mayor_que_votantes << endl << endl;

  /* b) El número de votos válidos no es igual a la suma de los votos recibidos
  por las tres opciones. */

  votos_validos = votos_validos_correo +  votos_validos_presenciales;
  votos_validos = votos_A + votos_B + votos_C;

  bool votos_validos_distinto_de_recibidos_por_opciones =
  (votos_validos != (votos_A + votos_B + votos_C));

  cout << "El número de votos válidos no es igual a la suma de los votos ";
  cout << "recibidos por las tres opciones ";
  cout << votos_validos_distinto_de_recibidos_por_opciones << endl << endl;

  /* c) El número de votos registrados es igual a la suma de los votos válidos
  y nulos. */

  bool votos_emitidos_igual_validos_mas_nulos =
  (votos_emitidos = votos_validos + votos_nulos);

  cout << "El número de votos registrados es igual a la suma de los votos ";
  cout << "válidos y nulos " << votos_emitidos_igual_validos_mas_nulos;
  cout << endl << endl;

  // d) Gana la opción A.

  bool gana_A = ((votos_A > votos_B) && (votos_A > votos_C));

  cout << "Gana A " << gana_A << endl << endl;

  // e) Gana la opción B.

  bool gana_B = ((votos_B > votos_A) && (votos_B > votos_C));

  cout << "Gana B " << gana_B << endl << endl;

  // f) Gana la opción C.

  bool gana_C = ((votos_C > votos_A) && (votos_C > votos_B));

  cout << "Gana C " << gana_C << endl << endl;

  // g) Empatan dos opciones.

  bool empate_de_dos = ((votos_A == votos_B) || (votos_A == votos_C)
  || (votos_B == votos_C));

  cout << "Empatan dos opciones " << empate_de_dos << endl << endl;

  /* h) Hay un empate técnico entre las opciones A y B.
  Definimos que ocurre un empate técnico cuando la diferencia entre los dos
  valores es menor que el 5 % de su suma. */

  bool empate_tecnico_AB =
  ((abs (votos_A - votos_B)) < (0.05 * (votos_A + votos_B)));

  cout << "Hay un empate técnico entre las opciones A y B ";
  cout << empate_tecnico_AB << endl << endl;


  // i) La opción A obtiene mayoría absoluta.

  int mayoria_abs_votos = 1 + votos_validos / 2;
  bool mayoria_abs_A = (votos_A >= mayoria_abs_votos);

  cout << "La opción A obtiene mayoría absoluta " << mayoria_abs_A;
  cout << endl << endl;


  // j) Hay una coalición de dos opciones que obtiene mayoría absoluta.

  int coalicion_AB = votos_A + votos_B;
  int coalicion_AC = votos_A + votos_C;
  int coalicion_BC = votos_B + votos_C;

  bool mayoria_abs_2_opciones =
    ((coalicion_AB >= mayoria_abs_votos)
  || (coalicion_AC >= mayoria_abs_votos)
  || (coalicion_BC >= mayoria_abs_votos));

  cout << "Hay una coalición de dos opciones que obtiene mayoría absoluta ";
  cout << mayoria_abs_2_opciones << endl << endl;

  // k) La coalición A-C obtiene mayoría absoluta.

  bool mayoria_abs_AC = (coalicion_AC >= mayoria_abs_votos);

  cout << "La coalición A-C obtiene mayoría absoluta " << mayoria_abs_AC;
  cout << endl << endl;

  // l) La opción B obtiene menos de 3 % de los votos válidos registrados.

  bool votos_B_menos_3_por_ciento_votos_validos =
  (votos_B < (0.03 * votos_validos));

  cout << "La opción B obtiene menos de 3 % de los votos válidos registrados ";
  cout << votos_B_menos_3_por_ciento_votos_validos << endl << endl;

  // m) La participación es mayor que el 75 % del censo de votantes.

  int participacion;
  cin >> participacion;   //80
  int no_votantes = VOTANTES - participacion;

  bool participacion_mayor_75_por_ciento_votantes =
  (participacion > (0.75 * VOTANTES));

  cout << "La participación es mayor que el 75 % del censo de votantes ";
  cout << participacion_mayor_75_por_ciento_votantes << endl << endl;

  /* n) Queremos saber si la opción A puede gobernar "sólo o en compañía de
  otros". */

  bool A_solo = mayoria_abs_A;
  bool A_compania = !(A_solo);

  cout << "Queremos saber si la opción A puede gobernar sólo o en compañía ";
  cout << "de otros. Solo " << A_solo << " En compañia " << A_compania;
  cout << endl << endl;

  /* ñ) El número de votos nulos ó el número de abstenciones es mayor que el
  número de votos válidos. */

  bool votos_nulos_o_no_votantes_mayor_votos_validos =
  ((votos_nulos > votos_validos) || (no_votantes > votos_validos));

  cout << "El número de votos nulos ó el número de abstenciones es mayor que ";
  cout << "el número de votos válidos ";
  cout << votos_nulos_o_no_votantes_mayor_votos_validos << endl << endl;

  /* o) El número de votos nulos y el número de abstenciones es mayor que el
  número de votos válidos, pero las abstenciones no son mayores que los votos
  nulos. */

  bool nulos_mas_no_votantes_mayor_validos_abstenciones_no_mayores_nulos =
  (((votos_nulos + no_votantes) > votos_validos)
  && !(no_votantes > votos_nulos));

  cout << "El número de votos nulos y el número de abstenciones es mayor que ";
  cout << "el número de votos válidos, pero las abstenciones no son mayores ";
  cout << "que los votos nulos. ";
  cout << nulos_mas_no_votantes_mayor_validos_abstenciones_no_mayores_nulos;
  cout << endl << endl;


  /* p) El número de votos por correo es mayor que el 20 % de los votos
  presenciales o el número de abstenciones. */

  bool votos_correo_mayor_20_por_ciento_preseciales_o_abstenciones =
  (votos_correo > (0.2 * votos_presenciales) || (votos_correo > no_votantes));

  cout << "El número de votos por correo es mayor que el 20 % de los votos ";
  cout << "presenciales o el número de abstenciones. ";
  cout << votos_correo_mayor_20_por_ciento_preseciales_o_abstenciones;
  cout << endl << endl;

  /* q) El número de votos nulos por correo es mayor que el número de votos
  nulos presenciales. */

  int votos_nulos_correo = votos_correo - votos_validos_correo;
  int votos_nulos_presenciales =
  votos_presenciales - votos_validos_presenciales;

  bool nulos_correo_mayor_nulos_presenciales =
  (votos_nulos_correo > votos_nulos_presenciales);

  cout << "El número de votos nulos por correo es mayor que el número de ";
  cout << "votos nulos presenciales. ";
  cout << nulos_correo_mayor_nulos_presenciales << endl << endl;

  /* r) El número de votos nulos por correo es mayor que el número de votos
  válidos por correo. */

  bool nulos_correo_mayor_validos_correo =
  (votos_nulos_correo > votos_validos_correo);

  cout << "El número de votos nulos por correo es mayor que el número de ";
  cout << "votos válidos por correo. " << nulos_correo_mayor_validos_correo;
  cout << endl << endl;



  return 0;
}
