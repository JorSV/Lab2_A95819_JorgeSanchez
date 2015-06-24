/* Corona.h Laboratorio 2
 * Author: Jorge Sanchez Vargas A95819 */

#ifndef CORONA_H_
#define CORONA_H_

using namespace std;

class Corona{

	private:
		int valor;
		int peso;
		Corona* idUnico;
		double valorReal;
		bool estaEnElBotin;

	public:
		void asignarValor(int);
		void asignarPeso(int);
		void calcularValorReal();
		void meterAlBotin();

		int obtenerValor();
		int obtenerPeso();
		Corona* obtenerID();
		double obtenerValorReal();
		bool estaEnBotin();

		Corona();
		Corona(int, int);
		virtual ~Corona();

};

#endif /* CORONA_H_ */
