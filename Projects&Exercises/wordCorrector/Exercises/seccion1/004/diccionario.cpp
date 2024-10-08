#include "diccionario.hpp"

#include <iostream>
#include <sstream>

#include <list>

using namespace std;

DicPalabras::DicPalabras () {
    contador= 0;
}

void DicPalabras::vaciar (void) {
    lista.clear();
    contador= 0;
}

void DicPalabras::insertar (string palabra){
    list<string>::iterator it = lista.begin(); //Creamos una lista y la inicializamos desde el inicio
    while (it!=lista.end() && *it<palabra){ //Recorremos la lista buscando la palabra
        it++;
    }
    if ((it==lista.end()) || (*it!=palabra)){ //Si no la encontramos, la insertamos
        lista.insert(it, palabra);
        contador++;
    }
}

bool DicPalabras::consultar (string palabra){
    list<string>::iterator it = lista.begin(); //Creamos una lista y la inicializamos desde el inicio
    while (it!=lista.end() && *it<palabra){ //Recorremos la lisa buscando la palabra
        it++;
    }
    if ((it!=lista.end()) && (*it==palabra)){ //Si la encontramos, devolvemos true
        return true;
    }
    else{ //Si no la encontramos, devolvemos false
        return false;
    }
}


