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
    if (p==2){
            delete_pixel(126,y-1);
            delete_pixel(127,y-1);
        for (i = 0; i< 9; i++){
            display_pixel(126,y+i);
            display_pixel(127,y+i);
        }
            delete_pixel(126,y+9);
            delete_pixel(127,y+9);
               
    }
    }
}

//activated  by whataboutbuttons to move paddle up or down
void movePaddle(int a){
    ledupdate();
    if (a == 0 && p1<24 && (p1 >= 1) ){
    //code for moving paddle up
    p1 = p1-1;
    //test
    display_pixel(100,20);
    display_update();

    printpaddle(p1,1);
   }
    else if (a == 1 && p1<24 && (p1 >= 1) ){
        //code for moving paddle down  
        p1 = p1+1;

            //test 2
    display_pixel(110,15);
    display_update();
    

        printpaddle(p1,1);
    }
    else if (a == 2 && p2<24 && (p2 >= 1) ){
        p2 = p2-1;

                    //test 3
    display_pixel(80,27);
    display_update();

        printpaddle(p2,2);
        }
    else if (a == 3 && p2<24 && (p2 >= 1) ){
        p2 = p2+1;
         //test 3
    display_pixel(40,18);
    display_update();

        printpaddle(p2,2);
  }
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
