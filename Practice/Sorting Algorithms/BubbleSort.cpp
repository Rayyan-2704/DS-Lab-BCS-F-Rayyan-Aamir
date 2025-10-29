/* Bubble Sort is used to sort an array in an ascending or descending order. Time Complexity: O(n^2) */
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool isSwapped = false;

        for (int j = 0; j < size - i - 1; j++)
        {
            // for descending order: arr[j] < arr[j + 1]
            if (arr[j] > arr[j + 1])
            { // for ascending order
                swap(arr[j], arr[j + 1]);
                isSwapped = true;
            }
        }

        if (!isSwapped)
            return; // For further optimization, no need to sort further if the array is already sorted
    }
}

int main()
{
    int arr[] = {2, 100, 50, 7, 8, 1, 99, 75, 69};
    int size = 9;

    bubbleSort(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}