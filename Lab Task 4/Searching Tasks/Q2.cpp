/* 2. You've been given an array of numbers representing employee IDs. Your task is to identify the employee whose ID 
matches the last two digits of your roll number. If your roll number's last two digits are not present in the array, 
insert the missing value in its correct position within the array. You must use binary search to locate the position of 
that value within the array. */

#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key);

int main(){
    int size;
    while(1){
        cout << "Enter the size of the array: ";
        cin >> size;

        if(size > 0) break;
        cout << "Invalid size!" << endl;
    }

    int *employeeID = new int[size];
    cout << "\nEnter the employee IDs in increasing order:\n";
    for(int i = 0; i < size; i++)
        cin >> employeeID[i];

    int target;
    cout << "\nEnter the last two digits of your roll number: ";
    cin >> target;

    int idx = binarySearch(employeeID, size, target);
    if(idx >= 0){
        cout << "\nEmployee ID at index " << idx << " matches the last 2 digits of your roll number i.e. " << target << endl;
    }
    else{
        cout << "\nNo matches found with the last 2 digits of your roll number! Inserting the list with a new value..." << endl;

        int *newArr = new int[size + 1];
        int i = 0, j = 0;
        bool inserted = false;
        while(i < size){
            if(i == (-idx - 1) && !inserted){
                newArr[j++] = target;
                inserted = true;
            }
            
            newArr[j++] = employeeID[i++];
        }

        // Check if it is to be inserted at last
        if(!inserted){
            newArr[j++] = target;
            inserted = true;
        }

        delete[] employeeID;
        employeeID = newArr;
        size++;
    }

    cout << "\n------------- Displaying Employee IDs below -------------\n";
    for(int i = 0; i < size; i++)
        cout << employeeID[i] << " ";

    return 0;
}

int binarySearch(int arr[], int n, int key){
    int left = 0, right = n - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;

        if(key == arr[mid]) 
            return mid;
        else if(key < arr[mid])
            right = mid - 1;
        else 
            left = mid + 1;
    }

    return -left - 1;
    // left pointer (if key is not found) will point to the insertion index
    // returning it as negative so we know that a negative value means insertion index, not an index in which key is found
}
