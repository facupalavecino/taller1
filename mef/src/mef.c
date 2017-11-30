#include "mef.h"
#include "types.h"

estado e;

void MEF_init(void){
	e = INICIAL;
}

void MEF_avanzarESTADO (uint8 t){
	switch (e){
	case INICIAL:
		//MEF_actualizarINICIAL();
		switch (t){
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
		case 'C':
			break;
		case 'D':
			break;
		case '0':
			break;
		}
	break;
	case CONFIG_WIFI:
		switch (t){
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

void MEF_actualizarINICIAL(void){

}

void MEF_actualizarCONFIG_WIFI(void){

}

void MEF_actualizarCONFIG_HORA(void){
	
}

void MEF_actualizarSET_DESCARGA(void){

}

void MEF_actualizarSET_POSICION(void){

}
