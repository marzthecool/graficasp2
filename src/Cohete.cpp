#include "Cohete.h"
#include <stdio.h>
#include <GL/glut.h>
#include <stdlib.h>

Cohete::Cohete(Operador *opera)
{
    for(int i = 0; i < 31; i++)
        misPuntos[i].setOperador(opera);

    //cubo abajo
    misPuntos[0].setValues(0,0,0); //origen
    misPuntos[1].setValues(1,0,0);
    misPuntos[2].setValues(0,1,0);
    misPuntos[3].setValues(1,1,0);
    misPuntos[4].setValues(0,0,1);
    misPuntos[5].setValues(1,0,1);
    misPuntos[6].setValues(0,1,1);
    misPuntos[7].setValues(1,1,1);
    //cubo arriba
    misPuntos[8].setValues(0,2,0);
    misPuntos[9].setValues(1,2,0);
    misPuntos[10].setValues(0,2,1);
    misPuntos[11].setValues(1,2,1);
    //piramide arriba
    misPuntos[12].setValues(0.5,3,0.5); //pico
    //piramide lateral1
    misPuntos[13].setValues(-1,0.5,0.5); //pico
    //piramide lateral2
    misPuntos[14].setValues(2,0.5,0.5); //pico
    //propulsores
    misPuntos[15].setValues(-0.25,-0.4,-0.25); //propulsor 1
    misPuntos[16].setValues(0.25,-0.4,-0.25);
    misPuntos[17].setValues(-0.25,-0.4,0.25);
    misPuntos[18].setValues(0.25,-0.4,0.25);
    misPuntos[19].setValues(0.75,-0.4,-0.25); //propulsor 2
    misPuntos[20].setValues(1.25,-0.4,-0.25);
    misPuntos[21].setValues(0.75,-0.4,0.25);
    misPuntos[22].setValues(1.25,-0.4,0.25);
    misPuntos[23].setValues(-0.25,-0.4,0.75); //propulsor 3
    misPuntos[24].setValues(0.25,-0.4,0.75);
    misPuntos[25].setValues(-0.25,-0.4,1.25);
    misPuntos[26].setValues(0.25,-0.4,1.25);
    misPuntos[27].setValues(0.75,-0.4,0.75); //propulsor 4
    misPuntos[28].setValues(1.25,-0.4,0.75);
    misPuntos[29].setValues(0.75,-0.4,1.25);
    misPuntos[30].setValues(1.25,-0.4,1.25);

    for (int i = 0; i < 31; i++)
        misPuntosP[i] = misPuntos[i];

    for (int i = 0; i < 3; i++)
    {
        puntosOrigen[i] = 0;
        puntosPivote[i] = 0;
    }
    op = opera;
}

Cohete::~Cohete()
{
    //dtor
}

void Cohete::setOrigen(float x, float y, float z)
{
    puntosOrigen[0] = x;
    puntosOrigen[1] = y;
    puntosOrigen[2] = z;

    for (int i = 0; i < 3; i++)
        puntosPivote[i] = puntosOrigen[i];
}

