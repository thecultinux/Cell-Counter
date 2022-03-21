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

image union_(image A , image B){
  image union_;
  int i,j;
  assert (A.height==B.height);
  assert (A.width==B.width);
  assert (A.depth==B.depth);
  union_.height=A.height;
  union_.width=A.width;
  union_.depth=A.depth;
  union_=allocate(union_);
  for (i=0; i<A.height; i++){
    for (j=0; j<A.width; j++){

       if(A.data[i][j]==0 && B.data[i][j]==0) union_.data[i][j]=0;
       if(A.data[i][j]==255 && B.data[i][j]==0) union_.data[i][j]=255;
       if(A.data[i][j]==0 && B.data[i][j]==255) union_.data[i][j]=255;
       if(A.data[i][j]==255 && B.data[i][j]==255) union_.data[i][j]=255;

    }
  }
  return union_;
}

image XOR(image A , image B){
  image XOR;
  int i,j;
  assert (A.height==B.height);
  assert (A.width==B.width);
  assert (A.depth==B.depth);
  XOR.height=A.height;
  XOR.width=A.width;
  XOR.depth=A.depth;
  XOR=allocate(XOR);
  for (i=0; i<A.height; i++){
    for (j=0; j<A.width; j++){

       if(A.data[i][j]==0 && B.data[i][j]==0) XOR.data[i][j]=0;
       if(A.data[i][j]==255 && B.data[i][j]==0) XOR.data[i][j]=255;
       if(A.data[i][j]==0 && B.data[i][j]==255) XOR.data[i][j]=255;
       if(A.data[i][j]==255 && B.data[i][j]==255) XOR.data[i][j]=0;

    }
  }
  return XOR;
}
