/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 4
//
/*	
	Programa que lee las coordenadas que definen un rectángulo y calcula 
	la circunferencia centrada en el punto de corte de sus diagonales 
	tal que su superficie es la menor entre todas las circunferencias de 
	área mayor que la del rectángulo.

	En este programa se usa el struct "Punto2D" para representar un punto en 
	R^2 y el struct "Circunferencia" para representar circunferencias, y el 
	struct "Rectangulo" para representar rectángulos, 
	Un "Rectangulo" se caracteriza por: 
		1) coordenada superior izquierda (Punto2D)
		2) coordenada inferior derecha (Punto2D)
		
		
	NOTA IMPORTANTE: Esta solución emplea muchas (demasiadas) funciones pero 
	se da "tal cual" para que el alumno pueda ver -repetidamente- cómo se 
	pasan registros a funciones, cómo se devuelven registros desde funciones 
	y cómo se emplean la llamadas a funciones que devuelven registros 
	dentro de expresiones numéricas. 
	 
*/ 
/***************************************************************************/

#define _USE_MATH_DEFINES

#include <iostream>
#include <cctype>
#include <cmath>
#include <iomanip>

using namespace std;

	
/***************************************************************************/
// Constantes
/***************************************************************************/

const double PI = 3.1415926;	
const int TAM_CAD = 100;
		
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

Punto2D Centro (Circunferencia c)
{
	return (c.centro);
}

/***************************************************************************/
// Devuelve el radio de una circunferencia.
//
// Recibe: c, la circunferencia.
// Devuelve: el radio de "c".
/***************************************************************************/

double RadioCircunferencia (Circunferencia c)
{
	return (c.radio);
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

double Area (Circunferencia c)
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
	double dif_x = Centro(c).x - p.x;
	double dif_y = Centro(c).y - p.y;
	return ((dif_x * dif_x) + (dif_y * dif_y) <= RadioCircunferencia(c));
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
	double distancia = DistanciaEuclidea (p, Centro(c));
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

double Area (Rectangulo r)
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

Punto2D Centro (Rectangulo r)
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
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 

	Rectangulo r;
	Punto2D centro;
		
	double area_r, area_c;
	
	r.esquina_si = LeePunto("Esquina sup. izda."); // Lectura del centro
	r.esquina_id = LeePunto("Esquina inf. dcha."); // Lectura del centro
	
	cout << endl;		
	cout << "Punto sup.izda. del rectangulo = " 
	     << ToString (PuntoSuperiorIzquierdaRectangulo(r))<< endl;	
	cout << "Punto sup.dcha. del rectangulo = " 
	     << ToString (PuntoSuperiorDerechaRectangulo(r))<< endl;	
	cout << "Punto inf.izda. del rectangulo = " 
	     << ToString (PuntoInferiorIzquierdaRectangulo(r))<< endl;	
	cout << "Punto inf.dcha. del rectangulo = " 
	     << ToString (PuntoInferiorDerechaRectangulo(r))<< endl;	
	cout << endl;		
	
	
	centro = Centro (r);
	area_r = Area (r);
	
	cout << endl;		
	cout << "Punto central del rectangulo = " << ToString (centro)<< endl;	
	cout << "Area del rectangulo = " << setw(6) << setprecision(2) 
	     << area_r << endl;		
	cout << endl;		


	// Creamos una circunferencia centrada en "centro", el centro del 
	// rectángulo. Las sucesivas circunferencias mantendrán el centro.
	
	const double RADIO_INIC = 0.5;  // Valor del radio inicial
	const double INCR_RADIO = 0.25;	// Incremento del valor del radio
	
	Circunferencia c;
	c.centro = centro; 	

	// El radio irá cambiando. El primer radio vale RADIO_INIC
	c.radio = RADIO_INIC;
	
	area_c = Area (c);
	
	while (area_c < area_r) {
	
		cout << "Circunferencia centrada en " 
		     << ToString (Centro(c)); 
		cout << ". Radio = " << setw(6) << setprecision(2) << c.radio;		
		cout << ". Area = " << setw(6) << setprecision(2) << area_c;		
		cout << endl;		
		     
		c.radio += INCR_RADIO;
		area_c = Area (c);
	} 

	// Mostrar datos sobre la circunferencia  

	cout << endl;
	cout << "Circunferencia resultado:" << endl;
	cout << "Circunferencia centrada en " 
	     << ToString (Centro(c));
	cout << ". Radio = " << setw(6) << setprecision(2) << c.radio;		
	cout << ". Area = " << setw(6) << setprecision(2) << Area(c);
	cout << endl;	

	return 0;
}

/***************************************************************************/
/***************************************************************************/

