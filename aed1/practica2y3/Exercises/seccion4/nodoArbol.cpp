#include "nodoArbol.hpp"

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

NodoArbol::NodoArbol() {
	caracter=' ';
	ptr = NULL;
	sig = NULL;
}

NodoArbol::NodoArbol(char car, NodoArbol* sig, NodoArbol* ptr){
    this->caracter = car;
    this->sig = sig;
    this->ptr = ptr;
}

NodoArbol::~NodoArbol() {
	delete ptr;
	delete sig;
}

void NodoArbol::inserta(char car) {
	NodoArbol* nodotemp = this;     //Nos situamos en el nodo
	//Mientras la siguiente posición del nodo no esté vacía y no el carácter sea distinto, avanzamos por el nodo
	while(nodotemp->sig!=NULL && nodotemp->sig->caracter<car) nodotemp=nodotemp->sig;
	//Si la siguiente posición del nodo está vacía: (esto quiere decir que el caracter aún no ha sido escrito)
	if(nodotemp->sig==NULL || nodotemp->sig->caracter!=car) nodotemp->sig = new NodoArbol(car, nodotemp->sig, new NodoArbol());
}

NodoArbol* NodoArbol::consulta(char car) {
	NodoArbol* nodotemp = this->sig;
	while(nodotemp!=NULL && nodotemp->caracter<car) nodotemp=nodotemp->sig;
	if (nodotemp!=NULL && nodotemp->caracter == car) return nodotemp->ptr;
	else return NULL;
}

void NodoArbol::PonMarca() {
	this->caracter='$';             //Pone marca de fin de palabra
}

void NodoArbol::QuitaMarca() {
	this->caracter=' ';             //Quita $
}

bool NodoArbol::HayMarca() {
	return this->caracter=='$';     //Busca final de palabra
}

void NodoArbol::alargarpal(string &palActual, string &mejorPalabra) {
    if (this->HayMarca()) {
        int contAct=0;
        int contMej=0;
        for(int i=0; i<palActual.length(); i++){
        	if (palActual[i]==(char)0xC3) contAct+=1;
        }
        for(int i=0; i<mejorPalabra.length(); i++){
        	if (mejorPalabra[i]==(char)0xC3) contMej+=1;
        }
        if (palActual.length()-contAct > mejorPalabra.length()-contMej ||
            (palActual.length()-contAct == mejorPalabra.length()-contMej && palActual < mejorPalabra)) {
            mejorPalabra = palActual;
        }
    }
    NodoArbol* nodotemp = this->sig;
    while (nodotemp != nullptr) {
        palActual += nodotemp->caracter;
        NodoArbol* ptrtemp = nodotemp->ptr;
        ptrtemp->alargarpal(palActual, mejorPalabra);
        palActual.pop_back();
        nodotemp = nodotemp->sig;
    }
}
