#include <iostream>
#include "fstream"

using namespace std;

int main(){
	
	ifstream file ;
	
	file.open("./mickey/mickey.txt") ; //fichero de geogebra (editado)
	
	int utilizados;
	 
	file >> utilizados;
	string etiqueta;
	string Util[1000];
	
	for (int i = 0; i < utilizados; i++){
		file >> etiqueta ; 		
		file >> etiqueta ; 
		file >> Util[i];
		file >> etiqueta ;		
		file >> etiqueta ;
		file >> etiqueta ;		
		file >> etiqueta ;
		file >> etiqueta ;		
		file >> etiqueta ;
	}
	
	ofstream h,j;
	
	h.open("./mickey/mickey_x.txt"); // array de las x
	j.open("./mickey/mickey_y.txt"); // array de las y
	
	for (int i = 0; i < utilizados; i++){
		
		int x = 1;
		string salida = "";
		
		while(Util[i].at(x) != ','){
			
			salida = salida + Util[i].at(x);
			x++;
			
			  
		}
		
		h << salida; 
		h << ",";
		
		int n = Util[i].length() ;
		
		string otro = "" ;
		
		for (int k = x + 1; k < n-1 ; k++ ){
			otro = otro + Util[i].at(k) ;  
		}
		
		j << otro ;
		j << "," ;
	}
	
	file.close();
	h.close();
	j.close();
	
	return 0;
	
}
