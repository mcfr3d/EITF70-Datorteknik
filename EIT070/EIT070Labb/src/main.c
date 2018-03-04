/*
 * main.c

 *
 *  Created on: 8 feb. 2017
 *      Author: htx10fny
 */
/*
 /* Labb 1 assignment 0
 char b;
 int main(){
 b=9;
 while(1==1){
 if(b<10){
 b--;
 }
 }
 }
 */

/* Labb 1 assignment 1
 unsigned char b;
 int main(){
 b=9;
 while(1==1){
 if(b<10){
 b--;
 }
 }
 }
 */

/* Labb 1 assignment 2
 int b;
 int main(){
 b=9;
 while(1==1){
 if(b<10){
 b--;
 }
 }
 }
 */
/* Labb 1 assignment 3
 unsigned int b;
 int main(){
 b=9;
 while(1==1){
 if(b<10){
 b--;
 }
 }
 }
 */
/* Labb 1 assignment 4
 char b[10];
 int main(){
 int i;
 while(1==1){
 for(i=0;i<10;i++)
 b[i]=i;
 }
 }
 */

/* Labb 1 assignment 5

 int b[10];
 int main(){
 int i;
 while(1==1){
 for(i=0;i<10;i++)
 b[i]=i;
 }
 }
 */
/* Labb 1 assignment 6
 char *address;
 char b;
 int main(){
 b=0;
 address=&b;
 *address=5;
 while(1==1){

 }
 }
 */
/* Labb 1 assignment 7
 char *address;
 int b;
 int main(){
 b=0xFFFFFFF;
 address=(char *)&b+3;
 *address+=0xF0;
 while(1==1){

 }
 }
 */

/* Labb 1 assignment 8
 #include "address_mapping.h"

 unsigned int state;
 unsigned int counter;
 int main(){
 *SWITCHES_CONTROL=0xFFFF;
 *LED_CONTROL=0x0;
 counter=10;
 while (1==1){
 while (counter >= 0){
 state=*SWITCHES_DATA;
 *LED_DATA=counter;
 counter--;
 }
 }
 }
 */

/* Labb 1 assignment 9
 #include "address_mapping.h"

 unsigned int state;
 int main(){
 *SWITCHES_CONTROL=0xFFFF;
 *LED_CONTROL=0x0;
 *LED_DATA=10;
 while (1==1){
 while (*LED_DATA >= 0){
 state=*SWITCHES_DATA;
 *LED_DATA=*LED_DATA-1;
 }
 }
 }
 */

/* Labb 1 assignment 10
 #include "address_mapping.h"

 unsigned int state;
 int main(){
 *SWITCHES_CONTROL=0xFFFF;
 *LED_CONTROL=0x0;
 *SWITCHES_DATA=10;
 while (1==1){
 while (*SWITCHES_DATA >= 0){
 state=*SWITCHES_DATA;
 *SWITCHES_DATA=*SWITCHES_DATA-1;
 }
 }
 }
 */

/* Labb 1 assignment 11
 #include "address_mapping.h"

 int main(){
 *SWITCHES_CONTROL=0xFFFF;
 *LED_CONTROL=0x0;
 while (1==1){
 *LED_DATA=*SWITCHES_DATA;
 }
 }
 */

/* Labb 1 assignment 12
 #include "address_mapping.h"

 unsigned int switchValue;
 unsigned int counter;
 unsigned int ledsBinary;

 int main(){
 *SWITCHES_CONTROL=0xFFFF;
 *LED_CONTROL=0x0;
 while (1==1){
 switchValue = *SWITCHES_DATA;
 counter = 0;
 for(int i = 0; i<16; i++){
 counter += switchValue & 0b000000000000001;
 switchValue = switchValue >> 1;
 }
 ledsBinary = 0;
 for(counter; counter>0; counter--){
 ledsBinary = ledsBinary << 1;
 ledsBinary = ledsBinary | 0b0000000000000001;
 }
 *LED_DATA = ledsBinary;
 }
 }
 */

/* Labb 2 assignment 1
 unsigned int *LED_1;
 unsigned int value;
 int i;
 int main() {
 LED_1 = (unsigned int *) 0x44A00000;
 //	LED_1 = 0x44A00000;
 while (1 == 1) {
 value = 1;
 for (i = 1; i < 32; i++) {
 *LED_1 = value;
 value = value << 1;
 }
 }
 }*/
/* Labb 2 assignment 4
 #include "displays.h"
 unsigned char i;
 int main() {
 while (1 == 1) {
 for (i = 0; i < 10; i++)
 displayDigitAtIndex(i % 8, i);
 }
 }*/
/* Labb 2 assignment 5 -6
 #include "displays.h"
 int main(){
 while (1==1){
 displayNumber(123);
 displayNumber(1234);
 displayNumber(555);
 displayNumber(00001);
 displayNumber(10000002);
 }
 }*/
