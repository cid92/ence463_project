//*****************************************************************************
//!	ENCE463 Project
//! Author: Campbell Reid-Tait
//! Date: 20 August 2014
//! file: "timer.h"
//!
//! Interlises the timer
//*****************************************************************************
#ifndef MYTIMER_H_
#define MYTIMER_H_


#include "ASC.h"
#include "driverlib/timer.h"

extern void Timer2BIntHandler(void); /*interupt timer for buttons */ 

extern void initTimer(void); /*initilises the timer for buttons */



#endif /* MYTIMER_H_ */
