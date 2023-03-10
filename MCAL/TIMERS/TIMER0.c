/******************************************************************************
 *
 * Module: TIMER0
 *
 * File Name: timer0.c
 *
 * Description: source file for the AVR timer0 driver
 *
 * Author: Hesham Shehata
 *
 *******************************************************************************/	
#include "TIMER0.h"
#include "../utilities/std_types.h"


void TIMER0_init(const Timer0_ConfigType * config_Ptr)
{
	if((config_Ptr->TIMER0_mode) != TIMER0_FAST_PWM_MODE){
		SET_BIT(TCCR0,7);  /* active only for non-PWM */
	}
	else{
	    /*nothing to do*/
	}
	TCCR0  |= (uint8_t)((uint8_t)(((uint8_t)(config_Ptr->TIMER0_mode) & (uint8_t)(0x01)) << (uint8_t)(6)) | (uint8_t)(((uint8_t)(config_Ptr->TIMER0_mode) & (uint8_t)(0x02)) << (uint8_t)(3)));/*set WGM00 WGM01  */
	TCCR0  |= (uint8_t)((uint8_t)(((uint8_t)(config_Ptr->TIMER0_compare_output_mode) & (uint8_t)(0x01)) << (uint8_t)(4) ) | (uint8_t)(((uint8_t)(config_Ptr->TIMER0_compare_output_mode) & (uint8_t)(0x02)) << (uint8_t)(5)));/*set COM21 COM20  */
	TCCR0 |= config_Ptr->TIMER0_clock; /*  choose clock  */
}

 void PWM_Write(uint8_t value)
 {
	 OCR0 = value;
 }