/* labb 2 assignment 7
 #include "displays.h"
 int main(){
 while (1==1){
 resetDisplays();
 displayNumber(123);
 resetDisplays();
 displayNumber(1234);
 resetDisplays();
 displayNumber(555);
 resetDisplays();
 displayNumber(00001);
 resetDisplays();
 displayNumber(10000002);
 resetDisplayAtIndex(4);
 resetDisplayAtIndex(7);
 resetDisplayAtIndex(6);
 resetDisplayAtIndex(5);
 resetDisplayAtIndex(3);
 resetDisplayAtIndex(2);
 resetDisplayAtIndex(1);
 resetDisplayAtIndex(0);
 }
 }*/

/* Labb 2 assignment 8
 #include "displays.h"
 int main(){
 while (1==1){
 displayNumberAtIndex(123,2);
 displayNumberAtIndex(555555,2);
 displayNumberAtIndex(20,4);
 displayNumberAtIndex(10000,5);
 displayNumberAtIndex(10,7);
 displayNumberAtIndex(1,7);
 }
 }
 */

/* Labb 2 assignment 9
 #include "buttons.h"
 unsigned int state;
 int main(){
 *BUTTONS_CONTROL=0xFFFFFFFF; //Varför är minnet 1F000000, och inte FFFFFFFF. Och varför fungerar det även om vi sätter hela minnet till nollor?
 while (1==1){
 state=*BUTTONS_DATA;
 }
 }
 */

/*Labb 2 assignment 11
 #include "buttons.h"
 #include "displays.h"
 unsigned int counter;
 int main(){
 *BUTTONS_CONTROL=0xFFFFFFFF;
 //*BUTTONS_CONTROL=0x00000000; Varför funkar detta också? Om data_control är nollor så borde de väl inte kunna tolkas som input devices?
 counter=0;
 while (1==1){
 resetDisplays();
 displayNumber(counter);
 while (*BUTTONS_DATA==0); // keep reading the data register
 if (*BUTTONS_DATA==UP)
 if(counter < 99999999){ //we added this if-statement...
 counter++;
 }
 if (*BUTTONS_DATA==DOWN) //...and this
 if(counter > 0){
 counter--;
 }
 while(*BUTTONS_DATA!=0); //...and this while loop
 }
 }*/

/*Labb 2 assignment 12
 #include "buttons.h"
 #include "displays.h"
 unsigned int counter;
 unsigned int buttons_state;
 int main() {
 *BUTTONS_CONTROL = 0xFFFFFFFF;
 counter = 0;
 while (1 == 1) {
 resetDisplays();
 displayNumber(counter);
 while (*BUTTONS_DATA == 0); // keep reading the data register
 buttons_state = *BUTTONS_DATA;
 if (buttons_state == UP) //Om man håller inne två knappar, hur kommer den förbi något if-statement
 counter++;
 if (buttons_state == DOWN)
 counter--;
 while (*BUTTONS_DATA == buttons_state);
 }
 }
 /*
 /* Labb 2 assignment 13
 #include "buttons.h"
 #include "displays.h"
 unsigned int counter;
 unsigned int buttons_state;
 unsigned int i;
 int main() {
 *BUTTONS_CONTROL = 0xFFFFFFFF;
 counter = 0;
 while (1 == 1) {
 resetDisplays();
 displayNumber(counter);
 while (*BUTTONS_DATA == 0);
 for (i = 0; i < 20000; i++);
 buttons_state = *BUTTONS_DATA;
 if (buttons_state == UP)
 counter++;
 if (buttons_state == DOWN)
 counter--;
 while (*BUTTONS_DATA == buttons_state);
 for (i = 0; i < 20000; i++);
 }
 }
 */

/* assignment 14 Labb 2
 #include "buttons.h"
 #include "displays.h"
 unsigned int counter;
 unsigned int buttons_state;
 unsigned int i;
 int main() {
 *BUTTONS_CONTROL = 0xFFFFFFFF;
 //*BUTTONS_CONTROL = 0x00000000;
 counter = 0;
 while (1 == 1) {
 resetDisplays();
 displayNumber(counter);
 while (*BUTTONS_DATA == 0);
 for (i = 0; i < 20000; i++);
 buttons_state = *BUTTONS_DATA;
 if ((buttons_state & UP) == UP)
 counter++;
 if ((buttons_state & DOWN) == DOWN)
 counter--;
 while (*BUTTONS_DATA == buttons_state); //why this?
 for (i = 0; i < 20000; i++);
 }
 }*/

/* assignment 15 labb 2
 #include "buttons.h"
 #include "displays.h"
 unsigned int counter;
 unsigned int buttons_state;
 unsigned int i;
 int main() {
 *BUTTONS_CONTROL = 0xFFFFFFFF;
 //*BUTTONS_CONTROL = 0x00000000;
 counter = 0;
 resetDisplays();
 displayNumber(counter);
 while (1 == 1) {
 while (*BUTTONS_DATA == 0);
 for (i = 0; i < 20000; i++);
 buttons_state = *BUTTONS_DATA;
 if ((buttons_state & UP) == UP)
 if (counter < 99999999) {
 counter++;}
 if ((buttons_state & DOWN) == DOWN)
 if (counter > 0) {
 counter--;}
 resetDisplays();
 displayNumber(counter);
 while (*BUTTONS_DATA == buttons_state); //why this?
 for (i = 0; i < 20000; i++);
 }
 }
 */
