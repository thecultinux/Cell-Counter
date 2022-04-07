#include "library.h"

image intersection(image A , image B, image inter){
  int i,j;
  assert (A.height==B.height);
  assert (A.width==B.width);
  assert (A.depth==B.depth);

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

image union_(image A , image B, image union_){
  int i,j;
  assert (A.height==B.height);
  assert (A.width==B.width);
  assert (A.depth==B.depth);
  union_.height=A.height;

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
image XOR(image A , image B, image XOR){
  int i,j;
  assert (A.height==B.height);
  assert (A.width==B.width);
  assert (A.depth==B.depth);
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
