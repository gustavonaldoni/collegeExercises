bool CheckTie(Board, int);
void DrawTieMessage();

bool CheckTie(Board board, int totalPlays)
{
    if (totalPlays == 9 &&
        CheckWin(board, 1) == false &&
        CheckWin(board, 2) == false)
        return true;

    return false;
}

void DrawTieMessage()
{
    glColor3f(0,0,0);
    glTranslatef(-3000, 3200,0);
    //glScalef(1.5, 1, 0);

    TextToStroke(GLUT_STROKE_MONO_ROMAN,"Game TIED! Press SPACE to play again ...");
}
