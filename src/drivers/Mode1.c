// Mode1.c
// Course number: 447
// Term: Spring 2026
// Project number: 3
// Driver description: A brief summary on driver responsibility and team member assignment
// Team #: 2
// Team members: Ana Arante, Emily Hsu, Suphia Sidiqi
#include "../tm4c123gh6pm.h"
#include <stdint.h>
#include "src/drivers/PWM_car.h"
#include "src/drivers/Movements.h"
#include "src/drivers/Colors.h"
#include "src/drivers/LED_Init.h"
#include "src/drivers/UART_BT.h"
#include "src/drivers/BLT.h"
#include "src/drivers/Delay.h"

extern unsigned char control_symbol; // control symbol received from Bluetooth module

void Mode1(void){

	//LED = Green;
	
	switch(control_symbol){
		case 'C':
			case 'c':
			Slight_Left(SPEED_35, SPEED_60);
			Delay_1s();
			Stop();
			break;
			
		case 'S': 
			case 's':
			for(int i = 0; i < 4; i++){
				Forward(SPEED_20, SPEED_20);
				Delay_1s();
				Stop();
				Delay_50ms();
				Pivot_Left();
				Delay_50ms();
				Delay_30ms();
				Stop();
				Delay_100ms();
			}
			Stop();
			break;
		
		case 'Z': 
			case 'z':
    // Side 1
    Forward(SPEED_20, SPEED_20);
    Delay_300ms();
    Stop();
    Delay_30ms();
    Pivot_Left();
    Delay_50ms();      				
    Stop();
    Delay_50ms();

		//Side 2
    Forward(SPEED_20, SPEED_20);
    Delay_300ms();
		Stop();
    Delay_30ms();
    Pivot_Right();
    Delay_100ms();
    Stop();
    Delay_50ms();
    
		// Side 3
    Forward(SPEED_20, SPEED_20);
    Delay_300ms();
    Stop();
    Delay_30ms();
    Pivot_Left();
    Delay_100ms();
		Stop();
    Delay_50ms();
    
		// Side 4
    Forward(SPEED_20, SPEED_20);
		Delay_300ms();
		Stop();
		Delay_30ms();
		Pivot_Right();
    Delay_100ms();
    Stop();
		Delay_50ms();
		
		// Side 5
		Forward(SPEED_20, SPEED_20);
    Delay_300ms();
    Stop();
    Delay_30ms();
    Pivot_Left();
    Delay_150ms();
		Stop();
    Delay_50ms();
    break;
	
    case '8':
			Slight_Left(SPEED_35, SPEED_60);
			Delay_1s();
			Slight_Right(SPEED_60, SPEED_35);
			Delay_1s();
			Stop();
			break;
		
		default:
			Stop();
			break;
		} 
}