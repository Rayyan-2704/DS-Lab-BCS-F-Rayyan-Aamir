/* Task 5: Implement a Sudoku solver using the backtracking technique. The program should take a
partially filled 9x9 Sudoku grid and fill the empty cells (represented by 0) to solve the puzzle.
Your algorithm should:
1. Find an empty cell.
2. Try placing a number from 1 to 9 in the empty cell.
3. Check if the number is valid in the current row, column, and 3x3 subgrid.
4. If valid, recursively call the function to solve the rest of the puzzle.
5. If the recursive call doesn't lead to a solution,
backtrack by resetting the cell to 0 and trying the next number. */

#include <iostream>
using namespace std;

#define N 9

void printGrid(int grid[N][N]){
    for(int row = 0; row < N; row++){
        for(int col = 0; col < N; col++){
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int grid[N][N], int row, int col, int num){
    for(int x = 0; x < N; x++){
        if(grid[row][x] == num)
            return false;
    }

    for(int x = 0; x < N; x++){
        if(grid[x][col] == num)
            return false;
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(grid[i + startRow][j + startCol] == num) return false;
        }
    }

    return true;
}

bool findEmptyCell(int grid[N][N], int &row, int &col){
    for(row = 0; row < N; row++){
        for(col = 0; col < N; col++){
            if(grid[row][col] == 0)
                return true;
        }
    }

    return false;
}

bool solveSudoku(int grid[N][N]){
    int row, col;

    if(!findEmptyCell(grid, row, col)) return true;

    for(int num = 1; num <= 9; num++){
        if(isSafe(grid, row, col, num)){
            grid[row][col] = num;

            if(solveSudoku(grid)) return true;

            // Backtrack
            grid[row][col] = 0;
        }
    }

    return false;
}

int main(){
    int grid[N][N] = {
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

    if(solveSudoku(grid))
        printGrid(grid);
    else
        cout << "No solution exists!" << endl;

    return 0;
}
