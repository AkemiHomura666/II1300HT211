#include <stdint.h>   /* Declarations of uint_32 and the like */
#include "pic32mx.h"  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */
#include "fontheader.h"
void nameselect(int selection){
    //char name[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char name[26] = "ABCDEFGHIJKLMNOPQRSTUVXYZ";
    int i;
    int j;
    reset_string();
    text_update();
    display_string(0, "CHOOSE NAME");
    for (i = 0; i < 4; i++){
       if (namechecker[i] == 0){ 
            nameselected = i;
            if (selection == 0){
                display_init();
                display_char(2, &name[change_a]);
                text_update();
                display_init();
                change_a ++;
                quicksleep(100000);
            }
            if (selection == 1){
                
                text_update();
                display_init();
                display_char(2, &name[change_a]);
                text_update();
                display_init();
                change_a --;
                quicksleep(100000);
            }
            if (selection == 2){
                namebuffer[i][2 + j] = name[change_a];
                change_a = 0;
                j++;
                if(j == 3){
                    namechecker[i] = 1;
                    quicksleep(100000);
                playerselected = 1;
                mode = 1;
                }
                
            }    


    }
    }
}


  /*   int a = 33;
    int b = 33;
    int c = 33;
    if (selection == 0){
        if(firstletter == 25){
            int i;
            for (i=0; i < 8;i++){
                delete_hex(firstletter + i, 1);
                display_hex(firstletter + i, 1 ,dank_font[a + change_a][i]);
                display_update();
            }
        change_a ++;
        }
        if(firstletter == 33){
            int i;
            for (i=0; i < 8;i++){
                delete_hex(firstletter + i, 1 );
                display_hex(firstletter + i, 1 ,dank_font[b + change_b][i]);
                display_update();
            }
        change_b ++;
        }
        if(firstletter == 41){
            int i;
            for (i=0; i < 8;i++){
                delete_hex(firstletter + i, 1 );
                display_hex(firstletter + i, 1 ,dank_font[c + change_c][i]);
                display_update();
            }
        change_c ++;
        }
        
    }
    if (selection == 1){
        if(firstletter == 25){
            int i;
            for (i=0; i < 8;i++){
                delete_hex(firstletter + i, 1);
                display_hex(firstletter + i, 1 ,dank_font[a + change_a][i]);
                display_update();
            }
        change_a --;
        }
        if(firstletter == 33){
            int i;
            for (i=0; i < 8;i++){
                delete_hex(firstletter + i, 1 );
                display_hex(firstletter + i, 1 ,dank_font[b + change_b][i]);
                display_update();
            }
        change_b --;
        }
        if(firstletter == 41){
            int i;
            for (i=0; i < 8;i++){
                delete_hex(firstletter + i, 1 );
                display_hex(firstletter + i, 1 ,dank_font[c + change_c][i]);
                display_update();
            }
        change_c --;
        }
    }
    if (selection == 2){
        //highscorer[3][5][8];
        firstletter = firstletter + 8;
    } */
