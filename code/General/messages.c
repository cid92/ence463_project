//*****************************************************************************
//!	ENCE463 Project
//! Author: Vincent Crowe, Campbell Reid-Tait, Cid Gilani
//! Date: 20 August 2014
//! file: "messages.h"
//!
//! The main header file for the ASC device.
//! Includes all the tasks to be registed with freeRTOS
//*****************************************************************************

#include "messages.h"



//*****************************************************************************
//
// Decoding Messages.
//
//*****************************************************************************
extern void decode(char message[]){
	i = 0;
	for (i = 0; i <= BuffSize; i++){
		//WUS status
		if (message[i] == 'W'){
			w = ((uint32_t)message[i+3] - (uint32_t)'0')*16;
			w = w + (uint32_t)message[i+4] - (uint32_t)'0';
			i = i+4;
		}
		//Road type
		else if (message[i] == 'R'){
			r = ((uint32_t)message[i+1] - (uint32_t)'0')*10;
			r = r + ((uint32_t)message[i+2] - (uint32_t)'0');
			i = i+2;
		}
		//Reset the car speed to 0
		else if (message[i] == 'S'){
			s = 1;

		}
		else if (message[i] == 'A'){
			a = ((float)message[i+1] - (float)'0')*10;
			a = a + ((float)message[i+2] - (float)'0');
			a = a + ((float)message[i+4] - (float)'0')*0.1;
			a = a + ((float)message[i+5] - (float)'0')*0.01;
			a = a + ((float)message[i+6] - (float)'0')*0.001;
		}
		//Start the simulation
		else if (message[i] == 'M'){
			m = 1;
		}
	}
 }

//*****************************************************************************
//
// Send a string to the UART.
//
//*****************************************************************************
extern void UARTSend(const unsigned char *pucbuff, unsigned long ulCount)
{
    //
    // Loop while there are more characters to send.
    //

    while(ulCount--)
    {
        //
        // Write the next character to the UART.
        //
        UARTCharPut(UART1_BASE, *pucbuff++);

    }
}

//*****************************************************************************
//
// Interrupt Handler for Rx.
// Note: Need to be declared in starup_ccs.c
//
//*****************************************************************************

void UART1IntHandler(void)
{
	uint32_t ulStatus;
	//count = 0;
    //
    // Get the interrrupt status.
    //
    ulStatus = UARTIntStatus(UART1_BASE, true);

    //
    // Clear the asserted interrupts.
    //
    UARTIntClear(UART1_BASE, ulStatus);
    //
    // Loop while there are characters in the receive FIFO.
    //
    flag++;
    int c;
    while(UARTCharsAvail(UART1_BASE))
    {
        // Read the next character from the UART and write it back to the UART.
       c = UARTCharGetNonBlocking(UART1_BASE);
       if (c > NULL){
    	   buff[count] = (char)c;
       }
       count++;
       if (count >= BuffSize){
    	   count = 0;
       }
    }
}

//*****************************************************************************
//
// Initialise the UART1 pins.
//
//*****************************************************************************
void initUART(void){
    // Enable the peripherals used by this example.
    //

    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART1);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	GPIOPinTypeUART(GPIO_PORTD_BASE, GPIO_PIN_3 | GPIO_PIN_2);

	// Configure the UART for 9600, 8-N-1 operation.
	UARTConfigSetExpClk(UART1_BASE, SysCtlClockGet(), 625,
			(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
					UART_CONFIG_PAR_NONE));
	// Enable the UART interrupt.
	IntEnable(INT_UART1);
	UARTIntEnable(UART1_BASE, UART_INT_RX |UART_INT_RT);

}

