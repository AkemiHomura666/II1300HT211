/* mipslabwork.c

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

//checks if buttons are pressed and acts accordingly
void whataboutbuttons(void){
  int swbtns = (getbtns() >> 1);
  int sw = getsw();
    if ((getbtns() & 4) == 4){
      if (mode == 0){
        moveMenu(0);
      }
      else if (mode == 1){
        movePaddle(0);
      }
  }
   if ((getbtns() & 2) == 2){
      if (mode == 0){
        moveMenu(1);
      }
      else if (mode == 1){
        movePaddle(1);
      }
  }

/*     if ((getbtns() & 1) == 1){
      mytime = ((mytime & 65295) | (sw << 4));
    printf("knapp 3 är tryckt%d", mytime);
  } */
  return 0;
}

//activated  by whataboutbuttons to move paddle up or down
void movePaddle(int a){
  if (a == 0){
    //code for moving paddle up
  }
  else if (a == 1){
    //code for moving paddle down  
}
  else {
    return 0;
  }
  }
}
