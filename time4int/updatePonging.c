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
/*     else if (p==3){
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
    }*/
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
			while (mode == 1){
                whataboutbuttons();
                whataboutintersect();
                whataboutball();
                displayscore();
            }
}


void whataboutintersect(void){
    // kod för direction change på paddle
    check_hit();
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
    display_update();
    if (aiON==0 && (score[0]==5 || score[1]==5)){
        display_string(1, "GAME OVER!");
        if (score[1]==5){
            display_string(2, "Player 1 wins!");
        }
        else if (score[0]==5){
            display_string(2, "Player 2 wins!");
        }        
        text_update();
        quicksleep(30000000);
        resetponging();
        reset_string();
        display_init();
        mode = 0;
    }
    updatePonging();
}

void resetponging(void){
    score[0] = 0;
    score[1] = 0;
    display_init();
    quicksleep(20000000);
}

void displayscore(void){
    int i=0;
    int g;
    for (g = 0; g<score[1]; g++){
        display_hex(32+i, 1, 63);
        i=i+2;
        }
        i=0;
    for (g = 0; g<score[0]-1; g++){
        display_hex(95+i, 1, 63);
        i=i+2;
        }
}