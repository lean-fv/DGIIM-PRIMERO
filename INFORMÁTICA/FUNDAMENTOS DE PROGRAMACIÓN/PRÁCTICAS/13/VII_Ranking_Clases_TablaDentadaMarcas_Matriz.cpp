/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS VII

52. En el ejercicio 36 de esta Relación de Problemas (ordenación de marcas de
atletismo) se propuso el uso de clases para caracterizar las marcas sobre las
que se trabaja, además de sus componentes complejas: el tiempo y la fecha.

En ese ejercicio, no obstante, se usaba una matriz clásica y un array para poder
manejar una estructura de matriz dentada que nos permitiera representar y
organizar las marcas por cada tipo de prueba. Ahora proponemos crear un tipo de
dato específico, TablaDentadaMarcas, para gestionar una tabla dentada de datos
de tipo RegistroDeMarca. La descripción de las clases (una propuesta
orientativa) se especifica en la figura 49.

Reescriba la solución del ejercicio 36 de esta Relación de Problemas usando las
clases SecuenciaMarcas y TablaDentadaMarcas.

ENTRADA: un numero de pruebas, el nombre de las pruebas, una licencia, fecha
y el tiempo en completar el recorrido.
SALIDA: clasificacion final segun el tiempo.

*/


#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


// Numero maximo de pruebas a leer
const int MAX_PRUEBAS = 20;

// Numero maximo de marcas de cada prueba.
const int MAX_MARCAS_EN_PRUEBA = 100;




/***************************************************************************
Funcion ToStringInt: que pasa a string un numero entero, con los espacios
deseados deseen. Si no sobran espacios, estos se rellenan.


PRE: entero es estrictamente un dato entero y num_casillas > 0.
***************************************************************************/

string ToStringInt (int entero, int num_casillas, char relleno){
	string resultado;

	resultado=to_string(entero);
	int lon=resultado.length();

	if(lon<num_casillas){
		for(int i=lon; i<num_casillas; i++){
			resultado=relleno + resultado;
		}
	}

	return resultado;
}


/*---------------------------------------------------------------------------
								Clase Fecha
---------------------------------------------------------------------------*/


class Fecha{

private:


	int dia; //PRE: 1<=dia<=31;
	int mes; //PRE: 1<=mes<=12;
	int anio;


public:


	//Constructor con argumentos
	Fecha(string fecha)
	{
		ComponeFecha(fecha);
	}


	//Constructor sin argumentos.
	Fecha(void): dia(0), mes(0), anio(0)
	{}


	//Setters

	void SetDia(string d){
		dia=stoi(d);
	}

	void SetMes(string m){
		mes=stoi(m);
	}

	void SetAnio(string a){
		anio=stoi(a);
	}

	void ComponeFecha(string fecha_leida){
		SetDia(fecha_leida.substr(0,2));
		SetMes(fecha_leida.substr(3,2));
		SetAnio(fecha_leida.substr(6,4));
	}

	/**************************************************************************
	Metodo ToString: Pasa a string una fecha.

	PRE: 1<=dia<=31 y 1<=mes<=12.
	***************************************************************************/

	string ToString(){

		const string meses[]={"Enero     ", "Febrero   ", "Marzo     ",
							  "Abril     ", "Mayo      ", "Junio     ",
							  "Julio     ", "Agosto    ", "Septiembre",
							  "Octubre   ", "Noviembre ", "Diciembre "};

		string resultado;

		string mes_string=meses[mes-1];

		resultado=ToStringInt(dia, 3, ' ') + " " + mes_string + " " +
				  ToStringInt(anio, 4, ' ');

		return resultado;
	}

};


/*---------------------------------------------------------------------------
									Clase Tiempo
---------------------------------------------------------------------------*/

class Tiempo{


private:
	int horas; //PRE: horas<HORAS_DIA
	int minutos; //PRE: minutos horas < MINUTOS_HORA
	int segundos; //PRE: segundos < SEGUNDOS_HORA
	int milisegundos; //PRE: milisegundos < MILISEGUNDOS_SEGUNDO



public:


	//Constructor con argumentos.
	Tiempo(string tiempo)
	{
		ComponeTiempo(tiempo);
	}


	//Constructor sin argumentos.
	Tiempo(): horas(0), minutos(0), segundos(0), milisegundos(0)
	{}


	//Setters.

	void SetHoras(string h){
		horas=stoi(h);
	}


	void SetMinutos(string m){
		minutos=stoi(m);
	}


	void SetSegundos(string s){
		segundos=stoi(s);
	}


