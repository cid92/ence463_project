//*****************************************************************************
//!	ENCE463 Project
//! Author: Campbell Reid-Tait
//! Date: 20 August 2014
//! file: "button.h"
//!
//! This module reads the buttons and apply button debounced.
//*****************************************************************************

#include "mytimer.h"

//*****************************************************************************
//
// The interrupt handler for the Timer2B interrupt.
//
//*****************************************************************************
extern void Timer2BIntHandler(void)
{
    //
    // Clear the timer interrupt flag.
    //
    TimerIntClear(TIMER2_BASE, TIMER_TIMB_TIMEOUT);
    vPrintString( "Interrupt" );
    buttonPress();

}

/*initilises the buttons */
extern void initTimer(void)
{
	//
    // The Timer2 peripheral must be enabled for use.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER2);
	//
	// Configure Timer2B as a 16-bit periodic timer.
	//
	TimerConfigure(TIMER2_BASE, TIMER_CFG_16_BIT_PAIR |
                   TIMER_CFG_A_PERIODIC);
	//
    // Set the Timer2B load value to 1ms.
    //
    TimerLoadSet(TIMER2_BASE, TIMER_B, SysCtlClockGet() / 1000);

    TimerIntRegister(TIMER2_BASE, TIMER_B, Timer2BIntHandler);

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

    //
    // Enable Timer2B.
    //
    TimerEnable(TIMER2_BASE, TIMER_B);

    TimerIntClear(TIMER2_BASE, TIMER_TIMB_TIMEOUT);
    vPrintString( "Create timer2B" );

}

