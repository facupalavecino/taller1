#include "mef.h"
#include "lcd.h"
#include "stepper.h"
#include "sapi.h"
#include "my_clock.h"

estado e;
static char lcdBuffer[16];
rtc_t rtc_aux;
extern volatile bool_t val;
int cursor;
int hora_int[16];
uint16_t porcion = 100;
uint16_t porcion_aux = 100;

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
			gpioWrite(LED1, ON);
			break;
		case '2':
			gpioWrite(LED2, ON);
			break;
		case '3':
			gpioWrite(LED3, ON);
			break;
		case '4':
			gpioWrite(LED1, OFF);
			break;
		case '5':
			gpioWrite(LED2, OFF);
			break;
		case '6':
			gpioWrite(LED3, OFF);
			break;
		case '7':
			LCD_pos_xy(0, 1);
			LCD_write_string("   Sirviendo   ");
			step(48);
			step(-24);
			step(48);
			step(-24);
			step(48);
			break;
		case '8':
			gpioWrite(LEDB, OFF);
			break;
		case '9':
			gpioWrite(LEDR, ON);
			gpioWrite(LEDG, ON);
			gpioWrite(LEDB, ON);
			break;
		case 'A':
			e = CONFIG_HORA;
			LCD_pos_xy(0, 0);
			LCD_write_string("Configurar Hora ");
			showTime(1);
			LCD_cursor_blink_on();
			cursor = 4;
			LCD_pos_xy(cursor, 1);
			val = rtcRead(&rtc_aux);
			hora_int[4] = rtc_aux.hour / 10;
			hora_int[5] = rtc_aux.hour % 10;
			hora_int[7] = rtc_aux.min / 10;
			hora_int[8] = rtc_aux.min % 10;
			hora_int[10] = rtc_aux.sec / 10;
			hora_int[11] = rtc_aux.sec % 10;
			break;
		case 'B':
			e = SET_PORCION;
			LCD_pos_xy(0, 0);
			LCD_write_string("Config. Porcion ");
			LCD_pos_xy(0, 1);
			switch (porcion) {
			case 100:
				LCD_write_string("     100 gr.    ");
				break;
			case 200:
				LCD_write_string("     200 gr.    ");
				break;
			case 300:
				LCD_write_string("     300 gr.    ");
				break;
			case 400:
				LCD_write_string("     400 gr.    ");
				break;
			case 500:
				LCD_write_string("     500 gr.    ");
				break;
			case 600:
				LCD_write_string("     600 gr.    ");
				break;
			case 700:
				LCD_write_string("     700 gr.    ");
				break;
			case 800:
				LCD_write_string("     800 gr.    ");
				break;
			case 900:
				LCD_write_string("     900 gr.    ");
				break;
			}
			break;
		case 'C':
			//e=CONFIG_WIFI;
			//MEF_actualizarCONFIG_WIFI();
			break;
		case 'D':
			e = SET_DESCARGA;
			LCD_pos_xy(0, 0);
			LCD_write_string("A)10:30  B)15:30");
			LCD_pos_xy(0, 1);
			LCD_write_string("C)18:30  D)20:30");
			//MEF_actualizarSET_DESCARGA();
			break;
		case '0':
			gpioWrite(LEDR, OFF);
			gpioWrite(LEDG, OFF);
			gpioWrite(LEDB, OFF);
			break;
		default:
			break;
		}
		break;
	case CONFIG_WIFI:
		switch (t) {
		/* Poner cada tecla */
		case '*':
			// cancelarwifi();
			e = INICIAL;
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
		MEF_actualizarCONFIG_HORA(t);
		break;
	case SET_DESCARGA:
		MEF_actualizarSET_DESCARGA(t);
		break;
	case SET_PORCION:
		MEF_actualizarSET_PORCION(t);

	}
}

void MEF_actualizarINICIAL(void) {
	updateTime();
	LCD_pos_xy(0, 0);
	LCD_write_string("Dispenser Activo");
	showTime(1);
}

void MEF_actualizarCONFIG_WIFI(void) {

}

