//*****************************************************************************
//!	ENCE463 Project
//! Author: Cid Gilani
//! Date: 20 August 2014
//! file: "WUSgui.h"
//!
//! This module updates the GUI and display for WUS
//*****************************************************************************

#ifndef ASCGUI_H_
#define ASCGUI_H_

#include "ASC.h"
#include "drivers/rit128x96x4.h"

extern int testValue;
extern float accel;
extern int accel1;
extern int accel2;
extern int state;
extern int state1;

/*called to update the screen*/
extern void updateGui(void);
/*initializes the screen and Gui */
extern void initGui(void);

/*Choose the screen to display with buttons*/
extern void displayGui(void);

/*Take button inputs to for user interface to change screen display*/
extern void wusGui(void);


/*Display the acceleration and speed of the car*/
extern void displayMotion(float currSpeed, float currAccel);



#endif /* ASCGUI_H_ */
