/******************************************
* Module: common - standard types
*
* File Name: std_types.h
*
* Description: typedefs for data types to meaningful easy
*
* Author: Hesham Shehata
*
******************************************/


#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_

/*********************************************************
*               Function like macros
*********************************************************/


/* set a certain bit in any register*/
#define SET_BIT(REG,BIT) ((REG) |= ((uint8_t)((uint8_t)(1)<<(uint8_t)(BIT))))

/* clear a certain bit in any register*/
#define CLEAR_BIT(REG,BIT)     ((REG) &= (uint8_t)(~((uint8_t)((uint8_t)(1)<<(uint8_t)(BIT)))))

/* toggle a certain bit in any register*/
#define TOGGLE_BIT(REG,BIT)    ((REG) ^= (uint8_t)((uint8_t)(1)<<(uint8_t)(BIT)))

/* rotate register right with number of rotate*/
#define ROR(REG,NUM)           ((REG) = ((uint8_t)((REG) >> (uint8_t)(NUM))) | ((uint8_t)((REG) << ((uint8_t)(8-NUM)))))

/* rotate register left with number of rotate */
#define ROL(REG,NUM)           ((REG) = ((uint8_t)((REG) << (uint8_t)(NUM))) | ((uint8_t)((REG) >> ((uint8_t)(8-NUM)))))

/* check if specific bit is set and if set return "yes" */
#define  BIT_IS_SET(REG,BIT)   ((uint8_t)((REG) & ((uint8_t)((uint8_t)(1)<<(uint8_t)(BIT)))))

/* check if specific bit is clear and if clear return "yes" */
#define BIT_IS_CLEAR(REG,BIT)  ((uint8_t)(!((REG) & ((uint8_t)((uint8_t)(1)<<(uint8_t)(BIT))))))


#endif /* COMMON_MACROS_H_ */
