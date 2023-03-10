#include "../LED/LED.h"
#include "../LED/LED_MANAGER.h"
#include "../POLLING/PollDataClient.h"
#include "../TIMERS/TIMER0.h"
#include "../TIMERS/TIMER2.h"


#include "switchcases.h"
extern state_types state;
extern uint8_t Change_State;

void SYSTEM_BEHAVIOR (void)
{
	
	if (Change_State == (uint8_t)1){
		Change_State = (uint8_t)0;
	switch (state)
	{
		case R_BTN :
		Right_LED_BLINKING();
		break;
		
		case L_BTN :
		Left_LED_BLINKING();
		break;
		
		case H_BTN :
			
				Blink_Both();

		break;
		
		default:
		PWM2_Write(1u);
		PWM_Write(1u);

		break;
	}
	
}
}
