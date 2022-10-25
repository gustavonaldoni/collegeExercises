#include <cstdlib>
#include <cctype>
#include <cstdio>
#ifdef __APPLE__
#include <GLUT/freeglut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>

#define SCREEN_X 1920
#define SCREEN_Y 1080

struct bola
{
    int raio;
};

float alpha = 19;
float beta = 0;
float cor = 1;
float altura = -4.499998;
float profundidade = 0;
float comprimento = 5.699997;

using namespace std;

float rx = 0, rz = 0;

float abertura = 100.0f, znear = 10, zfar = 20, aspect = 1.0f;
GLUquadricObj *quadratic;

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(abertura, aspect, znear, zfar);
    glMatrixMode(GL_MODELVIEW);


    glClearColor(0, 0, 0, 1);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glEnable(GL_DEPTH_TEST);
    quadratic = gluNewQuadric();
}
void display()
{
    glClearColor(255.0, 255.0, 255.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(abertura, aspect, znear, zfar);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    gluLookAt(0, 0, 15,  //from. Posicao onde a camera esta posicionada
              0, 0, 0,  //to. Posicao absoluta onde a camera esta vendo
              0, 1, 0);

    glRotatef((GLfloat) rx, 90.0f, 1.0f, 0.0f);
    glRotatef((GLfloat) rz, 1.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Bola
    glPushMatrix();
    glTranslatef(comprimento, altura, 0);
    glRotatef(7, 0, 1, 0);
    glRotatef(4, 1, 0, 0);
    glColor3f(0, 0, 0);
    printf("comprimento = %f\n", comprimento);
    printf("altura = %f\n\n", altura);
    glutWireSphere(1.0f, 15, 10);
    glPopMatrix();

    // Gol
    glPushMatrix();
    glColor3f(255, 0, 0);

    glPushMatrix();
    glScalef(2.0f, 80.0f, 2.0f);
    glTranslatef(-4, 0.1, 0);
    glutSolidCube(0.2f);
    glPopMatrix();

    glPushMatrix();
    glScalef(2.0f, 80.0f, 2.0f);
    glTranslatef(4, 0.1, 0);
    glutSolidCube(0.2f);
    glPopMatrix();

    glPushMatrix();
    glScalef(80.0f, 2.0f, 2.0f);
    glTranslatef(0, 8, 0);
    glutSolidCube(0.2f);
    glPopMatrix();

    glPushMatrix();
    glScalef(80.0f, 0.0f, 0.0f);
    glTranslatef(0, 0, 0);
    glutSolidCube(0.2f);
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

void  listeningSpKey (GLint tecla,
                      GLint x, GLint y)
{
    switch(tecla)
    {
    case GLUT_KEY_RIGHT:
        comprimento += 0.1f;
        break;

    case GLUT_KEY_LEFT:
        comprimento -= 0.1f;
        break;
    case GLUT_KEY_UP:
        altura += 0.1f;
        break;
    case GLUT_KEY_DOWN:
        altura -= 0.1f;
        break;

    }
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{

    switch(key)
    {
    case 'k':
        profundidade += 0.1f;
        break;
    case 'l':
        profundidade -= 0.1f;
        break;

    }
    glutPostRedisplay();
}


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(SCREEN_X, SCREEN_Y);
    glutCreateWindow("Futebol");
    gluOrtho2D(0.0, 400, 0.0, 600);
    init();
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(listeningSpKey);
    glutDisplayFunc(display);
    glutMainLoop();
}
