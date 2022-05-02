#include "library.h"

int main(int argc, char** argv){
  if (argc<2) {
    printf("utilisation : test_bool <mode> <image1.pgm> <image2.pgm> \n modes : \"i\" intersection || \"u\" union || \"xor\" XOR\n");
    return -1;
  }

  if (!strcmp( argv[1], "i" ) ||
      !strcmp( argv[1], "I" ) ) {
    printf("Mode intersection \n");
    image A,B,result;
    A=readPgm(argv[2]);
    B=readPgm(argv[3]);
    result=A;
    result=allocate(result);
    result=intersection(A , B, result);
    writePgm(result, "intersection.pgm");
    freeImage(A);
    freeImage(B);
    freeImage(result);
    printf("successful intersection \n");
    return 0;
  }
  if (!strcmp( argv[1], "u" ) ||
      !strcmp( argv[1], "U" ) ) {
    printf("Mode Union \n");
    image A,B,result;
    A=readPgm(argv[2]);
    B=readPgm(argv[3]);
    result=A;
    result=allocate(result);
    result=union_(A , B, result);
    writePgm(result, "union.pgm");
    freeImage(A);
    freeImage(B);
    freeImage(result);
    printf("successful union \n");
    return 0;
  }
  if (!strcmp( argv[1], "xor" ) ||
      !strcmp( argv[1], "XOR" ) ) {
    printf("Mode XOR \n");
    image A,B,result;
    A=readPgm(argv[2]);
    B=readPgm(argv[3]);
    result=A;
    result=allocate(result);
    result=XOR(A , B, result);
    writePgm(result, "xor.pgm");
    freeImage(A);
    freeImage(B);
    freeImage(result);
    printf("successful XOR \n");
    return 0;
  }
}
