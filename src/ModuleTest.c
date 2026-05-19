// ModuleTest.c
// Course number:
// Term: 
// Project number: 
// Module description: 
// A brief summary on modules tested in this module test file,
// including module list, responsibility and team member assignment
// Team #:
// Team members:


// Header files needed for this program
// Include C library header files, microntroller header files, and 
// project module header files. 
// Example:
// #include module1_driver.h

// preprocessor directives for module name
// Example:
// #define MODULE_1_TEST

// functions prototypes
void System_Init(void);

// Module test function prototypes
#if defined(MODULE_1_TEST)
void Module_1_Test(void);
#endif

int main(void){
  System_Init();
	
  while(1){
    // Call individual module test functions here
	// Example:
	#if defined(MODULE_1_TEST)
	Module_1_Test();
	#endif
  }
}

void System_Init(void){
  // Example:
  #if defined(MODULE_1_TEST)
  Module_1_Init();
  #endif	
}

// Module test function definitions
#if defined(MODULE_1_TEST)
void Module_1_Test(void){
}
#endif
