/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS VII

6. Queremos disponer de una clase que nos permita trabajar con datos binarios
(la clase Bin) y realizar las operaciones básicas típicas sobre éstos.
Vamos a restringir el tamaño a un máximo de 32 bits y sólo consideraremos
valores positivos. Así, podremos operar con valores (decimales) entre 0 y 2
32−1 = 4294967295.

Investigue y vea que el tipo unsigned int requiere 4 bytes (32 bits) para su
almacenamiento y que el máximo valor que puede representarse es 4294967295
(consulte UINT_MAX en climits). Esto nos ayudará a adoptar un dato unsigned int
como campo privado de la clase. Es económico (4 bytes para cada valor a
representar) y disponemos de un amplio surtido de operaciones aritméticas que
pueden realizarse con datos unsigned int.

La clase Bin responderá al esquema dado en la figura 43. Los métodos se
comportan como se describe a continuación.
Nota: Escriba las precondiciones lógicas para cada caso.

• Constructores.

Bin (void);

Bin (unsigned int el_valor_inicial);

Bin (string el_valor_inicial);

Crean un objeto Bin y lo inicializan al valor dado. El constructor sin
argumentos inicializa el objeto con el valor 0.


• Métodos que modifican el objeto (set).

void SetValor (unsigned int el_valor);
void SetValor (string int el_valor);
Modifica el valor del dato binario sustituyéndolo por el_valor.

• Métodos de consulta (get).

int MinNumBits (void);
Devuelve cuántos bits se requieren para representar el valor.

unsigned int GetValorDecimal (void);
Devuelve el valor decimal del dato binario.

string ToString (int num_casillas);
Devuelve un string con el valor binario. El valor binario ocupa num_casillas.
En el caso de no precisar tantas casillas se rellenan con ceros a la izquierda.
Si se necesitan más casillas se usan las que se requieran para no perder
información. El valor binario obtenido siempre está delimitado por los
caracteres [ y ].

• Métodos de cálculo.

Bin Suma (Bin otro);

Bin Resta (Bin otro);

Bin AND (Bin otro);

Bin OR (Bin otro);

Realiza la operación indicada y devuelve un nuevo objeto con el resultado. Ni
el objeto implícito ni el explícito (otro) se modifican.

• Métodos de desplazamiento de bits.

Bin DespDcha (int veces);

Bin DespIzda (int veces);

Realiza la operación indicada (desplazamiento de los bits tantas casillas
como indique veces) y devuelve un nuevo objeto con el resultado. Los
“huecos” se rellenan con ceros. El objeto implícito no se modifica.

• Los métodos privados DecToBin y BinToDec son, básicamente, las funciones
desarrolladas en los ejercicios 38 y 39 de la Relación de Problemas III.

ENTRADA: Un numero decimal y uno binario, los bits a desplazar a la izquierda y
la derecha.
SALIDA: Los numeros en decimal y binario, su suma, resta, operaciones AND y OR y
el numero en binario desplazado.

*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;



/*---------------------------------------------------------------------------
									Clase Bin
---------------------------------------------------------------------------*/

class Bin{

private:

	unsigned int valor; //Pre: 0 <= valor < 4294967295



	/**************************************************************************
	Metodo DecToBin: Pasa de decimal a binario, ocupando como minimo las
	casillas  indicadas.
	**************************************************************************/

	string DecToBin (unsigned int num_decimal, int num_casillas){
		string binario;
		int resto;

		if(num_decimal == 0){
			binario = "0";
		}

		while(num_decimal > 0){
			resto = num_decimal%2;
			num_decimal = num_decimal/2;

			if(resto == 0){
				binario = "0"+ binario;
			}else{
				binario = "1" + binario;
			}
		}

		//Aniado ceros para completar el tamanio.
		int longitud = (int)binario.length();

		if(longitud < num_casillas){
			for(int i = longitud; i<num_casillas; i++)
			binario= "0" + binario;
		}

		return binario;
	}



	/**************************************************************************
	Metodo BinToDec: Pasa de binario a decimal.

	PRE: Cadena tiene que estar formada por 0 y 1.
	**************************************************************************/

	unsigned int BinToDec (string cad){

		unsigned int decimal = 0;
		double pot_2;
		double longitud_cadena = cad.length();
		double exponente=longitud_cadena - 1;

		for(int i = 0 ; i < longitud_cadena; i++){
			pot_2 = pow(2,exponente);

			if(cad.at(i) == '1'){
				decimal = decimal + pot_2;
			}
			exponente--;
		}

		return decimal;
	}



public:


	//Constructor sin argumentos
	Bin (void) : valor(0)
	{}

	//Constructores con argumentos.

	Bin (unsigned int el_valor_inicial){

		SetValor (el_valor_inicial);
	}

	Bin (string el_valor_inicial){

		SetValor(el_valor_inicial);
	}


	//Setters.

	void SetValor (unsigned int el_valor){

		valor = el_valor;
	}

	void SetValor (string el_valor){

		valor = BinToDec(el_valor);
	}


	//Getter.
	unsigned int GetValorDecimal (){
		return valor;
	}



	/**************************************************************************
	Metodo MinNumBits: devuelve cuantos bits se requieren para representar
	el valor.
	**************************************************************************/

