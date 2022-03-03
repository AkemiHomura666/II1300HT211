#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

void printpaddle(int y, int p){
    int i=0;
    if (p==1)
    {
        for (i = 0; i< 8; i++){
            delete_pixel(0,y-1);
            delete_pixel(1,y-1);
            display_pixel(0,y+i);
            display_pixel(1,y+i);
            delete_pixel(0,y+1);
            delete_pixel(1,y+1);
        }
    if (p=2){
        for (i = 0; i< 8; i++){
            delete_pixel(126,y-1);
            delete_pixel(127,y-1);
            display_pixel(126,y+i);
            display_pixel(127,y+i);
            delete_pixel(126,y+1);
            delete_pixel(127,y+1);
        }
               
    }
    }
}

//activated  by whataboutbuttons to move paddle up or down
void movePaddle(int a){
  if (a == 0 && p1<24 && p1>-1){
    //code for moving paddle up
    p1 = p1-1;
    printpaddle(p1,1);
    display_update();
  }
    else if (a == 1 && p1<24 && p1>-1){
        //code for moving paddle down  
        p1 = p1+1;
        printpaddle(p1,1);
        display_update();
    }
    else if (a == 2 && p2<24 && p2>-1){
        p2 = p2-1;
        printpaddle(p2,2);
        display_update();
        }
    else if (a == 3 && p2<24 && p2>-1){
        p2 = p2+1;
        printpaddle(p2,2);
        display_update();
  }
}

void updatePonging(void){
			whataboutbuttons();
			//whataboutintersect();
            //whataboutball();




}
    //int whataboutintersect(int,int)
    //{
       // int relativeIntersectY = (paddle1Y+(PADDLELENGTH/2)) - intersectY;

   // }
