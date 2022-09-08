void DrawTurnMessage(int);

void DrawTurnMessage(int turn)
{
    glColor3f(0,0,0);
    glTranslatef(-2400, 3200,0);
    glScalef(1.5, 1, 0);

    if (turn == 1)
        TextToStroke(GLUT_STROKE_MONO_ROMAN,"Turn Player X");

    else if (turn == 2)
        TextToStroke(GLUT_STROKE_MONO_ROMAN,"Turn Player O");
}

