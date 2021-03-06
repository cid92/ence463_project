/*
    FreeRTOS V6.0.5 - Copyright (C) 2009 Real Time Engineers Ltd.

    This file is part of the FreeRTOS distribution.

    FreeRTOS is free software; you can redistribute it and/or modify it under
    the terms of the GNU General Public License (version 2) as published by the
    Free Software Foundation AND MODIFIED BY the FreeRTOS exception.
    ***NOTE*** The exception to the GPL is included to allow you to distribute
    a combined work that includes FreeRTOS without being obliged to provide the
    source code for proprietary components outside of the FreeRTOS kernel.
    FreeRTOS is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
    more details. You should have received a copy of the GNU General Public 
    License and the FreeRTOS license exception along with FreeRTOS; if not it 
    can be viewed here: http://www.freertos.org/a00114.html and also obtained 
    by writing to Richard Barry, contact details for whom are available on the
    FreeRTOS WEB site.

    1 tab == 4 spaces!

    http://www.FreeRTOS.org - Documentation, latest information, license and
    contact details.

    http://www.SafeRTOS.com - A version that is certified for use in safety
    critical systems.

    http://www.OpenRTOS.com - Commercial support, development, porting,
    licensing and training services.
*/

/* WUS.h */
#include "WUS.h"



/* Used as a loop counter to create a very crude delay. */
#define mainDELAY_LOOP_COUNT		( 0xfffff )


/* Define the strings that will be passed in as the task parameters.  These are
defined const and off the stack to ensure they remain valid when the tasks are
executing. */
const char *pcTextForTask1 = "Task 1 is running\n";
const char *pcTextForTask2 = "Task 2 is running\n";


xQueueHandle XQueueMessageR;
xQueueHandle XQueueMessageS;
xQueueHandle XQueueMessageA;
xQueueHandle XQueueMessageM;

/*-----------------------------------------------------------*/

int main( void )
{
	/* Set the clocking to run from the PLL at 50 MHz.  Assumes 8MHz XTAL,
	whereas some older eval boards used 6MHz. */
	SysCtlClockSet( SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_8MHZ );



	initButton();
	//initTimer();
	initGui();
	initUART();
	initPWM(3);
	initADC(2);


	/* Create one of the two tasks. */
	//xTaskCreate(	vTaskFunction,			/* Pointer to the function that implements the task. */
	//				"Task 1",				/* Text name for the task.  This is to facilitate debugging only. */
	//				240,					/* Stack depth in words. */
	//				(void*)pcTextForTask1,	/* Pass the text to be printed in as the task parameter. */
	//				1,						/* This task will run at priority 1. */
	//				NULL );					/* We are not using the task handle. */

	/* Create the other task in exactly the same way.  Note this time that we
	are creating the SAME task, but passing in a different parameter.  We are
	creating two instances of a single task implementation. */
	//xTaskCreate( vTaskFunction, "Task 2", 240, (void*)pcTextForTask2, 1, NULL );

	XQueueMessageR = xQueueCreate(5, sizeof( char ) * 3  );
	XQueueMessageS = xQueueCreate(5, sizeof( char ) * 1  );
	XQueueMessageA = xQueueCreate(5, sizeof( char ) * 7  );
	XQueueMessageM = xQueueCreate(5, sizeof( char ) * 5  );

	xTaskCreate( vUpdateGUIFunction, "Update GUI", 240, NULL, 1, NULL );

	xTaskCreate( vPollButtonFunction, "Poll Button", 240, NULL, 1, NULL );

	xTaskCreate( vPollMessageRFunction, "Poll Message R", 240, NULL, 1, NULL );
	xTaskCreate( vPollMessageSFunction, "Poll Message S", 240, NULL, 1, NULL );
	xTaskCreate( vPollMessageAFunction, "Poll Message A", 240, NULL, 1, NULL );
	xTaskCreate( vPollMessageMFunction, "Poll Message M", 240, NULL, 1, NULL );

	xTaskCreate( vReadADCFunction, "Read ADC", 240, NULL, 1, NULL );

	xTaskCreate( vSendStatusFunction, "Send Status Message", 240, NULL, 1, NULL );


	/* Start the scheduler so our tasks start executing. */
	vTaskStartScheduler();	
	
	/* If all is well we will never reach here as the scheduler will now be
	running.  If we do reach here then it is likely that there was insufficient
	heap available for the idle task to be created. */
	for( ;; );
}


void vSendStatusFunction( void )
{

	//char testBuf[50];
	volatile unsigned long ul;
	portTickType xLastWakeTime;

	xLastWakeTime = xTaskGetTickCount();

	const unsigned long ulCount = 5;
	const unsigned char sendbuffer[5] = {'W','0','x','0','0'};

	/* As per most tasks, this task is implemented in an infinite loop. */
	for( ;; )
	{
		UARTSend(sendbuffer, ulCount);

		/* Enter the blocked state for 100 mircoseconds */
		vTaskDelayUntil(&xLastWakeTime, (1/ portTICK_RATE_MS) );
	}
}

