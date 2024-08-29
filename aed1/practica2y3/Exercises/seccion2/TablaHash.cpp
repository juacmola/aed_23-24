
#include "TablaHash.hpp"

#include <list>
#include <string>
#include <algorithm>

using namespace std;

void TablaHash::reestructurar(){
	unsigned long t;

	int tamprevio = B;
	B = B*2;
	list<string> *nuevaLista = new list<string>[B];

	for(int i = 0; i<tamprevio; i++){
		list<string>::iterator iter = T[i].begin();

		while(iter!=T[i].end()){
			string palabra = *iter;
			t = Hash(palabra)%B;
			list<string>::iterator nuevoIter = nuevaLista[t].begin();

				while (nuevoIter!=nuevaLista[t].end() && *nuevoIter<palabra) nuevoIter++;

						if (nuevoIter==nuevaLista[t].end() || *nuevoIter!=palabra){
								nuevaLista[t].insert(nuevoIter, palabra);
						}iter++;
		}
	}
	delete[] T;
	T = nuevaLista;
}

TablaHash::TablaHash(){
	B = 500;
	T = new list<string>[B];

	nElem = 0;
}

TablaHash::~TablaHash(){
	delete[] T;
}

void TablaHash::vaciar(void){
   for(unsigned int i=0; i < B; i++) {
        T[i].clear();
   }
   nElem = 0;
}

unsigned long TablaHash::Hash(string palabra){
	long resultado = 0;

	for (int i = 0; i < palabra.length(); i++){
		resultado = resultado + palabra[i];
	}return resultado;
}

bool TablaHash::consultar (string palabra){
    unsigned long t = Hash(palabra)%B;
    list<string>::iterator iter = T[t].begin();

    while(iter!=T[t].end() && (*iter<palabra)) iter++;

    if(iter==T[t].end() || *iter!=palabra ) return false;

    return true;
}

void TablaHash::insertar (string palabra){
    unsigned long t = Hash(palabra)%B;
    list<string>::iterator iter = T[t].begin();

    while (iter!=T[t].end() && *iter<palabra) iter++;

    if (iter==T[t].end() || *iter!=palabra){
        nElem++;
        T[t].insert(iter, palabra);
    }
    if(nElem > 2*B) reestructurar();
}

list<string> TablaHash::anagramas(string palabra){
	unsigned long t = Hash(palabra) % B;

	list<string>::iterator iter = T[t].begin();

	list<string> nuevaLista;

	while(iter!=T[t].end()){
		string palabra2 = palabra;
		sort(palabra2.begin(),palabra2.end());

		string anag = *iter;
		sort(anag.begin(),anag.end());

		if(anag == palabra2)
            nuevaLista.push_back(*iter);

		iter++;
	}return nuevaLista;
}
