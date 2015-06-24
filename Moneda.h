/* Moneda.h Laboratorio 2
 * Author: Jorge Sanchez Vargas A95819 */

#ifndef MONEDA_H_
#define MONEDA_H_

using namespace std;

class Moneda{

	private:
		int valor;
		int peso;
		Moneda* idUnico;
		double valorReal;
		bool estaEnElBotin;

	public:
		void asignarValor(int);
		void asignarPeso(int);
		void calcularValorReal();
		void meterAlBotin();

		int obtenerValor();
		int obtenerPeso();
		Moneda* obtenerID();
		double obtenerValorReal();
		bool estaEnBotin();

		Moneda();
		Moneda(int, int);
		~Moneda();

};

#endif /* MONEDA_H_ */
