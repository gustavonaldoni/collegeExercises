bool CheckTie(Board, int);

bool CheckTie(Board board, int totalPlays)
{
    if (totalPlays == 9 &&
        CheckWin(board, 1) == false &&
        CheckWin(board, 2) == false)
        return true;

    return false;
}
