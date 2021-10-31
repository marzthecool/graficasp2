#include "Sphere.h"
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.14159265359

Sphere::Sphere(Operador *opera)
{
    resolution = 15;
    radius = 2;

    for(int a = 0; a < resolution; a++){
            for(int b = 0; b < resolution; b++){
                misPuntos[a][b].setOperador(opera);
            }
        }
    for(int x = 0; x < resolution*resolution; x++)


    for(int i = 0; i < resolution; i++){
        float lon = i*(PI/resolution);
        for(int j = 0; j < resolution; j ++){
            float lat = j*(2*PI/resolution);
            float x = radius * sin(lon) * cos(lat);
            float y = radius * sin(lon) * sin(lat);
            float z = radius * cos(lon);
            misPuntos[i][j].setValues(x,y,z);
        }
    }

    setOrigen(0,0,0);
    op = opera;
}

Sphere::~Sphere()
{
    //dtor
}

void Sphere::setOrigen(float x, float y, float z)
{
    puntoOrigen[0] = x;
    puntoOrigen[1] = y;
    puntoOrigen[2] = z;

    for (int i = 0; i < 3; i++)
        puntoPivote[i] = puntoOrigen[i];
}

void Sphere::draw()
{
    op->push();

        for(int i = 0; i < resolution; i++){
            for(int j = 0; j < resolution; j++){
                op -> multPuntos(misPuntos[i][j].p, misPuntosP[i][j].p);
            }
        }

        for(int a = 0; a < resolution; a++){
            for(int b = 0; b < resolution; b++){
                glBegin(GL_LINES);

                    glVertex3f(misPuntosP[a][b].p[0],misPuntosP[a][b].p[1],misPuntosP[a][b].p[2]);

                    if(a < resolution-1)
                        glVertex3f(misPuntosP[a+1][b].p[0],misPuntosP[a+1][b].p[1],misPuntosP[a+1][b].p[2]);

                    if( (a >= resolution - 2) && (b >= resolution-1)){
                        //
                    } else{
                        glVertex3f(misPuntosP[a][b+1].p[0],misPuntosP[a][b+1].p[1],misPuntosP[a][b+1].p[2]);
                    }

                    glVertex3f(misPuntosP[a][b].p[0],misPuntosP[a][b].p[1],misPuntosP[a][b].p[2]);
                glEnd();
            }
        }
    op->pop();
}

void Sphere::update(){

}
