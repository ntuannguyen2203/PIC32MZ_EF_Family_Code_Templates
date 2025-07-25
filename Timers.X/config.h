// // DEVCFG3
// // #pragma config USERID = 0xFFFF          // Enter Hexadecimal value (Enter Hexadecimal value)
// // #pragma config FMIIEN = ON              // Ethernet RMII/MII Enable (MII Enabled)
// // #pragma config FETHIO = ON              // Ethernet I/O Pin Select (Default Ethernet I/O)
// // #pragma config PGL1WAY = ON             // Permission Group Lock One Way Configuration (Allow only one reconfiguration)
// // #pragma config PMDL1WAY = ON            // Peripheral Module Disable Configuration (Allow only one reconfiguration)
// // #pragma config IOL1WAY = ON             // Peripheral Pin Select Configuration (Allow only one reconfiguration)
// // #pragma config FUSBIDIO = ON            // USB USBID Selection (Controlled by the USB Module)

// // DEVCFG2
// #pragma config FPLLIDIV = DIV_1         // System PLL Input Divider (3x Divider)
// #pragma config FPLLRNG = RANGE_5_10_MHZ // System PLL Input Range (5-10 MHz Input)
// #pragma config FPLLICLK = PLL_FRC      // System PLL Input Clock Selection (POSC is input to the System PLL)
// #pragma config FPLLMULT = MUL_65        // System PLL Multiplier (PLL Multiply by 50)
// #pragma config FPLLODIV = DIV_4         // System PLL Output Clock Divider (2x Divider)
// // #pragma config UPLLFSEL = FREQ_24MHZ    // USB PLL Input Frequency Selection (USB PLL input is 24 MHz)

// // DEVCFG1
// #pragma config FNOSC = SPLL             // Oscillator Selection Bits (System PLL)
// // #pragma config DMTINTV = WIN_127_128    // DMT Count Window Interval (Window/Interval value is 127/128 counter value)
// #pragma config FSOSCEN = OFF             // Secondary Oscillator Enable (Enable SOSC)
// // #pragma config IESO = ON                // Internal/External Switch Over (Enabled)
// #pragma config POSCMOD = HS             // Primary Oscillator Configuration (HS osc mode)
// #pragma config OSCIOFNC = ON        // CLKO Output Signal Active on the OSCO Pin (Disabled)
// // #pragma config FCKSM = CSECME           // Clock Switching and Monitor Selection (Clock Switch Enabled, FSCM Enabled)
// // #pragma config WDTPS = PS1048576        // Watchdog Timer Postscaler (1:1048576)
// // #pragma config WDTSPGM = STOP           // Watchdog Timer Stop During Flash Programming (WDT stops during Flash programming)
// // #pragma config WINDIS = NORMAL          // Watchdog Timer Window Mode (Watchdog Timer is in non-Window mode)
// // #pragma config FWDTEN = OFF             // Watchdog Timer Enable (WDT Disabled)
// // #pragma config FWDTWINSZ = WINSZ_25     // Watchdog Timer Window Size (Window size is 25%)
// #pragma config DMTCNT = DMT31           // Deadman Timer Count Selection (2^31 (2147483648))
// // #pragma config FDMTEN = OFF             // Deadman Timer Enable (Deadman Timer is disabled)

// // DEVCFG0
// #pragma config DEBUG = ON              // Background Debugger Enable (Debugger is disabled)
// // #pragma config JTAGEN = OFF             // JTAG Enable (JTAG Disabled)
// // #pragma config ICESEL = ICS_PGx2        // ICE/ICD Comm Channel Select (Communicate on PGEC2/PGED2)
// // #pragma config TRCEN = ON               // Trace Enable (Trace features in the CPU are enabled)
// // #pragma config BOOTISA = MIPS32         // Boot ISA Selection (Boot code and Exception code is MIPS32)
// // #pragma config FECCCON = OFF_UNLOCKED   // Dynamic Flash ECC Configuration (ECC and Dynamic ECC are disabled (ECCCON bits are writable))
// // #pragma config FSLEEP = OFF             // Flash Sleep Mode (Flash is powered down when the device is in Sleep mode)
// // #pragma config DBGPER = PG_ALL          // Debug Mode CPU Access Permission (Allow CPU access to all permission regions)
// // #pragma config SMCLR = MCLR_NORM        // Soft Master Clear Enable bit (MCLR pin generates a normal system Reset)
// // #pragma config SOSCGAIN = GAIN_2X       // Secondary Oscillator Gain Control bits (2x gain setting)
// // #pragma config SOSCBOOST = ON           // Secondary Oscillator Boost Kick Start Enable bit (Boost the kick start of the oscillator)
// // #pragma config POSCGAIN = GAIN_2X       // Primary Oscillator Gain Control bits (2x gain setting)
// // #pragma config POSCBOOST = ON           // Primary Oscillator Boost Kick Start Enable bit (Boost the kick start of the oscillator)
// // #pragma config EJTAGBEN = NORMAL        // EJTAG Boot (Normal EJTAG functionality)

// // DEVCP0
// // #pragma config CP = OFF                 // Code Protect (Protection Disabled)

// // // SEQ3
// // #pragma config TSEQ = 0xFFFF            // Boot Flash True Sequence Number (Enter Hexadecimal value)
// // #pragma config CSEQ = 0xFFFF            // Boot Flash Complement Sequence Number (Enter Hexadecimal value)

// // #pragma config statements should precede project file includes.
// // Use project enums instead of #define for ON and OFF.

#include <xc.h>
/*** DEVCFG0 ***/
#pragma config DEBUG =      OFF
#pragma config JTAGEN =     OFF
#pragma config ICESEL =     ICS_PGx2
#pragma config TRCEN =      OFF
#pragma config BOOTISA =    MIPS32
#pragma config FECCCON =    OFF_UNLOCKED
#pragma config FSLEEP =     OFF
#pragma config DBGPER =     PG_ALL
#pragma config SMCLR =      MCLR_NORM
#pragma config SOSCGAIN =   GAIN_LEVEL_3
#pragma config SOSCBOOST =  ON
#pragma config POSCGAIN =   GAIN_LEVEL_3
#pragma config POSCBOOST =  ON
#pragma config EJTAGBEN =   NORMAL
#pragma config CP =         OFF

/*** DEVCFG1 ***/
#pragma config FNOSC =      SPLL
#pragma config DMTCNT =     DMT31
// #pragma config FDMTEN =     OFF

/*** DEVCFG2 ***/
#pragma config FPLLIDIV =   DIV_1
#pragma config FPLLRNG =    RANGE_5_10_MHZ
#pragma config FPLLICLK =   PLL_FRC
#pragma config FPLLMULT =   MUL_65
#pragma config FPLLODIV =   DIV_32
#pragma config UPLLFSEL =   FREQ_24MHZ

/*** DEVCFG3 ***/
// #pragma config USERID =     0xffff
// #pragma config FMIIEN =     ON
// #pragma config FETHIO =     ON
// #pragma config PGL1WAY =    ON
// #pragma config PMDL1WAY =   ON
// #pragma config IOL1WAY =    ON
// #pragma config FUSBIDIO =   ON
// #pragma FPBDIV  DIV_1
/*** BF1SEQ0 ***/

//#pragma config TSEQ =       0xffff
//#pragma config CSEQ =       0x0