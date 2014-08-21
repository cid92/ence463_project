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

#include "carparameters.h"
#include "PWM.h"

/*Calculate the damping factor and force actuation and generate PWM wave 
which are transmitted to WUS via PWM signals.*/
extern ConOut calcPID (SimOut disNAccel);

#endif /* PID_H_ */
