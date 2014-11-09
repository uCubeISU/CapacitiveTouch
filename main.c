#include <msp430.h> 
#include "CapSens/CTS_Layer.h"
#include <stdint.h>


/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	uint16_t value;
    while(1)
    {
		TI_CAPT_Raw(&sensor_0,&value);
		__no_operation(); // set breakpoint here
    }

}

#pragma vector= PORT2_VECTOR,PORT1_VECTOR,ADC10_VECTOR,NMI_VECTOR,          \
                TIMER0_A1_VECTOR,COMPARATORA_VECTOR,TIMER0_A0_VECTOR
__interrupt void ISR_trap(void)
{
  /* the following will cause an access violation and result in a PUC reset */
  WDTCTL = 0;
}
