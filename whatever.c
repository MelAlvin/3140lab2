#include <fsl_device_registers.h>

int main (void) {
SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK; //Enable the clock to port B
PORTB->PCR[22] = (1 << 8); //Set up PTB22 as GPIO
PORTB->PCR[22] = PORT_PCR_MUX(001); //Set up PTB22 as GPIO
	
SIM->SCGC6 = SIM_SCGC6_PIT_MASK; // Enable clock to PIT module
PIT->MCR = 0;// Clock for standard PIT timers is enabled
PIT->CHANNEL[0].LDVAL = 0x0000001; // Set load value of zeroth PIT
PIT->CHANNEL[0].TCTRL = 1 ;// Enable Interrupts

	
void LEDRed_On(), LEDRed_Off(), start();

PIT->CHANNEL[0].TCTRL |= 1; // start Timer 	
	
while(1){ 
	int check = PIT->CHANNEL[0].TFLG;
if (check == 1){
		LEDRed_On();
		}
}
}
void LEDRed_On(void){
PTB->PSOR = (0u<<22);
}
void LEDRed_Off(void){
PTB->PCOR = (0u<<22);
}
