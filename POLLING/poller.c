/*
 *  Author: The Fantastic Five ??
 */
#include "poller.h"
#include "device.h"
#include "PollDataClient.h"
#include "../HWAL/LED/LED_MANAGER.h"
#include "../FreeRTOS/Source/include/FreeRTOS.h"
#include "../FreeRTOS/Source/include/task.h"
#include "../FreeRTOS/Source/include/timers.h"

int polling_enabled= 1;
int polling_counter= 1;
int counter = 0 ;
uint8_t readvalue;
extern TimerHandle_t Right_BlinkTimer;
void Poll(void)
{
	if(polling_enabled && (!counter))
	{
		update_btns();
		//readvalue = DIO_readPin(PORTA_ID,PIN0_ID);
		//if(readvalue ==0){
		handle_state();

		//xTimerStop(Right_BlinkTimer, 0);
		//LED_off(Right_LED_Port, Right_LED_Pin);
		//PWM2_Write(0);
		//LED_on(Left_LED_Port, Left_LED_Pin);
		//}
//		test();

	}
	counter++;
	counter = counter%polling_counter;
}

void StartPolling(void)
{
	polling_enabled=1;
}

void StopPolling(void)
{
	polling_enabled=0;
}

void SetPollingTime(int polling_time)
{
	polling_counter = polling_time/100;
}
