#include "display.h"
#include <stdlib.h>

#define GRN   "\x1B[32m"
#define RESET "\x1B[0m"

/*********************************************************************************************
clear(): a function that clears the window
*********************************************************************************************/
void clear() {
    system("clear");
}

/*********************************************************************************************
displayNext(): a function that prints out what the next piece looks like
Author: Paul Schot
*********************************************************************************************/
void displayNext(int size, int board[3][size][size]) {
    for (int i = 0; i < 3; i++) {
        printf("Piece %d:\n\n", i + 1);
        for (int r = 0; r < size; r++) {
            for (int c = 0; c < size; c++) {
                if (board[i][r][c] != 0) {
                    printf(GRN " * " RESET);
                } else {
                    printf("   ");
                }
            }
            printf("\n");
        }
    }
}

/*********************************************************************************************
displayBoard(): a function that prints out a given board, with style
Author: Paul Schot
*********************************************************************************************/
void displayBoard(int size, int board[size][size]) {
    // Print the columns headers
    printf("    ");
    for (int c = 0; c < size; c++) {
        printf(" %d ", c + 1);
    }

    // Print top edge
    printf("\n    ");
    for (int c = 0; c < size; c++) {
        printf("===");
    }

    for (int r = 0; r < size; r++) {
        // Print the row header
        printf("\n %c |", (char) (r +  65));

        for (int c = 0; c < size; c++) {
            // Print pieces
            if (board[r][c] != 0) {
                printf(GRN " * " RESET);
            } else {
                printf("   ");
            }
            // If last column, close it with a bar
            if (c == size - 1) {
                printf("|");
            }
        }
    }

    // Print bottom edge
    printf("\n    ");
    for (int c = 0; c < size; c++) {
        printf("===");
    }

    printf("\n\n");
}
