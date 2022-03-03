#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

int ballposition_x = 64;
int ballposition_y = 16;
int ball_speed_x = 30;
int ball_speed_y = 10;

void ball(int x, int y){
    display_pixel(x,y);
    display_pixel(x+1,y);
    display_pixel(x,y+1);
    display_pixel(x-1,y);
    display_pixel(x,y-1);
    ballposition_x = x;
    ballposition_y = y;
}

void horizontal_direction_change(void){
    ball_speed_x = -1 * ball_speed_x;
}

void verticle_direction_change(void){
    ball_speed_y = -1 * ball_speed_y;
}

void ball_hit_paddle1(p1){
    if(ballposition_x = 1) {
        int i;
        for(i = p1; i< p1 + 9; i++){
            if(ballposition_y = i){
               horizontal_direction_change();
            }
        }
    }

void ball_hit_paddle2(p2){
    if(ballposition_x = 126) {
        int i;
        for(i = p2; i< p2 + 9; i++){
            if(ballposition_y = i){
               horizontal_direction_change();
            }
        }
    }    