/* assignment 17 labb 2
 #include "buttons.h"
 #include "displays.h"
 unsigned int counter;
 unsigned int buttons_state;
 unsigned int i;
 unsigned int old_buttons_state;
 unsigned char index;
 unsigned char nbrOfDigits;
 int main() {
 *BUTTONS_CONTROL = 0xFFFFFFFF;
 counter = 0;
 index = 0;
 resetDisplays();
 displayNumber(counter);
 old_buttons_state = *BUTTONS_DATA;
 while (1 == 1) {
 while (*BUTTONS_DATA == 0);
 while (*BUTTONS_DATA == buttons_state)
 for (i = 0; i < 20000; i++);
 buttons_state = *BUTTONS_DATA;

 if (((old_buttons_state & buttons_state) != UP) && ((buttons_state & UP) == UP) && (counter < 99999999)) {
 nbrOfDigits = numberOfDigits(counter + 1);
 if((nbrOfDigits + index) < 9){
 counter++;
 }
 }

 if (((old_buttons_state & buttons_state) != DOWN) && ((buttons_state & DOWN) == DOWN) && (counter > 0)){
 counter--;
 }

 if(((old_buttons_state & buttons_state) != MIDDLE) && ((buttons_state & MIDDLE) == MIDDLE)){
 counter = 0;
 index = 0;
 }

 if(((old_buttons_state & buttons_state) != RIGHT) && ((buttons_state & RIGHT) == RIGHT) && (index > 0)){
 index--;
 }

 if(((old_buttons_state & buttons_state) != LEFT) && ((buttons_state & LEFT) == LEFT)){
 nbrOfDigits = numberOfDigits(counter);
 if((nbrOfDigits + index) < 8){
 index++;
 }
 }

 resetDisplays();
 displayNumberAtIndex(counter, index);
 old_buttons_state = buttons_state;
 for (i = 0; i < 20000; i++);
 }
 }
 */
/* labb 2 last assignment
 #include "buttons.h"
 #include "displays.h"
 unsigned int counter;
 unsigned int buttons_state;
 unsigned int i;
 unsigned int old_buttons_state;
 unsigned char index;
 unsigned char nbrOfDigits;
 int main() {
 *BUTTONS_CONTROL = 0xFFFFFFFF;
 counter = 0;
 index = 0;
 resetDisplays();
 displayNumber(counter);
 while (1 == 1) {
 while (*BUTTONS_DATA == 0);
 for (i = 0; i < 20000; i++);
 while (*BUTTONS_DATA == buttons_state);
 for (i = 0; i < 20000; i++);
 buttons_state = *BUTTONS_DATA;

 if (((old_buttons_state & UP) != UP) && ((buttons_state & UP) == UP) && (counter < 99999999)) {
 nbrOfDigits = numberOfDigits(counter + 1);
 if((nbrOfDigits + index) < 9){
 counter++;
 }
 }

 if (((old_buttons_state & DOWN) != DOWN) && ((buttons_state & DOWN) == DOWN) && (counter > 0)){
 counter--;
 }

 if(((old_buttons_state & MIDDLE) != MIDDLE) && ((buttons_state & MIDDLE) == MIDDLE)){
 counter = 0;
 index = 0;
 }

 if(((old_buttons_state & RIGHT) != RIGHT) && ((buttons_state & RIGHT) == RIGHT) && (index > 0)){
 index--;
 }

 if(((old_buttons_state & LEFT) != LEFT) && ((buttons_state & LEFT) == LEFT)){
 nbrOfDigits = numberOfDigits(counter);
 if((nbrOfDigits + index) < 8){
 index++;
 }
 }

 resetDisplays();
 displayNumberAtIndex(counter, index);
 old_buttons_state = buttons_state;
 }
 }
 */

/*/ Labb 3 assignment 1
 #include "address_mapping.h"
 void readSwitches_writeLed();
 int main() {
 *SWITCHES_CONTROL = 0xFFFF;
 *LED_CONTROL = 0;
 while (1 == 1)
 readSwitches_writeLed();
 }
 void readSwitches_writeLed() {
 unsigned int temp;
 temp = *SWITCHES_DATA;
 *LED_DATA = temp;
 }*/
/*Labb 3 assignment 2
 #include "address_mapping.h"
 void readSwitches_writeLed();
 unsigned int readSwitches();
 void writeLed(unsigned int value);
 int main() {
 *SWITCHES_CONTROL = 0xFFFF;
 *LED_CONTROL = 0;
 while (1 == 1)
 readSwitches_writeLed();
 }
 void readSwitches_writeLed() {
 unsigned int temp;
 temp = readSwitches();
 writeLed(temp);
 }
 unsigned int readSwitches() {
 unsigned int temp;
 temp = *SWITCHES_DATA;
 return temp;
 }
 void writeLed(unsigned int value) {
 *LED_DATA = value;
 }*/
