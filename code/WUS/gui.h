//*****************************************************************************
//!	ENCE463 Project
//! Author: Cid Gilani
//! Date: 20 August 2014
//! file: "gui.h"
//!
//! This module updates the GUI and display for WUS
//*****************************************************************************

#ifndef GUI_H_
#define GUI_H_

#include "carparameters.h"
#include "roadgen.h"

/*called to update the screen*/
extern void updateGui(void);
/*initializes the screen and Gui */
extern void initGui(void);

/*Choose the screen to display with buttons*/
extern void displayGui(void);

/*Information to display*/
extern void displaySuspension(SimOut disNAccel, ConOut forceDamp);

extern void displayRoad(SimGen surfaceBump, int roadType);

extern void displayMotion(float currSpeed, float currAccel); 

extern void displayWUS(char[30] ASC_status); 

#endif /* GUI_H_ *