#include "pgm.h"

int main(int argc,char** argv) { //arg 1 nom image || arg2 seuil

  if(!argv[1]||!argv[2]||atoi(argv[2])<0||argc!=3){
    printf("Utilisation du programme : test_pgm_threshold <file.pgm> <threshold>\n");
    return -1;
  }
  
  int threshold=atoi(argv[2]);
  image fichier = readPgm(argv[1]);
  manual_threshold(fichier,threshold);

  writePgm(fichier, "threshold.pgm");
  freeImage(fichier);
  return 0;
}
