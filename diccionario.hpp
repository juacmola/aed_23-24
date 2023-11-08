#ifndef _DICCIONARIO_H_INCLUDED
#define _DICCIONARIO_H_INCLUDED

#include <list>

using namespace std;

class DicPalabras {
    private:
        list<string> lista;
        int contador;
        TablaHash tabla;
    public:
        DicPalabras ();
        void vaciar () { tabla.vaciar(); }
        void insertar (string palabra) { tabla.insertar(); }
        bool consultar (string palabra) { tabla.consultar(); }
        int numElem (void) { return tabla.numElem(); }
};
#endif
