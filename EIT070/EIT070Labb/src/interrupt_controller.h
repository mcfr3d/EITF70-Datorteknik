/*
 * interrupt_controller.h
 *
 *  Created on: 1 mars 2017
 *      Author: htx10fny
 */

#ifndef SRC_INTERRUPT_CONTROLLER_H_
#define SRC_INTERRUPT_CONTROLLER_H_
#define IER   (unsigned int*) 0x41200008
#define IAR   (unsigned int*) 0x4120000C
#define MER   (unsigned int*) 0x4120001C
#define IVAR1 (unsigned int*) 0x41200104
#define IVAR2 (unsigned int*) 0x41200108
void initController();

#endif /* SRC_INTERRUPT_CONTROLLER_H_ */
