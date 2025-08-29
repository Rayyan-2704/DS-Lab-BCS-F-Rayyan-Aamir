/* Task #1:
Implement a program that dynamically allocates a 1D array of integers.
=> The size should be given by the user.
=> Initialize all elements with zero.
=> Then, let the user update values at different positions.
=> Finally, print the array and deallocate memory properly. */

#include <iostream>
using namespace std;

void updateValues(int *arr, int size){
    int pos;
    while(true){
        cout << "\nEnter the index: ";
        cin >> pos;
        
        if(pos < 0 || pos >= size){
            cout << "Out of bounds!" << endl;
        }
        else break;
    }
    
    cout << "Enter the value to be stored at index " << pos << ": ";
    cin >> arr[pos];
}

void printArray(int *arr, int size){
    cout << "\nPrinting the array:" << endl;
    for(int i = 0; i < size; i++){
        cout << "Index " << i << ": " << arr[i] << endl;
    }
}

int main() {
    int size;
    while(true){
        cout << "Enter the size of the array: ";
        cin >> size;
        
        if(size <= 0){
            cout << "Invalid size!" << endl;
        }
        else break;
    }
    
    int *arr = new int[size];
    for(int i = 0; i < size; i++)
        arr[i] = 0;
        
    updateValues(arr, size);
    printArray(arr, size);

    delete[] arr;

    return 0;
}
