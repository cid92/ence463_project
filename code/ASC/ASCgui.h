//*****************************************************************************
//!	ENCE463 Project
//! Author: Campbell Reid-Tait
//! Date: 20 August 2014
//! file: "ASCgui.h"
//!
//! This module updates the GUI and display for ASC
//*****************************************************************************
#ifndef ASCGUI_H_
#define ASCGUI_H_


#include "PID.h"
#include "carspeed.h"
#include "button.h"

/*called to update the screen*/
extern void updateGui(void);

/*initilises the screen and gui */
extern void initGui(void);

/*Display to damping factor and actuation force transmitted to WUC and the sensor outputs received from ASC*/
extern void displaySuspension(SimOut disNAccel, ConOut forceDamp);

/*Display the acceleration and speed of the car*/
extern void displayMotion(float currSpeed, float currAccel);

/*Display the status of WUC */
extern void displayWUS(char[30] WUS_status); 

#endif /* ASCGUI_H_ */