void MEF_actualizarCONFIG_HORA(uint8_t tecla) {
	switch (tecla) {
	case '*':
		LCD_cursor_blink_off();
		e = INICIAL;
		break;
	case '#':
		rtc_aux.hour = hora_int[4] * 10 + hora_int[5];
		rtc_aux.min = hora_int[7] * 10 + hora_int[8];
		rtc_aux.sec = hora_int[10] * 10 + hora_int[11];
		if ((rtc_aux.hour < 25) && (rtc_aux.min < 60) && (rtc_aux.sec < 60)) {
			LCD_pos_xy(0, 0);
			LCD_write_string("Hora modificada!");
			setTime(rtc_aux);
			delay(1500);
		} else {
			LCD_pos_xy(0, 0);
			LCD_write_string("Valor Incorrecto");
			delay(1500);
		}
		LCD_cursor_blink_off();
		e = INICIAL;
		break;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		if ((cursor == 4 && (tecla < '2') && hora_int[5] >= 4)
				|| (cursor == 4 && (tecla < '3') && hora_int[5] < 4)
				|| (hora_int[4] == 2 && cursor == 5 && (tecla < '4'))
				|| (hora_int[4] < 2 && cursor == 5)
				|| (cursor == 7 && (tecla < '6')) || (cursor == 8)
				|| (cursor == 10 && (tecla < '6')) || (cursor == 11)) {
			hora_int[cursor] = tecla - '0';
			LCD_pos_xy(cursor, 1);
			LCD_write_char(tecla);
			cursor++;
			switch (cursor) {
			case 6:
			case 9:
				cursor++;
				LCD_pos_xy(cursor, 1);
				break;
			case 12:
				cursor = 4;
				LCD_pos_xy(cursor, 1);
				break;
			}
			delay(200); // Agrego delay porque si no lee como que ingresaste la misma tecla más de una vez.
		}
		LCD_pos_xy(cursor, 1);
		break;
	case 'A':
	case 'B':
	case 'C':
	case 'D':
		break;
	}
}

void MEF_actualizarSET_DESCARGA(uint8_t tecla) {
	//int muestra = 0;
	//muestra = adcRead(CH3);
	//itoa(muestra, lcdBuffer, 10);
	//LCD_pos_xy(0, 0);
	//LCD_write_string("  Valor Leido   ");
	//LCD_pos_xy(0, 1);
	//LCD_write_string(lcdBuffer);

	switch (tecla) {
	/* Poner cada tecla */
	case '*':
		e = INICIAL;
		break;
	case '#':
		e = INICIAL;
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
}

void MEF_actualizarSET_PORCION(uint8_t tecla) {
	switch (tecla) {
	/* Poner cada tecla */
	case '*':
		e = INICIAL;
		break;
	case '#':
		porcion = porcion_aux;
		LCD_pos_xy(0, 0);
		LCD_write_string("Valor modificado!");
		delay(1500);
		e = INICIAL;
		break;
	case '1':
		porcion_aux = 100;
		LCD_pos_xy(0, 1);
		LCD_write_string("     100 gr.    ");
		break;
	case '2':
		porcion_aux = 200;
		LCD_pos_xy(0, 1);
		LCD_write_string("     200 gr.    ");
		break;
	case '3':
		porcion_aux = 300;
		LCD_pos_xy(0, 1);
		LCD_write_string("     300 gr.    ");
		break;
	case '4':
		porcion_aux = 400;
		LCD_pos_xy(0, 1);
		LCD_write_string("     400 gr.    ");
		break;
	case '7':
		porcion_aux = 700;
		LCD_pos_xy(0, 1);
		LCD_write_string("     700 gr.    ");
		break;
	case '5':
		porcion_aux = 500;
		LCD_pos_xy(0, 1);
		LCD_write_string("     500 gr.    ");
		break;
	case '8':
		porcion_aux = 800;
		LCD_pos_xy(0, 1);
		LCD_write_string("     800 gr.    ");
		break;
	case '6':
		porcion_aux = 600;
		LCD_pos_xy(0, 1);
		LCD_write_string("     600 gr.    ");
		break;
	case '9':
		porcion_aux = 900;
		LCD_pos_xy(0, 1);
		LCD_write_string("     900 gr.    ");
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

}
