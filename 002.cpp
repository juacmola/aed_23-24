
#include <iostream>
#include <vector>

using namespace std;

const string STR_ESPEC="áéíóúÁÉÍÓÚñÑüÜ";

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

int main (void){
    int contador=1;
    string palabra, normalizada;

    while (cin>>palabra){
        normalizada = normalizar(palabra);
        cout << contador << ". " << palabra << " -> " << normalizada << endl;
        contador+=1;
    }
}

