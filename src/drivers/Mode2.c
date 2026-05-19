// Mode2.c
// Course number: 447
// Term: Spring 2026
// Project number: 3
// Driver description: A brief summary on driver responsibility and team member assignment
// Team #: 2
// Team members: Ana Arante, Emily Hsu, Suphia Sidiqi

#include "src/drivers/PWM_car.h"
#include "src/drivers/Movements.h"
#include "src/drivers/Colors.h"
#include "src/drivers/LED_Init.h"
#include "src/drivers/UART_BT.h"
#include "src/drivers/BLT.h"
#include "src/drivers/Mode2.h"

void Mode2(void);
void Delay(void);

extern int PWM_SPEED[5];
int speed_idx = 1;
extern unsigned char control_symbol; // control symbol received from Bluetooth module

void Mode2(void){
static char prev;
	
	//LED = Blue;

	switch(control_symbol){
		case 'F':
		case 'f':
			prev = 'f';
			Forward(PWM_SPEED[speed_idx], PWM_SPEED[speed_idx]);
			//Delay();
			break;
		case 'B':
		case 'b':
			prev = 'b';
			Backward(PWM_SPEED[speed_idx], PWM_SPEED[speed_idx]);
			//Delay();
			break;
		case 'L':
		case 'l':			
			prev = 'l';
			Forward(PWM_SPEED[speed_idx - 1], PWM_SPEED[speed_idx]);
			//Delay();
			break;
		case 'R':
		case 'r':
			prev = 'r';
			Forward(PWM_SPEED[speed_idx], PWM_SPEED[speed_idx - 1]);
			//Delay();
			break;
		case 'S':
		case 's':
			Stop();
			//Delay();
			break;
		case 'U':
		case 'u':
			if(PWM_SPEED[speed_idx] != SPEED_98){
				speed_idx = speed_idx + 1;
				LED = Green;
			}
			if(prev == 'f'){
				Forward(PWM_SPEED[speed_idx], PWM_SPEED[speed_idx]);
			} else if (prev == 'b'){
				Backward(PWM_SPEED[speed_idx], PWM_SPEED[speed_idx]);
			} else if (prev == 'l'){
				Forward(PWM_SPEED[speed_idx - 1], PWM_SPEED[speed_idx]);
			} else if (prev == 'r'){
				Forward(PWM_SPEED[speed_idx], PWM_SPEED[speed_idx - 1]);
			}
			//Delay();
			break;
		case 'D':
		case 'd':
			if(PWM_SPEED[speed_idx] != SPEED_35){
				speed_idx = speed_idx - 1;
				LED = Red;
			}
			if(prev == 'f'){
				Forward(PWM_SPEED[speed_idx], PWM_SPEED[speed_idx]);
			} else if (prev == 'b'){
				Backward(PWM_SPEED[speed_idx], PWM_SPEED[speed_idx]);
			} else if (prev == 'l'){
				Forward(PWM_SPEED[speed_idx - 1], PWM_SPEED[speed_idx]);
			} else if (prev == 'r'){
				Forward(PWM_SPEED[speed_idx], PWM_SPEED[speed_idx - 1]);
			}
			//Delay();
			break;
		default:
			Stop();
			Delay();
			break;
	}
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