	void SetMilisegundos(string mili){
		milisegundos=stoi(mili);
	}


	void ComponeTiempo(string tiempo_leido){
		SetHoras(tiempo_leido.substr(0,2));
		SetMinutos(tiempo_leido.substr(3,2));
		SetSegundos(tiempo_leido.substr(6,2));
		SetMilisegundos(tiempo_leido.substr(9,3));
	}



	/**************************************************************************
	Metodo ToString: devuelve el tiempo, restringido hasta la magnitud deseada.
	***************************************************************************/

	string ToString(){

		//Tipo enumerado de las maneras de imprimir las marcas.

		enum class CategoriaTiempo{horas, minutos,segundos};

		CategoriaTiempo categoria;
		string resultado;

		//Compruebo hasta que magnitud tengo se debe imprimir.
		if(horas!=0) categoria=CategoriaTiempo::horas;
		else if(horas==0 && minutos!=0)
			categoria=CategoriaTiempo::minutos;
		else if(horas==0 && minutos==0)
			categoria=CategoriaTiempo::segundos;

		if (categoria == CategoriaTiempo::segundos) {
			resultado=ToStringInt(segundos, 2, '0') + ":" +
					  ToStringInt(milisegundos, 3, '0');
		}
		else if (categoria == CategoriaTiempo::minutos){
			resultado=ToStringInt(minutos, 2, '0') + ":" +
					  ToStringInt(segundos, 2, '0') + ":" +
					  ToStringInt(milisegundos, 3, '0');
		}
		else if (categoria == CategoriaTiempo::horas){
			resultado=ToStringInt(horas, 2, '0') + ":" +
					  ToStringInt(minutos, 2, '0') + ":" +
					  ToStringInt(segundos, 2, '0') + ":" +
					  ToStringInt(milisegundos, 3, '0');

		}

		return resultado;
	}


	/**************************************************************************
	Metodo EsMayor: compara dos objetos de tipo Tiempo.
	***************************************************************************/

	bool EsMayor(Tiempo tiempo2){
		const int MINS_HORA=60;
		const int SEGS_MIN=60;
		const int MILISEGS_SEGS=1000;

		double milisegs_tiempo1=(horas*MINS_HORA*SEGS_MIN*MILISEGS_SEGS) +
							(minutos*SEGS_MIN*MILISEGS_SEGS)
							+(segundos*MILISEGS_SEGS)+milisegundos;
		double milisegs_tiempo2=(tiempo2.horas*MINS_HORA*SEGS_MIN*MILISEGS_SEGS)
								 +(tiempo2.minutos*SEGS_MIN*MILISEGS_SEGS)+
								(tiempo2.segundos*MILISEGS_SEGS)+
								tiempo2.milisegundos;

		return milisegs_tiempo1>milisegs_tiempo2;
	}
};



/*---------------------------------------------------------------------------
							Clase RegistroDeMarca
---------------------------------------------------------------------------*/

class RegistroDeMarca{

private:


	string prueba;
	Fecha fecha;
	Tiempo tiempo;
	string licencia;


	//Tipo enumerado para serializar un dato
	enum class TipoAjuste {izquierda, centro, derecha};



	/***************************************************************************
	Metodo FormateaString: Ajusta un string.
	***************************************************************************/

	string FormateaString (string cad, int num_casillas, TipoAjuste ajuste,
							   char relleno=' ')
	{
		string resultado=cad;
		int lon=resultado.length();

		if(lon<num_casillas){

			if (ajuste == TipoAjuste::izquierda){
				for(int i=lon; i<=num_casillas; i++)
					resultado=resultado +relleno ;
				}

			else if (ajuste == TipoAjuste::derecha){
					for(int i=lon; i<=num_casillas; i++)
						resultado=relleno + resultado ;
			}
			else if  (ajuste == TipoAjuste::centro){
					for(int i=lon; i<=num_casillas; i++){
						i%2==0 ? resultado=relleno + resultado :
									resultado=resultado +relleno;
					}
				}
			}


		return resultado;

	}


public:


	//Constructor con argumentos.

	RegistroDeMarca(string p, Fecha f, Tiempo t, string l):
		prueba(p), fecha(f), tiempo(t), licencia(l)
	{}


	//Constructor sin argumentos.

	RegistroDeMarca():
		prueba(""), fecha(), tiempo(), licencia("")
	{}


	//Setter

	void SetMarca(string p, Fecha f, Tiempo t, string l){
		prueba=p;
		fecha=f;
		tiempo=t;
		licencia=l;
	}


	//Getters.

	Tiempo GetTiempo(){
		return tiempo;
	}

