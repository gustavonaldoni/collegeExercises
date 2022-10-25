void DrawDevNameOnScreen();

void DrawDevNameOnScreen()
{
    glColor3f(0,0,0);
    glTranslatef(125, 50,0);
    glScalef(0.15, 0.15, 0.15);
    TextToStroke(GLUT_STROKE_ROMAN,"Developed by Gustavo Azevedo Naldoni - 09/08/2022");
}
