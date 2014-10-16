//*****************************************************************************
//!	ENCE463 Project
//! Author: Campbell Reid-Tait
//! Date: 20 August 2014
//! file: "ASCgui.h"
//!
//! This module updates the GUI and display for ASC
//*****************************************************************************
#ifndef ASCGUI_H_
#define ASCGUI_H_


#include "PID.h"
#include "carspeed.h"
#include "button.h"
#include "ride.h"
#include "drivers/rit128x96x4.h"

/*called to update the screen*/
extern void updateGui(void){
		char strBuf[bufsize];
	char strBuf1[bufsize];

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
		char strBuf2[bufsize];
		char strBuf3[bufsize];
		char strBuf4[bufsize];

		uint32_t * adc_reading_test;

		adc_reading_test  = readADC();
		//uint32_t adc_reading_test[4] = {1,2,1,2};

		sprintf(strBuf2, "ADC1: %lu", adc_reading_test[0]);
		sprintf(strBuf3, "ADC2: %lu", adc_reading_test[1]);
		sprintf(strBuf4, "ADC2: %lu", adc_reading_test[2]);

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


}

/*initilises the screen and gui */
extern void initGui(void){
	
}

/*Take button inputs to for user interface eg. change screen, change ride type*/
extern void ascGui(void){
	
}

/*Display to damping factor and actuation force transmitted to WUC and the sensor outputs received from ASC*/
extern void displaySuspension(SimOut disNAccel, ConOut forceDamp){
	
}

/*Display the ride type, acceleration and speed of the car*/
extern void displayMotion(float currSpeed, float currAccel){
	
}

/*Display the status of WUC */
extern void displayWUS(char[30] WUS_status){
	
}

#endif /* ASCGUI_H_ */