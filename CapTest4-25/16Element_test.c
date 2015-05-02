/**
 * @addtogroup <group name>
 * @{
 * @file      16Element_test.c
 * @author    Iowa State University uCube team
 * @author    Sprog
 * @date      May 2, 2015
 * @brief     <brief description>
 * @copyright Copyright (C) 2015 ISU uCube team
 * @details   <detailed description>
 */

/*
    CapacitiveTouch
    Copyright (C) 2015  Iowa State University uCube team

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	uint16_t raw_value[16];
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
    	TI_CAPT_Raw(&sensor_1,raw_value);

    	/*Puts raw capacitive touch value into correct place in the 5x5 panel*/
    	panel[0][0] = (CAP_VALUE(raw_value[0], 6000, 14191) - 6000) >> 5;
    	panel[0][1] = (CAP_VALUE(raw_value[1], 6000, 14191) - 6000) >> 5;
    	panel[0][2] = (CAP_VALUE(raw_value[2], 6000, 14191) - 6000) >> 5;
    	panel[0][3] = (CAP_VALUE(raw_value[3], 6000, 14191) - 6000) >> 5;
    	panel[0][4] = (CAP_VALUE(raw_value[4], 6000, 14191) - 6000) >> 5;
    	panel[1][0] = (CAP_VALUE(raw_value[5], 6000, 14191) - 6000) >> 5;
    	panel[1][1] = (CAP_VALUE(raw_value[6], 6000, 14191) - 6000) >> 5;
    	panel[1][2] = (CAP_VALUE(raw_value[7], 6000, 14191) - 6000) >> 5;
    	panel[1][3] = (CAP_VALUE(raw_value[8], 6000, 14191) - 6000) >> 5;
    	panel[1][4] = (CAP_VALUE(raw_value[9], 6000, 14191) - 6000) >> 5;
		panel[2][1] = (CAP_VALUE(raw_value[10], 6000, 14191) - 6000) >> 5;
		panel[2][2] = (CAP_VALUE(raw_value[11], 6000, 14191) - 6000) >> 5;
		panel[2][3] = (CAP_VALUE(raw_value[12], 6000, 14191) - 6000) >> 5;
		panel[2][4] = (CAP_VALUE(raw_value[13], 6000, 14191) - 6000) >> 5;
		panel[3][3] = (CAP_VALUE(raw_value[14], 6000, 14191) - 6000) >> 5;
		panel[3][4] = (CAP_VALUE(raw_value[15], 6000, 14191) - 6000) >> 5;

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

/// @}

