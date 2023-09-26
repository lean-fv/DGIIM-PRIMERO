/*
8. Escriba una funci´on ordenacionPorBurbuja() que reciba como entrada un array de n´umeros junto con
su longitud y que nos devuelva un array de punteros a los elementos del array de entrada de forma que
los elementos apuntados por dicho array de punteros est´en ordenados (v´ease la siguiente figura).
Debe usarse el algoritmo de ordenaci´on de la burbuja. Este algoritmo consiste en hacer una comparaci´on
entre cada dos elementos consecutivos desde un extremo del vector hasta el otro, de forma que el elemento
de ese extremo queda situado en su posici´on final. Una posible implementaci´on es la siguiente:

Note que el array de punteros debe ser un par´ametro de la funci´on, y estar reservado previamente a la
llamada con un tama˜no, al menos, igual al del array. Una vez escrita la funci´on, considere la siguiente
declaraci´on:
int vec [1000];
int *ptr [1000];
y escriba un trozo de c´odigo que, haciendo uso de la funci´on, permita:
(a) Ordenando punteros, mostrar los elementos del array, ordenados.
(b) Ordenando punteros, mostrar los elementos de la segunda mitad del array, ordenados.
sin modificar el array de datos vec.
*/

#include <iostream>
#include <string>
#include<cstdlib>
#include <ctime>

using namespace std;

void ordenacionBurbuja (int *vec[], int n) {
	for (int i=n-1; i>0; --i) {
		for (int j=0; j<i; ++j) {
			if (*vec[j] > *vec[j+1]) {
				int *aux = vec[j];
				vec[j] = vec[j+1];
				vec[j+1]= aux;
			}
		}
	}
}


int main(){

	const int TAM=10;
	int vec [TAM];
	int *ptr [TAM];
	srand(time(NULL));


	for (int i=0; i<TAM; i++){
		vec[i]= - 5 + rand() % (5 + 1 - (- 5));
		ptr[i]=&vec[i];
		//cout <<*ptr[i]<<" ";
	}

	ordenacionBurbuja(ptr,TAM);

	//A)
	cout << endl << "Verdadero array (no queda modificado): ";

	for (int i=0; i<TAM;i++)
		cout << vec[i] << " ";


	cout << endl << "Ordenado mediante punteros: ";

	for (int i=0; i<TAM;i++)
		cout << *ptr[i] << " ";

	//B)
	cout << endl << "Mitad ordenado: ";

	for (int i=TAM/2; i<TAM;i++)
		cout << *ptr[i] << " ";



	cout << endl << endl;

	return 0;
}
