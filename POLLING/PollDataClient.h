#ifndef POLLDATACLIENT_H_
#define POLLDATACLIENT_H_


typedef enum
{
	R_BTN,
	L_BTN,
	H_BTN,
	NO_INDICATOR,
}state_types;


/*function prototypes*/

void handle_state(void);


#endif
