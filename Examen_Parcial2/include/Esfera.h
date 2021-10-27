#ifndef ESFERA_H
#define ESFERA_H
#include "Punto.h"
#include "Operador.h"


class Esfera
{
    private:
        Punto misPuntos[26], misPuntosP[26];
		Operador *op;
		float puntosPivote[3], puntosOrigen[3];
    public:
        Esfera(Operador*);
		~Esfera();
		void setOrigen(float x, float y, float z);
        void draw();
        void update();
};

#endif // ESFERA_H
