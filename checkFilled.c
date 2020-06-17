#include "checkFilled.h"

#define SCORE_ROW_COL 10

/*********************************************************************************************
fillWithZeros(): a function that fills a given array with 0's
Author: Nina Hoang
*********************************************************************************************/
void fillWithZeroes(int size, int array[size]) {
    for (int i = 0; i < size; i++) {
        array[i] = 0;
    }
}

/*********************************************************************************************
checkFilled(): a function that checks whether any rows or columns are filled in a board,
then empties any and calculates a point total to return
Author(s): Nina Hoang, Paul Schot
*********************************************************************************************/
int checkFilled(int size, int board[size][size]) {
    // Initialize arrays to count filled rows/cols
    int rowsFilled[size];
    int colsFilled[size];
    fillWithZeroes(size, rowsFilled);
    fillWithZeroes(size, colsFilled);

    // Check every row for fills
    for (int r = 0; r < size; r++) {
        int foundZero = 0;
        // Check each column in row r
        for (int c = 0; c < size; c++) {
            if (board[r][c] == 0) {
                foundZero = 1;
            }
        }
        // Went through all the columns, check if row was full
        if (foundZero == 0) {
            rowsFilled[r] = 1;
        }
    }

    // Check every column for fills
    for (int c = 0; c < size; c++) {
        int foundZero = 0;
        // Check every row in column c
        for (int r = 0; r < size; r++) {
            if (board[r][c] == 0) {
                foundZero = 1;
            }
        }
        // Went through all the rows, check if column was full
        if (foundZero == 0) {
            colsFilled[c] = 1;
        }
    }

    // Tally points
    int points = 0;
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += rowsFilled[i];
        sum += colsFilled[i];
    }
    points = sum * sum * SCORE_ROW_COL;

    // Clear rows
    for (int r = 0; r < size; r++) {
        if (rowsFilled[r] == 1) {
            for (int c = 0; c < size; c++) {
                board[r][c] = 0;
            }
        }
    }
    // Clear columns
    for (int c = 0; c < size; c++) {
        if (colsFilled[c] ==1) {
            for(int r = 0; r < size; r++) {
                board[r][c] = 0;
            }
        }
    }

    return points;
}
