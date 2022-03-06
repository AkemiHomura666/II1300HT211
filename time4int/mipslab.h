/* mipslab.h
   Header file for all labs.
   This file written 2015 by F Lundevall
   Some parts are original code written by Axel Isaksson

   Latest update 2015-08-28 by F Lundevall

   For copyright and licensing, see file COPYING */

/* Declare display-related functions from mipslabfunc.c */
void display_image(int x, const uint8_t *data);
void display_init(void);
void display_string(int line, char *s);
void display_update(void);
void spi_send_recv(uint8_t data);
void reset_string(void);
/* Declare lab-related functions from mipslabfunc.c */
char * itoaconv( int num );
void labwork(void);
int nextprime( int inval );
void quicksleep(int cyc);
void tick( unsigned int * timep );

/* Declare display_debug - a function to help debugging.

   After calling display_debug,
   the two middle lines of the display show
   an address and its current contents.

   There's one parameter: the address to read and display.

   Note: When you use this function, you should comment out any
   repeated calls to display_image; display_image overwrites
   about half of the digits shown by display_debug.
*/
void display_debug( volatile int * const addr );

/* Declare bitmap array containing font */
extern const uint8_t const font[128*8];
/* Declare bitmap array containing icon */
extern const uint8_t const icon[128];
/* Declare text buffer for display output */
extern char textbuffer[4][16];

/* Declare functions written by students.
   Note: Since we declare these functions here,
   students must define their functions with the exact types
   specified in the laboratory instructions. */
/* Written as part of asm lab: delay, time2string */
void delay(int);
void time2string( char *, int );
/* Written as part of i/o lab: getbtns, getsw, enable_interrupt */
int getbtns(void);
int getsw(void);
void enable_interrupt(void);
void paddle(int);
void updatePonging(void);
void whataboutintersect(void);
void whataboutball(void);
void ball(int, int);
void goal(int);
void display_hs(uint8_t[5][5]);
void resetponging(void);
void updateMenu(void);
void moveMenu(int);
void check_hit(void);
void game_over(void);
void displayscore(void);
void clear_buffer(void);
void nameselect(int);
void display_hex(int x, int linje, int invalue);
void delete_hex(int x, int linje);

int mode;
int score[2];
int level;
int menuselection;
uint8_t highscorename[5][5];
int highscorer1[5][8];
int highscorer2[5][8];
int highscorer3[5][8];
int p1;
int p2;
float ballposition_x;
float ballposition_y;
float ball_speed_x;
float ball_speed_y;
int aiON;
