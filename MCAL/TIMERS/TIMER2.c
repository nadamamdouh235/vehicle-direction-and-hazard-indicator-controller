/*
 * TIMER1.c
 *
 * Created: 2/9/2023 12:04:46 PM
 *  Author: nada
 */ 
#include "TIMER2.h"
void TIMER2_init(const Timer2_ConfigType * config_Ptr)
{
	if((config_Ptr->TIMER2_mode) != TIMER2_FAST_PWM_MODE)
	{ SET_BIT(TCCR0,7);  
		}/*active only for non-PWM*/
	
	TCCR2  |= (uint8_t)((uint8_t)(((uint8_t)(config_Ptr->TIMER2_mode) & (uint8_t)(0x01)) << (uint8_t)(6)) | (uint8_t)(((uint8_t)(config_Ptr->TIMER2_mode) & (uint8_t)(0x02)) << (uint8_t)(3)));/*set WGM20 WGM21  */
	TCCR2  |= (uint8_t)((uint8_t)(((uint8_t)(config_Ptr->TIMER2_compare_output_mode) & (uint8_t)(0x01)) << (uint8_t)(4) ) | (uint8_t)(((uint8_t)(config_Ptr->TIMER2_compare_output_mode) & (uint8_t)(0x02)) << (uint8_t)(5)));/*set COM21 COM20  */

	TCCR2 |= config_Ptr->TIMER2_clock; /*  choose clock         */ 

	}


 void PWM2_Write(uint8_t value)
 {
	 OCR2 = value;
 }
