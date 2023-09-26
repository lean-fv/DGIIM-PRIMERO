/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS VII

36. Reescriba la solución del ejercicio 44 de la Relación de Problemas V usando
clases, siguiendo las pautas dadas en el ejercicio 35 de esta Relación de
Problemas.

ENTRADA: un numero de pruebas, el nombre de las pruebas, una licencia, fecha
y el tiempo en completar el recorrido.
SALIDA: clasificacion final segun el tiempo.

*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


/*---------------------------------------------------------------------------
									Clase Fecha
---------------------------------------------------------------------------*/

class Fecha {

private:

	int dia; // PRE: 1 <= dia <= 31
	int mes; // PRE: 1 <= mes <= 12
	int anio; // PRE: anio > 0

public:

	//Constructor sin argumentos.

	Fecha (void) {}


	//Setters

	void SetDia(int d) {

		dia = d;
	}

	void SetMes(int m) {

		mes = m;
	}

	void SetAnio(int a) {

		anio = a;
	}

	//Getters.

	int GetDia() {

		return dia;
	}

	int GetMes() {

		return mes;
	}

	int GetAnio() {

		return anio;
	}


	/*********************************************************************
	Metodo ToStringMes: obtiene el nombre de un mes a partir del numero que
	lo identifica.

	PRE: 1 <= mes <= 12
	*********************************************************************/

	string ToStringMes() {

		string nombre_mes;

		if (mes == 1) 	   nombre_mes = "Enero";
		else if (mes == 2) nombre_mes = "Febrero";
		else if (mes == 3) nombre_mes = "Marzo";
		else if (mes == 4) nombre_mes = "Abril";
		else if (mes == 5) nombre_mes = "Mayo";
		else if (mes == 6) nombre_mes = "Junio";
		else if (mes == 7) nombre_mes = "Julio";
		else if (mes == 8) nombre_mes = "Agosto";
		else if (mes == 9) nombre_mes = "Septiembre";
		else if (mes == 10) nombre_mes = "Octubre";
		else if (mes == 11) nombre_mes = "Noviembre";
		else if (mes == 12) nombre_mes = "Diciembre";

		return nombre_mes;
	}
};



/*---------------------------------------------------------------------------
								Clase Tiempo
---------------------------------------------------------------------------*/

class Tiempo {

private:

	int horas; // PRE:  0 <= horas < 24
	int minutos; // PRE: 0 <= minutos < 60
	int segundos; // PRE: 0 <= segundos < 60
	int milisegundos; // PRE: 0 <= milisegundos < 1000

public:


	//Constructor sin argumentos.

	Tiempo (void)
	{}


	//Setters.

	void SetHoras(int h) {

		horas = h;
	}

	void SetMinutos(int m) {

		minutos = m;
	}

	void SetSegundos(int s) {

		segundos = s;
	}

	void SetMilisegundos(int ms) {

		milisegundos = ms;
	}



	//Getters.

	int GetHoras() {

		return horas;
	}

	int GetMinutos() {

		return minutos;
	}

	int GetSegundos() {

		return segundos;
	}

	int GetMilisegundos() {

		return milisegundos;
	}


	/*********************************************************************
	Metodo TotalMilisegundos: clacula el tiempo total en milisegundos a
	partir de horas, minutos, segundos y milisegundos.

	PRE:
	0 <= horas < 24
	0 <= minutos < 60
	0 <= segundos < 60
	0 <= milisegundos < 1000
	*********************************************************************/

	int TotalMilisegundos() {

		const int MSH = 3600000, MSMIN = 60000, MSS = 1000;
		int milisegundos_totales;

		milisegundos_totales = (horas * MSH) + (minutos * MSMIN)
								+ (segundos * MSS) + milisegundos;

		return milisegundos_totales;
	}
};



/*---------------------------------------------------------------------------
							Clase RegistroDeMarca
---------------------------------------------------------------------------*/

class RegistroDeMarca {

private:

	string licencia_marca;
	string fecha_marca;
	string tiempo_marca;

	Fecha fecha_carrera;
	Tiempo tiempo_carrera;


public:

	//Constructor sin argumentos.

	RegistroDeMarca (void)
	{}


	//Setters.

	void SetLicenciaMarca(string licencia) {

		licencia_marca = licencia;
	}

	void SetFechaMarca(string fecha) {

		fecha_marca = fecha;

		fecha_carrera.SetDia(stoi(fecha_marca.substr(0,2)));
		fecha_carrera.SetMes(stoi(fecha_marca.substr(3,2)));
		fecha_carrera.SetAnio(stoi(fecha_marca.substr(6,4)));
	}

