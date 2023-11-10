#ifndef ANAGRAMAS_H_INCLUDED
#define ANAGRAMAS_H_INCLUDED

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <list>

using namespace std;

class Anagramas {
	private:
		list<string> *A;
		int tam;
		void reestr();
		int nElementos;
	public:
		Anagramas();
		~Anagramas();
		unsigned long Hash(string palabra);
		bool consultar(string palabra);
		void insertar(string palabra);
		void vaciar(void);
		int numElem(void) { return nElem; }

		list<string> anagramas(string palabra);
};


#endif
