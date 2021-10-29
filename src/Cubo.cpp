#include "Cubo.h"
#include <stdio.h>
#include <GL/glut.h>
#include <stdlib.h>

Cubo::Cubo(Operador *opera)
{
    for(int i = 0; i < 8; i++)
        misPuntos[i].setOperador(opera);

    misPuntos[0].setValues(0,0,0); //Origen
    misPuntos[1].setValues(1,0,0); //Origen derecha
    misPuntos[2].setValues(0,1,0); //Origen arriba
    misPuntos[3].setValues(1,1,0); //Origen esquina
    misPuntos[4].setValues(0,0,1); //Z origen
    misPuntos[5].setValues(1,0,1); //Z derecha
    misPuntos[6].setValues(0,1,1); //Z arriba
    misPuntos[7].setValues(1,1,1); //Z esquina

    for (int i = 0; i < 8; i++)
        misPuntosP[i] = misPuntos[i];

    for (int i = 0; i < 3; i++)
    {
        puntosOrigen[i] = 0;
        puntosPivote[i] = 0;
    }
    op = opera;
}

Cubo::~Cubo()
{
    //dtor
}

void Cubo::setOrigen(float x, float y, float z)
{
    puntosOrigen[0] = x;
    puntosOrigen[1] = y;
    puntosOrigen[2] = z;

    for (int i = 0; i < 3; i++)
        puntosPivote[i] = puntosOrigen[i];
}

void Cubo::draw(){
    op->push();

    op->trsPuntos(puntosPivote[0], puntosPivote[1], puntosPivote[2]);
    for(int i=0; i<8; i++)
    {
        op->multPuntos(misPuntos[i].p, misPuntosP[i].p);
    }

    for (int i = 0; i < 8; i = i + 2)
    {
        glBegin(GL_LINES);
        glVertex3f(misPuntosP[i].p[0],misPuntosP[i].p[1],misPuntosP[i].p[2]);
        glVertex3f(misPuntosP[i+1].p[0],misPuntosP[i+1].p[1],misPuntosP[i+1].p[2]);
        glEnd();
    }

    for (int i = 0; i < 4; i++)
    {
        glBegin(GL_LINES);
        glVertex3f(misPuntosP[i].p[0],misPuntosP[i].p[1],misPuntosP[i].p[2]);
        glVertex3f(misPuntosP[i+4].p[0],misPuntosP[i+4].p[1],misPuntosP[i+4].p[2]);
        glEnd();
    }

    for (int i = 0; i < 2; i++)
    {
        glBegin(GL_LINES);
        glVertex3f(misPuntosP[i].p[0],misPuntosP[i].p[1],misPuntosP[i].p[2]);
        glVertex3f(misPuntosP[i+2].p[0],misPuntosP[i+2].p[1],misPuntosP[i+2].p[2]);
        glVertex3f(misPuntosP[i+4].p[0],misPuntosP[i+4].p[1],misPuntosP[i+4].p[2]);
        glVertex3f(misPuntosP[i+6].p[0],misPuntosP[i+6].p[1],misPuntosP[i+6].p[2]);
        glEnd();
    }



    op->pop();
}

void Cubo::update(){
    if(puntosPivote[0]>20 || puntosPivote[0]<-20 || puntosPivote[1]>20 || puntosPivote[1]<-20 || puntosPivote[2]>20 || puntosPivote[2]<-20){
        for(int i=0; i<3; i++)
            puntosPivote[i] = puntosOrigen[i];
    }
}

