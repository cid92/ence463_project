//*****************************************************************************
//!	ENCE463 Project
//! Author: Cid Gilani
//! Date: 20 August 2014
//! file: "roadgen.h"
//!
//! This module enable WUS to generate road surface with pseudorandom number generator
//*****************************************************************************


#ifndef ROADGEN_H_
#define ROADGEN_H_

#include "carspeed.h"

struct SimGen {
	float dzR;
	float vzR;
};

extern int returnRoadType(void);

extern SimGen roadSurfGen(float currSpeed, int roadType, float tStep);

#endif /* ROADGEN_H_ *
