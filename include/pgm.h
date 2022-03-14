#include <stdio.h>
#include <stdlib.h>


typedef struct image{
  int width;
  int height;
  int depth;
  unsigned char** data;
} image;

image readPgm( char * );
int writePgm( image );
void freeImage( image );
