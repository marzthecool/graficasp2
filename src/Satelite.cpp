#include "Satelite.h"
#include <stdio.h>
#include <GL/glut.h>
#include <stdlib.h>

Satelite::Satelite(Operador *opera)
{
    for(int i = 0; i < 9; i++)
        misPuntos[i].setOperador(opera);

    misPuntos[0].setValues(0,0,0); //Origen picos
    //Piramide izq
    misPuntos[1].setValues(-1,0.5,-0.5);
    misPuntos[2].setValues(-1,0.5,0.5);
    misPuntos[3].setValues(-1,-0.5,-0.5);
    misPuntos[4].setValues(-1,-0.5,0.5);
    //Piramide der
    misPuntos[5].setValues(1,0.5,-0.5);
    misPuntos[6].setValues(1,0.5,0.5);
    misPuntos[7].setValues(1,-0.5,-0.5);
    misPuntos[8].setValues(1,-0.5,0.5);

    for (int i = 0; i < 9; i++)
        misPuntosP[i] = misPuntos[i];

    for (int i = 0; i < 3; i++)
    {
        puntosOrigen[i] = 0;
        puntosPivote[i] = 0;
    }
    op = opera;
}

Satelite::~Satelite()
{
    //dtor
}

void Satelite::setOrigen(float x, float y, float z)
{
    puntosOrigen[0] = x;
    puntosOrigen[1] = y;
    puntosOrigen[2] = z;

    for (int i = 0; i < 3; i++)
        puntosPivote[i] = puntosOrigen[i];
}

void Satelite::draw(){
    op->push();

    op->trsPuntos(puntosPivote[0], puntosPivote[1], puntosPivote[2]);
    for(int i=0; i<9; i++)
    {
        op->multPuntos(misPuntos[i].p, misPuntosP[i].p);
    }

    //inicia dibujado piramide izq
    for (int i = 0; i < 5; i++)
    {
        glBegin(GL_LINES);
        glVertex3f(misPuntosP[i].p[0],misPuntosP[i].p[1],misPuntosP[i].p[2]);
        glVertex3f(misPuntosP[0].p[0],misPuntosP[0].p[1],misPuntosP[0].p[2]);
        glEnd();
    }

    glBegin(GL_LINES);
    glVertex3f(misPuntosP[1].p[0],misPuntosP[1].p[1],misPuntosP[1].p[2]);
    glVertex3f(misPuntosP[2].p[0],misPuntosP[2].p[1],misPuntosP[2].p[2]);
    glVertex3f(misPuntosP[4].p[0],misPuntosP[4].p[1],misPuntosP[4].p[2]);
    glVertex3f(misPuntosP[2].p[0],misPuntosP[2].p[1],misPuntosP[2].p[2]);
    glVertex3f(misPuntosP[3].p[0],misPuntosP[3].p[1],misPuntosP[3].p[2]);
    glVertex3f(misPuntosP[1].p[0],misPuntosP[1].p[1],misPuntosP[1].p[2]);
    glVertex3f(misPuntosP[3].p[0],misPuntosP[3].p[1],misPuntosP[3].p[2]);
    glVertex3f(misPuntosP[4].p[0],misPuntosP[4].p[1],misPuntosP[4].p[2]);
    glEnd();
    //termina dibujado piramide izq

    //inicia dibujado piramide der
    for (int i = 5; i < 9; i++)
    {
        glBegin(GL_LINES);
        glVertex3f(misPuntosP[i].p[0],misPuntosP[i].p[1],misPuntosP[i].p[2]);
        glVertex3f(misPuntosP[0].p[0],misPuntosP[0].p[1],misPuntosP[0].p[2]);
        glEnd();
    }

    glBegin(GL_LINES);
    glVertex3f(misPuntosP[5].p[0],misPuntosP[5].p[1],misPuntosP[5].p[2]);
    glVertex3f(misPuntosP[6].p[0],misPuntosP[6].p[1],misPuntosP[6].p[2]);
    glVertex3f(misPuntosP[8].p[0],misPuntosP[8].p[1],misPuntosP[8].p[2]);
    glVertex3f(misPuntosP[6].p[0],misPuntosP[6].p[1],misPuntosP[6].p[2]);
    glVertex3f(misPuntosP[7].p[0],misPuntosP[7].p[1],misPuntosP[7].p[2]);
    glVertex3f(misPuntosP[5].p[0],misPuntosP[5].p[1],misPuntosP[5].p[2]);
    glVertex3f(misPuntosP[7].p[0],misPuntosP[7].p[1],misPuntosP[7].p[2]);
    glVertex3f(misPuntosP[8].p[0],misPuntosP[8].p[1],misPuntosP[8].p[2]);
    glEnd();
    //termina dibujado piramide der

    op->pop();
}

void Satelite::update(){
    if(puntosPivote[0]>20 || puntosPivote[0]<-20 || puntosPivote[1]>20 || puntosPivote[1]<-20 || puntosPivote[2]>20 || puntosPivote[2]<-20){
        for(int i=0; i<3; i++)
            puntosPivote[i] = puntosOrigen[i];
    }
}
