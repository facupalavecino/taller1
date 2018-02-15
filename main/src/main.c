#include "teclado_matricial.h"
#include "lcd.h"
#include "mef.h"
#include "sapi.h"

int main(void){
	boardConfig();
	LCD_init (_2_LINES | DISPLAY_8X5, CURSOR_OFF | DISPLAY_ON);
	INIT_KEYBOARD();
	MEF_init();

	return 0;
}
