#include <stdint.h> 
#include <stdio.h>

int innput = 1472;
int getsw( void ){
    int sw = (innput >> 8) & 0xf;
    return sw;
};

int getbtns(void){
    int btns = (innput >> 5) & 0x7;
    return btns;

}
int main(int argc, char *argv[]){
int mytime = 0x5957;

  int oldtime = mytime;
  int swbtns = (getbtns() >> 1);
  int sw = getsw();
    if ((getbtns() & 4) == 4){
        mytime = ((mytime & 4095) | (sw << 12));
    printf("knapp 1 är tryckt%d", mytime);
  }
   if ((getbtns() & 2) == 2){
      mytime = ((mytime & 61695) | (sw << 8));
    printf("knapp 2 är tryckt%d", mytime);
  }
    if ((getbtns() & 1) == 1){
      mytime = ((mytime & 65295) | (sw << 4));
    printf("knapp 3 är tryckt%d", mytime);
  }
  return 0;
}
//0011 1110 0000
//0000 0101 1100 0000