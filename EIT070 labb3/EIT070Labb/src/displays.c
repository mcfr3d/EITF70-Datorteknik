/*
 * displays.c

 *
 *  Created on: 15 feb. 2017
 *      Author: htx10fny
 */

#include "displays.h"
const unsigned int display_codes[] = {
		0b0111111,
		0b0000110,
		0b1011011,
		0b1001111,
		0b1100110,
		0b1101101,
		0b1111101,
		0b0000111,
		0b1111111,
		0b1101111
};
void displayDigitAtIndex(unsigned char index, unsigned char digit) {
	if ((index < 8) && (digit < 10))
		*((unsigned int *) (SEVEN_SEGMENT_DISPLAY_BASE + index * 4)) =
				display_codes[digit];
}

unsigned int numberOfDigits(unsigned int x) {
	unsigned int count = 1;
	while (x / 10 > 0) {
		count++;
		x = x / 10;
	}
	return count;
}

void displayNumber(unsigned int x) {
	unsigned int index = 0;
	if (numberOfDigits(x) < 9)
		do {
			displayDigitAtIndex(index, x % 10);
			index++;
			x = x / 10;
		} while (x > 0);
}

void resetDisplayAtIndex(unsigned char index){
	if ((index < 8))
			*((unsigned int *) (SEVEN_SEGMENT_DISPLAY_BASE + index * 4)) = 0b0000000;
}

void resetDisplays(){
	for(unsigned char i=0; i<8; i++){
		resetDisplayAtIndex(i);
	}
}

void displayNumberAtIndex(unsigned int number, unsigned char index) {
	if (numberOfDigits(number) + index <= 8) {
		unsigned int numbers = number;
		resetDisplays();
		for (unsigned char i = 0; i < numberOfDigits(number); i++) {
			displayDigitAtIndex(index + i, numbers % 10);
			numbers = numbers / 10;
		}
	}

}