//void writeLed(unsigned int value, unsigned int v1, unsigned int v2,unsigned int v3,unsigned int v4,unsigned int v5);
//writeLed(temp, temp + 1, temp + 2,temp + 3,temp + 4,temp + 5); //the i-th argument is temp+i
//void writeLed(unsigned int value, unsigned int v1, unsigned int v2, unsigned int v3, unsigned int v4, unsigned int v5, unsigned int v6, unsigned int v7) {
/*
 #include "address_mapping.h"
 void readSwitches_writeLed();
 unsigned int readSwitches();
 void writeLed(unsigned int value, unsigned int v1, unsigned int v2, unsigned int v3, unsigned int v4, unsigned int v5, unsigned int v6, unsigned int v7);
 int main() {
 *SWITCHES_CONTROL = 0xFFFF;
 *LED_CONTROL = 0;
 while (1 == 1)
 readSwitches_writeLed();
 }
 void readSwitches_writeLed() {
 unsigned int temp;
 temp = readSwitches();
 writeLed(temp, temp + 1, temp + 2,temp + 3,temp + 4,temp + 5,temp + 6,temp + 7); //the i-th argument is temp+i
 }
 unsigned int readSwitches() {
 unsigned int temp;
 temp = *SWITCHES_DATA;
 return temp;
 }
 void writeLed(unsigned int value, unsigned int v1, unsigned int v2, unsigned int v3, unsigned int v4, unsigned int v5, unsigned int v6, unsigned int v7) {
 *LED_DATA = value;
 }
 */
/* Labb 3 assignment 4
 #include "address_mapping.h"
 #include "assemblyImplementations.h"
 int main() {
 *SWITCHES_CONTROL = 0xFFFF;
 *LED_CONTROL = 0;
 while (1 == 1)
 readSwitches_writeLed_Assembly();
 }
 */
/* Labb 3 assignment 5
 #include "address_mapping.h"
 #include "assemblyImplementations.h"
 int main() {
 *SWITCHES_CONTROL = 0xFFFF;
 *LED_CONTROL = 0;
 while (1 == 1)
 function();
 }
 */

/* Labb 3 assignment 6
 #include "address_mapping.h"
 #include "assemblyImplementations.h"
 int main() {
 *SWITCHES_CONTROL = 0xFFFF;
 *LED_CONTROL = 0;
 while (1 == 1)
 process_switches();
 }
 */
/*labb 3 assignment 8
 #include "address_mapping.h"
 #include "assemblyImplementations.h"
 int main() {
 *SWITCHES_CONTROL = 0xFFFF;
 *LED_CONTROL = 0;
 while (1 == 1)
 process_all_switches();
 }
 */
