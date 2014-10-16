//*****************************************************************************
//!	ENCE463 Project
//! Author: Vincent Crowe, Campbell Reid-Tait
//! Date: 20 August 2014
//! file: "WUS.h"
//!
//! The main header file for the WUS device.
//! Includes all the tasks to be registed with freeRTOS
//*****************************************************************************


#ifndef WUS_H_
#define WUS_H_

/* FreeRTOS includes. */
#include "include/FreeRTOS.h"
#include "include/task.h"
#include "include/queue.h"

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

/* Dispaly */
#include "WUSgui.h"

#include "button.h"
#include "ADC.h"
#include "PWM.h"
#include "mytimer.h"
#include "messages.h"


#define uint16_t unsigned short
#define uint32_t unsigned long

extern xQueueHandle XQueueMessageR;
extern xQueueHandle XQueueMessageS;
extern xQueueHandle XQueueMessageA;
extern xQueueHandle XQueueMessageM;

/* The task function. */
void vTaskFunction( void *pvParameters );
void vSendStatusFunction( void );
void vReadADCFunction( void );
void vUpdateGUIFunction( void );
void vPollMessageRFunction( void );
void vPollMessageSFunction( void );
void vPollMessageAFunction( void );
void vPollMessageMFunction( void );
void vPollButtonFunction( void );

#endif /* WUS_H_ */
