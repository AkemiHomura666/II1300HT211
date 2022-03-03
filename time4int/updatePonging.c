#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

//activated  by whataboutbuttons to move paddle up or down
void movePaddle(int a){
  if (a == 0){
    //code for moving paddle up
    p1 = p1-1;
  }
    else if (a == 1){
        //code for moving paddle down  
        p1 = p1+1;
    }
    else if (a == 2){
        p2 = p2-1;
        }
    else if (a == 3){
        p2 = p2+1;
  }

void updatePonging(void){
			whataboutbuttons();
			whataboutintersect();




}
    int whataboutintersect(int,int)
    {
        int relativeIntersectY = (paddle1Y+(PADDLELENGTH/2)) - intersectY;

    }

void printpaddle(int x, int y){
    
}