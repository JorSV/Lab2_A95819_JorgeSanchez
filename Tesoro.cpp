/* Tesoro.cpp Laboratorio 2
 * Author: Jorge Sanchez Vargas A95819 */

#include "Tesoro.h"

Tesoro::Tesoro(){
	totalObjetosEnTesoro = 0;
	srand (time(0));
}

Tesoro::~Tesoro(){
}

int Tesoro::generarRandom(int piso, int techo){
	return  rand() % techo + piso;
}
