#include "mef.h"
#include "lcd.h"
#include "stepper.h"
#include "sapi.h"
estado e;
static char lcdBuffer[16];

void MEF_init(void) {
	e = INICIAL;
}

void MEF_avanzarESTADO(uint8_t t) {
	switch (e) {
	case INICIAL:
		MEF_actualizarINICIAL();
		switch (t) {
		/* Poner cada tecla */
		case '*':
			break;
		case '#':
			break;
		case '1':
			gpioWrite(LED1,ON);
			break;
		case '2':
			gpioWrite(LED2,ON);
			break;
		case '3':
			gpioWrite(LED3,ON);
			break;
		case '4':
			gpioWrite(LED1,OFF);
			break;
		case '5':
			gpioWrite(LED2,OFF);
			break;
		case '6':
			gpioWrite(LED3,OFF);
			break;
		case '7':
			step(-144);
			break;
		case '8':
			gpioWrite(LEDB,OFF);
			break;
		case '9':
			gpioWrite(LEDR,ON);
			gpioWrite(LEDG,ON);
			gpioWrite(LEDB,ON);
			break;
		case 'A':
			e=CONFIG_HORA;
			MEF_actualizarCONFIG_HORA();
			break;
		case 'B':
			//e=SET_PORCION;
			//MEF_actualizarSET_PORCION();
			break;
		case 'C':
			//e=CONFIG_WIFI;
			//MEF_actualizarCONFIG_WIFI();
			break;
		case 'D':
			e=SET_DESCARGA;
			MEF_actualizarSET_DESCARGA();
			break;
		case '0':
			gpioWrite(LEDR,OFF);
			gpioWrite(LEDG,OFF);
			gpioWrite(LEDB,OFF);
			break;
		default:
			LCD_write_string(itoa(rtc.hour));
				LCD_write_char(':');
				LCD_write_string(itoa(rtc.min));
				LCD_write_char(':');
				LCD_write_string(rtc.sec);
				delayInaccurate(1000);
			break;
		}
		break;
	case CONFIG_WIFI:
		switch (t) {
		/* Poner cada tecla */
		case '*':
			// cancelarwifi();
			e=INICIAL;
			break;
		case '#':
			//guardarconfigwifi();
			break;
		case '1':
			break;
		case '2':
			break;
		case '3':
			break;
		case '4':
			break;
		case '7':
			break;
		case '5':
			break;
		case '8':
			break;
		case '6':
			break;
		case '9':
			break;
		case 'A':
			break;
		case 'B':
			break;
		case 'C':
			break;
		case 'D':
			break;
		case '0':
			break;
		}
		break;
	case CONFIG_HORA:
		switch (t) {
		/* Poner cada tecla */
		case '*':
			break;
		case '#':
			break;
		case '1':
			break;
		case '2':
			break;
		case '3':
			break;
		case '4':
			break;
		case '7':
			break;
		case '5':
			break;
		case '8':
			break;
		case '6':
			break;
		case '9':
			break;
		case 'A':
			break;
		case 'B':
			break;
		case 'C':
			break;
		case 'D':
			break;
		case '0':
		e = INICIAL;
			break;
		}
		break;
	case SET_DESCARGA:

	case SET_PORCION:
		switch (t) {
		/* Poner cada tecla */
		case '*':
			break;
		case '#':
			break;
		case '1':
			break;
		case '2':
			break;
		case '3':
			break;
		case '4':
			break;
		case '7':
			break;
		case '5':
			break;
		case '8':
			break;
		case '6':
			break;
		case '9':
			break;
		case 'A':
			break;
		case 'B':
			break;
		case 'C':
			break;
		case 'D':
			break;
		case '0':
			break;
		}
		break;
	}
}

void MEF_actualizarINICIAL(void) {
	LCD_pos_xy(0,0);
	LCD_write_string("    Estado 0    ");
	LCD_pos_xy(0,1);
	LCD_write_string("    INICIAL     ");
}

void MEF_actualizarCONFIG_WIFI(void) {

}

void MEF_actualizarCONFIG_HORA(void) {
	LCD_pos_xy(0,0);
	LCD_write_string("    Estado A    ");
	LCD_pos_xy(0,1);
	LCD_write_string("  CONFIG_HORA   ");
	LCD_delay_ms(2000);
	LCD_pos_xy(4,0);
	LCD_cursor_blink_on();
}

void MEF_actualizarSET_DESCARGA(void) {
	int muestra = 0;
	muestra = adcRead(CH3);
	itoa(muestra,lcdBuffer,10);
	LCD_pos_xy(0,0);
	LCD_write_string("  Valor Leído   ");
	LCD_pos_xy(0,1);
	LCD_write_string(lcdBuffer);
}

void MEF_actualizarSET_PORCION(void) {

}
