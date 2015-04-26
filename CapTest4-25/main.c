#include <msp430.h> 
#include "CapSens/CTS_Layer.h"
#include <stdint.h>

/*
 * main.c
 */
 
 #define MAX_X 5
 #define MAX_Y 5
 #define THRESHOLD 1000
 
 int checkSurroundings(int i, int j);
 
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	uint16_t raw_value[4];
	int64_t x, a = -21561, b=-85786625;

	int16_t value[4];
    while(1)
    {
		TI_CAPT_Raw(&sensor_0,raw_value);
		for(int i = 0; i<MAX_X; i++)
		{
			for(int j = 0; j<MAX_Y; j++)
			{
				if(panel[i,j]<THRESHOLD)
				{
					panel[i,j] = 0;
					checkSurroundings(i,j);
				}
			}
		}
		__no_operation(); // set breakpoint here
    }

}

int checkSurroundings(int i, int j) {
	int status = 0;
	
	if (i == 0) {
		if (j == 0) {
			//Don't check up or left
		}
		//Don't check left
	}
	
	else if (i == MAX_X) {
		if (j == MAX_X) {
			//Don't check down or right
		}
		//Don't check right
	}
	
	else if (j == 0) {
		if (i == MAX_X) {
			//Don't check up or right
		}
		//Don't check up
	}
	
	else if (j == MAX_Y) {
		if (i == 0) {
			//Don't check down or left
		}
		//Don't check down
	}	 
	else {
		//Check everything
	}
	
	return status;
}

#pragma vector= PORT2_VECTOR,PORT1_VECTOR,ADC10_VECTOR,NMI_VECTOR,          \
                TIMER0_A1_VECTOR,COMPARATORA_VECTOR,TIMER0_A0_VECTOR
__interrupt void ISR_trap(void)
{
  /* the following will cause an access violation and result in a PUC reset */
  WDTCTL = 0;
}
