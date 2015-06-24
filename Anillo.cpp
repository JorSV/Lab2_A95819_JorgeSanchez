/* Anillo.cpp Laboratorio 2
 * Author: Jorge Sanchez Vargas A95819 */

#include "Anillo.h"

Anillo::Anillo(){
	valor = 0;
	peso = 0;
	idUnico = this;
	valorReal = 0.0;
	estaEnElBotin = false;
}

Anillo::Anillo(int valorAAsignar, int pesoAAsignar){
	valor = valorAAsignar;
	peso = pesoAAsignar;
	idUnico = this;
	valorReal = valor/peso;
	estaEnElBotin = false;
}

Anillo::~Anillo(){
}

void Anillo::asignarValor(int valorAAsignar){
	valor = valorAAsignar;
}

void Anillo::asignarPeso(int pesoAAsignar){
	peso = pesoAAsignar;
}

void Anillo::calcularValorReal(){
	valorReal = (double)valor/peso;
}

void Anillo::meterAlBotin(){
	estaEnElBotin = true;
}

int Anillo::obtenerValor(){
	return valor;
}

int Anillo::obtenerPeso(){
	return peso;
}

Anillo* Anillo::obtenerID(){
	return idUnico;
}

double Anillo::obtenerValorReal(){
	return valorReal;
}

bool Anillo::estaEnBotin(){
	return estaEnElBotin;
}
