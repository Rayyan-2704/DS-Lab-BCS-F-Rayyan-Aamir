/* 3. Implement the Selection Sort algorithm. The program should take an array of integers from
the user, find the smallest element, and exchange it with the element at the first position.
This process should continue until the array is completely sorted. Display the sorted array
to the user. */

#include <iostream>
using namespace std;

void printArray(int arr[], int n);
void selectionSort(int arr[], int n);

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

    selectionSort(arr, size);

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

void selectionSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        int smallestIdx = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[smallestIdx])
                smallestIdx = j;
        }

        if(smallestIdx != i){
            int temp = arr[i];
            arr[i] = arr[smallestIdx];
            arr[smallestIdx] = temp; 
        }
    }
}