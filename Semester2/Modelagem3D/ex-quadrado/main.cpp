#include <windows.h>
#include <GL/freeglut.h>
#include <stdio.h>

#include "quadrado.h"

// Vetor de translacao
GLfloat xstep = 3.0f;
GLfloat ystep = 3.0f;

GLfloat windowWidth;
GLfloat windowHeight;

Quadrado quadrado1;

void Desenha(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    QuadradoDesenha(quadrado1);

    glutSwapBuffers();
}

void Timer(int value)
{
    // Muda a direção quando chega na borda esquerda ou direita
    if(quadrado1.x > windowWidth-quadrado1.size || quadrado1.x < 0)
        xstep = -xstep;

    // Muda a direção quando chega na borda superior ou inferior
    if(quadrado1.y > windowHeight-quadrado1.size || quadrado1.y < 0)
        ystep = -ystep;

    // Verificação de bordas.  Se a window for menor e o quadrado sair do volume de visualização
    if(quadrado1.x > windowWidth-quadrado1.size)
        quadrado1.x = windowWidth-quadrado1.size-1;

    if(quadrado1.y > windowHeight-quadrado1.size)
        quadrado1.y = windowHeight-quadrado1.size-1;

    quadrado1.x += xstep;
    quadrado1.y += ystep;

    glutPostRedisplay();
    glutTimerFunc(5,Timer, 0);
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    printf("\n w: %d      h: %d ", w, h);
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    windowWidth = w;
    windowHeight = h;
    gluOrtho2D(0.0f, windowWidth, 0.0f, windowHeight);
}

int main(int argc, char** argv)
{
    //Quadrado quadrado1;

    quadrado1.x = 100.0f;
    quadrado1.y = 150.0f;
    quadrado1.size = 20.0f;

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutCreateWindow("Exercício Quadrado");
    glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
    glutTimerFunc(5, Timer, 0);
    glutMainLoop();
}