	int MinNumBits (void){
		int num_bits = 0;
		unsigned int num_decimal = valor;

		if(num_decimal == 0){
			num_bits = 1;
		}

		while(num_decimal > 0){
			num_decimal = num_decimal/2;

			num_bits++;
		}
		return num_bits;
	}


	/**************************************************************************
	Metodo ToString: Devuelve el dato entero en forma de binario.
	**************************************************************************/

	string ToString (int num_casillas){

		string binario = "[" + DecToBin(valor, num_casillas) + "]";

		return binario;
	}



	/**************************************************************************
	Metodo Suma: se suman los dos valores.

	PRE: la suma de ambos no puede ser mayor a 2^{32}-1.
	**************************************************************************/

	Bin Suma (Bin otro){

		unsigned int suma = valor + otro.valor;

		return Bin(suma);
	}



	/**************************************************************************
	Metodo Resta: se restan los dos valores.

	Se debe restar mayor menos menor para poder devolver un dato unsigned int.
	**************************************************************************/

	Bin Resta (Bin otro){

		unsigned int mayor, menor;

		if(valor > otro.valor){
			mayor = valor;
			menor = otro.valor;
		}else{
			mayor = otro.valor;
			menor = valor;
		}

		unsigned int resta = mayor - menor;

		return Bin(resta);
	}


	/**************************************************************************
	Metodo AND:

	1 and 1 = 1
	1 and 0 = 0
	0 and 0 = 0
	**************************************************************************/

	Bin AND (Bin otro){

		return Bin(valor & otro.valor);
	}
	/**************************************************************************
	Metodo OR:

	1 or 1 = 1
	1 or 0 = 1
	0 or 0 = 0
	**************************************************************************/

	Bin OR (Bin otro){
		return Bin(valor | otro.valor);
	}



	/**************************************************************************
	Metodo DespDcha: Desplaza el numero n bits a la derecha.

	PRE: resultado <= 2^{32}-1
	**************************************************************************/

	Bin DespDcha (int veces){
		return Bin(valor >> veces);
	}



	/**************************************************************************
	Metodo DespIzda: Desplaza el numero n bits a la inzquierda.

	PRE: resultado <= 2^{32}-1
	**************************************************************************/

	Bin DespIzda (int veces){
		return Bin(valor << veces);
	}

};




/**************************************************************************
Funcion EsBinario: Indica si una cadena introducida es un dato binario o no.
**************************************************************************/

bool EsBinario(string cadena){
	bool es_binario=true;

	int pos=0;
	int longitud=cadena.length();

	while(es_binario && pos < longitud){
		if(cadena.at(pos)!= '0' && cadena.at(pos) != '1')
			es_binario = false;

		pos++;
	}

	return es_binario;
}



/*---------------------------------------------------------------------------
							Programa principal
---------------------------------------------------------------------------*/
int main(){

	unsigned int numero_decimal;

	//Entrada de datos.

	cout << "***********************************************" << endl << endl;

	cout << "Introduce un numero entero: ";
	cin >> numero_decimal;

	Bin binario1(numero_decimal);

	string binario;

	do{
		cout << "Introduce un numero binario: ";
		cin >> binario;

	}while(!EsBinario(binario));


	Bin binario2(binario);


	int dcha;
	do{
		cout << "Bits a desplazar hacia la derecha el dato 1: ";
		cin >> dcha;
	}while(dcha<0);


	int izda;
	do{
		cout << "Bits a desplazar hacia la izquierda el dato 1: ";
		cin >> izda;
	}while(izda<0);


	//Calculos

	Bin suma(binario1.Suma(binario2));
	Bin resta(binario1.Resta(binario2));

	Bin And(binario1.AND(binario2));
	Bin Or(binario1.OR(binario2));

	Bin desp_dcha(binario1.DespDcha(dcha));
	Bin desp_izda(binario1.DespIzda(izda));

	//Salida de datos

	const int BITS = 16;

	cout << endl;

	cout << "El primer dato es el " << binario1.GetValorDecimal()
		 << " en decimal y " << binario1.ToString(BITS) << " en binario";
		 cout << endl << endl;

	cout << "El segundo dato es el " << binario2.GetValorDecimal()
		 << " en decimal y " << binario2.ToString(BITS) << " en binario";
		 cout << endl << endl;

	cout << "La suma de ambos es " << suma.GetValorDecimal() << " , "
		 << suma.ToString(BITS) << " en binario" << endl << endl;

	cout << "La diferencia de ambos es " << resta.GetValorDecimal() << " , "
		 << resta.ToString(BITS) << " en binario" << endl << endl;

	cout << "La operacion AND de ambos es " << And.ToString(BITS)
		 << " en binario" << endl << endl;

	cout << "La operacion OR de ambos es " << Or.ToString(BITS)
		 << " en binario" << endl << endl;

	cout << "El primer dato desplazado a la derecha " << dcha << " bits es "
		 << desp_dcha.ToString(BITS) << endl << endl;

	cout << "El primer dato desplazado a la izquierda " << izda << " bits es "
		 << desp_izda.ToString(BITS) << endl << endl;

	cout << "***********************************************" << endl << endl;


	return 0;
}
