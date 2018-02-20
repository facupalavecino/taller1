/*
 * setDescarga.c
 *
 *  Created on: Feb 20, 2018
 *      Author: Luciano
 */
//SET DESCARGAS
rtc_t alarma[4];

rtc_t rtcaux[4];

unsigned char cantAlarmas = 0;

unsigned char modoEstado = 0;

int digitomayorhora[4];
int digitomenorhora[4];
int digitomayormin[4];
int digitomenormin[4];
int i, j, k = 0;

unsigned char numdigito = 0;

void actualiza_SET_DESCARGAS(uint8 tecla) { //  recibe la tecla ingresada

	switch (modoEstado) {

	case '0':
		//mostrar en lcd mensaje "INGRESE LA CANTIDAD DE DESCARGAS POR DIA QUE DESEA"
		modoEstado = 1;
		break;
	case '1':
		switch (tecla) {
		case '1':
			cantAlarmas = 1;
			modoEstado = 2;
			//mostrar en lcd "cantAlarmas DESCARGAS POR DIA"
			break;
		case '2':
			cantAlarmas = 2;
			modoEstado = 2;
			//mostrar en lcd "cantAlarmas DESCARGAS POR DIA"
			break;
		case '3':
			cantAlarmas = 3;
			modoEstado = 2;
			//mostrar en lcd "cantAlarmas DESCARGAS POR DIA"
			break;
		case '4':
			cantAlarmas = 4;
			modoEstado = 2;
			//mostrar en lcd "cantAlarmas DESCARGAS POR DIA"
			break;
		default:
			//mostrar mensaje "tecla invalida, ingrese un numero entre 1 y 4"
		}
		// DELAY
		//mostrar mensaje ingrese la hora de la primer alarma
		break;

	case '2':
		while (i < cantAlarmas) {
			setAlarma(tecla); // ACA LE TENGO QUE PASAR LA TECLA Y EL AUXILIAR RTC CORRESPOONDIENTE A i
		}

		i = 0;
		for (j = 0; j < cantAlarmas; j++) {
			rtcaux[j].hour = concat(digitomayorhora[j], digitomenorhora[j]);
			rtcaux[j].min = concat(digitomayormin[j], digitomenormin[j]);
		}
		break;

	case '3':
		LCD_pos_xy(4, 1);
		LCD_write_string("INGRESE '#' PARA CANCELAR O '*' PARA CONFIRMAR");
		if (tecla == '#') {
			for (k = 0; k < cantAlarmas; k++) // ASIGNO LOS AUX A LA ALARMA
				alarma[k].hour = rtcaux[k].hour;
			alarma[k].min = rtcaux[k].min;

		}

		else {
			if (tecla == '*') {
				modoEstado = 0;

				// vuelvo a estado inicial
			}
			else{
				//nada?
			}
		}
		break;

	default:
		modoEstado=0;
	}

}

