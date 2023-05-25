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
        if (i < BOARD_SIZE - 1) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

int main()
{
    char board[BOARD_SIZE][BOARD_SIZE] = {{' ', ' ', ' '},
                                          {' ', ' ', ' '},
                                          {' ', ' ', ' '}};
    
    printBoard(board);
}