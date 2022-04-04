#include "library.h"

int main(int argc, char** argv){
  if (argc<2) {
    printf("utilisation : test_counter <mode> <image1.pgm> \n modes : \"s\" simple\n");
    return -1;
  }

  if (!strcmp( argv[1], "s" ) ||
      !strcmp( argv[1], "S" ) ) {
    printf("Mode Comptage simple \n");
    image fichier;
    fichier=readPgm(argv[2]);
    int i,j;
    int count=0;

    //creation d'une matrice pour savoir quels pixels ont été visité
    int** visited;

    visited=calloc(fichier.height,sizeof(int*));
    *(visited)=calloc(fichier.height*fichier.width,sizeof(int));
    for( j=1; j<fichier.height ;j++){
      visited[j]=visited[j-1]+fichier.width;
    }
    //matrice de pixel visité initialisée a 0
    for (i = 0; i < fichier.height; i++) {
      for (j = 0; j < fichier.width; j++) {
        visited[i][j]=0;
      }
    }
    //on lance le DFS sur tout les pixels
    for (i = 0; i < fichier.height; i++) {
      for (j = 0; j < fichier.width; j++) {
        count=count+DFS(fichier,i,j,visited);
      }
    }
    freeImage(fichier);
    printf("Counter result : %d cells \n",count);
    return 0;
  }
}
