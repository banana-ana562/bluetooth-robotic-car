// LED_Init.c
// Course number: 447
// Term: Spring 2026
// Project number: 3
// Driver description: A brief summary on driver responsibility and team member assignment
// Team #: 2
// Team members: Ana Arante, Emily Hsu, Suphia Sidiqi

#include "../tm4c123gh6pm.h"

//------------LED_Init------------
// Initialize the GPIO for the 3 LEDs on Port F
void LED_Init(void){ 
    volatile unsigned long delay;
    SYSCTL_RCGC2_R |= 0x00000020;     // 1) F clock
    delay = SYSCTL_RCGC2_R;           // delay   
    GPIO_PORTF_LOCK_R = 0x4C4F434B;   // 2) unlock PortF PF0  
    GPIO_PORTF_CR_R |= 0x0E;          // allow changes to PF3-PF1       
    GPIO_PORTF_AMSEL_R &= ~0x0E;      // 3) disable analog function
    GPIO_PORTF_PCTL_R &= ~0x0000FFF0; // 4) GPIO clear bit PCTL  
    GPIO_PORTF_DIR_R |= 0x0E;         // 6) PF1-PF3 output
    GPIO_PORTF_AFSEL_R &= ~0x0E;      // 7) no alternate function     
    GPIO_PORTF_DEN_R |= 0x0E;         // 8) enable digital pins PF3-PF1
}