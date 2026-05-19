// Switch.h
// Course number: 447
// Term: Spring 2026
// Project number: 3
// Driver description: A brief summary on driver responsibility and team member assignment
// Team #: 2
// Team members: Ana Arante, Emily Hsu, Suphia Sidiqi

#ifndef SWITCH_H
#define SWITCH_H

#define SW1_MASK 0x10 // Mask for switch 1 (PF4)

typedef enum {
  MODE1,
  MODE2
} MODE_NUM;

// Function Prototypes
void Switch_Init(void);
void GPIOPortF_Handler(void);

#endif
