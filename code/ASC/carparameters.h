//*****************************************************************************
//!	ENCE463 Project
//! Author: Cid Gilani
//! Date: 20 August 2014
//! file: "carparameters.h"
//!
//! This module classify the general parameters use by 
//!	both ASC and WUS into structure.
//*****************************************************************************

#ifndef CARPARAMETERS_H_
#define CARPARAMETERS_H_

/*These parameters are calculated by the WUS and sent to ASC */
extern struct SimOut {
	float azS;
	float azU;
	float dzSU;
	};
	
/*These parameters are calculated by the ASC and sent to WUS */	
extern struct ConOut {
	float Fa;
	float Bs;
	};

extern struct SusState {
	float dzS;
	float vzS;
	float dzU;
	float vzU;
	};
	
#endif /* CARPARAMETERS_H_ *