//*****************************************************************************
//!	ENCE463 Project
//! Author: Campbell Reid-Tait
//! Date: 20 August 2014
//! file: "gui.h"
//!
//! This module updates the GUI and display for ASC
//*****************************************************************************
#ifndef GUI_H_
#define GUI_H_

/*called to update the screen*/
extern void updateGui(void);

/*initilises the screen and gui */
extern void initGui(void);

/*Information to display*/
extern void displaySuspension(SimOut disNAccel, ConOut forceDamp);

extern void displayMotion(float currSpeed, float currAccel);

extern void displayWUS(char[30] WUS_status); 

#endif /* GUI_H_ */
