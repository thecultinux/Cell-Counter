#include "library.h"

int main(int argc, char** argv){

  if (argc<2) {
    printf("utilisation : test_label <mode> <number> \n modes : \"gen_num\" generates image with a number || \n");
    return -1;
  }

  if (!strcmp( argv[1], "gen_num" ) ||
      !strcmp( argv[1], "GEN_NUM" ) ) {
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
  return 0;
}
