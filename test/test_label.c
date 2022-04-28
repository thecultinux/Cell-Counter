#include "library.h"

int main(int argc, char** argv){

  if (argc<2) {
    printf("utilisation : \ntest_label gen_num <number> \ntest_label l <number> <image>\n modes : \"gen_num\" generates image with a number || \"l\" adds a number to an image || \n");
    return -1;
  }

  if (!strcmp( argv[1], "gen_num" ) ||
      !strcmp( argv[1], "GEN_NUM" ) ) {
        if (argc<2) {
          printf("utilisation : \ntest_label gen_num <number> \ntest_label l <number> <image>\n modes : \"gen_num\" generates image with a number || \"l\" adds a number to an image || \n");
          return -1;
        }
        int n = atoi(argv[2]);
        image number;
        number.height=1000;
        number.width=500;
        number.depth=255;
        number=allocate(number);
        number=gen_number(n,number);
        writePgm(number,"number.pgm");
        freeImage(number);
        printf("Label printed\n");
  }

  if (!strcmp( argv[1], "l" ) ||
      !strcmp( argv[1], "L" ) ) {
        if (argc<4) {
          printf("utilisation : \ntest_label gen_num <number> \ntest_label l <number> <image>\n modes : \"gen_num\" generates image with a number || \"l\" adds a number to an image || \n");
          return -1;
        }
        int N = atoi(argv[2]);
        image fichier = readPgm(argv[3]);
        image output=fichier;
        output=allocate(output);
        output=label( fichier.height/2, fichier.width/2 , N, fichier, output);
        writePgm(output,"labeled.pgm");
        freeImage(output);
        freeImage(fichier);
        printf("Label printed\n");
  }
  return 0;
}
