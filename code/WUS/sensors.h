//**********************************************************************************************
//!	ENCE463 Project
//! Author: Cid Gilani
//! Date: 20 August 2014
//! file: "sensors.h"
//!
//! This module calculates the sensor outputs required to be transmitted to ASC via PWM signals
//**********************************************************************************************

#ifndef SENSORS_H_
#define SENSORS_H_

#include "carparameters.h"
#include "roadgen.h"
#include "pwm.h"
#include "ADC.h"

extern  SimOut sensorOutput(SimGen surfaceBump, ConOut forceDamp, SusState disNvelo, float tStep);

#endif /* SENSORS_H_ *