/*
 * buttons.h
 *
 *  Created on: 15 feb. 2017
 *      Author: htx10fny
 */

#ifndef SRC_BUTTONS_H_
#define SRC_BUTTONS_H_

#define BUTTONS_DATA (unsigned int *) 0x40000000
#define BUTTONS_CONTROL (unsigned int *) 0x40000004

//Labb 2 assignment 10

#define UP 0b10
#define DOWN 0b10000
#define MIDDLE 0b1
#define LEFT 0b100
#define RIGHT 0b1000

/* Gör detta någon skillnad?
#define UP 0b00000010
#define DOWN 0b00010000
#define MIDDLE 0b00000001
#define LEFT 0b00000100
#define RIGHT 0b00001000
*/
#endif /* SRC_BUTTONS_H_ */
