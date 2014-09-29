//*****************************************************************************
//!	ENCE463 Project
//! Author: Cid Gilani
//! Date: 20 August 2014
//! file: "PWM.h"
//!
//! This module does everything to do with the PWM
//*****************************************************************************

#ifndef PWM_H_
#define PWM_H_

#include "driverlib/pwm.h"


/*Initialise a number of PWM pins eg. 2 for ASC 3 for WUS*/
extern void initPWM(uint8_t PWM_NUM);

extern void changeDutyPWM(uint8_t PWM_PIN , float NEW_DUTY);

extern void changeFrequrencyPWM(uint8_t PWM_PIN , uint8_t NEW_FREQ);

extern void startPWM(uint8_t PWM_PIN);

extern void stopPWM (uint8_t PWM_PIN);

/*convert car parameters such as Fa, Bs, azS, azU, dzSU to duty cycle*/
extern float convert2Duty(uint8_t PWM_NUM, uint8_t PWM_PIN, uint8_t param_value);

#endif /* PWM_H_ *
