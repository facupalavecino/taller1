#include "stepper.h"
#include "sapi.h"
#include <stdlib.h>

bool_t valor;
uint8_t number_of_steps = 48;
int16_t step_number = 0;
bool_t direction;
tick_t last_step_time = 0;
tick_t step_delay = 20;
extern volatile tick_t tickRateMS;

void stepMotor(uint8_t thisStep) {
	switch (thisStep) {
	case 0:  // 1010
		gpioWrite(GPIO1, OFF);
		gpioWrite(GPIO2, ON);
		gpioWrite(GPIO3, OFF);
		gpioWrite(GPIO4, ON);
		break;
	case 1:  // 0110
		gpioWrite(GPIO1, OFF);
		gpioWrite(GPIO2, ON);
		gpioWrite(GPIO3, ON);
		gpioWrite(GPIO4, OFF);
		break;
	case 2:  //0101
		gpioWrite(GPIO1, ON);
		gpioWrite(GPIO2, OFF);
		gpioWrite(GPIO3, ON);
		gpioWrite(GPIO4, OFF);
		break;
	case 3:  //1001
		gpioWrite(GPIO1, ON);
		gpioWrite(GPIO2, OFF);
		gpioWrite(GPIO3, OFF);
		gpioWrite(GPIO4, ON);
		break;
	}
}

void step(int16_t steps_to_move) {
	int16_t steps_left = abs(steps_to_move);
	if (steps_to_move > 0) {
		direction = 1;
	}
	if (steps_to_move < 0) {
		direction = 0;
	}

	while (steps_left > 0) {
		tick_t now = tickRead() / tickRateMS; // Ver como tomar el tiempo

		if (now - last_step_time >= step_delay) {
			last_step_time = now;
			if (direction == 1) {
				step_number++;
				if (step_number == number_of_steps) {
					step_number = 0;
				}
			} else {
				if (step_number == 0) {
					step_number = number_of_steps;
				}
				step_number--;

			}

			steps_left--;
			stepMotor(step_number % 4);
		}
	}

}
