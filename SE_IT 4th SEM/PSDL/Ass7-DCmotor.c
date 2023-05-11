//Assignment 7-Dhiraj23361

#include<pic18f4550.h>

void main(void)
{
    unsigned int i;
   
    TRISCbits.TRISC2    = 0;            //CCP1 pin as output
   
    CCP1CON  =   0b00011100;            //Select PWM mode; Duty cycle LSB CCP1CON<4:5> = <1:1>
   
    T2CON   =   0b00000010;             //Prescalar = 16; Timer2 OFF
    GIE=1; //Global Interrupt Enable
    TRISAbits.TRISA4=0; //PORTA pin4 as output
    while(1)
    {
        TMR2=0;
        PR2     =   250;   //0x95;  
        CCPR1L   =   2;    //0x0F;      //Duty cycle 10%
       
        TMR2IF=0;
        TMR2ON = 1;                     //Timer2 ON
        for(int i=2;i<255;i+=50)
        {
            CCPR1L=i; //For Decreasing the speed  
            for(int j=0;j<1000;j++)
                for(int k=0;k<10000;k++);
                PORTAbits.RA4=~PORTAbits.RA4;
        }
    }
}