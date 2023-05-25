#include <stdio.h>

#define BOARD_SIZE 3

void printBoard(char board[BOARD_SIZE][BOARD_SIZE])
{
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf(" %c ", board[i][j]);
            if (j != BOARD_SIZE - 1)
            {
                printf("|");
            }
        }
        printf("\n");
        if (i < BOARD_SIZE - 1)
        {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

int checkWin(char board[BOARD_SIZE][BOARD_SIZE], char player)
{
    // Check for row winner
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return 1;
        }
    }

    // Check for column winner
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return 1;
        }
    }
    // Check for diagonal winner
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    {
        return 1;
    }

    return 0;
}

int main()
{

    printf("Welcome to TicTacToe\n");

    char board[BOARD_SIZE][BOARD_SIZE] = {{' ', ' ', ' '},
                                          {' ', ' ', ' '},
                                          {' ', ' ', ' '}};

    char player = 'X';
    int row, column, moves = 0;

    while (1)
    {
        printf("It's player %c's turn\n", player);
        printf("Select a row (i.e., 3-1)");
        scanf("%c", row);
        printf("Select a column");
        scanf("%c", column);

        // Check if the entered position is valid
        if (row < 0 || row >= BOARD_SIZE || column < 0 || column >= BOARD_SIZE)
        {
            printf("This position is outside the board! Try again.\n");
            continue;
        }

        // Check if space is taken
        if (board[row][column] == 'X' || board[row][column] == 'Y')
        {
            printf("Sorry that space is taken. Try again.\n");
            continue;
        }

        board[row][column] = player;
        moves++;
        printBoard(board);
    }

    printBoard(board);
}