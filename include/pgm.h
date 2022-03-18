#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <float.h>
#include <math.h>


typedef struct image{
  int width;
  int height;
  int depth;
  unsigned char** data;
} image;

image readPgm( char * );
int writePgm( image , char*);
void freeImage( image );
int manual_threshold(image , int );
int auto_threshold(image);
