#ifndef SPHERE_H
#define SPHERE_H
#include "Punto.h"


class Sphere
{
    private:
        int resolution;
        float radius;
        Punto misPuntos[15][15], misPuntosP[15][15];
        Operador *op;
        float puntoOrigen[3], puntoPivote[3];

    public:
        Sphere(Operador*);
        virtual ~Sphere();
        void setOrigen(float, float, float);
        void draw();
        void update();
};

#endif // SPHERE_H
