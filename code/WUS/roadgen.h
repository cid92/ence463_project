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
/*Return the road type value. It can either be a float or uint8_t*/
extern uint8_t RoadType(void);

/*Generate the road surface with pseudo random number generator */
extern SimGen roadSurfGen(float currSpeed, uint8_t roadType, float tStep);

#endif /* ROADGEN_H_ *
