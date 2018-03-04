/*
 * displays.h
 *
 *  Created on: 15 feb. 2017
 *      Author: htx10fny
 */

#ifndef SRC_DISPLAYS_H_
#define SRC_DISPLAYS_H_
#define SEVEN_SEGMENT_DISPLAY_BASE 0x44A00000
void displayDigitAtIndex(unsigned char index, unsigned char digit);
unsigned int numberOfDigits(unsigned int x);
void displayNumber(unsigned int x);
void resetDisplayAtIndex(unsigned char index);
void resetDisplays();
void displayNumberAtIndex(unsigned int number, unsigned char index);

#endif /* SRC_DISPLAYS_H_ */