/* labb 4 asignment 1
 #include "displays.h"
 #include "address_mapping.h"
 #include "buttons.h"
 #include "interrupt_controller.h"
 #include "timers.h"
 #include "microBlaze.h"
 unsigned int currentButtonsState = 0;
 unsigned int prevButtonsState = 0;
 unsigned int blinker = 0b0001000;
 unsigned int blinkerOnOff = 0;
 unsigned int application_state = 0;
 unsigned char index_pos = 0;
 unsigned char prev_index_pos = 0;
 int main() {
 resetDisplays();
 initTimers();
 initController();
 enableMicroBlazeInterrupts();
 enableTimers();
 while (1 == 1) {
 switch (application_state) {
 case 0:
 *LED_DATA = 1 << application_state;
 if (currentButtonsState != prevButtonsState) {
 if (((currentButtonsState & MIDDLE)!= (prevButtonsState & MIDDLE)) && ((currentButtonsState & MIDDLE) != 0))
 application_state++;
 if (((currentButtonsState & LEFT) != (prevButtonsState & LEFT)) && ((currentButtonsState & LEFT) != 0))
 if (index_pos< 7){
 prev_index_pos = index_pos;
 index_pos++;
 }
 if (((currentButtonsState & RIGHT) != (prevButtonsState & RIGHT)) && ((currentButtonsState & RIGHT) != 0))
 if (index_pos > 0){
 prev_index_pos = index_pos;
 index_pos--;
 }
 prevButtonsState = currentButtonsState;
 }
 *((unsigned int *)(SEVEN_SEGMENT_DISPLAY_BASE + prev_index_pos* 4)) = 0;
 *((unsigned int *)(SEVEN_SEGMENT_DISPLAY_BASE + index_pos* 4)) = blinker & blinkerOnOff;
 break;
 case 1:
 *LED_DATA = 1 << application_state;
 if (currentButtonsState != prevButtonsState) {
 if (((currentButtonsState & MIDDLE)!= (prevButtonsState & MIDDLE))&& ((currentButtonsState & MIDDLE) != 0))
 application_state++;
 if (((currentButtonsState & RIGHT) != (prevButtonsState & RIGHT)) && ((currentButtonsState & RIGHT) != 0))
 if (index_pos< 7){
 prev_index_pos = index_pos;
 index_pos++;
 }
 if (((currentButtonsState & LEFT) != (prevButtonsState & LEFT)) && ((currentButtonsState & LEFT) != 0))
 if (index_pos > 0){
 prev_index_pos = index_pos;
 index_pos--;
 }
 prevButtonsState = currentButtonsState;
 }
 *((unsigned int *)(SEVEN_SEGMENT_DISPLAY_BASE + prev_index_pos* 4)) = 0;
 *((unsigned int *)(SEVEN_SEGMENT_DISPLAY_BASE + index_pos* 4)) = blinker & blinkerOnOff;
 break;
 case 2:
 *LED_DATA = 1 << application_state;
 if (currentButtonsState != prevButtonsState) {
 if (((currentButtonsState & MIDDLE) != (prevButtonsState & MIDDLE)) && ((currentButtonsState & MIDDLE) != 0))
 application_state++;
 if (((currentButtonsState & UP) != (prevButtonsState & UP)) && ((currentButtonsState & UP) != 0))
 if (index_pos< 7){
 prev_index_pos = index_pos;
 index_pos++;
 }
 if (((currentButtonsState & DOWN) != (prevButtonsState & DOWN)) && ((currentButtonsState & DOWN) != 0))
 if (index_pos> 0){
 prev_index_pos = index_pos;
 index_pos--;
 }
 prevButtonsState = currentButtonsState;
 }
 *((unsigned int *)(SEVEN_SEGMENT_DISPLAY_BASE + prev_index_pos* 4)) = 0;
 *((unsigned int *)(SEVEN_SEGMENT_DISPLAY_BASE + index_pos* 4)) = blinker & blinkerOnOff;
 break;
 case 3:
 *LED_DATA = 1 << application_state;
 if (currentButtonsState != prevButtonsState) {
 if (((currentButtonsState & MIDDLE) != (prevButtonsState & MIDDLE)) && ((currentButtonsState & MIDDLE) != 0))
 application_state=0;
 if (((currentButtonsState & DOWN) != (prevButtonsState & DOWN)) && ((currentButtonsState & DOWN) != 0))
 if (index_pos< 7){
 prev_index_pos = index_pos;
 index_pos++;
 }
 if (((currentButtonsState & UP) != (prevButtonsState & UP)) && ((currentButtonsState & UP) != 0))
 if (index_pos> 0){
 prev_index_pos = index_pos;
 index_pos--;
 }
 prevButtonsState = currentButtonsState;
 }
 *((unsigned int *)(SEVEN_SEGMENT_DISPLAY_BASE + prev_index_pos* 4)) = 0;
 *((unsigned int *)(SEVEN_SEGMENT_DISPLAY_BASE + index_pos* 4)) = blinker & blinkerOnOff;
 break;
 default:
 break;
 }

 }
 }
 */

#include "displays.h"
#include "address_mapping.h"
#include "buttons.h"
#include "interrupt_controller.h"
#include "timers.h"
#include "microBlaze.h"
#include "alarm_clock.h"

/*
 *  Keeps the current state of the push buttons. Modified only in the interrupt handler for TIMER1 timer1AlarmClockInterruptHandler()
 */
unsigned int currentButtonsState = 0;

/*
 *  Keeps the previous state of the push buttons
 */
unsigned int prevButtonsState = 0;

/*
 *  Keeps the binary pattern for the bottom-most horizontal segment
 */
unsigned int blinker = 0b0001000;

/*
 *  Changes from 0x00000000 to 0xFFFFFFFF and vice-versa. Modified only in the interrupt handler for TIMER1 timer1AlarmClockInterruptHandler()
 *  Used to indicate if the blinker should be on or off
 */
unsigned int blinkerOnOff = 0;

/*
 *  Keeps track of the current state of the alarm-clock.
 *  value 0 == RUN state
 *  value 1 == SET_TIME state
 *  value 2 == SET_ALARM state
 *  value 3 == ALARM state
 */
unsigned int alarmclock_state = 0;

/*
 *  Keeps track of the index of the seven-segment display whose value might be modified by pressing the up or the down button
 */
unsigned char index_pos = 0;

/*
 *  Keeps the time set by the user.
 *  Element at index 0 refers to hours and should only accept values in the range 0-23
 *  Element at index 1 refers to minutes and should only accept values in the range 0-59
 *  Element at index 2 refers to seconds and should only accept values in the range 0-59
 *  Element at index 3 refers to hundreds of a second and should only accept values in the range 0-99
 */
unsigned char newTime[4];

/*
 *  Keeps the running time.
 *  Modified in the interrupt handler for TIMER1 timer1AlarmClockInterruptHandler() or when the state changes from SET_TIME to RUN
 *  Element at index 0 refers to hours and should only accept values in the range 0-23
 *  Element at index 1 refers to minutes and should only accept values in the range 0-59
 *  Element at index 2 refers to seconds and should only accept values in the range 0-59
 *  Element at index 3 refers to hundreds of a second and should only accept values in the range 0-99
 */
