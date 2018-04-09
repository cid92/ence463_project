//*****************************************************************************
//!	ENCE463 Project
//! Author: Campbell Reid-Tait
//! Date: 20 August 2014
//! file: "button.h"
//!
//! This module reads the buttons and apply button debounced.
//*****************************************************************************

#include "timer.h"

//*****************************************************************************
//
// The interrupt handler for the Timer0B interrupt.
//
//*****************************************************************************
void
Timer0BIntHandler(void)
{
    //
    // Clear the timer interrupt flag.
    //
    TimerIntClear(TIMER0_BASE, TIMER_TIMB_TIMEOUT);

    //
    // Update the periodic interrupt counter.
    //
    g_ulCounter++;

    //
    // Once NUMBER_OF_INTS interrupts have been received, turn off the
    // TIMER0B interrupt.
    //
    if(g_ulCounter == NUMBER_OF_INTS)
    {
        //
        // Disable the Timer0B interrupt.
        //
        IntDisable(INT_TIMER0B);

        //
        // Turn off Timer0B interrupt.
        //
        TimerIntDisable(TIMER0_BASE, TIMER_TIMB_TIMEOUT);

        //
        // Clear any pending interrupt flag.
        //
        TimerIntClear(TIMER0_BASE, TIMER_TIMB_TIMEOUT);
    }
}




/*initilises the buttons */
extern void initTimer(void)
{
	//
    // The Timer1 peripheral must be enabled for use.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
	//
	// Configure Timer2B as a 16-bit periodic timer.
	//
	TimerConfigure(TIMER2_BASE, TIMER_CFG_16_BIT_PAIR |
                   TIMER_CFG_A_PERIODIC);
	//
    // Set the Timer2B load value to 1ms.
    //
    TimerLoadSet(TIMER2_BASE, TIMER_B, SysCtlClockGet() / 1000);

    //
    // Enable processor interrupts.
    //
    IntMasterEnable();

    //
    // Configure the Timer2B interrupt for timer timeout.
    //
    TimerIntEnable(TIMER2_BASE, TIMER_TIMB_TIMEOUT);

    //
    // Enable the Timer2B interrupt on the processor (NVIC).
    //
    IntEnable(INT_TIMER2B);
    //
    // Initialize the interrupt counter.
    //
    g_ulCounter = 0;

    //
    // Enable Timer0B.
    //
    TimerEnable(TIMER2_BASE, TIMER_B);



}

