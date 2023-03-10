/*
 * PollDataClient.c
 *
 *  Created on: Feb 8, 2023
 *      Author: Esraa Ossama
 */

#include "../utilities/std_types.h"
#include "PollDataClient.h"
#include "../DIO/DIO.h"
#include "../FreeRTOS/Source/include/FreeRTOS.h"
#include "../FreeRTOS/Source/include/task.h"
#include "../FreeRTOS/Source/include/timers.h"
#include "../LED/LED.h"
#include "../TIMERS/TIMER0.h"
#include "../TIMERS/TIMER2.h"




extern TimerHandle_t Right_BlinkTimer;
extern TimerHandle_t Left_BlinkTimer;



uint8_t prev_hazard_btn_state = LOGIC_LOW;
uint8_t prev_right_indicator_state = LOGIC_LOW;
uint8_t prev_left_indicator_state = LOGIC_LOW;
uint8_t prev_ignition_sw_state = LOGIC_LOW;
uint8_t prev_null_sw_state = LOGIC_LOW;

uint8_t hazard_btn_state;
uint8_t right_indicator_state;
uint8_t left_indicator_state;
uint8_t ignition_sw_state;
uint8_t null_sw_state;

state_types state = NO_INDICATOR;
uint8_t hazard_flag = 0;
uint8_t Change_State = 0;

void handle_state(void){

	if((prev_ignition_sw_state == LOGIC_LOW) && (ignition_sw_state == LOGIC_LOW) && (state != H_BTN)){

		if ((prev_right_indicator_state == LOGIC_LOW) && (right_indicator_state == LOGIC_LOW)){
			if (state != R_BTN){
			state = R_BTN;
			Change_State = 1u;
			xTimerStop(Right_BlinkTimer,0);
			xTimerStop(Left_BlinkTimer,0);
			PWM2_Write(1u);
			PWM_Write(1u);
			}
		}

		else if((prev_left_indicator_state == LOGIC_LOW) && (left_indicator_state == LOGIC_LOW)){
			if (state != L_BTN){
			state = L_BTN;
			Change_State = 1u;
			xTimerStop(Left_BlinkTimer,0);
			xTimerStop(Right_BlinkTimer,0);
			PWM2_Write(1u);
			PWM_Write(1u);
			}
		}
		else if((prev_null_sw_state == LOGIC_LOW) && (null_sw_state == LOGIC_LOW)){
			if (state != NO_INDICATOR){
			state = NO_INDICATOR;
			xTimerStop(Right_BlinkTimer,0);
			xTimerStop(Left_BlinkTimer,0);
			PWM2_Write(1u);
			PWM_Write(1u);
			}
		}

		prev_right_indicator_state = right_indicator_state;
		prev_left_indicator_state = left_indicator_state;
		prev_null_sw_state = null_sw_state;

	}

	else if(state != H_BTN){
		if(state != NO_INDICATOR){
		state = NO_INDICATOR;
		Change_State = 1u;
		xTimerStop(Right_BlinkTimer,0);
		xTimerStop(Left_BlinkTimer,0);
		PWM2_Write(1);
		PWM_Write(1);
	}
	}
	prev_ignition_sw_state = ignition_sw_state;


	if ((prev_hazard_btn_state == LOGIC_LOW) && (hazard_btn_state == LOGIC_HIGH)){
		if (state != H_BTN){
		state = H_BTN;
		Change_State = 1u;
		xTimerStop(Right_BlinkTimer,0);
		xTimerStop(Left_BlinkTimer,0);
		PWM2_Write(1u);
		PWM_Write(1u);
		}
		hazard_flag ++;
		if (hazard_flag != 1u){
			state = NO_INDICATOR;
			Change_State = 1u;
			xTimerStop(Right_BlinkTimer,0);
			xTimerStop(Left_BlinkTimer,0);
		}
		hazard_flag = hazard_flag % 2u;
	}
	prev_hazard_btn_state = hazard_btn_state;
}

