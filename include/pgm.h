#include <stdio.h>
#include <stdlib.h>


typedef struct image{
  unsigned int width;
  unsigned int height;
  unsigned int depth;
  unsigned char** data;
} image;

image readPgm( char * );
