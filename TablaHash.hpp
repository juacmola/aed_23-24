
#ifndef __TABLA_HASH_H_INCLUDED
#define __TABLA_HASH_H_INCLUDED

#include <string>

class TablaHash {
	private:
    list<string> *T;
    int B;
		void reestructurar();
    int nElem;
	public:
	  TablaHash();
		~TablaHash();
		void insertar (string palabra);
		bool consultar (string palabra);
    void vaciar (void);
		int numElem (void) { return nElem; }
};
#endif
