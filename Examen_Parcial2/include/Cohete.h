#ifndef COHETE_H
#define COHETE_H
#include "Punto.h"
#include "Operador.h"


class Cohete
{
	private:
		Punto misPuntos[8], misPuntosP[8];
		Operador *op;
		float puntosPivote[3], puntosOrigen[3];
    public:
        Cohete(Operador*);
		~Cohete();
		void setOrigen(float x, float y, float z);
        void draw();
        void update();
};

#endif // CUBO_H
