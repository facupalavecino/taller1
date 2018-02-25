#ifndef _STEPPER_H_
#define _STEPPER_H_

#include "sapi.h"
/*==================[inclusions]=============================================*/

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
extern "C" {
#endif

void stepMotor(uint8_t thisStep);

void stepMotorOG(uint8_t thisStep);

void step(int16_t steps_to_move);

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
}
#endif

/*==================[end of file]============================================*/
#endif /* #ifndef _STEPPER_H_ */
