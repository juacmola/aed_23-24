#include "diccionario.hpp"

#include <iostream>
#include <sstream>

#include <list>

using namespace std;

DicPalabras dic;

DicPalabras::DicPalabras () {
    contador= 0;
}

void DicPalabras::vaciar (void) {
    lista.clear();
    contador= 0;
}

void DicPalabras::inserta (string palabra){
    list<string>::iterator it = lista.begin(); //Creamos una lista y la iniciamos por el principio
    while (it!=lista.end() && *it<palabra){ //Recorremos la lista buscando la palabra
        it++;
    }
    if ((it==lista.end()) || (*it!=palabra)){ //Si no la encontramos la insertamos
        lista.insert(it, palabra);
        contador++;
    }
}

bool DicPalabras::consulta (string palabra){
    list<string>::iterator it = lista.begin(); //Creamos una lista y la iniciamos por el principio
    while (it!=lista.end() && *it<palabra){ //Recorremos la lista buscando la palabra
        it++;
    }
    if (*it==palabra){ //Si la encontramos devuelve true
        return true;
    }
    else{ //Si no la encontramos devuelve false
        return false;
    }
}


