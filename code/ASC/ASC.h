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



#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/debug.h"
#include "driverlib/pwm.h"
#include "drivers/rit128x96x4.h"

#define uint16_t unsigned short
#define uint32_t unsigned long

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



