/* 1. Write a C++ program to implement Linear Search. Your program should take an array of integers and a target value as input from the user. 
The program should search for the target value in the array using the linear search algorithm and output the index at which the target is found. 
If the target value is not found in the array, the program should display an appropriate message.  */

#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key);

int main(){
    int size;
    while(1)
    {
        cout << "Enter the size of the array: ";
        cin >> size;

        if(size > 0) break;
        cout << "Invalid size!" << endl;
    }

    int *arr = new int[size];
    for(int i = 0; i < size; i++){
        cout << "Enter the element at index " << i << ": ";
        cin >> arr[i];
    }

    int target;
    cout << "\nEnter the target element to be searched: ";
    cin >> target;

    int idx = linearSearch(arr, size, target);
    if(idx != -1)
        cout << "Target element " << target << " found at index " << idx << " of the array!" << endl;
    else
        cout << "Target element " << target << " not found in the array!" << endl;

    delete[] arr;
    return 0;
}

int linearSearch(int arr[], int n, int key)
{
    for(int i = 0; i < n; i++){
        if(arr[i] == key) return i;
    }

    return -1;
}
