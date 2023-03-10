/*
 * device.h
 *
 *  Created on: Feb 8, 2023
 *      Author: Esraa Ossama
 */
#ifndef POLLER_H_
#define POLLER_H_
#include "../utilities/std_types.h"
/*function prototypes*/

void Poll(void);
void StartPolling(void);
void StopPolling(void);
void SetPollingTime(uint8_t polling_time);

#endif
