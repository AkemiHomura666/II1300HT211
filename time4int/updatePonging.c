#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

void printpaddle(int y, int p){
    int i=0;
    if (p==1)
    {
            delete_pixel(0,y-1);
            delete_pixel(1,y-1);
            delete_pixel(0,y+9);
            delete_pixel(1,y+9);
        for (i = 0; i< 9; i++){
            display_pixel(0,y+i);
            display_pixel(1,y+i);
        }
    }

    else if (p==2){
            delete_pixel(126,y-1);
            delete_pixel(127,y-1);
            delete_pixel(126,y+9);
            delete_pixel(127,y+9);
        for (i = 0; i< 9; i++){
            display_pixel(126,y+i);
            display_pixel(127,y+i);
        }
            }
    else if (p==3){
            delete_pixel(0,y-1);
            delete_pixel(1,y-1);
            delete_pixel(0,y+9);
            delete_pixel(1,y+9);
            for (i = 0; i< 9; i++){
            display_pixel(126,y+i);
            display_pixel(127,y+i);
        }
            delete_pixel(126,y-1);
            delete_pixel(127,y-1);
            delete_pixel(126,y+9);
            delete_pixel(127,y+9);
            for (i = 0; i< 9; i++){
            display_pixel(0,y+i);
            display_pixel(1,y+i);
        }
    }
        display_update();
    quicksleep(1000000/level);
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
    if ((a == 1) && (p1<23)){
        //code for moving paddle down  
        p1 = p1+1;
        printpaddle(p1,1);
    }
    if (a == 2 && (p2 >= 1)){
        //code for moving paddle 2 up
        p2 = p2-1;

        printpaddle(p2,2);
        }
    if ((a == 3) && (p2<23)){
        //code for moving paddle 2 down
        p2 = p2+1;
        printpaddle(p2,2);
  }
  return;
}

void updatePonging(void){
			while (1){
                whataboutbuttons();
                whataboutintersect();
                whataboutball();
            }
}


void whataboutintersect(void){
    // kod för direction change på paddle
    check_hit();
    printpaddle(p1,3);
    printpaddle(p2,3);
    // kod för direction change på top / bottom
    game_over();
    //kod för goaaal
    return;
}

void whataboutball(void){
    // kod för ball position
    ball_moving();
    // kod för ball movement
    //
    return;
}

void goal(int scorer){
    score[scorer]++;
    ballposition_x = 64;
    ballposition_y = 16;
    ball_speed_x = 1;
    ball_speed_y = 1;
    p1 = 12;
    p2 = 12;
    clearPixels();
    updatePonging(); //?
}

void resetponging(void){
    score[0] = 0;
    score[1] = 0;
}