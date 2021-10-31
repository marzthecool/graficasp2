#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include "Punto.h"
#include "Cubo.h"
#include "Linea.h"
#include "Asteroide.h"
#include "Triangulo.h"
#include "Cohete.h"
#include "Satelite.h"
#include "Operador.h"
#include "Sphere.h"

//Variables dimensiones de la pantalla
int WIDTH=600;
int HEIGTH=600;

//Variables para establecer los valores de gluPerspective
float FOVY=60.0;
float ZNEAR=0.01;
float ZFAR=100.0;

//Variables para definir la posicion del observador
//gluLookAt(EYE_X,EYE_Y,EYE_Z,CENTER_X,CENTER_Y,CENTER_Z,UP_X,UP_Y,UP_Z)
float EYE_X=10.0;
float EYE_Y=5.0;
float EYE_Z=10.0;
float CENTER_X=0;
float CENTER_Y=0;
float CENTER_Z=0;
float UP_X=0;
float UP_Y=1;
float UP_Z=0;

//Variables para dibujar los ejes del sistema
float X_MIN=-20;
float X_MAX=20;
float Y_MIN=-20;
float Y_MAX=20;
float Z_MIN=-20;
float Z_MAX=20;

//Variables del dibujado
Operador operador3D;
Cohete nave1(&operador3D);
Cohete nave2(&operador3D);
Satelite sat1(&operador3D);
Asteroide ast1(&operador3D);
Asteroide ast2(&operador3D);
Sphere plan1(&operador3D);
Sphere luna1(&operador3D);

//Velocidad de animacion
float d;

//puntos para eje de rotación
Punto pA;
Punto pB;
//float pA[3];
//float pB[3];

void drawAxis()
{
     glShadeModel(GL_SMOOTH);
     glLineWidth(3.0);
     //X axis in red
     glBegin(GL_LINES);
       glColor3f(1.0f,0.0f,0.0f);
       glVertex3f(X_MIN,0.0,0.0);
       glColor3f(0.5f,0.0f,0.0f);
       glVertex3f(X_MAX,0.0,0.0);
     glEnd();
     //Y axis in green
     glColor3f(0.0f,1.0f,0.0f);
     glBegin(GL_LINES);
       glColor3f(0.0f,1.0f,0.0f);
       glVertex3f(0.0,Y_MIN,0.0);
       glColor3f(0.0f,0.5f,0.0f);
       glVertex3f(0.0,Y_MAX,0.0);
     glEnd();
     //Z axis in blue
     glBegin(GL_LINES);
       glColor3f(0.0f,0.0f,1.0f);
       glVertex3f(0.0,0.0,Z_MIN);
       glColor3f(0.0f,0.0f,0.5f);
       glVertex3f(0.0,0.0,Z_MAX);
     glEnd();
     glLineWidth(1.0);
 }

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
}

void display()
{

    d += 0.05; //Velocidad de animacion
    operador3D.identidad();

    Sleep(50);

    glClear(GL_COLOR_BUFFER_BIT);
    drawAxis();

    //Planetas
    operador3D.push();
        //position
            //..
        //animation
        pA.setValues(0.0,0.0,0.0);
        pB.setValues(2.0,0.0,2.0);
        operador3D.rotar(d*7, pA.p, pB.p);
        //drawing
        plan1.update();
        glColor3f(0.4f,0.4f,0.8f); //azul
        plan1.draw();
    operador3D.pop();

    //Satelites
    operador3D.push();
        //position
            //..
        //animation
        operador3D.trs(-5*cos(d/2),0,6*sin(d/2));
        operador3D.rotZ(d*100);
        //drawing
        sat1.update();
        glColor3f(0.6f,0.3f,0.3f); //cobre
        sat1.draw();
    operador3D.pop();

    //Nave1
    operador3D.push();
        //position
        operador3D.trs(-4.0,-5.0,-40.0);
        //animation
        operador3D.trs(-d,d,d*3);
        operador3D.rotX(-d*4);
        //drawing
        nave1.update();
        glColor3f(0.8f,0.8f,0.8f); //plateado
        nave1.draw();
    operador3D.pop();

    //Nave2
    operador3D.push();
        //position
        operador3D.trs(-4.0,-4.0,10.0);
        //animation
        operador3D.trs(d*1.5,d*1.2,-d*3);
        operador3D.rotX(d*4);
        //drawing
        nave2.update();
        glColor3f(0.0f,1.0f,1.0f); //aqua
        nave2.draw();
    operador3D.pop();

    //Luna
    operador3D.push();
        //position
        operador3D.esc(-15,-15,-15);
        operador3D.trs(2,-4,-5);
        //animation
        operador3D.trs(0,sin(d/2),sin(d/2));
        //drawing
        luna1.update();
        glColor3f(0.4f,0.9f,0.4f); //verde
        luna1.draw();
    operador3D.pop();

    //Asteroide1
    operador3D.push();
        //position
            //..
        //animation
        operador3D.rotY(d*2);
        operador3D.trs(4*cos(d/2),4*sin(d/2),0);
        //drawing
        ast1.update();
        glColor3f(0.35f,0.35f,0.35f); //gris
        ast1.draw();
    operador3D.pop();

    //Asteroide2
    operador3D.push();
        //position
            //..
        //animation
        operador3D.rotX(d*2);
        operador3D.trs(4*sin(d/2),0,4*cos(d/2));
        //drawing
        ast1.update();
        glColor3f(1.0f,0.9f,0.0f); //amarillo
        ast1.draw();
    operador3D.pop();

    glutSwapBuffers();
}

void idle()
{
  display();
}

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(FOVY, (GLfloat)WIDTH/HEIGTH, ZNEAR, ZFAR);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(EYE_X,EYE_Y,EYE_Z,CENTER_X,CENTER_Y,CENTER_Z,UP_X,UP_Y,UP_Z);
    glClearColor(0,0,0,0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(WIDTH, HEIGTH);
    glutCreateWindow("Parcial 2");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}
