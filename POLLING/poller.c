/*
 * poller.c
 *
 *  Created on: Feb 8, 2023
 *      Author: Esraa Ossama
 */

#include "poller.h"
#include "device.h"
#include "PollDataClient.h"
#include "../LED/LED_MANAGER.h"
#include "../FreeRTOS/Source/include/FreeRTOS.h"
#include "../FreeRTOS/Source/include/task.h"
#include "../FreeRTOS/Source/include/timers.h"
#include "../utilities/std_types.h"
uint8_t polling_enabled= 1;
uint8_t polling_counter= 1;
uint8_t counter = 0 ;
uint8_t readvalue;
extern TimerHandle_t Right_BlinkTimer;
void Poll(void)
{
	if(polling_enabled && (!counter))
	{
		read_btns();
		handle_state();


	}
	counter++;
	counter = counter%polling_counter;
}

void StartPolling(void)
{
	polling_enabled=1u;
}

void StopPolling(void)
{
	polling_enabled=0u;
}

void SetPollingTime(uint8_t polling_time)
{
	polling_counter = polling_time/100u;
}
