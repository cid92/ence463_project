//*****************************************************************************
//!	ENCE463 Project
//! Author: Campbell Reid-Tait
//! Date: 20 August 2014
//! file: "ADC.h"
//!
//! This module does everything to do with the adc
//*****************************************************************************
#ifndef ADC_H_
#define ADC_H_

/*called to read a certain ADC*/
extern float readADC(int toreadADC );

/*initilises a number of ADC inputs*/
extern void initADC(int howmany);

extern void startADC (int numADC);

extern void stopADC (int numADC);


#endif /* ADC_H_ */
