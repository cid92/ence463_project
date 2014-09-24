//*****************************************************************************
//!	ENCE463 Project
//! Author: Cid Gilani
//! Date: 20 August 2014
//! file: "PWM.h"
//!
//! This module does everything to do with the PWM
//*****************************************************************************

#include "pwm.h"

#define FREQ 

/*Initialise a number of PWM pins eg. 2 for ASC 3 for WUS*/
extern void initPWM(uint8_t PWM_NUM)
{
	// Compute the PWM period based on the system clock.
	SysCtlPeripheralEnable (SYSCTL_PERIPH_PWM);

	//Configure PWM 1 from GEN 0
	PWMGenConfigure (PWM_BASE, PWM_GEN_0,                    
		PWM_GEN_MODE_UP_DOWN | PWM_GEN_MODE_NO_SYNC);
	// Enable the PWM 1 output signals
	PWMGenPeriodSet (PWM_BASE, PWM_GEN_0, (SysCtlClockGet ()/FREQ));
	PWMPulseWidthSet (PWM_BASE, PWM_OUT_1, SysCtlClockGet () /FREQ* duty_cycle/100);
	// Enable the PWM generator 0.
	PWMOutputState (PWM_BASE, PWM_OUT_1_BIT, true);
	// Enable the PWM GEN 0.
	PWMGenEnable (PWM_BASE, PWM_GEN_0);

	//Configure PWM 4 from GEN 2
	PWMGenConfigure (PWM_BASE, PWM_GEN_2,
	PWM_GEN_MODE_UP_DOWN | PWM_GEN_MODE_NO_SYNC);
	// Enable the PWM 4 output signals.
	PWMGenPeriodSet (PWM_BASE, PWM_GEN_2, (SysCtlClockGet ()/FREQ));
	PWMPulseWidthSet (PWM_BASE, PWM_OUT_4, SysCtlClockGet () /FREQ* duty_cycle/100);
	// Enable the PWM generator 2.
	PWMOutputState (PWM_BASE, PWM_OUT_4_BIT, true);
	// Enable the PWM GEN 2.
	PWMGenEnable (PWM_BASE, PWM_GEN_2);

	if (PWM_NUM == 3) // If the board is WUS
	{
		// Enable the PWM5 output signals.
		PWMPulseWidthSet (PWM_BASE, PWM_OUT_5, SysCtlClockGet () /FREQ* duty_cycle/100);
		// Enable the PWM5 generators.
		PWMOutputState (PWM_BASE, PWM_OUT_5_BIT, true);
	}
}


extern void changeDutyPWM(uint8_t PWM_PIN , float NEW_DUTY);
{
	if (PMW_PIN == 1)
	{
			PWMPulseWidthSet (PWM_BASE, PWM_OUT_1, SysCtlClockGet () /FREQ* NEW_DUTY/100);
	}
	if (PMW_PIN == 4)
	{
			PWMPulseWidthSet (PWM_BASE,PWM_OUT_4, SysCtlClockGet () /FREQ* NEW_DUTY/100);;
	}
	if (PMW_PIN == 5)
	{
			PWMPulseWidthSet (PWM_BASE, PWM_OUT_5, SysCtlClockGet () /FREQ* NEW_DUTY/100);
	}
}

extern void changeFrequrencyPWM(uint8_t PWM_PIN , uint8_t NEW_FREQ)
{
	if (PMW_PIN == 1)
	{
		PWMGenPeriodSet (PWM_BASE, PWM_GEN_0, (SysCtlClockGet ()/NEW_FREQ));
	}
	if (PMW_PIN == 4 || PWM_PIN == 5)
	{
		PWMGenPeriodSet (PWM_BASE, PWM_GEN_2, (SysCtlClockGet ()/NEW_FREQ));
	}
}

extern void startPWM(uint8_t PWM_PIN)
{
	if (PMW_PIN == 1)
	{
		PWMOutputState (PWM_BASE, PWM_OUT_1_BIT, true);
	}
	if (PMW_PIN == 4)
	{
		PWMOutputState (PWM_BASE, PWM_OUT_4_BIT, true);
	}
	if (PMW_PIN == 5)
	{
		PWMOutputState (PWM_BASE, PWM_OUT_5_BIT, true);
	}
}
extern void stopPWM (uint8_t PWM_PIN)
{
	if (PMW_PIN == 1)
	{
		PWMOutputState (PWM_BASE, PWM_OUT_1_BIT, false);
	}
	if (PMW_PIN == 4)
	{
		PWMOutputState (PWM_BASE, PWM_OUT_4_BIT, false);
	}
	if (PMW_PIN == 5)
	{
		PWMOutputState (PWM_BASE, PWM_OUT_5_BIT, false);
	}
}
/*convert car parameters such as Fa, Bs, azS, azU, dzSU to duty cycle*/
extern float convert2Duty(uint8_t PWM_NUM, uint8_t PWM_PIN, uint8_t param_value)
{
}