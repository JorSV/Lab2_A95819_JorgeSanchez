/* Collar.cpp Laboratorio 2
 * Author: Jorge Sanchez Vargas A95819 */

#include "Collar.h"

Collar::Collar(){
	valor = 0;
	peso = 0;
	idUnico = this;
	valorReal = 0.0;
	estaEnElBotin = false;
}

Collar::Collar(int valorAAsignar, int pesoAAsignar){
	valor = valorAAsignar;
	peso = pesoAAsignar;
	idUnico = this;
	valorReal = (valor/peso);
	estaEnElBotin = false;
}

Collar::~Collar(){
}

void Collar::asignarValor(int valorAAsignar){
	valor = valorAAsignar;
}

void Collar::asignarPeso(int pesoAAsignar){
	peso = pesoAAsignar;
}

void Collar::calcularValorReal(){
	valorReal = (double)valor/peso;
}

void Collar::meterAlBotin(){
	estaEnElBotin = true;
}

int Collar::obtenerValor(){
	return valor;
}

int Collar::obtenerPeso(){
	return peso;
}

Collar* Collar::obtenerID(){
	return idUnico;
}

double Collar::obtenerValorReal(){
	return valorReal;
}

bool Collar::estaEnBotin(){
	return estaEnElBotin;
}
