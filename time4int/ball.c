#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */


void horizontal_direction_change(void){
    ball_speed_x = -1 * ball_speed_x;
    if (ballposition_y >= (p1 + 4)){
        ball_speed_y = ball_speed_y + (ballposition_y - (p1 + 4));
    }
    else if (ballposition_y < (p1 + 4)){
        ball_speed_y = ball_speed_y - ((p1 + 4) - ballposition_y);
    }
    else if (ballposition_y >= (p2 + 4)){
        ball_speed_y = ball_speed_y + (ballposition_y - (p2 + 4));
    }    
    else if (ballposition_y < (p2 + 4)){
        ball_speed_y = ball_speed_y - ((p2 + 4) -  ballposition_y);
    }
}

void verticle_direction_change(void){
    ball_speed_y = -1 * ball_speed_y;
}


void game_over(void){
    if (ballposition_x <= 0){
        goal(0);
    }
    if (ballposition_x >= 127){
        goal(1);
    }
    return;
}

void ball_hit_paddle1(void){
    if(ballposition_x <= 1 && ballposition_x >0) {
            if(ballposition_y > (p1 - 1) && ballposition_y <(p1 + 9)){
               horizontal_direction_change();
            }
        }
        return;
    }
    
void ball_hit_paddle2(void){
    if(ballposition_x >= 126 && ballposition_x <127) {
        if(ballposition_y >(p2 - 1)  && ballposition_y <(p2 + 9)){
               horizontal_direction_change();
            }
        }
           return;
    } 
 
void ball_hit_side(void){ 
    if (ballposition_y <= 0){
        verticle_direction_change();
    }
    if (ballposition_y >= 31){
        verticle_direction_change();
    }
    return;
}

void check_hit(void){
    ball_hit_paddle1();
    ball_hit_paddle2();
    ball_hit_side();
}

void robot(void){
    int ai_x = ballposition_x;
    int ai_y = ballposition_y;
/*     if(ai_x >= 64){ */
        printpaddle(p2,2);
        if((ai_y - 4 < p2)&& (p2 >= 0)){
            p2--;
        }
        if((ai_y - 4 > p2)&&(p2 <= 23)){
            p2++;
        }
/*     } 
    if(ai_x <= 63){
        if(12 <= p2){
            p2--;
        }
        if(12 > p2){
            p2++;
        }    
    } */
}


void ball_moving(void){
    int ball_x = ballposition_x;
    int ball_y = ballposition_y;
    int spd_x = ball_speed_x;
    int spd_y = ball_speed_y;
    delete_pixel(ball_x ,ball_y);
    delete_pixel(ball_x + 1,ball_y);
    delete_pixel(ball_x,ball_y+ 1);
    delete_pixel(ball_x - 1,ball_y);
    delete_pixel(ball_x,ball_y - 1);
    display_pixel(ball_x + spd_x,ball_y + spd_y);
    display_pixel(ball_x + 1 + spd_x,ball_y + spd_y);
    display_pixel(ball_x + spd_x,ball_y+ 1 + spd_y);
    display_pixel(ball_x - 1 + spd_x,ball_y + spd_y);
    display_pixel(ball_x + spd_x,ball_y - 1 + spd_y);
    if (aiON==1){
        robot();
    }
    if(ball_x < 3){
        printpaddle(p1,1);
    }
    if(ball_x > 124){
        printpaddle(p2,2);
    }
    display_update();
    quicksleep(1000000/level);
    ballposition_x = ballposition_x + ball_speed_x;
    ballposition_y = ballposition_y + ball_speed_y;
    }



