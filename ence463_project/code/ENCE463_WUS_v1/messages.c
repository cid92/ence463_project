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

extern int count = 0;
extern char buff[BUFFSIZE] = {0};

uint32_t w;
uint16_t r;
uint16_t s;
float a;
uint16_t m;



char startLetter = 0;

char messageR[3];
char messageS[1];
char messageA[7];
char messageM[5];

int newMessage = 1;
//*****************************************************************************
//
// Decoding Messages.
//
//*****************************************************************************
extern void decode(char * message, int size){
	int i = 0;
	for (i = 0; i < size; i++){
		//WUS status

		//Road type
		if (message[i] == 'R'){
			r = ((uint32_t)message[i+1] - (uint32_t)'0')*10;
			r = r + ((uint32_t)message[i+2] - (uint32_t)'0');
			roadtype = (int)message[i+1] - (int)'0';
			i = i+2;
		}
		//Reset the car speed to 0
		else if (message[i] == 'S'){
			s = 1;
			speed = 0;

		}
		else if (message[i] == 'A'){
			if (message[i+1] ==  '-' ) {
				a = ((float)message[i+2] - (float)'0')*((float)'-1');
			}
			else {
				a = ((float)message[i+1] - (float)'0')*10;
				a = a + ((float)message[i+2] - (float)'0');
			}

			a = a + ((float)message[i+4] - (float)'0')*0.1;
			a = a + ((float)message[i+5] - (float)'0')*0.01;
			a = a + ((float)message[i+6] - (float)'0')*0.001;

			speed  = (int) ((int) a + speed);
		}
		//Start the simulation
		else if (message[i] == 'M'){
			m = ((uint32_t)message[i+3] - (uint32_t)'0')*16;
			m = m + (uint32_t)message[i+4] - (uint32_t)'0';
			i = i+4;


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
	portBASE_TYPE xStatus;
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
    int testint;
    char c;
    //while(UARTCharsAvail(UART1_BASE))
    //{
        // Read the next character from the UART and write it back to the UART.
       testint = UARTCharGetNonBlocking(UART1_BASE);
       c = (char) testint;
       if (c > NULL){



    	   if (c == 'R' || c == 'S' || c == 'A' || c == 'M') newMessage = 1;
    	   if (newMessage == 1 ) {
        	   startLetter = (char) c;
			   switch (startLetter) {
				   case 'R':
					   newMessage = 0;
					   count = 0;
					   messageR[count] = c;
					   break;
				   case 'S':
					   count = 0;
					   messageS[count] = c;
					   newMessage = 1;

					   /* TODO copy message to external buffer */
					   xStatus = xQueueSendToBack( XQueueMessageS, &messageS, 0);
					   break;

				   case 'A':
					   newMessage = 0;
					   count = 0;
					   messageA[count] = c;
					   break;
				   case 'M':
					   newMessage = 0;
					   count = 0;
					   messageM[count] = c;
					   break;
			   }
		   }
           else {
        	   switch (startLetter) {
				   case 'R':
					   if (count < 2) {
						   messageR[count] = c;
					   }
					   else {
						   messageR[count] = c;
						   newMessage = 1;
						   /* TODO copy message to external buffer */
						   xStatus = xQueueSendToBack( XQueueMessageR, &messageR, 0);
					   }
					   break;
				   case 'A':
					   if (count < 6) {
						   messageA[count] = c;
					   }
					   else {
						   messageA[count] = c;
						   newMessage = 1;
						   /* TODO copy message to external buffer */
						   xStatus = xQueueSendToBack( XQueueMessageA, &messageA, 0);
					   }
					   break;
				   case 'M':
					   if (count < 4) {
						   messageM[count] = c;
					   }
					   else {
						   messageM[count] = c;
						   newMessage = 1;
						   /* TODO copy message to external buffer */
						   xStatus = xQueueSendToBack( XQueueMessageM, &messageM, 0);
					   }
					   break;
        	   }
           }
           count++;
       }
    //}
}

//*****************************************************************************
//
// Initialise the UART1 pins.
//
//*****************************************************************************
void initUART(void){
    // Enable the peripherals used by this example.
    //
	count = 0;
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART1);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	GPIOPinTypeUART(GPIO_PORTD_BASE, GPIO_PIN_3 | GPIO_PIN_2);

	// Configure the UART for 625, 8-N-1 operation.
	UARTConfigSetExpClk(UART1_BASE, SysCtlClockGet(), 625000,
			(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
					UART_CONFIG_PAR_NONE));
	// Enable the UART interrupt.
	IntEnable(INT_UART1);
	UARTIntEnable(UART1_BASE, UART_INT_RX |UART_INT_RT);

}

