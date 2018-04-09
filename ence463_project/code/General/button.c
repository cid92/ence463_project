

//*****************************************************************************
//!	ENCE463 Project
//! Author: Campbell Reid-Tait
//! Date: 20 August 2014
//! file: "button.c"
//!
//! This module reads the buttons and apply button debounced.
//*****************************************************************************

#include "button.h"

// The debounced state of the five push buttons.  The bit positions correspond
static unsigned char g_ucSwitches = 0xf8;

// The vertical counter used to debounce the push buttons.  The bit positions
// are the same as g_ucSwitches.
static unsigned char g_ucSwitchClockA = 0;
static unsigned char g_ucSwitchClockB = 0;

/*called to poll the buttons*/
extern void buttonPress(void) 
{
	unsigned long ulData, ulDelta;
	// Read the state of the buttons.
	ulData = GPIOPinRead(GPIO_PORTG_BASE,
                     (GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | 
                     	GPIO_PIN_6 | GPIO_PIN_7));


	// Determine the switches that are at a different state than the debounced state.
	ulDelta = ulData ^ g_ucSwitches;
	// Increment the clocks by one.
	g_ucSwitchClockA ^= g_ucSwitchClockB;
	g_ucSwitchClockB = ~g_ucSwitchClockB;
	// Reset the clocks corresponding to switches that have not changed state.
	g_ucSwitchClockA &= ulDelta;
	g_ucSwitchClockB &= ulDelta;
	// Get the new debounced switch state.
	g_ucSwitches &= g_ucSwitchClockA | g_ucSwitchClockB;
	g_ucSwitches |= (~(g_ucSwitchClockA | g_ucSwitchClockB)) & ulData;
	// Determine the switches that just changed debounced state.
	ulDelta ^= (g_ucSwitchClockA | g_ucSwitchClockB);
	// See if the up button was just pressed.
	if((ulDelta & 0x08) && !(g_ucSwitches & 0x08))
	{
		
	}
	// See if the down Button was just pressed.
	if((ulDelta & 0x10) && !(g_ucSwitches & 0x10))
	{
		
	}
	// See if the left button was just pressed.
	if((ulDelta & 0x20) && !(g_ucSwitches & 0x20))
	{

	
	}
	// See if the right button was just pressed.
	if((ulDelta & 0x40) && !(g_ucSwitches & 0x40))
	{
		
	}
	// See if the select button was just pressed.
	if((ulDelta & 0x80) && !(g_ucSwitches & 0x80))
	{
		

	}

}


/*initilises the buttons */
extern void initButton(void)
{
	// Enable GPIO module for buttons and LED.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOG);
    // Set the buttons as input.
    GPIODirModeSet(GPIO_PORTG_BASE, GPIO_PIN_3|GPIO_PIN_4|
    	GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_DIR_MODE_IN);
    
    GPIOPadConfigSet(GPIO_PORTG_BASE, GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|
    	GPIO_PIN_6|GPIO_PIN_7, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
    
}



