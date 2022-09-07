#include <math.h>

#define PI 3.1415926535898

float mapValue(float, float, float, float, float);
void DrawRectangle(int, int, int, int);
void DrawLine(int, int, int, int, int);
void DrawCross(int, int, int);

float mapValue(float n, float start1, float stop1, float start2, float stop2)
{
    if (stop1 == start1)
        return (float) 0;

    return start2 + ((n - start1) * (stop2 - start2) / (stop1 - start1));
}

void DrawRectangle(int x, int y, int width, int height)
{
    glRecti(x, y, x + width, y + height);
}

void DrawLine(int x1, int y1, int x2, int y2, int color)
{
    glBegin(GL_LINES);
    glColor3f(mapValue((float)color, 0.0, 255.0, 0.0, 1.0),
              mapValue((float)color, 0.0, 255.0, 0.0, 1.0),
              mapValue((float)color, 0.0, 255.0, 0.0, 1.0));
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glEnd();
}

void DrawCross(int x, int y, int crossSize, int color)
{
    DrawLine(x, y, x + crossSize, y + crossSize, color);
    DrawLine(x, y + crossSize, x + crossSize, y, color);
}

void DrawCircle(int xCenter, int yCenter, int radius, int color)
{
    float ang;
    float x, y;
    int i;

    glBegin(GL_LINE_LOOP);
    for (i = 0; i < 360; i++)
    {
        ang = (i * PI) / 180.0;
        x = xCenter + (cos(ang) * radius);
        y = yCenter + (sin(ang) * radius);

        glColor3f(mapValue((float)color, 0.0, 255.0, 0.0, 1.0),
              mapValue((float)color, 0.0, 255.0, 0.0, 1.0),
              mapValue((float)color, 0.0, 255.0, 0.0, 1.0));

        glVertex2f(x, y);
    }
    glEnd();
}
