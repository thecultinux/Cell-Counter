#ifndef PGM_H
#define PGM_H

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
int indexmaxi(float[], int);
image allocate(image img);


#endif
