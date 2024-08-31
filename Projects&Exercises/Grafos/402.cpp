#include <stdlib.h>  // Funcion exit
#include <string.h>  // Funcion memset
#include <iostream>  // Variables cin y cout
#include <queue>     // Manejo de colas
using namespace std;

#define MAX_NODOS 26

//////////////////////////////////////////////////////////////
////////////        VARIABLES GLOBALES        ////////////////
//////////////////////////////////////////////////////////////

int nnodos;                   // Numero de nodos del grafo
int naristas;                 // Numero de aristas del grafo
bool G[MAX_NODOS][MAX_NODOS]; // Matriz de adyacencia
bool visitado[MAX_NODOS];     // Marcas de nodos visitados

//////////////////////////////////////////////////////////////
////////////     FUNCIONES DEL PROGRAMA       ////////////////
//////////////////////////////////////////////////////////////

void leeGrafo (void){
// Procedimiento para leer un grafo de la entrada
  cin >> nnodos >> naristas;
  if (nnodos<0 || nnodos>MAX_NODOS) {
    cerr << "Numero de nodos (" << nnodos << ") no valido\n";
    exit(0);
  }
  memset(G, 0, sizeof(G));
  char c1, c2;
  for (int i= 0; i<naristas; i++) {
    cin >> c1 >> c2;
    G[c1-'A'][c2-'A']= true;
  }
}

void bpa(int v){
// Procedimiento recursivo de la busqueda primero en profundidad
//   v - primer nodo visitado en la bpp
  queue<int> Cola;

  cout << char(v+'A');

  visitado[v]= true;
  Cola.push(v);
  while(!Cola.empty()){
      int x=Cola.front();
      Cola.pop();
      for (int y= 0; y<nnodos; y++){
          if (!visitado[y] && G[x][y]){
            visitado[y]=true;
	    Cola.push(y);
	    
            cout << char(y+'A'); 
          }
      }
  }
}

void busquedaPA (void){
// Procedimiento principal de la busqueda en profundidad
  memset(visitado, 0, sizeof(visitado));
  for (int v= 0; v<nnodos; v++) if (!visitado[v]) bpa(v);
  cout << endl;
}

//////////////////////////////////////////////////////////////
////////////        PROGRAMA PRINCIPAL        ////////////////
//////////////////////////////////////////////////////////////

int main (void){
  int ncasos;
  cin >> ncasos;
  for (int i= 0; i<ncasos; i++) {
    leeGrafo();
    busquedaPA();
  }
}
