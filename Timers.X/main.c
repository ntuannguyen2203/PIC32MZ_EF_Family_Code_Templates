#include "config.h"
#include <proc/p32mz2048efm144.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/attribs.h>
void delay(uint32_t time)
{
    while(time--);
}
int counter =0;
void __ISR(_TIMER_1_VECTOR, IPL7AUTO) TIM1_ISR(void) {
    //call back every 2 seconds
    //   LATHbits.LATH1 ^=1;
    LATHbits.LATH0 ^=1;
    LATHbits.LATH1 ^=1;
    LATJbits.LATJ3 ^=1;
    IFS0bits.T1IF = 0; //clear flag
    counter++;
}
void config_GPIO(void)
{
    // Configure GPIO pins
    TRISHbits.TRISH0 = 0; // Set pin H0 as output
    LATHbits.LATH0 = 0;   // Initialize pin H0 to low
    TRISHbits.TRISH1 = 0; // Set pin H1 as output
    LATHbits.LATH1 = 0;   // Initialize pin H1 to low
    TRISHbits.TRISH2 = 0; // Set pin H2 as output
    LATHbits.LATH2 = 1;   // Initialize pin H2 to high
    TRISJbits.TRISJ3 = 0; // Set pin J3 as output
}
void config_Timer1(void)
{
    T1CONbits.ON = 0; //timer is disabled
    T1CONbits.TCS = 0; //internal PBCLK source
    T1CONbits.TCKPS = 3;   
    // 11 = 1:256 prescale value
    // 10 = 1:64 prescale value
    // 01 = 1:8 prescale value
    // 00 = 1:1 prescale value`
    TMR1 = 0; //clear timer1    
    PR1 = 63476; //PR1 = 12499, 1kHz Timer     
    IPC1bits.T1IP = 7; //priority 7
    IFS0bits.T1IF = 0; //clear flag
    IEC0bits.T1IE = 1; //enable interrupt    
}
int main(void)
{
    config_GPIO();
    config_Timer1();

   __builtin_disable_interrupts(); //disable interrupts
    config_Timer1(); //configure Timer1   
    T1CONbits.ON = 1; //timer is enabled
    PMD4 &=0;
    __builtin_enable_interrupts();   // disable interrupts

    printf("Hello");

    while(1)
    {


    }

    return 0;
}