void vReadADCFunction( void )
{

	//char testBuf[50];
	volatile unsigned long ul;
	portTickType xLastWakeTime;

	xLastWakeTime = xTaskGetTickCount();

	const unsigned long ulCount = 5;
	const unsigned char sendbuffer[5] = {'w','0','x','0','0'};

	/* As per most tasks, this task is implemented in an infinite loop. */
	for( ;; )
	{
		uint32_t * adc_reading_test;
		adc_reading_test  = readADC();

		dampingFactor = adc_reading_test[0];
		actuatorForce = adc_reading_test[0];
		vTaskDelayUntil(&xLastWakeTime, (1/ portTICK_RATE_MS) );
	}
}

void vTaskFunction( void *pvParameters)
{

	volatile unsigned long ul;
	portTickType xLastWakeTime;

	xLastWakeTime = xTaskGetTickCount();

	/* As per most tasks, this task is implemented in an infinite loop. */
	for( ;; )
	{


		/* Enter the blocked state for 10 milliseconds */
		vTaskDelayUntil(&xLastWakeTime, (1000/ portTICK_RATE_MS) );
	}
}


void vUpdateGUIFunction( void )
{
	portTickType xLastWakeTime;

	xLastWakeTime = xTaskGetTickCount();
	for( ;; )
		{

			displayGui();
			/* Enter the blocked state for 10 milliseconds */
			vTaskDelayUntil(&xLastWakeTime, (10/ portTICK_RATE_MS) );
		}
}


void vPollMessageRFunction( void )
{

	portBASE_TYPE xStatus;
	char tempmessage[3];
	const portTickType xTicksToWait = 1 / portTICK_RATE_MS;
	portTickType xLastWakeTime;

	xLastWakeTime = xTaskGetTickCount();
	for( ;; )
	{
		//if( uxQueueMessagesWaiting( xQueueMessagesR) != 0 ) {
		xStatus = xQueueReceive( XQueueMessageR, &tempmessage, xTicksToWait );
		//}
		if ( xStatus == pdPASS )
		{
			decode(tempmessage , 3);
		}
		vTaskDelayUntil(&xLastWakeTime, (10/ portTICK_RATE_MS) );
	}
}
void vPollMessageSFunction( void )
{

	portBASE_TYPE xStatus;
	char tempmessage[1];
	const portTickType xTicksToWait = 100 / portTICK_RATE_MS;


	for( ;; )
	{
		//if( uxQueueMessagesWaiting( xQueueMessagesR) != 0 ) {
		xStatus = xQueueReceive( XQueueMessageS, &tempmessage, xTicksToWait );
		//}
		if ( xStatus == pdPASS )
		{
			decode(tempmessage, 1);
		}
	}
}void vPollMessageAFunction( void )
{

	portBASE_TYPE xStatus;
	char tempmessage[7];
	const portTickType xTicksToWait = 100 / portTICK_RATE_MS;


	for( ;; )
	{
		//if( uxQueueMessagesWaiting( xQueueMessagesR) != 0 ) {
		xStatus = xQueueReceive( XQueueMessageA, &tempmessage, xTicksToWait );
		//}
		if ( xStatus == pdPASS )
		{
			decode(tempmessage, 7);
		}
	}
}

void vPollMessageMFunction( void )
{

	portBASE_TYPE xStatus;
	char tempmessage[5];
	const portTickType xTicksToWait = 100 / portTICK_RATE_MS;

	for( ;; )
	{
		//if( uxQueueMessagesWaiting( xQueueMessagesR) != 0 ) {
		xStatus = xQueueReceive( XQueueMessageM, &tempmessage, xTicksToWait );
		//}
		if ( xStatus == pdPASS )
		{
			decode(tempmessage, 5);
		}
	}
}


void vPollButtonFunction( void )
{
	portTickType xLastWakeTime;

	xLastWakeTime = xTaskGetTickCount();
	for( ;; )
		{

			buttonPress();
			/* Enter the blocked state for 10 milliseconds */
			vTaskDelayUntil(&xLastWakeTime, (1/ portTICK_RATE_MS) );
		}
}




/*-----------------------------------------------------------*/

void vApplicationMallocFailedHook( void )
{
	/* This function will only be called if an API call to create a task, queue
	or semaphore fails because there is too little heap RAM remaining. */
	for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationStackOverflowHook( xTaskHandle *pxTask, signed char *pcTaskName )
{
	/* This function will only be called if a task overflows its stack.  Note
	that stack overflow checking does slow down the context switch
	implementation. */
	for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationIdleHook( void )
{
	/* This example does not use the idle hook to perform any processing. */
}
/*-----------------------------------------------------------*/

void vApplicationTickHook( void )
{
	/* This example does not use the tick hook to perform any processing. */
}


