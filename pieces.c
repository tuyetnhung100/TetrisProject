#include "pieces.h"

int FAILED_FLAG = 0;

/**********************************************************************************************
placeNextPiece(): a function that chooses an appropriate row and column to place a piece onto
	a nextup board given a piece type, a board, and the size of the board (which will be 4).
	It then calls the normal placePiece function.
Author: Paul Schot
**********************************************************************************************/
int placeNextPiece(int type, int size, int board[size][size]) {
	switch (type) {
		// Single block
		case 0:
			return placePiece(type, 0, 0, size, board);
		// 2 block lines
		case 1:
			return placePiece(type, 0, 0, size, board);
		case 2:
			return placePiece(type, 0, 0, size, board);
		// 3 block lines
		case 3:
			return placePiece(type, 0, 0, size, board);
		case 4:
			return placePiece(type, 0, 0, size, board);
		// 3 block L's
		case 5:
			return placePiece(type, 0, 0, size, board);
		case 6:
			return placePiece(type, 1, 0, size, board);
		case 7:
			return placePiece(type, 0, 0, size, board);
		case 8:
			return placePiece(type, 0, 0, size, board);
		// 3x3 block
		case 9:
			return placePiece(type, 0, 0, size, board);
		// 2x2 block
		case 10:
			return placePiece(type, 0, 0, size, board);
		// 4 block lines
		case 11:
			return placePiece(type, 0, 0, size, board);
		case 12:
			return placePiece(type, 0, 0, size, board);
		// 5 block L's
		case 13:
			return placePiece(type, 0, 0, size, board);
		case 14:
			return placePiece(type, 2, 0, size, board);
		case 15:
			return placePiece(type, 0, 0, size, board);
		case 16:
			return placePiece(type, 0, 0, size, board);
		// 4 block Z's
		case 17:
			return placePiece(type, 0, 0, size, board);
		case 18:
			return placePiece(type, 0, 1, size, board);
		// 4 block S's
		case 19:
			return placePiece(type, 1, 0, size, board);
		case 20:
			return placePiece(type, 0, 0, size, board);
		// 4 block L's
		case 21:
			return placePiece(type, 0, 0, size, board);
		case 22:
			return placePiece(type, 1, 0, size, board);
		case 23:
			return placePiece(type, 0, 0, size, board);
		case 24:
			return placePiece(type, 1, 0, size, board);
		// 4 block reverse L's
		case 25:
			return placePiece(type, 2, 0, size, board);
		case 26:
			return placePiece(type, 0, 0, size, board);
		case 27:
			return placePiece(type, 0, 0, size, board);
		case 28:
			return placePiece(type, 0, 0, size, board);
		default:
			return 0;
	}
}

