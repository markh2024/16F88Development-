
#include <xc.h>
#include <stdlib.h>
#include <stdio.h>

#define _XTAL_FREQ 2000000 // Define system clock frequency for delay calculations

// Global counter variable to track time
volatile unsigned int delay_counter = 0;

// Timer0 interrupt service routine (ISR) for delay
void __interrupt() ISR() {
    // Check if the interrupt is from Timer0
    if (INTCONbits.TMR0IF) {  // Use INTCONbits.TMR0IF for Timer0 interrupt flag
        INTCONbits.TMR0IF = 0; // Clear the interrupt flag
        delay_counter++;       // Increment delay counter
        TMR0 = 248;            // Preload TMR0 for 1 ms delay
    }
}

// Function to initialize Timer0 for delay
void init_timer0() {
    // Configure Timer0: Set it to 8-bit mode and use internal clock (Fosc/4)
    TMR0 = 0 ;  // Clear the timer register to start with 
    
    
    // These three settings are a must 
    INTCONbits.TMR0IE = 1; // Enable Timer0 overflow interrupt
    INTCONbits.GIE = 1;    // Global interrupt enable
    INTCONbits.PEIE = 1;   // Peripheral interrupt enable
    
    
    OPTION_REGbits.T0CS = 0;   //Select the internal instruction clock cycle 
    OPTION_REGbits.PSA = 0; // Pre Scaler is assigned to Timer 0 
  
    /* Now set the  Pre scaler   to 1:64
     * This is done by the OPTION_REGbits.PS2 , OPTION_REGbits.PS1 ,OPTION_REGbits.PS0 
     * The value that we want here is 101
     
     */
    
    OPTION_REGbits.PS2=1 ;
    OPTION_REGbits.PS1 = 0 ;
    OPTION_REGbits.PS0  =1 ; 
    
     
    TMR0 = 248;       // Load timer with preset value
    
    
    
    
   }

// Function to delay for a specific number of milliseconds
void delay_ms(unsigned int ms) {
    delay_counter = 0; // Reset the counter
    while (delay_counter < ms) {
        // Wait for the desired delay count
    }
}

// Function to scan PORTB pins (RB0 to RB3) with a dynamic delay
void scan_portb_pins(const unsigned int delay_ms_val) {
    int i;

    // Left to right (RB0 to RB3)
    for (i = 0; i <= 3; i++) {
        PORTB = (unsigned char)(1 << i); // Set one pin HIGH at a time
        delay_ms(delay_ms_val); // Wait for the specified delay
        PORTB = 0x00; // Turn all pins OFF
    }

    // Right to left (RB3 to RB0)
    for (i = 3; i >= 0; i--) {
        PORTB = (unsigned char)(1 << i); // Set one pin HIGH at a time
        delay_ms(delay_ms_val); // Wait for the specified delay
        PORTB = 0x00; // Turn all pins OFF
    }
}
