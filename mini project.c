#include <reg51.h>   // Header file for 8051

// Push button connected to INT0 (P3.2)
sbit BUTTON = P3^2;

void delay_ms(unsigned int ms);

// ---------- INTERRUPT FUNCTION ----------
void external_interrupt0(void) interrupt 0
{
    P2 = ~P2;      // TOGGLE all LEDs when button is pressed
}

// ------------------ MAIN ----------------
void main()
{
   // P1 = 0x10;    // Port 1 as INPUT (switches)
    P2 = 0x00;     // Port 2 as OUTPUT (LEDs)

    IT0 = 1;       // INT0 as edge-triggered
    EX0 = 1;       // Enable external interrupt 0
    EA  = 1;       // Enable global interrupt

    while(1)
    {
        P2 = P1;   // Switch input ? LED output
    }
}

// ------------------- DELAY FUNCTION ------------------------
void delay_ms(unsigned int ms)
{
    unsigned int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 200000; j++);
}


