//*****************************************************************************
//!	ENCE463 Project
//! Author: Cid Gilani
//! Date: 20 August 2014
//! file: "pwm.h"
//!
//! This module does everything to do with the PWM
//*****************************************************************************

#ifndef PWM_H_
#define PWM_H_

/*Initialise a number of PWM pins eg. 2 for ASC 3 for WUS*/
extern void initPWM(int PWM_NUM);

extern void changeDutyPWM(int PWM_PIN , float NEW_DUTY);

extern void changeFrequrencyPWM(int PWM_PIN , int NEW_FREQ);

extern void startPWM(int PWM_PIN);

extern void stopPWM (int PWM_PIN);

/*convert car parameters such as Fa, Bs, azS, azU, dzSU to duty cycle*/
extern float convert2Duty(int PWM_NUM, int PWM_PIN, int param_value);

#endif /* PWM_H_ *
