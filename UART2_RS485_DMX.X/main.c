#include "config.h"
#include <proc/p32mz2048efm144.h>
#include <p32xxxx.h>
#define SYSTEM_CLOCK 200000000 // 200 MHz
#define PB_CLOCK (SYSTEM_CLOCK/2)
#include <unistd.h>
#include <stdio.h>
#include <sys/attribs.h>
#define BUFFER_SIZE 255
uint8_t DMX_BREAK_FLAG = 0, SW_COLOR_FLAG = 0;
uint16_t dmx_ticks, dmx_pre_ticks;
static uint16_t switch_color= 0;
int _write(int file, const void *ptr, size_t len)
{
    // for use printf
    const char* data = (const char*) ptr;
    for (size_t i = 0; i < len; i++) {
        while (U2STAbits.UTXBF);   
        U2TXREG = data[i];         
    }
    return len;
}

void UART_Config(void)
{
    U2MODEbits.ON = 0; // disable UART2
    U2MODE = 0; // Clear the mode register

    U2STA = 0; // Clear the status register

    U2MODEbits.BRGH = 1; //high speed mode
    U2MODEbits.PDSEL = 0; //8bit no parity
    U2MODEbits.STSEL = 1; //2 stop bit       
        
    U2STAbits.UTXEN = 1; //enable transmitter    




    U2BRG = PB_CLOCK/(4*250000)-1; 

    U2MODEbits.ON = 1; // Enable UART2
}


void UART_Write(const char* string)
{
    while (*string != '\0') {
        while (U2STAbits.UTXBF); // Wait until the transmit buffer is not full
        U2TXREG = *string; // Transmit the character
        ++string; // Move to the next character
    }
}

void printResetReasons(void) {
    __RCONbits_t RCONbits;

    // Assuming RCON is a volatile register that holds the reset reason
    RCONbits = *(volatile __RCONbits_t*)&RCON; // Read the RCON register into the structure

    // Print reset reasons based on the bits set in RCONbits
    printf("Reset Reasons:\n");
    if (RCONbits.POR)        printf(" - Power-on Reset\n");
    if (RCONbits.BOR)        printf(" - Brown-out Reset\n");
    if (RCONbits.IDLE)       printf(" - Idle Mode Reset\n");
    if (RCONbits.SLEEP)      printf(" - Sleep Mode Reset\n");
    if (RCONbits.WDTO)       printf(" - Watchdog Timer Reset\n");
    if (RCONbits.DMTO)       printf(" - Device Manager Timeout Reset\n");
    if (RCONbits.SWR)        printf(" - Software Reset\n");
    if (RCONbits.EXTR)       printf(" - External Reset\n");
    if (RCONbits.CMR)        printf(" - Configuration Mismatch Reset\n");
    if (RCONbits.BCFGFAIL)   printf(" - Boot Configuration Fail\n");
    if (RCONbits.BCFGERR)    printf(" - Boot Configuration Error\n");

    // Clear reset flags
    RCON = 0; // Clear the RCON register
}
void DMX_SendBreak(void) {
    U2STAbits.UTXEN = 0;        // Tắt TX
    RPB14R = 0;                 // Unmap UART2 TX khỏi RB14
    TRISBbits.TRISB14 = 0;      // RB14 output
    LATBbits.LATB14 = 0;        // Kéo xuống LOW
    dmx_pre_ticks = dmx_ticks;
    DMX_BREAK_FLAG = 1;

}
void UART2_SendByte(uint8_t data) {
    while(U2STAbits.UTXBF);   // Chờ buffer rảnh
    U2TXREG = data;
}
void DMX_SendPacket(uint8_t *data, uint16_t length) {
    uint16_t i;
    DMX_SendBreak();
    while (DMX_BREAK_FLAG)
    {
        /* code */
    }
    
    UART2_SendByte(0);        // Start code = 0
    for(i=0; i<length; i++) {
        UART2_SendByte(data[i]);
    }
}
void config_Timer1(void)
{
    T1CONbits.ON = 0; //timer is disabled
    T1CONbits.TCS = 0; //internal PBCLK source
    T1CONbits.TCKPS = 3;   // /256, 1 tick = 2.56us
    // 11 = 1:256 prescale value
    // 10 = 1:64 prescale value
    // 01 = 1:8 prescale value
    // 00 = 1:1 prescale value`
    TMR1 = 0; //clear timer1    
    PR1 = 70;   
    IPC1bits.T1IP = 7; //priority 7
    IFS0bits.T1IF = 0; //clear flag
    IEC0bits.T1IE = 1; //enable interrupt    
}

