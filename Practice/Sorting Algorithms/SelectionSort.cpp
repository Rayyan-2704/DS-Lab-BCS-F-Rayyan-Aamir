/* Selection Sort is used to sort an array in an ascending or descending order. Time Complexity: O(n^2) */
#include <iostream>
using namespace std;

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int smallestIndex = i;

        for (int j = i + 1; j < size; j++)
        {
            // for descending order: arr[j] > largestIndex
            if (arr[j] < arr[smallestIndex])
                smallestIndex = j;
        }

        // Swap only if needed
        if (i != smallestIndex)
            swap(arr[i], arr[smallestIndex]);
    }
}

int main()
{
    int arr[] = {2, 100, 50, 7, 8, 1, 99, 75, 69};
    int size = 9;

    selectionSort(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}