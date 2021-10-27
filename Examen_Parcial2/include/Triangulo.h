#ifndef TRIANGULO_H
#define TRIANGULO_H
#include "Punto.h"
#include "Operador.h"


class Triangulo
{
    private:
        Punto misPuntos[5], misPuntosP[5];
		Operador *op;
		float puntosPivote[3], puntosOrigen[3];
    public:
        Triangulo(Operador*);
		~Triangulo();
		void setOrigen(float x, float y, float z);
        void draw();
        void update();
};

#endif // TRIANGULO_H
