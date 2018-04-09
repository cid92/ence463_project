//*****************************************************************************
//!	ENCE463 Project
//! Author: Campbell Reid-Tait
//! Date: 20 August 2014
//! file: "timer.h"
//!
//! Tinterlises the timer
//*****************************************************************************
#ifndef TIMER_H_
#define TIMER_H_


#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_timer.h"
#include "inc/hw_ints.h"
#include "driverlib/gpio.h"
#include "driverlib/timer.c"
#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"


extern void Timer2BIntHandler(void); /*interupt timer for buttons */ 

extern void initTimer(void); /*initilises the timer for buttons */



#endif /* TIMER_H_ */
