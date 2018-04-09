//*****************************************************************************
//!	ENCE463 Project
//! Author: Vincent Crowe, Campbell Reid-Tait
//! Date: 20 August 2014
//! file: "ASC.h"
//!
//! The main header file for the ASC device.
//! Includes all the tasks to be registed with freeRTOS 
//*****************************************************************************



#ifndef ASC_H
#define ASC_H



/* FreeRTOS includes. */
#include "include/FreeRTOS.h"
#include "include/task.h"

/* Stellaris library includes. */
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_timer.h"
#include "inc/hw_ints.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"

//#include "ustdlib.h"
#include <stdio.h>
/* Demo includes. */
#include "demo_code/basic_io.h"

/* Display */
#include "ASCgui.h"

#include "button.h"
#include "ADC.h"
#include "PWM.h"
#include "mytimer.h"
#include "messages.h"


#define uint16_t unsigned short
#define uint32_t unsigned long


/* The task function. */
void vTaskFunction( void *pvParameters );
void vUpdateGUIFunction( void );
void vPollButtonFunction( void );


/*Sets Car Speed mutex to zero*/
void Start_Car(void);

/**/
void Operate_PID(void);

/*This reads the status variables e.g. and displays them on the screen*/
void Update_Display(void);

/*Read status of Road_Type variable and writes to Send Buffer semaphore*/
void Transmit_Road_Type(void);

/*Read status of Car_Acceleration variable and writes to Send Buffer semaphore*/
void Transmit_Car_Acceleration(void);

/*Reads the Receive_Buffer semaphore and writes into status values variables*/
void Recieve_Messages(void);

/*Reads the input from buttons and writes into buttons variables*/
void Check_Buttons(void);

/**/
void Simulate_Shocks(void);

/*Reads status of Ride_Type variable and writes to Send Buffer semaphore*/
void Transmit_Ride_Type(void);

#endif



