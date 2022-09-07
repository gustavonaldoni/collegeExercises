#include<GL/Glut.h>
#include<stdlib.h>
#include<stdio.h>
#include <stdbool.h>
#include<time.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

float r,g,b,x,y;

void DrawRectangle(int x, int y, int width, int height)
{
    glRecti(x, y, x + width, y + height);
}

void mouse(int button, int state, int mousex, int mousey)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        x = mousex;
        y = SCREEN_HEIGHT - mousey;
        r=(rand()%10)/10.0;
        g=(rand()%10)/10.0;
        b=(rand()%10)/10.0;
    }
    glutPostRedisplay();
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(r,g,b);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (float)(SCREEN_WIDTH), 0.0, (float) (SCREEN_HEIGHT));

    DrawRectangle(x, y, 50, 50);

    glFlush();
}
int main(int argc, char** argv)
{
    srand(time(NULL));
    glutInit(&argc,argv);

    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Interacao via Mouse");
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop();
}
