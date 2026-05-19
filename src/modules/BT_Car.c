// BT_Car.c
// Course number: 447
// Term: Spring 2026
// Project number: 3
// Driver description: A brief summary on driver responsibility and team member assignment
// Team #: 2
// Team members: Ana Arante, Emily Hsu, Suphia Sidiqi

#include <stdint.h>
#include "src/drivers/PWM_car.h"
#include "src/drivers/Movements.h"
#include "src/drivers/Colors.h"
#include "src/drivers/LED_Init.h"
#include "src/drivers/UART_BT.h"
#include "src/drivers/UART0_BT.h"
#include "src/drivers/BLT.h"
#include "../tm4c123gh6pm.h"

void Delay(void);
void System_Init(void);
unsigned char UART1_InChar(void);
extern void DisableInterrupts(void); // Disable interrupts
extern void EnableInterrupts(void);  // Enable interrupts
extern void WaitForInterrupt(void);  // low power mode

int main(void){
  System_Init();
  unsigned char control_symbol; // control symbol received from Bluetooth module

  UART0_OutString((unsigned char *)">>> Welcome to Bluetooth Controlled Car! <<<\n\r");
  UART0_OutString((unsigned char *)"Enter one of the following commands to control the car: f, b, l, r, or s.\n\r");

  while(1){
    control_symbol = UART1_InChar();
    UART0_OutChar(control_symbol);
    UART0_OutChar(CR);
    UART0_OutChar(LF);

    switch(control_symbol){
      case 'F':
      case 'f':
        Move_Forward(SPEED_60, SPEED_60);
        LED = Green;
        Delay();
        break;
      case 'B':
      case 'b':
        Move_Backward(SPEED_60, SPEED_60);
        LED = White;
        Delay();
        break;
      case 'L':
      case 'l':
        Move_Left(SPEED_60, SPEED_60);
        LED = Blue;
        Delay();
        break;
      case 'R':
      case 'r':
        Move_Right(SPEED_60, SPEED_60);
        LED = Yellow;
        Delay();
        break;
      case 'S':
      case 's':
        Stop();
        LED = Red;
        Delay();
        break;
      default:
        Stop();
        LED = Red;
        Delay();
        break;
    }
  }
}

void System_Init(void){
  DisableInterrupts();
  //PLL_Init();                 // set system clock to 50 MHz
  PWM0A_Init(PERIOD);         // initialize PWM0, PB6 LEFT MOTOR
  PWM0B_Init(PERIOD);         // initialize PWM0, PB7 RIGHT MOTOR
  PortE_Init();               // initialize PE0-3 for direction control

  UART_Init();                 // initialize UART0 for Bluetooth module setup and debugging
  //BLT_Init();                  // initialize UART1 for Bluetooth communication with HC-05 module
  LED_Init();                // initialize Port F for LED control
	
	 EnableInterrupts();         // enable after all initialization are done
}

// Subroutine to wait 0.5 sec
// Inputs: None
// Outputs: None
// Notes: ...
void Delay(void){unsigned long volatile time;
  time = 727240*100/91;  // 1 sec
  while(time){
		time--;
  }
	for (time=0;time<1000;time=time+10) {
	}
}

