/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS II

82. El cálculo de la raiz cuadrada puede realizarse con la función sqrt
disponible en cmath. En el manual de referencia
(por ejemplo, https://www.cplusplus.com/reference/cmath/sqrt) puede leer que
en C++ 11 tiene disponibles, básicamente, las siguientes sobrecargas de esa
función:

double sqrt (double x);
float sqrt (float x);
long double sqrt (long double x);

Pueden emplearse aproximaciones numéricas para evitar el cálculo con la función
sqrt. Por ejemplo, en https://www.youtube.com/watch?v=sOSdi9z8S6E
puede ver un método muy sencillo. Impleméntelo para el cálculo de la raiz
cuadrada de datos double.

Implemente a continuación una estimación basada en la proporcionalidad entre
triángulos. Se trata de aproximar la función y = √x por rectas entre los
tramos determinados por los valores con raices exactas. Por ejemplo, en la
figura 12.A mostramos la función y = √x y remarcamos sobre el eje x los valores
con raices exactas (0, 1, 4, 9 y 16) y en el eje y los valores de las raices
exactas (0, 1, 2, 3 y 4). En la figura 12.B unimos los puntos (x, √x) que
verifican que x tiene raiz exacta.

Si tomamos un segmento cualquiera en el eje x y lo vemos con detalle observará
que hay una región triangular bien delimitada. Por ejemplo en la región entre
x = 1 y x = 4 puede ver el triángulo delimitado por los puntos (1, 1), (4, 1) y
(4, 2) (figura 13.A). Por ser estrictos se trata del triángulo delimitado por
los puntos (1,√1), (4,√1) y (4,√2).

La raiz de un valor x entre 1 y 4 se puede calcular geométricamente. En la
figura 13.B mostramos cómo se calcula la raiz cuadrada de x =3.5. Observe que
el triángulo delimitado por (1,√1), (3.5, 1) y (3.5,√3.5) (triángulo amarillo)
es equivalente al delimitado por los puntos (1,√1), (4,√1) y (4,√2)
(triángulo azul).

Calcule la raiz cuadrada de un número real positivo usando esta aproximación.

Finalmente muestre una tabla comparativa en la que se muestren los valores
estimados por los dos métodos y por la función sqrt para valores de x desde
0 a 16, con saltos de 0.5. ¿Puede extraer alguna conclusión de esta tabla?
¿Puede proponer un método de estimación mejor -más ajustado al verdadero valor-
que los dos implementados?

ENTRADA: numero.
SALIDA: valor aproximado de su raiz cuadrada por dos metodos y el valor real.

*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){

	cout.setf(ios::fixed);

	// Declaracion de variables

	double x;

	// Entrada

	do{

	cout << "Introduzca un numero mayor o igual que 0: ";
	cin >> x;

	} while (x < 0);

	cout << endl;

	cout << "------------   ------------   ------------   ------------" << endl;
	cout << "   Numero        Metodo 1       Metodo 2      Valor real" << endl;
	cout << "------------   ------------   ------------   ------------" << endl;

	bool numero_primero = true;

	do {

		// Metodo 1

		// Declaracion de variables

		double resultado_metodo_1;
		double aprox = 0;
		int aprox_por_abajo, aprox_por_arriba;
		double diferencia;
		double aproximacion_cuadrado = - 1;

		// Calculos

		while (x > aproximacion_cuadrado){

			aproximacion_cuadrado = pow (aprox, 2);
			aprox_por_arriba = aprox;
			aprox++;

		}

		aprox_por_abajo = aprox_por_arriba - 1;

		double aprox_por_abajo_cuadrado = pow (aprox_por_abajo, 2);
		double aprox_por_arriba_cuadrado = pow (aprox_por_arriba, 2);

		double diferencia_por_abajo = x - aprox_por_abajo_cuadrado;
		double diferencia_por_arriba = x - aprox_por_arriba_cuadrado;

		if (abs(diferencia_por_abajo) <= abs(diferencia_por_arriba)){

			aprox = aprox_por_abajo;
			diferencia = diferencia_por_abajo;
			aproximacion_cuadrado = aprox_por_abajo_cuadrado;

		}

		else {

			aprox = aprox_por_arriba;
			diferencia = diferencia_por_arriba;
			aproximacion_cuadrado = aprox_por_arriba_cuadrado;

		}

		bool error_metodo_uno = false;

		if (aprox != 0){

			resultado_metodo_1 = aprox + (diferencia / (aprox * 2));

		}
		else {

			error_metodo_uno = true;

		}

	// Metodo 2

	// Declaracion de variables.

	double base_del_triangulo = aprox_por_arriba_cuadrado -
							    aprox_por_abajo_cuadrado;

	double altura_del_triangulo = aprox_por_arriba - aprox_por_abajo;
	double base_del_triangulo_menor = x - aprox_por_abajo_cuadrado;
	double altura_del_triangulo_menor;
	double resultado_metodo_2;

	// Calculos: Teorema de Tales.

	altura_del_triangulo_menor = (altura_del_triangulo / base_del_triangulo) *
								  base_del_triangulo_menor;

	resultado_metodo_2 = altura_del_triangulo_menor + aprox_por_abajo;

	// Metodo 3

	double resultado_metodo_tres = sqrt (x);

	// Salida

	int valor_setw = 8;

	cout << setprecision(1) << setw(valor_setw);
	cout << x;

	if (!error_metodo_uno) {

		cout << "       ";
		cout << setprecision(3) << setw(valor_setw);
		cout << resultado_metodo_1;

	} else {

		cout << "       ";
		cout << setprecision(3) << setw(valor_setw);
		cout << "ERROR";

	}

	cout << "       ";
	cout << setprecision(3) << setw(valor_setw);
	cout << resultado_metodo_2;

	cout << "        ";
	cout << setprecision(3) << setw(valor_setw);
	cout << resultado_metodo_tres;
	cout << endl;

	if (numero_primero) {

		x = -0.5;
		numero_primero = false;

	}

	x += 0.5;

	} while (x <= 16);

	return 0;

}
