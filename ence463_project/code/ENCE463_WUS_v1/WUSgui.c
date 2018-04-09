//*****************************************************************************
//!	ENCE463 Project
//! Author: Campbell Reid-Tait, Cid Gilani
//! Date: 20 August 2014
//! file: "WUSgui.c"
//!
//! This module updates the GUI and display for WUS
//*****************************************************************************



#include "WUSgui.h"
#define bufsize 20

int x = 0;

extern int testValue = 0;
int testValue_old = 0;

int roadtype = 0;
int roadtype_old = -1;

int wheelHeight = 0;
int wheelHeight_old = -1;


int unsprungAccel = 0;
int unsprungAccel_old = -1;

int sprungAccel = 0;
int sprungAccel_old = -1;

int dampingFactor = 0;
int dampingFactor_old = -1;

int actuatorForce = 0;
int actuatorForce_old = -1;

int speed = 0;
int speed_old = -1;



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
	/*
	char strBuf[bufsize];
	char strBuf1[bufsize];
	char strBuf2[bufsize];
	char strBuf3[bufsize];

	//RIT128x96x4Clear();
	sprintf(strBuf, "Group 2");
	sprintf(strBuf1, "testValue: %d", testValue);

	if (testValue != testValue_old) {
			RIT128x96x4StringDraw( "testValue:          ", 10, 20, 15);
	}

	RIT128x96x4StringDraw( strBuf,  35, 10, 15);
	RIT128x96x4StringDraw( strBuf1, 10, 20, 15);



	RIT128x96x4StringDraw( " . ", x, 90, 15);



	if (x%10 == 0 ){


		uint32_t * adc_reading_test;

		adc_reading_test  = readADC();
		//uint32_t adc_reading_test[4] = {1,2,1,2};

		sprintf(strBuf2, "ADC1: %lu", adc_reading_test[0]);
		sprintf(strBuf3, "ADC2: %lu", adc_reading_test[1]);

		//sprintf(strBuf2, "ADC1: 1");
		//sprintf(strBuf3, "ADC2: 2");

		//clear

		RIT128x96x4StringDraw( "ADC1:     ", 10, 45, 15);
		RIT128x96x4StringDraw( "ADC2:     ", 10, 60, 15);

		RIT128x96x4StringDraw( strBuf2, 10, 45, 15);
		RIT128x96x4StringDraw( strBuf3, 10, 60, 15);
	}

	x++;
	testValue_old = testValue;
	if (x >= 128) x = 0;

	*/



	char strBuf2[bufsize];


	if (roadtype != roadtype_old) {
		RIT128x96x4StringDraw( "Road Type:            ", 10, 10, 15);
		switch (roadtype) {
			case 1 :
				//sprintf(strBuf, "Road Type: %s", "Tarseal");
				RIT128x96x4StringDraw( "Road Type: Tarseal", 10, 10, 15);
				break;
			case 2:
				RIT128x96x4StringDraw( "Road Type: Gravel", 10, 10, 15);
				break;
			case 3:
				RIT128x96x4StringDraw( "Road Type: Track", 10, 10, 15);
				break;
			default:
				RIT128x96x4StringDraw( "Road Type: Error", 10, 10, 15);
				break;
		}
		roadtype_old  = roadtype;
	}

	if (wheelHeight != wheelHeight_old) {
		RIT128x96x4StringDraw( "Height:            ", 10, 20, 15);
		sprintf(strBuf2, "Height: %d", wheelHeight);
		RIT128x96x4StringDraw( strBuf2, 10, 20, 15);
		wheelHeight_old  = wheelHeight;
	}

	if (unsprungAccel != unsprungAccel_old) {
		RIT128x96x4StringDraw( "UA:            ", 10, 30, 15);
		sprintf(strBuf2, "UA: %d", unsprungAccel);
		RIT128x96x4StringDraw( strBuf2, 10, 30, 15);
		unsprungAccel_old  = unsprungAccel;
	}
	if (sprungAccel != sprungAccel_old) {
		RIT128x96x4StringDraw( "SA:            ", 10, 40, 15);
		sprintf(strBuf2, "SA: %d", sprungAccel);
		RIT128x96x4StringDraw( strBuf2, 10, 40, 15);
		sprungAccel_old  = sprungAccel;
	}
	if (dampingFactor != dampingFactor_old) {
		RIT128x96x4StringDraw( "DF:            ", 10, 50, 15);
		sprintf(strBuf2, "DF: %d", dampingFactor);
		RIT128x96x4StringDraw( strBuf2, 10, 50, 15);
		dampingFactor_old  = dampingFactor;
	}
	if (actuatorForce != actuatorForce_old) {
		RIT128x96x4StringDraw( "AF:            ", 10, 60, 15);
		sprintf(strBuf2, "AF: %d", actuatorForce);
		RIT128x96x4StringDraw( strBuf2, 10, 60, 15);
		actuatorForce_old  = actuatorForce;
	}
	if (speed != speed_old) {
		RIT128x96x4StringDraw( "speed:            ", 10, 70, 15);
		sprintf(strBuf2, "speed: %d", speed/1000);
		RIT128x96x4StringDraw( strBuf2, 10, 70, 15);
		speed_old  = speed;
	}

	RIT128x96x4StringDraw( " . ", x, 90, 15);
	x++;
	if (x >= 128) x = 0;



}







/*Take button inputs to for user interface to change screen display*/
extern void wusGui(void)
{

}


/*Display the acceleration and speed of the car*/
extern void displayMotion(float currSpeed, float currAccel)
{

}




