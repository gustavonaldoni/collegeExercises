#include<GL/freeglut.h>
#include<iostream>

GLfloat escala = 1;
GLfloat transladarX = 1;
GLfloat transladarY = 1;

GLfloat angulo = 0;

void desenharNome(int tamanho)
{
    glBegin(GL_LINES);

    glVertex2f(-8, tamanho/2);
    glVertex2f(-8, -tamanho/2);

    glVertex2f(-8, tamanho/2);
    glVertex2f(-4, -tamanho/2);

    glVertex2f(-4, -tamanho/2);
    glVertex2f(-4, tamanho/2);

    glVertex2f(-2, -tamanho/2);
    glVertex2f(0, tamanho/2);

    glVertex2f(0, tamanho/2);
    glVertex2f(2, -tamanho/2);

    glVertex2f(4, tamanho/2);
    glVertex2f(4, -tamanho/2);

    glVertex2f(4, -tamanho/2);
    glVertex2f(8, -tamanho/2);

    glVertex2f(10, tamanho/2);
    glVertex2f(10, -tamanho/2);

    glVertex2f(10, tamanho/2);
    glVertex2f(14, 0);

    glVertex2f(14, 0);
    glVertex2f(10, -tamanho/2);

    glVertex2f(16, tamanho/2);
    glVertex2f(16, -tamanho/2);

    glVertex2f(16, -tamanho/2);
    glVertex2f(20, -tamanho/2);

    glVertex2f(20, -tamanho/2);
    glVertex2f(20, tamanho/2);

    glVertex2f(20, tamanho/2);
    glVertex2f(16, tamanho/2);

    glVertex2f(22, tamanho/2);
    glVertex2f(22, -tamanho/2);

    glVertex2f(22, tamanho/2);
    glVertex2f(26, -tamanho/2);

    glVertex2f(26, -tamanho/2);
    glVertex2f(26, tamanho/2);

    glVertex2f(28, tamanho/2);
    glVertex2f(28, -tamanho/2);
    glEnd();

    glBegin(GL_POINTS);
    glVertex2f(28, tamanho/2 + 1);
    glEnd();
}

void desenha(void)
{
    glClear( GL_COLOR_BUFFER_BIT );

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);

    glScalef(escala, escala, 0);
    glTranslatef(transladarX, transladarY, 0);
    glRotatef(angulo, 0, 0, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    desenharNome(15);

    glFlush();
}

void listeningKey(unsigned char tecla, GLint x, GLint y)
{
    if (tecla == '+')
        escala += 0.01;

    else if (tecla == '-')
        escala -= 0.01;

    else if (tecla == 'a' || tecla == 'A')
        transladarX -= 1;

    else if (tecla == 'd' || tecla == 'D')
        transladarX += 1;

    else if (tecla == 'w' || tecla == 'W')
        transladarY += 1;

    else if (tecla == 's' || tecla == 'S')
        transladarY -= 1;

    else if (tecla == 'Q' || tecla == 'q')
        angulo -= 1;

    else if (tecla == 'E' || tecla == 'e')
        angulo += 1;

    if (escala >= 1.3)
        escala = 1.3;

    if (escala <= 0.5)
        escala = 0.5;

    desenha();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize(800,600);
    glutCreateWindow("TRABALHO - GUSTAVO AZEVEDO NALDONI");

    glutDisplayFunc(desenha);
    glutKeyboardFunc(listeningKey);

    glClearColor(0, 0, 0, 2);
    glutMainLoop();
    return 0;
}
