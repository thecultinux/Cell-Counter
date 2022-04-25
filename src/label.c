#include "library.h"

image gen_number(int n, image number){
  int i,j,k,l;
  float p = 0.10; //epaisseur du trait en % de la dimension de l'image
  for (i=0; i<number.height ; i++){
    for (j=0 ; j<number.width; j++){
      number.data[i][j]=255;
    }
  }
  switch (n) {
    case 0 :
      for (i=0; i<number.height ; i++){
        for (j=0 ; j<number.width; j++){
          if (i==0 || i==number.height-1 || j==0 || j==number.width-1 ){
            for (k=i-p*number.height/2; k<i+p*number.height/2 ; k++){
              for (l=j-p*number.width/2 ; l<j+p*number.width/2; l++){
                if (k>0 && k<number.height && l>0 && l<number.width) {
                  number.data[k][l]=0;
                }
              }
            }
          }
        }
      }
      break;

    case 1 :
    for (i=0; i<number.height ; i++){
      for (j=0 ; j<number.width; j++){
        if ( j== number.width-1 )
          for (k=i-p*number.height/2; k<i+p*number.height/2 ; k++){
            for (l=j-p*number.width/2 ; l<j+p*number.width/2; l++){
              if (k>0 && k<number.height && l>0 && l<number.width) {
                number.data[k][l]=0;
              }
            }
          }
      }
    }
    break;

    case 2 :
    for (i=0; i<number.height ; i++){
      for (j=0 ; j<number.width; j++){
        if ( i==0 || i==number.height-1 || i==number.height/2 || (j==number.width-1 &&  i>0 && i<number.height/2) || (j==0&&  i<number.height && i>number.height/2))
          for (k=i-p*number.height/2; k<i+p*number.height/2 ; k++){
            for (l=j-p*number.width/2 ; l<j+p*number.width/2; l++){
              if (k>0 && k<number.height && l>0 && l<number.width) {
                number.data[k][l]=0;
              }
            }
          }
      }
    }
    break;

    case 3 :
    for (i=0; i<number.height ; i++){
      for (j=0 ; j<number.width; j++){
        if ( i==0 || i==number.height-1 || i==number.height/2 || j==number.width-1 )
          for (k=i-p*number.height/2; k<i+p*number.height/2 ; k++){
            for (l=j-p*number.width/2 ; l<j+p*number.width/2; l++){
              if (k>0 && k<number.height && l>0 && l<number.width) {
                number.data[k][l]=0;
              }
            }
          }
      }
    }
    break;

    case 4 :
    for (i=0; i<number.height ; i++){
      for (j=0 ; j<number.width; j++){
        if (   i==number.height/2 || j==number.width-1 || (j==0 &&  i>0 && i<number.height/2))
          for (k=i-p*number.height/2; k<i+p*number.height/2 ; k++){
            for (l=j-p*number.width/2 ; l<j+p*number.width/2; l++){
              if (k>0 && k<number.height && l>0 && l<number.width) {
                number.data[k][l]=0;
              }
            }
          }
      }
    }
    break;

    case 5 :
    for (i=0; i<number.height ; i++){
      for (j=0 ; j<number.width; j++){
        if ( i==0 || i==number.height-1 || i==number.height/2 || (j==0 &&  i>0 && i<number.height/2) || (j==number.width-1 &&  i<number.height && i>number.height/2))
          for (k=i-p*number.height/2; k<i+p*number.height/2 ; k++){
            for (l=j-p*number.width/2 ; l<j+p*number.width/2; l++){
              if (k>0 && k<number.height && l>0 && l<number.width) {
                number.data[k][l]=0;
              }
            }
          }
      }
    }
    break;

    case 6 :
    for (i=0; i<number.height ; i++){
      for (j=0 ; j<number.width; j++){
        if ( i==0 || i==number.height-1 || i==number.height/2  || j==0 || (j==number.width-1 &&  i<number.height && i>number.height/2))
          for (k=i-p*number.height/2; k<i+p*number.height/2 ; k++){
            for (l=j-p*number.width/2 ; l<j+p*number.width/2; l++){
              if (k>0 && k<number.height && l>0 && l<number.width) {
                number.data[k][l]=0;
              }
            }
          }
      }
    }
    break;

    case 7 :
    for (i=0; i<number.height ; i++){
      for (j=0 ; j<number.width; j++){
        if ( j== number.width-1 || i==0 || j==0 || (j==number.width-1 &&  i<number.height && i>number.height/2) || (j==0 &&  i>0 && i<number.height/2))
          for (k=i-p*number.height/2; k<i+p*number.height/2 ; k++){
            for (l=j-p*number.width/2 ; l<j+p*number.width/2; l++){
              if (k>0 && k<number.height && l>0 && l<number.width ) {
                number.data[k][l]=0;
              }
            }
          }
      }
    }
    break;

    case 8 :
      for (i=0; i<number.height ; i++){
        for (j=0 ; j<number.width; j++){
          if (i==0 || i==number.height-1 || j==0 || j== number.width-1 || i==number.height/2)
            for (k=i-p*number.height/2; k<i+p*number.height/2 ; k++){
              for (l=j-p*number.width/2 ; l<j+p*number.width/2; l++){
                if (k>0 && k<number.height && l>0 && l<number.width ) {
                  number.data[k][l]=0;
                }
              }
            }
        }
      }
      break;

      case 9 :
      for (i=0; i<number.height ; i++){
        for (j=0 ; j<number.width; j++){
          if ( j== number.width-1 || i==0 || i==number.height-1 || i==number.height/2 || (j==0 &&  i>0 && i<number.height/2))
            for (k=i-p*number.height/2; k<i+p*number.height/2 ; k++){
              for (l=j-p*number.width/2 ; l<j+p*number.width/2; l++){
                if (k>0 && k<number.height && l>0 && l<number.width ) {
                  number.data[k][l]=0;
                }
              }
            }
        }
      }
      break;

  }
  return number;
}
