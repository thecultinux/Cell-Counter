#include "library.h"

int DFS(image fichier,int i, int j, int** visited){
  if (visited[i][j]==0 && fichier.data[i][j]==255) {
    visited[i][j]=1; //marque le pixel comme visité
    DFS(fichier,i-i,j,visited);
    DFS(fichier,i+1,j,visited);
    DFS(fichier,i,j-1,visited);
    DFS(fichier,i,j+1,visited);
    return 1;
  }
  return 0;
}
