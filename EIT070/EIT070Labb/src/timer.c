/*
 * timer.c
 *
 *  Created on: 1 mars 2017
 *      Author: htx10fny
 */
#include "timers.h"
#include "buttons.h"
#include "interrupt_controller.h"
void initTimers() {
	*TIMER1_LOAD = 1999999;
	*TIMER1_CTRL = (1 << 8) | (1 << 6) | (1 << 5) | (1 << 4) | (1 << 1);
	*TIMER2_LOAD = 0xFFFFFFFF - 25000000;
	*TIMER2_CTRL = (1 << 8) | (1 << 6) | (1 << 5) | (1 << 4);
}
void enableTimers() {
	*TIMER1_CTRL = (*TIMER1_CTRL | (1 << 7)) & (~(1 << 5));
	*TIMER2_CTRL = (*TIMER2_CTRL | (1 << 7)) & (~(1 << 5));
}

void timer1InterruptHandler() {
	currentButtonsState = *BUTTONS_DATA;
	*TIMER1_CTRL |= (1 << 8);
	*IAR = 0b10;
}
void timer2InterruptHandler() {
	blinkerOnOff = ~blinkerOnOff;
	*TIMER2_CTRL |= (1 << 8);
	*IAR = 0b100;
}
