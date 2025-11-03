/* Quick Sort is a divide and conquer algorithm used to sort an array in ascending or descending order. 
Time Complexity: O(n log n) on average and O(n^2) in the worst case. */
#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
    int i = low, j = high;
    int pivot = arr[low];
    while (i < j)
    {
        // for decreasing order:
        // while (i <= high - 1 && arr[i] >= pivot) i++;
        // while (j >= low + 1 && arr[j] < pivot) j--;
        
        while (i <= high - 1 && arr[i] <= pivot) i++;
        while (j >= low + 1 && arr[j] > pivot) j--;

        if (i < j) swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low >= high) return;

    int partitionIndex = partition(arr, low, high);
    quickSort(arr, low, partitionIndex - 1);
    quickSort(arr, partitionIndex + 1, high);
}

void sort(int arr[], int n)
{
    quickSort(arr, 0, n - 1);
}

int main()
{
    int arr[] = {2, 100, 50, 7, 8, 1, 99, 75, 69};
    int size = 9;

    sort(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;

}
