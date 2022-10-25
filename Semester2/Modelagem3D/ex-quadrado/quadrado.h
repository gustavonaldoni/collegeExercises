typedef struct
{
    float x, y;
    int size;
} Quadrado;

void QuadradoDesenha(Quadrado quadrado)
{
    glBegin(GL_QUADS);
        glVertex2i(quadrado.x,quadrado.y+quadrado.size);
        glVertex2i(quadrado.x,quadrado.y);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2i(quadrado.x+quadrado.size,quadrado.y);
        glVertex2i(quadrado.x+quadrado.size,quadrado.y + quadrado.size);
    glEnd();
}
