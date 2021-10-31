#include "Asteroide.h"
#include <stdio.h>
#include <GL/glut.h>
#include <stdlib.h>

Asteroide::Asteroide(Operador *opera)
{
    for(int i = 0; i < 26; i++)
        misPuntos[i].setOperador(opera);

    misPuntos[0].setValues(0,0,0); //Base
    int lvly = 1;
    int lvl = 1;
    for(int i = 1; i < 25; i = i + 8)
    {
        misPuntos[i].setValues((0.25 * lvl), (0.25 * lvly), 0);
        misPuntos[i+1].setValues((0.25 * lvl), (0.25 * lvly), (0.25 * lvl));
        misPuntos[i+2].setValues(0, (0.25 * lvly), (0.25 * lvl));
        misPuntos[i+3].setValues((0.25 * lvl), (0.25 * lvly), (-0.25 * lvl));
        misPuntos[i+7].setValues((-0.25 * lvl), (0.25 * lvly), (0.25 * lvl));
        misPuntos[i+6].setValues(0, (0.25 * lvly), (-0.25 * lvl));
        misPuntos[i+5].setValues((-0.25 * lvl), (0.25 * lvly), (-0.25 * lvl));
        misPuntos[i+4].setValues((-0.25 * lvl), (0.25 * lvly), 0);
        lvl += 1;
        lvly += 1;
        if (lvl > 2)
            lvl = 1;
    }
    misPuntos[25].setValues(0,1,0); //Cabeza

    for (int i = 0; i < 5; i++)
        misPuntosP[i] = misPuntos[i];

    for (int i = 0; i < 3; i++)
    {
        puntosOrigen[i] = 0;
        puntosPivote[i] = 0;
    }
    op = opera;
}

Asteroide::~Asteroide()
{
    //dtor
}

void Asteroide::setOrigen(float x, float y, float z)
{
    puntosOrigen[0] = x;
    puntosOrigen[1] = y;
    puntosOrigen[2] = z;

    for (int i = 0; i < 3; i++)
        puntosPivote[i] = puntosOrigen[i];
}

void Asteroide::draw(){
    op->push();

    op->trsPuntos(puntosPivote[0], puntosPivote[1], puntosPivote[2]);
    for(int i=0; i<26; i++)
    {
        op->multPuntos(misPuntos[i].p, misPuntosP[i].p);
    }

    for (int i = 1; i < 9; i++)
    {
        glBegin(GL_LINES);
        glVertex3f(misPuntosP[0].p[0],misPuntosP[0].p[1],misPuntosP[0].p[2]);
        glVertex3f(misPuntosP[i].p[0],misPuntosP[i].p[1],misPuntosP[i].p[2]);
        glEnd();
    }

    for (int i = 1; i < 8; i++)
    {
        glBegin(GL_LINES);
        glVertex3f(misPuntosP[i].p[0],misPuntosP[i].p[1],misPuntosP[i].p[2]);
        glVertex3f(misPuntosP[i+1].p[0],misPuntosP[i+1].p[1],misPuntosP[i+1].p[2]);
        glEnd();
    }

    glBegin(GL_LINES);
        glVertex3f(misPuntosP[8].p[0],misPuntosP[8].p[1],misPuntosP[8].p[2]);
        glVertex3f(misPuntosP[1].p[0],misPuntosP[1].p[1],misPuntosP[1].p[2]);
        glEnd();

    for (int i = 1; i < 9; i++)
    {
        glBegin(GL_LINES);
        glVertex3f(misPuntosP[i].p[0],misPuntosP[i].p[1],misPuntosP[i].p[2]);
        glVertex3f(misPuntosP[i+8].p[0],misPuntosP[i+8].p[1],misPuntosP[i+8].p[2]);
        glEnd();
    }

    for (int i = 9; i < 16; i++)
    {
        glBegin(GL_LINES);
        glVertex3f(misPuntosP[i].p[0],misPuntosP[i].p[1],misPuntosP[i].p[2]);
        glVertex3f(misPuntosP[i+1].p[0],misPuntosP[i+1].p[1],misPuntosP[i+1].p[2]);
        glEnd();
    }

    glBegin(GL_LINES);
        glVertex3f(misPuntosP[9].p[0],misPuntosP[9].p[1],misPuntosP[9].p[2]);
        glVertex3f(misPuntosP[16].p[0],misPuntosP[16].p[1],misPuntosP[16].p[2]);
        glEnd();

    for (int i = 9; i < 17; i++)
    {
        glBegin(GL_LINES);
        glVertex3f(misPuntosP[i].p[0],misPuntosP[i].p[1],misPuntosP[i].p[2]);
        glVertex3f(misPuntosP[i+8].p[0],misPuntosP[i+8].p[1],misPuntosP[i+8].p[2]);
        glEnd();
    }

    for (int i = 17; i < 24; i++)
    {
        glBegin(GL_LINES);
        glVertex3f(misPuntosP[i].p[0],misPuntosP[i].p[1],misPuntosP[i].p[2]);
        glVertex3f(misPuntosP[i+1].p[0],misPuntosP[i+1].p[1],misPuntosP[i+1].p[2]);
        glEnd();
    }

    glBegin(GL_LINES);
        glVertex3f(misPuntosP[24].p[0],misPuntosP[24].p[1],misPuntosP[24].p[2]);
        glVertex3f(misPuntosP[17].p[0],misPuntosP[17].p[1],misPuntosP[17].p[2]);
        glEnd();

    for (int i = 17; i < 25; i++)
    {
        glBegin(GL_LINES);
        glVertex3f(misPuntosP[i].p[0],misPuntosP[i].p[1],misPuntosP[i].p[2]);
        glVertex3f(misPuntosP[25].p[0],misPuntosP[25].p[1],misPuntosP[25].p[2]);
        glEnd();
    }

    op->pop();
}

void Asteroide::update(){
    if(puntosPivote[0]>20 || puntosPivote[0]<-20 || puntosPivote[1]>20 || puntosPivote[1]<-20 || puntosPivote[2]>20 || puntosPivote[2]<-20){
        for(int i=0; i<3; i++)
            puntosPivote[i] = puntosOrigen[i];
    }
}
