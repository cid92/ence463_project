//*****************************************************************************
//!	ENCE463 Project
//! Author: Vincent Crowe, Campbell Reid-Tait
//! Date: 20 August 2014
//! file: "WUS.h"
//!
//! The main header file for the WUS device.
//! Includes all the tasks to be registed with freeRTOS
//*****************************************************************************

#ifndef WUS_H
#define WUS_H

/*Internal Status Variables*/
int power_failure;
int OK;
int watchdog_restart;
int acc_exceeds_range_s;
int acc_exceeds_range_u;
int height_exceeds_range;
int car_speed_exceeds_200;

char Receive_Buffer;
char Send_Buffer;

/*Sets all Values to Default*/
void Initialize(void);
/*This reads the status variables e.g. and displays them on the screen*/
void Update_Display(void);

/*Uses a Random Variable Generator to write to time_series variable, by using
Current_Car_Speed semaphore, a time_step variable and Road_Surface_Parameter
mutex*/
void Generate_Road_Surface(void);

/*Reads the Receive_Buffer semaphore and writes into status values variables*/
void Receive_Messages(void);

/*Reads the the status values variables and writes into the mutex Send_Buffer*/
void Transmit_Status(void);

/*Reads the input from buttons variables and writes into buttons variables*/
void Check_Buttons(void);

/*Reads Wheel_Pulse Mutex and writes into Send_Buffer mutex*/
void Send_Wheel_Pulse(void);

void Generate_WUS_Status(void);
/*generates the graphic for the road surface if needed*/
void Generate_Road_Surface_Graphic(void);


#endif
