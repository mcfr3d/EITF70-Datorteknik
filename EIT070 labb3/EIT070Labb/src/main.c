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
//labb 3 assignment 8
#include "address_mapping.h"
#include "assemblyImplementations.h"
int main() {
	*SWITCHES_CONTROL = 0xFFFF;
	*LED_CONTROL = 0;
	while (1 == 1)
		process_all_switches();
}


