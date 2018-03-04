/*
 * interrupt_controller.c
 *
 *  Created on: 1 mars 2017
 *      Author: htx10fny
 */
#include "interrupt_controller.h"
#include "timers.h"
void initController() {
	*IER |= 0b110;
	*IVAR1 = (unsigned int) timer1InterruptHandler;
	*IVAR2 = (unsigned int) timer2InterruptHandler;
	*MER |= 0b11;
}

