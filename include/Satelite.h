#ifndef SATELITE_H
#define SATELITE_H
#include "Punto.h"
#include "Operador.h"


class Satelite
{
    private:
        Punto misPuntos[9], misPuntosP[9];
		Operador *op;
		float puntosPivote[3], puntosOrigen[3];
    public:
        Satelite(Operador*);
		~Satelite();
		void setOrigen(float x, float y, float z);
        void draw();
        void update();
};

#endif // SATELITE_H
