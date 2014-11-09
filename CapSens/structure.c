/*
 *     uCube is a motion controlled interactive LED cube.
 *     Copyright (C) 2014  Jeramie Vens
 *
 *     This program is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 *
 *     This program is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 *
 *     You should have received a copy of the GNU General Public License
 *     along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
/**
 * @addtogroup CapacitiveTouch
 * @{
 * @file structure.c
 * @author Sprog
 * @date Nov 8, 2014
 * @copyright GNU Public License v3
 * @brief
 * @details
 */
#include "structure.h"

const struct Element element_0 = {
	.inputPxselRegister = (uint8_t *)&P3SEL,
	.inputPxsel2Register = (uint8_t *)&P3SEL2,
	.inputBits = BIT3,
	.maxResponse = 400,
	.threshold = 50
};


const struct Sensor sensor_0 =
{
	.halDefinition = RO_PINOSC_TA0_WDTp,
	.numElements = 1,
	.baseOffset = 0,
	// Pointer to elements
	.arrayPtr[0] = &element_0, // point to first element
	// Timer Information
	.measGateSource= GATE_WDTp_SMCLK, // 0->SMCLK, 1-> ACLK
	.accumulationCycles= WDTp_GATE_512 //512
};


