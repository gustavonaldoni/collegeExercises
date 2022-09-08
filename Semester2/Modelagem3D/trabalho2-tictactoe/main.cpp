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
#include "devName.h"
#include "turn.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

float r,g,b;
int x=0, y=0;

int n = 0;

int playerLine, playerColumn;
int turn = 1;
int totalPlays = 0;

Board board;

void Mouse(int button, int state, int mousex, int mousey)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        printf("mousex = %d, mousey = %d\n", mousex, mousey);

        x = mousex;
        y = SCREEN_HEIGHT - mousey;

        r=(rand()%10)/10.0;
        g=(rand()%10)/10.0;
        b=(rand()%10)/10.0;
    }
    glutPostRedisplay();
}

void Draw(void)
{
    printf("Total plays = %d\n", totalPlays);

    if (PlayerHasClickedOnBoard(board, x, y) &&
            totalPlays <= 9 &&
            CheckTie(board, totalPlays) == false)
    {
        playerLine = GetPlayerLineCoordinate(board, x);
        playerColumn = GetPlayerColumnCoordinate(board, y);

        if (PlayIsValid(board, playerLine, playerColumn) && totalPlays != -1)
        {
            totalPlays += 1;

            if (turn == 1)
            {
                board.canvas[playerLine][playerColumn] = 1;
                turn = 2;
            }

            else if (turn == 2)
            {
                board.canvas[playerLine][playerColumn] = 2;
                turn = 1;
            }
        }
    }

    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (float)(SCREEN_WIDTH), 0.0, (float) (SCREEN_HEIGHT));

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    DrawBoard(board);
    DrawDevNameOnScreen();

    if (totalPlays <= 9 && CheckTie(board, totalPlays) == false)
    {
        DrawTurnMessage(turn);
    }

    if (CheckWin(board, 1))
    {
        DrawWinMessage(1);
        totalPlays = 10;
    }

    if (CheckWin(board, 2))
    {
        DrawWinMessage(2);
        totalPlays = 10;
    }


    if (CheckTie(board, totalPlays))
    {
        DrawTieMessage();
    }

    glFlush();

    if (totalPlays == -1)
    {
        totalPlays = 0;
    }
}

void ListeningKey(unsigned char key, GLint x, GLint y)
{
    int KEY_SPACE = 32;

    if (CheckWin(board, 1) || CheckWin(board, 2) || CheckTie(board, totalPlays))
    {
        if (key == KEY_SPACE)
        {
            totalPlays = -1;
            turn = (rand() % 2) + 1;
            ResetBoard(&board);
        }
    }

    Draw();
}

int main(int argc, char** argv)
{
    srand(time(NULL));

    board.size = 350;
    board.x = (SCREEN_WIDTH - board.size) / 2;
    board.y = (SCREEN_HEIGHT - board.size) / 2;

    ResetBoard(&board);

    glutInit(&argc,argv);

    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Trabalho 2 - Tic Tac Toe");

    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glutDisplayFunc(Draw);
    glutMouseFunc(Mouse);
    glutKeyboardFunc(ListeningKey);

    glutMainLoop();
}
