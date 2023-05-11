//Assignment 4-Dhiraj23361

#include <xc.h>
#include<stdio.h>
#include<stdlib.h>
#include<pic18f4550.h>

void delay();

void main(void){
    TRISB = 0;

     while(1){
     PORTB=0x00;
     PORTBbits.RB0=1;
     delay();
     PORTBbits.RB0=0;
     PORTBbits.RB1=1;
     delay();
     PORTBbits.RB1=0;
     PORTBbits.RB2=1;
     delay();
     PORTBbits.RB2=0;
     PORTBbits.RB3=1;
     delay();
     PORTBbits.RB3=0;
     PORTBbits.RB4=1;
     delay();
     PORTBbits.RB4=0;
     PORTBbits.RB5=1;
     delay();
     PORTBbits.RB5=0;
     PORTBbits.RB6=1;
     delay();
     PORTBbits.RB6=0;
     PORTBbits.RB7=1;
     delay();
     PORTBbits.RB7=0;
     }
    return;
}



void delay(){
    T0CON = 0x7;
    TMR0 = 10;
    INTCONbits.TMR0IF=0;
    T0CONbits.TMR0ON=1;
    while(INTCONbits.TMR0IF!=1);
    INTCONbits.TMR0IF=0;
    T0CONbits.TMR0ON=0;
    return;
}

