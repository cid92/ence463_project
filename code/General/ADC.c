//*****************************************************************************
//!	ENCE463 Project
//! Author: Campbell Reid-Tait, Cid Gilani
//! Date: 20 August 2014
//! file: "ADC.h"
//!
//! This module does everything to do with the adc
//*****************************************************************************

/*called to read a certain ADC* eg. 2 for WUS 3 for ASC*/
extern float readADC(uint8_t ADC_PIN );

/*initilises a number of ADC inputs*/
extern void initADC(uint8_t ADC_NUM);
{
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

	if (ADC_NUM == 3)//If the board is ASC
	{
		// Set GPIO D1 and GPIO B3 as ADC pin.
		GPIOPinTypeADC(GPIO_PORTB_BASE, GPIO_PIN_3);
	}
	// Configuring the ADC hardaware oversampling to 8 oversampling rate.
	ADCHardwareOversampleConfigure(ADC0_BASE, 8);


	SysCtlADCSpeedSet(SYSCTL_ADCSPEED_1MSPS);


	// Enable the first sample sequencer to capture the value of channel 0 when the processor trigger occurs.
	ADCSequenceConfigure(ADC0_BASE, 0, ADC_TRIGGER_PROCESSOR, 0);
	ADCSequenceStepConfigure(ADC0_BASE, 0, 0,
	ADC_CTL_IE | ADC_CTL_END | ADC_CTL_CH0);
    // Enable the first sample sequencer to capture the value of channel 1 when the processor trigger occurs.
	ADCSequenceConfigure(ADC0_BASE, 0, ADC_TRIGGER_PROCESSOR, 0);
	ADCSequenceStepConfigure(ADC0_BASE, 0, 0,
	ADC_CTL_IE | ADC_CTL_END | ADC_CTL_CH0);

	if (ADC_NUM == 3)//If the board is ASC
	{

	}

}
extern void startADC (uint8_t ADC_PIN);

extern void stopADC (uint8_t ADC_PIN);
 
/*convert ADC values to car parameters; eg. Fa, Bs, azS, azU,dzSU */
extern float convert2Value(uint8_t ADC_NUM, uint8_t ADC_PIN, float ADC_VALUE);

