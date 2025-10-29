/* Insertion Sort is used to sort an array in an ascending or descending order. Time Complexity: O(n^2) */
#include <iostream>
using namespace std;

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int curr = arr[i];
        int prev = i - 1;

        // for descending order: arr[prev] < curr
        while (prev >= 0 && arr[prev] > curr)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }

        arr[prev + 1] = curr;
    }
}

int main()
{
    int arr[] = {2, 100, 50, 7, 8, 1, 99, 75, 69};
    int size = 9;

    insertionSort(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}