unsigned char currentTime[4];

/*
 *  Keeps the time that indicates when the alarm goes off.
 *  Element at index 0 refers to hours and should only accept values in the range 0-23
 *  Element at index 1 refers to minutes and should only accept values in the range 0-59
 *  Element at index 2 refers to seconds and should only accept values in the range 0-59
 *  Element at index 3 refers to hundreds of a second and should only accept values in the range 0-99
 */
unsigned char alarmTime[4];


/*
 *  Implement the code based on the description written as a comment
 */
int main() {
	resetDisplays();
	initTimers_alarmClock();
	initController_alarmClock();
	enableTimer1();
	enableMicroBlazeInterrupts();
	while (1 == 1) {
		switch (alarmclock_state) {
		case 0:
			/*
			 * Turn off the 16 LEDs.
			 * Displays the current time on the eight seven-segment displays
			 * Changes the state of the alarm-clock to ALARM and enables TIMER2 only if the current time is the same as the alarm time and the leftmost switch is turned on
			 * Checks if the UP or DOWN button are pressed now but has not been pressed before
			 * If the UP button is pressed now, but has not been pressed before
			 * 			-the state of the alarm-clock changes to SET_TIME
			 * 			-the newTime is set to the same value as the currentTime
			 * 			-the newTime is displayed on the eight seven-segment displays
			 * 			-the index_pos is initialized to zero
			 * If the DOWN button is pressed now, but has not been pressed before
			 * 			-the state of the alarm-clock changes to SET_ALARM
			 * 			-the alarmTime is displayed on the eight seven-segment displays
			 * 			-the index_pos is initialized to zero
			 * 			-the 16 LEDs are turned on
			 */
			*LED_DATA = 0;
			display(currentTime);
			if((compareTimeArray(currentTime,alarmTime) == 1) && (0b1000000000000000 == (*SWITCHES_DATA & 0b1000000000000000)) ){
				alarmclock_state = 3;
				enableTimer2();
			}
			if(currentButtonsState != prevButtonsState){
				if (((currentButtonsState & UP)!= (prevButtonsState & UP)) && ((currentButtonsState & UP) != 0)){
					alarmclock_state=1;
					setTime(newTime,currentTime);
					display(newTime);
					index_pos = 0;
				}
				if (((currentButtonsState & DOWN)!= (prevButtonsState & DOWN)) && ((currentButtonsState & DOWN) != 0)){
					alarmclock_state=2;
					display(alarmTime);
					index_pos = 0;
					*LED_DATA=0xFFFF;
				}
			prevButtonsState = currentButtonsState;
			}
			break;
		case 1:
			/*
			 * Only when the state of the buttons has changed, the newTime is displayed
			 * If the UP or DOWN buttons are pressed now, but have not been pressed before
			 * 		-based on the index_pos, the corresponding element in the newTime array is incremented or decremented
			 * If the LEFT or RIGHT buttons are pressed now, but have not been pressed before
			 * 		-the index_pos is incremented/decremented by 2
			 * If the MIDDLE button is pressed now, but has not been pressed before,
			 * 		-the currentTime is set to be the same as the newTime
			 * 		-the state of the alarm-clock changes to RUN
			 * Based on the blinkerOnOff variable, the bottom-most horizontal segments of the displays with indices "index_pos" and "index_pos+1" are turned-on or turned-off
			 * NOTE: The data registers of the SEVEN_SEGMENT_DISPLAY device are read-write registers, i.e. when reading the data register controlling a particular seven-segment display, one obtains the same information that is used to drive (control) the seven-segment display
			 */
			if(currentButtonsState != prevButtonsState){
				display(newTime);
				if (((currentButtonsState & UP)!= (prevButtonsState & UP)) && ((currentButtonsState & UP) != 0)){
					incrementTime(index_pos, newTime);

				}
				if (((currentButtonsState & DOWN)!= (prevButtonsState & DOWN)) && ((currentButtonsState & DOWN) != 0)){
					decrementTime(index_pos, newTime);

				}
				if (((currentButtonsState & LEFT)!= (prevButtonsState & LEFT)) && ((currentButtonsState & LEFT) != 0)){
					if(index_pos < 6){
						index_pos += 2;
					}
				}
				if (((currentButtonsState & RIGHT)!= (prevButtonsState & RIGHT)) && ((currentButtonsState & RIGHT) != 0)){
					if(index_pos > 0){
						index_pos -= 2;
					}
				}
				if (((currentButtonsState & MIDDLE)!= (prevButtonsState & MIDDLE)) && ((currentButtonsState & MIDDLE) != 0)){
					setTime(currentTime, newTime);
					alarmclock_state = 0;
				}
			prevButtonsState = currentButtonsState;
			}
			if(blinkerOnOff == 0){
				*((unsigned int *)(SEVEN_SEGMENT_DISPLAY_BASE + index_pos* 4)) &= ~blinker;
				*((unsigned int *)(SEVEN_SEGMENT_DISPLAY_BASE + ((index_pos + 1)* 4))) &= ~blinker;
			}
			if(blinkerOnOff == -1){
				*((unsigned int *)(SEVEN_SEGMENT_DISPLAY_BASE + index_pos* 4)) |= blinker;
				*((unsigned int *)(SEVEN_SEGMENT_DISPLAY_BASE + ((index_pos + 1)* 4))) |= blinker;
			}

			break;
		case 2:
			/*
			 * Only when the state of the buttons has changed, the alarmTime is displayed
			 * If the UP or DOWN buttons are pressed now, but have not been pressed before
			 * 		-based on the index_pos, the corresponding element in the alarmTime is incremented or decremented
			 * If the LEFT or RIGHT buttons are pressed now, but have not been pressed before
			 * 		-the index_pos is incremented/decremented by 2
			 * If the MIDDLE button is pressed now, but has not been pressed before,
			 * 		-the 16 LEDs are turned off
			 * 		- the state of the alarm-clock changes to RUN
			 * Based on the blinkerOnOff variable, the bottom-most horizontal segments of the displays with indices "index_pos" and "index_pos+1" are turned-on or turned-off
			 * NOTE: The data registers of the SEVEN_SEGMENT_DISPLAY device are read-write registers, i.e. when reading the data register controlling a particular seven-segment display, one obtains the same information that is used to drive (control) the seven-segment display
			 */
			if(currentButtonsState != prevButtonsState){
				display(alarmTime);
				if (((currentButtonsState & UP)!= (prevButtonsState & UP)) && ((currentButtonsState & UP) != 0)){
					incrementTime(index_pos, alarmTime);
				}
				if (((currentButtonsState & DOWN)!= (prevButtonsState & DOWN)) && ((currentButtonsState & DOWN) != 0)){
					decrementTime(index_pos, alarmTime);
				}
				if (((currentButtonsState & LEFT) != (prevButtonsState & LEFT)) && ((currentButtonsState & LEFT) != 0)) {
					if (index_pos < 6) {
						index_pos += 2;
					}
				}
				if (((currentButtonsState & RIGHT)!= (prevButtonsState & RIGHT)) && ((currentButtonsState & RIGHT) != 0)){
					if(index_pos > 0){
						index_pos -= 2;
					}
				}
				if (((currentButtonsState & MIDDLE)!= (prevButtonsState & MIDDLE)) && ((currentButtonsState & MIDDLE) != 0)){
					*LED_DATA=0;
					alarmclock_state=0;
				}
				prevButtonsState = currentButtonsState;
			}
			if(blinkerOnOff == 0){
				*((unsigned int *)(SEVEN_SEGMENT_DISPLAY_BASE + index_pos* 4)) &= ~blinker;
				*((unsigned int *)(SEVEN_SEGMENT_DISPLAY_BASE + ((index_pos + 1)* 4))) &= ~blinker;
			}
			if(blinkerOnOff == -1){
				*((unsigned int *)(SEVEN_SEGMENT_DISPLAY_BASE + index_pos* 4)) |= blinker;
				*((unsigned int *)(SEVEN_SEGMENT_DISPLAY_BASE + ((index_pos + 1)* 4))) |= blinker;
			}

			break;
		case 3:
			/*
			 * Based on the state of blinkerOnOff, the 16 LEDs are turned on or off
			 * Checks if the state of the buttons has changed
			 * If the MIDDLE button is pressed, but has not been pressed before
			 * 		-the alarmTime is incremented by 5s
			 * 		-TIMER2 is stopped and the interrupts in the device are acknowledged
			 * 		-the alarm-clock state is changed to RUN
			 */
			display(alarmTime);
			*LED_DATA = blinkerOnOff;
			if(currentButtonsState != prevButtonsState){
				if (((currentButtonsState & MIDDLE)!= (prevButtonsState & MIDDLE)) && ((currentButtonsState & MIDDLE) != 0)){
					//add increment limit
					snooze();
					*TIMER2_CTRL = *TIMER2_CTRL & ~(1 << 7);
					*TIMER2_CTRL |= (1 << 8);
					alarmclock_state = 0;
					*IAR = 0b100;
				}

				prevButtonsState = currentButtonsState;
			}
			break;
		default:
			break;
		}
	}
}

