#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

void printpaddle(int y, int p){
    int i=0;
    if (p==1)
    {
            delete_pixel(0,y-1);
            delete_pixel(1,y-1);
        for (i = 0; i< 9; i++){
            display_pixel(0,y+i);
            display_pixel(1,y+i);
        }
            delete_pixel(0,y+9);
            delete_pixel(1,y+9);
    }

    else if (p==2){
            delete_pixel(126,y-1);
            delete_pixel(127,y-1);
        for (i = 0; i< 9; i++){
            display_pixel(126,y+i);
            display_pixel(127,y+i);
        }
            delete_pixel(126,y+9);
            delete_pixel(127,y+9);
            }
        display_update();
    quicksleep(1000000);
    return;
    }
    


//activated  by whataboutbuttons to move paddle up or down
void movePaddle(int a){
    ledupdate();
    if ((a == 0 ) && (p1 >= 1)){
    //code for moving paddle up
    p1 = p1-1;
    printpaddle(p1,1);
   }
    if ((a == 1) && (p1<24)){
        //code for moving paddle down  
        p1 = p1+1;
        printpaddle(p1,1);
    }
    if (a == 2 && (p2 >= 1)){
        //code for moving paddle 2 up
        p2 = p2-1;

        printpaddle(p2,2);
        }
    if ((a == 3) && p2<24 ){
        //code for moving paddle 2 down
        p2 = p2+1;
        printpaddle(p2,2);
  }
  return;
}

void updatePonging(void){
			while (1){
                whataboutbuttons();
            }
            
			//whataboutintersect();
            //whataboutball();




}
    //int whataboutintersect(int,int)
    //{
       // int relativeIntersectY = (paddle1Y+(PADDLELENGTH/2)) - intersectY;

   // }
