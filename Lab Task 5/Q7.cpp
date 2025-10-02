/* Task 7: Create a program that solves the N-Queens problem for any given N using backtracking. The
program should print all possible solutions for placing N queens on an N x N chessboard so
that no two queens threaten each other. This task requires you to use a recursive function to
place queens row by row , and a validation function to check if a queen can be placed in a
specific cell. If a placement leads to a conflict, the algorithm should backtrack to the previous
row and try a different column. */

#include <iostream>
using namespace std;

bool isSafe(int board[], int row, int col){
    for(int i = 0; i < row; i++){
        int prevCol = board[i];
        if(prevCol == col || abs(prevCol - col) == abs(i - row))
            return false;
    }
    return true;
}

void printBoard(int board[], int N){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(board[i] == j) cout << "Q ";
            else cout << "_ ";
        }
        cout << endl;
    }
    cout << endl;
}

void solveNQueens(int board[], int row, int N, int &sol){
    if(row == N){
        sol++;
        cout << "-------------- Solution #" << sol << " --------------" << endl;
        printBoard(board, N);
        return;
    }

    for(int col = 0; col < N; col++){
        if(isSafe(board, row, col)){
            board[row] = col;
            solveNQueens(board, row + 1, N, sol);
        }
    }
}

int main(){
    int N;
    do {
        cout << "Enter the size of chessboard: ";
        cin >> N;

        if(N > 0) break;
        cout << "Please enter a positive integer for the size!" << endl;
    } while(N <= 0);

    int *board = new int[N];
    for(int i = 0; i < N; i++) board[i] = -1;
    int numSolutions = 0;

    solveNQueens(board, 0, N, numSolutions);
    if(numSolutions == 0)
        cout << "No solutions exist for N = " << N << endl;
    else
        cout << "Total solutions for N = " << N << " : " << numSolutions << endl;

    delete[] board;
    return 0;
}
