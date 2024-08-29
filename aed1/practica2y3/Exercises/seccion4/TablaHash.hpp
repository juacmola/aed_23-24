#ifndef __TABLA_HASH_H_INCLUDED
#define __TABLA_HASH_H_INCLUDED

#include <list>
#include <string>

using namespace std;

class TablaHash {
	private:
        	list<string> *T;
        	int B;
		void reestructurar();
        	int nElem;
	public:
        	TablaHash();
        	~TablaHash();
		unsigned long Hash(string palabra);
		unsigned long Hashana(string palabra);
		void insertar (string palabra);
		bool consultar (string palabra);
        	void vaciar (void);
		int numElem (void) { return nElem; }

		list<string> anagramas(string palabra);
};
#endif
