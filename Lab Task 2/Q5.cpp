/* Task #5:
Write a C++ program that dynamically creates a 2D matrix and provides:
=> Addition of two matrices.
=> Subtraction of two matrices.
=> Ensure safe memory handling with proper allocation/deallocation. */

#include <iostream>
using namespace std;

void initializeMatrix(int **arr, int r, int c);
int **addition(int **arr1, int **arr2, int r, int c);
int **subtraction(int **arr1, int **arr2, int r, int c);
void printMatrix(int **arr, int r, int c);

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

    int **matrix1 = new int *[rows];
    int **matrix2 = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix1[i] = new int[cols];
        matrix2[i] = new int[cols];
    }

    cout << "\nEnter the elements of Matrix 1 below\n";
    initializeMatrix(matrix1, rows, cols);

    cout << "\nEnter the elements of Matrix 2 below\n";
    initializeMatrix(matrix2, rows, cols);

    cout << "\nAddition of Matrix 1 and Matrix 2\n";
    int **sum = addition(matrix1, matrix2, rows, cols);
    printMatrix(sum, rows, cols);

    cout << "\nSubtraction of Matrix 1 and Matrix 2\n";
    int **diff = subtraction(matrix1, matrix2, rows, cols);
    printMatrix(diff, rows, cols);

    for (int i = 0; i < rows; i++)
    {
        delete[] matrix1[i];
        delete[] matrix2[i];
        delete[] sum[i];
        delete[] diff[i];
    }

    delete[] matrix1;
    delete[] matrix2;
    delete[] sum;
    delete[] diff;

    return 0;
}

void initializeMatrix(int **arr, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << "Row " << (i + 1) << ", Column " << (j + 1) << ": ";
            cin >> arr[i][j];
        }
    }
    cout << endl;
}

int **addition(int **arr1, int **arr2, int r, int c)
{
    int **res = new int *[r];
    for (int i = 0; i < r; i++)
        res[i] = new int[c];

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            res[i][j] = arr1[i][j] + arr2[i][j];
    }

    return res;
}

int **subtraction(int **arr1, int **arr2, int r, int c)
{
    int **res = new int *[r];
    for (int i = 0; i < r; i++)
        res[i] = new int[c];

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            res[i][j] = arr1[i][j] - arr2[i][j];
    }

    return res;
}

void printMatrix(int **arr, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        cout << "[ ";
        for (int j = 0; j < c; j++)
            cout << arr[i][j] << " ";
        cout << "]\n";
    }
}
