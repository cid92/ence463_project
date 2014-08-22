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

#include "carparameters.h"
#include "roadgen.h"
#include "button.h"
#include "drivers/rit128x96x4.h"

/*called to update the screen*/
extern void updateGui(void);
/*initializes the screen and Gui */
extern void initGui(void);

/*Choose the screen to display with buttons*/
extern void displayGui(void);

/*Take button inputs to for user interface to change screen display*/
extern void wusGui(void);

/*Display to damping factor and actuation force received from ASC and the sensor outputs transmitted to ASC*/
extern void displaySuspension(SimOut disNAccel, ConOut forceDamp);

/*Display the road surface mapping. The dzR and vzR are written into circular buffers*/
extern void displayRoad(SimGen surfaceBump, uint8_t roadType, float[50] dzRbuff, float[50] vzRbuff );

/*Display the acceleration and speed of the car*/
extern void displayMotion(float currSpeed, float currAccel); 

/*Display the status of ASC */
extern void displayASC(char[30] ASC_status); 

#endif /* WUSGUI_H_ *