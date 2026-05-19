// Movements.c
// Course number: 447
// Term: Spring 2026
// Project number: 3
// Driver description: A brief summary on driver responsibility and team member assignment
// Team #: 2
// Team members: Ana Arante, Emily Hsu, Suphia Sidiqi

#include "src/drivers/Movements.h"
#include "src/drivers/PWM_car.h"
#include "src/drivers/Delay.h"

#define DUTY_70			

void Forward(uint16_t dutyA, uint16_t dutyB){
    DIRECTION = FORWARD;
    PWM0A_Duty(dutyA);
    PWM0B_Duty(dutyB);
}

void Backward(uint16_t dutyA, uint16_t dutyB){
    DIRECTION = BACKWARD;
    PWM0A_Duty(dutyA);
    PWM0B_Duty(dutyB);
}

void Move_Left(uint16_t dutyA, uint16_t dutyB){
    DIRECTION = FORWARD;
    PWM0A_Duty(dutyA);
    PWM0B_Duty(dutyB);
}

void Move_Right(uint16_t dutyA, uint16_t dutyB){
    DIRECTION = FORWARD;
    PWM0A_Duty(dutyA);
    PWM0B_Duty(dutyB);
}


void Sharp_Left(uint16_t dutyL, uint16_t dutyR){
    DIRECTION = 0x0B;   // left wheel stopped (DIR=0), right forward
    PWM0A_Duty(STOP);
    PWM0B_Duty(dutyR);
}

void Slight_Left(uint16_t dutyL, uint16_t dutyR){
    DIRECTION = FORWARD;
    PWM0A_Duty(dutyL);
    PWM0B_Duty(dutyR);
	//	Delay_1s();
}

void Sharp_Right(uint16_t dutyL, uint16_t dutyR){
    DIRECTION = 0x0E;   // left forward, right wheel stopped (DIR=0)  
    PWM0A_Duty(dutyL);
    PWM0B_Duty(STOP);
}

void Slight_Right(uint16_t dutyL, uint16_t dutyR){
    DIRECTION = FORWARD;
    PWM0A_Duty(dutyL);
    PWM0B_Duty(dutyR);
	//	Delay_1s();
}
void Stop(void){
    DIRECTION = FORWARD; // Direction doesn't matter when stopped
    PWM0A_Duty(STOP);
    PWM0B_Duty(STOP);
}
// Add these to Movements.c
void Pivot_Left(void){
    DIRECTION = LEFT_PIVOT;   // 0x09 ? left wheel back, right wheel forward
    PWM0A_Duty(SPEED_35);
    PWM0B_Duty(SPEED_35);
}

void Pivot_Right(void){
    DIRECTION = RIGHT_PIVOT;  // 0x06 ? left wheel forward, right wheel back
    PWM0A_Duty(SPEED_35);
    PWM0B_Duty(SPEED_35);
}