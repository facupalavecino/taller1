#include "mef.h"

estado e;

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
		case '#':
		case '1':
		case '2':
		case '3':
		case '4':
		case '7':
		case '5':
		case '8':
		case '6':
		case '9':
			break;
		case 'A':
			e=CONFIG_HORA;
			//MEF_actualizarCONFIG_HORA();
			break;
		case 'B':
			e=SET_PORCION;
			//MEF_actualizarSET_PORCION();
			break;
		case 'C':
			e=CONFIG_WIFI;
			//MEF_actualizarCONFIG_WIFI();
			break;
		case 'D':
			e=SET_DESCARGA;
			//MEF_actualizarSET_DESCARGA();
			break;
		case '0':
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
			break;
		}
		break;
	case SET_DESCARGA:
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

}

void MEF_actualizarCONFIG_WIFI(void) {

}

void MEF_actualizarCONFIG_HORA(void) {

}

void MEF_actualizarSET_DESCARGA(void) {

}

void MEF_actualizarSET_PORCION(void) {

}
