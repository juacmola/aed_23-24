
#include <stdlib.h>  // Funcion exit
#include <string.h>  // Funcion memset
#include <iostream>  // Variables cin y cout
#include <queue>     // Manejo de colas
#include <sstream>
using namespace std;

#define MAX_NODOS 20000
#define MAX_ADYACENTES 10

//////////////////////////////////////////////////////////////
////////////        VARIABLES GLOBALES        ////////////////
//////////////////////////////////////////////////////////////

int N;                              // Numero de sitios del laberinto
int G[MAX_NODOS][MAX_ADYACENTES];   // Matriz de adyacencia
bool visitado[MAX_NODOS];           // Marcas de nodos visitados
queue<int> Cola;
bool k;

//////////////////////////////////////////////////////////////
////////////     FUNCIONES DEL PROGRAMA       ////////////////
//////////////////////////////////////////////////////////////

void leeGrafo (void){
// Procedimiento para leer un grafo de la entrada
  cin >> N;
  if (N<0 || N>MAX_NODOS) {
    cerr << "Numero de sitios (" << N << ") no valido\n";
    exit(0);
  }
  memset(G, 0, sizeof(G));
  
  string linea;
  int numadyacente;
  
  for (int i= -1; i<N; i++) {
    getline(cin,linea);
    stringstream lineaAdyacente(linea);
    
    int j=0;
    while(lineaAdyacente >> numadyacente){
        G[i][j]= numadyacente;
        j++;
    }
  }
  /*for (int i= 0; i<=N; i++){
	for (int j= 0; j<=5; j++){
		cout << G[i][j]<<" ";
} cout<<endl;
}  */
}

void salto(int v){
    visitado[v-1]=true;
    Cola.push(v);
    int n;
    
    if (N!=v){
        for(int p=0;p<MAX_ADYACENTES;p++){
            n=G[v-1][p];
            if(!visitado[n-1] && n!=0){
                salto(n);
                if (!visitado[N-1]&&!k) {
                	k=true;
                	salto(v);
                }
            }else k=false;
            if (visitado[N-1]){              
                break;
                }
        }
    }

}

bool nodosVisitados(){
    if (visitado[N-1]){
		return true;
	}else{
		bool nodovisitado =true;
		for(int r=0;r<N;r++) if (!visitado[r]) nodovisitado=false;
		return nodovisitado;
	}
}


void laberinto(){
    memset(visitado, 0, sizeof(visitado));
    
    salto(1);

	if(nodosVisitados()){
        	cout << Cola.size() << endl;
		while (!Cola.empty()){
		    cout << Cola.front() << endl;
		    Cola.pop();
		}
		//if(Cola.empty()) cout<< "Cola vacía"<<endl;
    	}else {
    		cout << "INFINITO" << endl;
    		while (!Cola.empty()){
		    Cola.pop();
		}
    	}
    	
}

//////////////////////////////////////////////////////////////
////////////        PROGRAMA PRINCIPAL        ////////////////
//////////////////////////////////////////////////////////////

int main (void){
  int ncasos;
  cin >> ncasos;
  for (int i= 0; i<ncasos; i++) {
    leeGrafo();
    cout << "Caso " << i+1 << endl;
    laberinto();
  }
}

