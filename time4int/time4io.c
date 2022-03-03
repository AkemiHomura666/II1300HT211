#include <stdint.h> 
#include <pic32mx.h> 
#include "mipslab.h"
int getsw( void ){
    int sw = (PORTD >> 8) & 0xf;
    return sw;
};

int getbtns(void){
    int btns = (((PORTD >> 5) & 0x7) << 1)|((PORTF >> 1) & 0x1);
    //int btns = (((PORTD >> 5) & 0x7)<< 1)|(PORTF  & 0x1);
    return btns;
}
