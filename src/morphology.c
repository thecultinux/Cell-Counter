#include "library.h"

image erode(image fichier){
  int i,j;
  image output;
  output.height=fichier.height;
  output.width=fichier.width;
  output.depth=fichier.depth;
  output=allocate(output);
  for (i = 1; i < fichier.height-1; i++) { //on commence a 1 et on s'arrete a -1 car la bordure n'a pas de voisins
    for (j = 1; j < fichier.width-1; j++) {
      if(fichier.data[i][j-1]==255
        && (fichier.data[i][j+1]==255)
        && (fichier.data[i-1][j]==255)
        && (fichier.data[i+1][j]==255)
        && (fichier.data[i-1][j-1]==255)
        && (fichier.data[i-1][j+1]==255)
        && (fichier.data[i+1][j-1]==255)
        && (fichier.data[i+1][j+1]==255)
        && (fichier.data[i][j]==255)){
        output.data[i][j]=255;
      }
      else if((fichier.data[i][j-1]==0)
      || (fichier.data[i][j+1]==0)
      || (fichier.data[i-1][j]==0)
      || (fichier.data[i+1][j]==0)
      || (fichier.data[i-1][j-1]==0)
      || (fichier.data[i-1][j+1]==0)
      || (fichier.data[i+1][j-1]==0)
      || (fichier.data[i+1][j+1]==0)
      || (fichier.data[i][j]==0)){
        output.data[i][j]=0;
      }
    }
  }
  freeImage(fichier);
  return output;
}

image expanse(image fichier){
  int i,j;
  image output;
  output.height=fichier.height;
  output.width=fichier.width;
  output.depth=fichier.depth;
  output=allocate(output);
  for (i = 1; i < fichier.height-1; i++) { //on commence a 1 et on s'arrete a -1 car la bordure n'a pas de voisins
    for (j = 1; j < fichier.width-1; j++) {
      if((fichier.data[i][j-1]==255)
      || (fichier.data[i][j+1]==255)
      || (fichier.data[i-1][j]==255)
      || (fichier.data[i+1][j]==255)
      || (fichier.data[i-1][j-1]==255)
      || (fichier.data[i-1][j+1]==255)
      || (fichier.data[i+1][j-1]==255)
      || (fichier.data[i+1][j+1]==255)
      || (fichier.data[i][j]==255)){
        output.data[i][j]=255;
      }
      else if(fichier.data[i][j-1]==0
        && (fichier.data[i][j+1]==0)
        && (fichier.data[i-1][j]==0)
        && (fichier.data[i+1][j]==0)
        && (fichier.data[i-1][j-1]==0)
        && (fichier.data[i-1][j+1]==0)
        && (fichier.data[i+1][j-1]==0)
        && (fichier.data[i+1][j+1]==0)
        && (fichier.data[i][j]==0)){
        output.data[i][j]=0;
      }
    }
  }
  freeImage(fichier);
  return output;
}

image reconstruct(image fichier, image seed){
  image old_output = fichier;
  image output = fichier;
  old_output=allocate(old_output);
  output=allocate(output);
  image_copy(fichier,output);

  do {
    seed=expanse(seed);
    image_copy(output,old_output);
    output=intersection(fichier,seed);
    image_copy(output,seed);
  }while(!are_same_image(output, old_output));
  return output;
}
