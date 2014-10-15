//*****************************************************************************
//!	ENCE463 Project
//! Author: Vincent Crowe, Campbell Reid-Tait, Cid Gilani
//! Date: 20 August 2014
//! file: "messages.h"
//!
//! The main header file for the ASC device.
//! Includes all the tasks to be registed with freeRTOS
//*****************************************************************************

#ifndef MESSAGES_H_
#define MESSAGES_H_


#include "uart_echo.h"

#define uint16_t unsigned short
#define uint32_t unsigned long


/*Declare those variables in the main file*/
extern uint16_t count;
extern int flag;
extern char buff[6];

//*****************************************************************************
//
// Send a string to the UART.
//
//*****************************************************************************
extern void UARTSend(const unsigned char *pucBuffer, unsigned long ulCount);

//*****************************************************************************
//
// Interrupt Handler for Rx.
// Note: Need to be declared in starup_ccs.c
//
//*****************************************************************************



extern void UART1IntHandler(void);

//*****************************************************************************
//
// Initialise the UART1 pins.
//
//*****************************************************************************
extern void initUART(void);


#endif /* MESSAGES_H_ */
