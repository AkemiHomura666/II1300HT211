#include <stdint.h>   /* Declarations of uint_32 and the like */
#include "pic32mx.h"  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */
#include "fontheader.h"
void nameselect(int selection){
    int a = 33;
    int b = 33;
    int c = 33;
    int change_a = 0;
    int change_b = 0;
    int change_c =0;
    if (selection == 0){
        if(x == 25){
            int i;
            for (i=0; i < 8;i++){
                delete_hex(x + i, 1);
                display_hex(x + i, 1 ,dank_font[a + change_a][i]);
                display_update();
            }
        change_a ++;
        }
        if(x == 33){
            int i;
            for (i=0; i < 8;i++){
                delete_hex(x + i, 1 );
                display_hex(x + i, 1 ,dank_font[b + change_b][i]);
                display_update();
            }
        change_b ++;
        }
        if(x == 41){
            int i;
            for (i=0; i < 8;i++){
                delete_hex(x + i, 1 );
                display_hex(x + i, 1 ,dank_font[c + change_c][i]);
                display_update();
            }
        change_c ++;
        }
        
    }
    if (selection == 1){
        if(x == 25){
            int i;
            for (i=0; i < 8;i++){
                delete_hex(x + i, 1);
                display_hex(x + i, 1 ,dank_font[a + change_a][i]);
                display_update();
            }
        change_a --;
        }
        if(x == 33){
            int i;
            for (i=0; i < 8;i++){
                delete_hex(x + i, 1 );
                display_hex(x + i, 1 ,dank_font[b + change_b][i]);
                display_update();
            }
        change_b --;
        }
        if(x == 41){
            int i;
            for (i=0; i < 8;i++){
                delete_hex(x + i, 1 );
                display_hex(x + i, 1 ,dank_font[c + change_c][i]);
                display_update();
            }
        change_c --;
        }
    }
    if (selection == 2){
        highscorer[3][5][8];
        x = x + 8;
    }
}