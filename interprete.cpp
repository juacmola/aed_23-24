#include "interprete.hpp"
#include "diccionario.hpp"

#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <algorithm>

using namespace std;

DicPalabras dic;

string normalizar (string cad){
    unordered_map<char, char> letras = {{0xA1, 0x41}, {0xA9, 0x45}, {0xAD, 0x49},
                                             {0xB3, 0x4F}, {0xBA, 0x55}, {0x81, 0x41},
                                             {0x89, 0x45}, {0x8D, 0x49}, {0x93, 0x4F},
                                             {0x9A, 0x55}};

    transform(cad.begin(), cad.end(), cad.begin(), ::toupper);

    for(unsigned i=0; i<cad.length(); i++){
        if (cad[i]==(char)0xC3){
            if (cad[i+1]==(char)0xBC || cad[i+1]==(char)0x9C){
                cad[i+1]=(char)0x9C;
                i++;
            }else if (cad[i+1]==(char)0xB1 || cad[i+1]==(char)0x91){
                cad[i+1]=(char)0x91;
                i++;
            }else if (STR_ESPEC.find(cad[i+1])!=string::npos){
                auto it = letras.find(cad[i+1]);
                if (it != letras.end()){
                    cad[i+1] = it->second;
                    i++;
                }
            }
        }
    }
    return cad;
}

void PARTIDAS(){
    string palabra;
    cout << "Partidas: ";

    cin>>palabra;

    if(palabra!="</partidas>"){
        cout << normalizar(palabra);
        while(cin>>palabra){
            if(palabra=="</partidas>")
                break;
            cout << " " << normalizar(palabra);
        }
    }
    cout << endl << "No implementado" << endl;
}

void ALOCADO(){
    string palabra;
    cin >> palabra;
    cout << "Alocado: " << normalizar(palabra) << endl <<
            "No implementado" << endl;
}

void CESAR(){
    string palabra;
    cin >> palabra;
    cout << "César: " << normalizar(palabra) << endl <<
            "No implementado" << endl;
}

void JUANAGRAMA(){
    string palabra;
    cin >> palabra;
	
	string normalizada = normalizar(palabra);
	
	cout << "Juanagrama: " << normalizada << " ->";

    list<string> juanagrama = dic.anagramas(normalizada);
	list<string>::iterator iter = juanagrama.begin();

    	if(iter==juanagrama.end()) cout  << "";
	else cout << " " << *iter;	
    
    cout << endl;
}

void SACO(){
    string palabra1, palabra2;
    cin >> palabra1 >> palabra2;
    cout << "Saco: " << normalizar(palabra1) << " " << normalizar(palabra2) <<
            endl << "No implementado" << endl;
}

void CONSOME(){
    string palabra;
    cin >> palabra;
    cout << "Consomé: " << normalizar(palabra) << endl <<
            "No implementado" << endl;
}

void ALARGA(){
    string palabra;
    cin >> palabra;
    string normalizada=normalizar(palabra);
    cout << "Alarga: " << normalizada << " ->";
    dic.alarga(normalizada);
}

void INSERTAR(){
    string palabra;
    int M=0;

    while(cin>>palabra){
        if(palabra=="</insertar>")
            break;
	dic.insertar(normalizar(palabra)); //Insertamos la palabra normalizada
        M++;
    }
    cout << "Insertando: " << M << " palabras" << endl <<
            "Total diccionario: " << dic.numElem() << " palabras" << endl;
}

void VACIAR(){
    dic.vaciar();
    cout << "Vaciando" << endl << "Total diccionario: " <<
            dic.numElem() << " palabras" << endl;
}

void BUSCAR(){
    string palabra;
    cin >> palabra;
    if (dic.consultar(normalizar(palabra))){ //La buscamos normalizada porque así es como se guarda
	cout << "Buscando: " << normalizar(palabra) << " -> " <<
            "Encontrada" << endl;
    }else{
    	cout << "Buscando: " << normalizar(palabra) << " -> " <<
            "No encontrada" << endl;
    }
}

void EXIT(){
    cout << "Saliendo..." <<endl;
    exit(0);
}

void procesar(string comando){
    if (comando=="<insertar>") INSERTAR();
    else if (comando=="<vaciar>") VACIAR();
    else if (comando=="<buscar>") BUSCAR();
    else if (comando=="<partidas>") PARTIDAS();
    else if (comando=="<alocado>") ALOCADO();
    else if (comando=="<césar>") CESAR();
    else if (comando=="<juanagra>") JUANAGRAMA();
    else if (comando=="<saco>") SACO();
    else if (comando=="<consomé>") CONSOME();
    else if (comando=="<alarga>") ALARGA();
    else if (comando=="<exit>") EXIT();
}


