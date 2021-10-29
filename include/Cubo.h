#ifndef CUBO_H
#define CUBO_H
#include "Punto.h"
#include "Operador.h"


class Cubo
{
	private:
		Punto misPuntos[8], misPuntosP[8];
		Operador *op;
		float puntosPivote[3], puntosOrigen[3];
    public:
        Cubo(Operador*);
		~Cubo();
		void setOrigen(float x, float y, float z);
        void draw();
        void update();
};

#endif // CUBO_H
