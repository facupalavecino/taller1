#include "my_clock.h"
#include "lcd.h"

rtc_t rtc;
static char bufferRtc[16];
delay_t delay1s;
bool_t val = 0;
uint8_t i = 0;

char* itoa(int value, char* result, int base) {
	// check that the base if valid
	if (base < 2 || base > 36) {
		*result = '\0';
		return result;
	}

	char* ptr = result, *ptr1 = result, tmp_char;
	int tmp_value;

	do {
		tmp_value = value;
		value /= base;
		*ptr++ =
				"zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz"[35
						+ (tmp_value - value * base)];
	} while (value);

	// Apply negative sign
	if (tmp_value < 0)
		*ptr++ = '-';
	*ptr-- = '\0';
	while (ptr1 < ptr) {
		tmp_char = *ptr;
		*ptr-- = *ptr1;
		*ptr1++ = tmp_char;
	}
	return result;
}

void configTime() {

	LCD_pos_xy(0, 0);
	LCD_write_string("  Iniciando...  ");
	LCD_pos_xy(0, 1);
	LCD_write_string("##");

	rtc.year = 2016;
	rtc.month = 7;
	rtc.mday = 3;
	rtc.wday = 1;
	rtc.hour = 9;
	rtc.min = 59;
	rtc.sec = 30;

	/* Inicializar RTC */
	val = rtcConfig(&rtc);

	delayConfig(&delay1s, 1000);
	delay(2000); // El RTC tarda en setear la hora, por eso el delay
	LCD_write_string("####");
	for (i = 0; i < 10; i++) {
		/* Leer fecha y hora */
		val = rtcRead(&rtc);
		/* Mostrar fecha y hora en formato "DD/MM/YYYY, HH:MM:SS" */
		// showTime(1);
		LCD_pos_xy(i + 6, 1);
		LCD_write_string("#");
		delay(1000);
	}

	rtc.year = 2016;
	rtc.month = 7;
	rtc.mday = 3;
	rtc.wday = 1;
	rtc.hour = 9;
	rtc.min = 59;
	rtc.sec = 39;

	/* Establecer fecha y hora */
	val = rtcWrite(&rtc);
}

void showTime(char line) {
	if (line > 0) {
		line = 1;
	}
	LCD_pos_xy(0, line);
	LCD_write_string("    ");
	LCD_pos_xy(4, line);
	if (rtc.hour > 9) {
		LCD_write_string(itoa(rtc.hour, bufferRtc, 10));
	} else {
		LCD_write_char('0');
		LCD_pos_xy(5, line);
		LCD_write_string(itoa(rtc.hour, bufferRtc, 10));
	}
	LCD_pos_xy(6, line);
	LCD_write_char(':');
	LCD_pos_xy(7, line);
	if (rtc.min > 9) {
		LCD_write_string(itoa(rtc.min, bufferRtc, 10));
	} else {
		LCD_write_char('0');
		LCD_pos_xy(8, line);
		LCD_write_string(itoa(rtc.min, bufferRtc, 10));
	}
	LCD_pos_xy(9, line);
	LCD_write_char(':');
	LCD_pos_xy(10, line);
	if (rtc.sec > 9) {
		LCD_write_string(itoa(rtc.sec, bufferRtc, 10));
	} else {
		LCD_write_char('0');
		LCD_pos_xy(11, line);
		LCD_write_string(itoa(rtc.sec, bufferRtc, 10));
	}
	LCD_write_string("    ");
}

void updateTime() {
	if (delayRead(&delay1s)) {
		/* Leer fecha y hora */
		val = rtcRead(&rtc);
	}
}

void setTime(rtc_t rtc_aux) {
	val = rtcWrite(&rtc_aux);
	//delay(200);
}
