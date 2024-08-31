#include "TablaHash.hpp"

#include <list>
#include <string>
#include <algorithm>
#include <unordered_map>

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
	B = 1000;
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

/*unsigned long TablaHash::Hash(string palabra){
	long base = 16777619;
	long resultado = 2166136261;

	for (char c : palabra) {
        resultado = (resultado ^ c) * base;
    }return resultado;
}*/

/*unsigned long TablaHash::Hash(string palabra){
	long resultado = 0;

	for (int i = 0; i < palabra.length(); i++){
		resultado = resultado + palabra[i];
	}return resultado;
}*/

/*unsigned long TablaHash::Hash(string palabra) {
    const unsigned int p = 131;  // un número primo para evitar colisiones
    unsigned long resultado = 0;

    for (char c : palabra) {
        resultado = resultado * p + c;
    }

    return resultado;
}*/

unsigned long TablaHash::Hash(string palabra){
    long resultado=3*(abs(int(palabra[0])));
    
    for (unsigned i=1;i<palabra.length();i++){
        resultado+= 3*(abs(int(palabra[i])));
    }
    resultado+=B;
    return resultado;
}

/*unsigned long TablaHash::Hash(string palabra){
    unsigned long hash = 5381;
    int c;

    while ((c = *palabra++))
        hash = ((hash << 5) + hash) + c; //hash * 33 + c

    return hash;
}*/

/*unsigned long TablaHash::Hash(string palabra) {
	int valor = 5381;
	for(unsigned i=0; i < palabra.length(); i++) {
		valor *= 33;
		valor ^= palabra[i];
	}
	return abs(valor);
}*/

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

/*list<string> TablaHash::anagramas(string palabra){
	unsigned long t = Hash(palabra);

	list<string>::iterator iter = T[t].begin();

	list<string> nuevaLista;

	string palabraOrdenada = palabra;
	sort(palabraOrdenada .begin(),palabraOrdenada .end());

	while(iter!=T[t].end()){
		string anag = *iter;
		sort(anag.begin(),anag.end());

		if(anag == palabraOrdenada )
            nuevaLista.push_back(*iter);

		iter++;
	}return nuevaLista;
}*/

list<string> TablaHash::anagramas(string palabra) {
    unsigned long t = Hash(palabra)%B;

    list<string>::iterator iter = T[t].begin();
    list<string> nuevaLista;

    unordered_map<char, int> frecuenciaPalabra;

    for (char c : palabra)
        frecuenciaPalabra[c]++;

    while (iter != T[t].end()) {
        unordered_map<char, int> frecuenciaAnagrama;
        bool esAnagrama = true;

        for (char c : *iter)
            frecuenciaAnagrama[c]++;

        for (auto &p : frecuenciaPalabra) {
            if (frecuenciaAnagrama[p.first] != p.second) {
                esAnagrama = false;
                break;
            }
        }

        if (esAnagrama)
            nuevaLista.push_back(*iter);

        iter++;
    }
    return nuevaLista;
}

