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

extern void initSpeedInt(void);

extern void initSpeedGen(void);

extern float readCurrSpeed(float currSpeed);

extern float genCurrSpeed(float currSpeed);

#endif /* CARSPEED_H_ *