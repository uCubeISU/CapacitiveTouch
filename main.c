#include <msp430.h> 
#include "CapSens/CTS_Layer.h"
#include <stdint.h>

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	uint16_t raw_value[4];
	int64_t x, a = -21561, b=-85786625;

	int16_t value[4];
    while(1)
    {
		TI_CAPT_Raw(&sensor_0,raw_value);
		//value[0]=(uint16_t)-.329*(raw_value[0]-1310);
		//x = ((int32_t)raw_value[0]) << 16;
		//value[0] = (a*(x+b)) >> 32;
		//if(value[0]) __no_operation();
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