void Cohete::draw(){
    op->push();
    op->trsPuntos(puntosPivote[0], puntosPivote[1], puntosPivote[2]);

    for(int i=0; i<31; i++)
    {
        op->multPuntos(misPuntos[i].p, misPuntosP[i].p);
    }

    // inicia dibujado cubo abajo
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
    // termina dibujado cubo abajo

    // inicia dibujado cubo arriba
    for (int i = 8; i < 11; i = i + 2)
    {
        glBegin(GL_LINES);
        glVertex3f(misPuntosP[i].p[0],misPuntosP[i].p[1],misPuntosP[i].p[2]);
        glVertex3f(misPuntosP[i+1].p[0],misPuntosP[i+1].p[1],misPuntosP[i+1].p[2]);
        glEnd();
    }

    for (int i = 8; i < 10; i++)
    {
        glBegin(GL_LINES);
        glVertex3f(misPuntosP[i].p[0],misPuntosP[i].p[1],misPuntosP[i].p[2]);
        glVertex3f(misPuntosP[i+2].p[0],misPuntosP[i+2].p[1],misPuntosP[i+2].p[2]);
        glEnd();
    }

    for (int i = 2; i < 4; i++)
    {
        glBegin(GL_LINES);
        glVertex3f(misPuntosP[i].p[0],misPuntosP[i].p[1],misPuntosP[i].p[2]);
        glVertex3f(misPuntosP[i+6].p[0],misPuntosP[i+6].p[1],misPuntosP[i+6].p[2]);
        glVertex3f(misPuntosP[i+4].p[0],misPuntosP[i+4].p[1],misPuntosP[i+4].p[2]);
        glVertex3f(misPuntosP[i+8].p[0],misPuntosP[i+8].p[1],misPuntosP[i+8].p[2]);
        glEnd();
    }
    // termina dibujado cubo abajo

    // inicia dibujado pico arriba
    for (int i = 8; i < 12; i++)
    {
        glBegin(GL_LINES);
        glVertex3f(misPuntosP[i].p[0],misPuntosP[i].p[1],misPuntosP[i].p[2]);
        glVertex3f(misPuntosP[12].p[0],misPuntosP[12].p[1],misPuntosP[12].p[2]);
        glEnd();
    }
    // termina dibujado pico arriba

    // inicia dibujado pico lateral1
    for (int i = 0; i < 7; i = i + 2)
    {
        glBegin(GL_LINES);
        glVertex3f(misPuntosP[i].p[0],misPuntosP[i].p[1],misPuntosP[i].p[2]);
        glVertex3f(misPuntosP[13].p[0],misPuntosP[13].p[1],misPuntosP[13].p[2]);
        glEnd();
    }
    // termina dibujado pico lateral1

    // inicia dibujado pico lateral2
    for (int i = 1; i < 8; i = i + 2)
    {
        glBegin(GL_LINES);
        glVertex3f(misPuntosP[i].p[0],misPuntosP[i].p[1],misPuntosP[i].p[2]);
        glVertex3f(misPuntosP[14].p[0],misPuntosP[13].p[1],misPuntosP[13].p[2]);
        glEnd();
    }
    // termina dibujado pico lateral2

    // inicia dibujado propulsor1
    for (int i = 15; i < 19; i++)
    {
        glBegin(GL_LINES);
        glVertex3f(misPuntosP[i].p[0],misPuntosP[i].p[1],misPuntosP[i].p[2]);
        glVertex3f(misPuntosP[0].p[0],misPuntosP[0].p[1],misPuntosP[0].p[2]);
        glEnd();
    }

        glBegin(GL_LINES);
        glVertex3f(misPuntosP[15].p[0],misPuntosP[15].p[1],misPuntosP[15].p[2]);
        glVertex3f(misPuntosP[16].p[0],misPuntosP[16].p[1],misPuntosP[16].p[2]);
        glVertex3f(misPuntosP[17].p[0],misPuntosP[17].p[1],misPuntosP[17].p[2]);
        glVertex3f(misPuntosP[18].p[0],misPuntosP[18].p[1],misPuntosP[18].p[2]);
        glVertex3f(misPuntosP[15].p[0],misPuntosP[15].p[1],misPuntosP[15].p[2]);
        glVertex3f(misPuntosP[17].p[0],misPuntosP[17].p[1],misPuntosP[17].p[2]);
        glVertex3f(misPuntosP[16].p[0],misPuntosP[16].p[1],misPuntosP[16].p[2]);
        glVertex3f(misPuntosP[18].p[0],misPuntosP[18].p[1],misPuntosP[18].p[2]);
        glEnd();
    // termina dibujado propulsor1

    // inicia dibujado propulsor2
    for (int i = 19; i < 23; i++)
    {
        glBegin(GL_LINES);
        glVertex3f(misPuntosP[i].p[0],misPuntosP[i].p[1],misPuntosP[i].p[2]);
        glVertex3f(misPuntosP[1].p[0],misPuntosP[1].p[1],misPuntosP[1].p[2]);
        glEnd();
    }

        glBegin(GL_LINES);
        glVertex3f(misPuntosP[19].p[0],misPuntosP[19].p[1],misPuntosP[19].p[2]);
        glVertex3f(misPuntosP[20].p[0],misPuntosP[20].p[1],misPuntosP[20].p[2]);
        glVertex3f(misPuntosP[21].p[0],misPuntosP[21].p[1],misPuntosP[21].p[2]);
        glVertex3f(misPuntosP[22].p[0],misPuntosP[22].p[1],misPuntosP[22].p[2]);
        glVertex3f(misPuntosP[19].p[0],misPuntosP[19].p[1],misPuntosP[19].p[2]);
        glVertex3f(misPuntosP[21].p[0],misPuntosP[21].p[1],misPuntosP[21].p[2]);
        glVertex3f(misPuntosP[20].p[0],misPuntosP[20].p[1],misPuntosP[20].p[2]);
        glVertex3f(misPuntosP[22].p[0],misPuntosP[22].p[1],misPuntosP[22].p[2]);
        glEnd();
    // termina dibujado propulsor2

    // inicia dibujado propulsor3
    for (int i = 23; i < 27; i++)
    {
        glBegin(GL_LINES);
        glVertex3f(misPuntosP[i].p[0],misPuntosP[i].p[1],misPuntosP[i].p[2]);
        glVertex3f(misPuntosP[4].p[0],misPuntosP[4].p[1],misPuntosP[4].p[2]);
        glEnd();
    }

        glBegin(GL_LINES);
        glVertex3f(misPuntosP[23].p[0],misPuntosP[23].p[1],misPuntosP[23].p[2]);
        glVertex3f(misPuntosP[24].p[0],misPuntosP[24].p[1],misPuntosP[24].p[2]);
        glVertex3f(misPuntosP[25].p[0],misPuntosP[25].p[1],misPuntosP[25].p[2]);
        glVertex3f(misPuntosP[26].p[0],misPuntosP[26].p[1],misPuntosP[26].p[2]);
        glVertex3f(misPuntosP[23].p[0],misPuntosP[23].p[1],misPuntosP[23].p[2]);
        glVertex3f(misPuntosP[25].p[0],misPuntosP[25].p[1],misPuntosP[25].p[2]);
        glVertex3f(misPuntosP[24].p[0],misPuntosP[24].p[1],misPuntosP[24].p[2]);
        glVertex3f(misPuntosP[26].p[0],misPuntosP[26].p[1],misPuntosP[26].p[2]);
        glEnd();
    // termina dibujado propulsor3

    // inicia dibujado propulsor4
    for (int i = 27; i < 31; i++)
    {
        glBegin(GL_LINES);
        glVertex3f(misPuntosP[i].p[0],misPuntosP[i].p[1],misPuntosP[i].p[2]);
        glVertex3f(misPuntosP[5].p[0],misPuntosP[5].p[1],misPuntosP[5].p[2]);
        glEnd();
    }

        glBegin(GL_LINES);
        glVertex3f(misPuntosP[27].p[0],misPuntosP[27].p[1],misPuntosP[27].p[2]);
        glVertex3f(misPuntosP[28].p[0],misPuntosP[28].p[1],misPuntosP[28].p[2]);
        glVertex3f(misPuntosP[27].p[0],misPuntosP[27].p[1],misPuntosP[27].p[2]);
        glVertex3f(misPuntosP[29].p[0],misPuntosP[29].p[1],misPuntosP[29].p[2]);
//        glVertex3f(misPuntosP[29].p[0],misPuntosP[29].p[1],misPuntosP[29].p[2]);
//        glVertex3f(misPuntosP[30].p[0],misPuntosP[30].p[1],misPuntosP[30].p[2]);
//        glVertex3f(misPuntosP[28].p[0],misPuntosP[28].p[1],misPuntosP[28].p[2]);
//        glVertex3f(misPuntosP[30].p[0],misPuntosP[30].p[1],misPuntosP[30].p[2]);
        glEnd();
    // termina dibujado propulsor4

    op->pop();
}

void Cohete::update(){
    if(puntosPivote[0]>20 || puntosPivote[0]<-20 || puntosPivote[1]>20 || puntosPivote[1]<-20 || puntosPivote[2]>20 || puntosPivote[2]<-20){
        for(int i=0; i<3; i++)
            puntosPivote[i] = puntosOrigen[i];
    }
}

