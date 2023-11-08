#include "TablaHash.hpp"

void TablaHash::reestructurar(){
	unsigned long t;

	int tamprevio = tam;
	tam = tam*2;
	list<string> *nuevaLista = new list<string>[tam];

	for(int i = 0; i<tamprevio; i++){
		list<string>::iterator iter = tablaH[i].begin();

		while(iter!=tablaH[i].end()){
			string palabra = *iter;
			t = Hash(palabra)%tam;
			list<string>::iterator nuevoIter = nuevaLista[t].begin();

            while (nuevoIter!=nuevaLista[t].end() && *nuevoIter<palabra) nuevoIter++;

                if (nuevoIter==nuevaLista[t].end() || *nuevoIter!=palabra){
                    nuevaLista[t].insert(nuevoIter, palabra);
                }iter++;
		}
	}
	delete[] tablaH;
	tablaH = nuevaLista;
}

TablaHash::TablaHash(){
	tam = 500;
	tablaH = new list<string>[tam];

	nElementos = 0;
}

void TablaHash::vacia(void){
   for(unsigned int i=0; i < tam; i++) {
        tablaH[i].clear();
   }
   nElementos = 0;
}

TablaHash::~TablaHash(){
	delete[] tablaH;
}

unsigned long TablaHash::Hash(string palabra){
	long base = 16777619;
	long resultado = 2166136261;

	for (int i = 0; i < palabra.length(); i++){
		resultado = resultado * base;
		resultado = resultado ^ palabra[i];
	}return resultado;
}

bool TablaHash::consulta(string palabra){
    unsigned long t = Hash(palabra)%tam;
    list<string>::iterator iter = tablaH[t].begin();

    while(iter!=tablaH[t].end() && (*iter<palabra)) iter++;

    if(iter==tablaH[t].end() || *iter!=palabra ) return false;

    return true;
}

void TablaHash::inserta(string palabra){
    unsigned long t = Hash(palabra)%tam;
    list<string>::iterator iter = tablaH[t].begin();

    while (iter!=tablaH[t].end() && *iter<palabra) iter++;

    if (iter==tablaH[t].end() || *iter!=palabra){
        nElementos++;
        tablaH[t].insert(iter, palabra);
    }
    if(nElementos > 2*tam) reestr();
}
