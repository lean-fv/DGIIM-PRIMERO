/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 5 (Arrays)
//
/*	
	Programa que lee las coordenadas que definen un rectángulo y calcula una 
	serie de circunferencias centradas en el punto de corte de sus diagonales.
	Solo nos interesan aquellas que estén inscritas en el rectángulo.  	
	Guarda estas circunferencias en un array.
*/
/***************************************************************************/

//#define _USE_MATH_DEFINES

#include <iostream>
#include <cctype>
#include <cmath>
#include <iomanip>

using namespace std;

	
/***************************************************************************/
// Constantes
/***************************************************************************/

const double PI = 3.1415926;	
		
/***************************************************************************/
// Tipos de datos usados en este programa
/***************************************************************************/

// Punto en un plano
struct Punto2D {
	double x, y; // abscisa y ordenada de un punto
};

// Circunferencia
// PRE: radio > 0

struct Circunferencia {
	Punto2D centro; // Centro
	double radio;   // Radio
};
		
struct Rectangulo {
	Punto2D esquina_si; // Esquina superior izquierda
	Punto2D esquina_id; // Esquina inferior derecha
};

/* Las funciones que devuelven las coordenadas del rectángulo se construyen 
   a partir de la representación escogida (esquina_si, esquina_id) y lo hacen 
   siguiendo el esquema de dependencia siguiente: 
   
                                     PuntoSuperiorDerechaRectangulo()
                                        -----------^-----------
                                       |                      |
esquina_si --> PuntoSuperiorIzquierdaRectangulo() \    AnchoRectangulo()
                                                   >
esquina_id --> PuntoInferiorDerechaRectangulo()   /    AltoRectangulo()
                                       |                      |
                                        -----------v-----------
                                     PuntoInferiorIzquierdaRectangulo()
*/

/***************************************************************************/
/***************************************************************************/


/***************************************************************************/
// Calcula y devuelve la distancia Euclídea entre dos puntos.
//
// Recibe: uno y otro, los puntos entre los que se va a calcular la distancia.
// Devuelve: la distancia Euclídea entre "uno" y "otro".
/***************************************************************************/

double DistanciaEuclidea (Punto2D uno, Punto2D otro)
{
	double dif_x = uno.x - otro.x;
	double dif_y = uno.y - otro.y;
	return (sqrt((dif_x * dif_x) + (dif_y * dif_y)));
}
				
/***************************************************************************/
// Devuelve un string con la expresión textual de un punto.
//
// Recibe: p, el punto que se va a a usar para calcular su valor textual.
// Devuelve: la representación textual de "p".
/***************************************************************************/

string ToString (Punto2D p)
{	
	string cad;
	cad = "[ " + to_string (p.x) + ", " + to_string (p.y) + "]";	
	return (cad);
}	

/***************************************************************************/
// Leer y devolver el valor de un punto. La lectura está etiquuetada. 
//
// Recibe: msg, una cadena que etiqueta la lectura.
// Devuelve: un punto (Punto2D) con las coordenadas leidas del punto.			
/***************************************************************************/
/***************************************************************************/

Punto2D LeePunto (string msg)
{
	Punto2D centro;

	cout << "Coordenada X del punto " + msg + ": ";
	cin >> centro.x; 

	cout << "Coordenada Y del punto " + msg + ": ";
	cin >> centro.y; 
	
	return (centro);
}

/***************************************************************************/
// Devuelve el centro (Punto2D) de una circunferencia.
//
// Recibe: c, la circunferencia que se va a a usar para calcular su centro.
// Devuelve: el centro de "c".
/***************************************************************************/

Punto2D CentroCircunferencia (Circunferencia c)
{
	return (c.centro);
}

/***************************************************************************/
// Calcula la longitud de una circunferencia.
//
// Recibe: c, la circunferencia que se va a a usar para calcular su longitud.
// Devuelve: la longitud de "c".
/***************************************************************************/

double LongitudCircunferencia (Circunferencia c)
{
	return (2.0 * PI  * c.radio);
}

/***************************************************************************/
// Calcula el área del círculo interior a una circunferencia.
//
// Recibe: c, la circunferencia que se va a a usar para calcular el área 
//		 	  del círculo. 
// Devuelve: El área del circulo interior a "c".
/***************************************************************************/

double AreaCircunferencia (Circunferencia c)
{
	return (PI * c.radio * c.radio);
}

