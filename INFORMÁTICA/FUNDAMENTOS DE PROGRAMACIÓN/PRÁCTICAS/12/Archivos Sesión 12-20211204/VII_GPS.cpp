/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 7
//
/*	
	Trabajo con la clase "SecuenciaCoordenadasGPS" para modelar modelar un 
	track GPS, basada en una secuencia de datos de tipo "CoordenadasGPS".
	
	(Ver enunciado)
*/
/***************************************************************************/

#include <iostream>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;


/***************************************************************************/
// Función global (asociada a la constante PRECISION_SON_IGUALES) que
// permite que dos números reales muy próximos sean considerados iguales.

const double PRECISION_SON_IGUALES = 1e-6; // 0.000001

bool SonIguales(double uno, double otro) 
{
	return (fabs(uno-otro) <= PRECISION_SON_IGUALES);
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// La clase CoordenadasGPS para representar las coordenadas geográficas de 
// una posición terrestre, dada por tres datos reales, a saber, su longitud, 
// latitud y altura. 

class CoordenadaGPS 
{
	
private:
	
	static const double PI;
	static const double RADIANES_POR_GRADO;
	static const double GRADOS_POR_RADIAN;
	static const double METROS_POR_KILOMETRO;
	static const double KILOMETROS_POR_METRO;


	// La tripleta (latitud, longitud, altura) son las coordenadas de un 
	// punto en el espacio. 
	
	// En radianes (unidad escogida para el almacenamiento): 
	// PRE: -PI/2 <= latitud <= PI/2 
	// Lat.S si -PI/2 <= latitud < 0, Lat.N. si 0 <= latitud <= PI/2 (N)
	//
	// En grados: 
	// PRE: -90 <= latitud <= 90 
	// Lat.S si -90 <= latitud < 0, Lat.N. si 0 <= latitud <= 90 (N)
	double latitud;
	
	// En radianes (unidad escogida para el almacenamiento): 
	// PRE: -PI <= longitud <= PI 
	// Lon.E si 0 <= longitud < PI, Lon.W. si -PI <= longitud < 0
	//
	// PRE: -180 <= longitud <= 180 
	// Lon.E si 0 <= longitud < 180, Lon.W. si -180 <= longitud < 0
	double longitud;

	// PRE: -423 <= altura <= 8848 
	double altura;
	
public:

	/***********************************************************************/
	// Constructor sin argumentos.
	// NECESARIO PARA CREAR UNA ARRAY DE DATOS "CoordenadaGPS" en la clase 
	// "SecuenciaCoordenadasGPS". No se debe usar para nada más. 
	
	CoordenadaGPS (void) 
	{ }

	/***********************************************************************/
	// Constructor con argumentos.
	//
	// Recibe: 	la_latitud (grados), la_longitud (grados) y la_altura (metros) 
	//			del punto que se está creando.
	// PRE:  -90 <= la_latitud <= 90 	
	// PRE: -180 <= la_longitud <= 180
	// PRE: -423 <= la_altura <= 8848 
	
	CoordenadaGPS (double la_latitud, double la_longitud, double la_altura) 
	{
		SetCoordenadas (la_latitud, la_longitud, la_altura);
	}

	/***********************************************************************/
	// Método Set para fijar simultaneamente las coordenadas.
	//
	// Recibe: 	la_latitud (grados), la_longitud (grados) y la_altura (metros) 
	//			del punto que se está modificando.
	// PRE:  -90 <= la_latitud <= 90 	
	// PRE: -180 <= longitud <= 180
	// PRE: -423 <= la_altura <= 8848 
	// POST: Los valores de "latitud" y "longitud" se guardan en radianes.  
	
	void SetCoordenadas (double la_latitud, double la_longitud, 
	                     double la_altura)
	{
		latitud  = ToRadianes(la_latitud);
		longitud = ToRadianes(la_longitud);
		altura   = la_altura;
	}

	/***********************************************************************/
	// Métodos Get para leer las coordenadas

	double GetLatitudRadianes (void)
	{
		return (latitud);
	}

	double GetLongitudRadianes(void)
	{
		return (longitud);
	}

	double GetLatitudGrados (void)
	{
		return (ToGrados(latitud));
	}

	double GetLongitudGrados (void)
	{
		return (ToGrados(longitud));
	}

	double GetAltura (void)
	{
		return (altura);
	}
	
	double GetAlturaKm (void)
	{
		return (ToKm(altura));
	}
	
	/***********************************************************************/
	// Calcula la diferencia de altura entre dos datos "CoordenadaGPS"
	double DiferenciaAltura (CoordenadaGPS otro)
	{
		return (altura-otro.altura);	
	}
	
	/***********************************************************************/
	// Calcula la distancia sobre plano entre dos datos "CoordenadaGPS"
	double DistanciaSobrePlano (CoordenadaGPS otro)
	{
		// Calculos: Distancia -sobre plano- entre dos puntos 
		//
		// Suponiendo que la Tierra es esférica, de radio R, la distancia 
		// -despreciando la altura- entre dos puntos cuyas coordenadas vienen 
		// dadas en grados de latitud y longitud puede calcularse por la
		// "Fórmula del Haversine":  
		//
		/*  Haversine Formula (from R.W. Sinnott, "Virtues of the Haversine", 
				Sky and Telescope, vol. 68, no. 2, 1984, p. 159):
	
		    dlon = lon2 - lon1
		    dlat = lat2 - lat1
		    a = sin^2(dlat/2) + cos(lat1) * cos(lat2) * sin^2(dlon/2)
		    c = 2 * arcsin(min(1,sqrt(a)))
		    d = R * c
	    
		    donde las coordenadas del primer punto son (lat1, lon1)  y las 
			del segundo son (lat2, lon2)
		*/
	
		// Radio medio de la Tierra en WGS-84 (World Geodetic System 84) 

		const double R = 6372797.560856; // m
	
		// Los datos de latitud y longitud están en radianes por lo que 
		// no se prercisa conversión
		double dlat = (otro.latitud - latitud); 
		double dlon = (otro.longitud - longitud); 

		/*		
		cout << endl;	
		cout << "Rad--> 1: " << ToStringRadianes() << endl;
		cout << "Rad--> 2: " << otro.ToStringRadianes() << endl;
		cout << endl;
		cout << "dlat (rad)= " << dlat << endl;
		cout << "dlon (rad)= " << dlon << endl;
		cout << endl << endl;
		*/
		
		double sen2dlat = sin(dlat * 0.5);
		sen2dlat *= sen2dlat;  
		    
		double sen2lon = sin(dlon * 0.5);
		sen2lon *= sen2lon;
		
		double coslat1coslat2 = cos (latitud) * cos (otro.latitud);		
		double a = sen2dlat + coslat1coslat2 * sen2lon;
		                                      
		double minimo = sqrt(a); 
		if (1.0 < minimo) minimo = 1.0;
		
		double c = 2.0 * asin(minimo);

		double dp = R * c; // Distancia sobre plano
		
		return (dp);
	}
	
	/***********************************************************************/
	// Calcula la distancia real entre dos datos "CoordenadaGPS"
	double DistanciaReal (CoordenadaGPS otro)
	{
		
		double dp = DistanciaSobrePlano(otro); // Distancia sobre plano
		
		double dh = altura - otro.altura; // Diferencia de altura
		
		double dr = sqrt(pow(dp, 2) + pow(dh, 2)); // Distancia real
	
		return (dr);
	}
		
	/***********************************************************************/
	// Devuelve un string con la representación textual de una "CoordenadaGPS"
	
	string ToStringRadianes ()
	{
		return ("[ (" + to_string(GetLatitudRadianes())  + ", " +
		                to_string(GetLongitudRadianes()) + ") " + ", " +  
		                to_string(GetAlturaKm()) + "]");
	}

	/***********************************************************************/
	// Devuelve un string con la representación textual de una CoordenadaGPS
	
	string ToStringGrados ()
	{
		return ("[ (" + to_string(GetLatitudGrados())  + ", " +
		                to_string(GetLongitudGrados()) + ") " + ", " +  
		                to_string(GetAltura()) + "]");
	}
	
	/***********************************************************************/
   
private: 

	double ToRadianes (double grados)
	{
		return (grados * RADIANES_POR_GRADO);
	}
	
	double ToGrados (double radianes)
	{
		return (radianes * GRADOS_POR_RADIAN);
	}
	
	double ToKm (double metros) 
	{
		return (metros * KILOMETROS_POR_METRO);
	}
   
};

const double CoordenadaGPS::PI = 3.14159265358979323846;
const double CoordenadaGPS::RADIANES_POR_GRADO = PI / 180.0;
const double CoordenadaGPS::GRADOS_POR_RADIAN = 1 / RADIANES_POR_GRADO;
const double CoordenadaGPS::METROS_POR_KILOMETRO = 1000.0;
const double CoordenadaGPS::KILOMETROS_POR_METRO = 1/ METROS_POR_KILOMETRO;

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class SecuenciaCoordenadasGPS 
{
private:

	// Datos asociados a la estructura de datos empleada para guardar 
	// los valores de la secuencia.

	static const int TAMANIO = 200; // Número de casillas disponibles

	CoordenadaGPS vector_privado[TAMANIO];
	
	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;	// Número de casillas ocupadas
	

public:
	
	/***********************************************************************/
	// Constructor sin parámetros. 

	SecuenciaCoordenadasGPS (void) : total_utilizados(0) { }

	/***********************************************************************/
	// Constructor a partir de una coordenada. 
	//
	// Recibe: CoordenadaGPS, la única coordenada que forma la nueva secuencia. 
	
	SecuenciaCoordenadasGPS (CoordenadaGPS nueva_coordenada) 
		: total_utilizados(0)
	{ 
		Aniade (nueva_coordenada);
	}

	/***********************************************************************/
	// Métodos de lectura (Get) sobre tamaño y capacidad de la secuencia 

	// Devuelve el número de coordenadas que componen la secuencia.
	int NumCoordenadas ()
	{
		return (total_utilizados);
	}

	// Devuelve el número de puntos que podrían formar una secuencia completa.
	int CapacidadSecuencia()
	{
		return (TAMANIO);
	}


	/***********************************************************************/
	// Añade una coordenada a la secuencia.
	// Recibe: nueva_coordenada, la coordenada que se va a añadir.
	//
	// PRE: total_utilizados < TAMANIO
	// 		La adición se realiza si hay espacio para el nuevo elemento. 
	// 		El nuevo elemento se coloca al final del vector. 
	// 		Si no hay espacio, no se hace nada.	

	void Aniade (CoordenadaGPS nueva_coordenada)
	{
		if (total_utilizados < TAMANIO) {
			vector_privado[total_utilizados] = nueva_coordenada;
			total_utilizados++;
		}
	}

	/***********************************************************************/
	// Devuelve el elemento de la casilla "indice" 
	//
	// PRE: 0 <= indice < total_utilizados 

	CoordenadaGPS Elemento (int indice)
	{
		return (vector_privado[indice]);
	}
	
	/***********************************************************************/
	// Calcula el máximo desnivel de la secuencia. 
	// Se define como la máxima diferencia (en valor absoluto) entre 
	// dos alturas consecutivas.
	
	double MaxDesnivel ()
	{
		double maximo_desnivel = 0;
		
		for (int pos=1; pos<total_utilizados; pos++) {
			
			double altura1 = (vector_privado[pos-1]).GetAltura();
			double altura2 = (vector_privado[pos]).GetAltura();
			
			double dif_altura = fabs(altura1 - altura2);

			if (dif_altura > maximo_desnivel) maximo_desnivel = dif_altura;
		}

		return (maximo_desnivel);
	}

	/***********************************************************************/
	// Calcula el desnivel acumulado positivo de la secuencia. 
	//  Se calcula como la suma de las diferencias de altura positivas 
	// entre cada dos puntos consecutivos.
	
	double DesnivelAcumuladoPositivo ()
	{
		double desnivel_acumulado_positivo = 0;
		
		for (int pos=1; pos<total_utilizados; pos++) {
			
			double altura1 = (vector_privado[pos-1]).GetAltura();
			double altura2 = (vector_privado[pos]).GetAltura();
			
			double dif_altura = altura2 - altura1;	

			if (dif_altura > 0) desnivel_acumulado_positivo += dif_altura;
		}
		
		return (desnivel_acumulado_positivo);
	}

	/***********************************************************************/
	// Calcula la distancia real  de la secuencia. 
	// Se calcula como la suma de las distancias reales entre cada dos 
	// puntos consecutivos.
	
	double DistanciaReal ()
	{
		double suma_distancia_real = 0;
		
		for (int pos=1; pos<total_utilizados; pos++) {
			
			CoordenadaGPS coord_1 = vector_privado[pos-1];
			CoordenadaGPS coord_2 = vector_privado[pos];
			
			double dist_real = coord_1.DistanciaReal(coord_2);

			suma_distancia_real += dist_real;
		}

		return (suma_distancia_real);
	}
	
	/***********************************************************************/
	// Calcula la distancia sobre plano de la secuencia. 
	// Se calcula como la suma de las distancias sobre plano entre cada dos 
	// puntos consecutivos.
	
	double DistanciaSobrePlano ()
	{
		double suma_distancia_plano = 0;
		
		for (int pos=1; pos<total_utilizados; pos++) {
	
			CoordenadaGPS coord_1 = vector_privado[pos-1];
			CoordenadaGPS coord_2 = vector_privado[pos];
			
			double dist_plano = coord_1.DistanciaSobrePlano(coord_2);

			suma_distancia_plano += dist_plano;
		}

		return (suma_distancia_plano);
	}
	/***********************************************************************/

};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////


/***************************************************************************/
/***************************************************************************/

int main()
{
	/*	Parte de un track real: 
	
	 <trkpt lat="37.248279" lon="-3.681155">
        <ele>800</ele>
        <time>2015-04-29T10:04:17Z</time>
      </trkpt>
      <trkpt lat="37.248186" lon="-3.681268">
        <ele>802</ele>
        <time>2015-04-29T10:04:21Z</time>
      </trkpt>
      <trkpt lat="37.248164" lon="-3.681404">
        <ele>802</ele>
        <time>2015-04-29T10:04:25Z</time>
      </trkpt>
      <trkpt lat="37.248231" lon="-3.681583">
        <ele>798</ele>
        <time>2015-04-29T10:04:29Z</time>
      </trkpt>
	*/
	
	SecuenciaCoordenadasGPS track;
	
	track.Aniade(CoordenadaGPS(37.248279, -3.681155, 800));
	track.Aniade(CoordenadaGPS(37.248186, -3.681268, 802));
	track.Aniade(CoordenadaGPS(37.248164, -3.681404, 802));
	track.Aniade(CoordenadaGPS(37.248231, -3.681583, 799));

	// Mostrar track
	
	cout << endl; 
	cout << "Track:" << endl; 
	cout << endl; 
	
	for (int i=0; i<track.NumCoordenadas(); i++)
		cout << track.Elemento(i).ToStringGrados() << endl;

	// Calcular Maximo desnivel
	
	cout << endl; 
	cout << "Max. desnivel = " << track.MaxDesnivel() << " m."<< endl; 
	cout << endl; 
	
	// Calcular desnivel acumulado positivo

	cout << endl; 
	cout << "Desnivel acumulado positivo = " 
	     << track.DesnivelAcumuladoPositivo() << endl; 
	cout << endl; 
	
	// Calcular distancia sobre plano

	cout << endl; 
	cout << "Distancia sobre plano = " 
	     << track.DistanciaSobrePlano() << " m."<< endl; 
	cout << endl; 
	
	// Calcular distancia real

	cout << endl; 
	cout << "Distancia real = " << track.DistanciaReal() << " m."<< endl; 
	cout << endl; 
	
	return 0;
}

/***************************************************************************/
/***************************************************************************/

