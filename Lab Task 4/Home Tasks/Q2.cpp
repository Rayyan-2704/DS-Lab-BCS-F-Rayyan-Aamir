/* 2. Write a program to implement the Bubble Sort algorithm. The program should take
an array of integers as input from the user, sort the array using bubble sort, and then
display both the unsorted and sorted arrays. */

#include <iostream>
using namespace std;

void printArray(int arr[], int n);
void bubbleSort(int arr[], int n);

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

    bubbleSort(arr, size);

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

void bubbleSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        bool isSwapped = false;
        
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSwapped = true;
            }
        }

        if(!isSwapped) return;
    }
}