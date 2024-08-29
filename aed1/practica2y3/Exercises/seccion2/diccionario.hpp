#include "TablaHash.hpp"

#ifndef _DICCIONARIO_H_INCLUDED
#define _DICCIONARIO_H_INCLUDED

using namespace std;

class DicPalabras {
    private:
        TablaHash tabla;
    public:
        DicPalabras ();
        void vaciar () { tabla.vaciar(); }
        void insertar (string palabra) { tabla.insertar(palabra); }
        bool consultar (string palabra) { return tabla.consultar(palabra); }
        int numElem (void) { return tabla.numElem(); }

        list<string> anagramas(string palabra) { return tabla.anagramas(palabra); }
};
#endif
