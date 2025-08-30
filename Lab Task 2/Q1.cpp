/* Task #1:
Implement a program that dynamically allocates a 1D array of integers.
=> The size should be given by the user.
=> Initialize all elements with zero.
=> Then, let the user update values at different positions.
=> Finally, print the array and deallocate memory properly. */

#include <iostream>
using namespace std;

bool updateArray(int *arr, int n, int pos);
void printArray(int *arr, int n);

int main()
{
    int size;
    while (true)
    {
        cout << "Enter the size of the array: ";
        cin >> size;

        if (size > 0)
            break;
        cout << "Invalid size!" << endl;
    }

    int *arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = 0;

    while (true)
    {
        int pos;
        char choice;
        cout << "\nEnter the index of the array: ";
        cin >> pos;

        if (!updateArray(arr, size, pos))
        {
            cout << "Invalid index!" << endl;
            continue;
        }

        cout << "Do you want to update the array further (Y/N)? ";
        cin >> choice;

        if (choice == 'N' || choice == 'n')
            break;
    }

    printArray(arr, size);
    delete[] arr;

    return 0;
}

bool updateArray(int *arr, int n, int pos)
{
    if (pos < 0 || pos >= n)
    {
        return false;
    }

    cout << "Enter the value to be updated at index " << pos << ": ";
    cin >> arr[pos];
    return true;
}

void printArray(int *arr, int n)
{
    cout << "\n------------ Printing the array ------------\n";
    for (int i = 0; i < n; i++)
        cout << "Index " << i << ": " << arr[i] << endl;
}
