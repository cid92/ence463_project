//*****************************************************************************
//!	ENCE463 Project
//! Author: Campbell Reid-Tait
//! Date: 20 August 2014
//! file: "button.h"
//!
//! This module reads the buttons and apply button debounced.
//*****************************************************************************

#include "driverlib/gpio.h"



/*FreeRTOS is to handle the button debounced. */

extern void buttonPress(void); /*called to poll the buttons*/
extern void initButton(void); /*initilises the buttons */



#endif /* BUTTON_H_ */
