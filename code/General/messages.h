//*****************************************************************************
//!	ENCE463 Project
//! Author: Campbell Reid-Tait
//! Date: 20 August 2014
//! file: "messages.h"
//!
//! This module controls the messing between devices.
//*****************************************************************************
#ifndef MESSAGES_H_
#define MESSAGES_H_

#include "driverlib/uart.h"
#include "driverlib/interrupt.h"
#include "driverlib/gpio.h"

/*called to send a message*/
extern void sendMessage(str * message);

/*called to reseave a message. Returns the recieved message*/
extern int recieveMessage( void );

/*initilises the UART pins etc */
extern void initMessage(void);

#endif /* MESSAGES_H_ */
