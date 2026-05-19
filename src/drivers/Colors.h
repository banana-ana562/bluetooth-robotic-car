// Colors.c
// Course number: 447
// Term: Spring 2026
// Project number: 3
// Driver description: A brief summary on driver responsibility and team member assignment
// Team #: 2
// Team members: Ana Arante, Emily Hsu, Suphia Sidiqi

#include "../tm4c123gh6pm.h"

#define LED 	(GPIO_PORTF_DATA_R)

// Color    LED(s) PortF
// dark     ---    0
// red      R--    0x02
// blue     --B    0x04
// green    -G-    0x08
// yellow   RG-    0x0A
// white    RGB    0x0E
// pink     R-B    0x06

#define Dark    	0x00
#define Red     	0x02
#define Blue    	0x04
#define Green   	0x08
#define Yellow  	0x0A
#define White   	0x0E
#define Purple  	0x06

// standard ASCII symbols
#define CR   0x0D
#define LF   0x0A

