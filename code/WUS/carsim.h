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

#include "carparameters.h"
#include "roadgen.h"
#include "pwm.h"
#include "ADC.h"

/*Simulate the car suspensions and generate PWM signal to send the sensor outputs to ASC*/
extern  SimOut sensorOutput(SimGen surfaceBump, ConOut forceDamp, SusState disNvelo, float tStep);

#endif /* CARSIM_H_ *