void __ISR(_TIMER_1_VECTOR, IPL7AUTO) TIM1_ISR(void) {
    //call back every 2 seconds

    switch_color++;
    //25000 for 5s
    if(switch_color == 10000)
    {
        SW_COLOR_FLAG = 1;
        switch_color = 0;


    } 


    LATJbits.LATJ3 ^=1;
    IFS0bits.T1IF = 0; //clear flag
    if (DMX_BREAK_FLAG) 
    {
        dmx_ticks++;
        if(dmx_ticks-dmx_pre_ticks>1)
        {
            LATBbits.LATB14 = 1;        // Mark After Break

        }
        if(dmx_ticks-dmx_pre_ticks>2)
        {
            RPB14R = 0b0010;            // Map lại UART2 TX ra RB14
            U2STAbits.UTXEN = 1;        // Bật lại TX
            DMX_BREAK_FLAG = 0;
        }
    }
 
}
int main(void)
{
    ANSELA = 0; //disable analog input
    ANSELB = 0;
    ANSELC = 0;
    ANSELD = 0;
    ANSELE = 0;
    ANSELF = 0;
    ANSELG = 0;
    ANSELH = 0;
    ANSELJ = 0;


    __builtin_disable_interrupts(); //disable interrupts
    config_Timer1();
    T1CONbits.ON = 1; //timer is enabled
    PMD4 &=0;
    // led config
    TRISHbits.TRISH0 = 0; 
    TRISHbits.TRISH1 = 0;
    TRISHbits.TRISH2 = 0;
    LATHbits.LATH0 = 0;
    LATHbits.LATH1 = 0;
    LATHbits.LATH2 = 1;
    // button
    TRISBbits.TRISB12 = 1;
    TRISBbits.TRISB13 = 1;

    // debug
    TRISJbits.TRISJ3 = 0; // Set pin J3 as output
    // uart IO config

    TRISBbits.TRISB14 = 0;
    RPB14R =2;//tx
    PMD5bits.U2MD =0;

    UART_Config(); 
    __builtin_enable_interrupts();   // enable interrupts

    // Print reset reason


    




    while (1) {
        static uint8_t B12_state,B13_state;
        static int color;
        // auto switching
        if(SW_COLOR_FLAG)
        {
            uint8_t dmxData[512] = {0};
            dmxData[color] = 0xFF;
            color++;
            DMX_SendPacket(dmxData,512);
            if(color>2) color = 0;
            SW_COLOR_FLAG =0;
        }

        // manual
        if( (PORTBbits.RB12 == 0)&&(B12_state==0) )
        {
            uint8_t dmxData[512] = {0};
            dmxData[color] = 0xFF;
            color++;
            DMX_SendPacket(dmxData,512);
            if(color>2) color = 0;

            LATHbits.LATH0 = 1;
            LATHbits.LATH1 = 0;
            LATHbits.LATH2 = 0;

            B12_state = 1;
        }
        else if( (PORTBbits.RB12 == 1)&&(B12_state==1) ) B12_state = 0;

        if( (PORTBbits.RB13 == 0)&&(B13_state==0) )
        {
            uint8_t dmxData[512] = {0};
            dmxData[color] = 0xFF;
            color--;
            DMX_SendPacket(dmxData,512);
            if(color<0) color = 2;
            LATHbits.LATH0 = 0;
            LATHbits.LATH1 = 1;
            LATHbits.LATH2 = 1;
            B13_state = 1;
        }
        else if( (PORTBbits.RB13 == 1)&&(B13_state==1) ) B13_state = 0;
    }
    return 0;
}