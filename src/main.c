// main.c
// Course number: 447
// Term: Spring 2026
// Project number: 3
// Project description: A bluetooth controlled car that has two different modes
// Team #: 2
// Team members: Ana Arante, Emily Hsu, Suphia Sidiqi

// Header files needed for this program
// Include C library header files, microntroller header files, and 
// project module header files.

#include <stdint.h>
#include "src/drivers/PWM_car.h"
#include "src/drivers/Movements.h"
#include "src/drivers/Colors.h"
#include "src/drivers/LED_Init.h"
#include "src/drivers/UART_BT.h"
//#include "src/drivers/BLT.h"
#include "src/drivers/Delay.h"
#include "src/drivers/Mode1.h"
#include "src/drivers/Mode2.h"
#include "src/drivers/Switch.h"
#include "tm4c123gh6pm.h"

unsigned char control_symbol; // control symbol received from Bluetooth module
volatile MODE_NUM mode = MODE1;

// function prototypes
void System_Init(void);
//unsigned char UART1_InChar(void);
extern void DisableInterrupts(void); // Disable interrupts
extern void EnableInterrupts(void);  // Enable interrupts
extern void WaitForInterrupt(void);  // low power mode

int main(void){	
  System_Init();
	UART0_OutString((unsigned char *)">>> Welcome to Bluetooth Controlled Car! <<<\n\r");

  while(1){
    control_symbol = UART1_InChar();

    if(mode == MODE1){
        Mode1();
    }
    else{
        Mode2();
    }
}
}

void System_Init(void) {
  DisableInterrupts();
	
  PWM0A_Init(PERIOD);         // initialize PWM0, PB6 LEFT MOTOR
  PWM0B_Init(PERIOD);         // initialize PWM0, PB7 RIGHT MOTOR
  PortE_Init();               // initialize PE0-3 for direction control

  UART_Init();                 // initialize UART0 for Bluetooth module setup and debugging
  //BLT_Init();                  // initialize UART1 for Bluetooth communication with HC-05 module
  LED_Init();                // initialize Port F for LED control
	Switch_Init();
	
	mode = MODE1;
	LED = Green;
	Stop();
	
	EnableInterrupts();         // enable after all initialization are done
}