	string GetLicencia(){
		return licencia;
	}

	Fecha GetFecha(){
		return fecha;
	}


	/***********************************************************************
	Metodo ToString: compone la marca completa.
	***************************************************************************/

	string ToString (void)
	{
		string cad;

		cad = FormateaString (licencia , 9, TipoAjuste::derecha) + "  " +
			  	fecha.ToString() + "  " +
			 	tiempo.ToString();

		return cad;
	}

};



/*---------------------------------------------------------------------------
							Clase SecuenciaMarcas
---------------------------------------------------------------------------*/

class SecuenciaMarcas{

private:


	static const int TAMANIO=MAX_MARCAS_EN_PRUEBA; //Maximo de marcas por prueba

	RegistroDeMarca vector_privado[TAMANIO];

	//PRE: 0<=total_utilizados<=TAMANIO
	int total_utilizados;


public:

	//Constructor sin argumentos

	SecuenciaMarcas(): total_utilizados(0)
	{}

	//Getters.

	int TotalUtilizados(){
		return total_utilizados;
	}

	int Capacidad(){
		return TAMANIO;
	}

	//PRE: 0<=indice<total_utilizados
	RegistroDeMarca Elemento(int indice){
		return vector_privado[indice];

	}

	/**************************************************************************
	Metodo EliminaTodos : elimina todos los elementos de la secuencia.
	***************************************************************************/

	void EliminaTodos(){
		total_utilizados=0;
	}

	/**************************************************************************
	Metodo Aniade: aniade una nueva marca al vector.

	PRE: total_utilizados < TAMANIO
	***************************************************************************/
	void Aniade(RegistroDeMarca r){
		if(total_utilizados < TAMANIO){
			vector_privado[total_utilizados]=r;
			total_utilizados++;
		}
	}

	/**************************************************************************
	Metodo Modifica: modifica el elemento de la casilla indice por el nuevo.

	PRE: 0<=indice<total_utilizados
	***************************************************************************/

	void Modifica(int indice, RegistroDeMarca nuevo){
		if(indice>=0 && indice<total_utilizados){
			vector_privado[indice]=nuevo;
		}
	}

	/**************************************************************************
	Metodo Elimina: elimina el elemento de una posicion determinada.

	PRE: 0<=indice<total_utilizados
	***************************************************************************/

	void Elimina(int indice){
		if(indice>=0 && indice<total_utilizados){
			for(int i=indice; i<total_utilizados; i++){
				vector_privado[i]=vector_privado[i+1];
			}
			total_utilizados--;
		}
	}


	/**************************************************************************
	//Metodo Inserta: inserta un elemento en una posicion determinada.

	PRE: 0<=indice<total_utilizados y total_utilizados<TAMANIO.
	***************************************************************************/

	void Inserta(int indice, RegistroDeMarca nuevo){
		if(total_utilizados < TAMANIO && indice>=0 && indice<total_utilizados){
			for(int i=total_utilizados; i>indice; i--)
				vector_privado[i]=vector_privado[i-1];

			vector_privado[indice]=nuevo;
			total_utilizados++;
		}
	}

	/**************************************************************************
	Metodo OrdenaSecuencia: ordena la secuencia

	PRE: total_utilizados > 0
	***************************************************************************/
	void OrdenaSecuencia(){

		if(total_utilizados>0){
			bool cambio = true;

			int izda = 0 ;

			while(izda<total_utilizados && cambio){

				//cambio = true si hay algun intercambio.
				cambio = false;

				for (int c =total_utilizados-1 ; c > izda ; c--){

					// Intercambiar
					bool mayor=vector_privado[c-1].GetTiempo().
										 EsMayor(vector_privado[c].GetTiempo());

					if(mayor){
						RegistroDeMarca intercambia(vector_privado[c]);
						Modifica(c, vector_privado[c-1]);
						Modifica(c-1, intercambia);
						cambio = true; // Se ha hecho un intercambio
					}
				}

				izda++;
			}
		}
	}


};


/*---------------------------------------------------------------------------
							Clase TablaDentadaMarcas
---------------------------------------------------------------------------*/

class TablaDentadaMarcas{

private:

	static const int NUM_FILAS=MAX_PRUEBAS; //Maximo de pruebas
	static const int NUM_COLS=MAX_MARCAS_EN_PRUEBA; //Maximo marcas por prueba

	RegistroDeMarca matriz_privada[NUM_FILAS][NUM_COLS];

	//PRE: 0<=filas_utilizadas<=NUM_FILAS
	int filas_utilizadas;

