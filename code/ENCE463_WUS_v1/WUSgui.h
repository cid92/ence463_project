//*****************************************************************************
//!	ENCE463 Project
//! Author: Cid Gilani
//! Date: 20 August 2014
//! file: "WUSgui.h"
//!
//! This module updates the GUI and display for WUS
//*****************************************************************************

#ifndef WUSGUI_H_
#define WUSGUI_H_

#include "WUS.h"
#include "drivers/rit128x96x4.h"

extern int testValue;
extern int roadtype;
extern int wheelHeight;
extern int unsprungAccel;
extern int sprungAccel;
extern int dampingFactor;
extern int actuatorForce;
extern int speed;



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



#endif /* WUSGUI_H_ */
