/*
 * microBlaze.s
 *
 *  Created on: 1 mars 2017
 *      Author: htx10fny
 */
.global enableMicroBlazeInterrupts
.text
.ent enableMicroBlazeInterrupts
enableMicroBlazeInterrupts:
mfs  r11, rmsr
ori  r11, r11, 2
mts  rmsr, r11
rtsd r15, 8
nop
.end enableMicroBlazeInterrupts

