typedef struct
{
    int x, y;
    int size;
    int canvas[3][3];
} Board;

void ResetBoard(Board *);
void DrawBoard(Board);
int GetPlayerLineCoordinate(Board, int);
int GetPlayerColumnCoordinate(Board, int);
bool PlayerHasClickedOnBoard(Board);

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

void DrawBoard(Board board)
{
    int i, j;
    int space = board.size / 3;
    int startX, startY, endX, endY;
    int crossSize = 80;

    for (i = 1; i < 3; i++)
    {
        startX = board.x;
        startY = board.y + i * space;

        endX = board.x + 3 * space;
        endY = startY;

        DrawLine(startX, startY, endX, endY, 0);
    }

    for (j = 1; j < 3; j++)
    {
        startX = board.x + j * space;
        startY = board.y;

        endX = startX;
        endY = board.y + 3 * space;

        DrawLine(startX, startY, endX, endY, 0);
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (board.canvas[i][j] == 1)
            {
                DrawCross(board.x + i * space + (space - crossSize) / 2,
                          board.y + j * space + (space - crossSize) / 2,
                          crossSize,
                          0);
            }
            else if (board.canvas[i][j] == 2)
            {
                DrawCircle(board.x + i * space + space / 2,
                           board.y + j * space + space / 2,
                           (float)(crossSize / 2),
                           0);
            }
        }
    }
}

int GetPlayerLineCoordinate(Board board, int mousex)
{
    return (mousex - board.x) / (board.size / 3);
}

int GetPlayerColumnCoordinate(Board board, int mousey)
{
    return (mousey - board.y) / (board.size / 3);
}

bool PlayerHasClickedOnBoard(Board board, int mousex, int mousey)
{
    return CheckCollisionPointRec(mousex, mousey,
                                  board.x, board.y, board.size, board.size);
}
