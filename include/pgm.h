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
image allocate(image img);
int are_same_image(image a, image b);
int image_copy(image source, image dest);

#endif