/***************************************************************************/
// Calcular si la circunferencia contiene a un punto dado.
//
// Recibe: p, el punto del que se quiere evaluar su pertenencia. 
//         c, la circunferencia contenedora.
//
//	Un punto (Px, Py) está dentro de una circunferencia con centro (Cx, Cy) 
// 	y radio r si se verifica que: (Cx - Px)^2 + (Py - Cy)^2 <= r^2
//
// Devuelve: true si el punto "p" está contenido en la circunferencia "c".			
/***************************************************************************/

bool PuntoContenidoEnCircunferencia (Punto2D p, Circunferencia c)
{	
	double dif_x = CentroCircunferencia(c).x - p.x;
	double dif_y = CentroCircunferencia(c).y - p.y;
	return (sqrt((dif_x * dif_x) + (dif_y * dif_y)));
}

/***************************************************************************/
// Calcular si la circunferencia contiene a un punto dado usando un 
// test explícito sobre la distancia Euclídea.
// 
// Recibe: p, el punto del que se quiere evaluar su pertenencia. 
//         c, la circunferencia contenedora.
//
//	Un punto (Px, Py) está dentro de una circunferencia con centro (Cx, Cy) 
//	y radio r si se verifica que: DistaciaEuclidea (P, C) <= r
//
// Devuelve: true si el punto "p" está contenido en la circunferencia "c".			
/***************************************************************************/

bool PuntoContenidoEnCircunferencia_Alternativo (Punto2D p, Circunferencia c)
{
	double distancia = DistanciaEuclidea (p, CentroCircunferencia(c));
	return (distancia <= c.radio);
}

/***************************************************************************/
// Leer y devolver el valor del radio de la circunferencia ("radio")
//
// Devuelve: el valor leído del centro de una circunferencia.	
//		
// POST: radio>0
/***************************************************************************/

double LeeRadio ()
{
	double radio;
	
	// Aseguramos que se cumplirá la precondición sobre el radio
	do {
		cout << "Introduzca el radio = ";
		cin >> radio; 
	} while (radio <= 0);
	
	return (radio);
}

/***************************************************************************/
// Devuelve el punto superior izquierda de un rectángulo.
//
// Recibe: r, el rectángulo.
// Devuelve: el punto superior izquierda (Punto2D) del rectángulo "r".
/***************************************************************************/

Punto2D PuntoSuperiorIzquierdaRectangulo (Rectangulo r)
{
	return (r.esquina_si);
}

/***************************************************************************/
// Devuelve el punto inferior derecha de un rectángulo.
//
// Recibe: r, el rectángulo.
// Devuelve: el punto inferior derecha (Punto2D) del rectángulo "r".
/***************************************************************************/

Punto2D PuntoInferiorDerechaRectangulo (Rectangulo r)
{
	return (r.esquina_id);
}

/***************************************************************************/
// Devuelve el ancho de un rectángulo.
//
// Recibe: r, el rectángulo.
// Devuelve: el ancho del rectángulo "r".
/***************************************************************************/

double AnchoRectangulo (Rectangulo r)
{	
	return (PuntoInferiorDerechaRectangulo(r).x 
	      - PuntoSuperiorIzquierdaRectangulo(r).x);
}

/***************************************************************************/
// Devuelve el alto de un rectángulo.
//
// Recibe: r, el rectángulo.
// Devuelve: el alto del rectángulo "r".
/***************************************************************************/

double AltoRectangulo (Rectangulo r)
{	
	return (PuntoSuperiorIzquierdaRectangulo(r).y 
	      - PuntoInferiorDerechaRectangulo(r).y);
}


/***************************************************************************/
// Devuelve el punto superior derecha de un rectángulo.
//
// Recibe: r, el rectángulo.
// Devuelve: el punto superior derecha (Punto2D) del rectángulo "r".
/***************************************************************************/

Punto2D PuntoSuperiorDerechaRectangulo (Rectangulo r)
{
	Punto2D p;	
	
	p.x = PuntoSuperiorIzquierdaRectangulo(r).x + AnchoRectangulo(r);
	p.y = PuntoSuperiorIzquierdaRectangulo(r).y;
	 
	return (p);
}


/***************************************************************************/
// Devuelve el punto inferior izquierda  de un rectángulo.
//
// Recibe: r, el rectángulo.
// Devuelve: el punto inferior izquierda  (Punto2D) del rectángulo "r".
/***************************************************************************/

Punto2D PuntoInferiorIzquierdaRectangulo (Rectangulo r)
{
	Punto2D p;	
	
	p.x = PuntoSuperiorIzquierdaRectangulo(r).x;
	p.y = PuntoSuperiorIzquierdaRectangulo(r).y - AltoRectangulo(r);
	 
	return (p);
}

