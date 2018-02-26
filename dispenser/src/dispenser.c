/* Copyright 2016, Eric Pernia.
 * All rights reserved.
 *
 * This file is part sAPI library for microcontrollers.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/*
 * Date: 2016-04-26
 */

/*==================[inclusions]=============================================*/

#include "dispenser.h"       /* <= own header */
#include "teclado_matricial.h"
#include "lcd.h"
#include "stepper.h"
#include "mef.h"
#include <stdlib.h>
#include "my_clock.h";

#include "sapi.h"         /* <= sAPI header */

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/
keypad_t keypad;

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

/* FUNCION PRINCIPAL, PUNTO DE ENTRADA AL PROGRAMA LUEGO DE RESET. */
int main(void) {

	//Inicializar placa
  	boardConfig();
	//Inicializar LCD
	LCD_init(_2_LINES | DISPLAY_8X5, CURSOR_OFF | DISPLAY_ON);
	//Inicializar cfg del teclado
	uint16_t nro_tecla = 0;
	uint8_t tecla_recibida;
	//INIT_KEYBOARD();
	/* Configuracion de pines para el Teclado Matricial*/

	// Filas --> Salidas
	uint8_t keypadRowPins[4] = { T_FIL0,	 // Row 0
			T_FIL1,    // Row 1
			T_FIL2,    // Row 2
			T_FIL3     // Row 3
			};

	// Columnas --> Entradas con pull-up (MODO = GPIO_INPUT_PULLUP)
	uint8_t keypadColPins[4] = { T_COL0,    // Column 0
			T_COL1,    // Column 1
			T_COL2,    // Column 2
			CAN_TD     // Column 3
			};

	keypadConfig(&keypad, keypadRowPins, 4, keypadColPins, 4);

	uint8_t keypad_key(uint8_t ntecla) {

		// Vector de conversion entre indice de tecla presionada y el indice del display 7 segmentos
		char keypadToChar[16] = { '1', '2', '3', 'A', '4', '5', '6', 'B', '7',
				'8', '9', 'C', '*', '0', '#', 'D' };
		return keypadToChar[ntecla];

	}
	//Configuracion pines para motor
	gpioConfig(GPIO2, GPIO_OUTPUT); // ENABLE A
	gpioConfig(GPIO8, GPIO_OUTPUT); // ENABLE B
	gpioWrite(GPIO2, OFF);
	gpioWrite(GPIO8, OFF);

	//Secuencia orishinal
	gpioConfig(GPIO0, GPIO_OUTPUT); // Negro
	gpioConfig(GPIO7, GPIO_OUTPUT); // Marron
	gpioConfig(GPIO3, GPIO_OUTPUT); // Amarillo
	gpioConfig(GPIO5, GPIO_OUTPUT); // Naranja

	//Secuencia invert
//	gpioConfig(GPIO7, GPIO_OUTPUT); // Negro
//	gpioConfig(GPIO0, GPIO_OUTPUT); // Marron
//	gpioConfig(GPIO5, GPIO_OUTPUT); // Amarillo
//	gpioConfig(GPIO3, GPIO_OUTPUT); // Naranja

//	gpioConfig(GPIO1, GPIO_OUTPUT); // Negro
//	gpioConfig(GPIO2, GPIO_OUTPUT); // Marron
//	gpioConfig(GPIO3, GPIO_OUTPUT); // Amarillo
//	gpioConfig(GPIO4, GPIO_OUTPUT); // Naranja
	//Inicializar MEF
	MEF_init();
	//Inicializar ADC
	adcConfig(ADC_ENABLE);
	gpioWrite(LED1, ON);

	LCD_pos_xy(0, 0);
	LCD_write_string("  Iniciando...  ");

	configTime();

	while (1) {
		if (keypadRead(&keypad, &nro_tecla)) {
			tecla_recibida = keypad_key(nro_tecla);
			MEF_avanzarESTADO(keypad_key(nro_tecla));
		} else {
			MEF_avanzarESTADO('x');
		}
	}

	return 0;
}

/*==================[end of file]============================================*/
