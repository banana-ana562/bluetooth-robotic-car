// Switch.c
// Course number: 447
// Term: Spring 2026
// Project number: 3
// Driver description: A brief summary on driver responsibility and team member assignment
// Team #: 2
// Team members: Ana Arante, Emily Hsu, Suphia Sidiqi

#include "src/drivers/Switch.h"
#include "src/drivers/UART_BT.h"
#include "src/drivers/Movements.h"
#include "src/drivers/Colors.h"
#include "../tm4c123gh6pm.h"
#include <stdio.h>

extern volatile MODE_NUM mode;

void Switch_Init(void){
    volatile unsigned long delay;
    SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF;
    delay = SYSCTL_RCGC2_R;

    GPIO_PORTF_LOCK_R   = 0x4C4F434B;
    GPIO_PORTF_CR_R    |= SW1_MASK;
    GPIO_PORTF_DIR_R   &= ~SW1_MASK;
    GPIO_PORTF_AFSEL_R &= ~SW1_MASK;
    GPIO_PORTF_DEN_R   |= SW1_MASK;
    GPIO_PORTF_PCTL_R  &= ~0x000F000F;
    GPIO_PORTF_AMSEL_R &= ~SW1_MASK;
    GPIO_PORTF_PUR_R   |= SW1_MASK;

    GPIO_PORTF_IS_R  &= ~SW1_MASK;
    GPIO_PORTF_IBE_R &= ~SW1_MASK;
    GPIO_PORTF_IEV_R &= ~SW1_MASK;
    GPIO_PORTF_ICR_R  = SW1_MASK;
    GPIO_PORTF_IM_R  |= SW1_MASK;

    NVIC_PRI7_R = (NVIC_PRI7_R & ~0x00E00000) | 0x00C00000;
    NVIC_EN0_R |= 0x40000000;
}

void GPIOPortF_Handler(void){
	for (uint32_t time = 0; time < 40000; time++){} // simple debounce
		
    if(GPIO_PORTF_RIS_R & SW1_MASK){
			GPIO_PORTF_ICR_R = SW1_MASK;
			
			if (mode == MODE1){
					mode = MODE2;
					LED = Blue;
      }
			else {
				mode = MODE1;
				LED = Green;
			}
			Stop();
    } 
}

