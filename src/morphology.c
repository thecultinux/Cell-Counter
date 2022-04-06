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
        ){
        output.data[i][j]=255;
      }
      else{
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
      ){
        output.data[i][j]=255;
      }
      else {
        output.data[i][j]=0;
      }
    }
  }
  freeImage(fichier);
  return output;
}

image reconstruct(image fichier, image seed, image output){
  image old_output = fichier;
  old_output=allocate(old_output);
  image local_seed=seed;
  local_seed=allocate(local_seed);
  if(output.data==0){
    output=allocate(output);
  }
  image_copy(seed,local_seed);
  image_copy(fichier,old_output);
  do {
    image_copy(output,old_output);
    local_seed=expanse(local_seed);
    output=intersection(fichier,local_seed,output);
    image_copy(output,local_seed);
  }while(!are_same_image(output, old_output));
  freeImage(old_output);
  freeImage(local_seed);
  return output;
}
