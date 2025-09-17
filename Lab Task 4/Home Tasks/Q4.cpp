/* 4. Use Insertion Sort to sort an array of integers provided by the user. Then, implement the
Binary Search algorithm to find a target value within the newly sorted array. The program
should display the sorted array and the index of the found element or a message if it's not
present. */

#include <iostream>
using namespace std;

void printArray(int arr[], int n);
void insertionSort(int arr[], int n);
int binarySearch(int arr[], int n, int target);

int main(){
    int size;
    while(1){
        cout << "Enter the size of the array: ";
        cin >> size;

        if(size > 0) break;
        cout << "Invalid size!" << endl;
    }

    int *arr = new int[size];
    cout << "\n------------- Enter the elements of the array below -------------\n";
    for(int i = 0; i < size; i++)
        cin >> arr[i];

    cout << "\n------------- Printing the original array -------------\n";
    printArray(arr, size);

    insertionSort(arr, size);

    int target;
    cout << "\nEnter the target element to be searched: ";
    cin >> target;

    int idx = binarySearch(arr, size, target);
    if(idx != -1)
        cout << "\nThe target element " << target << " has been found at index " << idx << " of the sorted array." << endl;
    else
        cout << "\nThe target element " << target << " is not present in the array!" << endl;

    cout << "\n------------- Printing the sorted array -------------\n";
    printArray(arr, size);

    delete[] arr;
    return 0;
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void insertionSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >=0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int binarySearch(int arr[], int n, int target){
    int left = 0, right = n - 1;
    while(left <= right){
        int mid = left + (right - left)/2;

        if(arr[mid] == target)
            return mid;
        else if(arr[mid] > target) 
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}