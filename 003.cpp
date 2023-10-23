
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

const string STR_ESPEC="áéíóúÁÉÍÓÚñÑüÜ";

int contador=0;

string normalizar (string cad){
    string salida="";

    int letras[10][2]= {{0xA1, 0x41}, {0xA9, 0x45}, {0xAD, 0x49},
                    {0xB3, 0x4F}, {0xBA, 0x55}, {0x81, 0x41},
                    {0x89, 0x45}, {0x8D, 0x49}, {0x93, 0x4F},
                    {0x9A, 0x55}};

    for(unsigned i=0; i<cad.length(); i++){
        if (cad[i] >= 'a' && cad[i] <= 'z')
            salida+=toupper(cad[i]);
        else if (cad[i]==(char)0xC3){
            if (cad[i+1]==(char)0xBC || cad[i+1]==(char)0x9C){
                salida+=(char)0xC3;
                salida+=(char)0x9C;
                i++;
            }else if (cad[i+1]==(char)0xB1 || cad[i+1]==(char)0x91){
                salida+=(char)0xC3;
                salida+=(char)0x91;
                i++;
            }else if (STR_ESPEC.find(cad[i+1])!=string::npos){
                for (int j= 0; j<10; j++){
                    if (cad[i+1]==(char)letras[j][0]){
                        salida+=(char)letras[j][1];
                        i++;
                        break;
                    }
                }
            }else{
                salida+=cad[i];
            }
        }else {salida+=cad[i];}
    }
    return salida;
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
    cout << "Juanagrama: " << normalizar(palabra) << endl <<
            "No implementado" << endl;
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
    cout << "Alarga: " << normalizar(palabra) << endl <<
            "No implementado" << endl;
}

void INSERTAR(){
    string palabra;
    int M=0;

    while(cin>>palabra){
        if(palabra=="</insertar>")
            break;
        M+=1;
        contador+=1;
    }
    cout << "Insertando: " << M << " palabras" << endl <<
            "Total diccionario: " << contador << " palabras" << endl;
}

void VACIAR(){
    contador=0;
    cout << "Vaciando" << endl << "Total diccionario: " <<
            contador << " palabras" << endl;
}

void BUSCAR(){
    string palabra;
    cin >> palabra;
    cout << "Buscando: " << normalizar(palabra) << " -> " <<
            "No encontrada" << endl;
}

void EXIT(){
    cout << "Saliendo..." << endl;
    exit(0);
}

void Interprete (string comando){
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

int main (void){
    string comando;

    while (cin>>comando){
        Interprete(comando);
    }
}

