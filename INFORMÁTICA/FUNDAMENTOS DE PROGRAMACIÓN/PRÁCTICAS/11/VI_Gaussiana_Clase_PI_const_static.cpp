/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS VI

7. Recuperad el ejercicio 30 de la Relación de Problemas III sobre la función
gaussiana.

En vez de trabajar con funciones, plantead la solución con una clase.
Debe diseñar la clase teniendo en cuenta que la función matemática gaussiana
viene determinada unívocamente por el valor de la esperanza y la desviación, es
decir, son estos dos parámetros lo que distinguen a una función gaussiana de
otra.

Recuerde añadir un método ToString para la clase. Sugerimos el siguiente
formato: si g es N(0, 1) y el objeto g representa a esa función, la ejecución de
 g.ToString() devolverá la cadena N (0.000000, 1.000000).

Variante: Modifique la clase Gaussiana de manera que π sea una constante a
nivel de clase (static).

ENTRADA: Un media y desviacion tipica.
SALIDA: El valor de la gaussiana en un rango de abscisas y el valor del cdf por
dos metodos.

*/

#include <iostream>
#include <cmath>
#include <string>



using namespace std;


/*---------------------------------------------------------------------------
									Clase Gaussiana
---------------------------------------------------------------------------*/
const double SALTO = 0.25;


class Gaussiana
{
	private:

		static const double PI;
		double media;
		double desviacion_tipica;

	public:

		// Constructor con argumentos.

		Gaussiana (double media, double desviacion) :
			media (media), desviacion_tipica (desviacion)
		{}

		//Getters.

		double GetMedia (void)
		{
			return(media);
		}

		double GetDesviacion (void)
		{
			return(desviacion_tipica);
		}

		// Metodo ToString: muestra en el main la distribucion normal de la
		//gaussiana.

		string ToString (void)
		{
			string cad;

			cad = "N(" + to_string(media) + ", "
			+ to_string(desviacion_tipica) + ")";

			return(cad);
		}

		// Calculo de g(x) - APARTADO A

		double Gauss (double variable_x){

		  double gaussiana;

		  gaussiana = (1/(desviacion_tipica * sqrt (2 * PI)))
		              * exp (- 0.5 * pow ((variable_x - media)
		              / desviacion_tipica, 2));

		  return gaussiana;
		}

		// Calculo de CDF_1(x) (Mediante suma) - APARTADO B

		double Cdf_b (double variable_x){

		  double suma_cdf_b = 0;

		  for (double x_inicial =  media - 3 * desviacion_tipica;
			  x_inicial <= variable_x; x_inicial = x_inicial + SALTO){

		   suma_cdf_b = suma_cdf_b + Gauss (x_inicial);
		  }

		  return (suma_cdf_b * SALTO);
		}

	    // Calculo de CDF_2(x) (Aproximacion) - APARTADO C

		double Cdf_c (double variable_x){

		  const double B0 = 0.2316419, B1 = 0.319381530, B2 = - 0.356563782;
		  const double B3 = 1.781477937, B4 = - 1.821255978, B5 = 1.330274429;
		  double t, cdf_b;
		  double variable_x_estandarizada =
		  (variable_x - media) / desviacion_tipica;

		  t = 1 / (1 + B0 * fabs (variable_x_estandarizada));
		  double w;
		  w = 1 - (Gauss (fabs(variable_x)) *
		  (B1*t+ B2*pow (t, 2)+ B3*pow (t, 3)+ B4*pow (t, 4)+ B5*pow (t, 5)));

		  if (variable_x_estandarizada >= 0) cdf_b =  w;

		  else cdf_b = (1 - w);

		  return cdf_b;

		}
};

const double Gaussiana :: PI = 3.14159265358979323846;

/*---------------------------------------------------------------------------
							Programa principal
---------------------------------------------------------------------------*/
int main() {


	//Declaraciones.
	double desviacion_tipica, media, variable_x, gaussiana, cdf_b, cdf_c;


    //Entrada de datos.

    cout << "***********************************************" << endl << endl;

    do { //Filtro
      cout << "Introduzca un valor mayor que 0 para la desviacion_tipica. ";
      cin >> desviacion_tipica;
    } while (desviacion_tipica <= 0);

    cout << endl;
    cout << "Introduzca un valor para la media. ";
    cin >> media;


    cout << endl;

	Gaussiana g (media, desviacion_tipica);
	double x_inicial = g.GetMedia() - 3 * g.GetDesviacion();
	double x_final = g.GetMedia() + 3 * g.GetDesviacion();

    //Calculos.

    //b.
    cdf_b = g.Cdf_b (x_final);

    //c.
    cdf_c = g.Cdf_c (x_final);


    //Salida de datos.

	cout << "La Gaussiana sigue una distribucion normal de " << g.ToString();
	cout << endl << endl;

    cout << "En un rango entre " << x_inicial << " y " << x_final << ":"<< endl;

    cout << "-------------------------------------------------" << endl;


    for (double x_inicio = x_inicial; x_inicio <= x_final; x_inicio+=SALTO){

      gaussiana = g.Gauss (x_inicio);

      cout << "Para x = " << x_inicio << " el valor de la gaussiana es "
           << gaussiana << endl;
    }
    cout << "-------------------------------------------------" << endl << endl;

    cout << "La distribución acumulada es " << cdf_b << endl;

    cout << "-------------------------------------------------" << endl << endl;

    cout << "La distribución acumulada aproximada es " << cdf_c << endl;

    cout << "*************************************************" << endl << endl;



    return 0;
  }
