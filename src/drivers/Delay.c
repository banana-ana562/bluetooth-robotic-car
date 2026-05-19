// Delay.c
// Course number: 447
// Term: Spring 2026
// Project number: 3
// Driver description: A brief summary on driver responsibility and team member assignment
// Team #: 2
// Team members: Ana Arante, Emily Hsu, Suphia Sidiqi

#include "src/drivers/Delay.h"

// Subroutine to wait 100 ms
// Inputs: None
// Outputs: None
// Notes: ...
// 1 second delay


void Delay_1s(void){
    volatile unsigned long time;
    time = 5333333;   // 16,000,000 / 3 cycles per loop
    while(time){ time--; }
}

void Delay_100ms(void){
    volatile unsigned long time;
    time = 533333;    // 5333333 / 10
    while(time){ time--; }
}

void Delay_20ms(void){
    volatile unsigned long time;
    time = 106666;    // 5333333 / 50
    while(time){ time--; }
}

void Delay_10ms(void){
    volatile unsigned long time;
    time = 53333;     // 5333333 / 100
    while(time){ time--; }
}

void Delay_50ms(void){
    volatile unsigned long time;
    time = 266666;    // 5333333 / 20
    while(time){ time--; }
}

void Delay_200ms(void){
    volatile unsigned long time;
    time = 1066666;    // 5333333 / 5
    while(time){ time--; }
}

void Delay_150ms(void){
    volatile unsigned long time;
    time = 800000;    // 5333333 / 6.667
    while(time){ time--; }
}
void Delay_300ms(void){
    volatile unsigned long time;
    time = 1600000;    // 5333333 / 3.333
    while(time){ time--; }
}
void Delay_30ms(void){
    volatile unsigned long time;
    time = 160000;    // 5333333 / 33.333
    while(time){ time--; }
}
void Delay_15ms(void){
    volatile unsigned long time;
    time = 80000;    // 5333333 / 66.667
    while(time){ time--; }
}