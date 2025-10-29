/* Merge Sort is a divide and conquer algorithm used to sort an array in ascending or descending order. Time Complexity: O(n log n) */
#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    int *temp = new int[high - low + 1];
    int left = low, right = mid + 1;
    int idx = 0;
    while (left <= mid && right <= high)
    {
        // for descending order: if (arr[left] >= arr[right])
        if (arr[left] <= arr[right])
            temp[idx++] = arr[left++];
        else
            temp[idx++] = arr[right++];
    }

    while (left <= mid)
        temp[idx++] = arr[left++];

    while (right <= high)
        temp[idx++] = arr[right++];

    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];

    delete[] temp;
}

void mergeSort(int arr[], int low, int high)
{
    if (low >= high) return;

    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    merge(arr, low, mid, high);
}

void sort(int arr[], int n)
{
    mergeSort(arr, 0, n - 1);
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