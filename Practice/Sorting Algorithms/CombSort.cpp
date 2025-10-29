/* Comb Sort (improved Bubble Sort) is used to sort an array in an ascending or descending order. Time Complexity: O(n^2) */
#include <iostream>
using namespace std;

void combSort(int arr[], int size)
{
    int gap = size;
    const double shrink = 1.3;
    bool isSwapped = true;

    while (gap > 1 || isSwapped)
    {
        isSwapped = false;
        gap = (int)(gap / shrink);
        if (gap < 1)
            gap = 1;

        for (int i = 0; i + gap < size; i++)
        {
            // for descending order : arr[i] < arr[i + gap]
            if (arr[i] > arr[i + gap])
            {
                swap(arr[i], arr[i + gap]);
                isSwapped = true;
            }
        }
    }
}

int main()
{
    int arr[] = {2, 100, 50, 7, 8, 1, 99, 75, 69};
    int size = 9;

    combSort(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}