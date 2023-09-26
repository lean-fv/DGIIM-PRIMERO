/*
7. Implemente las siguientes funciones sobre cadenas de caracteres estilo C
usando aritm´etica de punteros (sin usar el operador []):

(a) Funci´on compararCadenas que compara dos cadenas. Devuelve un valor negativo
si la primera es mas pequena, positivo si es mas grande y cero si son iguales.

(b) Funci´on insertarCadena que inserte una cadena dentro de otra, en una
posici´on dada.
Se supone que hay suficiente memoria en la cadena de destino.
Se supone que no es necesario pasar el tama˜no de las cadenas (recordad que el
car´acter nulo delimita el final de la cadena).
*/

#include <iostream>
#include <cstring>

using namespace std;

void insertarCadena(const char* origen, char* destino, int pos){

	int long_origen=strlen(origen);
	for (int i=long_origen; i>=0; i--){

		*(destino+pos+i)= *(destino+pos);
		*(destino+pos)= *(origen+i);
	}
}


int main(){

	const int TAM=100;
	char cad1[TAM], cad2[TAM];
	int pos;

	//A)

	cout <<"Introduzca la primera cadena: ";
	cin.getline(cad1,TAM);

	cout <<"Introduzca la segunda cadena: ";
	cin.getline(cad2,TAM);

	cout << "Introduzca la posicion donde insertar la primera cadena: ";
	cin >> pos;

	cout << endl;

	if (!strcmp(cad1,cad2)) cout <<"Son iguales." << endl;
	else if (strcmp(cad1,cad2)<0)
		cout<<"La primera es menor que la segunda"<<endl;
	else if (strcmp(cad1,cad2)>0)
		cout << "La primera es mayor que la segunda" << endl;

	//B)
	insertarCadena(cad1,cad2,pos);

	cout << "Cadena final: " << cad2 << endl;


	return 0;
}
