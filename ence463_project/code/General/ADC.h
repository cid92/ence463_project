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

#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/adc.h"
#include "drivers/rit128x96x4.h"

#define uint16_t unsigned short
#define uint32_t unsigned long

//*****************************************************************************
//
// Reads ADC pins.
//
//*****************************************************************************
extern uint32_t *readADC(void);

//*****************************************************************************
//
// Initialise a number of ADC pins.
//
//*****************************************************************************
extern void initADC(uint16_t ADC_NUM);

//*****************************************************************************
//
// Starts all ADC readings.
//
//*****************************************************************************
extern void startADC (uint16_t ADC_PIN);

//*****************************************************************************
//
// Stops all ADC readings.
//
//*****************************************************************************
extern void stopADC (uint16_t ADC_PIN);
 
//*****************************************************************************
//
// Converts ADC values to car parameters; eg. Fa, Bs, azS, azU,dzSU.
//
//*****************************************************************************
extern float convert2Value(uint16_t ADC_NUM, uint16_t ADC_PIN, float ADC_VALUE);

#endif /* ADC_H_ */
