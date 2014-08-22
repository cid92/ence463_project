//**********************************************************************************************
//!	ENCE463 Project
//! Author: Cid Gilani
//! Date: 20 August 2014
//! file: "carsim.h"
//!
//! This module simulates the car and produce sensor outputs which are be transmitted to ASC via PWM signals
//**********************************************************************************************

#ifndef CARSIM_H_
#define CARSIM_H_


#include "roadgen.h"
#include "pwm.h"
#include "ADC.h"

/*These parameters are calculated by the WUS and sent to ASC */
extern struct SimOut {
	float unsprungAccel;
	float sprungAccel;
	float wheelHeight;
};

/*These parameters are calculated by the ASC and sent to WUS */
extern struct ConOut {
	float actuatorForce;
	float dampingFactor;
};

extern struct SusState {
	float sprungDis;
	float sprungVel;
	float unsprungDis;
	float unsprungVel;
};

/*Read the ADC signals from ASC and convert the them to force actuation and damping factor*/
extern ConOut readPIDOut(void);

/*Simulate the car suspensions and generate PWM signal to send the sensor outputs to ASC*/
extern  SimOut sensorOutput(SimGen surfaceBump, ConOut pidOut, SusState Suspension, float tStep);

#endif /* CARSIM_H_ *