	//PRE: 0<=num_cols_utilizadas[i]<=NUM_COLS
	int num_cols_utilizadas[NUM_FILAS];


	/**************************************************************************
	Metodo ReemplazaFila: reemplaza una fila por otra.
	**************************************************************************/

	void ReemplazaFila (int fila_a_borrar, int fila_origen){
		int columnas_utilizadas = num_cols_utilizadas[fila_origen];

		for (int col = 0; col < columnas_utilizadas; col++)
			matriz_privada[fila_a_borrar][col]=matriz_privada[fila_origen][col];

		num_cols_utilizadas[fila_a_borrar] = columnas_utilizadas;
	}


public:


	//Constructor sin argumentos
	TablaDentadaMarcas(): filas_utilizadas(0)
	{}

	//Constructores con argumentos

	TablaDentadaMarcas (SecuenciaMarcas primera_fila): filas_utilizadas(0)
	{
		Aniade(primera_fila);
	}


	TablaDentadaMarcas(int num_pruebas): filas_utilizadas(num_pruebas)
	{
		for(int p=0; p<num_pruebas; p++){
			num_cols_utilizadas[p]=0;
		}
	}


	//Getters

	int CapacidadFilas(){
		return NUM_FILAS;
	}

	int CapacidadColumnas(){
		return NUM_COLS;
	}

	int FilasUtilizadas(){
		return filas_utilizadas;
	}

	int ColumnasUtilizadas(int fila){
		return num_cols_utilizadas[fila];
	}

	//PRE: 0<=fila<filas_utilizadas
	//	   0<=columna<=num_cols_utilizadas[fila]
	RegistroDeMarca Elemento(int fila, int columna){
		return matriz_privada[fila][columna];
	}

	//PRE: 0<=fila<filas_utilizadas
	SecuenciaMarcas Fila(int fila){
		SecuenciaMarcas f;

		for(int i=0; i<num_cols_utilizadas[fila]; i++){
			f.Aniade(matriz_privada[fila][i]);
		}

		return f;
	}


	/**************************************************************************
	Metodo Aniade: aniadir una fila nueva (pruebas de otra marca).

	PRE: fila.TotalUtilizados() <= NUM_COLS y filas_utilizadas < NUM_FILS.
	***************************************************************************/

	void Aniade(SecuenciaMarcas fila_nueva){
		int numero_cols_fila_nueva = fila_nueva.TotalUtilizados();

		if(filas_utilizadas < NUM_FILAS && numero_cols_fila_nueva<=NUM_COLS){

			for(int c=0; c<numero_cols_fila_nueva; c++){
				matriz_privada[filas_utilizadas][c]=fila_nueva.Elemento(c);
			}

			num_cols_utilizadas[filas_utilizadas]=numero_cols_fila_nueva;
			filas_utilizadas++;
		}
	}


	/**************************************************************************
	Metodo AniadeMarca: aniadir una marca a la fila correspondiente.

	PRE: cols_fila<NUM_COLS
	***************************************************************************/

	void AniadeMarca(RegistroDeMarca m, int fila){
		int cols_fila=num_cols_utilizadas[fila];

		if(cols_fila<NUM_COLS){
			matriz_privada[fila][cols_fila]=m;
			num_cols_utilizadas[fila]++;
		}
	}


	/**************************************************************************
	Metodo Inserta: introduce una fila nueva en la matriz

	PRE: filas_utilizadas < NUM_FILS
		 num_cols_nueva <= NUM_COLS
		 fila_insercion >= 0 && fila_insercion <= filas_utilizadas
	***************************************************************************/

	void Inserta(SecuenciaMarcas fila_nueva, int fila_insercion){
		int num_cols_nueva = fila_nueva.TotalUtilizados();

		if (num_cols_nueva <= NUM_COLS && filas_utilizadas < NUM_FILAS &&
			fila_insercion >= 0 && fila_insercion <= filas_utilizadas) {

			for (int i = filas_utilizadas ; i > fila_insercion ; i--)
				ReemplazaFila(i, i-1);

			for (int j = 0; j < num_cols_nueva; j++)
				matriz_privada[fila_insercion][j] = fila_nueva.Elemento(j);

			filas_utilizadas++;
			num_cols_utilizadas[fila_insercion] = num_cols_nueva;
		}
	}


	/**************************************************************************
	Metodo Elimina: que elimina una fila de la matriz

	PRE: fila >= 0 y fila < filas_utilizadas.
	***************************************************************************/

	void Elimina(int fila_elimina){
		for(int i=fila_elimina; i<filas_utilizadas; i++){
			ReemplazaFila(i, i+1);
		}

		filas_utilizadas--;
	}


