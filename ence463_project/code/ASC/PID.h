//*****************************************************************************
//!	ENCE463 Project
//! Author: Campbell Reid-Tait
//! Date: 20 August 2014
//! file: "PID.h"
//!
//! This module does everything to do with the PID controller
//*****************************************************************************
#ifndef PID_H_
#define PID_H_

#include "PWM.h"
#include "ADC.h"
#include "ride.h"

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

/*Read the ADC signals from WUS and convert them into sprung and unsprung acceleration, and wheel height*/
extern SimOut readSensorOut(void);

/*Calculate the damping factor and force actuation and generate PWM wave 
which are transmitted to WUS via PWM signals.*/
extern ConOut calcPID (SimOut sensOut, int rideType);

#endif /* PID_H_ */
