/*
 * ISR.c
 *
 *  Created on: Apr 25, 2018
 *      Author: ihass
 */

#include "../all-includes.h"

extern u8 flag;

ISR (INT0_vect) {
	// Toggling The first bit into flag variable
	Toggle_Bit(flag, 0);
}
