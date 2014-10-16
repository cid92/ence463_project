//*****************************************************************************
//!	ENCE463 Project
//! Author: Campbell Reid-Tait, Cid Gilani
//! Date: 20 August 2014
//! file: "WUSgui.c"
//!
//! This module updates the GUI and display for WUS
//*****************************************************************************



#include "ASCgui.h"
#define bufsize 20

int x = 0;
extern int testValue = 0;
extern float accel = 0;
extern int accel1 = 0;
extern int accel2 = 0;
extern int state = 0;
extern int state1 = 0;
int testValue_old = 0;
/*called to update the screen*/
extern void updateGui(void)
{

}


/*initializes the screen and Gui */
extern void initGui(void)
{
	// intialise the OLED display
	RIT128x96x4Init(1000000);
	RIT128x96x4Clear();
	testValue = -1;
}

/*Choose the screen to display with buttons*/
extern void displayGui(void)
{
	char strBuf[bufsize];
	char strBuf1[bufsize];
	char strBuf2[bufsize];
	char strBuf3[bufsize];
	uint32_t * adc_reading_test;
	//RIT128x96x4Clear();
	if (state == 0){
		RIT128x96x4StringDraw( "Team 2",  40, 10, 15);
		RIT128x96x4StringDraw( "ASC", 10, 20, 15);
		RIT128x96x4StringDraw( "Press Select", 10, 30, 15);
		RIT128x96x4StringDraw( "To Continue...", 10, 40, 15);
	}

	if (state == 1){
		if (state1 <= 1 && state1!= -1){
			RIT128x96x4Clear();
			state1++;
		}
		else if (state1 > 1){
			state1 = -1;
		}
		adc_reading_test  = readADC();
		sprintf(strBuf, "zS: %lu", adc_reading_test[0]);
		sprintf(strBuf1, "zU: %lu", adc_reading_test[1]);
		sprintf(strBuf2, "zSU: %lu", adc_reading_test[2]);
		RIT128x96x4StringDraw( "ADC Readings",  35, 10, 15);
		RIT128x96x4StringDraw(strBuf, 10, 30, 15);
		RIT128x96x4StringDraw(strBuf1, 10, 40, 15);
		RIT128x96x4StringDraw(strBuf2, 10, 50, 15);
	}
	if (state == 2){
		if (state1 <= 1 && state1!= -1){
			RIT128x96x4Clear();
			state1++;
		}
		else if (state1 > 1){
			state1 = -1;
		}
		//sprintf(strBuf, "zS: %3.2f", (float)2.56);
		sprintf(strBuf1, "zU: %lu", accel);
		RIT128x96x4StringDraw( "Accel&Vel",  35, 10, 15);
		//RIT128x96x4StringDraw(strBuf, 10, 20, 15);
		RIT128x96x4StringDraw(strBuf1, 10, 30, 15);
		RIT128x96x4StringDraw( "Accel.: UP",  35, 50, 15);
		RIT128x96x4StringDraw( "Decel.: DOWN",  35, 60, 15);
		RIT128x96x4StringDraw( "Speed: SELECT",  35, 70, 15);
	}
	if (state == 3){
		if (state1 <= 1 && state1!= -1){
			RIT128x96x4Clear();
			state1++;
		}
		else if (state1 > 1){
			state1 = -1;
		}
		RIT128x96x4StringDraw( "WUS Status",  30, 10, 15);
		sprintf(strBuf, "RX: 0x%x", 0);
		sprintf(strBuf1, "TX: 0x%x", 0);
		sprintf(strBuf2, "Road Type: %d", roadtype);
		RIT128x96x4StringDraw(strBuf, 10, 20, 15);
		RIT128x96x4StringDraw( strBuf1,  10, 30, 15);
		RIT128x96x4StringDraw( strBuf2,  10, 50, 15);
		if (ridenum == 0){
			RIT128x96x4StringDraw("Ride Type: Sedate",  10, 60, 15);
		}
		else if(ridenum == 1){
			RIT128x96x4StringDraw("Ride Type: Normal",  10, 60, 15);
		}
		else if(ridenum == 2){
			RIT128x96x4StringDraw("Ride Type: Sport",  10, 60, 15);
		}
		else if(ridenum == 3){
			RIT128x96x4StringDraw("Ride Type: Rally",  10, 60, 15);
		}
	}

}







/*Take button inputs to for user interface to change screen display*/
extern void wusGui(void)
{

}


/*Display the acceleration and speed of the car*/
extern void displayMotion(float currSpeed, float currAccel)
{

}




