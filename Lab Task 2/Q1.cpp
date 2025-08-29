/* Task #1:
Implement a program that dynamically allocates a 1D array of integers.
=> The size should be given by the user.
=> Initialize all elements with zero.
=> Then, let the user update values at different positions.
=> Finally, print the array and deallocate memory properly. */

#include <iostream>
using namespace std;

void updateValues(int *&arr, int size){
    for(int i = 0; i < size; i++){
        cout << "Enter the value to be stored at index " << i << ": ";
        cin >> arr[i];
    }
}

void printArray(int *arr, int size){
    cout << "Printing the array:" << endl;
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    
    int *arr = new int[size];
    for(int i = 0; i < size; i++)
        arr[i] = 0;
        
    updateValues(arr, size);
    printArray(arr, size);

    return 0;
}
