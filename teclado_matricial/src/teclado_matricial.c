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
 * Date: 2016-07-28
 */

/*==================[inclusions]=============================================*/

#include "teclado_matricial.h"          /* <= own header */

#include "sapi.h"                     /* <= sAPI header */

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/


/* FUNCION PRINCIPAL, PUNTO DE ENTRADA AL PROGRAMA LUEGO DE RESET. */
int main(void){

   /* ------------- INICIALIZACIONES ------------- */

   /* Inicializar la placa */
	/*Acá se configuran los LEDS como salida*/
   boardConfig();

   /* Configuracion de pines para el Teclado Matricial*/

   // Teclado
   keypad_t keypad;

   // Filas --> Salidas
   uint8_t keypadRowPins[4] = {
      T_FIL0,	 // Row 0
      T_FIL1,    // Row 1
      T_FIL2,    // Row 2
      T_FIL3     // Row 3
   };

   // Columnas --> Entradas con pull-up (MODO = GPIO_INPUT_PULLUP)
   uint8_t keypadColPins[4] = {
      T_COL0,    // Column 0
      T_COL1,    // Column 1
      T_COL2,    // Column 2
      CAN_TD     // Column 3
   };

   keypadConfig( &keypad, keypadRowPins, 4, keypadColPins, 4 );


   // Vector de conversion entre indice de tecla presionada y el Ã­ndice del
   // display 7 segmentos
   char keypadToChar[16] = {'1','2','3','A','4','5','6','B','7','8','9','C','*','0','#','D'};

   // Variable para guardar la tecla leida
   uint16_t tecla = 0;
   int i;

   /* ------------- REPETIR POR SIEMPRE ------------- */
   while(1) {

      if( keypadRead( &keypad, &tecla ) ){
         /*Se presionó una tecla, el valor numérico está en la variable 'tecla'*/
    	 switch(keypadToChar[tecla]){
    	 case '1':
    		 /*Prendo LED 1, 1 vez*/
    		 gpioWrite (LED1, ON);
    		 delay(100);
    		 gpioWrite (LED1, OFF);
    		 break;
    	 case '2':
    		 /*Prendo LED 1, 2 veces*/
    		 for (i = 0; i < 2; i++){
        		 gpioWrite (LED1, ON);
        		 delay(100);
        		 gpioWrite (LED1, OFF);
        		 delay(100);
    		 }
    		 break;
    	 case '3':
    		 /*Prendo LED 1, 3 veces*/
    		 for (i = 0; i < 3; i++){
        		 gpioWrite (LED1, ON);
        		 delay(100);
        		 gpioWrite (LED1, OFF);
        		 delay(100);
    		 }
    		 break;
    	 case'A':
    		 /*Prendo LED 1, 4 veces*/
    		 for (i = 0; i < 4; i++){
        		 gpioWrite (LED1, ON);
        		 delay(100);
        		 gpioWrite (LED1, OFF);
        		 delay(100);
    		 }
    		 break;
    	 case '4':
    		 /*Prendo LED 2, 1 vez*/
    		 gpioWrite(LED2, ON);
    		 delay(100);
    		 gpioWrite(LED2, OFF);
    		 break;
    	 case '5':
    		 /*Prendo LED 2, 2 veces*/
    		 for (i = 0; i < 2; i++){
        		 gpioWrite(LED2, ON);
        		 delay(100);
        		 gpioWrite(LED2, OFF);
        		 delay(100);
    		 }
    		 break;
    	 case '6':
    		 /*Prendo LED 2, 3 veces*/
    		 for (i = 0; i < 3; i++){
        		 gpioWrite(LED2, ON);
        		 delay(100);
        		 gpioWrite(LED2, OFF);
        		 delay(100);
    		 }
    		 break;
    	 case'B':
    		 /*Prendo LED 2, 4 veces*/
    		 for (i = 0; i < 4; i++){
        		 gpioWrite(LED2, ON);
        		 delay(100);
        		 gpioWrite(LED2, OFF);
        		 delay(100);
    		 }
    		 break;
    	 case '7':
    		 /*Prendo LED 3, 1 vez*/
    		 gpioWrite(LED3, ON);
    		 delay(100);
    		 gpioWrite(LED3, OFF);
    		 break;
    	 case '8':
    		 /*Prendo LED 3, 2 veces*/
    		 for (i = 0; i < 2; i++){
        		 gpioWrite(LED3, ON);
        		 delay(100);
        		 gpioWrite(LED3, OFF);
        		 delay(100);
    		 }
    		 break;
    	 case '9':
    		 /*Prendo LED 3, 3 veces*/
    		 for (i = 0; i < 3; i++){
        		 gpioWrite(LED3, ON);
        		 delay(100);
        		 gpioWrite(LED3, OFF);
        		 delay(100);
    		 }
    		 break;
    	 case'C':
    		 /*Prendo LED 3, 4 veces*/
    		 for (i = 0; i < 4; i++){
        		 gpioWrite(LED3, ON);
        		 delay(100);
        		 gpioWrite(LED3, OFF);
        		 delay(100);
    		 }
    		 break;
    	 case '*':
    		 /*Prendo LED B, 1 vez*/
    		 gpioWrite(LEDB, ON);
    		 delay(100);
    		 gpioWrite(LEDB, OFF);
    		 break;
    	 case '0':
    		 /*Prendo LED B, 2 veces*/
    		 for(i = 0; i < 2; i++){
        		 gpioWrite(LEDB, ON);
        		 delay(100);
        		 gpioWrite(LEDB, OFF);
        		 delay(100);
    		 }
    		 break;
    	 case '#':
    		 /*Prendo LED B, 3 veces*/
    		 for(i = 0; i < 3; i++){
        		 gpioWrite(LEDB, ON);
        		 delay(100);
        		 gpioWrite(LEDB, OFF);
        		 delay(100);
    		 }
    		 break;
    	 case'D':
    		 /*Prendo LED B, 4 veces*/
    		 for(i = 0; i < 4; i++){
        		 gpioWrite(LEDB, ON);
        		 delay(100);
        		 gpioWrite(LEDB, OFF);
        		 delay(100);
    		 }
    		 break;
    	 default:
    		 break;
    	 }

      } else{
         /*No se presionó nada*/
      }
   }

   /* NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa no es llamado
      por ningun S.O. */
   return 0 ;
}

/*==================[end of file]============================================*/
