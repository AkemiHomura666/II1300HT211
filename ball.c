#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

int ball_speed_x = 30;
int ball_speed_y = 10;
void ball(int x, int y){
    display_pixel(x,y);
    display_pixel(x+1,y);
    display_pixel(x,y+1);
    display_pixel(x-1,y);
    display_pixel(x,y-1);
}

void horizontal_direction_change(int x){
    ball_speed_x = -1 * ball_speed_x;
}

void verticle_direction_change(int x){
    ball_speed_y = -1 * ball_speed_y;
}

void ball_hit_paddle(int x, int y){
    
}