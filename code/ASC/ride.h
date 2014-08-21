//*****************************************************************************
//!	ENCE463 Progect
//! Author: Campbell Reid-Tait
//! Date: 20 August 2014
//! file: "ride.h"
//!
//! This modules changes the current ride infomation 
//*****************************************************************************

#ifndef RIDE_H_
#define RIDE_H_

#include "pwm.h"

/*Change the ride type (sedate, normal, sport, rally).*/
extern void rideType (int newRide);

/*Return the Bs and send Bs to WUS via PWM.*/
extern int genRide(void);

#endif /* RIDE_H_ */