/***************************************************************************/
// Calcula el área de un rectángulo.
//
// Recibe: r, el rectángulo.
// Devuelve: el área del rectángulo "r".
/***************************************************************************/

double AreaRectangulo (Rectangulo r)
{
	double long_lado_x = fabs(AnchoRectangulo(r));
	double long_lado_y = fabs(AltoRectangulo(r));
	return (long_lado_x * long_lado_y);
}


/***************************************************************************/
// Calcula y devuelve el punto central de un rectángulo.
//
// Recibe: r, el rectángulo.
// Devuelve: el punto central (Punto2D) del rectángulo "r".
/***************************************************************************/

Punto2D PuntoCentralRectangulo (Rectangulo r)
{
	Punto2D p;	
	
	p.x = (PuntoSuperiorIzquierdaRectangulo(r).x 
	     + PuntoSuperiorDerechaRectangulo(r).x) / 2.0;
	p.y = (PuntoSuperiorIzquierdaRectangulo(r).y 
	     +  PuntoInferiorIzquierdaRectangulo(r).y) / 2.0;
	 
	return (p);
}

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	// Núm. máximo de circunferencias en el array de circunferenmcias inscritas 
	const int MAX_CIRCUNFERENCIAS = 50;

	const double RADIO_INIC = 0.5;  // Valor del radio inicial
	const double INCR_RADIO = 0.25;	// Incremento del valor del radio


	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 

	// Leer los puntos que definen el rectángulo
	
	Rectangulo r;
			
	r.esquina_si = LeePunto("Esquina sup. izda."); // Lectura del centro
	r.esquina_id = LeePunto("Esquina inf. dcha."); // Lectura del centro
	
	
	// Mostrar las coordenadas de los cuatro puntos del rectángulo 
	// y del centro del rectángulo. 
	
	cout << endl;		
	cout << "Punto sup.izda. del rectangulo = " 
	     << ToString (PuntoSuperiorIzquierdaRectangulo(r))<< endl;	
	cout << "Punto sup.dcha. del rectangulo = " 
	     << ToString (PuntoSuperiorDerechaRectangulo(r))<< endl;	
	cout << "Punto ToString.izda. del rectangulo = " 
	     << ToString (PuntoInferiorIzquierdaRectangulo(r))<< endl;	
	cout << "Punto inf.dcha. del rectangulo = " 
	     << ToString (PuntoInferiorDerechaRectangulo(r))<< endl;	
	cout << endl;		

	Punto2D centro;	
	centro = PuntoCentralRectangulo (r);
	
	cout << endl;		
	cout << "Punto central del rectangulo = " << ToString (centro)<< endl;	
	cout << endl;		


	// Todas las circunferencias inscritas tendrán un radio menor o igual que 
	// la mitad de la longitud de la dimensión menor entre el alto y el ancho 
	// del rectángulo.

	double ancho_r = AnchoRectangulo (r);
	double alto_r  = AltoRectangulo (r);
	
	double min_dimension = ((ancho_r < alto_r) ? ancho_r : alto_r);
	double max_radio = min_dimension / 2;	


	// Creamos una circunferencia centrada en "centro", el centro del 
	// rectángulo. Las sucesivas circunferencias mantendrán el centro.
	
	Circunferencia circunferencias[MAX_CIRCUNFERENCIAS];
	int num_circ_insc = 0; // Num. de casillas usadas de "circunferencias"
	

	Circunferencia c;
	c.centro = centro; 	

	// El radio irá cambiando. El primer radio vale 0.5
	c.radio = RADIO_INIC;
		
	while (c.radio <= max_radio) {
	
		cout << "Guardando circunferencia centrada en " 
		     << ToString (CentroCircunferencia(c)); 
		cout << ". Radio = " << setw(6) << setprecision(2) << c.radio;		
		cout << endl;		

		circunferencias[num_circ_insc] = c; // Copiar al array
		num_circ_insc++; // Actualizar el contador
		
		c.radio += INCR_RADIO;
	} 
	
	// Mostrar datos de las circunferencias inscritas  

	cout << endl;
	cout << "Circunferencias inscritas = " << setw(3) << num_circ_insc << endl;
	cout << endl;
	
	for (int i=0; i<num_circ_insc; i++) {
		
		Circunferencia c = circunferencias[i];
		
		cout << "Circunferencia " << setw(3) << i+1 << " --> ";
		cout << "Centro = " << ToString (CentroCircunferencia(c));
		cout << ". Radio = " << setw(6) << setprecision(2) << c.radio;		
		cout << endl;	
	}

	return 0;
}

/***************************************************************************/
/***************************************************************************/

