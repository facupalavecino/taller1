#ifndef PROJECTS_TALLER1_DISPENSER_INC_MY_CLOCK_H_
#define PROJECTS_TALLER1_DISPENSER_INC_MY_CLOCK_H_

#include "sapi.h"
/*==================[inclusions]=============================================*/

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
extern "C" {
#endif

char* itoa(int value, char* result, int base);
void configTime();
void showTime(char line);
void updateTime();
void setTime(rtc_t rtc_aux);
void step(int16_t steps_to_move);

void showAlarma(char line, rtc_t rtc1);
void pantallaAlarmas(rtc_t rtc1[]);

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
}
#endif

/*==================[end of file]============================================*/
#endif /* PROJECTS_TALLER1_DISPENSER_INC_MY_CLOCK_H_ */
