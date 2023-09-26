/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS VI

25. (Basado en el Examen Ordinario 2019) Implementar una clase RedSocial para
gestionar una red social. La red debe almacenar los nombres de los usuarios y
las relaciones de amistad. Se propone la siguiente representación:

class RedSocial {
private:
static const int MAXIMO_USUARIOS = 100;
string usuarios[MAXIMO_USUARIOS];
bool relaciones_amistad[MAXIMO_USUARIOS][MAXIMO_USUARIOS];
int usuarios_utiles;
public:
...
};


donde relaciones_amistad es una matriz binaria tal que la componente (i, j) es
true, si el usuario i es amigo del usuario j, y false, en otro caso. Asumiremos
que las relaciones de amistad son simétricas, por lo que la matriz binaria
también lo es.

Se pide implementar, al menos, los siguientes métodos básicos (los usuarios
vienen especificados por sus nombres):

• RedSocial (void);
Constructor sin argumentos. Crea una red vacía.

• int NumUsuarios (void)
Devuelve el número de ususrios de la red.

• void AniadeUsuario (string usr)
Añade el usuario usr a la red (no tiene amigos).

• void EliminaUsuario (string usr)
Elimina el usuario usr de la red.

• bool Existe (string usr)
Informa si usr es un usuario de la red.

• void HacerAmigos(string usr1, string usr2);
Registra una relación de amistad entre usr1 y usr2

• void DeshacerAmigos(string usr1, string usr2);
Elimina una relación de amistad entre usr1 y usr2

• bool SonAmigos(string usr1, string usr2);
Informa si hay relación de amistad entre usr1 y usr2


Escriba un programa que cree una red y lea los nombres de los usuarios de la red
(termina cuando se introduce FIN en el primer nombre). Después lee una serie de
lineas que contienen parejas de nombres que indican las relaciones de amistad y
va actualizando las relaciones de amistad en la red.

Queremos ampliar la funcionalidad de la red con:

a) Un método que, dado un usuario A de la red, sugiera un amigo potencial para
A. Un amigo potencial es aquel usuario de la red (no amigo de A) que tiene más
amigos en común con A.

Escriba en la función main código para que solicite el nombre de un usuario y
sugiera una relación de amistad par él.

b) Un método que decida si dos usuarios son amigos circunstanciales, es decir,
si son amigos pero no tienen amigos en común.

Escriba en la función main código para que muestre todos los amigos
circunstanciales presentes en la red.

Implemente cualquier otro método adicional, público o privado, que considere
útil. Use cualquier clase adicional que le resulte útil.
Ampliación: Use un menú para gestionar la red social.

ENTRADA: Cada una de las opciones del menu.
SALIDA: adiciones de usuarios, eliminaciones, adicion y eliminacion de
amistades, existencia de usuario, sugerencia y comprobacion de amistad.

*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

/*---------------------------------------------------------------------------
									Clase RedSocial
---------------------------------------------------------------------------*/

class RedSocial {

private:

	static const int MAXIMO_USUARIOS = 100;
	string usuarios[MAXIMO_USUARIOS];
	bool relaciones_amistad[MAXIMO_USUARIOS][MAXIMO_USUARIOS];
	int usuarios_utiles;


	/*************************************************************************
	Metodo PosicionUsuarioBuscado:

	Indica la posicion del usuario buscado dentro del vector.

	PRE: usr existe.
	*************************************************************************/

	int PosicionUsuarioBuscado(string usr){
		int i = 0;
		int pos_encontrado = -1;
		bool encontrado=false;

		while (i < usuarios_utiles && !encontrado){
			if (usuarios[i] == usr){
				encontrado = true;
				pos_encontrado = i;
			}
			else i++;
		}

		return pos_encontrado;
	}



public:

	//Constructor sin argumentos, crea una red vacia
	RedSocial(void):usuarios_utiles(0) {

		//Inicializo toda la matriz de amistades a false.
		for(int f=0; f<MAXIMO_USUARIOS; f++){
			for(int c=0; f<MAXIMO_USUARIOS; f++){
				relaciones_amistad[f][c]=false;
			}
		}
	}

	//Getter.
	int NumUsuarios(){
		return usuarios_utiles;
	}


	/*************************************************************************
	Metodo Aniade un usuario a la red: añade un usuario al vector de usuarios.
	*************************************************************************/
	void AniadeUsuario (string usr){
		if(!Existe(usr)){
			usuarios[usuarios_utiles]=usr;
			usuarios_utiles++;
		}
	}

