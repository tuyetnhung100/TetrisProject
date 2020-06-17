/*********************************************************************************************
main.c
    Authors: Paul Schot, Nina Hoang, Tony Marcello
    About: The file that controls the setup, flow, and termination of the game.
*********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include "pieces.h"
#include "checkFilled.h"
#include "display.h"

#define SIZE 10 // Size of the board
#define NEXT_SIZE 4 // Size of next up display
#define TOTAL_PIECES 28
#define PIECE_SCORE 5 // 5 points per place piece

void initializeBoard(int size, int board[size][size]);
int getUserIntInput(char *message, int max);
char getUserCharInput(char *message);
int getRandomPiece();
int nextEmpty(int size, int nextType[size]);
void generateNext(int size1, int nextType[size1], int size2, int nextup[size1][size2][size2]);
int gameOver(int failCount);
void readHighScore(int *highScore);
void writeHighScore(int score);

/*********************************************************************************************
main(): the main function
Author(s): Paul Schot, Nina Hoang, Tony Marcello
*********************************************************************************************/
int main(void) {
    // Seed the randomizer with time
    srand(time(NULL));

    // Create board
    int board[SIZE][SIZE];
    initializeBoard(SIZE, board);

    // Create nextup
    int nextType[3];
    nextType[0] = -1;
    nextType[1] = -1;
    nextType[2] = -1;
    int nextup[3][NEXT_SIZE][NEXT_SIZE];
    for (int i = 0; i < 3; i++) {
        initializeBoard(NEXT_SIZE, nextup[i]);
    }
    generateNext(3, nextType, NEXT_SIZE, nextup);

    // Start a new score and high score
    int score = 0;
    int highScore;
    readHighScore(&highScore);

    // Clear the window
    clear();

    int failCount = 0;

    do {
        // Show the score
        printf("Score: %d\nHigh Score: %d\n\n\n", score, highScore);

        // Show the board
        displayBoard(SIZE, board);

        // Show the next up display
        displayNext(NEXT_SIZE, nextup);

        int piece = getUserIntInput("Which piece (1-3)? ", 3) - 1;

        // Get a row (as a letter) and column from the user
        int row = getUserCharInput("Which row? ") - 65;
        int col = getUserIntInput("Which column? ", SIZE) - 1;

        // Attempt to place the piece
        if (placePiece(nextType[piece], row, col, SIZE, board)) {
            failCount = 0;
            int points = PIECE_SCORE + checkFilled(SIZE, board);
            score += points;
            nextType[piece] = -1;
            initializeBoard(NEXT_SIZE, nextup[piece]);
            // Clear the window
            clear();
            printf("PLACEMENT SUCCEEDED +%d POINTS!\n\n", points);

            if (nextEmpty(3, nextType)) {
                generateNext(3, nextType, NEXT_SIZE, nextup);
            }
        } else {
            // Clear the window
            clear();
            printf("PLACEMENT FAILED\n\n");
            failCount++;
        }
    } while (!gameOver(failCount));

    printf("GAME OVER\n");

    // Check if new high score
    if (score > highScore) {
        printf("NEW HIGH SCORE! %d POINTS\n", score);
        writeHighScore(score);
    }

    return 0;
}

/*********************************************************************************************
gameOver(): a function that checks whether the game is over
Author: Nina Hoang
*********************************************************************************************/
int gameOver(int failCount) {
    if (failCount == 3) {
        return 1;
    }
    return 0;
}

/*********************************************************************************************
nextEmpty(): a function that checks whether the next display is empty
*********************************************************************************************/
int nextEmpty(int size, int nextType[size]) {
    int empty = 1;
    for (int i = 0; i < 3; i++) {
        if (nextType[i] != -1) {
            empty = 0;
        }
    }
    return empty;
}

/*********************************************************************************************
generateNext(): a function that fills the next arrays with random pieces
Author: Paul Schot
*********************************************************************************************/
void generateNext(int size1, int nextType[size1], int size2, int nextup[size1][size2][size2]) {
    for (int i = 0; i < size1; i++) {
        // Get a new random piece number
        nextType[i] = getRandomPiece();

        // Put it in the display
        placeNextPiece(nextType[i], NEXT_SIZE, nextup[i]);
    }
}

/*********************************************************************************************
initializeBoard(): a function that fills a given board with 0's
*********************************************************************************************/
void initializeBoard(int size, int board[size][size]) {
	for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            board[r][c] = 0;
        }
    }
}

/*********************************************************************************************
getUserIntInput(): a function that returns a user input of type int, not exceeding a given
maximum or going below 1
Author: Paul Schot
CITATION: for help with better validation
    http://jackstromberg.com/2013/02/how-to-validate-numeric-integer-input-in-c/
*********************************************************************************************/
int getUserIntInput(char *message, int max) {
    printf("%s", message);
    int input, temp, status;
    status = scanf("%d", &input);
	while (status != 1 || input < 1 || input > max){
        do {
            temp = getchar();
        } while (temp != '\n');
		printf("Invalid input. Try again: ");
		status = scanf("%d", &input);
	}
    return input;
}

/*********************************************************************************************
getUserCharInput(): a function that returns a user input of type char from A to J
Author: Paul Schot
CITATION: for help with better validation
    http://jackstromberg.com/2013/02/how-to-validate-numeric-integer-input-in-c/
*********************************************************************************************/
char getUserCharInput(char *message) {
    printf("%s", message);
    int status;
    char input, temp;
    status = scanf(" %c", &input);
    input = toupper(input);
	while (status != 1 || input < 'A' || input > 'J'){
        do {
            temp = getchar();
        } while (temp != '\n');
		printf("Invalid input. Try again: ");
		status = scanf(" %c", &input);
        input = toupper(input);
	}
    return input;
}

/*********************************************************************************************
getRandomPiece(): a function that returns a random piece type [0-TOTAL_PIECES]
Author: Tony Marcello
*********************************************************************************************/
int getRandomPiece() {
    return rand() % (TOTAL_PIECES + 1);
}

/*********************************************************************************************
readHighScore(): a function that reads a high score from a file
Author: Nina Hoang
*********************************************************************************************/
void readHighScore(int *score) {
    // open the file to read from
    FILE *scorekeeperFile = fopen("scorekeeper.txt", "r");

    // scan in a number and put it in score
    fscanf(scorekeeperFile, "%d", score);

    // close the file
    fclose(scorekeeperFile);
}

/*********************************************************************************************
writeHighScore(): a function that writes a high score to a file
Author: Nina Hoang
*********************************************************************************************/
void writeHighScore(int score) {
    // open the file to write to
    FILE *scorekeeperFile = fopen("scorekeeper.txt", "w+");

    // write the new score
    fprintf(scorekeeperFile, "%d", score);

    // close the file
    fclose(scorekeeperFile);
}
