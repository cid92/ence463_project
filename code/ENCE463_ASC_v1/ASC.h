//*****************************************************************************
//!	ENCE463 Project
//! Author: Vincent Crowe, Campbell Reid-Tait
//! Date: 20 August 2014
//! file: "ASC.h"
//!
//! The main header file for the WUS device.
//! Includes all the tasks to be registed with freeRTOS
//*****************************************************************************


#ifndef ASC_H_
#define ASC_H_

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
#include <stdlib.h>
#include <string.h>
/* Demo includes. */
#include "demo_code/basic_io.h"


/* Dispaly */
#include "ASCgui.h"
#include "button.h"
#include "ADC.h"
#include "PWM.h"
#include "mytimer.h"
#include "messages.h"


#define uint16_t unsigned short
#define uint32_t unsigned long

extern int roadtype;
extern int ridetype;
extern int ridenum;
extern int grade;
extern int select;




/* The task function. */
void vTaskFunction( void *pvParameters );
void vSendStatusFunction( void );
void vUpdateGUIFunction( void );
void vPollButtonFunction( void );

#endif /* ASC_H_ */