	void SetTiempoMarca(string tiempo) {

		tiempo_marca = tiempo;

		tiempo_carrera.SetHoras(stoi(tiempo_marca.substr(0,2)));
		tiempo_carrera.SetMinutos(stoi(tiempo_marca.substr(3,2)));
		tiempo_carrera.SetSegundos(stoi(tiempo_marca.substr(6,2)));
		tiempo_carrera.SetMilisegundos(stoi(tiempo_marca.substr(9,3)));
	}


	//Getters.

	int GetTiempoTotal() {

		int tiempo_total;

		tiempo_total = tiempo_carrera.TotalMilisegundos();

		return tiempo_total;
	}

	Fecha GetFechaCarrera() {

		return fecha_carrera;
	}

	string GetTiempoMarca() {

		return tiempo_marca;
	}

	string GetLicenciaMarca() {

		return licencia_marca;
	}

};




/*---------------------------------------------------------------------------
							Programa principal
---------------------------------------------------------------------------*/

int main() {

	//Declaraciones

	const int MAX_PRUEBAS = 20;
	const int MAX_MARCAS_EN_PRUEBA = 100;
	RegistroDeMarca marcas[MAX_PRUEBAS][MAX_MARCAS_EN_PRUEBA];

	// Numero de filas ocupadas de "marcas"
	// PRE: 0 <= num_pruebas < MAX_PRUEBAS
	int num_pruebas;

	// PRE: 0 <= num_marcas_en_prueba[i] < MAX_MARCAS_EN_PRUEBA
	int num_marcas_en_prueba[MAX_MARCAS_EN_PRUEBA];


	// Entrada de datos

	cout << "***********************************************" << endl << endl;

	cin >> num_pruebas;

	// Array que almacena nombre de pruebas
	string pruebas [MAX_PRUEBAS];

	for (int i = 0; i < num_pruebas; i++) {

		cin >> pruebas[i];
	}

	string prueba;
	string fecha;
	string tiempo;
	string licencia;

	cin >> prueba;


	while (prueba.substr(0,3) != "FIN") {

		bool encontrado = false;
		int pos_1 = 0;

		while (pos_1 < num_pruebas && !encontrado) {

			if (pruebas[pos_1] == prueba) {

				encontrado = true;
			}
			pos_1++;
		}

		int pos_2;

		if (encontrado) {

			pos_2 = pos_1 - 1;
		}

		cin >> fecha;

		marcas[pos_2][num_marcas_en_prueba[pos_2]].SetFechaMarca(fecha);

		cin >> licencia;

		marcas[pos_2][num_marcas_en_prueba[pos_2]].SetLicenciaMarca(licencia);

		cin >> tiempo;

		marcas[pos_2][num_marcas_en_prueba[pos_2]].SetTiempoMarca(tiempo);

		marcas[pos_2][num_marcas_en_prueba[pos_2]].GetTiempoTotal();

		num_marcas_en_prueba[pos_2]++;

		cin >> prueba;

	} //Mientras se introduzca una nueva marca.
	

	// Algoritmo de ordenacion de la marcas de cada prueba.

	for (int i = 0; i < num_pruebas; i++) {

		for (int izq = 0; izq < num_marcas_en_prueba[i]; izq++) {

			int minimo = marcas[i][izq].GetTiempoTotal();
			int pos_minimo = izq;

			for (int j = izq + 1; j < num_marcas_en_prueba[i]; j++) {

				if (marcas[i][j].GetTiempoTotal() < minimo) {

					minimo = marcas[i][j].GetTiempoTotal();
					pos_minimo = j;
				}
			}

			RegistroDeMarca intercambia = marcas[i][izq];
			marcas[i][izq] = marcas[i][pos_minimo];
			marcas[i][pos_minimo] = intercambia;
		}
	}


	// Salida de datos.

	cout << endl;
	cout << "Ranking general: " << endl;
	cout << endl;

	for (int i = 0; i < num_pruebas; i++) {

		cout << pruebas[i] << endl << endl;

		for (int z = 0; z < num_marcas_en_prueba[i]; z++){

			cout << " > " << z + 1  << "   " << setw(8)
				 << marcas[i][z].GetLicenciaMarca()
				 << setw(5)
				 << marcas[i][z].GetFechaCarrera().GetDia() << setw(5);

			cout << " " << setw(10)
				 << marcas[i][z].GetFechaCarrera().ToStringMes() << "  "
			 	 << marcas[i][z].GetFechaCarrera().GetAnio() << "   "
			 	 << marcas[i][z].GetTiempoMarca() << endl;
		}

		cout << endl;
	}

	cout << "***********************************************" << endl << endl;

	return 0;
}
