#include<iostream>
#include<vector>
using namespace std;

void printBoard(vector<vector<char>> boards) {
    int n = boards.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << boards[i][j] << " ";
        }
        cout << endl;
    }

    cout << "----------------------------" << endl;
}

bool isSafe (vector<vector<char>> boards, int row, int col) {
    int n = boards.size();

    // horizontal
    for (int i = 0; i < n; i++) {
        if (boards[row][i] == 'Q') {
            return false;
        }
    }

    // vertical
    for (int j = 0; j < row; j++) {
        if (boards[j][col] == 'Q') {
            return false;
        }
    }

    // Diagonal left
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (boards[i][j] == 'Q') {
            return false;
        }
    }

    // Diagonal right
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (boards[i][j] == 'Q') {
            return false;
        }
    }


    return true;
}

int nqueens (vector<vector<char>> boards, int row  ) {
    int n = boards.size();

    if (row == n) {
        printBoard(boards);
        return 1;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (isSafe(boards, row, i)) {
            boards[row][i] = 'Q';
            count += nqueens(boards, row+1);
            
            // printing the first solution
            // if (count == 1) {
            //     return 1;
            // }

            boards[row][i] = '.';
        }
    }

    return count;
}

int main() {
    vector<vector<char>> boards;
    int n = 4;

    for (int i = 0; i < n; i++) {
        vector<char> newRow;

        for (int j = 0; j < n; j++) {
            newRow.push_back('.');
        }

        boards.push_back(newRow);
    }


    int count = nqueens(boards, 0);
    cout << count;

    return 0;
}