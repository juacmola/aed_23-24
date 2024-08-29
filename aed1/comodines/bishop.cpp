#include <iostream>
#include <vector>
using namespace std;
int main (void){
    int C;
    cin>>C;
    vector<string> listaFinal;

    for(int i=0;i<C;i++){
        cout<<"\n"<<endl;
        int T,N;
        cin>>T;
        cin>>N;
        for(int t=0;t<T;t++){
            int fa, ca, fo, co;
            cin>>fa>>ca>>fo>>co;
            cin.ignore();
            if((1<=fa<=N)&&(1<=ca<=N)&&(1<=fo<=N)&&(1<=co<=N)){
                if((fa+ca)%2==(fo+co)%2){
                    if(fa==fo&&ca==co){
                        listaFinal.push_back("0");
                    }
                    else if(abs(fa-fo)==abs(ca-co)){
                        listaFinal.push_back("1");
                    }
                    else{listaFinal.push_back("2");}
                }
                else{listaFinal.push_back("no move");}
            }else{listaFinal.push_back("no move");}
        }
    }
    cout<<"\n"<<endl;
    for (int l=0; l<listaFinal.size(); l++){
        cout<<listaFinal[l]<<endl;
    }
}