void initTimers_alarmClock() {
	/*
	 * Implement the code based on the description provided in the header file alarm_clock.h
	 */
	*TIMER1_LOAD = 999999;
	*TIMER1_CTRL = (1 << 8) | (1 << 6) | (1 << 5) | (1 << 4) | (1 << 1);
	*TIMER2_LOAD = 0xFFFFFFFF - 500000000;
	*TIMER2_CTRL = ((1 << 8) | (1 << 6) | (1 << 5)) & (~(1 << 4));

}

void enableTimer1() {
	/*
	 * Implement the code based on the description provided in the header file alarm_clock.h
	 */
	*TIMER1_CTRL = (*TIMER1_CTRL | (1 << 7)) & (~(1 << 5));
}

void enableTimer2() {
	/*
	 * Implement the code based on the description provided in the header file alarm_clock.h
	 */
	*TIMER2_CTRL = *TIMER2_CTRL | (1 << 5);
	*TIMER2_CTRL = (*TIMER2_CTRL | (1 << 7)) & (~(1 << 5));
}

void display(unsigned char *time_array) {
	/*
	 * Implement the code based on the description provided in the header file alarm_clock.h
	 */
	for (unsigned char i = 0; i < 4; i++) {
		if (time_array[i] < 10) {
			displayNumberAtIndex(0, 7 - (2 * i));
		}
		displayNumberAtIndex(time_array[i], 6 - (2 * i));
	}
}

