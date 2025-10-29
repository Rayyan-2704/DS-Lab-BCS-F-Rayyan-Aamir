/* Shell Sort (improved Insertion Sort) is used to sort an array in an ascending or descending order.
Time Complexity: Average Case: O(n log n), Worst Case: O(n^2) */
#include <iostream>
using namespace std;

void shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int j = gap; j < n; j++)
        {
            int key = arr[j];
            int res = j;

            // for descending order: arr[res - gap] < key
            while (res >= gap && arr[res - gap] > key)
            {
                arr[res] = arr[res - gap];
                res -= gap;
            }
            arr[res] = key;
        }
    }
}

int main()
{
    int arr[] = {2, 100, 50, 7, 8, 1, 99, 75, 69};
    int size = 9;

    shellSort(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}