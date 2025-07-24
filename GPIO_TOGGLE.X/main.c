#include "config.h"
#define CLOCK_RATE 16250000/10//hz
// estimate 6-10 ticks use in while(1)
int main(void)
{
    TRISHbits.TRISH0 = 0;
    int tick_count = 0;
    TRISJbits.TRISJ3 = 0; // Set pin H1 as output
    while(1)
    {
        tick_count++;
        if(tick_count >= CLOCK_RATE)
        {
            LATHbits.LATH0 ^= 1; // Toggle pin H0
            LATJbits.LATJ3 ^= 1; // Toggle pin J1
            tick_count = 0; // Reset tick count
        }
    }
}