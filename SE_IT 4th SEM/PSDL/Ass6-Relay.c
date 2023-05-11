//Assignment 6-Dhiraj23361

#include<pic18f4550.h>

void __interrupt() int1_isr()
{
    if(INTCON3bits.INT1IF == 1)
    {
        INTCONbits.GIE = 0;
        PORTAbits.RA4 = 1;
        for(int  i = 0;i<0;i++)
        {
            for(int j = 0;j<0;j++)
            {
             
            }
        }
        PORTAbits.RA4 = 0;
        INTCON3bits.INT1IF=0;
        INTCONbits.GIE=1;
    }
    
}


void main(void) 
{
    TRISBbits.TRISB1 =1;
    TRISAbits.TRISA4 = 0;
    PORTAbits.RA4 = 0;
    INTCON2bits.INTEDG1 = 1;
    INTCON3bits.INT1IF = 0;
    INTCON3bits.INT1IE = 1;
   
   
    INTCONbits.PEIE = 1;
    INTCONbits.GIE = 1;
 
    while(1);
     
    
    return;
}
