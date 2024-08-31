#include "arbol.hpp"

#include <iostream>

using namespace std;

ArbolPalabras::ArbolPalabras() {
	raiz = new NodoArbol();     //Crea un nodo nodo denominado raiz, está vacío
}

ArbolPalabras::~ArbolPalabras() {
	delete raiz;                //Borra raíz, y por tanto el árbol
}

void ArbolPalabras::insertar(string palabra) {
	NodoArbol* nodo = raiz;
	for(int i = 0; i<palabra.length();i++) {
		if (nodo->consulta(char(palabra[i]))==NULL) nodo->inserta(char(palabra[i]));
        	nodo=nodo->consulta(char(palabra[i]));
	}
    if (!nodo->HayMarca()){
        nodo->PonMarca();
        nElem++;
    }
}

void ArbolPalabras::vaciar() {
	delete raiz;                //Vacía el árbol actual borrando la raíz de este
	nElem=0;                    //El número de palabras del árbol vuelve a ser 0
	raiz = new NodoArbol();     //Ahora, se genera un nuevo árbol vacío
}

void ArbolPalabras::alargar(string prefijo){
    NodoArbol* nodo = raiz;                     //Nos situamos en la raiz
    string palcompleta="";                      //Esto será lo que imprimamos
    
    for(int i = 0; i<prefijo.length();i++) {    //Recorremos el prefijo
        if (nodo->consulta(prefijo[i])==NULL){  //Si el caracter no está en el árbol:
            cout << "" << endl;                 // devuelve vacío, no se puede alargar
            return;                              //Nos salimos, ya que ha impreso
        }
        else{
            nodo = nodo->consulta(prefijo[i]);  //Nos situamos en el lugar donde está el caracter
            palcompleta+=prefijo[i];            //Añadimos el caracter a la palabra a imprimir
        }
    }
    string mejorpal="";
    nodo->alargarpal(palcompleta, mejorpal);    //Alargamos nodo actual a partir del prefijo
    
    cout << " " << mejorpal << endl;
}