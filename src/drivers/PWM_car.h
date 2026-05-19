// PWM.h
// Course number: 447
// Term: Spring 2026
// Project number: 3
// Driver description: A brief summary on driver responsibility and team member assignment
// Team #: 2
// Team members: Ana Arante, Emily Hsu, Suphia Sidiqi

#include <stdint.h>
#include "../tm4c123gh6pm.h"

#define DIRECTION (*((volatile unsigned long *)0x4002403C))
#define LEFT_WHEEL ()
#define FORWARD 		0x0F	//1111
#define BACKWARD 		0x0A	//1010

#define LIGHT (*((volatile unsigned long *)0x40025038))
#define RED 0x02
#define GREEN 0x08
#define BLUE 0x04

#define PERIOD 10000				// Total PWM period
#define STEP 1000						// increments of duty cycle
#define MAX_DUTY 9000				// max duty cycle (90%)

#define STOP 1
#define SPEED_10 1000
#define SPEED_20 2000
#define SPEED_35 3500
#define SPEED_60 6000
#define SPEED_80 8000
#define SPEED_98 9800
#define SPEED_15 1500
#define SPEED_35 3500
#define SPEED_60 6000
#define SPEED_80 8000
#define SPEED_98 9800

void PLL_Init(void);

// period is 16-bit number of PWM clock cycles in one period 
// Output on PB6/M0PWM0
void PWM0A_Init(uint16_t period);

// change duty cycle of PB6
// duty is number of PWM clock cycles output is high  
void PWM0A_Duty(uint16_t duty);

// period is 16-bit number of PWM clock cycles in one period 
// Output on PB7/M0PWM1
void PWM0B_Init(uint16_t period);

// change duty cycle of PB7
// duty is number of PWM clock cycles output is high  
void PWM0B_Duty(uint16_t duty);

// Initialize Port E for motor direction control
void PortE_Init(void);