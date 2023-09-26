/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS VII

27. Considerar la clase ColeccionPuntos2D que se usará para almacenar y
gestionar una colección de datos de tipo Punto2D.

Realizar un programa que lea del teclado un número indeterminado de datos de
tipo Punto2D de manera que termine la lectura si el usuario escribe FIN cuando
el programa le pide la abscisa de un nuevo punto. Los puntos leídos los almacena
en un objeto ColeccionPuntos2D.

A continuación pide los datos necesarios, y crea un objeto Circunferencia,
y finalmente muestra cuáles de los puntos almacenados en la colección
ColeccionPuntos2D está en el círculo delimitado por la circunferencia.

ENTRADA: conjunto de puntos y centro y radio de circunferencia.
SALIDA: cuales de los puntos estan dentro de la circunferencia.

*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

/***************************************************************************/
const double PI = 3.1415926;

/***************************************************************************/
// Funci�n global (asociada a la constante PRECISION_SON_IGUALES) que
// permite que dos n�meros reales muy pr�ximos sean considerados iguales.

const double PRECISION_SON_IGUALES = 1e-6; // 0.000001

bool SonIguales(double uno, double otro)
{
	return (fabs(uno-otro) <= PRECISION_SON_IGUALES);
}

/***************************************************************************/
// Elimina los �ltimos caracteres de "cadena" iguales a "a_borrar"

string EliminaUltimos(string cadena, char a_borrar)
{
   	while (cadena.length()>0 && cadena.back() == a_borrar)
		cadena.pop_back();

	return (cadena);
}

/***************************************************************************/
// Elimina los primeros caracteres de "cadena" iguales a "a_borrar"

string EliminaPrimeros (string cadena, char a_borrar)
{
	// Buscar el primer xarácter no espacio
	int pos = 0;
	while (pos <cadena.length() && cadena.back() == a_borrar) pos++;

	string local;

	// Copiar todos los que quedan
	while (pos <cadena.length()) {
		local.push_back(cadena.at(pos));
		pos++;
	}

	return (local);
}

/***************************************************************************/
// Redondea el n�mero "real" a "num_decimales" decimales.
// Recibe:
//		real, el valor que se va a redondear.
//		num_decimales, el n�mero de decimales que se desea.
// Devuelve:
//		El n�mero "real" redondeado a la "num_decimales" cifra.
/***************************************************************************/

double Redondea (double real, int num_decimales)
{
   long long potencia_10 = pow(10, num_decimales);
   double nuevo_num = ((int) (round (real * potencia_10)));
   double real_redondeado = nuevo_num / potencia_10;

   return (real_redondeado);
}

/***************************************************************************/
// Convierte el dato double "real" a un string que contiene el valor
// textual de "real" de acuerdo con el formato indicado seg�n los
// valores de "num_casillas" y "decimales".
//
// Recibe:
//      "real", el n�mero a transformar.
//		"num_casillas", n�mero total de casillas que tendr� el resultado.
//		"decimales", n�mero de casillas para la parte decimal del resultado.
//		"relleno", el car�cter usado para rellenar los huecos.
//
// Devuelve: el string compuesto.
//
// NOTAS:
// 1) Si el n�mero de casillas solicitado es mayor que el que se necesita,
//	  se completa el inicio de la parte entera con "relleno".
// 2) Si el n�mero de decimales requerido es cero, NO se muestra el punto.
//	  Si es mayor que el que se necesita se completa con ceros.

string ToStringDouble (double real, int num_casillas,
                       int decimales, char relleno= ' ')
{
	string cadena;

	double real_redondeado = Redondea (real, decimales);

	cadena = to_string(real_redondeado);
	cadena = EliminaUltimos(cadena, '0');

	// Si no queremos decimales

	if (decimales==0) {

		cadena.pop_back();	// Borrar el punto

		int long_cadena = (int) cadena.length();

		// Rellenar parte entera
		int digitos_enteros_faltan = num_casillas-long_cadena;
		for (int i=0; i<digitos_enteros_faltan; i++)
			cadena = relleno + cadena;
	}
	else { // Queremos decimales

		int long_cadena = (int) cadena.length();

		if (long_cadena < num_casillas) {

			// Se calcula la longitud de las partes entera y decimal
			// La referencia es el punto (��SIEMPRE EST�!!)

			int pos_punto = cadena.find ('.');
			int long_parte_entera = pos_punto;
			int long_parte_decimal = long_cadena-pos_punto-1;

			// Rellenar parte decimal con ceros
			int digitos_decimales_faltan = decimales - long_parte_decimal;
			for (int i=0; i<digitos_decimales_faltan; i++)
				cadena += '0';

			// Rellenar parte entera con relleno
			int digitos_enteros = num_casillas-decimales-1;
			int digitos_enteros_faltan = digitos_enteros-long_parte_entera;

			for (int i=0; i<digitos_enteros_faltan; i++)
				cadena = relleno + cadena;
		}
	}

	return (cadena);
}

