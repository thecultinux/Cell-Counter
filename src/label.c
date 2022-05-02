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
        if ( j== number.width-1 || i==0 || (j==number.width-1 &&  i<number.height && i>number.height/2) || (j==0 &&  i>0 && i<number.height/2))
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

image label(int i,int j,int N,image fichier,image output){
  int k,l;
  int m=0;
  int n=m;

  if (N<10){
    image number;
    number.height=0.1*fichier.height;
    number.width=0.05*fichier.width;
    number.depth=255;
    number=allocate(number);
    number=gen_number(N,number);
    image_copy(fichier, output);
    for(k=i-number.height/2+1 ; k<i+number.height/2 ; k++){
      n=0;
      for(l=j-number.width/2+1 ; l<j+number.width/2 ; l++){
        n++;
        if (k>0 && k<output.height && l>0 && l<output.width && number.data[m][n]==0){
          output.data[k][l]=number.data[m][n];
        }
      }
      m++;
    }
    freeImage(number);
  }
  if (N>=10 && N<100){
    image number;
    number.height=0.1*fichier.height;
    number.width=0.05*fichier.width;
    number.depth=255;
    number=allocate(number);
    number=gen_number(N/10,number); //puissance unités
    image_copy(fichier, output);
    for(k=i-number.height/2+1 ; k<i+number.height/2 ; k++){
      n=0;
      for(l=j-number.width+1 ; l<j ; l++){
        n++;
        if (k>0 && k<output.height && l>0 && l<output.width && number.data[m][n]==0){
          output.data[k][l]=number.data[m][n];
        }
      }
      m++;
    }

  m=0;
  number=gen_number(N%10,number); //puissance dizaine
  for(k=i-number.height/2+1 ; k<i+number.height/2 ; k++){
    n=0;
    for(l=j+1 ; l<j+number.width+1 ; l++){
      n++;
      if (k>0 && k<output.height && l>0 && l<output.width && number.data[m][n]==0){
        output.data[k][l]=number.data[m][n];
      }
    }
    m++;
  }
  freeImage(number);
}

  return output;
}
