/* Moneda.cpp Laboratorio 2
 * Author: Jorge Sanchez Vargas A95819 */

#include "Moneda.h"

Moneda::Moneda(){
	valor = 0;
	peso = 0;
	idUnico = this;
	valorReal = 0.0;
	estaEnElBotin = false;
}

Moneda::Moneda(int valorAAsignar, int pesoAAsignar){
	valor = valorAAsignar;
	peso = pesoAAsignar;
	idUnico = this;
	valorReal = (valor/peso);
	estaEnElBotin = false;
}

Moneda::~Moneda(){
}

void Moneda::asignarValor(int valorAAsignar){
	valor = valorAAsignar;
}

void Moneda::asignarPeso(int pesoAAsignar){
	peso = pesoAAsignar;
}


void Moneda::calcularValorReal(){
	valorReal = (double)valor/peso;
}

void Moneda::meterAlBotin(){
	estaEnElBotin = true;
}


int Moneda::obtenerValor(){
	return valor;
}

int Moneda::obtenerPeso(){
	return peso;
}

Moneda* Moneda::obtenerID(){
	return this;
}

double Moneda::obtenerValorReal(){
	return valorReal;
}

bool Moneda::estaEnBotin(){
	return estaEnElBotin;
}

