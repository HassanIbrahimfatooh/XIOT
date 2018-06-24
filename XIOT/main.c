/*
 * main.c
 *
 *  Created on: Jun 24, 2018
 *      Author: Hassan Ibrahim
 *
 */

#define F_CPU 4000000ul
#include "all-includes.h"

// Initializing Global Variables
u8 flag = 0;

int main() {

	// Initializing Local Variables
	u8 adcREAD;

	// Initializing PORTS
	DDRB = 0x0f;
	DDRC = 0xff;

	// Initializing ADC
	ADC_voidInitializeADC();

	// Initializing External interrupt
	ExternalInterrupt_voidInitialzie();

	while (1) {

		while (flag == 0) {

			PORTB = 0x00;
			// Reading the value of variable resistor
			adcREAD = ADC_u8ReadADC();
			PORTC = adcREAD;
			// Assigning Higher Nibble
			Assign_High_Nibble(PORTC, (adcREAD * 5) / 255);
			// Assigning Lower Nibble
			Assign_Low_Nibble(PORTC, (int ) (((adcREAD * 5) % 255) / 28));
			_delay_ms(3000);

			// It replaces the serial monitor output
			printf("Not Pressed, The LED is OFF");

		}

		while (flag == 1) {

			PORTC = 0x00;
			PORTB = 0x0f;

			// It replaces the serial monitor output
			printf("Pressed, The LED is ON");

		}

	} // End of While

	return 0;
} // End of main
