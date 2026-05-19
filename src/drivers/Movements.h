// Movements.h
// Course number: 447
// Term: Spring 2026
// Project number: 3
// Driver description: A brief summary on driver responsibility and team member assignment
// Team #: 2
// Team members: Ana Arante, Emily Hsu, Suphia Sidiqi

#include <stdint.h>

#define DIRECTION (*((volatile unsigned long *)0x4002403C)) // Mask for PE0-3
#define FORWARD 		0x0F		// 1111
#define BACKWARD 		0x0A		// 1010

#define PERIOD 10000				// Total PWM period
#define STEP 1000						// increments of duty cycle
#define MAX_DUTY 9000				// max duty cycle (90%)
#define STOP 1							// min duty cycle (0%)
#define SPEED_35 3500				// 35% duty cycle
#define SPEED_60 6000				// 60% duty cycle
#define SPEED_80 8000				// 80% duty cycle
#define SPEED_98 9800				// 98% duty cycle

#define LEFT_PIVOT   0x0B   // 1011: SLP_L=1, DIR_L=0(back), SLP_R=1, DIR_R=1(fwd)
#define RIGHT_PIVOT  0x0E   // 1110: SLP_L=1, DIR_L=1(fwd),  SLP_R=1, DIR_R=0(back)

// Function Prototypes
void Move_Forward(uint16_t dutyA, uint16_t dutyB);
void Move_Backward(uint16_t dutyA, uint16_t dutyB);
void Move_Left(uint16_t dutyA, uint16_t dutyB);
void Move_Right(uint16_t dutyA, uint16_t dutyB);
void Stop(void);

//#define PERIOD 10000				// Total PWM period
//#define STEP 1000						// increments of duty cycle
//#define MAX_DUTY 9000				// max duty cycle (90%)
//#define STOP 1							// min duty cycle (0%)
//#define SPEED_20 2000				// 20% duty cycle
//#define SPEED_35 3500				// 35% duty cycle
//#define SPEED_50 5000				// 50% duty cycle
//#define SPEED_60 6000				// 60% duty cycle
//#define SPEED_80 8000				// 80% duty cycle
//#define SPEED_98 9800				// 98% duty cycle

void Forward(uint16_t dutyL, uint16_t dutyR);
void Backward(uint16_t dutyL, uint16_t dutyR);

void Sharp_Left(uint16_t dutyL, uint16_t dutyR);
void Slight_Left(uint16_t dutyL, uint16_t dutyR);

void Sharp_Right(uint16_t dutyL, uint16_t dutyR);
void Slight_Right(uint16_t dutyL, uint16_t dutyR);

void Pivot_Left(void);
void Pivot_Right(void);

void Stop(void);