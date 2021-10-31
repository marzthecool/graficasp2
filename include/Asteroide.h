#ifndef ASTEROIDE_H
#define ASTEROIDE_H
#include "Punto.h"
#include "Operador.h"


class Asteroide
{
    private:
        Punto misPuntos[26], misPuntosP[26];
		Operador *op;
		float puntosPivote[3], puntosOrigen[3];
    public:
        Asteroide(Operador*);
		~Asteroide();
		void setOrigen(float x, float y, float z);
        void draw();
        void update();
};

#endif // ASTEROIDE_H
