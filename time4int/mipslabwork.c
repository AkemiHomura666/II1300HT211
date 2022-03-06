/* mipslabwork.c
1.0.0.1

   This file written 2015 by F Lundevall
   Updated 2017-04-21 by F Lundevall

   This file should be changed by YOU! So you must
   add comment(s) here with your name(s) and date(s):

   This file modified 2017-04-31 by Ture Teknolog 

   For copyright and licensing, see file COPYING */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include "pic32mx.h"  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

int counttimer = 0;
int mytime = 0x0;
int p1 = 12;
int p2 = 12;

//Lab code
char textstring[] = "text, more text, and even more text!";

/* Interrupt Service Routine */
void user_isr( void )
{
  return;
}

/* Lab-specific initialization goes here */
void labinit( void )
{
  volatile int *trise = (volatile int*) 0xbf886100;
  *trise &= ~0xff; /* Port E is used for the LED 
  Set bits 0 through 7 to 0 (output) */
  TRISD &= 0x0fe0;
  TRISF &= 0x2;

  T2CONCLR = 0x0;     // Stop timer and clear control register
  T2CONSET = 0x70;    // Set prescale to 1:256
  TMR2 = 0x0;         // Clear timer register
  PR2 = 0x7a12;       // Load period register
  IFSCLR(0)=0x100;
  T2CONSET = 0x8000;
  return;
}

//delay + swag
void ledupdate(void)
{
  volatile int *porte = (volatile int*) 0xbf886110;
  volatile int *LED = (volatile int*) 0xbf886110; 
  //delay( 1000 );

if ((IFS(0) & 0x100)){
counttimer++;
IFSCLR(0) = 0x100;
}
if (counttimer == 10){
  tick( &mytime );
  *LED = *LED + 1;
  counttimer = 0;
}
}

/* This function is called repetitively from the main program */
void labwork( void )
{
// print text
//time2string( textstring, mytime );
//display_string( 3, textstring );
//display_update();
//display_image(96, icon);
}
//Checks if buttons are pressed and acts accordingly
void whataboutbuttons(void){
  //level set by switches
  if (!getsw ==0){
    level = getsw();
  }
  else level = 1;
  //check button 4
    if ((getbtns() & 8) == 8){
      if (mode == 0){
       // moveLetter(0);
       //selects first menu item
       moveMenu(0);
       return;
      }
      else if (mode == 1){
        movePaddle(0);
      }
      else if (mode == 2){
        nameselect(0);
      }
  }
  //check button 3
   if ((getbtns() & 4) == 4){
      if (mode == 0){
       // moveLetter(1);
       //moves menu selection upwards
       moveMenu(1);
       quicksleep(10000000);
       return;
      }
      else if (mode == 1){
        movePaddle(1);
      }
      else if (mode == 2){
        nameselect(1);
      }

  }
  //check button 2
  if ((getbtns() & 2) == 2){
      if (mode == 0){
       // moveLetter(1);
      //enters menu selection
       moveMenu(2);
       quicksleep(10000000);
       return;
      }
      else if (mode == 1){
        movePaddle(2);
      }
      else if (mode == 2){
        nameselect(2);
      }
  } 
  //check button 1
    if ((getbtns() & 1) == 1){
      if (mode == 0){        
       // moveLetter(1);

      }
      else if (mode == 1){
        movePaddle(3);
      }
  } 
}
// Generates menu graphics
void updateMenu(void){
  display_string(0, "      MENU");
  display_string(1, "1 PLAY");
  display_string(2, "2 HIGHSCORE");
  if (aiON==1){
    display_string(3, "3 MODE: AI");
  }
  else if (aiON==0){
  display_string(3, "3 MODE: 2PLAYER");
  }
  else {
    display_string(3, "ERROR aiON==?");
  }
  text_update();
}
// Menu functions
void moveMenu(int selection){
  if (selection == 0)
  {
  //select PLAY
  resetponging();
  mode = 1;
  p1 = 12;
  p2 = 12;
	printpaddle(p1,1);
	printpaddle(p2,2);
  }
  else if (selection == 1)
  {
    //select highscore
    mode = 3;
    return;
    
  }
  else if (selection == 2)
  {
    //select game mode change
    clearPixels();
    if (aiON==1){
      aiON=0;
      updateMenu();
      
    }
    else if (aiON==0){
      aiON=1;
      updateMenu();
    }
  }
}


/* void moveLetter(int input){
  
  switch (input)
// if 
  case 0:
  letterselector++
  int i;
  for (i = 0; i<60; i++){

  }
  break;
  case 1:
  int i;
  for (i = 0; i<60; i++){

  }
  break;
} */