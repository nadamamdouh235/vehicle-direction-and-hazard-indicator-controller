/*
 * device.c
 *
 *  Created on: Feb 8, 2023
 *      Author: Esraa Ossama
 */
#include "../DIO/DIO.h"
#include "../BTN/btn.h"
#include "device.h"

btn_init_param button_init_parameters[5];

extern uint8_t hazard_btn_state;
extern uint8_t right_indicator_state;
extern uint8_t left_indicator_state;
extern uint8_t ignition_sw_state;
extern uint8_t null_sw_state;


btn_init_param *hbtn_id;
btn_init_param *rbtn_id;
btn_init_param *lbtn_id;
btn_init_param *ignition_btn_id;
btn_init_param *null_btn_id;

void init_btns(void){
	BUTTON_init(rbtn_id);
	BUTTON_init(lbtn_id);
	BUTTON_init(hbtn_id);
	BUTTON_init(ignition_btn_id);
	BUTTON_init(null_btn_id);
	DIO_setupPinDirection(PORTC_ID,PIN0_ID,OUTPUT_PIN);
	DIO_setupPinDirection(PORTC_ID,PIN1_ID,OUTPUT_PIN);

}

void read_btns(void){
	hazard_btn_state = BUTTON_read(hbtn_id);
	right_indicator_state = BUTTON_read(rbtn_id);
	left_indicator_state = BUTTON_read(lbtn_id);
	ignition_sw_state = BUTTON_read(ignition_btn_id);
	null_sw_state = BUTTON_read(null_btn_id);

}

