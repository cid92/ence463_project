//*****************************************************************************
//!	ENCE463 Project
//! Author: Cid Gilani
//! Date: 20 August 2014
//! file: "carspeed.h"
//!
//! This module has a function that calculates and reads speed pulse
//*****************************************************************************

#ifndef CARSPEED_H_
#define CARSPEED_H_

#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"

/*Initialise pin interrupt to read the car speed from WUS*/
extern void initSpeedInt(void);

/*read the pulse signal from WUS that represent the car speed*/
extern float readCurrSpeed(float currSpeed);

/*Initialise the time interrupt to  generate  pulse signal that represent the car speed to ASC
The pulse signal is produced by using FreeRTOS*/
extern void initSpeedGen(void); 

/*calculate the car speed from car acceleration receive via UART and send pulse signal to ASC*/
extern float genCurrSpeed(float currAccel);

#endif /* CARSPEED_H_ *