bool CheckWin(Board, int);

bool CheckWin(Board board, int playerNumber)
{
    int i, j;

    // Check horizontal win
    for (i = 0; i < 3; i++)
    {
        j = 0;

        if (board.canvas[i][j] == board.canvas[i][j + 1] &&
            board.canvas[i][j + 1] == board.canvas[i][j + 2] &&
            board.canvas[i][j] == playerNumber)
            return true;
    }

    // Check vertical win
    for (j = 0; j < 3; j++)
    {
        i = 0;

        if (board.canvas[i][j] == board.canvas[i + 1][j] &&
            board.canvas[i + 1][j] == board.canvas[i + 2][j] &&
            board.canvas[i][j] == playerNumber)
            return true;
    }

    // Check diagonal win -> left to right
    i = 0;
    j = 0;

    if (board.canvas[i][j] == board.canvas[i + 1][j + 1] &&
        board.canvas[i + 1][j + 1] == board.canvas[i + 2][j + 2] &&
        board.canvas[i][j] == playerNumber)
        return true;

    // Check diagonal win -> right to left
    i = 0;
    j = 2;

    if (board.canvas[i][j] == board.canvas[i + 1][j - 1] &&
        board.canvas[i + 1][j - 1] == board.canvas[i + 2][j - 2] &&
        board.canvas[i][j] == playerNumber)
        return true;

    return false;
}