unsigned int compareTimeArray(unsigned char *time_array1,
		unsigned char *time_array2) {
	/*
	 * Implement the code based on the description provided in the header file alarm_clock.h
	 */
	int i;
	for (i = 0; i <= 3; i++) {
		if (time_array1[i] != time_array2[i])
			return 0;
	}
	return 1;

}

void setTime(unsigned char *newTime_array, unsigned char *oldTime_array) {
	/*
	 * Implement the code based on the description provided in the header file alarm_clock.h
	 */
	int i;
	for (i = 0; i <= 3; i++) {
		newTime_array[i] = oldTime_array[i];

	}

}

void initController_alarmClock() {
	/*
	 * Implement the code based on the description provided in the header file alarm_clock.h
	 */

	*IER |= 0b110;
	*IVAR1 = (unsigned int) timer1AlarmClockInterruptHandler;
	*IVAR2 = (unsigned int) timer2AlarmClockInterruptHandler;
	*MER |= 0b11;

}

void timer1AlarmClockInterruptHandler() {
	/*
	 * Implement the code based on the description provided in the header file alarm_clock.h
	 */
	*TIMER1_CTRL |= (1 << 8);
	updateCurrentTime();
	if(currentTime[3] % 2 == 0){
		currentButtonsState = *BUTTONS_DATA;
	}
	if(currentTime[3] % 25 == 0){
		blinkerOnOff = ~blinkerOnOff;
	}
	*IAR = 0b10;
}

void timer2AlarmClockInterruptHandler() {
	/*
	 * Implement the code based on the description provided in the header file alarm_clock.h
	 */
	*TIMER2_CTRL |= (1 << 8);
	alarmclock_state = 0;
	*IAR = 0b100;
}

void updateCurrentTime() {
	if(currentTime[3] == 99){
		currentTime[3] = 0;
		if(currentTime[2] == 59){
			currentTime[2] = 0;
			if(currentTime[1] == 59){
				currentTime[1] = 0;
				if(currentTime[0] == 23){
					currentTime[0] = 0;
				} else {
					currentTime[0]++;
				}
			} else {
				currentTime[1]++;
			}
		} else {
			currentTime[2]++;
		}
	} else {
		currentTime[3]++;
	}
}
void decrementTime(unsigned char index_pos, unsigned char *time_array1) {
	//maybe add cannot exceed min value
	switch (index_pos) {
	case 0:
		if (time_array1[3] > 0) {
			time_array1[3]--;
		} else {
			time_array1[3] = 99;
		}
		break;
	case 2:
		if (time_array1[2] > 0) {
			time_array1[2]--;
		} else {
			time_array1[2] = 59;
		}
		break;
	case 4:
		if (time_array1[1] > 0) {
			time_array1[1]--;
		} else {
			time_array1[1] = 59;
		}
		break;
	case 6:
		if (time_array1[0] > 0) {
			time_array1[0]--;
		} else {
			time_array1[0] = 23;
		}
		break;
	default:
		break;
	}
}

void incrementTime(unsigned char index_pos, unsigned char *time_array) {
	//maybe add cannot exceed max value
	switch (index_pos) {
	case 0:
		if (time_array[3] < 99) {
			time_array[3]++;
		} else {
			time_array[3] = 0;
		}
		break;
	case 2:
		if (time_array[2] < 59) {
			time_array[2]++;
		} else {
			time_array[2] = 0;
		}
		break;
	case 4:
		if (time_array[1] < 59) {
			time_array[1]++;
		} else {
			time_array[1] = 0;
		}
		break;
	case 6:
		if (time_array[0] < 23) {
			time_array[0]++;
		} else {
			time_array[0] = 0;
		}
		break;
	default:
		break;
	}
}

void snooze(){
	//setTime(alarmTime, currentTime);
	if(alarmTime[2] > 49){
		alarmTime[2] = 10 - (60 - alarmTime[2]);
		if(alarmTime[1] == 59){
			alarmTime[1] = 0;
			if(alarmTime[0] == 23){
				alarmTime[0] = 0;
			} else {
				alarmTime[0]++;
			}
		} else {
			alarmTime[1]++;
		}
	} else {
		alarmTime[2]+=10;
	}

}