/***************************************************************************/
// Convierte el dato int "entero" a un string con "num_casillas" casillas
// que contiene el valor textual de "entero".
//
// Recibe: 	entero, el valor a transformar.
//			num_casillas, número total de casillas que tendrá el resultado.
//			relleno, el carácter que se emplea para rellenar los huecos.
// Devuelve: el string compuesto.
//
// NOTAS: Si el número de casillas solicitado es mayor que el que se necesita,
//	  	se completa al principio con "relleno" hasta alcanzar un tamaño de
//	  	"num_casillas". Si el valor tuviera "per se" más de "num_casillas"
//		se devuelve tal cual.

string ToStringInt (int entero, int num_casillas, char relleno=' ')
{
	// Inicialmente nos quedamos con el resultado de to_string
	string cadena = to_string(entero);

	int long_cadena = (int) cadena.length();

	// Si es preciso se completa (por la izquierda) con RELLENO_INT

	if (long_cadena < num_casillas) {

		int num_casillas_faltan = num_casillas-long_cadena;

		for (int i=0; i<num_casillas_faltan; i++)
			cadena = relleno + cadena;
	}

	return (cadena);
}


/*---------------------------------------------------------------------------
								Clase Punto2D
---------------------------------------------------------------------------*/

class Punto2D
{
private:

	// La pareja (x,y) son las coordenadas de un punto en un espacio 2D
	double x;
	double y;

public:

	Punto2D (void)
	{}

	/***********************************************************************/
	// Constructor con argumentos.
	//
	// Recibe: abscisaPunto y ordenadaPunto, la abscisa y ordenada,
	// respectivamente del punto que se est� creando.

	Punto2D (double abscisaPunto, double ordenadaPunto)
	{
		SetCoordenadas (abscisaPunto, ordenadaPunto);
	}

	/***********************************************************************/
	// M�todo Set para fijar simultaneamente las coordenadas.
	//
	// Recibe: abscisaPunto y ordenadaPunto, la abscisa y ordenada,
	// respectivamente del punto que se est� modificando.

	void SetCoordenadas (double abscisaPunto, double ordenadaPunto)
	{
		x = abscisaPunto;
		y = ordenadaPunto;
	}

	/***********************************************************************/
	// M�todos Get para leer las coordenadas

	double GetX (void)
	{
		return (x);
	}
	double GetY (void)
	{
		return (y);
	}

	/***********************************************************************/
	// Calcula si dos puntos son iguales
	//
	// Recibe: otro, el punto que se quiere comparar con el objeto impl�cito.
	// Devuelve: true, si se consideran iguales los dos objetos.

	bool EsIgual (Punto2D otro)
	{
		return (SonIguales(x,otro.x) && SonIguales(y,otro.y));
	}

	/***********************************************************************/
	// Calcula la distancia Eucl�dea del punto (objeto impl�cito) a otro que
	// se recibe como argumento.
	//
	// Recibe: otro, el punto respecto al cual que se quiere calcular la
	// distancia eucl�dea.
	// Devuelve: la distancia entre los dos puntos.

	double DistanciaEuclidea (Punto2D otro)
	{
		double dif_x = pow (x - otro.x, 2);
		double dif_y = pow (y - otro.y, 2);

		return (sqrt(dif_x + dif_y));
	}

	/***********************************************************************/
	// Serializa un dato "Punto2D"

	string ToString ()
	{
		return ("[" + ToStringDouble (x, 7, 3, ' ') + ", " +
		              ToStringDouble (y, 7, 3, ' ') + "]");
	}

	/***********************************************************************/
};



/*---------------------------------------------------------------------------
							Clase ColeccionPuntos2D
---------------------------------------------------------------------------*/

class ColeccionPuntos2D{

private:

	static const int TAM = 100;
	Punto2D puntos[TAM];

	//Pre: 0 <= total_utilizados < TAM
	int total_utilizados;

public:

	//Constructor sin argumentos.
	ColeccionPuntos2D (void): total_utilizados(0)
	{}


