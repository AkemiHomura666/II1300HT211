#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

ballposition_x = 64;
ballposition_y = 16;
ball_speed_x = 1;
ball_speed_y = 1;



void horizontal_direction_change(void){
    ball_speed_x = -1 * ball_speed_x;
}

void verticle_direction_change(void){
    ball_speed_y = -1 * ball_speed_y;
}

void ball_hit_paddle1(void){
    if(ballposition_x = 1) {
        int i;
        for(i = p1; i< p1 + 9; i++){
            if(ballposition_y = i){
               horizontal_direction_change();
            }
        }
        printpaddle(p2,3);
    }

void ball_hit_paddle2(void){
    if(ballposition_x = 126) {
        int i;
        for(i = p2; i< p2 + 9; i++){
            if(ballposition_y = i){
               horizontal_direction_change();
            }
        }
        printpaddle(p2,3);
        
    } 

void ball_hit_side(void){ 
    if (ballposition_y = 0){
        verticle_direction_change();
    }
    if (ballposition_y = 31){
        verticle_direction_change();
    }
}

void game_over(void){
    if (ball_position_x = 0){
        goal(0);
    }
    if (ball_position_x = 127){
        goal(1);
    }
}

void ball_moving(void){
    delete_pixel(ballposition_x, ballposition_y);
    delete_pixel(ballposition_x, ballposition_y);
    display_pixel(ballposition_x + ball_speed_x,ballposition_y + ball_speed_y);
    display_pixel(ballposition_x + 1 + ball_speed_x,ballposition_y + ball_speed_y);
    display_pixel(ballposition_x + ball_speed_x,ballposition_y+ 1 + ball_speed_y);
    display_pixel(ballposition_x - 1 + ball_speed_x,ballposition_y + ball_speed_y);
    display_pixel(ballposition_x + ball_speed_x,ballposition_y - 1 + ball_speed_y);    
    ballposition_x = ballposition_x + + ball_speed_x;
    ballposition_y = ballposition_y + + ball_speed_y;
    ball_hit_paddle1();
    ball_hit_paddle2();
    ball_hit_side();
    game_over();
}