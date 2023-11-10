#include "Anagramas.h"

void Anagramas::reestr(){
	unsigned long t;

	int tamprevio = tam;
	tam = tam*2;
	list<string> *nuevaLista = new list<string>[tam];

	for(int i = 0; i<tamprevio; i++){
		list<string>::iterator iter = A[i].begin();

		while(iter!=A[i].end()){
			string palabra = *iter;
			t = Hash(palabra)%tam;
			list<string>::iterator nuevoIter = nuevaLista[t].begin();

            while (nuevoIter!=nuevaLista[t].end() && *nuevoIter<palabra) nuevoIter++;

                if (nuevoIter==nuevaLista[t].end() || *nuevoIter!=palabra){
                    nuevaLista[t].insert(nuevoIter, palabra);
                }iter++;
		}
	}
	delete[] A;
	A = nuevaLista;
}

Anagramas::Anagramas(){
	tam = 500;
	A = new list<string>[tam];

	nElem = 0;
}

void Anagramas::vacia(void){
   for(unsigned int i=0; i < tam; i++) {
        A[i].clear();
   }
   nElem = 0;
}

Anagramas::~Anagramas(){
	delete[] A;
}

list<string> Anagramas::anagramas(string palabra){
	unsigned long t = Hash(palabra) % tam;

	list<string>::iterator iter = A[t].begin();

	list<string> nuevaLista;

	while(iter!=A[t].end()){
		string palabra2 = palabra;
		sort(palabra2.begin(),palabra2.end());

		string anag = *iter;
		sort(anag.begin(),anag.end());

		if(anag == palabra2)
            nuevaLista.push_back(*iter);

		iter++;
	}return nuevaLista;
}

unsigned long Anagramas::Hash(string palabra){
	long resultado = 0;

	for (int i = 0; i < palabra.length(); i++){
		resultado = resultado + palabra[i];
	}return resultado;
}

bool Anagramas::consultar(string palabra){
    unsigned long t = Hash(palabra)%tam;
    list<string>::iterator iter = tablaA[t].begin();

    while(iter!=A[t].end() && (*iter<palabra)) iter++;

    if(iter==A[t].end() || *iter!=palabra ) return false;

    return true;
}

void Anagramas::insertar(string palabra){
    unsigned long t = Hash(palabra)%tam;
    list<string>::iterator iter = A[t].begin();

    while (iter!=A[t].end() && *iter<palabra) iter++;

    if (iter==A[t].end() || *iter!=palabra){
        nElem++;
        A[t].insert(iter, palabra);
    }
    if(nElem > 2*tam) reestr();
}

