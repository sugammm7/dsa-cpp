#include <iostream>
#include <vector>
using namespace std;

void printSudoku (vector<vector<int>> board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe (vector<vector<int>> board, int row, int col, int digit) {
    // horizontal
    for (int i = 0; i <= 8; i++) {
        if (board[row][i] == digit) {
            return false;
        }
    }

    // vertical
    for (int j = 0; j <= 8; j++) {
        if (board[j][col] == digit) {
            return false;
        }
    }

    // 3*3 grid
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    for (int i = startRow; i <= startRow + 2; i++) {
        for (int j = startCol; j <= startCol + 2; j++) {
            if (board[i][j] == digit) {
                return false;
            }
        }
    }

    return true;
}

bool sudokuSolver (vector<vector<int>> board, int row, int col) {
    if (row == 8 && col == 8) {
        printSudoku(board);
        return 1;
    }

    int nextRow = row;
    int nextCol = col + 1;

    if (col == 8) {
        nextRow = row + 1;
        nextCol = 0;
    }

    if (board[row][col] != 0) {
        return sudokuSolver(board, nextRow, nextCol);
    }

    for (int digit = 1; digit <= 9; digit++) {
        if (isSafe(board, row, col, digit)) {
            board[row][col] = digit;

            if (sudokuSolver(board, nextRow, nextCol)) {
                return true;
            };

            board[row][col] = 0;
        }
    }

    return false;
}  

int main () {
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    sudokuSolver(board, 0, 0);

    return 0;
}