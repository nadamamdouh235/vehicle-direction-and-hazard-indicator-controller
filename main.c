#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
//#include <util/delay.h>
#include "EXT_INTERRUPT/EXT_INTTERUPT.h"
#include "DIO/DIO.h"
#include "STATE_MACHINE/switchcases.h"
#include "POLLING/poller.h"
#include "POLLING/device.h"
#include "POLLING/PollDataClient.h"
#include "LED/LED.h"
#include "LED/LED_MANAGER.h"
#include "utilities/std_types.h"
#include "../TIMERS/TIMER0.h"
#include "../TIMERS/TIMER2.h"



TaskHandle_t myCallerPollHandler = NULL;
TaskHandle_t FSM_Handler = NULL;
TaskHandle_t toggle_handler = NULL;
TimerHandle_t Right_BlinkTimer;
TimerHandle_t Left_BlinkTimer;
state_types state;
uint8_t Right_LED_Counter = 0u;
uint8_t Left_LED_Counter = 0u;
uint8_t ticks = pdMS_TO_TICKS( 50u );



void Blink_Right_LED(TimerHandle_t xTimer);
void Blink_Left_LED(TimerHandle_t xTimer );
void call_Polling(void);
void call_FSM(void);



void call_Polling(void){

	while(1){

		Poll();
		vTaskDelay(ticks);
	}
}

void call_FSM(void){

	while(1){

	SYSTEM_BEHAVIOR();
	
	vTaskDelay(ticks);
	}
}

void Blink_Right_LED(TimerHandle_t xTimer){

	if (Right_LED_Counter == 0u){
		PWM2_Write(1u);

		Right_LED_Counter ++;
	}
	else {
			PWM2_Write(200u);

			Right_LED_Counter = 0u;
	}
	
}

void Blink_Left_LED(TimerHandle_t xTimer ){

	if (Left_LED_Counter == 0u){

		PWM_Write(1u);

		Left_LED_Counter ++;

	}
	else {

		PWM_Write(200u);

		Left_LED_Counter = 0u;
	}
}

int main (void)
{

	init_btns();
	Right_LED_init();
	Left_LED_init();
	//LED_off(PORTD_ID, 7);
	//LED_off(PORTB_ID, 3);
	
	uint8_t LED_ticks = pdMS_TO_TICKS( 500u );

	xTaskCreate(call_Polling,"Calling_poll",200,NULL,2,&myCallerPollHandler);
	xTaskCreate(call_FSM,"Calling_switchcases",200,NULL,1,&FSM_Handler);
	Right_BlinkTimer=xTimerCreate("Right_blink_timer",LED_ticks,pdTRUE, ( void * ) 0,Blink_Right_LED);
	Left_BlinkTimer=xTimerCreate("Left_blink_timer",LED_ticks,pdTRUE, ( void * ) 0,Blink_Left_LED);
	//xTimerStart(Right_BlinkTimer, 0);
	//xTimerStart(Left_BlinkTimer, 0);

	
	vTaskStartScheduler();

}
