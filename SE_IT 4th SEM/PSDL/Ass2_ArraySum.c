//Assignment 2-Dhiraj23361

#include<pic18f458.h>
#include<stdlib.h>
#include<stdio.h>
#include<xc.h>


void main(void){
   int a[100];
   int sum=0;
   for(int i=0;i<10;i++){
       a[i]=2;
       sum+=a[i];
    }   
    TMR0=sum;
    return;
}
