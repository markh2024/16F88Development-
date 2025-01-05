#include <xc.h>
#include "port_scan.h" // Include your custom header file

// CONFIG1
#pragma config FOSC = INTOSCCLK // Oscillator Selection bits (INTRC oscillator; CLKO function on RA6/OSC2/CLKO pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select bit (MCLR pin function is MCLR)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB3 is digital I/O)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// CONFIG2
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor enabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal External Switchover mode enabled)

void main() {
    // Disable analog inputs and comparators
    ANSEL = 0x00; // Set all pins to digital
    CMCON = 0x07; // Disable comparators

    // Configure PORTB as output
    TRISB = 0x00; // All pins on PORTB set as outputs

    // Configure oscillator for 2 MHz
    OSCCON = 0x62; // Set IRCF = 100 (2 MHz), SCS = 0 (Clock source selected by configuration)
    OSCTUNE = 0x00; // Default oscillator tuning
    
    const int delay = 100; // adjust for delay 

    // Initialize Timer0 for delay obtained from the header file 
    init_timer0();

    while (1) {
        scan_portb_pins(delay); // Call the function with a delay of 100ms
    }
}
