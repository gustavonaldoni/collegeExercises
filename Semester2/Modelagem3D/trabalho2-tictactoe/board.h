typedef struct
{
    int x, y;
    int size;
    int canvas[3][3];
} Board;

void ResetBoard(Board *);

void ResetBoard(Board *board)
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            board->canvas[i][j] = 0;
        }
    }
}
