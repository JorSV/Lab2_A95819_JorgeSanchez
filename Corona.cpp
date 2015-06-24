/* Corona.cpp Laboratorio 2
 * Author: Jorge Sanchez Vargas A95819 */

#include "Corona.h"

Corona::Corona(){
	valor = 0;
	peso = 0;
	idUnico = this;
	valorReal = 0.0;
	estaEnElBotin = false;
}

Corona::Corona(int valorAAsignar, int pesoAAsignar){
	valor = valorAAsignar;
	peso = pesoAAsignar;
	idUnico = this;
	valorReal = valor/peso;
	estaEnElBotin = false;
}

Corona::~Corona(){
}

void Corona::asignarValor(int valorAAsignar){
	valor = valorAAsignar;
}

void Corona::asignarPeso(int pesoAAsignar){
	peso = pesoAAsignar;
}

void Corona::calcularValorReal(){
	valorReal = (double)valor/peso;
}

void Corona::meterAlBotin(){
	estaEnElBotin = true;
}

int Corona::obtenerValor(){
	return valor;
}

int Corona::obtenerPeso(){
	return peso;
}

Corona* Corona::obtenerID(){
	return idUnico;
}

double Corona::obtenerValorReal(){
	return valorReal;
}

bool Corona::estaEnBotin(){
	return estaEnElBotin;
}
