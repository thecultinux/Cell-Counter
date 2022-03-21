#include "pgm.h"

image intersection(image A , image B){
  image inter;
  int i,j;
  assert (A.height==B.height);
  assert (A.width==B.width);
  assert (A.depth==B.depth);
  inter.height=A.height;
  inter.width=A.width;
  inter.depth=A.depth;
  inter=allocate(inter);
  for (i=0; i<A.height; i++){
    for (j=0; j<A.width; j++){

       if(A.data[i][j]==0 && B.data[i][j]==0) inter.data[i][j]=0;
       if(A.data[i][j]==255 && B.data[i][j]==0) inter.data[i][j]=0;
       if(A.data[i][j]==0 && B.data[i][j]==255) inter.data[i][j]=0;
       if(A.data[i][j]==255 && B.data[i][j]==255) inter.data[i][j]=255;

    }
  }
  return inter ;
}
