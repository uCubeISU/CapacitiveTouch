#include <msp430.h> 
#include "../CapSens/CTS_Layer.h"
#include <stdint.h>

/*
 * main.c
 */
 
 #define MAX_X 5
 #define MAX_Y 5
 #define THRESHOLD 1000
 #define CAP_VALUE(x, min, max) (x = x < min ? min: x > max ? max : x)
 
 int checkSurroundings(int x, int y);
#ifdef 0
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	uint16_t raw_value[9];
//	int64_t x, a = -21561, b=-85786625;
	int16_t panel[MAX_X][MAX_Y];
	int i;
	int j;



	/* Set panel array to 0 */
	for(i = 0; i<MAX_X; i++)
	{
		for(j = 0; j<MAX_Y; j++)
		{
			panel[i][j] = 0;
		}
	}
    while(1)
    {
    	TI_CAPT_Raw(&sensor_0,raw_value);

    	/*Puts raw capacitive touch value into correct place in the 5x5 panel*/
    	panel[2][0] = (CAP_VALUE(raw_value[0], 6000, 14191) - 6000) >> 5;
    	panel[3][0] = (CAP_VALUE(raw_value[1], 6000, 14191) - 6000) >> 5;
    	panel[3][1] = (CAP_VALUE(raw_value[2], 6000, 14191) - 6000) >> 5;
    	panel[3][2] = (CAP_VALUE(raw_value[3], 6000, 14191) - 6000) >> 5;
    	panel[4][0] = (CAP_VALUE(raw_value[4], 6000, 14191) - 6000) >> 5;
    	panel[4][1] = (CAP_VALUE(raw_value[5], 6000, 14191) - 6000) >> 5;
    	panel[4][2] = (CAP_VALUE(raw_value[6], 6000, 14191) - 6000) >> 5;
    	panel[4][3] = (CAP_VALUE(raw_value[7], 6000, 14191) - 6000) >> 5;
    	panel[4][4] = (CAP_VALUE(raw_value[8], 6000, 14191) - 6000) >> 5;

		for(i = 0; i<MAX_X; i++)
		{
			for(j = 0; j<MAX_Y; j++)
			{
				if(panel[i][j] != 0 || panel[i][j] > THRESHOLD || panel[i][j] < THRESHOLD)
				{

				}
			}
		}
		__no_operation(); // set breakpoint here
    }

}

int checkSurroundings(int x, int y) {
	int status = 0;
	
	if (x == 0) {
		if (y == 0) {
			//Don't check up or left
		}
		//Don't check left
	}
	
	else if (x == MAX_X) {
		if (y == MAX_X) {
			//Don't check down or right
		}
		//Don't check right
	}
	
	else if (y == 0) {
		if (x == MAX_X) {
			//Don't check up or right
		}
		//Don't check up
	}
	
	else if (y == MAX_Y) {
		if (x == 0) {
			//Don't check down or left
		}
		//Don't check down
	}	 
	else {
		//Check everything
	}
	
	return status;
}
/*
#pragma vector= PORT2_VECTOR,PORT1_VECTOR,ADC10_VECTOR,NMI_VECTOR,
                TIMER0_A1_VECTOR,COMPARATORA_VECTOR,TIMER0_A0_VECTOR
__interrupt void ISR_trap(void)
{

  WDTCTL = 0;
}
*/
#endif
