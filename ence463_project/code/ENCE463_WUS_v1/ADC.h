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



#include "WUS.h"
#include "driverlib/adc.h"




#define uint16_t unsigned short
#define uint32_t unsigned long

/*called to read a certain ADC* eg. 2 for WUS 3 for ASC*/
//extern uint16_t readADC(uint16_t ADC_PIN );
extern uint32_t *readADC(void);

/*initilises a number of ADC inputs*/
extern void initADC(uint16_t ADC_NUM);

extern void startADC (uint16_t ADC_PIN);

extern void stopADC (uint16_t ADC_PIN);
 
/*convert ADC values to car parameters; eg. Fa, Bs, azS, azU,dzSU */
extern float convert2Value(uint16_t ADC_NUM, uint16_t ADC_PIN, float ADC_VALUE);

#endif /* ADC_H_ */
