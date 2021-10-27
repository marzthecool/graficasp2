#include "Linea.h"

Linea::Linea()
{
    //ctor
}

Linea::~Linea()
{
    //dtor
}

void Linea::setValues(Punto pp1, Punto pp2)
{
	p1.setValues(pp1);
	p2.setValues(pp2);
}

void Linea::draw()
{
    glBegin(GL_LINES);
        glVertex3fv(p1.getValues());
        glVertex3fv(p2.getValues());
    glEnd();
}
