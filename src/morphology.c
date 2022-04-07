#include "library.h"

image erode(image fichier, image output){
  int i,j;
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
  return output;
}

image expanse(image fichier, image output){
  int i,j;
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
  return output;
}

image reconstruct(image fichier, image seed, image output){
  image old_output = fichier;
  old_output=allocate(old_output);
  image local_seed=seed;
  local_seed=allocate(local_seed);
  image expansed_seed = fichier;
  expansed_seed=allocate(expansed_seed);
  image_copy(seed,local_seed);
  image_copy(fichier,old_output);
  do {
    image_copy(output,old_output);
    expansed_seed=expanse(local_seed,expansed_seed);
    output=intersection(fichier,expansed_seed,output);
    image_copy(output,local_seed);
  }while(!are_same_image(output, old_output));
  freeImage(old_output);
  freeImage(local_seed);
  freeImage(expansed_seed);
  return output;
}

image ultimate_erode(image input, image ultimate_erode){
  image residues, reconstructed, current, eroded, expansed;
  reconstructed=input;
  eroded=input;
  current=input;
  residues=input;
  expansed=input;
  residues=allocate(residues);
  reconstructed=allocate(reconstructed);
  eroded=allocate(eroded);
  current=allocate(current);
  expansed=allocate(expansed);
  image_copy(input, current);
  do{
    eroded=erode(current,eroded);
    wipeImage(reconstructed);
    reconstructed=reconstruct(current,eroded,reconstructed);
    residues=XOR(reconstructed,current,residues);
    ultimate_erode=union_(residues,ultimate_erode,ultimate_erode);
    image_copy(eroded,current);
  }while(!isEmpty(current));
  ultimate_erode=expanse(ultimate_erode,expansed);
  image_copy(expansed,ultimate_erode);
  freeImage(reconstructed);
  freeImage(eroded);
  freeImage(current);
  freeImage(residues);
  //freeImage(expansed); fait une erreur ?
  return ultimate_erode;
}
