//*****************************************************************************
//!	ENCE463 Project
//! Author: Campbell Reid-Tait, Cid Gilani
//! Date: 20 August 2014
//! file: "ADC.h"
//!
//! This module does everything to do with the adc
//*****************************************************************************

#include "ADC.h"

/*called to read a certain ADC* eg. 2 for WUS 3 for ASC*/
/*
extern uint16_t readADC(uint16_t ADC_PIN)
{
	uint32_t adc_reading[24];
	uint16_t adc_value;
	ADCProcessorTrigger(ADC_BASE, 2);
	ADCSequenceDataGet(ADC_BASE, 2, adc_reading);
	adc_value = (unsigned int) adc_reading[ADC_PIN];
	return adc_value;
}
*/

extern uint32_t * readADC(void)
{
	static uint32_t adc_reading[4];
	ADCProcessorTrigger(ADC_BASE, 2);
	ADCSequenceDataGet(ADC_BASE, 2, adc_reading);
	return adc_reading;
}

/*initilises a number of ADC inputs*/
extern void initADC(uint16_t ADC_NUM)
{
	//ADCIntDisable(ADC_BASE, 2);
    // The ADC0 peripheral must be enabled for use.	
	SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);

	//Enabling the port where ADC1 pin is located.
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	//Enabling the port where ADC0 and ADC2 pins are located.
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

	 // Set GPIO D1 and GPIO A1 as ADC pin.
	GPIOPinTypeADC(GPIO_PORTA_BASE, GPIO_PIN_1);
	// Set GPIO D1 and GPIO B1 as ADC pin.
	GPIOPinTypeADC(GPIO_PORTB_BASE, GPIO_PIN_1); 
	// Set GPIO D1 and GPIO B3 as ADC pin.
	GPIOPinTypeADC(GPIO_PORTB_BASE, GPIO_PIN_3);

	 // Configuring the ADC sampling rate
	 SysCtlADCSpeedSet(SYSCTL_ADCSPEED_500KSPS);
	 //Configuring ADC oversampling rate to 8
	 ADCHardwareOversampleConfigure(ADC_BASE, 8);
	 //Configuring ADC sequence
	 ADCSequenceDisable(ADC_BASE, 2);
	 ADCSequenceConfigure(ADC_BASE, 2, ADC_TRIGGER_PROCESSOR, 0);

	//Configuring ADC steps
	if (ADC_NUM == 2)
	{
		ADCSequenceStepConfigure(ADC_BASE, 2, 0, ADC_CTL_CH0);
		ADCSequenceStepConfigure(ADC_BASE, 2, 1, ADC_CTL_CH1 | ADC_CTL_IE | ADC_CTL_END);
	}
	if (ADC_NUM == 3)
	{
		ADCSequenceStepConfigure(ADC_BASE, 2, 0, ADC_CTL_CH0);
		ADCSequenceStepConfigure(ADC_BASE, 2, 1, ADC_CTL_CH1);
		ADCSequenceStepConfigure(ADC_BASE, 2, 2, ADC_CTL_CH2 | ADC_CTL_IE | ADC_CTL_END);
	}
	// Since sample sequence 2 is now configured, it must be enabled.
	ADCSequenceEnable(ADC_BASE, 2);

	// Clear the interrupt status flag.  This is done to make sure the
	// interrupt flag is cleared before we sample.
	ADCIntEnable(ADC_BASE, 2);

}
extern void startADC (uint16_t ADC_PIN)
{

}

extern void stopADC (uint16_t ADC_PIN)
{

}
/*convert ADC values to car parameters; eg. Fa, Bs, azS, azU,dzSU */
extern float convert2Value(uint16_t ADC_NUM, uint16_t ADC_PIN, float ADC_VALUE)
{
	return 0.0;

}



