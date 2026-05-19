// SetupBLT.c
// Course number: 447
// Term: Spring 2026
// Project number: 3
// Driver description: A brief summary on driver responsibility and team member assignment
// Team #: 2
// Team members: Ana Arante, Emily Hsu, Suphia Sidiqi

#include "tm4c123gh6pm.h"
#include "src/drivers/UART0_BT.h"
#include "src/drivers/BLT.h"
#include <stdint.h>

// This function sets up the Bluetooth module by sending AT commands through UART0.
void SetupBLT(void){
    uint8_t String[30];
	uint8_t i;
	uint8_t SetCommands[][30] = {"AT+NAME=CECS447\r\n","AT+UART=57600,0,1\r\n","AT+PSWD=0824\r\n","AT+ROLE=0\r\n"};
	uint8_t QueryCommands[][30] = {"AT+NAME?\r\n","AT+UART?\r\n","AT+PSWD?\r\n","AT+ROLE?\r\n"};
  UART0_Init();
	BLT_Init();
  
  // Setup the HC-05 bluetooth module
	for (i=0;i<4;i++) {
		UART0_OutString(SetCommands[i]); 		
		BLT_OutString(SetCommands[i]); 		
    while ((UART1_FR_R&UART_FR_BUSY) != 0){};
    BLT_InString(String);
    UART0_OutString(String);
		UART0_NextLine();		
		UART0_NextLine();
	}
	
  // Query the HC-05 bluetooth module: HC-05 reply format example:
	// AT+NAME?
	// +NAME:CECS447\r\n OK\r\n
	for (i=0;i<4;i++) {
		UART0_OutString(QueryCommands[i]); 		
		BLT_OutString(QueryCommands[i]); 		
    while ((UART1_FR_R&UART_FR_BUSY) != 0){};
    BLT_InString(String);  // get the 1st tring before OK
    UART0_OutString(String);
		BLT_InString(String);  // get OK
		UART0_OutChar(SP);
    UART0_OutString(String);
		UART0_NextLine();
		UART0_NextLine();
	}
	
  while (1) {}
}