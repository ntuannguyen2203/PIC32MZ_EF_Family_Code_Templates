#include "config.h"
#include <proc/p32mz2048efm144.h>
#include <p32xxxx.h>
#define SYSTEM_CLOCK 200000000 // 200 MHz
#define PB_CLOCK (SYSTEM_CLOCK/2)
#include <unistd.h>
#include <stdio.h>
#include <sys/attribs.h>
#define BUFFER_SIZE 255
char receivedData[BUFFER_SIZE];
int index_char = 0;
long _sys_ticks = 0;
long pre_sys_ticks = 0;
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
    U2MODEbits.STSEL = 0; //1 stop bit       
        
    U2STAbits.URXEN = 1; //enable receiver
    U2STAbits.UTXEN = 1; //enable transmitter    

    IEC4bits.U2RXIE =1; //enable uart2 rx interrupt 
    IPC36bits.U2RXIP = 1; //priority 1 (1~7)
    IPC36bits.U2RXIS = 0; //sub-priority 0 (0~3)
    U2STAbits.URXISEL =0 ;

    IFS4bits.U2RXIF = 0; //clear flag
    U2BRG = PB_CLOCK/(4*115200)-1; 

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
char receivedChar;
void __ISR(_UART2_RX_VECTOR, IPL1SRS) UART2_RX_ISR(void)
{
    LATHbits.LATH0 = !LATHbits.LATH0; // Toggle LED for debugging
    receivedChar = U2RXREG;
    if (index_char < BUFFER_SIZE - 1) {
        receivedData[index_char++] = receivedChar;
    }
    if (receivedChar == '\r' || receivedChar == '\n' || index_char >= BUFFER_SIZE - 1) {
        receivedData[index_char] = '\0'; // Null-terminate the string
        UART_Write("\n\rYou entered: ");
        UART_Write(receivedData);
        UART_Write("\n\rEnter a message: \n\r");
        index_char = 0; // Reset index for next message
    }

    IFS4bits.U2RXIF = 0;
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
    WDTCONbits.ON = 0;


    __builtin_disable_interrupts(); //disable interrupts
    // led config
    TRISHbits.TRISH0 = 0; 
    LATHbits.LATH0 = 1; 
    TRISHbits.TRISH1 = 0;
    // uart IO config
    TRISGbits.TRISG6 = 1;
    U2RXR = 1; //G6
    TRISBbits.TRISB14 = 0;
    RPB14R =2;//tx
    PMD5bits.U2MD =0;

    UART_Config(); 
    __builtin_enable_interrupts();   // enable interrupts
    UART_Write("UART2 Initialized\n\r");
    printf("RCON = 0x%X\n", RCON);
    // Print reset reason
    printResetReasons();

    UART_Write("Hello ntuannguyen2203\n\r");
    printf("Hello %s from printf\n\r", "ntuannguyen2203");

    UART_Write("Enter a message: \n\r");


    while (1) {

    }
    return 0;
}