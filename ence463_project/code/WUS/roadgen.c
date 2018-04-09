//*****************************************************************************
//!	ENCE463 Project
//! Author: Campbell Reid-Tait	
//! Date: 13 October 2014
//! file: "roadgen.c"
//!
//! This module does everything to do with the roadgen
//*****************************************************************************

#include "roadgen.h"



int rand_lim(int limit) {
/* return a random number between 0 and limit inclusive.
 */

    int divisor = RAND_MAX/(limit+1);
    int retval;

    do { 
        retval = rand() / divisor;
    } while (retval > limit);

    return retval;
}


/*Return the road type value. It can either be a float or uint8_t*/
extern uint8_t RoadType(void) 
{ 
	return roadtype;
}

/*Generate the road surface with pseudo random number generator */
extern SimGen roadSurfGen(float currSpeed, uint8_t roadType, float tStep){
	
	float zr 
	int r = rand_lim(3);
	float zr_old = zr
	
	switch( d1 )
	{
		case 1:
			zr = 0.005 + r*0.005;
		case 2:
			zr = 0.025 + r*0.025;
		case 3:
			zr = 0.15 + r*0.05;
	}		
			
	float zr_dash = (zr - zr_old) / tStep;		
			
	
}