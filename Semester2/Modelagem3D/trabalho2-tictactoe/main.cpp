#include<GL/Glut.h>
#include<stdlib.h>
#include<stdio.h>
#include <stdbool.h>
#include<time.h>

#include "utils.h"
#include "board.h"
#include "win.h"
#include "tie.h"
#include "play.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

float r,g,b;
int x=0, y=0;

int n = 0;

void mouse(int button, int state, int mousex, int mousey)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        printf("mousex = %d, mousey = %d\n", mousex, mousey);

        x = mousex;
        y = mousey;

        r=(rand()%10)/10.0;
        g=(rand()%10)/10.0;
        b=(rand()%10)/10.0;
    }
    glutPostRedisplay();
}

void Draw(void)
{
    Board board;

    board.size = 350;
    board.x = (SCREEN_WIDTH - board.size) / 2;
    board.y = (SCREEN_HEIGHT - board.size) / 2;

    if (n == 0)
        ResetBoard(&board);

    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (float)(SCREEN_WIDTH), 0.0, (float) (SCREEN_HEIGHT));

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    DrawBoard(board);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);

    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Trabalho 2 - Tic Tac Toe");

    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glutDisplayFunc(Draw);
    glutMouseFunc(mouse);

    srand(time(NULL));

    glutMainLoop();
}
