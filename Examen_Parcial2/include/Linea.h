#ifndef LINEA_H
#define LINEA_H
#include "Punto.h"


class Linea
{
	private:
		Punto p1, p2;
	public:
		Linea();
		~Linea();
		void setValues(Punto, Punto);
        void draw();
};

#endif // LINEA_H
