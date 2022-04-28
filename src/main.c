#include "library.h"

int main(int argc, char** argv) {
  if (argc!=2) {
    printf("This program counts the biological cells in a PGM picture\n");
    printf("To use the program please provide a picture as follow : ./main <picture.pgm> \n");
  }
  else{
    image fichier=readPgm(argv[1]);
    image output=fichier;
    output=allocate(output);
    auto_threshold(fichier);
    output=delete_edge_cell(fichier, output);
    image_copy(output,fichier);
    wipeImage(output);
    output=hole_plugging(fichier,output);
    image_copy(output,fichier);
    wipeImage(output);
    output=ultimate_erode(fichier,output);
    image_copy(output,fichier);
    wipeImage(output);
    image source=readPgm(argv[1]);

    int i,j;
    int N=0;
    int oldN=N;

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
        oldN=N;
        N=N+DFS(fichier,i,j,visited);
        printf("%d%% \r", 100*i/fichier.height);
        if (oldN!=N) {
          output=label(i, j, N, source, output);
          image_copy(output, source);
        }
      }
    }

    writePgm(source,"counted.pgm");
    printf("\n Counter result : %d cells \n",N);
    freeImage(fichier);
    freeImage(output);
    freeImage(source);
    free(*(visited));
    free(visited);

  }
  return 0;
}