	/**************************************************************************
	Metodo SustituyeFila: compone y devuelve un string con el contenido de la
	matriz.

	Pre: numero_cols_fila_nueva<=NUM_COLS
	***************************************************************************/

	void SustituyeFila(int fila, SecuenciaMarcas s){
		int numero_cols_fila_nueva = s.TotalUtilizados();

		if(numero_cols_fila_nueva<=NUM_COLS){
			for(int c=0; c<numero_cols_fila_nueva; c++){
				matriz_privada[fila][c]=s.Elemento(c);
			}

			num_cols_utilizadas[fila]=numero_cols_fila_nueva;
		}
	}

};


/*---------------------------------------------------------------------------
							Programa principal
---------------------------------------------------------------------------*/

int main(){


	//Declaraciones.
	const string TERMINADOR = "FIN";


	// Array que contiene los nombres de las pruebas y su posicion (fila)
	// en la matriz de marcas.
	string pruebas[MAX_PRUEBAS];

	// Numero de casillas ocupadas de "pruebas" (y filas de "marcas")
	int num_pruebas = 0;

	//Entrada de datos.

	//Lectura de pruebas.
	//PRE: 0 <= num_pruebas <= MAX_PRUEBAS

	cin >> num_pruebas;

	for (int pos=0; pos<num_pruebas; pos++)
		cin >> pruebas[pos];



	TablaDentadaMarcas marcas (num_pruebas);


	// Leectura de marcas.

	Fecha la_fecha;
	Tiempo el_tiempo;

	int cont_marcas = 0; /// N�mero de l�neas leidas

	string la_prueba, cad_fecha, cad_licencia, cad_tiempo;

	cin >> la_prueba;

	while (la_prueba != TERMINADOR) {

		cont_marcas++;

		int pos_prueba=0;
		while (pruebas[pos_prueba] != la_prueba) pos_prueba++;
		// Aseguramos que 0 <= pos_prueba < num_pruebas

		// Se leen los demas datos de la marca actual

		cin >> 	cad_fecha;
		Fecha la_fecha (cad_fecha); // Crear objeto "Fecha"

		cin >> cad_licencia;

		cin >> cad_tiempo;
		Tiempo el_tiempo (cad_tiempo); // Crear objeto "Tiempo"


		/* Crear un objeto "RegistroDeMarca" y guardarlo en la fila
		"pos_prueba" de "marcas" y actualizar el contador de datos para
		la prueba (num_marcas_en_prueba[pos_prueba]) */

		RegistroDeMarca la_marca (la_prueba, la_fecha, el_tiempo, cad_licencia);
		marcas.AniadeMarca (la_marca, pos_prueba);

		cin >> la_prueba;
		// Consecuencia de lectura anticipada

	} // while (cad_prueba != TERMINADOR)


	/* Mostrar los datos leidos y guardados en la matriz "marcas"

	cout << endl;
	cout << "Se procesan "<< setw(2)<< num_pruebas << " pruebas: ";
	for (int pos=0; pos<num_pruebas; pos++)
		cout << setw(8) << pruebas[pos];
	cout << endl;

	cout << endl;
	cout << "Se han guardado "<< setw(4) << cont_marcas << " marcas:" << endl;
	cout << endl;
	*/

	//Calculos

	// Ordenaci�n de cada fila de la matriz "marcas" por "tiempo_marca"
	// El procedimiento ser� 1) extraer una copia de cada fila de la
	// matriz, 2) ordenarla y 3) sustituir la fila antigua (desordenada)
	// por la secuencia ordenada.

	for (int p=0; p<num_pruebas; p++) { // para cada prueba "p"

		// Extraer copia de la fila "p"
 		SecuenciaMarcas marcas_fila_p = marcas.Fila(p);

		// Ordenar la secuencia
		marcas_fila_p.OrdenaSecuencia();

		// Sustituir la fila "p" por la secuencia ordenada
		marcas.SustituyeFila (p, marcas_fila_p);

	}


	//Salida de datos.

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);

	cout << endl;
	cout << "Ranking final: "<< endl;
	cout << endl;

	for (int p=0; p<num_pruebas; p++) {

		cout << setw(8) << pruebas[p] << endl;

		for (int m=0; m<marcas.ColumnasUtilizadas(p); m++){
			cout << '\t' << setw(3) << m+1
			     << marcas.Elemento(p,m).ToString() << endl;
		}
		cout << endl;

	}

	cout << endl << endl;
	cout << "***********************************************" << endl << endl;

	return 0;
}