/**********************************************************************************************
placePiece(): a function that tries to place a piece onto a board given a piece type, a
	row/column pair, the board, and the size of the board. Returns 1 if successful,
	0 if not successful.
Author(s): Paul Schot, Nina Hoang
**********************************************************************************************/
int placePiece(int type, int row, int col, int size, int board[size][size]) {
	// Make sure FAILED_FLAG is off
	FAILED_FLAG = 0;

	// If row and col are not contained in the board, return 0 and do nothing
	if (row < 0 || col < 0 || row >= size || col >= size) {
		return 0;
	}

	// Based on piece type, populate the board
	switch (type) {
		// Single block
		case 0:
			placePiecelet(row, col, size, board);
			break;
		// 2 block lines
		case 1:
			placePiecelet(row, col, size, board);
			placePiecelet(row + 1, col, size, board);
			break;
		case 2:
			placePiecelet(row, col, size, board);
			placePiecelet(row, col + 1, size, board);
			break;
		// 3 block lines
		case 3:
			placePiecelet(row, col, size, board);
			placePiecelet(row + 1, col, size, board);
			placePiecelet(row + 2, col, size, board);
			break;
		case 4:
			placePiecelet(row, col, size, board);
			placePiecelet(row, col + 1, size, board);
			placePiecelet(row, col + 2, size, board);
			break;
		// 3 block L's
		case 5:
			placePiecelet(row, col, size, board);
			placePiecelet(row, col + 1, size, board);
			placePiecelet(row + 1, col, size, board);
			break;
		case 6:
			placePiecelet(row, col, size, board);
			placePiecelet(row - 1, col + 1, size, board);
			placePiecelet(row, col + 1, size, board);
			break;
		case 7:
			placePiecelet(row, col, size, board);
			placePiecelet(row + 1, col, size, board);
			placePiecelet(row + 1, col + 1, size, board);
			break;
		case 8:
			placePiecelet(row, col, size, board);
			placePiecelet(row, col + 1, size, board);
			placePiecelet(row + 1, col + 1, size, board);
			break;
		// 3x3 block
		case 9:
			placePiecelet(row, col, size, board);
			placePiecelet(row, col + 1, size, board);
			placePiecelet(row, col + 2, size, board);
			placePiecelet(row + 1, col, size, board);
			placePiecelet(row + 1, col + 1, size, board);
			placePiecelet(row + 1, col + 2, size, board);
			placePiecelet(row + 2, col, size, board);
			placePiecelet(row + 2, col + 1, size, board);
			placePiecelet(row + 2, col + 2, size, board);
			break;
		// 2x2 block
		case 10:
			placePiecelet(row, col, size, board);
			placePiecelet(row, col + 1, size, board);
			placePiecelet(row + 1, col, size, board);
			placePiecelet(row + 1, col + 1, size, board);
			break;
		// 4 block lines
		case 11:
			placePiecelet(row, col, size, board);
			placePiecelet(row + 1, col, size, board);
			placePiecelet(row + 2, col, size, board);
			placePiecelet(row + 3, col, size, board);
			break;
		case 12:
			placePiecelet(row, col, size, board);
			placePiecelet(row, col + 1, size, board);
			placePiecelet(row, col + 2, size, board);
			placePiecelet(row, col + 3, size, board);
			break;
		// 5 block L's
		case 13:
			placePiecelet(row, col, size, board);
			placePiecelet(row, col + 1, size, board);
			placePiecelet(row, col + 2, size, board);
			placePiecelet(row + 1, col, size, board);
			placePiecelet(row + 2, col, size, board);
			break;
		case 14:
			placePiecelet(row, col, size, board);
			placePiecelet(row, col + 1, size, board);
			placePiecelet(row, col + 2, size, board);
			placePiecelet(row - 1, col + 2, size, board);
			placePiecelet(row - 2, col + 2, size, board);
			break;
		case 15:
			placePiecelet(row, col, size, board);
			placePiecelet(row + 1, col, size, board);
			placePiecelet(row + 2, col, size, board);
			placePiecelet(row + 2, col + 1, size, board);
			placePiecelet(row + 2, col + 2, size, board);
			break;
		case 16:
			placePiecelet(row, col, size, board);
			placePiecelet(row, col + 1, size, board);
			placePiecelet(row, col + 2, size, board);
			placePiecelet(row + 1, col + 2, size, board);
			placePiecelet(row + 2, col + 2, size, board);
			break;
		// 4 block Z's
		case 17:
			placePiecelet(row, col, size, board);
			placePiecelet(row, col + 1, size, board);
			placePiecelet(row + 1, col + 1, size, board);
			placePiecelet(row + 1, col + 2, size, board);
			break;
		case 18:
			placePiecelet(row, col, size, board);
			placePiecelet(row + 1, col, size, board);
			placePiecelet(row + 1, col - 1, size, board);
			placePiecelet(row + 2, col - 1, size, board);
			break;
		// 4 block S's
		case 19:
			placePiecelet(row, col, size, board);
			placePiecelet(row, col + 1, size, board);
			placePiecelet(row - 1, col + 1, size, board);
			placePiecelet(row - 1, col + 2, size, board);
			break;
		case 20:
			placePiecelet(row, col, size, board);
			placePiecelet(row + 1, col, size, board);
			placePiecelet(row + 1, col + 1, size, board);
			placePiecelet(row + 2, col + 1, size, board);
			break;
		case 21:
			placePiecelet(row, col, size, board);
			placePiecelet(row + 1, col, size, board);
			placePiecelet(row + 2, col, size, board);
			placePiecelet(row + 2, col + 1, size, board);
			break;
		case 22:
			placePiecelet(row, col, size, board);
			placePiecelet(row - 1, col, size, board);
			placePiecelet(row - 1, col + 1, size, board);
			placePiecelet(row - 1, col + 2, size, board);
			break;
		case 23:
			placePiecelet(row, col, size, board);
			placePiecelet(row, col + 1, size, board);
			placePiecelet(row + 1, col + 1, size, board);
			placePiecelet(row + 2, col + 1, size, board);
			break;
		case 24:
			placePiecelet(row, col, size, board);
			placePiecelet(row, col + 1, size, board);
			placePiecelet(row, col + 2, size, board);
			placePiecelet(row - 1, col + 2, size, board);
			break;
		// 4 block reverse L's
		case 25:
			placePiecelet(row, col, size, board);
			placePiecelet(row, col + 1, size, board);
			placePiecelet(row - 1, col + 1, size, board);
			placePiecelet(row - 2, col + 1, size, board);
			break;
		case 26:
			placePiecelet(row, col, size, board);
			placePiecelet(row + 1, col, size, board);
			placePiecelet(row + 1, col + 1, size, board);
			placePiecelet(row + 1, col + 2, size, board);
			break;
		case 27:
			placePiecelet(row, col, size, board);
			placePiecelet(row, col + 1, size, board);
			placePiecelet(row + 1, col, size, board);
			placePiecelet(row + 2, col, size, board);
			break;
		case 28:
			placePiecelet(row, col, size, board);
			placePiecelet(row, col + 1, size, board);
			placePiecelet(row, col + 2, size, board);
			placePiecelet(row + 1, col + 2, size, board);
			break;
		default:
			return 0;
	}
	if (FAILED_FLAG) {
		// Undo any changes
		undoChanges(size, board);
		return 0;
	}
	// Only reach here if successful
	confirmChanges(size, board);
	return 1;
}

/**********************************************************************************************
placePiecelet(): a function that tries to place a a single 1x1 piece onto a board given a
	a row/column pair, the board size, and a board. Sets FAILED_FLAG to 1 if it fails.
Author: Paul Schot
**********************************************************************************************/
void placePiecelet(int row, int col, int size, int board[size][size]) {
	// If row and col are not contained in the board, set FAILED_FLAG and do nothing
    if (row < 0 || col < 0 || row >= size || col >= size) {
    	FAILED_FLAG = 1;
		return;
	}
	// Check if position on board is empty
	if (board[row][col] == 0) {
		board[row][col] = 2;
	} else {
		FAILED_FLAG = 1;
	}
}

/**********************************************************************************************
undoChanges(): a function that clears the board of any standing changes
Author: Paul Schot
**********************************************************************************************/
void undoChanges(int size, int board[size][size]) {
	for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
			// Check if board position was filled by a 2, and set it to 0
            if (board[r][c] == 2) {
				board[r][c] = 0;
			}
        }
    }
}

/**********************************************************************************************
confirmChanges(): a function that changes any 2's on the board to 1's
Author: Paul Schot
**********************************************************************************************/
void confirmChanges(int size, int board[size][size]) {
	for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
			// Check if board position was filled by a 2, and set it to 1
            if (board[r][c] == 2) {
				board[r][c] = 1;
			}
        }
    }
}
