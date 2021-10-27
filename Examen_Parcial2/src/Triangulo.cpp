#include "Triangulo.h"
#include <stdio.h>
#include <GL/glut.h>
#include <stdlib.h>

Triangulo::Triangulo(Operador *opera)
{
    for(int i = 0; i < 8; i++)
        misPuntos[i].setOperador(opera);

    misPuntos[0].setValues(0,0,0); //Origen
    misPuntos[1].setValues(1,0,0); //Punto X
    misPuntos[2].setValues(0,0,1); //Punto Z
    misPuntos[3].setValues(1,0,1); //Punto esquina
    misPuntos[4].setValues(0.5,1,0.5); //Pico

    for (int i = 0; i < 5; i++)
        misPuntosP[i] = misPuntos[i];

    for (int i = 0; i < 3; i++)
    {
        puntosOrigen[i] = 0;
        puntosPivote[i] = 0;
    }
    op = opera;
}

Triangulo::~Triangulo()
{
    //dtor
}

void Triangulo::setOrigen(float x, float y, float z)
{
    puntosOrigen[0] = x;
    puntosOrigen[1] = y;
    puntosOrigen[2] = z;

    for (int i = 0; i < 3; i++)
        puntosPivote[i] = puntosOrigen[i];
}

void Triangulo::draw(){
    op->push();

    op->trsPuntos(puntosPivote[0], puntosPivote[1], puntosPivote[2]);
    for(int i=0; i<5; i++)
    {
        op->multPuntos(misPuntos[i].p, misPuntosP[i].p);
    }

    glBegin(GL_LINES);
    glVertex3f(misPuntosP[0].p[0],misPuntosP[0].p[1],misPuntosP[0].p[2]);
    glVertex3f(misPuntosP[1].p[0],misPuntosP[1].p[1],misPuntosP[1].p[2]);
    glVertex3f(misPuntosP[0].p[0],misPuntosP[0].p[1],misPuntosP[0].p[2]);
    glVertex3f(misPuntosP[2].p[0],misPuntosP[2].p[1],misPuntosP[2].p[2]);
    glVertex3f(misPuntosP[3].p[0],misPuntosP[3].p[1],misPuntosP[3].p[2]);
    glVertex3f(misPuntosP[1].p[0],misPuntosP[1].p[1],misPuntosP[1].p[2]);
    glVertex3f(misPuntosP[3].p[0],misPuntosP[3].p[1],misPuntosP[3].p[2]);
    glVertex3f(misPuntosP[2].p[0],misPuntosP[2].p[1],misPuntosP[2].p[2]);
    glEnd();

    for (int i = 0; i < 4; i++)
    {
        glBegin(GL_LINES);
        glVertex3f(misPuntosP[i].p[0],misPuntosP[i].p[1],misPuntosP[i].p[2]);
        glVertex3f(misPuntosP[4].p[0],misPuntosP[4].p[1],misPuntosP[4].p[2]);
        glEnd();
    }



    op->pop();
}

void Triangulo::update(){
    if(puntosPivote[0]>20 || puntosPivote[0]<-20 || puntosPivote[1]>20 || puntosPivote[1]<-20 || puntosPivote[2]>20 || puntosPivote[2]<-20){
        for(int i=0; i<3; i++)
            puntosPivote[i] = puntosOrigen[i];
    }
}