	/*************************************************************************
	Metodo AniadePunto: introduce un punto en cada posicion del vector.
	*************************************************************************/
	void AniadePunto (Punto2D punto){

		puntos[total_utilizados] = punto;
		total_utilizados++;
	}


	//Getters.

	Punto2D GetPunto (int pos){

		return Punto2D(puntos[pos].GetX(), puntos [pos].GetY());
	}


	int GetTAM (void){

		return TAM;
	}

	int GetTotalUtilizados(void){

		return total_utilizados;
	}


	/*************************************************************************
	Metodo ToString: devuelve las coordenadas de un punto.
	*************************************************************************/

	string ToString (Punto2D el_punto){

		string punto = "(" + to_string (el_punto.GetX()) + ","
		+ to_string (el_punto.GetY()) + ")";

		return punto;
	}

};

/*---------------------------------------------------------------------------
								Clase Circunferencia
---------------------------------------------------------------------------*/

class Circunferencia {

private:

	Punto2D centro;
	double radio;


public:

	//Constructor con argumentos.

	//Pre: el_radio > 0

	Circunferencia (double abs, double ord, double el_radio) :
	centro(abs, ord), radio(el_radio)

	{}

	void SetRadio (double el_radio){

		radio = el_radio;
	}


	//Getters.

	string GetCentro(){

		Punto2D el_centro = centro;

		string coord_centro = "[" + to_string (el_centro.GetX()) + ","
		+ to_string (el_centro.GetY()) + "]";

		return coord_centro;
	}


	double GetRadio (void){
		return (radio);
	}


	/*************************************************************************
	Metodo EstaEnCircunferencia: determina si un punto esta dentro de la
	circunferencia comparando el radio con la distancia del centro al punto.
	*************************************************************************/

	bool EstaEnCircunferencia (Punto2D punto){

		bool esta_en_circunferencia = false;

		if (fabs(centro.DistanciaEuclidea (punto)) <= radio){

			esta_en_circunferencia = true;
		}

		return esta_en_circunferencia;
	}



	/*************************************************************************
	Metodo AreaCircunferencia: calcula el area de la circunferencia a partir
	del punto medio de la diagonal.
	*************************************************************************/

	double AreaCircunferencia (void){

		const double PI = 6 * asin(0.5);
		double resultado;

		resultado = PI * radio * radio;

		return (resultado);
	}

};


/*---------------------------------------------------------------------------
							Programa principal
---------------------------------------------------------------------------*/
int main() {

	//Declaraciones.

	string abscisa, ordenada;
	const string FIN = "FIN";

	ColeccionPuntos2D coleccion;


	//Entrada de datos.

	cout << "***********************************************" << endl << endl;

	bool hay_puntos = false;
	cout << "Introduzca una abscisa.";
	cin >> abscisa;

	int pos = coleccion.GetTotalUtilizados();

	const int TAM = coleccion.GetTAM();

	while (abscisa != FIN && coleccion.GetTotalUtilizados() < TAM){

		cout << "Introduzca una ordenada.";
		cin >> ordenada;
		cout << endl << endl;

		Punto2D punto (stod (abscisa), stod (ordenada));

		coleccion.AniadePunto(punto);

		hay_puntos = true;

		cout << "Introduzca una abscisa.";
		cin >> abscisa;

	}

	cout << endl;

	double abscisa_circ, ordenada_circ, radio;

	if (hay_puntos){

		cout << "Introduzca la abscisa del centro de su circunferencia: ";
		cin >> abscisa_circ;

		cout << "Introduzca la ordenada del centro de su circunferencia: ";
		cin >> ordenada_circ;

		do{
			cout << "Introduzca el radio de su circunferencia: ";
			cin >> radio;
		}while (radio <= 0);

		cout << endl << endl;

	}

	Circunferencia circunferencia (abscisa_circ, ordenada_circ, radio);


	//Salida de datos.

	int contador_puntos = 0;

	if (hay_puntos){

		cout << "Los puntos que estan en la circunferencia son: "<< endl<< endl;

		for (int i = 0; i < coleccion.GetTotalUtilizados(); i++){

			if (circunferencia.EstaEnCircunferencia(coleccion.GetPunto(i))){

				cout << setw(10) << coleccion.ToString (coleccion.GetPunto(i));
				cout << endl;
				contador_puntos++;

			}
		}

		if (contador_puntos == 0) cout << "Ninguno." << endl;

	} // Si hay puntos

	else cout << "No ha introducido ningun punto." << endl;

	cout << "***********************************************" << endl << endl;



	return 0;
}
