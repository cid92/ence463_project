//*****************************************************************************
//!	ENCE463 Project
//! Author: Cid Gilani
//! Date: 20 August 2014
//! file: "PWM.h"
//!
//! This module does everything to do with the PWM
//*****************************************************************************

#include "PWM.h"

#define FREQ 100000
uint16_t duty_cycle = 50;
uint16_t PWM_PIN;

/*Initialise a number of PWM pins eg. 2 for ASC 3 for WUS*/
extern void initPWM(uint16_t PWM_NUM)
{
	// Compute the PWM period based on the system clock.
	SysCtlPeripheralEnable (SYSCTL_PERIPH_PWM);
	SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOD);
	SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOF);

	//Configure PWM 1 from GEN 0
    GPIOPinTypePWM (GPIO_PORTD_BASE, GPIO_PIN_1);

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
	GPIOPinTypePWM (GPIO_PORTF_BASE, GPIO_PIN_2);
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
		GPIOPinTypePWM (GPIO_PORTF_BASE, GPIO_PIN_3);
		// Enable the PWM5 output signals.
		PWMPulseWidthSet (PWM_BASE, PWM_OUT_5, SysCtlClockGet () /FREQ* duty_cycle/100);
		// Enable the PWM5 generators.
		PWMOutputState (PWM_BASE, PWM_OUT_5_BIT, 1);
	}
}

extern void changeDutyPWM(uint16_t PWM_PIN , float NEW_DUTY)
 {
	if (PWM_PIN == 1)
	{
			PWMPulseWidthSet (PWM_BASE, PWM_OUT_1, SysCtlClockGet () /FREQ* NEW_DUTY/100);
	}
	if (PWM_PIN == 4)
	{
			PWMPulseWidthSet (PWM_BASE,PWM_OUT_4, SysCtlClockGet () /FREQ* NEW_DUTY/100);;
	}
	if (PWM_PIN == 5)
	{
			PWMPulseWidthSet (PWM_BASE, PWM_OUT_5, SysCtlClockGet () /FREQ* NEW_DUTY/100);
	}
}

extern void changeFrequrencyPWM(uint16_t PWM_PIN , uint16_t NEW_FREQ)
{
	if (PWM_PIN == 1)
	{
		PWMGenPeriodSet (PWM_BASE, PWM_GEN_0, (SysCtlClockGet ()/NEW_FREQ));
	}
	if (PWM_PIN == 4 || PWM_PIN == 5)
	{
		PWMGenPeriodSet (PWM_BASE, PWM_GEN_2, (SysCtlClockGet ()/NEW_FREQ));
	}
}
extern void startPWM(uint16_t PWM_PIN)
{
	if (PWM_PIN == 1)
	{
		PWMOutputState (PWM_BASE, PWM_OUT_1_BIT, true);
	}
	if (PWM_PIN == 4)
	{
		PWMOutputState (PWM_BASE, PWM_OUT_4_BIT, true);
	}
	if (PWM_PIN == 5)
	{
		PWMOutputState (PWM_BASE, PWM_OUT_5_BIT, true);
	}
}
extern void stopPWM (uint16_t PWM_PIN)
{
	if (PWM_PIN == 1)
	{
		PWMOutputState (PWM_BASE, PWM_OUT_1_BIT, false);
	}
	if (PWM_PIN == 4)
	{
		PWMOutputState (PWM_BASE, PWM_OUT_4_BIT, false);
	}
	if (PWM_PIN == 5)
	{
		PWMOutputState (PWM_BASE, PWM_OUT_5_BIT, false);
	}
}
/*convert car parameters such as fa, bs, azs, azu, dzsu to duty cycle*/
extern float convert2duty(uint16_t pwm_num, uint16_t pwm_pin, uint16_t param_value)
{
	float duty;
	if (pwm_num == 2)
	{
		//damping factor bs
		if (pwm_pin ==  1)
		{
			duty = ((400*param_value/91)+100);
		}
		//actuator force fa
		else if (pwm_pin ==  4)
		{
			duty =  ((2000*param_value/91)-1000);
		}
	}
	if (pwm_num == 3)
	{
		//accel. sprung azs
		if (pwm_pin ==  1)
		{
			duty = ((40*param_value/91)-20);
		}
		//accel. unsprung azu
		else if (pwm_pin ==  4)
		{
			duty = ((2000*param_value/91)-1000);
		}
		//wheel height dzsu
		else if (pwm_pin ==  5)
		{
			duty = ((0.5*param_value/91)-0.25);
		}
	}
	return duty;
}
