#include <stdio.h>

#define MAX 20

int board[MAX][MAX];
int N;

int isSafe(int row, int col)
{
    int i, j;

    /* Check left side of the row */
    for (i = 0; i < col; i++)
    {
        if (board[row][i])
            return 0;
    }

    /* Check upper-left diagonal */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
            return 0;
    }

    /* Check lower-left diagonal */
    for (i = row, j = col; i < N && j >= 0; i++, j--)
    {
        if (board[i][j])
            return 0;
    }

    return 1;
}

int solveNQueens(int col)
{
    int i;

    if (col >= N)
        return 1;

    for (i = 0; i < N; i++)
    {
        if (isSafe(i, col))
        {
            board[i][col] = 1;

            if (solveNQueens(col + 1))
                return 1;

            /* Backtrack */
            board[i][col] = 0;
        }
    }

    return 0;
}

int main()
{
    int i, j;

    printf("Enter the value of N: ");
    scanf("%d", &N);

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            board[i][j] = 0;

    if (solveNQueens(0))
    {
        printf("Solution:\n");

        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
                printf("%d ", board[i][j]);

            printf("\n");
        }
    }
    else
    {
        printf("No solution exists.\n");
    }

    return 0;
}
