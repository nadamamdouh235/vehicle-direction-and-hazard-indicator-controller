#include "../HWAL/LED/LED.h"
#include "../HWAL/LED/LED_MANAGER.h"
#include "../POLLING/PollDataClient.h"
#include "../MCUAL/TIMERS/TIMER0.h"
#include "../MCUAL/TIMERS/TIMER2.h"


static uint8_t u8_static_CurrState;
static uint8_t u8_static_PrevState;
uint8_t u8_global_Counter = 0;
extern state_types state;
extern uint8_t Change_State;

void SYSTEM_BEHAVIOR (void)
{
	
	if (Change_State == 1){
		Change_State = 0;
	switch (state)
	{
		case R_BTN :
		//if (u8_global_Counter == 0){
		//xTimerReset(BlinkTimer, 0);
		//u8_static_CurrState = R_BTN;
		Right_LED_BLINKING();
		//u8_static_PrevState = u8_static_CurrState;
		//}
		break;
		
		case L_BTN :
		//if (u8_global_Counter == 0){
		//xTimerReset(BlinkTimer, 0);
		//u8_static_CurrState = L_BTN;
		Left_LED_BLINKING();
		//u8_static_PrevState = u8_static_CurrState;
		//}
		break;
		
		case H_BTN :
		//if (u8_global_Counter == 0)
		//{
			
				//xTimerReset(BlinkTimer, 0);
				Blink_Both();
				//u8_global_Counter ++;
				
		//}
		
		//else if (u8_global_Counter == 1)
		//{
			//state = u8_static_PrevState;
			////xTimerReset(BlinkTimer, 0);
			//u8_global_Counter = 0;
		//}
		break;
		
		default:
			//LED_on(PORTC_ID, PIN3_ID);

		//xTimerStop(Right_BlinkTimer,0);
		//xTimerStop(Left_BlinkTimer,0);
		PWM2_Write(1);
		PWM_Write(1);
		//LED_off(Right_LED_Port, Right_LED_Pin);
		//LED_off(Left_LED_Port, Left_LED_Pin);
		break;
	}
	
}
}