	/*************************************************************************
	Metodo EliminaUsuario:

	Elimina un usuario de la red, y sus amistades

	PRE: usr debe existir.
	*************************************************************************/
	void EliminaUsuario (string usr){
		int i = 0;
		int pos_encontrado = -1;
		bool encontrado=false;

		while (i < usuarios_utiles && !encontrado){

			if (usuarios[i] == usr){
				encontrado = true;
				pos_encontrado = i;
			}
			else i++;
		}

		if(encontrado){
			int tope = usuarios_utiles-1;
			for (int i = pos_encontrado ; i < tope ; i++){
				usuarios[i] = usuarios[i+1];

				//Borro tambien las amistades.
				for(int j=pos_encontrado; j< tope; j++){
					relaciones_amistad[i][j]=relaciones_amistad[i+1][j];
					relaciones_amistad[j][i]=relaciones_amistad[j][i+1];
				}
			}

			usuarios_utiles--;
		}
	}

	/*************************************************************************
	Metodo Existe: indica si un usuario existe en la red.
	*************************************************************************/

	bool Existe (string usr){
		int i = 0;
		bool encontrado=false;

		while (i < usuarios_utiles && !encontrado){
			if (usuarios[i] == usr){
				encontrado = true;
			}
			else i++;
		}

		return encontrado;
	}



	/*************************************************************************
	Metodo HacerAmigos: pone true en la interseccion de las casillas de esos
	usuarios en la matriz de amistades.

	PRE: usr1 y usr2 deben existir y ser distintos.
	*************************************************************************/

	void HacerAmigos(string usr1, string usr2){
		if(Existe(usr1) && Existe(usr2) && usr1!=usr2){
			int pos_usr1 = PosicionUsuarioBuscado(usr1);
			int pos_usr2 = PosicionUsuarioBuscado(usr2);

			relaciones_amistad[pos_usr1][pos_usr2] = true;
			relaciones_amistad[pos_usr2][pos_usr1] = true;
		}
	}


	/*************************************************************************
	Metodo HacerAmigos: pone false en la interseccion de las casillas de esos
	usuarios en la matriz de amistades.

	PRE: usr1 y usr2 deben existir y ser distintos.
	*************************************************************************/

	void DeshacerAmigos(string usr1, string usr2){
		if(Existe(usr1) && Existe(usr2)){
			int pos_usr1=PosicionUsuarioBuscado(usr1);
			int pos_usr2=PosicionUsuarioBuscado(usr2);

			relaciones_amistad[pos_usr1][pos_usr2]=false;
			relaciones_amistad[pos_usr2][pos_usr1]=false;
		}

	}

	/*************************************************************************
	Metodo SonAmigos: indica si dos usuarios son amigos.
	PRE: usr1 y usr2 deben existir y ser distintos.
	*************************************************************************/

	bool SonAmigos(string usr1, string usr2){
		int pos_usr1 = PosicionUsuarioBuscado(usr1);
		int pos_usr2 = PosicionUsuarioBuscado(usr2);

		return relaciones_amistad[pos_usr1][pos_usr2];

	}

	/*************************************************************************
	Metodo SugerenciaAmigoPotencialDe: Dado un usuario A de la red, sugiera un
	amigo potencial para A, que es aquel usuario de la red (no amigo de A) que
	tiene mas amigos en comun con A.

	PRE: usr debe existir y haber un cierto numero de usuarios.
	POST: amigo_potencial existe.
	*************************************************************************/
	string SugerenciaAmigoPotencialDe(string usr){

		int pos_usr = PosicionUsuarioBuscado(usr);
		int max_amigos_comun=0;
		int pos_amigo_potencial=0;

		/*Va recorriendo todos los usuarios y comparando los amigos en
		comun con usr */
		for(int u = 0; u < usuarios_utiles; u++){
			int amigos_comun = 0;

			if(usr!=usuarios[u] && !SonAmigos(usr, usuarios[u])){
				for(int i = 0 ; i < usuarios_utiles; i++){
					if(relaciones_amistad[pos_usr][i] &&
						relaciones_amistad[u][i]){

						amigos_comun++;
					}
				}
				if(amigos_comun > max_amigos_comun){
					max_amigos_comun = amigos_comun;
					pos_amigo_potencial = u;
				}
			}
		}

		string amigo_potencial = usuarios[pos_amigo_potencial];

		return amigo_potencial;
	}

