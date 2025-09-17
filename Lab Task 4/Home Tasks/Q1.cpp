/* 1. Implement a linear search algorithm to find a specific integer in an array. The program
should take an array of integers and a target value as input from the user. Print the index of
the target value if it's found or a message indicating that the element is not in the array. */

#include <iostream>
using namespace std;

int linearSearch(int *arr, int n, int key);

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

    int target;
    cout << "\nEnter the target element to be searched: ";
    cin >> target;

    int idx = linearSearch(arr, size, target);
    if(idx != -1)
        cout << "\nThe target element " << target << " has been found at index " << idx << endl;
    else
        cout << "\nThe target element " << target << " is not present in the array!" << endl;

    delete[] arr;
    return 0;
}

int linearSearch(int *arr, int n, int key){
    for(int i = 0; i < n; i++){
        if(arr[i] == key) return i;
    }

    return -1;
}
