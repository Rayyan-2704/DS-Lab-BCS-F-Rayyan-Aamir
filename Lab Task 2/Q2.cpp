/* Task #2:
Write a program that uses a dynamic 2D array to represent a seating chart in a classroom.
=> Rows represent benches, columns represent seats on each bench.
=> Initialize the array with 0 (empty).
=> Let the user fill seats (1 for occupied).
=> Print the final seating chart in matrix form. */

#include <iostream>
using namespace std;

void initializeArray(int **arr, int rows, int cols);
bool updateArray(int **arr, int rows, int cols, int r, int c);
void printArray(int **arr, int rows, int cols);

int main()
{
    int benches, seats;
    while (true)
    {
        cout << "Enter the number of benches: ";
        cin >> benches;

        if (benches > 0)
            break;
        cout << "Invalid number of benches!" << endl;
    }
    cout << endl;

    while (true)
    {
        cout << "Enter the number of seats: ";
        cin >> seats;

        if (seats > 0)
            break;
        cout << "Invalid number of seats!" << endl;
    }

    int **arr = new int *[benches];
    for (int i = 0; i < benches; i++)
        arr[i] = new int[seats];

    initializeArray(arr, benches, seats);

    while (true)
    {
        int b, s;
        char choice;
        cout << "\nEnter the bench number you'd like to fill: ";
        cin >> b;

        cout << "Enter the seat number you'd like to fill: ";
        cin >> s;

        if (!updateArray(arr, benches, seats, b, s))
            continue;

        cout << "Do you want to fill further seats (Y/N)? ";
        cin >> choice;

        if (choice == 'N' || choice == 'n')
            break;
    }

    printArray(arr, benches, seats);
    for (int i = 0; i < benches; i++)
        delete[] arr[i];
    delete[] arr;

    return 0;
}

void initializeArray(int **arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            arr[i][j] = 0;
    }
}

bool updateArray(int **arr, int rows, int cols, int r, int c)
{
    if (!((r >= 1 && r <= rows) && (c >= 1 && c <= cols)))
    {
        cout << "Invalid bench and/or seat number!" << endl;
        return false;
    }

    if (arr[r - 1][c - 1] == 1)
    {
        cout << "Bench " << r << ", Seat " << c << " already booked!" << endl;
        return false;
    }

    arr[r - 1][c - 1] = 1;
    cout << "Seat filled successfully!" << endl;
    return true;
}

void printArray(int **arr, int rows, int cols)
{
    cout << "\n------------ Displaying the seats ------------\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
