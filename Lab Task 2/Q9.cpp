/* Task #9:
Implement a program to represent a sparse matrix using a dynamic 2D array.
=> Input matrix elements.
=> Display the matrix in normal form.
=> Display the matrix in compressed form (row, column, value). */

#include <iostream>
using namespace std;

void initializeMatrix(int **arr, int r, int c);
void displayMatrix(int **arr, int r, int c);
void displayCompressedMatrix(int **arr, int r, int c);

int main()
{
    int rows, cols;
    while (true)
    {
        cout << "Enter the number of rows: ";
        cin >> rows;
        cout << "Enter the number of columns: ";
        cin >> cols;

        if (rows > 0 && cols > 0)
            break;
        cout << "Invalid rows and/or columns!" << endl;
    }

    int **matrix = new int *[rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = new int[cols];

    initializeMatrix(matrix, rows, cols);

    cout << "\nDisplaying the matrix in regular form\n";
    displayMatrix(matrix, rows, cols);

    cout << "\nDisplaying the matrix in compressed form\n";
    displayCompressedMatrix(matrix, rows, cols);

    for (int i = 0; i < rows; i++)
        delete[] matrix[i];
    delete[] matrix;

    return 0;
}

void initializeMatrix(int **arr, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << "Row " << i << ", Column " << j << ": ";
            cin >> arr[i][j];
        }
    }
    cout << endl;
}

void displayMatrix(int **arr, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        cout << "[ ";
        for (int j = 0; j < c; j++)
            cout << arr[i][j] << " ";
        cout << "]\n";
    }
}

void displayCompressedMatrix(int **arr, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] != 0)
            {
                cout << "Row " << i << ", Column " << j << ": " << arr[i][j] << endl;
            }
        }
    }
}