void setAlarma(char tecla) {
	switch (numdigito) { // numdigito indica que digito de la hora estoy recibiendo 0 = mayor digito de hora  3 = menor digito del minuto
	case 0:
		switch (tecla) {
		case '0':
			digitomayorhora[i] = '0';
			LCD_write_char('0')		//mostrar en LCD el 0

			break;
		case '1':
			digitomayorhora[i] = '1';
			//mostrar en LCD el 1
			break;
		case '2':
			digitomayorhora[i] = '2';
			//mostrar en LCD el 2
			break;
		case '*':

			break;
		case '#':

			break;
		default:
			// nada
		}

		if (tecla == '0' || tecla == '1' || tecla == '2') { // si el digito mayor de la hora es valido, paso al digito menor
			numdigito = 1;
		}
		break;
	case 1:
		switch (tecla) {
		case '0':
			digitomenorhora[i] = '0';
			//mostrar en LCD el 0

			break;
		case '1':
			digitomenorhora[i] = '1';
			//mostrar en LCD el 1
			break;
		case '2':
			digitomenorhora[i] = '2';
			//mostrar en LCD el 2
			break;
		case '3':
			digitomenorhora[i] = '3';
			//mostrar en LCD el 3
			break;
		case '4':
			if (digitomayorhora < 2) {
				digitomenorhora[i] = '4';
				//mostrar en LCD el 4
			}
			break;
		case '5':
			if (digitomayorhora < 2) {
				digitomenorhora[i] = '5';
				//mostrar en LCD el 5
			}
			break;
		case '6':
			if (digitomayorhora < 2) {
				digitomenorhora[i] = '6';
				//mostrar en LCD el 6
			}
			break;
		case '7':
			if (digitomayorhora < 2) {
				digitomenorhora[i] = '7';
				//mostrar en LCD el 7
			}
			break;
		case '8':
			if (digitomayorhora < 2) {
				digitomenorhora[i] = '8';
				//mostrar en LCD el 8
			}
			break;
		case '9':
			if (digitomayorhora < 2) {
				digitomenorhora[i] = '9';
				//mostrar en LCD el 9
			}
			break;
		case '*':

			break;
		case '#':

			break;
		default: //nada
		}
		if (tecla == '0' || tecla == '1' || tecla == '2' || tecla == '3'
				|| (digitomayorhora < 2
						&& (tecla == '4' || tecla == '5' || tecla == '6'
								|| tecla == '7' || tecla == '8' || tecla == '9'))) { // si el digito mayor de la hora es valido, paso al digito menor
			numdigito = 2;
		}
		break;
	case 2:
		switch (tecla) {
		case '0':
			digitomayormin[i] = '0';
			//mostrar en LCD el 0

			break;
		case '1':
			digitomayormin[i] = '1';
			//mostrar en LCD el 1
			break;
		case '2':
			digitomayormin[i] = '2';
			//mostrar en LCD el 2
			break;
		case '3':
			digitomayormin[i] = '3';
			//mostrar en LCD el 3
			break;
		case '4':
			digitomayormin[i] = '4';
			//mostrar en LCD el 4

			break;
		case '5':
			digitomayormin[i] = '5';
			//mostrar en LCD el 5

			break;
		case '*':

			break;
		case '#':

			break;
		default: //nada
			if (tecla == '0' || tecla == '1' || tecla == '2' || tecla == '3'
					|| tecla == '4' || tecla == '5') {
				numdigito = 3;
			}
		}
		break;
	case 3:
		switch (tecla) {
		case '0':
			digitomenormin[i] = '0';
			//mostrar en LCD el 0

			break;
		case '1':
			digitomenormin[i] = '1';
			//mostrar en LCD el 1
			break;
		case '2':
			digitomenormin[i] = '2';
			//mostrar en LCD el 2
			break;
		case '3':
			digitomenormin[i] = '3';
			//mostrar en LCD el 3
			break;
		case '4':
			digitomenormin[i] = '4';
			//mostrar en LCD el 4

			break;
		case '5':
			digitomenormin[i] = '5';
			//mostrar en LCD el 5

			break;
		case '6':
			digitomenormin[i] = '6';
			//mostrar en LCD el 6

			break;
		case '7':
			digitomenormin[i] = '7';
			//mostrar en LCD el 7

			break;
		case '8':
			digitomenormin[i] = '8';
			//mostrar en LCD el 8

			break;
		case '9':
			digitomenormin[i] = '9';
			//mostrar en LCD el 9

			break;
		case '*':

			break;
		case '#':

			break;
		default: //nada
			if (tecla == '0' || tecla == '1' || tecla == '2' || tecla == '3'
					|| tecla == '4' || tecla == '5' || tecla == '6'
					|| tecla == '7' || tecla == '8' || tecla == '9') {
				numdigito = 0;
				i++;
			}
		}

		break;
	default:
	}
}

int concat(int x, int y) { // CONCATENA DOS ENTEROS
	int z;
	z = x * pow(10, log10(y) + 1) + y;
	return z;
}

