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

#include "driverlib/adc.h"
#include "driverlib/gpio.h"

/*called to read a certain ADC* eg. 2 for WUS 3 for ASC*/
extern float readADC(uint8_t ADC_PIN );

/*initilises a number of ADC inputs*/
extern void initADC(uint8_t ADC_NUM);

extern void startADC (uint8_t ADC_PIN);

extern void stopADC (uint8_t ADC_PIN);
 
/*convert ADC values to car parameters; eg. Fa, Bs, azS, azU,dzSU */
extern float convert2Value(uint8_t ADC_NUM, uint8_t ADC_PIN, float ADC_VALUE);

#endif /* ADC_H_ */
