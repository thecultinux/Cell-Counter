#include "library.h"

image gen_number(int n; image number){
  int i,j ;
  for (i=0; i<number.height ; i++){
    for (j=0 ; j<number.width; j++){
      number.data[i][j]=255;
    }
  }
  switch (n) {
    case 0 :
      for (i=0; i<number.height ; i++){
        for (j=0 ; j<number.width; j++){
          if (i==0 || i==number.height-1 || j=0 || j= number.width-1 )
            number.data[i][j]=0;
        }
      }
    case 1 :
    for (i=0; i<number.height ; i++){
      for (j=0 ; j<number.width; j++){
        if ( j= number.width-1 )
          number.data[i][j]=0;
      }
    }
    case 2 :
    for (i=0; i<number.height ; i++){
      for (j=0 ; j<number.width; j++){
        if ( i==0 || i==number.height-1 || i==number.height/2 )
          number.data[i][j]=0;
        if (j==number.width-1 &&  i>0 && i<umber.height/2)
          number.data[i][j]=0;
        if (j==0&&  i<number.height && i>number.height/2)
            number.data[i][j]=0;
      }
    }
    case 3 :
    for (i=0; i<number.height ; i++){
      for (j=0 ; j<number.width; j++){
        if ( i==0 || i==number.height-1 || i==number.height/2 || j==number.width-1 )
          number.data[i][j]=0;
      }
    }
    case 4 :
    for (i=0; i<number.height ; i++){
      for (j=0 ; j<number.width; j++){
        if (   i==number.height/2 || j==number.width-1)
          number.data[i][j]=0;
        if (j==0 &&  i>0 && i<number.height/2)
            number.data[i][j]=0;
      }
    }
    case 5 :
    for (i=0; i<number.height ; i++){
      for (j=0 ; j<number.width; j++){
        if ( i==0 || i==number.height-1 || i==number.height/2 )
          number.data[i][j]=0;
        if (j==0 &&  i>0 && i<umber.height/2)
          number.data[i][j]=0;
        if (j==number.width-1 &&  i<number.height && i>number.height/2)
            number.data[i][j]=0;
      }
    }
    case 6 :
    for (i=0; i<number.height ; i++){
      for (j=0 ; j<number.width; j++){
        if ( i==0 || i==number.height-1 || i==number.height/2 )
          number.data[i][j]=0;
        if (j==0)
          number.data[i][j]=0;
        if (j==number.width-1 &&  i<number.height && i>number.height/2)
            number.data[i][j]=0;
      }
    }
    case 7 :
    for (i=0; i<number.height ; i++){
      for (j=0 ; j<number.width; j++){
        if ( j= number.width-1 || i==0 )
          number.data[i][j]=0;
        if (j==0 &&  i>0 && i<number.height/2)
          number.data[i][j]=0;
      }
    }
    case 8 :
      for (i=0; i<number.height ; i++){
        for (j=0 ; j<number.width; j++){
          if (i==0 || i==number.height-1 || j=0 || j= number.width-1 || i==number.height/2)
            number.data[i][j]=0;
        }
      }
      case 9 :
      for (i=0; i<number.height ; i++){
        for (j=0 ; j<number.width; j++){
          if ( j= number.width-1 || i==0 || i==number.height-1 || i==number.height/2)
            number.data[i][j]=0;
          if (j==0 &&  i>0 && i<number.height/2)
            number.data[i][j]=0;
        }
      }
  }
  return number;
}