	/*************************************************************************
	Metodo AmigosCircunstanciales: indica si son amigos pero no tienen amigos
	en comun.

	PRE: usr1, usr2 debe existir y ser distintos.
	*************************************************************************/
	bool AmigosCircunstanciales(string usr1, string usr2){

		bool son_amigos_circunstanciales=true;

		int pos_usr1=PosicionUsuarioBuscado(usr1);
		int pos_usr2=PosicionUsuarioBuscado(usr2);

		if(SonAmigos(usr1, usr2)){
			int i=0;

			while(i<usuarios_utiles && son_amigos_circunstanciales){
				if(relaciones_amistad[pos_usr1][i] &&
					relaciones_amistad[pos_usr2][i]){
					son_amigos_circunstanciales=false;
				}
				i++;
			}
		}

		else{
			son_amigos_circunstanciales=false;
		}

		return son_amigos_circunstanciales;
	}

};


/*---------------------------------------------------------------------------
							Programa principal
---------------------------------------------------------------------------*/


int main(){

	//Declaraciones.

	cout.setf (ios :: showpoint);
	cout.setf (ios :: fixed);

	const string FIN = "FIN";
	RedSocial red;
	bool seguir = true;

	cout << "***********************************************" << endl << endl;

	//Menu.

	while(seguir){

		int opcion;

		cout << endl;
		cout << setw (12) << "MENU" << endl << endl;
		cout << "1. Aniadir usuario" << endl;
		cout << "2. Eliminar usuario" << endl;
		cout << "3. Aniadir amistad" << endl;
		cout << "4. Eliminar amistad" << endl;
		cout << "5. Busqueda de usuario" << endl;
		cout << "6. Sugerencia de amistad" << endl;
		cout << "7. Comprobacion de amistad" << endl;
		cout << "8. SALIR" << endl << endl;

		do{ //Filtro
			//cout << "Opcion: ";
			cin >> opcion;
		}while(opcion < 1 || opcion > 8);


		//Opciones del menu.
		switch (opcion){

			case 1:{ //Aniadir usr

				string usr;
				cout << endl;
				//cout << "Introduzca un usuario:";
				cin >> usr;

				while (usr != FIN){

					red.AniadeUsuario(usr);

					//cout << "Introduzca un usuario:";
					cin >> usr;

				} //Lectura anticipada

				break;
			} // Case 1


			case 2:{ //Eliminar usr

				string usr_eliminar;
				cout << endl;
				//cout << "Introduzca un usuario a eliminar:";
				cin >> usr_eliminar;

				while (usr_eliminar != FIN){

					if (red.Existe (usr_eliminar)){

						red.EliminaUsuario(usr_eliminar);
						cout << "Se ha eliminado el usuario " << usr_eliminar;
						cout << endl << endl;

					} //Si existe

					else cout << "No existe el usuario." << endl << endl;


					//cout << "Introduzca un usuario a eliminar:";
					cin >> usr_eliminar;

				} //Lectura anticipada

				break;
			} // Case 2


			case 3:{ //Aniadir amistad

				string usr_amigo1, usr_amigo2;
				cout << endl;
				//cout << "Introduzca un usuario:";
				cin >> usr_amigo1;

				while(usr_amigo1 != FIN){

					do{
						//cout << "Introduzca otro usuario:";
						cin >> usr_amigo2;
					}while(usr_amigo1==usr_amigo2);

					if(red.Existe(usr_amigo1) && red.Existe(usr_amigo2)){

						red.HacerAmigos(usr_amigo1, usr_amigo2);
						cout << endl;
						cout << "Ahora " << usr_amigo1 << " y " << usr_amigo2
							 << " son amigos." << endl << endl;

					} //Si existen los dos

					else if(!red.Existe(usr_amigo1)){
						cout << endl;
						cout << usr_amigo1 << " no existe." << endl << endl;

					}else if(!red.Existe(usr_amigo2)){
						cout << endl;
						cout << usr_amigo2 << " no existe." << endl << endl;
					}
					//Si no existe alguno.

					//cout << "Introduzca un usuario:";
					cin >> usr_amigo1;

				} //Lectura anticipada

				break;
			} // Case 3


			case 4:{ //Eliminar amistad

				string usr_enemigo1, usr_enemigo2;

				cout << endl;
				//cout << "Introduzca un usuario:";
				cin >> usr_enemigo1;

				while (usr_enemigo1 != FIN){

					do{ //Filtro
						cout << endl;
						//cout << "Introduzca otro usuario:";
						cin >> usr_enemigo2;
					}while(usr_enemigo1 == usr_enemigo2);

					if(red.Existe(usr_enemigo1) && red.Existe(usr_enemigo2)){
						red.DeshacerAmigos(usr_enemigo1, usr_enemigo2);
						cout << endl;
						cout << "Ahora " << usr_enemigo1<< " y " << usr_enemigo2
							 << " no son amigos" << endl << endl;

					} //Si existen los dos

					else {

						if(!red.Existe(usr_enemigo1)){
							cout << endl;
							cout << usr_enemigo1 << " no existe."<< endl<< endl;
						}

					 	if(!red.Existe(usr_enemigo2)){
							cout << endl;
							cout << usr_enemigo2 << " no existe"<< endl << endl;
						}


					} //Si no existe alguno

					//cout << "Introduzca un usuario:";
					cin >> usr_enemigo1;

				} //Lectura anticipada

				break;
			} // Case 4


			case 5:{ //Ver si existe

				string usr_existe;
				cout << endl;
				//cout << "Introduzca un usuario:";
				cin >> usr_existe;

				while (usr_existe != FIN){

					if(red.Existe(usr_existe)){
						cout << endl;
						cout << usr_existe << " existe" << endl;
					}

					else{
						cout << endl;
						cout << usr_existe << " no existe" << endl;
					}

					//cout << "Introduzca un usuario:";
					cin >> usr_existe;
				} //Lectura anticipada

				break;
			} // Case 5


			case 6:{ //Sugerencia amigo potencial

				string usr_potencial;

				cout << endl;
				//cout << "Introduzca un usuario:";
				cin >> usr_potencial;

				while (usr_potencial != FIN){

					if(red.Existe(usr_potencial)){
						string amigo_potencial=
						red.SugerenciaAmigoPotencialDe(usr_potencial);

						cout << endl;
						cout << "Un amigo potencial de " << usr_potencial
							 << " es el usuario " << amigo_potencial;
						cout << endl << endl;
					}
					else{
						cout << endl;
						cout << usr_potencial << " no existe. " << endl;
					}

					//cout << "Introduzca un usuario:";
					cin >> usr_potencial;
				} //Lectura anticipada

				break;
			} //Case 6


			case 7:{ //Comprobar amistad

				string usr1_amistad, usr2_amistad;

				cout << endl;
				//cout << "Introduzca un usuario: ";
				cin >> usr1_amistad;

				while (usr1_amistad != FIN){

					do{
						//cout << "Introduzca otro usuario: ";
						cin >> usr2_amistad;
					}while(usr1_amistad==usr2_amistad);

					if (red.Existe(usr1_amistad) && red.Existe(usr2_amistad)){

						if(red.AmigosCircunstanciales(usr1_amistad,
							usr2_amistad)){

							cout << endl;
							cout << usr1_amistad << " y " << usr2_amistad
								 << " son amigos pero no tienen"
								 << " amigos en comun" << endl;

						}else if(red.SonAmigos(usr1_amistad, usr2_amistad)
						&& !red.AmigosCircunstanciales(usr1_amistad,
							usr2_amistad)){

							cout << endl;
							cout << usr1_amistad << " y " << usr2_amistad
								 << " son amigos y tienen amigos en comun";
								 cout << endl;

						}
						else{
							cout << endl;
							cout << usr1_amistad << " y " << usr2_amistad
							<< " no son amigos" << endl;
						}

					} //Si existen ambos usuarios.

					else{

						if (!red.Existe(usr1_amistad)){
							cout << usr1_amistad << " no existe." << endl;
						}

						if (!red.Existe(usr2_amistad)){
							cout << usr2_amistad << " no existe." << endl;
						}
					}

					//cout << "Introduzca un usuario: ";
					cin >> usr1_amistad;

				} //Lectura anticipada.

				break;
			} // Case 7


			default:{ //Salir

				seguir=false;

				break;
			}


		} //Switch (opcion)

	} //Seguir

	cout << endl << endl;
	cout << "Ha salido." << endl;

	cout << "***********************************************" << endl << endl;


	return 0;
}
