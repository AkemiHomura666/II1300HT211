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

void erase(void)
{
  int i = 0;
  int y = 0;
  for (i = 0; i< 128; i++){ 
    for (y = 0; y< 8; y++){
      display_pixel(i,y);
    }
  }
  display_update();
}

//checks if buttons are pressed and acts accordingly
void whataboutbuttons(void){
  mode = 0;
  level = getsw();
  //check button 4
    if ((getbtns() & 8) == 8){
      if (mode == 0){
        erase();
       // moveLetter(0);
      }
      else if (mode == 1){
        movePaddle(0);
      }
  }
  //check button 3
   else if ((getbtns() & 4) == 4){
      if (mode == 0){
        
       // moveLetter(1);
      }
      else if (mode == 1){
        movePaddle(1);
      }
  }
  else if ((getbtns() & 2) == 2){
      if (mode == 0){
        erase();
       // moveLetter(1);
      }
      else if (mode == 1){
        movePaddle(2);
      }
  } 
    else if ((getbtns() & 1) == 1){
      if (mode == 0){
       // moveLetter(1);

      }
      else if (mode == 1){
        movePaddle(3);
      }
  } 
}



//old what about buttons:

/* void whataboutbuttons(void){
  mode = 1;
  level = getsw();
  //check button 4
    if ((getbtns() & 4) == 4){
      if (mode == 0){
       // moveLetter(0);
      }
      else if (mode == 1){
        movePaddle(0);
      }
  }
  //check button 3
   if ((getbtns() & 2) == 2){
      if (mode == 0){
       // moveLetter(1);
      }
      else if (mode == 1){
        movePaddle(1);
      }
  }
  if ((getbtns() & 1) == 1){
      if (mode == 0){
       // moveLetter(1);
      }
      else if (mode == 1){
        movePaddle(3);
      }
  } 
} */













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